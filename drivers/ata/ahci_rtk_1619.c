#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/platform_device.h>
#include <linux/ahci_platform.h>
#include <linux/libata.h>
#include <linux/reset.h>
#include <linux/io.h>
#include <linux/delay.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <linux/suspend.h>

#include "ahci.h"
#include "libata.h"
#include <scsi/scsi_device.h>

#include <soc/realtek/rtk_chip.h>

#define DRV_NAME_RTK	"ahci_rtk"
#ifdef MY_DEF_HERE
#define POWER_SAVEING	0
#else /* MY_DEF_HERE */
#define POWER_SAVEING	1
#endif /* MY_DEF_HERE */
#define MAC_MAX_CLK	5
#define MAC_MAX_RST	5
#define MAX_GPIO_CTL	10

struct task_struct *rtk_sata_dev_task;
int RTK_SATA_DEV_FLAG;
struct ahci_host_priv *g_hpriv;

enum {
	SUSPEND = 0,
	RESUME,
	RESUME_OK,
	RUNNING
};

/*
int rtk_enter_loopback_mode(struct ata_port *ap)
{
	return 0;
}*/

#ifdef MY_DEF_HERE
bool syno_ahci_rtk_compare_ata_devicetree_info(const struct ata_port *, const struct device_node *);
struct ata_port_operations ahci_rtk_syno_ops = {
	.inherits	= &ahci_platform_ops,
	.syno_compare_node_info = syno_ahci_rtk_compare_ata_devicetree_info,
};
#endif /* MY_DEF_HERE */

static const struct ata_port_info ahci_port_info = {
	.flags		= AHCI_FLAG_COMMON,
	.pio_mask	= ATA_PIO4,
	.udma_mask	= ATA_UDMA6,
#ifdef MY_DEF_HERE
	.port_ops	= &ahci_rtk_syno_ops,
#else /* MY_DEF_HERE */
	.port_ops	= &ahci_platform_ops,
#endif /* MY_DEF_HERE */
};

static struct scsi_host_template ahci_platform_sht = {
	AHCI_SHT(DRV_NAME_RTK),
};

struct ahci_port_desc {
	unsigned int index;
	unsigned int power_io;
	unsigned int power_save;
	struct reset_control *rsts[MAC_MAX_RST];
};

struct ahci_rtk_dev {
	struct ahci_port_desc **ports;
	struct device *dev;
	struct ahci_host_priv *hpriv;
	struct delayed_work work;
	struct work_struct gpio;
	struct reset_control *rsts[MAC_MAX_RST];

	enum rtd_chip_id chip_id;
	enum rtd_chip_revision chip_revision;
	unsigned int state;
	unsigned int hostinit;
};

#ifdef MY_DEF_HERE
extern int syno_compare_dts_ata_port(const struct ata_port *pAtaPort, const struct device_node *pDeviceNode);
/**
 * syno_ahci_rtk_compare_ata_devicetree_info - check the ata_port matches the device_node
 * @ap [IN]:   query ata_port
 * @pNode [IN]: comparing device_node
 *
 * return true: success
          false: fail
 */
bool syno_ahci_rtk_compare_ata_devicetree_info(const struct ata_port *ap, const struct device_node *pNode)
{
	int ret = false;
	struct device_node *pAhciRtkNode = NULL;
	if (NULL == ap || NULL == pNode) {
		goto END;
	}

	pAhciRtkNode = of_get_child_by_name(pNode, DT_AHCI_RTK);
	if (0 == syno_compare_dts_ata_port(ap, pAhciRtkNode)) {
		ret = true;
	}
	of_node_put(pAhciRtkNode);
END:
	return ret;
}
#endif /* MY_DEF_HERE */

