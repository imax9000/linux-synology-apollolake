#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
#ifdef MY_ABC_HERE
#include <linux/synotify.h>
#include <linux/fdtable.h>
#include <linux/fsnotify_backend.h>
#include <linux/init.h>
#include <linux/jiffies.h>
#include <linux/kernel.h> /* UINT_MAX */
#include <linux/mount.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/wait.h>
#include <linux/nsproxy.h>
#include <linux/mnt_namespace.h>
#include <linux/module.h>

#include "synotify.h"

static struct kmem_cache *synotify_event_info_cachep = NULL;

static void path_append(char *parent_path, const char *child_name, int n) {
	int i = strlen(parent_path);

	if (parent_path[i] != '/' && child_name[0] != '/' && n - 1 > i) {
		parent_path[i] = '/';
		parent_path[i + 1] = '\0';
		strncat(parent_path, child_name, n - i - 2);
	} else
		strncat(parent_path, child_name, n - i - 1);
}

/*
   Fetch full mount point path,
   It traverse vfsmount from down to up by following mnt_parent
   @in: struct vfsmount: vfsmount structure, size_t buf_len: path buffer length
   @out: mnt_full_path: full path of vfsmount struct
   @return: < 0 : failed, 0 : success
 */
static int syno_fetch_mountpoint_fullpath(struct vfsmount *mnt, char *mnt_full_path, char *d_path_buf)
{
	int ret = -1;
	char *mnt_dentry_path = NULL;
	struct nsproxy *nsproxy = current->nsproxy;
	struct mnt_namespace *mnt_space = NULL;
	struct mount *root_mnt = NULL;
	struct path root_path;
	struct path mnt_path;

	if (!nsproxy)
		return -EINVAL;

	mnt_space = nsproxy->mnt_ns;
	if (!mnt_space || !mnt_space->root)
		return -EINVAL;

	get_mnt_ns(mnt_space);

	root_mnt = mnt_space->root;
	memset(&root_path, 0, sizeof(struct path));
	root_path.mnt = &root_mnt->mnt;
	root_path.dentry = root_mnt->mnt.mnt_root;

	memset(&mnt_path, 0, sizeof(struct path));
	mnt_path.mnt = mnt;
	mnt_path.dentry = mnt->mnt_root;

	path_get(&mnt_path);
	path_get(&root_path);

	mnt_dentry_path = __d_path(&mnt_path, &root_path, d_path_buf, PATH_MAX - 1);
	if(IS_ERR_OR_NULL(mnt_dentry_path)){
		ret = -ENOENT;
		goto RESOURCE_PUT;
	}

	path_append(mnt_full_path, mnt_dentry_path, PATH_MAX);

	ret = 0;

RESOURCE_PUT:
	path_put(&root_path);
	path_put(&mnt_path);
	put_mnt_ns(mnt_space);
	d_path_buf[0] = '\0';
	return ret;
}

// Caller should hold group->notification_mutex
static int synotify_fetch_name(struct fsnotify_event *fsnotify_event, struct fsnotify_group *group)
{
	struct synotify_event_info *event = SYNOTIFY_E(fsnotify_event);
	char *synotify_full_path_buf = NULL;
	char *synotify_d_path_buf = NULL;
	char *dentry_path = NULL;
	struct vfsmount *mnt = event->path.mnt;
	int ret = -1;

	if (event->data_type == FSNOTIFY_EVENT_NONE) {
		return 0;
	}

	synotify_full_path_buf = group->synotify_data.synotify_full_path_buf;
	synotify_d_path_buf = group->synotify_data.synotify_d_path_buf;
	WARN_ON_ONCE(synotify_full_path_buf[0] || synotify_d_path_buf[0]);

	ret = syno_fetch_mountpoint_fullpath(mnt, synotify_full_path_buf, synotify_d_path_buf);
	if (ret < 0)
		goto ERR;

	if(event->data_type == FSNOTIFY_EVENT_PATH) {
		struct path root_path;
		root_path.mnt = mnt;
		root_path.dentry = mnt->mnt_root;
		dentry_path = __d_path(&event->path, &root_path, synotify_d_path_buf, PATH_MAX-1);
		if (unlikely(IS_ERR_OR_NULL(dentry_path))) {
			ret = -ENOENT;
			goto ERR;
		}
		path_append(synotify_full_path_buf, dentry_path, PATH_MAX);
	} else
		path_append(synotify_full_path_buf, event->file_name, PATH_MAX);

	event->full_name = kstrdup(synotify_full_path_buf, GFP_NOFS);
	if (unlikely(!event->full_name)) {
		ret = -ENOMEM;
		goto ERR;
	}
	event->full_name_len = strlen(event->full_name);
	ret = 0;

ERR:
	synotify_full_path_buf[0] = '\0';
	synotify_d_path_buf[0] = '\0';
	return ret;
}

