#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
/*
 * Copyright (C) 2014 Facebook.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License v2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 021110-1307, USA.
 */

#ifndef __BTRFS_QGROUP__
#define __BTRFS_QGROUP__

#include "ulist.h"
#include "delayed-ref.h"

/*
 * Record a dirty extent, and info qgroup to update quota on it
 * TODO: Use kmem cache to alloc it.
 */
#ifdef MY_ABC_HERE
struct btrfs_quota_account_rec {
	struct list_head list;
	u64 ref_root;
	u64 bytenr;
	u64 num_bytes;
	u64 ram_bytes;
	unsigned int op_type:1;
#ifdef MY_ABC_HERE
	u64 objectid;
	uid_t uid;
	struct inode *inode;
#endif /* MY_ABC_HERE */
};
#endif /* MY_ABC_HERE */
struct btrfs_qgroup_extent_record {
	struct rb_node node;
	u64 bytenr;
	u64 num_bytes;
	struct ulist *old_roots;
};

/*
 * For qgroup event trace points only
 */
#define QGROUP_RESERVE		(1<<0)
#define QGROUP_RELEASE		(1<<1)
#define QGROUP_FREE		(1<<2)

int btrfs_quota_enable(struct btrfs_trans_handle *trans,
		       struct btrfs_fs_info *fs_info);
int btrfs_quota_disable(struct btrfs_trans_handle *trans,
			struct btrfs_fs_info *fs_info);
int btrfs_qgroup_rescan(struct btrfs_fs_info *fs_info);
void btrfs_qgroup_rescan_resume(struct btrfs_fs_info *fs_info);
int btrfs_qgroup_wait_for_completion(struct btrfs_fs_info *fs_info,
				     bool interruptible);
int btrfs_add_qgroup_relation(struct btrfs_trans_handle *trans,
			      struct btrfs_fs_info *fs_info, u64 src, u64 dst);
int btrfs_del_qgroup_relation(struct btrfs_trans_handle *trans,
			      struct btrfs_fs_info *fs_info, u64 src, u64 dst);
int btrfs_create_qgroup(struct btrfs_trans_handle *trans,
			struct btrfs_fs_info *fs_info, u64 qgroupid);
int btrfs_remove_qgroup(struct btrfs_trans_handle *trans,
			      struct btrfs_fs_info *fs_info, u64 qgroupid);
int btrfs_limit_qgroup(struct btrfs_trans_handle *trans,
		       struct btrfs_fs_info *fs_info, u64 qgroupid,
		       struct btrfs_qgroup_limit *limit);
int btrfs_read_qgroup_config(struct btrfs_fs_info *fs_info);
void btrfs_free_qgroup_config(struct btrfs_fs_info *fs_info);
struct btrfs_delayed_extent_op;
#ifdef MY_ABC_HERE
int btrfs_insert_quota_record(struct btrfs_trans_handle *trans,
				  struct btrfs_delayed_ref_node *node);
int btrfs_quota_accounting(struct btrfs_trans_handle *trans,
				  struct btrfs_fs_info *fs_info);
#else
int btrfs_qgroup_prepare_account_extents(struct btrfs_trans_handle *trans,
					 struct btrfs_fs_info *fs_info);
struct btrfs_qgroup_extent_record
*btrfs_qgroup_insert_dirty_extent(struct btrfs_delayed_ref_root *delayed_refs,
				  struct btrfs_qgroup_extent_record *record);
int
btrfs_qgroup_account_extent(struct btrfs_trans_handle *trans,
			    struct btrfs_fs_info *fs_info,
			    u64 bytenr, u64 num_bytes,
			    struct ulist *old_roots, struct ulist *new_roots);
int btrfs_qgroup_account_extents(struct btrfs_trans_handle *trans,
				 struct btrfs_fs_info *fs_info);
#endif /* MY_ABC_HERE */
int btrfs_run_qgroups(struct btrfs_trans_handle *trans,
		      struct btrfs_fs_info *fs_info);
int btrfs_qgroup_inherit(struct btrfs_trans_handle *trans,
			 struct btrfs_fs_info *fs_info, u64 srcid, u64 objectid,
			 struct btrfs_qgroup_inherit *inherit);
void btrfs_qgroup_free_refroot(struct btrfs_fs_info *fs_info,
			       u64 ref_root, u64 num_bytes);
/*
 * TODO: Add proper trace point for it, as btrfs_qgroup_free() is
 * called by everywhere, can't provide good trace for delayed ref case.
 */
static inline void btrfs_qgroup_free_delayed_ref(struct btrfs_fs_info *fs_info,
						 u64 ref_root, u64 num_bytes)
{
	btrfs_qgroup_free_refroot(fs_info, ref_root, num_bytes);
	trace_btrfs_qgroup_free_delayed_ref(ref_root, num_bytes);
}
void assert_qgroups_uptodate(struct btrfs_trans_handle *trans);

#ifdef CONFIG_BTRFS_FS_RUN_SANITY_TESTS
int btrfs_verify_qgroup_counts(struct btrfs_fs_info *fs_info, u64 qgroupid,
			       u64 rfer, u64 excl);
#endif

/* New io_tree based accurate qgroup reserve API */
#ifdef MY_ABC_HERE
int btrfs_quota_reserve(struct btrfs_root *root, struct inode *inode,
						 u64 num_bytes);
void btrfs_quota_reserve_free(struct btrfs_root *root,
						 struct inode *inode, u64 num_bytes);
#endif /* MY_ABC_HERE */
int btrfs_qgroup_reserve_data(struct inode *inode, u64 start, u64 len);
int btrfs_qgroup_release_data(struct inode *inode, u64 start, u64 len);
int btrfs_qgroup_free_data(struct inode *inode, u64 start, u64 len);

int btrfs_qgroup_reserve_meta(struct btrfs_root *root, int num_bytes);
void btrfs_qgroup_free_meta_all(struct btrfs_root *root);
void btrfs_qgroup_free_meta(struct btrfs_root *root, int num_bytes);
void btrfs_qgroup_check_reserved_leak(struct inode *inode);

#ifdef MY_ABC_HERE
void btrfs_qgroup_query(struct btrfs_fs_info *fs_info, u64 qgroupid,
                        struct btrfs_ioctl_qgroup_query_args *qqa);
#endif /* MY_ABC_HERE */

#endif /* __BTRFS_QGROUP__ */