void rtk_sata_phy_poweron(struct ata_link *link)
{
	struct ahci_rtk_dev *ahci_dev = g_hpriv->plat_data;
	struct ata_host *host;
	void __iomem *mmio = g_hpriv->mmio;
	unsigned val;
	int port;

	if (!ahci_dev) {
		pr_err("sata host not ready\n");
		return;
	}

	host = dev_get_drvdata(ahci_dev->dev);
	if (host != link->ap->host) {
		pr_err("host not match\n");
		return;
	}

	port = link->ap->port_no;
	if (port >= g_hpriv->nports || g_hpriv->phys[port] == NULL)
		return;
	if (g_hpriv->phys[port]->power_count == 0)
		phy_power_on(g_hpriv->phys[port]);

	if (ahci_dev->chip_id == CHIP_ID_RTD1619) {
		val = readl(mmio + 0xf18);
		val = val | (0x7 << 3*port);
		writel(val, mmio + 0xf18);
	}
}
EXPORT_SYMBOL_GPL(rtk_sata_phy_poweron);

static void rtk_sata_init(struct ahci_host_priv *hpriv)
{
	struct ahci_rtk_dev *ahci_dev = hpriv->plat_data;
	void __iomem *mmio = hpriv->mmio;
	unsigned int val;

	if (ahci_dev->chip_id == CHIP_ID_RTD1619) {
		writel(0x40, mmio + 0xf18);
		writel(0xc0c300, mmio + 0xf20);
		// COMINIT waveform adjustment
		writel(0x0506373e, mmio + 0xf28);
		writel(0x0506373e, mmio + 0xf2c);
		// COMINIT detect enable
		writel(0x42004200, mmio + 0xf04);
		// COMWAKE detect enable
		writel(0x02000200, mmio + 0xf08);
	}

	val = readl(mmio + 0xC);
	writel((val | 0x3), mmio + 0xC);
}

static int rtk_sata_dev_fun(void *data)
{
	struct ahci_rtk_dev *ahci_dev = (struct ahci_rtk_dev *)data;
	struct ata_host *host;
	struct ahci_host_priv *hpriv;
	struct ata_port *ap;
	struct scsi_device *sdev;
	int i;

	set_current_state(TASK_INTERRUPTIBLE);
	while (!kthread_should_stop()) {
		schedule();
		host = dev_get_drvdata(ahci_dev->dev);
		if (!host) {
			set_current_state(TASK_INTERRUPTIBLE);
			continue;
		}

		hpriv = host->private_data;
		for (i = 0; i < hpriv->nports; i++) {
			ap = host->ports[i];
			sdev = ap->link.device[0].sdev;
			if (!sdev)
				continue;
//			if (ap->scsi_host->shost_state == SHOST_RUNNING)
//				scsi_remove_device(sdev);
		}
		set_current_state(TASK_INTERRUPTIBLE);
	}

	return 0;
}
/*
static int rtk_sata_remove_scsi(struct ahci_rtk_dev *ahci_dev)
{
	struct ata_host *host;
	struct ahci_host_priv *hpriv;
	struct ata_port *ap;
	struct scsi_device *sdev;
	int i;

	host = dev_get_drvdata(ahci_dev->dev);
	if (!host)
		return 0;

	hpriv = host->private_data;
	for (i = 0; i < hpriv->nports; i++) {
		ap = host->ports[i];
		sdev = ap->link.device[0].sdev;
		if (!sdev)
			continue;
		if (ap->scsi_host->shost_state == SHOST_RUNNING)
			scsi_remove_device(sdev);
	}

	return 0;
}
*/
static void rtk_sata_host_resume(struct ahci_rtk_dev *ahci_dev)
{
	struct ata_host *host = dev_get_drvdata(ahci_dev->dev);
	struct ahci_host_priv *hpriv = host->private_data;
	struct ata_port *ap;
	int i;
	int resume_ok = 0;

	for (i = 0; i < hpriv->nports; i++) {
		ap = host->ports[i];
		if (ap->link.sata_spd &&
			ap->scsi_host->shost_state == SHOST_RUNNING)
			resume_ok++;
		else if (!ap->link.sata_spd)
			resume_ok++;
	}
	if (resume_ok != hpriv->nports)
		return;

	if (ahci_dev->state == RESUME) {
		ahci_dev->state = RESUME_OK;
		schedule_delayed_work(&ahci_dev->work, 500);
		return;
	}
	for (i = 0; i < hpriv->nports; i++) {
		ap = host->ports[i];
		if (ap->link.sata_spd) {
			dev_info(ahci_dev->dev, "ata scsi user scan\n");
			ata_scsi_user_scan(ap->scsi_host, 0, 0, 0);
		}
	}
	ahci_dev->state = RUNNING;
}

