#ifndef MY_ABC_HERE
#define MY_ABC_HERE
#endif
#if defined(MY_DEF_HERE)
/*******************************************************************************
Copyright (C) Marvell International Ltd. and its affiliates

This software file (the "File") is owned and distributed by Marvell
International Ltd. and/or its affiliates ("Marvell") under the following
alternative licensing terms.  Once you have made an election to distribute the
File under one of the following license alternatives, please (i) delete this
introductory statement regarding license alternatives, (ii) delete the two
license alternatives that you have not elected to use and (iii) preserve the
Marvell copyright notice above.


********************************************************************************
Marvell GPL License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File in accordance with the terms and conditions of the General
Public License Version 2, June 1991 (the "GPL License"), a copy of which is
available along with the File in the license.txt file or by writing to the Free
Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 or
on the worldwide web at http://www.gnu.org/licenses/gpl.txt.

THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE IMPLIED
WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY
DISCLAIMED.  The GPL License provides additional details about this warranty
disclaimer.
*******************************************************************************/

#ifndef __mv_nss_regs_h__
#define __mv_nss_regs_h__

/* includes */
#include "common/mv_hw_if.h"

/* unit offset */
#define MV_PP3_NSS_UNIT_OFFSET		0x00010000


/* Power Management Clock Gating Control 1 */
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_REG				0x8a00
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_S_AMB_PWR_UP_OFFS		0
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_S_AMB_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_S_AMB_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_M0_AMB_PWR_UP_OFFS		1
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_M0_AMB_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_M0_AMB_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_M1_AMB_PWR_UP_OFFS		2
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_M1_AMB_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_M1_AMB_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_EIP150_AMB_PWR_UP_OFFS		3
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_EIP150_AMB_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_EIP150_AMB_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_MG_NSS_PWR_OFFS		4
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_MG_NSS_PWR_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_MG_NSS_PWR_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_MG_CORE_PWR_OFFS		5
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_MG_CORE_PWR_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_MG_CORE_PWR_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_GOP_DP_PWR_UP_OFFS		6
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_GOP_DP_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_GOP_DP_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_GOP_NSS_PWR_UP_OFFS		7
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_GOP_NSS_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_GOP_NSS_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_SRAM_X2_PWR_UP_OFFS		8
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_SRAM_X2_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_SRAM_X2_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_SRAM_PWR_UP_OFFS		9
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_SRAM_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_SRAM_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_PPC_CMAC_PWR_UP_OFFS		10
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_PPC_CMAC_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_PPC_CMAC_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_PPC_PWR_UP_OFFS		11
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_PPC_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_PPC_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_PPC_NSS_PWR_UP_OFFS		12
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_PPC_NSS_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_PPC_NSS_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_MACS_CMAC_PWR_UP_OFFS		13
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_MACS_CMAC_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_MACS_CMAC_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_MACS_PWR_UP_OFFS		14
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_MACS_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_MACS_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_QM2_PWR_UP_OFFS		15
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_QM2_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_QM2_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_QM1_X2_PWR_UP_OFFS		16
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_QM1_X2_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_QM1_X2_PWR_UP_OFFS)

#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_QM1_PWR_UP_OFFS		17
#define MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_QM1_PWR_UP_MASK    \
		(0x00000001 << MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_NSS_QM1_PWR_UP_OFFS)


