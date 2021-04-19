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

#define ws2812_1_SHIFT_MASK 0x80
#define ws2812_1_NUM_SHIFT_BITS 8
#define ws2812_1_FIFO_LEVELS 4
#define ws2812_1_bit_cnt (*(reg8 *)ws2812_1_udb8_u0__D1_REG)
#define ws2812_1_shift_mask (*(reg8 *)ws2812_1_udb8_u0__D0_REG)
#define ws2812_1_data_fifo (*(reg8 *)ws2812_1_udb8_u0__F0_REG)
#define ws2812_1_actl (*(reg8 *)ws2812_1_udb8_u0__DP_AUX_CTL_REG)

void ws2812_1_Start(void);
/* [] END OF FILE */