static void rtk_sata_power_ctrl(struct ahci_rtk_dev *ahci_dev)
{
	struct ata_host *host = dev_get_drvdata(ahci_dev->dev);
	struct ahci_host_priv *hpriv = host->private_data;
	struct device *dev = ahci_dev->dev;
	struct ata_port *ap;
	void __iomem *mmio = hpriv->mmio;
	unsigned int val;
	int i;

	if(!IS_ENABLED(POWER_SAVEING))
		return;

	for (i = 0; i < hpriv->nports; i++) {
		ap = host->ports[i];
		if (hpriv->phys[i] == NULL)
			continue;

		if (ahci_dev->ports[i]->power_save == 1 &&
			(ahci_dev->chip_id & 0xFFF0) == CHIP_ID_RTD129X) {
			phy_set_mode(hpriv->phys[i], 0);
			ahci_dev->ports[i]->power_save = 0;
			msleep(20);
		}
		if (ahci_dev->ports[i]->power_save == 1 &&
			ahci_dev->chip_id == CHIP_ID_RTD1619) {
			val = readl(mmio + 0xf04);
			if (!(val & (0x1000 << i*16)))
				continue;

			dev_info(dev, "sata%d plugin detect\n", i);
			writel((readl(mmio + 0xf04) & ~(0xffff << i*16)) | (0x6600 << i*16), mmio + 0xf04);
			writel((readl(mmio + 0xf08) & ~(0xffff << i*16)) | (0x0600 << i*16), mmio + 0xf08);

			phy_set_mode(hpriv->phys[i], 0);
			ahci_dev->ports[i]->power_save = 0;

			writel(readl(mmio + 0xf0c) & ~(0x3 << (i*4)), mmio + 0xf0c);
			writel((readl(mmio + 0xf04) & ~(0xffff << i*16)) | (0x4200 << i*16), mmio + 0xf04);
			writel((readl(mmio + 0xf08) & ~(0xffff << i*16)) | (0x0200 << i*16), mmio + 0xf08);
			writel(readl(mmio + 0xf18) | (0x7 << 3*i), mmio + 0xf18);

			msleep(20);
			continue;
		}
		if (!ap->hotplug_flag && !ap->link.sata_spd && ahci_dev->ports[i]->power_save == 0) {
			if (ap->pflags & ATA_PFLAG_EH_IN_PROGRESS)
				continue;

			dev_dbg(dev, "sata%d enter power down mode\n", i);

			if (ahci_dev->chip_id == CHIP_ID_RTD1619)
				writel(readl(mmio + 0xf18) & ~(0x7 << 3*i), mmio + 0xf18);

			phy_set_mode(hpriv->phys[i], 1);
			ahci_dev->ports[i]->power_save = 1;

			if (ahci_dev->chip_id == CHIP_ID_RTD1619) {
				writel(readl(mmio + 0xf0c) | (0x3 << (i*4)), mmio + 0xf0c);
				writel((readl(mmio + 0xf04) & ~(0xffff << i*16)) | (0x6600 << i*16), mmio + 0xf04);
				writel((readl(mmio + 0xf04) & ~(0xffff << i*16)) | (0x4200 << i*16), mmio + 0xf04);
				writel((readl(mmio + 0xf08) & ~(0xffff << i*16)) | (0x0600 << i*16), mmio + 0xf08);
				writel((readl(mmio + 0xf08) & ~(0xffff << i*16)) | (0x0200 << i*16), mmio + 0xf08);
			}
		}
	}
}

