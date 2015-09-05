/**
 * \file exti.h
 * \brief Fichier contenant la gestion des interruptions externes du STM32.
 * \author S.LE GUEN
 * \version 0.1
 * \date 05/09/2015
 */
#ifndef _EXTI_H_
#define _EXTI_H_
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_exti.h"

/* macros ============================================================== */

/*
 * S4 -> PE2
 * S3 -> PE3
 * S2 -> PE4
 * S1 -> PE5
 */

//
// SWITCH S1
//
#define SWITCH_S1_GPIO_CLK          RCC_APB2Periph_GPIOE
#define SWITCH_S1_GPIO_PORT         GPIOE
#define SWITCH_S1_GPIO_SPEED        GPIO_Speed_50MHz
#define SWITCH_S1_GPIO_MODE         GPIO_Mode_IN_FLOATING
#define SWITCH_S1_GPIO_PIN          GPIO_Pin_5

#define SWITCH_S1_PORT_SOURCE       GPIO_PortSourceGPIOE
#define SWITCH_S1_PIN_SOURCE        GPIO_PinSource5
#define SWITCH_S1_EXTI_LINE         EXTI_Line5
#define SWITCH_S1_EXTI_MODE         EXTI_Mode_Interrupt
#define SWITCH_S1_EXTI_TRIGGER      EXTI_Trigger_Falling
#define SWITCH_S1_EXTI_LINE_CMD     ENABLE

#define SWITCH_S1_EXTI_ISR		    EXTI9_5_IRQn
#define SWITCH_S1_EXTI_ISR_PREMP    0x0F
#define SWITCH_S1_EXTI_ISR_SUB_PRIO 0x0F
#define SWITCH_S1_EXTI_CMD		    ENABLE

//
// SWITCH S2
//
#define SWITCH_S2_GPIO_CLK          RCC_APB2Periph_GPIOE
#define SWITCH_S2_GPIO_PORT         GPIOE
#define SWITCH_S2_GPIO_SPEED        GPIO_Speed_50MHz
#define SWITCH_S2_GPIO_MODE         GPIO_Mode_IN_FLOATING
#define SWITCH_S2_GPIO_PIN          GPIO_Pin_4

#define SWITCH_S2_PORT_SOURCE       GPIO_PortSourceGPIOE
#define SWITCH_S2_PIN_SOURCE        GPIO_PinSource4
#define SWITCH_S2_EXTI_LINE         EXTI_Line4
#define SWITCH_S2_EXTI_MODE         EXTI_Mode_Interrupt
#define SWITCH_S2_EXTI_TRIGGER      EXTI_Trigger_Falling
#define SWITCH_S2_EXTI_LINE_CMD     ENABLE

#define SWITCH_S2_EXTI_ISR		    EXTI4_IRQn
#define SWITCH_S2_EXTI_ISR_PREMP    0x0F
#define SWITCH_S2_EXTI_ISR_SUB_PRIO 0x0F
#define SWITCH_S2_EXTI_CMD		    ENABLE

//
// SWITCH S3
//
#define SWITCH_S3_GPIO_CLK          RCC_APB2Periph_GPIOE
#define SWITCH_S3_GPIO_PORT         GPIOE
#define SWITCH_S3_GPIO_SPEED        GPIO_Speed_50MHz
#define SWITCH_S3_GPIO_MODE         GPIO_Mode_IPU
#define SWITCH_S3_GPIO_PIN          GPIO_Pin_3

#define SWITCH_S3_PORT_SOURCE       GPIO_PortSourceGPIOE
#define SWITCH_S3_PIN_SOURCE        GPIO_PinSource3
#define SWITCH_S3_EXTI_LINE         EXTI_Line3
#define SWITCH_S3_EXTI_MODE         EXTI_Mode_Interrupt
#define SWITCH_S3_EXTI_TRIGGER      EXTI_Trigger_Falling
#define SWITCH_S3_EXTI_LINE_CMD     ENABLE

#define SWITCH_S3_EXTI_ISR		    EXTI3_IRQn
#define SWITCH_S3_EXTI_ISR_PREMP    0x0F
#define SWITCH_S3_EXTI_ISR_SUB_PRIO 0x0F
#define SWITCH_S3_EXTI_CMD		    ENABLE

//
// SWITCH S4
//
#define SWITCH_S4_GPIO_CLK      RCC_APB2Periph_GPIOE
#define SWITCH_S4_GPIO_PORT     GPIOE
#define SWITCH_S4_GPIO_SPEED    GPIO_Speed_50MHz
#define SWITCH_S4_GPIO_MODE     GPIO_Mode_IPU
#define SWITCH_S4_GPIO_PIN      GPIO_Pin_2

#define SWITCH_S4_PORT_SOURCE   GPIO_PortSourceGPIOE
#define SWITCH_S4_PIN_SOURCE    GPIO_PinSource2
#define SWITCH_S4_EXTI_LINE     EXTI_Line2
#define SWITCH_S4_EXTI_MODE     EXTI_Mode_Interrupt
#define SWITCH_S4_EXTI_TRIGGER  EXTI_Trigger_Falling
#define SWITCH_S4_EXTI_LINE_CMD ENABLE

#define SWITCH_S4_EXTI_ISR		    EXTI2_IRQn
#define SWITCH_S4_EXTI_ISR_PREMP    0x0F
#define SWITCH_S4_EXTI_ISR_SUB_PRIO 0x0F
#define SWITCH_S4_EXTI_CMD		    ENABLE

/* constants =========================================================== */
/* types =============================================================== */
/* structures ========================================================== */
/* internal public functions =========================================== */
/* entry points ======================================================== */
/* public variables ==================================================== */
/* inline public functions  ============================================ */

void exti2Init(void);
void exti3Init(void);
void exti4Init(void);
void exti5Init(void);
#endif /*_EXTI_H_*/
