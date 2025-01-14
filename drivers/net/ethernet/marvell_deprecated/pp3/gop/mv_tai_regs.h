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

#ifndef _mv_tai_regs_h_
#define _mv_tai_regs_h_

#ifdef __KERNEL__
/* includes */
#include "common/mv_hw_if.h"
#else
/* This "mv_*_regs.h is also included in User-space UIO */
#endif

/* unit offset (there are TAI & PTP which are the one same HW) */
#define MV_PP3_PTP_TAI_UNIT_OFFSET		0x03180000
#define MV_PP3_TAI_UNIT_OFFSET		MV_PP3_PTP_TAI_UNIT_OFFSET

/* Tai Control Reg0 */
#define MV_TAI_CTRL_REG0_REG								(0x0a08)
#define MV_TAI_CTRL_REG0_SW_RESET_OFFS		0
#define MV_TAI_CTRL_REG0_SW_RESET_MASK    \
		(0x00000001 << MV_TAI_CTRL_REG0_SW_RESET_OFFS)

/* Tai Control Reg1 */
#define MV_TAI_CTRL_REG1_REG						(0x0a0c)
#define MV_TAI_CTRL_REG1_TOD_INTERFACE_RATE_OFFS		0
#define MV_TAI_CTRL_REG1_TOD_INTERFACE_RATE_MASK    \
		(0x00000007 << MV_TAI_CTRL_REG1_TOD_INTERFACE_RATE_OFFS)

/* Time Counter Function Configuration 0 */
#define MV_TAI_TIME_CNTR_FUNC_CFG_0_REG					(0x0a10)
#define MV_TAI_TIME_CNTR_FUNC_CFG_0_TIME_CNTR_FUNC_TRIGGER_OFFS		0
#define MV_TAI_TIME_CNTR_FUNC_CFG_0_TIME_CNTR_FUNC_TRIGGER_MASK    \
		(0x00000001 << MV_TAI_TIME_CNTR_FUNC_CFG_0_TIME_CNTR_FUNC_TRIGGER_OFFS)

#define MV_TAI_TIME_CNTR_FUNC_CFG_0_TRIGGER_GENERATE_EN_OFFS		1
#define MV_TAI_TIME_CNTR_FUNC_CFG_0_TRIGGER_GENERATE_EN_MASK    \
		(0x00000001 << MV_TAI_TIME_CNTR_FUNC_CFG_0_TRIGGER_GENERATE_EN_OFFS)

#define MV_TAI_TIME_CNTR_FUNC_CFG_0_TIME_CNTR_FUNC_OFFS		2
#define MV_TAI_TIME_CNTR_FUNC_CFG_0_TIME_CNTR_FUNC_MASK    \
		(0x00000007 << MV_TAI_TIME_CNTR_FUNC_CFG_0_TIME_CNTR_FUNC_OFFS)

#define MV_TAI_TIME_CNTR_FUNC_CFG_0_EN_INCOMING_TRIGGER_CNTING_OFFS		5
#define MV_TAI_TIME_CNTR_FUNC_CFG_0_EN_INCOMING_TRIGGER_CNTING_MASK    \
		(0x00000001 << MV_TAI_TIME_CNTR_FUNC_CFG_0_EN_INCOMING_TRIGGER_CNTING_OFFS)

#define MV_TAI_TIME_CNTR_FUNC_CFG_0_CAPTURE_OVERWRITE_EN_OFFS		6
#define MV_TAI_TIME_CNTR_FUNC_CFG_0_CAPTURE_OVERWRITE_EN_MASK    \
		(0x00000001 << MV_TAI_TIME_CNTR_FUNC_CFG_0_CAPTURE_OVERWRITE_EN_OFFS)

#define MV_TAI_TIME_CNTR_FUNC_CFG_0_PCLK_DRIFT_ADJUSTMENT_EN_OFFS		7
#define MV_TAI_TIME_CNTR_FUNC_CFG_0_PCLK_DRIFT_ADJUSTMENT_EN_MASK    \
		(0x00000001 << MV_TAI_TIME_CNTR_FUNC_CFG_0_PCLK_DRIFT_ADJUSTMENT_EN_OFFS)

#define MV_TAI_TIME_CNTR_FUNC_CFG_0_INT_CLOCK_GENERATOR_EN_OFFS		8
#define MV_TAI_TIME_CNTR_FUNC_CFG_0_INT_CLOCK_GENERATOR_EN_MASK    \
		(0x00000001 << MV_TAI_TIME_CNTR_FUNC_CFG_0_INT_CLOCK_GENERATOR_EN_OFFS)

#define MV_TAI_TIME_CNTR_FUNC_CFG_0_CLOCK_MODE_OFFS		9
#define MV_TAI_TIME_CNTR_FUNC_CFG_0_CLOCK_MODE_MASK    \
		(0x00000003 << MV_TAI_TIME_CNTR_FUNC_CFG_0_CLOCK_MODE_OFFS)

#define MV_TAI_TIME_CNTR_FUNC_CFG_0_PCLK_COUNTER_START_OFFS		11
#define MV_TAI_TIME_CNTR_FUNC_CFG_0_PCLK_COUNTER_START_MASK    \
		(0x00000001 << MV_TAI_TIME_CNTR_FUNC_CFG_0_PCLK_COUNTER_START_OFFS)

#define MV_TAI_TIME_CNTR_FUNC_CFG_0_ONE_SHOT_UPDATE_OFFS		12
#define MV_TAI_TIME_CNTR_FUNC_CFG_0_ONE_SHOT_UPDATE_MASK    \
		(0x00000001 << MV_TAI_TIME_CNTR_FUNC_CFG_0_ONE_SHOT_UPDATE_OFFS)