static void rtk_sata_host_ctrl(struct work_struct *work)
{
	struct ahci_rtk_dev *ahci_dev =
			container_of(work, struct ahci_rtk_dev, work.work);
	struct device *dev = ahci_dev->dev;
	struct platform_device *pdev =
			container_of(dev, struct platform_device, dev);
	struct ata_host *host = dev_get_drvdata(ahci_dev->dev);

	if (!host) {
		ahci_platform_init_host(pdev,
			ahci_dev->hpriv, &ahci_port_info, &ahci_platform_sht);
		if (IS_ENABLED(POWER_SAVEING))
			schedule_delayed_work(&ahci_dev->work, 2000);
		return;
	}

	switch (ahci_dev->state) {
	case RUNNING:
		if (IS_ENABLED(POWER_SAVEING)) {
			rtk_sata_power_ctrl(ahci_dev);
			schedule_delayed_work(&ahci_dev->work, 200);
		}
		break;
	case RESUME_OK:
	case RESUME:
		rtk_sata_host_resume(ahci_dev);
		schedule_delayed_work(&ahci_dev->work, 20);
		break;
	case SUSPEND:
	default:
		dev_err(ahci_dev->dev, "state error, do nothing\n");
		break;
	}
}

static void rtk_sata_power_io_ctrl(struct work_struct *work)
{
	struct ahci_rtk_dev *ahci_dev =
			container_of(work, struct ahci_rtk_dev, gpio);
	struct device *dev = ahci_dev->dev;
	struct device_node *node = dev->of_node;
	int power_io;
	static int cnt = 0;

	power_io = of_get_gpio(node, cnt);
	if (power_io >= 0) {
		gpio_request(power_io, node->name);
		gpio_set_value(power_io, 1);
		gpio_free(power_io);
		cnt++;
		msleep(3000);
		schedule_work(&ahci_dev->gpio);
	}
}

static int ahci_rtk_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct ahci_rtk_dev *ahci_dev;
	struct ahci_host_priv *hpriv;
	struct device_node *child;
	struct ahci_port_desc *desc;
	struct reset_control *rst;
	int power_io;
	int id;
	int i;

	ahci_dev = devm_kzalloc(dev, sizeof(struct ahci_rtk_dev), GFP_KERNEL);
	if (!ahci_dev)
		goto memalloc_fail;

	ahci_dev->chip_id = get_rtd_chip_id();
	ahci_dev->chip_revision = get_rtd_chip_revision();
	ahci_dev->dev = dev;

	hpriv = ahci_platform_get_resources(pdev);
	if (IS_ERR(hpriv))
		return PTR_ERR(hpriv);
	g_hpriv = hpriv;

	ahci_dev->ports = devm_kcalloc(dev, hpriv->nports,
				sizeof(*ahci_dev->ports), GFP_KERNEL);
	if (!ahci_dev->ports)
		goto memalloc_fail;

	for (i=0; i<MAC_MAX_RST; i++) {
		rst = of_reset_control_get_by_index(dev->of_node, i);
		if (IS_ERR(rst))
			break;
		ahci_dev->rsts[i] = rst;
		reset_control_deassert(rst);
	}

	of_property_read_u32(dev->of_node, "hostinit-mode", &ahci_dev->hostinit);

	power_io = of_get_gpio(dev->of_node, 0);
	if (power_io >= 0) {
		INIT_WORK(&ahci_dev->gpio, rtk_sata_power_io_ctrl);
		schedule_work(&ahci_dev->gpio);
	}

	for_each_available_child_of_node(dev->of_node, child) {
		desc = devm_kzalloc(dev, sizeof(*desc), GFP_KERNEL);
		if (!desc)
			goto memalloc_fail;

		if (of_property_read_u32(child, "reg", &id))
			goto dtb_fail;

		if (id >= hpriv->nports)
			goto dtb_fail;

		power_io = of_get_gpio(child, 0);
		if (power_io >= 0) {
			gpio_request(power_io, child->name);
			gpio_set_value(power_io, 1);
			gpio_free(power_io);
			desc->power_io = power_io;
		}
		for (i=0; i<MAC_MAX_RST; i++) {
			rst = of_reset_control_get_by_index(child, i);
			if (IS_ERR(rst))
				break;
			desc->rsts[i] = rst;
			reset_control_deassert(rst);
		}
		desc->index = id;
		ahci_dev->ports[id] = desc;
	}

	ahci_platform_enable_clks(hpriv);
	for (i = 0; i < hpriv->nports; i++) {
		phy_init(hpriv->phys[i]);
		ahci_dev->ports[i]->power_save = 0;
	}

	hpriv->plat_data = ahci_dev;
	ahci_dev->hpriv = hpriv;

	hpriv->flags |= AHCI_HFLAG_YES_FBS;

	rtk_sata_init(hpriv);
	ahci_dev->state = RUNNING;

	INIT_DELAYED_WORK(&ahci_dev->work, rtk_sata_host_ctrl);
	if (ahci_dev->hostinit) {
		ahci_platform_init_host(pdev,
			ahci_dev->hpriv, &ahci_port_info,
			&ahci_platform_sht);
		if (IS_ENABLED(POWER_SAVEING))
			schedule_delayed_work(&ahci_dev->work, 2000);
	} else
		schedule_delayed_work(&ahci_dev->work, 800);

	rtk_sata_dev_task = kthread_run(rtk_sata_dev_fun,
				ahci_dev, "rtk sata dev handle");

	return 0;

