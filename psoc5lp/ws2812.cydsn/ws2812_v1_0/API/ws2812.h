/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "cytypes.h"

#define `$INSTANCE_NAME`_SHIFT_MASK 0x80
#define `$INSTANCE_NAME`_NUM_SHIFT_BITS 8
#define `$INSTANCE_NAME`_FIFO_LEVELS 4
#define `$INSTANCE_NAME`_bit_cnt (*(reg8 *)`$INSTANCE_NAME`_udb8_u0__D1_REG)
#define `$INSTANCE_NAME`_shift_mask (*(reg8 *)`$INSTANCE_NAME`_udb8_u0__D0_REG)
#define `$INSTANCE_NAME`_data_fifo (*(reg8 *)`$INSTANCE_NAME`_udb8_u0__F0_REG)
#define `$INSTANCE_NAME`_actl (*(reg8 *)`$INSTANCE_NAME`_udb8_u0__DP_AUX_CTL_REG)

void `$INSTANCE_NAME`_Start(void);
/* [] END OF FILE */