/* Time Counter Function Configuration 1 */
#define MV_TAI_TIME_CNTR_FUNC_CFG_1_REG					(0x0a14)
#define MV_TAI_TIME_CNTR_FUNC_CFG_1_PULSE_WIDTH_BITS_0_15_OFFS		0
#define MV_TAI_TIME_CNTR_FUNC_CFG_1_PULSE_WIDTH_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TIME_CNTR_FUNC_CFG_1_PULSE_WIDTH_BITS_0_15_OFFS)


/* Time Counter Function Configuration 2 */
#define MV_TAI_TIME_CNTR_FUNC_CFG_2_REG					(0x0a18)
#define MV_TAI_TIME_CNTR_FUNC_CFG_2_PULSE_WIDTH_BITS_16_27_OFFS		0
#define MV_TAI_TIME_CNTR_FUNC_CFG_2_PULSE_WIDTH_BITS_16_27_MASK    \
		(0x00000fff << MV_TAI_TIME_CNTR_FUNC_CFG_2_PULSE_WIDTH_BITS_16_27_OFFS)


/* Frequency Adjust Time Window */
#define MV_TAI_FREQUENCY_ADJUST_TIME_WINDOW_REG				(0x0a1c)
#define MV_TAI_FREQUENCY_ADJUST_TIME_WINDOW_FREQUENCY_ADJUST_TIME_WINDOW_OFFS		0
#define MV_TAI_FREQUENCY_ADJUST_TIME_WINDOW_FREQUENCY_ADJUST_TIME_WINDOW_MASK    \
		(0x00000007 << MV_TAI_FREQUENCY_ADJUST_TIME_WINDOW_FREQUENCY_ADJUST_TIME_WINDOW_OFFS)

#define MV_TAI_FREQUENCY_ADJUST_TIME_WINDOW_CLOCK_GEN_SM_DIVIDER_OFFS		3
#define MV_TAI_FREQUENCY_ADJUST_TIME_WINDOW_CLOCK_GEN_SM_DIVIDER_MASK    \
		(0x00000003 << MV_TAI_FREQUENCY_ADJUST_TIME_WINDOW_CLOCK_GEN_SM_DIVIDER_OFFS)

#define MV_TAI_FREQUENCY_ADJUST_TIME_WINDOW_DRIFT_ADJUST_VALUE_OFFS		5
#define MV_TAI_FREQUENCY_ADJUST_TIME_WINDOW_DRIFT_ADJUST_VALUE_MASK    \
		(0x00000001 << MV_TAI_FREQUENCY_ADJUST_TIME_WINDOW_DRIFT_ADJUST_VALUE_OFFS)


/* Tod Step Nano Configuration */
#define MV_TAI_TOD_STEP_NANO_CFG_REG						(0x0a20)
#define MV_TAI_TOD_STEP_NANO_CFG_TOD_STEP_NANOSECONDS_OFFS		0
#define MV_TAI_TOD_STEP_NANO_CFG_TOD_STEP_NANOSECONDS_MASK    \
		(0x0000ffff << MV_TAI_TOD_STEP_NANO_CFG_TOD_STEP_NANOSECONDS_OFFS)


/* Tod Step Frac Configuration High */
#define MV_TAI_TOD_STEP_FRAC_CFG_HIGH_REG						(0x0a24)
#define MV_TAI_TOD_STEP_FRAC_CFG_HIGH_TOD_STEP_FRACTIONAL_NANOSECONDS_BITS_16_31_OFFS		0
#define MV_TAI_TOD_STEP_FRAC_CFG_HIGH_TOD_STEP_FRACTIONAL_NANOSECONDS_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TOD_STEP_FRAC_CFG_HIGH_TOD_STEP_FRACTIONAL_NANOSECONDS_BITS_16_31_OFFS)


/* Tod Step Frac Configuration Low */
#define MV_TAI_TOD_STEP_FRAC_CFG_LOW_REG						(0x0a28)
#define MV_TAI_TOD_STEP_FRAC_CFG_LOW_TOD_STEP_FRACTIONAL_NANOSECONDS_BITS_0_15_OFFS		0
#define MV_TAI_TOD_STEP_FRAC_CFG_LOW_TOD_STEP_FRACTIONAL_NANOSECONDS_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TOD_STEP_FRAC_CFG_LOW_TOD_STEP_FRACTIONAL_NANOSECONDS_BITS_0_15_OFFS)


/* Time Adjustment Propagation Delay Configuration High */
#define MV_TAI_TIME_ADJUSTMENT_PROPAGATION_DELAY_CFG_HIGH_REG			(0x0a2c)
#define MV_TAI_TIME_ADJUSTMENT_PROPAGATION_DELAY_CFG_HIGH_PULSE_DELAY_BITS_16_31_OFFS		0
#define MV_TAI_TIME_ADJUSTMENT_PROPAGATION_DELAY_CFG_HIGH_PULSE_DELAY_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TIME_ADJUSTMENT_PROPAGATION_DELAY_CFG_HIGH_PULSE_DELAY_BITS_16_31_OFFS)


/* Time Adjustment Propagation Delay Configuration Low */
#define MV_TAI_TIME_ADJUSTMENT_PROPAGATION_DELAY_CFG_LOW_REG			(0x0a30)
#define MV_TAI_TIME_ADJUSTMENT_PROPAGATION_DELAY_CFG_LOW_PULSE_DELAY_BITS_0_15_OFFS		0
#define MV_TAI_TIME_ADJUSTMENT_PROPAGATION_DELAY_CFG_LOW_PULSE_DELAY_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TIME_ADJUSTMENT_PROPAGATION_DELAY_CFG_LOW_PULSE_DELAY_BITS_0_15_OFFS)


