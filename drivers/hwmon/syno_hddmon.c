#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/syno.h>
#include <linux/synobios.h>
#include <linux/delay.h>
#ifdef MY_ABC_HERE
#include <linux/libata.h>
#endif /* MY_ABC_HERE */
#ifdef MY_ABC_HERE
#include <linux/synosata.h>
#endif /* MY_ABC_HERE */

MODULE_LICENSE("Proprietary");

#define SYNO_MAX_HDD_PRZ 6
#define SYNO_HDDMON_POLL_SEC 1
#define SYNO_HDDMON_EN_WAIT_SEC 7
#define SYNO_HDDMON_STR "Syno_HDDMon"
#define SYNO_HDDMON_UPLG_STR "Syno_HDDMon_UPLGM"

#ifdef MY_ABC_HERE
extern long g_hdd_hotplug;
#endif /* MY_ABC_HERE */

#define GPIO_UNDEF				0xFF

extern int SYNO_SUPPORT_HDD_DYNAMIC_ENABLE_POWER(void);
extern int SYNO_CTRL_HDD_POWERON(int index, int value);
#ifdef MY_ABC_HERE
extern int SYNO_CHECK_HDD_DETECT(int index);
#else
extern int SYNO_CHECK_HDD_PRESENT(int index);
#endif /* MY_ABC_HERE */

#ifdef MY_DEF_HERE
extern struct ata_port *syno_ata_port_get_by_port(const unsigned short diskPort);
#endif /* MY_DEF_HERE */

typedef struct __SynoHddMonData {
	int iProcessingIdx;
	int blHddHotPlugSupport;
	int iMaxHddNum;
#ifdef MY_DEF_HERE
	int* blHddEnStat;
#else /* MY_DEF_HERE */
	int blHddEnStat[SYNO_MAX_HDD_PRZ];
#endif /* MY_DEF_HERE */
	int iHddEnWait;
} SynoHddMonData_t;

static struct task_struct *pHddPrzPolling;
static SynoHddMonData_t synoHddMonData;

static int syno_hddmon_data_init(SynoHddMonData_t *pData)
{
	int iRet = -1;

	if (NULL == pData) {
		goto END;
	}

	memset(pData, 0, sizeof(SynoHddMonData_t));

#ifdef MY_ABC_HERE
	/* FIXME: DS220j doesn't have boot args HddHotPlug, need work around here.
	 * the better way to fix this is remove this bootargs judgement, but need to take care of other models */
	if (syno_is_hw_version(HW_DS220j)) {
		pData->blHddHotPlugSupport = 1;
	} else {
		pData->blHddHotPlugSupport = g_hdd_hotplug;
	}
#endif /* MY_ABC_HERE */

#ifdef MY_DEF_HERE
	if (gSynoHddPowerupSeq) {
		pData->iMaxHddNum = gSynoInternalHddNumber;
		pData->blHddEnStat = kmalloc(sizeof(int) * pData->iMaxHddNum, GFP_KERNEL);
		memset(pData->blHddEnStat, 0, sizeof(int) * pData->iMaxHddNum);
	} else {
		goto END;
	}
#else /* MY_DEF_HERE */
	pData->iMaxHddNum = g_syno_hdd_powerup_seq;
#endif /* MY_DEF_HERE */

#ifdef MY_ABC_HERE
	if (0 < giSynoSpinupGroupDelay) {
		pData->iHddEnWait = giSynoSpinupGroupDelay;
	} else {
		pData->iHddEnWait = SYNO_HDDMON_EN_WAIT_SEC;
	}
#else /* MY_ABC_HERE */
	pData->iHddEnWait = SYNO_HDDMON_EN_WAIT_SEC;
#endif /* MY_ABC_HERE */

	if (!SYNO_SUPPORT_HDD_DYNAMIC_ENABLE_POWER()) {
		pData->blHddHotPlugSupport = 0;
	}

	if (0 == pData->blHddHotPlugSupport) {
		goto END;
	}

	iRet = 0;
END:
	return iRet;
}