dtb_fail:
	dev_err(dev, "[SATA] get resource from dtb fail\n");
	return -EINVAL;

memalloc_fail:
	dev_err(dev, "[SATA] memalloc fail\n");
	return -ENOMEM;
}

static int ahci_rtk_prepare(struct device *dev)
{
	struct device_node *child;
	int power_io;
	int i;

	dev_info(dev, "enter %s\n", __func__);
//	rtk_sata_remove_scsi(ahci_dev);
//	wake_up_process(rtk_sata_dev_task);
//	msleep(1600);

	if (RTK_PM_STATE == PM_SUSPEND_STANDBY)
		goto exit;

	for (i=0; i<MAX_GPIO_CTL; i++) {
		power_io = of_get_gpio(dev->of_node, i);
		if (power_io >= 0) {
			gpio_request(power_io, NULL);
			gpio_set_value(power_io, 0);
			gpio_free(power_io);
		} else {
			break;
		}
	}

	for_each_available_child_of_node(dev->of_node, child) {
		power_io = of_get_gpio(child, 0);
		if (power_io >= 0) {
			gpio_request(power_io, NULL);
			gpio_set_value(power_io, 0);
			gpio_free(power_io);
		}
	}

exit:
	dev_info(dev, "exit %s\n", __func__);

	return 0;
}

#ifdef CONFIG_PM
static int ahci_rtk_suspend(struct device *dev)
{
	struct ata_host *host = dev_get_drvdata(dev);
	struct ahci_host_priv *hpriv = host->private_data;
	struct ahci_rtk_dev *ahci_dev = hpriv->plat_data;
	void __iomem *mmio = hpriv->mmio;
#ifdef DISABLE_CLKRST
	struct reset_control *rst;
	int i, j;
#endif
	int rc;

	dev_info(dev, "enter %s\n", __func__);

	cancel_delayed_work(&ahci_dev->work);
	rc = ahci_platform_suspend_host(dev);
	if (rc)
		return rc;

	if (ahci_dev->chip_id == CHIP_ID_RTD1619)
		writel(0x40, mmio + 0xf18);

	if (RTK_PM_STATE == PM_SUSPEND_STANDBY) {
		ahci_platform_disable_clks(hpriv);
	} else {
#ifdef DISABLE_CLKRST
		ahci_platform_disable_resources(hpriv);
		for (i = 0; i < hpriv->nports; i++) {
			for (j = 0; j < MAC_MAX_RST; j++) {
				rst = ahci_dev->ports[i]->rsts[j];
				if (rst != NULL)
					reset_control_assert(rst);
				else
					break;
			}
		}
		for (j = 0; j < MAC_MAX_RST; j++) {
			rst = ahci_dev->rsts[j];
			if (rst != NULL)
				reset_control_assert(rst);
			else
				break;
		}
#endif
	}

	dev_info(dev, "exit %s\n", __func__);
	return 0;
}