/* Trigger Generation Tod Sec High */
#define MV_TAI_TRIGGER_GENERATION_TOD_SEC_HIGH_REG					(0x0a34)
#define MV_TAI_TRIGGER_GENERATION_TOD_SEC_HIGH_TRIGGER_GENERATION_TOD_SEC_BITS_32_47_OFFS		0
#define MV_TAI_TRIGGER_GENERATION_TOD_SEC_HIGH_TRIGGER_GENERATION_TOD_SEC_BITS_32_47_MASK    \
		(0x0000ffff << MV_TAI_TRIGGER_GENERATION_TOD_SEC_HIGH_TRIGGER_GENERATION_TOD_SEC_BITS_32_47_OFFS)


/* Trigger Generation Tod Sec Med */
#define MV_TAI_TRIGGER_GENERATION_TOD_SEC_MED_REG					(0x0a38)
#define MV_TAI_TRIGGER_GENERATION_TOD_SEC_MED_TRIGGER_GENERATION_TOD_SEC_BITS_16_31_OFFS		0
#define MV_TAI_TRIGGER_GENERATION_TOD_SEC_MED_TRIGGER_GENERATION_TOD_SEC_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TRIGGER_GENERATION_TOD_SEC_MED_TRIGGER_GENERATION_TOD_SEC_BITS_16_31_OFFS)


/* Trigger Generation Tod Sec Low */
#define MV_TAI_TRIGGER_GENERATION_TOD_SEC_LOW_REG					(0x0a3c)
#define MV_TAI_TRIGGER_GENERATION_TOD_SEC_LOW_TRIGGER_GENERATION_TOD_SEC_BITS_0_15_OFFS		0
#define MV_TAI_TRIGGER_GENERATION_TOD_SEC_LOW_TRIGGER_GENERATION_TOD_SEC_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TRIGGER_GENERATION_TOD_SEC_LOW_TRIGGER_GENERATION_TOD_SEC_BITS_0_15_OFFS)


/* Trigger Generation Tod Nano High */
#define MV_TAI_TRIGGER_GENERATION_TOD_NANO_HIGH_REG					(0x0a40)
#define MV_TAI_TRIGGER_GENERATION_TOD_NANO_HIGH_TRIGGER_GENERATION_TOD_NANO_BITS_16_31_OFFS		0
#define MV_TAI_TRIGGER_GENERATION_TOD_NANO_HIGH_TRIGGER_GENERATION_TOD_NANO_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TRIGGER_GENERATION_TOD_NANO_HIGH_TRIGGER_GENERATION_TOD_NANO_BITS_16_31_OFFS)


/* Trigger Generation Tod Nano Low */
#define MV_TAI_TRIGGER_GENERATION_TOD_NANO_LOW_REG					(0x0a44)
#define MV_TAI_TRIGGER_GENERATION_TOD_NANO_LOW_TRIGGER_GENERATION_TOD_NANO_BITS_0_15_OFFS		0
#define MV_TAI_TRIGGER_GENERATION_TOD_NANO_LOW_TRIGGER_GENERATION_TOD_NANO_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TRIGGER_GENERATION_TOD_NANO_LOW_TRIGGER_GENERATION_TOD_NANO_BITS_0_15_OFFS)


/* Trigger Generation Tod Frac High */
#define MV_TAI_TRIGGER_GENERATION_TOD_FRAC_HIGH_REG					(0x0a48)
#define MV_TAI_TRIGGER_GENERATION_TOD_FRAC_HIGH_TRIGGER_GENERATION_TOD_FRAC_BITS_16_31_OFFS		0
#define MV_TAI_TRIGGER_GENERATION_TOD_FRAC_HIGH_TRIGGER_GENERATION_TOD_FRAC_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TRIGGER_GENERATION_TOD_FRAC_HIGH_TRIGGER_GENERATION_TOD_FRAC_BITS_16_31_OFFS)


/* Trigger Generation Tod Frac Low */
#define MV_TAI_TRIGGER_GENERATION_TOD_FRAC_LOW_REG					(0x0a4c)
#define MV_TAI_TRIGGER_GENERATION_TOD_FRAC_LOW_TRIGGER_GENERATION_TOD_FRAC_BITS_0_15_OFFS		0
#define MV_TAI_TRIGGER_GENERATION_TOD_FRAC_LOW_TRIGGER_GENERATION_TOD_FRAC_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TRIGGER_GENERATION_TOD_FRAC_LOW_TRIGGER_GENERATION_TOD_FRAC_BITS_0_15_OFFS)


/* Time Load Value Sec High */
#define MV_TAI_TIME_LOAD_VALUE_SEC_HIGH_REG						(0x0a50)
#define MV_TAI_TIME_LOAD_VALUE_SEC_HIGH_TIME_LOAD_VALUE_SEC_BITS_32_47_OFFS		0
#define MV_TAI_TIME_LOAD_VALUE_SEC_HIGH_TIME_LOAD_VALUE_SEC_BITS_32_47_MASK    \
		(0x0000ffff << MV_TAI_TIME_LOAD_VALUE_SEC_HIGH_TIME_LOAD_VALUE_SEC_BITS_32_47_OFFS)


/* Time Load Value Sec Med */
#define MV_TAI_TIME_LOAD_VALUE_SEC_MED_REG						(0x0a54)
#define MV_TAI_TIME_LOAD_VALUE_SEC_MED_TIME_LOAD_VALUE_SEC_BITS_16_31_OFFS		0
#define MV_TAI_TIME_LOAD_VALUE_SEC_MED_TIME_LOAD_VALUE_SEC_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TIME_LOAD_VALUE_SEC_MED_TIME_LOAD_VALUE_SEC_BITS_16_31_OFFS)


