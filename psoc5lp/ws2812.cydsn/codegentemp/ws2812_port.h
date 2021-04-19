/*******************************************************************************
* File Name: ws2812_port.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ws2812_port_H) /* Pins ws2812_port_H */
#define CY_PINS_ws2812_port_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ws2812_port_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ws2812_port__PORT == 15 && ((ws2812_port__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ws2812_port_Write(uint8 value);
void    ws2812_port_SetDriveMode(uint8 mode);
uint8   ws2812_port_ReadDataReg(void);
uint8   ws2812_port_Read(void);
void    ws2812_port_SetInterruptMode(uint16 position, uint16 mode);
uint8   ws2812_port_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ws2812_port_SetDriveMode() function.
     *  @{
     */
        #define ws2812_port_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ws2812_port_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ws2812_port_DM_RES_UP          PIN_DM_RES_UP
        #define ws2812_port_DM_RES_DWN         PIN_DM_RES_DWN
        #define ws2812_port_DM_OD_LO           PIN_DM_OD_LO
        #define ws2812_port_DM_OD_HI           PIN_DM_OD_HI
        #define ws2812_port_DM_STRONG          PIN_DM_STRONG
        #define ws2812_port_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ws2812_port_MASK               ws2812_port__MASK
#define ws2812_port_SHIFT              ws2812_port__SHIFT
#define ws2812_port_WIDTH              1u

/* Interrupt constants */
#if defined(ws2812_port__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ws2812_port_SetInterruptMode() function.
     *  @{
     */
        #define ws2812_port_INTR_NONE      (uint16)(0x0000u)
        #define ws2812_port_INTR_RISING    (uint16)(0x0001u)
        #define ws2812_port_INTR_FALLING   (uint16)(0x0002u)
        #define ws2812_port_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ws2812_port_INTR_MASK      (0x01u) 
#endif /* (ws2812_port__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ws2812_port_PS                     (* (reg8 *) ws2812_port__PS)
/* Data Register */
#define ws2812_port_DR                     (* (reg8 *) ws2812_port__DR)
/* Port Number */
#define ws2812_port_PRT_NUM                (* (reg8 *) ws2812_port__PRT) 
/* Connect to Analog Globals */                                                  
#define ws2812_port_AG                     (* (reg8 *) ws2812_port__AG)                       
/* Analog MUX bux enable */
#define ws2812_port_AMUX                   (* (reg8 *) ws2812_port__AMUX) 
/* Bidirectional Enable */                                                        
#define ws2812_port_BIE                    (* (reg8 *) ws2812_port__BIE)
/* Bit-mask for Aliased Register Access */
#define ws2812_port_BIT_MASK               (* (reg8 *) ws2812_port__BIT_MASK)
/* Bypass Enable */
#define ws2812_port_BYP                    (* (reg8 *) ws2812_port__BYP)
/* Port wide control signals */                                                   
#define ws2812_port_CTL                    (* (reg8 *) ws2812_port__CTL)
/* Drive Modes */
#define ws2812_port_DM0                    (* (reg8 *) ws2812_port__DM0) 
#define ws2812_port_DM1                    (* (reg8 *) ws2812_port__DM1)
#define ws2812_port_DM2                    (* (reg8 *) ws2812_port__DM2) 
/* Input Buffer Disable Override */
#define ws2812_port_INP_DIS                (* (reg8 *) ws2812_port__INP_DIS)
/* LCD Common or Segment Drive */
#define ws2812_port_LCD_COM_SEG            (* (reg8 *) ws2812_port__LCD_COM_SEG)
/* Enable Segment LCD */
#define ws2812_port_LCD_EN                 (* (reg8 *) ws2812_port__LCD_EN)
/* Slew Rate Control */
#define ws2812_port_SLW                    (* (reg8 *) ws2812_port__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ws2812_port_PRTDSI__CAPS_SEL       (* (reg8 *) ws2812_port__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ws2812_port_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ws2812_port__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ws2812_port_PRTDSI__OE_SEL0        (* (reg8 *) ws2812_port__PRTDSI__OE_SEL0) 
#define ws2812_port_PRTDSI__OE_SEL1        (* (reg8 *) ws2812_port__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ws2812_port_PRTDSI__OUT_SEL0       (* (reg8 *) ws2812_port__PRTDSI__OUT_SEL0) 
#define ws2812_port_PRTDSI__OUT_SEL1       (* (reg8 *) ws2812_port__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ws2812_port_PRTDSI__SYNC_OUT       (* (reg8 *) ws2812_port__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ws2812_port__SIO_CFG)
    #define ws2812_port_SIO_HYST_EN        (* (reg8 *) ws2812_port__SIO_HYST_EN)
    #define ws2812_port_SIO_REG_HIFREQ     (* (reg8 *) ws2812_port__SIO_REG_HIFREQ)
    #define ws2812_port_SIO_CFG            (* (reg8 *) ws2812_port__SIO_CFG)
    #define ws2812_port_SIO_DIFF           (* (reg8 *) ws2812_port__SIO_DIFF)
#endif /* (ws2812_port__SIO_CFG) */

/* Interrupt Registers */
#if defined(ws2812_port__INTSTAT)
    #define ws2812_port_INTSTAT            (* (reg8 *) ws2812_port__INTSTAT)
    #define ws2812_port_SNAP               (* (reg8 *) ws2812_port__SNAP)
    
	#define ws2812_port_0_INTTYPE_REG 		(* (reg8 *) ws2812_port__0__INTTYPE)
#endif /* (ws2812_port__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ws2812_port_H */


/* [] END OF FILE */
