/*******************************************************************************
* File Name: isr_ws2812.h
* Version 1.71
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_isr_ws2812_H)
#define CY_ISR_isr_ws2812_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_ws2812_Start(void);
void isr_ws2812_StartEx(cyisraddress address);
void isr_ws2812_Stop(void);

CY_ISR_PROTO(isr_ws2812_Interrupt);

void isr_ws2812_SetVector(cyisraddress address);
cyisraddress isr_ws2812_GetVector(void);

void isr_ws2812_SetPriority(uint8 priority);
uint8 isr_ws2812_GetPriority(void);

void isr_ws2812_Enable(void);
uint8 isr_ws2812_GetState(void);
void isr_ws2812_Disable(void);

void isr_ws2812_SetPending(void);
void isr_ws2812_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_ws2812 ISR. */
#define isr_ws2812_INTC_VECTOR            ((reg32 *) isr_ws2812__INTC_VECT)

/* Address of the isr_ws2812 ISR priority. */
#define isr_ws2812_INTC_PRIOR             ((reg8 *) isr_ws2812__INTC_PRIOR_REG)

/* Priority of the isr_ws2812 interrupt. */
#define isr_ws2812_INTC_PRIOR_NUMBER      isr_ws2812__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_ws2812 interrupt. */
#define isr_ws2812_INTC_SET_EN            ((reg32 *) isr_ws2812__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_ws2812 interrupt. */
#define isr_ws2812_INTC_CLR_EN            ((reg32 *) isr_ws2812__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_ws2812 interrupt state to pending. */
#define isr_ws2812_INTC_SET_PD            ((reg32 *) isr_ws2812__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_ws2812 interrupt. */
#define isr_ws2812_INTC_CLR_PD            ((reg32 *) isr_ws2812__INTC_CLR_PD_REG)


#endif /* CY_ISR_isr_ws2812_H */


/* [] END OF FILE */