/* Time Load Value Sec Low */
#define MV_TAI_TIME_LOAD_VALUE_SEC_LOW_REG						(0x0a58)
#define MV_TAI_TIME_LOAD_VALUE_SEC_LOW_TIME_LOAD_VALUE_SEC_BITS_0_15_OFFS		0
#define MV_TAI_TIME_LOAD_VALUE_SEC_LOW_TIME_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TIME_LOAD_VALUE_SEC_LOW_TIME_LOAD_VALUE_SEC_BITS_0_15_OFFS)


/* Time Load Value Nano High */
#define MV_TAI_TIME_LOAD_VALUE_NANO_HIGH_REG					(0x0a5c)
#define MV_TAI_TIME_LOAD_VALUE_NANO_HIGH_TIME_LOAD_VALUE_NANO_BITS_16_31_OFFS		0
#define MV_TAI_TIME_LOAD_VALUE_NANO_HIGH_TIME_LOAD_VALUE_NANO_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TIME_LOAD_VALUE_NANO_HIGH_TIME_LOAD_VALUE_NANO_BITS_16_31_OFFS)


/* Time Load Value Nano Low */
#define MV_TAI_TIME_LOAD_VALUE_NANO_LOW_REG						(0x0a60)
#define MV_TAI_TIME_LOAD_VALUE_NANO_LOW_TIME_LOAD_VALUE_NANO_BITS_0_15_OFFS		0
#define MV_TAI_TIME_LOAD_VALUE_NANO_LOW_TIME_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TIME_LOAD_VALUE_NANO_LOW_TIME_LOAD_VALUE_NANO_BITS_0_15_OFFS)


/* Time Load Value Frac High */
#define MV_TAI_TIME_LOAD_VALUE_FRAC_HIGH_REG					(0x0a64)
#define MV_TAI_TIME_LOAD_VALUE_FRAC_HIGH_TIME_LOAD_VALUE_FRAC_BITS_16_31_OFFS		0
#define MV_TAI_TIME_LOAD_VALUE_FRAC_HIGH_TIME_LOAD_VALUE_FRAC_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TIME_LOAD_VALUE_FRAC_HIGH_TIME_LOAD_VALUE_FRAC_BITS_16_31_OFFS)


/* Time Load Value Frac Low */
#define MV_TAI_TIME_LOAD_VALUE_FRAC_LOW_REG						(0x0a68)
#define MV_TAI_TIME_LOAD_VALUE_FRAC_LOW_TIME_LOAD_VALUE_FRAC_BITS_0_15_OFFS		0
#define MV_TAI_TIME_LOAD_VALUE_FRAC_LOW_TIME_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TIME_LOAD_VALUE_FRAC_LOW_TIME_LOAD_VALUE_FRAC_BITS_0_15_OFFS)


/* Time Capture Value 0 Sec High */
#define MV_TAI_TIME_CAPTURE_VALUE_0_SEC_HIGH_REG					(0x0a6c)
#define MV_TAI_TIME_CAPTURE_VALUE_0_SEC_HIGH_TIME_CAPTURE_VALUE_0_SEC_BITS_32_47_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_0_SEC_HIGH_TIME_CAPTURE_VALUE_0_SEC_BITS_32_47_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_0_SEC_HIGH_TIME_CAPTURE_VALUE_0_SEC_BITS_32_47_OFFS)


/* Time Capture Value 0 Sec Med */
#define MV_TAI_TIME_CAPTURE_VALUE_0_SEC_MED_REG					(0x0a70)
#define MV_TAI_TIME_CAPTURE_VALUE_0_SEC_MED_TIME_CAPTURE_VALUE_0_SEC_BITS_16_31_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_0_SEC_MED_TIME_CAPTURE_VALUE_0_SEC_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_0_SEC_MED_TIME_CAPTURE_VALUE_0_SEC_BITS_16_31_OFFS)


/* Time Capture Value 0 Sec Low */
#define MV_TAI_TIME_CAPTURE_VALUE_0_SEC_LOW_REG					(0x0a74)
#define MV_TAI_TIME_CAPTURE_VALUE_0_SEC_LOW_TIME_CAPTURE_VALUE_0_SEC_BITS_0_15_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_0_SEC_LOW_TIME_CAPTURE_VALUE_0_SEC_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_0_SEC_LOW_TIME_CAPTURE_VALUE_0_SEC_BITS_0_15_OFFS)


/* Time Capture Value 0 Nano High */
#define MV_TAI_TIME_CAPTURE_VALUE_0_NANO_HIGH_REG					(0x0a78)
#define MV_TAI_TIME_CAPTURE_VALUE_0_NANO_HIGH_TIME_CAPTURE_VALUE_0_NANO_BITS_16_31_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_0_NANO_HIGH_TIME_CAPTURE_VALUE_0_NANO_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_0_NANO_HIGH_TIME_CAPTURE_VALUE_0_NANO_BITS_16_31_OFFS)


/* Time Capture Value 0 Nano Low */
#define MV_TAI_TIME_CAPTURE_VALUE_0_NANO_LOW_REG					(0x0a7c)
#define MV_TAI_TIME_CAPTURE_VALUE_0_NANO_LOW_TIME_CAPTURE_VALUE_0_NANO_BITS_0_15_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_0_NANO_LOW_TIME_CAPTURE_VALUE_0_NANO_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_0_NANO_LOW_TIME_CAPTURE_VALUE_0_NANO_BITS_0_15_OFFS)


/* Time Capture Value 0 Frac High */
#define MV_TAI_TIME_CAPTURE_VALUE_0_FRAC_HIGH_REG					(0x0a80)
#define MV_TAI_TIME_CAPTURE_VALUE_0_FRAC_HIGH_TIME_CAPTURE_VALUE_0_FRAC_BITS_16_31_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_0_FRAC_HIGH_TIME_CAPTURE_VALUE_0_FRAC_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_0_FRAC_HIGH_TIME_CAPTURE_VALUE_0_FRAC_BITS_16_31_OFFS)