#ifdef MY_ABC_HERE
extern int iIsSynoIRQOff(const struct ata_port *ap);

static int syno_hddmon_is_disk_deepsleep(int iDiskIdx, SynoHddMonData_t *pData)
{
#ifdef MY_DEF_HERE
#else /* MY_DEF_HERE */
	struct Scsi_Host *pScsiHost = NULL;
#endif /* MY_DEF_HERE */
	struct ata_port  *pAtaPrt = NULL;
	int iErr = -1;

	if (NULL == pData) {
		goto END;
	}

	if (0 > iDiskIdx || pData->iMaxHddNum < iDiskIdx) {
		iErr = -EINVAL;
		goto END;
	}

#ifdef MY_DEF_HERE
	if (NULL == (pAtaPrt = syno_ata_port_get_by_port(iDiskIdx + 1))) {
		iErr = -ENODEV;
		goto END;
	}
#else /* MY_DEF_HERE */
	if (NULL == (pScsiHost = scsi_host_lookup(iDiskIdx))) {
		iErr = -ENODEV;
		goto END;
	}

	if (NULL == (pAtaPrt = ata_shost_to_port(pScsiHost))) {
		iErr = -ENODEV;
		goto END;
	}
#endif /* MY_DEF_HERE */

	iErr = iIsSynoIRQOff(pAtaPrt);
END:
	return iErr;
}
#endif /* MY_ABC_HERE */

static int syno_hddmon_unplug_monitor(void *args)
{
	int iRet = -1;
	int iIdx;
	int iPrzPinVal;
	SynoHddMonData_t *pData = NULL;
	unsigned int uiTimeout;

	if (NULL == args) {
		goto END;
	}

	pData = (SynoHddMonData_t *) args;

	while (1) {
		if (kthread_should_stop()) {
			break;
		}

		for (iIdx = 1; iIdx <= pData->iMaxHddNum; iIdx++) {
			if (pData->iProcessingIdx == iIdx) {
				continue;
			}

#ifdef MY_ABC_HERE
			iPrzPinVal = SYNO_CHECK_HDD_DETECT(iIdx);
#else
			iPrzPinVal = SYNO_CHECK_HDD_PRESENT(iIdx);
#endif /* MY_ABC_HERE */

			if (iPrzPinVal) {
				continue;
			}

			mdelay(200);
			SYNO_CTRL_HDD_POWERON(iIdx, iPrzPinVal);
			pData->blHddEnStat[iIdx-1] = iPrzPinVal;
		}

		uiTimeout = SYNO_HDDMON_POLL_SEC * HZ;
		do {
			set_current_state(TASK_INTERRUPTIBLE);
			uiTimeout = schedule_timeout(uiTimeout);
		} while (uiTimeout);
	}

	iRet = 0;
END:
	return iRet;
}

static void syno_hddmon_task(SynoHddMonData_t *pData)
{
	int iIdx;
	int iPrzPinVal;
	static struct task_struct *pUnplugMonitor;
	unsigned int uiTimeout;

	if (NULL == pData) {
		goto END;
	}

	for (iIdx = 1; iIdx <= pData->iMaxHddNum; iIdx++) {
		pUnplugMonitor = NULL;
		pData->iProcessingIdx = iIdx;

#ifdef MY_ABC_HERE
		iPrzPinVal = SYNO_CHECK_HDD_DETECT(iIdx);
#else
		iPrzPinVal = SYNO_CHECK_HDD_PRESENT(iIdx);
#endif /* MY_ABC_HERE */

		if (pData->blHddEnStat[iIdx-1] != iPrzPinVal) {
#ifdef MY_ABC_HERE
			/*if the disk is plugged in while deep-sleep, do nothing*/
			if (iPrzPinVal && syno_hddmon_is_disk_deepsleep(iIdx-1, pData)) {
				continue;
			}
#endif /* MY_ABC_HERE */

			if (iPrzPinVal) {
				//while starting a port, monitoring other ports for the disks unplugged
				pUnplugMonitor = kthread_run(syno_hddmon_unplug_monitor, pData, SYNO_HDDMON_UPLG_STR);
			}

			mdelay(200);
#ifdef MY_ABC_HERE
			if (iPrzPinVal) {
				DBG_SpinupGroup("Power on disk: %d\n", iIdx);
			}
#endif /* MY_ABC_HERE */
			SYNO_CTRL_HDD_POWERON(iIdx, iPrzPinVal);
			pData->blHddEnStat[iIdx-1] = iPrzPinVal;

			if (iPrzPinVal) {
				uiTimeout = pData->iHddEnWait * HZ;
				do {
					set_current_state(TASK_INTERRUPTIBLE);
					uiTimeout = schedule_timeout(uiTimeout);
				} while (uiTimeout);
			}

			if (NULL != pUnplugMonitor) {
				kthread_stop(pUnplugMonitor);
			}
		}
	}

END:
	return;
}

