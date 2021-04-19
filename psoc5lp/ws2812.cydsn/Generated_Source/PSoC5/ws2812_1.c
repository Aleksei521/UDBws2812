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
#include "ws2812_1.h"

void ws2812_1_Start(void)
{
    ws2812_1_shift_mask=ws2812_1_SHIFT_MASK;
    ws2812_1_bit_cnt=ws2812_1_NUM_SHIFT_BITS;
}
/* [] END OF FILE */