/* Time Capture Value 0 Frac Low */
#define MV_TAI_TIME_CAPTURE_VALUE_0_FRAC_LOW_REG					(0x0a84)
#define MV_TAI_TIME_CAPTURE_VALUE_0_FRAC_LOW_TIME_CAPTURE_VALUE_0_FRAC_BITS_0_15_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_0_FRAC_LOW_TIME_CAPTURE_VALUE_0_FRAC_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_0_FRAC_LOW_TIME_CAPTURE_VALUE_0_FRAC_BITS_0_15_OFFS)


/* Time Capture Value 1 Sec High */
#define MV_TAI_TIME_CAPTURE_VALUE_1_SEC_HIGH_REG					(0x0a88)
#define MV_TAI_TIME_CAPTURE_VALUE_1_SEC_HIGH_TIME_CAPTURE_VALUE_1_SEC_BITS_32_47_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_1_SEC_HIGH_TIME_CAPTURE_VALUE_1_SEC_BITS_32_47_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_1_SEC_HIGH_TIME_CAPTURE_VALUE_1_SEC_BITS_32_47_OFFS)


/* Time Capture Value 1 Sec Med */
#define MV_TAI_TIME_CAPTURE_VALUE_1_SEC_MED_REG					(0x0a8c)
#define MV_TAI_TIME_CAPTURE_VALUE_1_SEC_MED_TIME_CAPTURE_VALUE_1_SEC_BITS_16_31_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_1_SEC_MED_TIME_CAPTURE_VALUE_1_SEC_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_1_SEC_MED_TIME_CAPTURE_VALUE_1_SEC_BITS_16_31_OFFS)


/* Time Capture Value 1 Sec Low */
#define MV_TAI_TIME_CAPTURE_VALUE_1_SEC_LOW_REG					(0x0a90)
#define MV_TAI_TIME_CAPTURE_VALUE_1_SEC_LOW_TIME_CAPTURE_VALUE_1_SEC_BITS_0_15_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_1_SEC_LOW_TIME_CAPTURE_VALUE_1_SEC_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_1_SEC_LOW_TIME_CAPTURE_VALUE_1_SEC_BITS_0_15_OFFS)


/* Time Capture Value 1 Nano High */
#define MV_TAI_TIME_CAPTURE_VALUE_1_NANO_HIGH_REG					(0x0a94)
#define MV_TAI_TIME_CAPTURE_VALUE_1_NANO_HIGH_TIME_CAPTURE_VALUE_1_NANO_BITS_16_31_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_1_NANO_HIGH_TIME_CAPTURE_VALUE_1_NANO_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_1_NANO_HIGH_TIME_CAPTURE_VALUE_1_NANO_BITS_16_31_OFFS)


/* Time Capture Value 1 Nano Low */
#define MV_TAI_TIME_CAPTURE_VALUE_1_NANO_LOW_REG					(0x0a98)
#define MV_TAI_TIME_CAPTURE_VALUE_1_NANO_LOW_TIME_CAPTURE_VALUE_1_NANO_BITS_0_15_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_1_NANO_LOW_TIME_CAPTURE_VALUE_1_NANO_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_1_NANO_LOW_TIME_CAPTURE_VALUE_1_NANO_BITS_0_15_OFFS)


/* Time Capture Value 1 Frac High */
#define MV_TAI_TIME_CAPTURE_VALUE_1_FRAC_HIGH_REG					(0x0a9c)
#define MV_TAI_TIME_CAPTURE_VALUE_1_FRAC_HIGH_TIME_CAPTURE_VALUE_1_FRAC_BITS_16_31_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_1_FRAC_HIGH_TIME_CAPTURE_VALUE_1_FRAC_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_1_FRAC_HIGH_TIME_CAPTURE_VALUE_1_FRAC_BITS_16_31_OFFS)


/* Time Capture Value 1 Frac Low */
#define MV_TAI_TIME_CAPTURE_VALUE_1_FRAC_LOW_REG					(0x0aa0)
#define MV_TAI_TIME_CAPTURE_VALUE_1_FRAC_LOW_TIME_CAPTURE_VALUE_1_FRAC_BITS_0_15_OFFS		0
#define MV_TAI_TIME_CAPTURE_VALUE_1_FRAC_LOW_TIME_CAPTURE_VALUE_1_FRAC_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_TIME_CAPTURE_VALUE_1_FRAC_LOW_TIME_CAPTURE_VALUE_1_FRAC_BITS_0_15_OFFS)


/* Time Capture Status */
#define MV_TAI_TIME_CAPTURE_STATUS_REG						(0x0aa4)
#define MV_TAI_TIME_CAPTURE_STATUS_CAPTURE_0_VALID_OFFS		0
#define MV_TAI_TIME_CAPTURE_STATUS_CAPTURE_0_VALID_MASK    \
		(0x00000001 << MV_TAI_TIME_CAPTURE_STATUS_CAPTURE_0_VALID_OFFS)

#define MV_TAI_TIME_CAPTURE_STATUS_CAPTURE_1_VALID_OFFS		1
#define MV_TAI_TIME_CAPTURE_STATUS_CAPTURE_1_VALID_MASK    \
		(0x00000001 << MV_TAI_TIME_CAPTURE_STATUS_CAPTURE_1_VALID_OFFS)


/* Time Update Counter LSB */
#define MV_TAI_TIME_UPDATE_CNTR_LSB_REG						(0x0aa8)
#define MV_TAI_TIME_UPDATE_CNTR_LSB_TIME_UPDATE_CNTR_LSB_OFFS		0
#define MV_TAI_TIME_UPDATE_CNTR_LSB_TIME_UPDATE_CNTR_LSB_MASK    \
		(0x0000ffff << MV_TAI_TIME_UPDATE_CNTR_LSB_TIME_UPDATE_CNTR_LSB_OFFS)