static void ahci_rtk_shutdown(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;

	dev_info(dev, "enter %s\n", __func__);
	ahci_rtk_suspend(dev);
	dev_info(dev, "exit %s\n", __func__);
}

static int ahci_rtk_resume(struct device *dev)
{
	struct ata_host *host = dev_get_drvdata(dev);
	struct ahci_host_priv *hpriv = host->private_data;
	struct ahci_rtk_dev *ahci_dev = hpriv->plat_data;
	struct device_node *child;
	struct reset_control *rst;
	int rc, i = 0, j;
	int power_io;

	dev_info(dev, "enter %s\n", __func__);

	power_io = of_get_gpio(dev->of_node, 0);
	if (power_io >= 0)
		schedule_work(&ahci_dev->gpio);

	for_each_available_child_of_node(dev->of_node, child) {
		power_io = of_get_gpio(child, 0);
		if (power_io >= 0) {
			ahci_dev->ports[i++]->power_io = power_io;
			gpio_request(power_io, NULL);
			gpio_set_value(power_io, 1);
			gpio_free(power_io);
		}
	}

	if (RTK_PM_STATE == PM_SUSPEND_STANDBY) {
		ahci_platform_enable_clks(hpriv);
		ahci_dev->state = RUNNING;
	} else {
		ahci_platform_disable_resources(hpriv);

		for (j = 0; j < MAC_MAX_RST; j++) {
			rst = ahci_dev->rsts[j];
			if (rst != NULL) {
				reset_control_assert(rst);
				reset_control_deassert(rst);
			} else
				break;
		}
		for (i = 0; i < hpriv->nports; i++) {
			for (j = 0; j < MAC_MAX_RST; j++) {
				rst = ahci_dev->ports[i]->rsts[j];
				if (rst != NULL) {
					reset_control_assert(rst);
					reset_control_deassert(rst);
				} else
					break;
			}
		}
		ahci_platform_enable_clks(hpriv);
		for (i = 0; i < hpriv->nports; i++) {
			phy_init(hpriv->phys[i]);
			ahci_dev->ports[i]->power_save = 0;
		}

		ahci_dev->state = RESUME;
		rtk_sata_init(hpriv);
	}
	rc = ahci_platform_resume_host(dev);
	if (rc)
		goto disable_resources;

	/* We resumed so update PM runtime state */
	pm_runtime_disable(dev);
	pm_runtime_set_active(dev);
	pm_runtime_enable(dev);

	schedule_delayed_work(&ahci_dev->work, 200);

	dev_info(dev, "exit %s\n", __func__);
	return 0;

disable_resources:
	ahci_platform_disable_resources(hpriv);
	return rc;
}

/*static SIMPLE_DEV_PM_OPS(ahci_rtk_pm_ops, ahci_rtk_suspend, ahci_rtk_resume);*/

static const struct dev_pm_ops ahci_rtk_pm_ops = {
	.prepare = ahci_rtk_prepare,
	.suspend = ahci_rtk_suspend,
	.resume = ahci_rtk_resume,
};
#else
static const struct dev_pm_ops ahci_rtk_pm_ops = {};
#endif

static const struct of_device_id ahci_rtk_of_match[] = {
	{ .compatible = "Realtek,ahci-sata", },
	{},
};
MODULE_DEVICE_TABLE(of, ahci_rtk_of_match);

static struct platform_driver ahci_rtk_driver = {
	.probe = ahci_rtk_probe,
	.remove = ata_platform_remove_one,
#ifdef CONFIG_PM
	.shutdown = ahci_rtk_shutdown,
#endif /* CONFIG_PM */
	.driver = {
		.name = DRV_NAME_RTK,
		.of_match_table = ahci_rtk_of_match,
#ifdef CONFIG_PM
		.pm = &ahci_rtk_pm_ops,
#endif
	},
};
module_platform_driver(ahci_rtk_driver);

MODULE_DESCRIPTION("RTK AHCI SATA platform driver");
MODULE_AUTHOR("Simon Hsu <simon_hsu@realtek.com>");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:ahci");