static bool should_merge(struct fsnotify_event *old_fsn, struct fsnotify_event *new_fsn)
{
	struct synotify_event_info *old, *new;

	pr_debug("%s: old=%p new=%p\n", __func__, old_fsn, new_fsn);
	old = SYNOTIFY_E(old_fsn);
	new = SYNOTIFY_E(new_fsn);

	if (old_fsn->mask != new_fsn->mask) return false;

	if ( (new_fsn->mask & (FS_ATTRIB | FS_ACCESS | FS_MODIFY))
			&& (old->path.mnt == new->path.mnt)
			&& (old->path.dentry == new->path.dentry))
		return true;
	return false;
}

/* and the list better be locked by something too! */
static int synotify_merge(struct list_head *list,
					     struct fsnotify_event *event)
{
	struct fsnotify_event *last_event;
	pr_debug("%s: list=%p event=%p, mask=%x\n", __func__, list, event, event->mask);

	last_event = list_entry(list->prev, struct fsnotify_event, list);
	return should_merge(last_event, event);
}

static bool synotify_should_send_event(struct fsnotify_mark *vfsmnt_mark,
				       __u32 event_mask, int data_type)
{
	__u32 marks_mask;

	/* if we don't have enough info to send an event to userspace say no */
	if (data_type != FSNOTIFY_EVENT_SYNO && data_type != FSNOTIFY_EVENT_PATH)
		return false;

	if (vfsmnt_mark) {
		marks_mask = vfsmnt_mark->mask;
	} else {
		BUG();
	}

	if (event_mask & marks_mask)
		return true;

	return false;
}

struct synotify_event_info *synotify_alloc_event(struct inode *inode, u32 mask,
						 struct path *path, u32 cookie)
{
	struct synotify_event_info *event;

	if (unlikely(!synotify_event_info_cachep))
		return NULL;

	event = kmem_cache_alloc(synotify_event_info_cachep, GFP_NOFS);
	if (!event)
		return NULL;

	fsnotify_init_event(&event->fse, inode, mask);
	if (path) {
		event->path = *path;
		path_get(&event->path);
	} else {
		event->path.mnt = NULL;
		event->path.dentry = NULL;
	}
	event->full_name = NULL;
	event->full_name_len = 0;
	event->sync_cookie = cookie;
	event->file_name = NULL;
	event->data_type = FSNOTIFY_EVENT_NONE;
	
	return event;
}

static int synotify_handle_event(struct fsnotify_group *group,
				 struct inode *inode,
				 struct fsnotify_mark *inode_mark,
				 struct fsnotify_mark *synotify_mark,
				 u32 mask, void *data, int data_type,
				 const unsigned char *file_name, u32 cookie)
{
	int ret = 0;
	struct synotify_event_info *event;
	struct fsnotify_event *fsn_event;

	if (!synotify_should_send_event(synotify_mark, mask, data_type))
		return 0;

	pr_debug("%s: group=%p inode=%p mask=%x\n", __func__, group, inode,
		 mask);

	event = synotify_alloc_event(inode, mask, data, cookie);
	if (unlikely(!event))
		return -ENOMEM;

	event->file_name = file_name;
	event->data_type = data_type;
	fsn_event = &event->fse;

	ret = fsnotify_add_event(group, fsn_event, synotify_merge);
	if (ret) {
		fsnotify_destroy_event(group, fsn_event);
		return ret > 0 ? 0 : ret;
	}

	return 0;
}

static void synotify_free_group_priv(struct fsnotify_group *group)
{
	struct user_struct *user;

	user = group->synotify_data.user;
	atomic_dec(&user->synotify_instances);
	free_uid(user);

	kfree(group->synotify_data.synotify_full_path_buf);
	kfree(group->synotify_data.synotify_d_path_buf);
}

static void synotify_free_event(struct fsnotify_event *fsn_event)
{
	struct synotify_event_info *event;

	event = SYNOTIFY_E(fsn_event);
	path_put(&event->path);
	kfree(event->full_name);
	kmem_cache_free(synotify_event_info_cachep, event);
}

const struct fsnotify_ops synotify_fsnotify_ops = {
	.handle_event = synotify_handle_event,
	.free_group_priv = synotify_free_group_priv,
	.free_event = synotify_free_event,
	.fetch_name = synotify_fetch_name,
};

static int __init synotify_setup(void)
{
	synotify_event_info_cachep = kmem_cache_create("synotify_event_info",
		sizeof(struct synotify_event_info), 0, SLAB_MEM_SPREAD, NULL);
	if (!synotify_event_info_cachep)
		printk(KERN_ERR "synotify failed to kmem_cache_create synotify_event_info, disable synotify!\n");

	return 0;
}

static void __exit exit_synotify(void) {
	kmem_cache_destroy(synotify_event_info_cachep);
}

device_initcall(synotify_setup);
module_exit(exit_synotify)
#endif /* MY_ABC_HERE */