/* Generate Function Mask Sec High */
#define MV_TAI_GENERATE_FUNCTION_MASK_SEC_HIGH_REG					(0x0aac)
#define MV_TAI_GENERATE_FUNCTION_MASK_SEC_HIGH_GENERATE_FUNCTION_MASK_SEC_BITS_32_47_OFFS		0
#define MV_TAI_GENERATE_FUNCTION_MASK_SEC_HIGH_GENERATE_FUNCTION_MASK_SEC_BITS_32_47_MASK    \
		(0x0000ffff << MV_TAI_GENERATE_FUNCTION_MASK_SEC_HIGH_GENERATE_FUNCTION_MASK_SEC_BITS_32_47_OFFS)


/* Generate Function Mask Sec Med */
#define MV_TAI_GENERATE_FUNCTION_MASK_SEC_MED_REG					(0x0ab0)
#define MV_TAI_GENERATE_FUNCTION_MASK_SEC_MED_GENERATE_FUNCTION_MASK_SEC_BITS_16_31_OFFS		0
#define MV_TAI_GENERATE_FUNCTION_MASK_SEC_MED_GENERATE_FUNCTION_MASK_SEC_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_GENERATE_FUNCTION_MASK_SEC_MED_GENERATE_FUNCTION_MASK_SEC_BITS_16_31_OFFS)


/* Generate Function Mask Sec Low */
#define MV_TAI_GENERATE_FUNCTION_MASK_SEC_LOW_REG					(0x0ab4)
#define MV_TAI_GENERATE_FUNCTION_MASK_SEC_LOW_GENERATE_FUNCTION_MASK_SEC_BITS_0_15_OFFS		0
#define MV_TAI_GENERATE_FUNCTION_MASK_SEC_LOW_GENERATE_FUNCTION_MASK_SEC_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_GENERATE_FUNCTION_MASK_SEC_LOW_GENERATE_FUNCTION_MASK_SEC_BITS_0_15_OFFS)


/* Generate Function Mask Nano High */
#define MV_TAI_GENERATE_FUNCTION_MASK_NANO_HIGH_REG					(0x0ab8)
#define MV_TAI_GENERATE_FUNCTION_MASK_NANO_HIGH_GENERATE_FUNCTION_MASK_NANO_BITS_16_31_OFFS		0
#define MV_TAI_GENERATE_FUNCTION_MASK_NANO_HIGH_GENERATE_FUNCTION_MASK_NANO_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_GENERATE_FUNCTION_MASK_NANO_HIGH_GENERATE_FUNCTION_MASK_NANO_BITS_16_31_OFFS)


/* Generate Function Mask Nano Low */
#define MV_TAI_GENERATE_FUNCTION_MASK_NANO_LOW_REG					(0x0abc)
#define MV_TAI_GENERATE_FUNCTION_MASK_NANO_LOW_GENERATE_FUNCTION_MASK_NANO_BITS_0_15_OFFS		0
#define MV_TAI_GENERATE_FUNCTION_MASK_NANO_LOW_GENERATE_FUNCTION_MASK_NANO_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_GENERATE_FUNCTION_MASK_NANO_LOW_GENERATE_FUNCTION_MASK_NANO_BITS_0_15_OFFS)


/* Generate Function Mask Frac High */
#define MV_TAI_GENERATE_FUNCTION_MASK_FRAC_HIGH_REG					(0x0ac0)
#define MV_TAI_GENERATE_FUNCTION_MASK_FRAC_HIGH_GENERATE_FUNCTION_MASK_FRAC_BITS_16_31_OFFS		0
#define MV_TAI_GENERATE_FUNCTION_MASK_FRAC_HIGH_GENERATE_FUNCTION_MASK_FRAC_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_GENERATE_FUNCTION_MASK_FRAC_HIGH_GENERATE_FUNCTION_MASK_FRAC_BITS_16_31_OFFS)


/* Generate Function Mask Frac Low */
#define MV_TAI_GENERATE_FUNCTION_MASK_FRAC_LOW_REG					(0x0ac4)
#define MV_TAI_GENERATE_FUNCTION_MASK_FRAC_LOW_GENERATE_FUNCTION_MASK_FRAC_BITS_0_15_OFFS		0
#define MV_TAI_GENERATE_FUNCTION_MASK_FRAC_LOW_GENERATE_FUNCTION_MASK_FRAC_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_GENERATE_FUNCTION_MASK_FRAC_LOW_GENERATE_FUNCTION_MASK_FRAC_BITS_0_15_OFFS)


/* Drift Adjustment Configuration High */
#define MV_TAI_DRIFT_ADJUSTMENT_CFG_HIGH_REG					(0x0ac8)
#define MV_TAI_DRIFT_ADJUSTMENT_CFG_HIGH_FRACTIONAL_NANOSECOND_DRIFT_BITS_16_31_OFFS		0
#define MV_TAI_DRIFT_ADJUSTMENT_CFG_HIGH_FRACTIONAL_NANOSECOND_DRIFT_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_DRIFT_ADJUSTMENT_CFG_HIGH_FRACTIONAL_NANOSECOND_DRIFT_BITS_16_31_OFFS)


/* Drift Adjustment Configuration Low */
#define MV_TAI_DRIFT_ADJUSTMENT_CFG_LOW_REG						(0x0acc)
#define MV_TAI_DRIFT_ADJUSTMENT_CFG_LOW_FRACTIONAL_NANOSECOND_DRIFT_BITS_0_15_OFFS		0
#define MV_TAI_DRIFT_ADJUSTMENT_CFG_LOW_FRACTIONAL_NANOSECOND_DRIFT_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_DRIFT_ADJUSTMENT_CFG_LOW_FRACTIONAL_NANOSECOND_DRIFT_BITS_0_15_OFFS)