static void syno_hddmon_sync(SynoHddMonData_t *pData)
{
	int iIdx;
	int iPrzPinVal;

	if (NULL == pData) {
		goto END;
	}

	for (iIdx = 1; iIdx <= pData->iMaxHddNum; iIdx++) {
		pData->iProcessingIdx = iIdx;

#ifdef MY_ABC_HERE
		iPrzPinVal = SYNO_CHECK_HDD_DETECT(iIdx);
#else
		iPrzPinVal = SYNO_CHECK_HDD_PRESENT(iIdx);
#endif

		/* HDD Enable pins must be high just after boot-up,
		 * so turns the pins to low if the hdds do not present.
		 */
		if (!iPrzPinVal) {
			mdelay(200);
			SYNO_CTRL_HDD_POWERON(iIdx, iPrzPinVal);
			pData->blHddEnStat[iIdx-1] = iPrzPinVal;
		}

		/*sync the states*/
		pData->blHddEnStat[iIdx-1] = iPrzPinVal;

	}

END:
	return;
}
static int syno_hddmon_routine(void *args)
{
	int iRet = -1;
	SynoHddMonData_t *pData = NULL;
	unsigned int uiTimeout;

	if (NULL == args) {
		goto END;
	}

	pData = (SynoHddMonData_t *) args;

	while (1) {
		if (kthread_should_stop()) {
			break;
		}

		syno_hddmon_task(pData);

		uiTimeout = SYNO_HDDMON_POLL_SEC * HZ;
		do {
			set_current_state(TASK_INTERRUPTIBLE);
			uiTimeout = schedule_timeout(uiTimeout);
		} while (uiTimeout);
	}

	iRet = 0;
END:
	return iRet;
}

static int __init syno_hddmon_init(void)
{
	int iRet = -1;

	iRet = syno_hddmon_data_init(&synoHddMonData);
	if (0 > iRet) {
		goto END;
	}

	syno_hddmon_sync(&synoHddMonData);

	/* processing */
	pHddPrzPolling = kthread_create(syno_hddmon_routine, &synoHddMonData, SYNO_HDDMON_STR);

	if (IS_ERR(pHddPrzPolling)) {
		iRet = PTR_ERR(pHddPrzPolling);
		pHddPrzPolling = NULL;
		goto END;
	}

	wake_up_process(pHddPrzPolling);

	printk("Syno_HddMon: Initialization completed.\n");

	iRet = 0;
END:
	return iRet;
}

static void __exit syno_hddman_exit(void)
{
	if (pHddPrzPolling) {
		printk("###\n");
		WARN_ON(1);
		kthread_stop(pHddPrzPolling);
	}
#ifdef MY_DEF_HERE
	if (synoHddMonData.blHddEnStat) {
		kfree(synoHddMonData.blHddEnStat);
	}
	synoHddMonData.blHddEnStat = NULL;
#endif /* MY_DEF_HERE */
}

MODULE_AUTHOR("Yikai Peng");
MODULE_DESCRIPTION("Syno_HddMon\n");
MODULE_LICENSE("Synology Inc.");

module_init(syno_hddmon_init);
module_exit(syno_hddman_exit);