/* System Soft Reset 1 */
#define MV_NSS_SYSTEM_SOFT_RESET_1_REG						0x8a08
#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_S_AMB_SW_RESET__OFFS		0
#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_S_AMB_SW_RESET__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_NSS_S_AMB_SW_RESET__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_M0_AMB_SW_RESET__OFFS		1
#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_M0_AMB_SW_RESET__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_NSS_M0_AMB_SW_RESET__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_M1_AMB_SW_RESET__OFFS		2
#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_M1_AMB_SW_RESET__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_NSS_M1_AMB_SW_RESET__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_EIP150_AMB_SW_RESET__OFFS		3
#define MV_NSS_SYSTEM_SOFT_RESET_1_EIP150_AMB_SW_RESET__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_EIP150_AMB_SW_RESET__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_MG_NSS_SW_RESET__OFFS		4
#define MV_NSS_SYSTEM_SOFT_RESET_1_MG_NSS_SW_RESET__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_MG_NSS_SW_RESET__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_MG_CORE_SW_RESET__OFFS		5
#define MV_NSS_SYSTEM_SOFT_RESET_1_MG_CORE_SW_RESET__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_MG_CORE_SW_RESET__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SW_RESET__OFFS		6
#define MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SW_RESET__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SW_RESET__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SW_LOAD_CONFIG__OFFS		8
#define MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SW_LOAD_CONFIG__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SW_LOAD_CONFIG__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_SRAM_SW_RESET__OFFS		9
#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_SRAM_SW_RESET__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_NSS_SRAM_SW_RESET__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_SRAM_SW_LOAD_CONFIG__OFFS		10
#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_SRAM_SW_LOAD_CONFIG__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_NSS_SRAM_SW_LOAD_CONFIG__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_PPC_SW_RESET__OFFS		11
#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_PPC_SW_RESET__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_NSS_PPC_SW_RESET__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_PPC_SW_LOAD_CONFIG__OFFS		12
#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_PPC_SW_LOAD_CONFIG__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_NSS_PPC_SW_LOAD_CONFIG__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_MACS_SW_RESET__OFFS		13
#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_MACS_SW_RESET__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_NSS_MACS_SW_RESET__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_MACS_SW_LOAD_CONFIG__OFFS		14
#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_MACS_SW_LOAD_CONFIG__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_NSS_MACS_SW_LOAD_CONFIG__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_QM2_SW_RESET__OFFS		15
#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_QM2_SW_RESET__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_NSS_QM2_SW_RESET__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_QM1_SW_RESET__OFFS		16
#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_QM1_SW_RESET__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_NSS_QM1_SW_RESET__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_QM1_SW_LOAD_CONFIG__OFFS		17
#define MV_NSS_SYSTEM_SOFT_RESET_1_NSS_QM1_SW_LOAD_CONFIG__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_NSS_QM1_SW_LOAD_CONFIG__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SD0_SW_LOAD_CONFIG__OFFS		18
#define MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SD0_SW_LOAD_CONFIG__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SD0_SW_LOAD_CONFIG__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SD1_SW_LOAD_CONFIG__OFFS		19
#define MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SD1_SW_LOAD_CONFIG__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SD1_SW_LOAD_CONFIG__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SD2_SW_LOAD_CONFIG__OFFS		20
#define MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SD2_SW_LOAD_CONFIG__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SD2_SW_LOAD_CONFIG__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SD3_SW_LOAD_CONFIG__OFFS		21
#define MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SD3_SW_LOAD_CONFIG__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_GOP_SD3_SW_LOAD_CONFIG__OFFS)

#define MV_NSS_SYSTEM_SOFT_RESET_1_MG_SW_LOAD_CONFIG__OFFS		22
#define MV_NSS_SYSTEM_SOFT_RESET_1_MG_SW_LOAD_CONFIG__MASK    \
		(0x00000001 << MV_NSS_SYSTEM_SOFT_RESET_1_MG_SW_LOAD_CONFIG__OFFS)