/* Capture Trigger Counter */
#define MV_TAI_CAPTURE_TRIGGER_CNTR_REG						(0x0ad0)
#define MV_TAI_CAPTURE_TRIGGER_CNTR_TRIGGER_CNTR_OFFS		0
#define MV_TAI_CAPTURE_TRIGGER_CNTR_TRIGGER_CNTR_MASK    \
		(0x000000ff << MV_TAI_CAPTURE_TRIGGER_CNTR_TRIGGER_CNTR_OFFS)


/* Pclk Clock Cycle Configuration High */
#define MV_TAI_PCLK_CLOCK_CYCLE_CFG_HIGH_REG					(0x0ad4)
#define MV_TAI_PCLK_CLOCK_CYCLE_CFG_HIGH_PCLK_CLOCK_CYCLE_BITS_16_31_OFFS		0
#define MV_TAI_PCLK_CLOCK_CYCLE_CFG_HIGH_PCLK_CLOCK_CYCLE_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_PCLK_CLOCK_CYCLE_CFG_HIGH_PCLK_CLOCK_CYCLE_BITS_16_31_OFFS)


/* Pclk Clock Cycle Configuration Low */
#define MV_TAI_PCLK_CLOCK_CYCLE_CFG_LOW_REG						(0x0ad8)
#define MV_TAI_PCLK_CLOCK_CYCLE_CFG_LOW_PCLK_CLOCK_CYCLE_BITS_0_15_OFFS		0
#define MV_TAI_PCLK_CLOCK_CYCLE_CFG_LOW_PCLK_CLOCK_CYCLE_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_PCLK_CLOCK_CYCLE_CFG_LOW_PCLK_CLOCK_CYCLE_BITS_0_15_OFFS)


/* Drift Threshold Configuration High */
#define MV_TAI_DRIFT_THR_CFG_HIGH_REG						(0x0adc)
#define MV_TAI_DRIFT_THR_CFG_HIGH_DRIFT_EXCEP_THR_BITS_8_23_OFFS		0
#define MV_TAI_DRIFT_THR_CFG_HIGH_DRIFT_EXCEP_THR_BITS_8_23_MASK    \
		(0x0000ffff << MV_TAI_DRIFT_THR_CFG_HIGH_DRIFT_EXCEP_THR_BITS_8_23_OFFS)


/* Drift Threshold Configuration Low */
#define MV_TAI_DRIFT_THR_CFG_LOW_REG						(0x0ae0)
#define MV_TAI_DRIFT_THR_CFG_LOW_MINIMAL_DRIFT_OFFS		0
#define MV_TAI_DRIFT_THR_CFG_LOW_MINIMAL_DRIFT_MASK    \
		(0x000000ff << MV_TAI_DRIFT_THR_CFG_LOW_MINIMAL_DRIFT_OFFS)

#define MV_TAI_DRIFT_THR_CFG_LOW_DRIFT_EXCEP_THR_BITS_0_7_OFFS		8
#define MV_TAI_DRIFT_THR_CFG_LOW_DRIFT_EXCEP_THR_BITS_0_7_MASK    \
		(0x000000ff << MV_TAI_DRIFT_THR_CFG_LOW_DRIFT_EXCEP_THR_BITS_0_7_OFFS)


/* Clock Cycle Configuration High */
#define MV_TAI_CLOCK_CYCLE_CFG_HIGH_REG						(0x0ae4)
#define MV_TAI_CLOCK_CYCLE_CFG_HIGH_CLOCK_CYCLE_NANOSECONDS_BITS_16_29_OFFS		0
#define MV_TAI_CLOCK_CYCLE_CFG_HIGH_CLOCK_CYCLE_NANOSECONDS_BITS_16_29_MASK    \
		(0x00003fff << MV_TAI_CLOCK_CYCLE_CFG_HIGH_CLOCK_CYCLE_NANOSECONDS_BITS_16_29_OFFS)

#define MV_TAI_CLOCK_CYCLE_CFG_HIGH_CLOCK_CYCLE_SECONDS_OFFS		14
#define MV_TAI_CLOCK_CYCLE_CFG_HIGH_CLOCK_CYCLE_SECONDS_MASK    \
		(0x00000003 << MV_TAI_CLOCK_CYCLE_CFG_HIGH_CLOCK_CYCLE_SECONDS_OFFS)


/* Clock Cycle Configuration Low */
#define MV_TAI_CLOCK_CYCLE_CFG_LOW_REG						(0x0ae8)
#define MV_TAI_CLOCK_CYCLE_CFG_LOW_CLOCK_CYCLE_NANOSECONDS_BITS_0_15_OFFS		0
#define MV_TAI_CLOCK_CYCLE_CFG_LOW_CLOCK_CYCLE_NANOSECONDS_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_CLOCK_CYCLE_CFG_LOW_CLOCK_CYCLE_NANOSECONDS_BITS_0_15_OFFS)


/* External Clock Propagation Delay Configuration High */
#define MV_TAI_EXT_CLOCK_PROPAGATION_DELAY_CFG_HIGH_REG				(0x0aec)
#define MV_TAI_EXT_CLOCK_PROPAGATION_DELAY_CFG_HIGH_CLOCK_DELAY_BITS_16_31_OFFS		0
#define MV_TAI_EXT_CLOCK_PROPAGATION_DELAY_CFG_HIGH_CLOCK_DELAY_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_EXT_CLOCK_PROPAGATION_DELAY_CFG_HIGH_CLOCK_DELAY_BITS_16_31_OFFS)


