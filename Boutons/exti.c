/**
 * \file exti.c
 * \brief Fichier contenant la gestion des interruptions externes du STM32.
 * \author S.LE GUEN
 * \version 0.1
 * \date 03/09/2015
 */
#include "misc.h"
#include "leds.h"
#include "exti.h"

/* macros ============================================================== */
/* constants =========================================================== */
/* types =============================================================== */
/* structures ========================================================== */
/* private variables =================================================== */
static uint8_t flagD1;
static uint8_t flagD2;
static uint8_t flagD3;
static uint8_t flagD4;

static GPIO_InitTypeDef GPIO_InitStructure;
static EXTI_InitTypeDef EXTI_InitStructure;
static NVIC_InitTypeDef NVIC_InitStructure;

/* private functions =================================================== */
/* entry points ======================================================== */
/* public variables ==================================================== */
/* internal public functions =========================================== */

/**
 * \fn void exti2Init(void)
 * \brief Gestion de l'IT externe Numero 2
 */
void exti5Init(void)
{
    RCC_APB2PeriphClockCmd(SWITCH_S1_GPIO_CLK,ENABLE);

    GPIO_InitStructure.GPIO_Mode   = SWITCH_S1_GPIO_MODE;
    GPIO_InitStructure.GPIO_Pin    = SWITCH_S1_GPIO_PIN;
    GPIO_Init(SWITCH_S1_GPIO_PORT, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    GPIO_EXTILineConfig(SWITCH_S1_PORT_SOURCE, SWITCH_S1_PIN_SOURCE);

    EXTI_InitStructure.EXTI_Line    = SWITCH_S1_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode    = SWITCH_S1_EXTI_MODE;
    EXTI_InitStructure.EXTI_Trigger = SWITCH_S1_EXTI_TRIGGER;
    EXTI_InitStructure.EXTI_LineCmd = SWITCH_S1_EXTI_LINE_CMD;
    EXTI_Init(&EXTI_InitStructure);


    NVIC_InitStructure.NVIC_IRQChannel                   = SWITCH_S1_EXTI_ISR;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = SWITCH_S1_EXTI_ISR_PREMP;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = SWITCH_S1_EXTI_ISR_SUB_PRIO;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = SWITCH_S1_EXTI_CMD;
    NVIC_Init(&NVIC_InitStructure);

    flagD1 = RESET;
}

/**
 * \fn void exti2Init(void)
 * \brief Gestion de l'IT externe Numero 2
 */
void exti2Init(void)
{
    RCC_APB2PeriphClockCmd(SWITCH_S4_GPIO_CLK,ENABLE);

    GPIO_InitStructure.GPIO_Mode   = SWITCH_S4_GPIO_MODE;
    GPIO_InitStructure.GPIO_Pin    = SWITCH_S4_GPIO_PIN;
    GPIO_Init(SWITCH_S4_GPIO_PORT, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    GPIO_EXTILineConfig(SWITCH_S4_PORT_SOURCE, SWITCH_S4_PIN_SOURCE);

    EXTI_InitStructure.EXTI_Line    = SWITCH_S4_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode    = SWITCH_S4_EXTI_MODE;
    EXTI_InitStructure.EXTI_Trigger = SWITCH_S4_EXTI_TRIGGER;
    EXTI_InitStructure.EXTI_LineCmd = SWITCH_S4_EXTI_LINE_CMD;
    EXTI_Init(&EXTI_InitStructure);


    NVIC_InitStructure.NVIC_IRQChannel                   = SWITCH_S4_EXTI_ISR;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = SWITCH_S4_EXTI_ISR_PREMP;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = SWITCH_S4_EXTI_ISR_SUB_PRIO;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = SWITCH_S4_EXTI_CMD;
    NVIC_Init(&NVIC_InitStructure);

    flagD4 = RESET;
}


/**
 * \fn void exti3Init(void)
 * \brief Gestion de l'IT externe Numero 3
 */
void exti3Init(void)
{
    RCC_APB2PeriphClockCmd(SWITCH_S3_GPIO_CLK,ENABLE);

    GPIO_InitStructure.GPIO_Mode   = SWITCH_S3_GPIO_MODE;
    GPIO_InitStructure.GPIO_Pin    = SWITCH_S3_GPIO_PIN;
    GPIO_Init(SWITCH_S3_GPIO_PORT, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    GPIO_EXTILineConfig(SWITCH_S3_PORT_SOURCE, SWITCH_S3_PIN_SOURCE);

    EXTI_InitStructure.EXTI_Line    = SWITCH_S3_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode    = SWITCH_S3_EXTI_MODE;
    EXTI_InitStructure.EXTI_Trigger = SWITCH_S3_EXTI_TRIGGER;
    EXTI_InitStructure.EXTI_LineCmd = SWITCH_S3_EXTI_LINE_CMD;
    EXTI_Init(&EXTI_InitStructure);


    NVIC_InitStructure.NVIC_IRQChannel                   = SWITCH_S3_EXTI_ISR;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = SWITCH_S3_EXTI_ISR_PREMP;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = SWITCH_S3_EXTI_ISR_SUB_PRIO;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = SWITCH_S3_EXTI_CMD;
    NVIC_Init(&NVIC_InitStructure);

    flagD3 = RESET;
}

/**
 * \fn void exti4Init(void)
 * \brief Gestion de l'IT externe Numero 4
 */
void exti4Init(void)
{
    RCC_APB2PeriphClockCmd(SWITCH_S2_GPIO_CLK,ENABLE);

    GPIO_InitStructure.GPIO_Mode   = SWITCH_S2_GPIO_MODE;
    GPIO_InitStructure.GPIO_Pin    = SWITCH_S2_GPIO_PIN;
    GPIO_Init(SWITCH_S4_GPIO_PORT, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    GPIO_EXTILineConfig(SWITCH_S2_PORT_SOURCE, SWITCH_S2_PIN_SOURCE);

    EXTI_InitStructure.EXTI_Line    = SWITCH_S2_EXTI_LINE;
    EXTI_InitStructure.EXTI_Mode    = SWITCH_S2_EXTI_MODE;
    EXTI_InitStructure.EXTI_Trigger = SWITCH_S2_EXTI_TRIGGER;
    EXTI_InitStructure.EXTI_LineCmd = SWITCH_S2_EXTI_LINE_CMD;
    EXTI_Init(&EXTI_InitStructure);


    NVIC_InitStructure.NVIC_IRQChannel                   = SWITCH_S2_EXTI_ISR;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = SWITCH_S2_EXTI_ISR_PREMP;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority        = SWITCH_S2_EXTI_ISR_SUB_PRIO;
    NVIC_InitStructure.NVIC_IRQChannelCmd                = SWITCH_S2_EXTI_CMD;
    NVIC_Init(&NVIC_InitStructure);

    flagD4 = RESET;
}

/**
 * \fn void EXTI2_IRQHandler(void)
 * \brief Gestion de l'IT externe Numero 4
 */
void EXTI2_IRQHandler(void)
{
    if (EXTI_GetITStatus(SWITCH_S4_EXTI_LINE) != RESET)
    {
    	if(flagD4 == RESET)
    	{
    	    ledOn(LED_D4_GPIO_PORT,LED_D4_GPIO_PIN);
    	    flagD4 = SET;
    	}
    	else
    	{
    		ledOff(LED_D4_GPIO_PORT,LED_D4_GPIO_PIN);
    		flagD4 = RESET;
    	}

        EXTI_ClearITPendingBit(SWITCH_S4_EXTI_LINE);
    }
}

/**
 * \fn void EXTI3_IRQHandler(void)
 * \brief Gestion de l'IT externe Numero 4
 */
void EXTI3_IRQHandler(void)
{
    if (EXTI_GetITStatus(SWITCH_S3_EXTI_LINE) != RESET)
    {
    	if(flagD3 == RESET)
    	{
    	    ledOn(LED_D3_GPIO_PORT,LED_D3_GPIO_PIN);
    	    flagD3 = SET;
    	}
    	else
    	{
    		ledOff(LED_D3_GPIO_PORT,LED_D3_GPIO_PIN);
    		flagD3 = RESET;
    	}

        EXTI_ClearITPendingBit(SWITCH_S3_EXTI_LINE);
    }
}

/**
 * \fn void EXTI4_IRQHandler(void)
 * \brief Gestion de l'IT externe Numero 4
 */
void EXTI4_IRQHandler(void)
{
    if (EXTI_GetITStatus(SWITCH_S2_EXTI_LINE) != RESET)
    {
    	if(flagD2 == RESET)
    	{
    	    ledOn(LED_D2_GPIO_PORT,LED_D2_GPIO_PIN);
    	    flagD2 = SET;
    	}
    	else
    	{
    		ledOff(LED_D2_GPIO_PORT,LED_D2_GPIO_PIN);
    		flagD2 = RESET;
    	}

        EXTI_ClearITPendingBit(SWITCH_S2_EXTI_LINE);
    }
}

/**
 * \fn void EXTI4_IRQHandler(void)
 * \brief Gestion des ITs pour les extis 5 a 9
 */
void EXTI9_5_IRQHandler(void)
{
	if (EXTI_GetITStatus(SWITCH_S1_EXTI_LINE) != RESET)
	{
	    	if(flagD1 == RESET)
	    	{
	    	    ledOn(LED_D1_GPIO_PORT,LED_D1_GPIO_PIN);
	    	    flagD1 = SET;
	    	}
	    	else
	    	{
	    		ledOff(LED_D1_GPIO_PORT,LED_D1_GPIO_PIN);
	    		flagD1 = RESET;
	    	}

	        EXTI_ClearITPendingBit(SWITCH_S1_EXTI_LINE);
	 }
}