/* Ports Control 0 */
#define MV_NSS_PORTS_CTRL_0_REG						0x8a10
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_EN_DEVICE_OFFS		0
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_EN_DEVICE_MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_GOP_EN_DEVICE_OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_GOP_HALF_BUS_MODE_OFFS		1
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_HALF_BUS_MODE_MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_GOP_HALF_BUS_MODE_OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_GOP_XPCS_USE_EXT_TX_CLK__OFFS		2
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_XPCS_USE_EXT_TX_CLK__MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_GOP_XPCS_USE_EXT_TX_CLK__OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_GOP_BM2P0_PAUSE__OFFS		3
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_BM2P0_PAUSE__MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_GOP_BM2P0_PAUSE__OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_GOP_BM2P1_PAUSE__OFFS		4
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_BM2P1_PAUSE__MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_GOP_BM2P1_PAUSE__OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_GOP_BM2P2_PAUSE__OFFS		5
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_BM2P2_PAUSE__MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_GOP_BM2P2_PAUSE__OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_GOP_BM2P3_PAUSE__OFFS		6
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_BM2P3_PAUSE__MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_GOP_BM2P3_PAUSE__OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_GOP_GLOBAL_XOFF__OFFS		7
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_GLOBAL_XOFF__MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_GOP_GLOBAL_XOFF__OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_GOP_SERDES_LB_CLK_SEL_OFFS		8
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_SERDES_LB_CLK_SEL_MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_GOP_SERDES_LB_CLK_SEL_OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_MG_HI_Z_ALL__OFFS		9
#define MV_NSS_PORTS_CTRL_0_CONF_MG_HI_Z_ALL__MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_MG_HI_Z_ALL__OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_GOP_IO_DEBUG_BUS_EN_OFFS		10
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_IO_DEBUG_BUS_EN_MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_GOP_IO_DEBUG_BUS_EN_OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_GOP_PORT_DEBUG_CTRL_OFFS		11
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_PORT_DEBUG_CTRL_MASK    \
		(0x000003ff << MV_NSS_PORTS_CTRL_0_CONF_GOP_PORT_DEBUG_CTRL_OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_GOP_PORT_NUM_DEBUG_OFFS		21
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_PORT_NUM_DEBUG_MASK    \
		(0x0000003f << MV_NSS_PORTS_CTRL_0_CONF_GOP_PORT_NUM_DEBUG_OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_MG_DEBUG_EN_OFFS		27
#define MV_NSS_PORTS_CTRL_0_CONF_MG_DEBUG_EN_MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_MG_DEBUG_EN_OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_MG_IO_DEBUG_BUS_EN_OFFS		28
#define MV_NSS_PORTS_CTRL_0_CONF_MG_IO_DEBUG_BUS_EN_MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_MG_IO_DEBUG_BUS_EN_OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_SD_GIG_RF_RXDATA_SAMP_SEL_OFFS		29
#define MV_NSS_PORTS_CTRL_0_CONF_SD_GIG_RF_RXDATA_SAMP_SEL_MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_SD_GIG_RF_RXDATA_SAMP_SEL_OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_SD_GIG_RF_TXDATA_SAMP_SEL_OFFS		30
#define MV_NSS_PORTS_CTRL_0_CONF_SD_GIG_RF_TXDATA_SAMP_SEL_MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_SD_GIG_RF_TXDATA_SAMP_SEL_OFFS)

#define MV_NSS_PORTS_CTRL_0_CONF_GOP_CLK_DIV_PHASE_SET__OFFS		31
#define MV_NSS_PORTS_CTRL_0_CONF_GOP_CLK_DIV_PHASE_SET__MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_0_CONF_GOP_CLK_DIV_PHASE_SET__OFFS)


/* Ports Control 1 */
#define MV_NSS_PORTS_CTRL_1_REG								0x8a14
#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P0_PORT_ACTIVE_OFFS		0
#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P0_PORT_ACTIVE_MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_1_CONF_GOP_P0_PORT_ACTIVE_OFFS)

#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P1_PORT_ACTIVE_OFFS		1
#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P1_PORT_ACTIVE_MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_1_CONF_GOP_P1_PORT_ACTIVE_OFFS)

#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P2_PORT_ACTIVE_OFFS		2
#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P2_PORT_ACTIVE_MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_1_CONF_GOP_P2_PORT_ACTIVE_OFFS)

#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P3_PORT_ACTIVE_OFFS		3
#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P3_PORT_ACTIVE_MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_1_CONF_GOP_P3_PORT_ACTIVE_OFFS)

#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P0_PORT_NUM_OFFS		4
#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P0_PORT_NUM_MASK    \
		(0x0000003f << MV_NSS_PORTS_CTRL_1_CONF_GOP_P0_PORT_NUM_OFFS)

#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P1_PORT_NUM_OFFS		10
#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P1_PORT_NUM_MASK    \
		(0x0000003f << MV_NSS_PORTS_CTRL_1_CONF_GOP_P1_PORT_NUM_OFFS)

#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P2_PORT_NUM_OFFS		16
#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P2_PORT_NUM_MASK    \
		(0x0000003f << MV_NSS_PORTS_CTRL_1_CONF_GOP_P2_PORT_NUM_OFFS)

#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P3_PORT_NUM_OFFS		22
#define MV_NSS_PORTS_CTRL_1_CONF_GOP_P3_PORT_NUM_MASK    \
		(0x0000003f << MV_NSS_PORTS_CTRL_1_CONF_GOP_P3_PORT_NUM_OFFS)

#define MV_NSS_PORTS_CTRL_1_CONF_P0_SD_GIG_RF_RESET__OFFS		28
#define MV_NSS_PORTS_CTRL_1_CONF_P0_SD_GIG_RF_RESET__MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_1_CONF_P0_SD_GIG_RF_RESET__OFFS)

#define MV_NSS_PORTS_CTRL_1_CONF_P1_SD_GIG_RF_RESET__OFFS		29
#define MV_NSS_PORTS_CTRL_1_CONF_P1_SD_GIG_RF_RESET__MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_1_CONF_P1_SD_GIG_RF_RESET__OFFS)

#define MV_NSS_PORTS_CTRL_1_CONF_P2_SD_GIG_RF_RESET__OFFS		30
#define MV_NSS_PORTS_CTRL_1_CONF_P2_SD_GIG_RF_RESET__MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_1_CONF_P2_SD_GIG_RF_RESET__OFFS)

#define MV_NSS_PORTS_CTRL_1_CONF_P3_SD_GIG_RF_RESET__OFFS		31
#define MV_NSS_PORTS_CTRL_1_CONF_P3_SD_GIG_RF_RESET__MASK    \
		(0x00000001 << MV_NSS_PORTS_CTRL_1_CONF_P3_SD_GIG_RF_RESET__OFFS)


/* Ports Control 2 */
#define MV_NSS_PORTS_CTRL_2_REG								0x8a18
#define MV_NSS_PORTS_CTRL_2_CONF_SD0_IN_HF_CC_DELAY_OFFS		0
#define MV_NSS_PORTS_CTRL_2_CONF_SD0_IN_HF_CC_DELAY_MASK    \
		(0x0000000f << MV_NSS_PORTS_CTRL_2_CONF_SD0_IN_HF_CC_DELAY_OFFS)

#define MV_NSS_PORTS_CTRL_2_CONF_SD1_IN_HF_CC_DELAY_OFFS		4
#define MV_NSS_PORTS_CTRL_2_CONF_SD1_IN_HF_CC_DELAY_MASK    \
		(0x0000000f << MV_NSS_PORTS_CTRL_2_CONF_SD1_IN_HF_CC_DELAY_OFFS)

#define MV_NSS_PORTS_CTRL_2_CONF_SD2_IN_HF_CC_DELAY_OFFS		8
#define MV_NSS_PORTS_CTRL_2_CONF_SD2_IN_HF_CC_DELAY_MASK    \
		(0x0000000f << MV_NSS_PORTS_CTRL_2_CONF_SD2_IN_HF_CC_DELAY_OFFS)

#define MV_NSS_PORTS_CTRL_2_CONF_SD3_IN_HF_CC_DELAY_OFFS		12
#define MV_NSS_PORTS_CTRL_2_CONF_SD3_IN_HF_CC_DELAY_MASK    \
		(0x0000000f << MV_NSS_PORTS_CTRL_2_CONF_SD3_IN_HF_CC_DELAY_OFFS)


/* Ports Status 0 */
#define MV_NSS_PORTS_STATUS_0_REG							0x8a1c
#define MV_NSS_PORTS_STATUS_0_GOP_P0_LINK_ENABLE_OFFS		0
#define MV_NSS_PORTS_STATUS_0_GOP_P0_LINK_ENABLE_MASK    \
		(0x00000001 << MV_NSS_PORTS_STATUS_0_GOP_P0_LINK_ENABLE_OFFS)

#define MV_NSS_PORTS_STATUS_0_GOP_P1_LINK_ENABLE_OFFS		1
#define MV_NSS_PORTS_STATUS_0_GOP_P1_LINK_ENABLE_MASK    \
		(0x00000001 << MV_NSS_PORTS_STATUS_0_GOP_P1_LINK_ENABLE_OFFS)

#define MV_NSS_PORTS_STATUS_0_GOP_P2_LINK_ENABLE_OFFS		2
#define MV_NSS_PORTS_STATUS_0_GOP_P2_LINK_ENABLE_MASK    \
		(0x00000001 << MV_NSS_PORTS_STATUS_0_GOP_P2_LINK_ENABLE_OFFS)

#define MV_NSS_PORTS_STATUS_0_GOP_P3_LINK_ENABLE_OFFS		3
#define MV_NSS_PORTS_STATUS_0_GOP_P3_LINK_ENABLE_MASK    \
		(0x00000001 << MV_NSS_PORTS_STATUS_0_GOP_P3_LINK_ENABLE_OFFS)


/* Networking Complex Control 0 */
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_REG						0x8a20
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_GOP_P0_SGMII_XMII_MODE_OFFS		0
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_GOP_P0_SGMII_XMII_MODE_MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_GOP_P0_SGMII_XMII_MODE_OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_GOP_P1_SGMII_XMII_MODE_OFFS		1
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_GOP_P1_SGMII_XMII_MODE_MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_GOP_P1_SGMII_XMII_MODE_OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P0_RFU_FORCE_SPEED_OFFS		4
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P0_RFU_FORCE_SPEED_MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P0_RFU_FORCE_SPEED_OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P0_RFU_GMII_SPEED_OFFS		5
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P0_RFU_GMII_SPEED_MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P0_RFU_GMII_SPEED_OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P0_RFU_MII_SPEED_OFFS		6
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P0_RFU_MII_SPEED_MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P0_RFU_MII_SPEED_OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P1_RFU_FORCE_SPEED_OFFS		7
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P1_RFU_FORCE_SPEED_MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P1_RFU_FORCE_SPEED_OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P1_RFU_GMII_SPEED_OFFS		8
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P1_RFU_GMII_SPEED_MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P1_RFU_GMII_SPEED_OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P1_RFU_MII_SPEED_OFFS		9
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P1_RFU_MII_SPEED_MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_P1_RFU_MII_SPEED_OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_RXAUI_ENABLE_OFFS		10
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_RXAUI_ENABLE_MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_RXAUI_ENABLE_OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_XAUI_ENABLE_OFFS		11
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_XAUI_ENABLE_MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_XAUI_ENABLE_OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_NSS_PTP_TRIG_GEN_OE__OFFS		12
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_NSS_PTP_TRIG_GEN_OE__MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_NSS_PTP_TRIG_GEN_OE__OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_NSS_PTP_EVENT_REQ_OE__OFFS		13
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_NSS_PTP_EVENT_REQ_OE__MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_NSS_PTP_EVENT_REQ_OE__OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_EIP_INT_ACCESS_EN_OFFS		14
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_EIP_INT_ACCESS_EN_MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_EIP_INT_ACCESS_EN_OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_GOP_GIG_PLL_LOCK_OFFS		16
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_GOP_GIG_PLL_LOCK_MASK    \
		(0x0000000f << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_GOP_GIG_PLL_LOCK_OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_GOP_INV_SIGDET_OFFS		20
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_GOP_INV_SIGDET_MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_GOP_INV_SIGDET_OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_FORCE_G0_TXCLK__OFFS		28
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_FORCE_G0_TXCLK__MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_FORCE_G0_TXCLK__OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_FORCE_G1_TXCLK__OFFS		29
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_FORCE_G1_TXCLK__MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_FORCE_G1_TXCLK__OFFS)

#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_FORCE_GOP1_TXCLK__OFFS		31
#define MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_FORCE_GOP1_TXCLK__MASK    \
		(0x00000001 << MV_NSS_NETWORKING_COMPLEX_CTRL_0_CONF_FORCE_GOP1_TXCLK__OFFS)


/* Jtag Control */
#define MV_NSS_JTAG_CTRL_REG								0x8a50
#define MV_NSS_JTAG_CTRL_JCON_JT_RST_OFFS		1
#define MV_NSS_JTAG_CTRL_JCON_JT_RST_MASK    \
		(0x00000001 << MV_NSS_JTAG_CTRL_JCON_JT_RST_OFFS)

#define MV_NSS_JTAG_CTRL_JCON_JT_TDI_OFFS		2
#define MV_NSS_JTAG_CTRL_JCON_JT_TDI_MASK    \
		(0x00000001 << MV_NSS_JTAG_CTRL_JCON_JT_TDI_OFFS)

#define MV_NSS_JTAG_CTRL_JCON_JT_TMS_OFFS		3
#define MV_NSS_JTAG_CTRL_JCON_JT_TMS_MASK    \
		(0x00000001 << MV_NSS_JTAG_CTRL_JCON_JT_TMS_OFFS)

#define MV_NSS_JTAG_CTRL_JCON_JT_CLK_OFFS		4
#define MV_NSS_JTAG_CTRL_JCON_JT_CLK_MASK    \
		(0x00000001 << MV_NSS_JTAG_CTRL_JCON_JT_CLK_OFFS)

#define MV_NSS_JTAG_CTRL_JCON_JT_TDO_EN__OFFS		30
#define MV_NSS_JTAG_CTRL_JCON_JT_TDO_EN__MASK    \
		(0x00000001 << MV_NSS_JTAG_CTRL_JCON_JT_TDO_EN__OFFS)

#define MV_NSS_JTAG_CTRL_CONF_JCON_JT_TDO_OFFS		31
#define MV_NSS_JTAG_CTRL_CONF_JCON_JT_TDO_MASK    \
		(0x00000001 << MV_NSS_JTAG_CTRL_CONF_JCON_JT_TDO_OFFS)


/* Jtag Chains Configuration */
#define MV_NSS_JTAG_CHAINS_CFG_REG							0x8a54
#define MV_NSS_JTAG_CHAINS_CFG_CONF_JCON_BYPASS_NSS_JTAG_OFFS		0
#define MV_NSS_JTAG_CHAINS_CFG_CONF_JCON_BYPASS_NSS_JTAG_MASK    \
		(0x00000001 << MV_NSS_JTAG_CHAINS_CFG_CONF_JCON_BYPASS_NSS_JTAG_OFFS)

#define MV_NSS_JTAG_CHAINS_CFG_CONF_NSS_JTAG_CHAIN_SELECT_OFFS		1
#define MV_NSS_JTAG_CHAINS_CFG_CONF_NSS_JTAG_CHAIN_SELECT_MASK    \
		(0x00000003 << MV_NSS_JTAG_CHAINS_CFG_CONF_NSS_JTAG_CHAIN_SELECT_OFFS)

#define MV_NSS_JTAG_CHAINS_CFG_CONF_JCON_ENABLE_OFFS		3
#define MV_NSS_JTAG_CHAINS_CFG_CONF_JCON_ENABLE_MASK    \
		(0x00000001 << MV_NSS_JTAG_CHAINS_CFG_CONF_JCON_ENABLE_OFFS)

#define MV_NSS_JTAG_CHAINS_CFG_CONF_NSS_DEBUG_CONFIG_ONGOING_OFFS		8
#define MV_NSS_JTAG_CHAINS_CFG_CONF_NSS_DEBUG_CONFIG_ONGOING_MASK    \
		(0x00000001 << MV_NSS_JTAG_CHAINS_CFG_CONF_NSS_DEBUG_CONFIG_ONGOING_OFFS)


/* Nss Master  Amb Access Control 0 */
#define MV_NSS_MASTER_AMB_ACC_CTRL_0_REG(n)						(0x8ac0 + 0x20*n)
#define MV_NSS_MASTER_AMB_ACC_CTRL_0_CONF_A2M_INT_VAL0_OFFS			0

/* Nss Master  Amb Access Control 1 */
#define MV_NSS_MASTER_AMB_ACC_CTRL_1_REG(n)						(0x8ac4 + 0x20*n)
#define MV_NSS_MASTER_AMB_ACC_CTRL_1_CONF_A2M_INT_VAL1_OFFS		0

/* Nss Master  Amb Access Mask 0 */
#define MV_NSS_MASTER_AMB_ACC_MASK_0_REG(n)						(0x8ad0 + 0x20*n)
#define MV_NSS_MASTER_AMB_ACC_MASK_0_CONF_A2M_INT_MASK0_OFFS		0

/* Nss Master  Amb Access Mask 1 */
#define MV_NSS_MASTER_AMB_ACC_MASK_1_REG(n)						(0x8ad4 + 0x20*n)
#define MV_NSS_MASTER_AMB_ACC_MASK_1_CONF_A2M_INT_MASK1_OFFS		0

/******************************************************************************/
/*                       Register acceess Functions                           */
/******************************************************************************/
static inline u32  mv_pp3_nss_reg_read(u32 reg_addr)
{
	u32 reg_data;

	mv_pp3_hw_read(reg_addr + MV_PP3_NSS_UNIT_OFFSET, 1, &reg_data);

	return reg_data;
}

static inline void mv_pp3_nss_reg_print(char *reg_name, u32 reg)
{
	pr_info("  %-32s: 0x%x = 0x%08x\n", reg_name, reg, mv_pp3_nss_reg_read(reg));
}

static inline void mv_pp3_nss_reg_dump(void)
{
	int n;
	char reg_name[32];

	mv_pp3_nss_reg_print("POWER_MNG_CLOCK_GATING_CTRL_1", MV_NSS_POWER_MNG_CLOCK_GATING_CTRL_1_REG);
	mv_pp3_nss_reg_print("SYSTEM_SOFT_RESET_1", MV_NSS_SYSTEM_SOFT_RESET_1_REG);
	mv_pp3_nss_reg_print("PORTS_CTRL_0", MV_NSS_PORTS_CTRL_0_REG);
	mv_pp3_nss_reg_print("PORTS_CTRL_1", MV_NSS_PORTS_CTRL_1_REG);
	mv_pp3_nss_reg_print("PORTS_CTRL_2", MV_NSS_PORTS_CTRL_2_REG);
	mv_pp3_nss_reg_print("PORTS_STATUS_0", MV_NSS_PORTS_STATUS_0_REG);
	mv_pp3_nss_reg_print("NETWORKING_COMPLEX_CTRL_0", MV_NSS_NETWORKING_COMPLEX_CTRL_0_REG);
	mv_pp3_nss_reg_print("JTAG_CTRL", MV_NSS_JTAG_CTRL_REG);
	mv_pp3_nss_reg_print("JTAG_CHAINS_CFG", MV_NSS_JTAG_CHAINS_CFG_REG);
	for (n = 0; n < 2; n++) {
		sprintf(reg_name, "NSS_MASTER_%d_AMB_ACC_CTRL_0", n);
		mv_pp3_nss_reg_print(reg_name, MV_NSS_MASTER_AMB_ACC_CTRL_0_REG(n));
		sprintf(reg_name, "NSS_MASTER_%d_AMB_ACC_CTRL_1", n);
		mv_pp3_nss_reg_print(reg_name, MV_NSS_MASTER_AMB_ACC_CTRL_1_REG(n));
		sprintf(reg_name, "NSS_MASTER_%d_AMB_ACC_MASK_0", n);
		mv_pp3_nss_reg_print(reg_name, MV_NSS_MASTER_AMB_ACC_MASK_0_REG(n));
		sprintf(reg_name, "NSS_MASTER_%d_AMB_ACC_MASK_1", n);
		mv_pp3_nss_reg_print(reg_name, MV_NSS_MASTER_AMB_ACC_MASK_1_REG(n));
	}
}

#endif /* __mv_nss_regs_h__ */
#endif /* MY_DEF_HERE */