/* External Clock Propagation Delay Configuration Low */
#define MV_TAI_EXT_CLOCK_PROPAGATION_DELAY_CFG_LOW_REG				(0x0af0)
#define MV_TAI_EXT_CLOCK_PROPAGATION_DELAY_CFG_LOW_CLOCK_DELAY_BITS_0_15_OFFS		0
#define MV_TAI_EXT_CLOCK_PROPAGATION_DELAY_CFG_LOW_CLOCK_DELAY_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_EXT_CLOCK_PROPAGATION_DELAY_CFG_LOW_CLOCK_DELAY_BITS_0_15_OFFS)


/* Incoming Clockin Counting Enable */
#define MV_TAI_INCOMING_CLOCKIN_CNTING_EN_REG					(0x0af4)
#define MV_TAI_INCOMING_CLOCKIN_CNTING_EN_EN_INCOMING_CLOCK_CNTING_OFFS		0
#define MV_TAI_INCOMING_CLOCKIN_CNTING_EN_EN_INCOMING_CLOCK_CNTING_MASK    \
		(0x00000001 << MV_TAI_INCOMING_CLOCKIN_CNTING_EN_EN_INCOMING_CLOCK_CNTING_OFFS)


/* Incoming Clockin Counting Configuration Low */
#define MV_TAI_INCOMING_CLOCKIN_CNTING_CFG_LOW_REG					(0x0af8)
#define MV_TAI_INCOMING_CLOCKIN_CNTING_CFG_LOW_CLOCK_CNTR_BITS_0_15_OFFS		0
#define MV_TAI_INCOMING_CLOCKIN_CNTING_CFG_LOW_CLOCK_CNTR_BITS_0_15_MASK    \
		(0x0000ffff << MV_TAI_INCOMING_CLOCKIN_CNTING_CFG_LOW_CLOCK_CNTR_BITS_0_15_OFFS)


/* Time Update Counter MSB */
#define MV_TAI_TIME_UPDATE_CNTR_MSB_REG						(0x0afc)
#define MV_TAI_TIME_UPDATE_CNTR_MSB_TIME_UPDATE_CNTR_MSB_OFFS		0
#define MV_TAI_TIME_UPDATE_CNTR_MSB_TIME_UPDATE_CNTR_MSB_MASK    \
		(0x0000ffff << MV_TAI_TIME_UPDATE_CNTR_MSB_TIME_UPDATE_CNTR_MSB_OFFS)


/* Incoming Clockin Counting Configuration High */
#define MV_TAI_INCOMING_CLOCKIN_CNTING_CFG_HIGH_REG					(0x0b00)
#define MV_TAI_INCOMING_CLOCKIN_CNTING_CFG_HIGH_CLOCK_CNTR_BITS_16_31_OFFS		0
#define MV_TAI_INCOMING_CLOCKIN_CNTING_CFG_HIGH_CLOCK_CNTR_BITS_16_31_MASK    \
		(0x0000ffff << MV_TAI_INCOMING_CLOCKIN_CNTING_CFG_HIGH_CLOCK_CNTR_BITS_16_31_OFFS)

#define MV_TAI_CNTR_TIME_FUNC_BITSET(op, reg_val) \
	((reg_val & ~MV_TAI_TIME_CNTR_FUNC_CFG_0_TIME_CNTR_FUNC_MASK) \
	| (op << MV_TAI_TIME_CNTR_FUNC_CFG_0_TIME_CNTR_FUNC_OFFS))


/* Generic HW and SW operations' enum */
enum mv_pp3_tai_ptp_op {
	/* HW: MV_TAI_TIME_CNTR_FUNC_CFG_0_TIME_CNTR_FUNC bit set
	 * (these enums are HW, do not change them)
	 */
	MV_TAI_SET_UPDATE = 0,	/* from shadow to tai/tod */
	MV_TAI_FREQ_UPDATE = 1,
	MV_TAI_INCREMENT = 2,
	MV_TAI_DECREMENT = 3,
	MV_TAI_GET_CAPTURE = 4,
	MV_TAI_INCREMENT_GRACEFUL = 5,
	MV_TAI_DECREMENT_GRACEFUL = 6,
	MV_TAI_NOP = 7,

	/* SW operation enum (values are free) */
	MV_TAI_PTP_SW_OP,
	MV_TAI_TO_LINUX,
	MV_TAI_FROM_LINUX,
	MV_TAI_FROM_KERNEL,

	MV_TAI_PTP_TX_TS,	/* Timestamp of TX/Egress packet */
	/*MV_TAI_PTP_RX_TS - RX is not needed. Read from CFH into PTP pack-payload */
	MV_TAI_PTP_ENABLE,	/* Total complete enable/disable */
	MV_TAI_PTP_DISABLE,	/* for TAI and PTP HW, and SW    */
	MV_TAI_CLOCK_INTERNAL,
	MV_TAI_CLOCK_EXTERNAL,
	MV_TAI_NOP_RESERVE3,
	MV_TAI_NOP_RESERVE2,
	MV_TAI_NOP_RESERVE1,
	MV_TAI_OP_MAX
};


#define MV_TAI_TOD_SKIP_ZERO_REGS /* sec_msb_16b, nfrac */

/* Generic HW and SW structure used for TAI operation INP and/or OUT */
struct mv_pp3_tai_tod {
	/* 4 bytes for User/Kernel communication only */
	u8 zero_byte_non_ascii; /* should be always ZERO */
	u8 ts_is_32bits; /* if(1) sec_lsb_32b contains 2bits sec + 30bits nsec */
	u8 operation; /* enum mv_pp3_tai_ptp_op */
	u8 pad;

	/* timestamp in 16+32+32 format, or 2+30 */
	/* in LittleEndian ordering so the *u64 could be used */
	u32	nsec;
	u32	sec_lsb_32b;
	u32	sec_msb_16b;
	u32	nfrac;
};

#endif /* _mv_tai_regs_h_ */
#endif /* MY_DEF_HERE */
