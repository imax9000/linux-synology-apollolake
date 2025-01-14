/*
 * xHCI host controller driver PCI Bus Glue.
 *
 * Copyright (C) 2008 Intel Corp.
 *
 * Author: Sarah Sharp
 * Some code borrowed from the Linux EHCI driver.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <linux/pci.h>

#include "etxhci.h"

static struct table_item cfg_items_v00301500[] = {
	{0x44, 0x03},
	{0xf0, 0x00},
	{0xf1, 0x51},
	{0xf4, 0x00},
	{0xf0, 0x01},
	{0xf5, 0x15},
	{0xf0, 0x02},
	{0xf6, 0x30},
	{0xf0, 0x03},
	{0xf7, 0x00},
	{0xf0, 0x00},
	{0xf1, 0x00},
	{0xf4, 0x6f},
	{0xf0, 0x01},
	{0xf5, 0x1b},
	{0xf0, 0x02},
	{0xf6, 0x52},
	{0xf0, 0x03},
	{0xf7, 0x70},
	{0xf0, 0x2c},
	{0xf4, 0x6f},
	{0xf0, 0x2d},
	{0xf5, 0x1b},
	{0xf0, 0x2e},
	{0xf6, 0x52},
	{0xf0, 0x2f},
	{0xf7, 0x70},
	{0xf0, 0x98},
	{0xf4, 0x24},
	{0xf0, 0x11},
	{0xf1, 0x50},
	{0xf5, 0x00},
	{0xf0, 0x16},
	{0xf1, 0x30},
	{0xf6, 0x89},
	{0xf0, 0x17},
	{0xf7, 0x08},
	{0xf0, 0x18},
	{0xf4, 0xfc},
	{0xf0, 0x17},
	{0xf7, 0x08},
	{0xf0, 0x04},
	{0xf1, 0x50},
	{0xf4, 0x00},
	{0xf0, 0x08},
	{0xf4, 0x07},
	{0xf0, 0x10},
	{0xf4, 0x04},
	{0x44, 0x00},
};
#define CFG_ITEMS_V00301500	((int)(sizeof(cfg_items_v00301500)/sizeof(cfg_items_v00301500[0])))

static struct table_item mmio_items_v00301500[] = {
	{0x1811, 0x60},
	{0x5034, 0x6f},
	{0x5035, 0x1b},
	{0x0000, 0x20},
	{0x0001, 0x00},
	{0x0002, 0x00},
	{0x0003, 0x01},
	{0x0004, 0x50},
	{0x0005, 0x04},
	{0x0006, 0x00},
	{0x0007, 0x08},
	{0x0010, 0xa5},
	{0x0011, 0x40},
	{0x4011, 0x72},
	{0x4012, 0x00},
	{0x40f4, 0x02},
	{0x4100, 0x8f},
	{0x4101, 0x8f},
	{0x4102, 0x00},
	{0x4103, 0xff},
	{0x4104, 0xff},
	{0x4105, 0x0f},
	{0x4108, 0x1f},
	{0x4109, 0x0f},
	{0x410a, 0x00},
	{0x410b, 0xff},
	{0x410c, 0xff},
	{0x410d, 0x0f},
	{0x4110, 0x42},
	{0x4111, 0x42},
	{0x4112, 0x00},
	{0x4113, 0x44},
	{0x4114, 0x44},
	{0x4115, 0x04},
	{0x4120, 0x8f},
	{0x4121, 0x8f},
	{0x4122, 0x00},
	{0x4123, 0xff},
	{0x4124, 0xff},
	{0x4125, 0x0f},
	{0x4128, 0x1f},
	{0x4129, 0x0f},
	{0x412a, 0x00},
	{0x412b, 0xff},
	{0x412c, 0xff},
	{0x412d, 0x0f},
	{0x4130, 0x44},
	{0x4131, 0x44},
	{0x4132, 0x00},
	{0x4133, 0x44},
	{0x4134, 0x40},
	{0x4135, 0x04},
	{0x4142, 0x10},
	{0x4052, 0x01},
	{0x4211, 0xa0},
	{0x4251, 0xa0},
	{0x4380, 0xd2},
	{0x4381, 0x01},
	{0x4213, 0x01},
	{0x4253, 0x01},
	{0x4203, 0x80},
	{0x4243, 0x80},
	{0x4280, 0x00},
	{0x4281, 0x01},
	{0x4282, 0x00},
	{0x4283, 0x08},
	{0x42c0, 0x00},
	{0x42c1, 0x01},
	{0x42c2, 0x00},
	{0x42c3, 0x08},
	{0x4286, 0x20},
	{0x4287, 0x09},
	{0x42c6, 0x20},
	{0x42c7, 0x09},
	{0x428c, 0xc2},
	{0x42cc, 0xc2},
	{0x4294, 0x0c},
	{0x4297, 0x70},
	{0x42d4, 0x0c},
	{0x42d7, 0x70},
	{0x4288, 0x10},
	{0x4289, 0xf3},
	{0x42c8, 0x10},
	{0x42c9, 0xf3},
	{0x4305, 0x84},
	{0x4307, 0x10},
	{0x4309, 0x02},
	{0x430e, 0x80},
	{0x4313, 0x88},
	{0x440f, 0x10},
	{0x4410, 0xa8},
	{0x4411, 0x61},
	{0x444f, 0x10},
	{0x4450, 0xa8},
	{0x4451, 0x61},
	{0x448f, 0x10},
	{0x4490, 0xa8},
	{0x4491, 0x61},
	{0x44cf, 0x10},
	{0x44d0, 0xa8},
	{0x44d1, 0x61},
	{0x4424, 0x0d},
	{0x4425, 0x08},
	{0x4464, 0x0d},
	{0x4465, 0x08},
	{0x44a4, 0x0d},
	{0x44a5, 0x08},
	{0x44e4, 0x0d},
	{0x44e5, 0x08},
	{0x4428, 0xc8},
	{0x4429, 0x60},
	{0x442a, 0x58},
	{0x4468, 0xc8},
	{0x4469, 0x60},
	{0x446a, 0x58},
	{0x44a8, 0xc8},
	{0x44a9, 0x60},
	{0x44aa, 0x58},
	{0x44e8, 0xc8},
	{0x44e9, 0x60},
	{0x44ea, 0x58},
	{0x5036, 0x52},
	{0x5037, 0x70},
	{0x1811, 0x61},
};
#define MMIO_ITEMS_V00301500	((int)(sizeof(mmio_items_v00301500)/sizeof(mmio_items_v00301500[0])))

void xhci_init_ej188_v00301500(struct xhci_hcd *xhci)
{
	int i, error_flag = 0;
	struct usb_hcd *hcd = xhci_to_hcd(xhci);
	struct pci_dev *pdev = to_pci_dev(hcd->self.controller);
	u8 reg8 = 0;

	for (i = 0; i < CFG_ITEMS_V00301500; i++) {
		pci_write_config_byte(pdev, cfg_items_v00301500[i].offset,
			cfg_items_v00301500[i].value);
	}

	for (i = 0; i < MMIO_ITEMS_V00301500; i++) {
		xhci_writeb(xhci, mmio_items_v00301500[i].value,
			mmio_items_v00301500[i].offset);
	}

	for (i = 0; i < MMIO_ITEMS_V00301500; i++) {
		if ((0x1811 != mmio_items_v00301500[i].offset) && (0 == error_flag)) {
			reg8 = xhci_readb(xhci, mmio_items_v00301500[i].offset);
			if (reg8 != (u8)mmio_items_v00301500[i].value)
				error_flag = 1;
		}
	}

	if (error_flag) {
		for (i = 0; i < MMIO_ITEMS_V00301500; i++) {
			if (0x1811 != mmio_items_v00301500[i].offset) {
				reg8 = xhci_readb(xhci, mmio_items_v00301500[i].offset);
				xhci_err(xhci, "%s - @%04x %02x\n",
					__func__, mmio_items_v00301500[i].offset, reg8);
			}
		}
	}
}

