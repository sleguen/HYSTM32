/**
 * \file stm32_gpio.c
 * \brief Function to initialize and manage all the system clock and
 * peripheral clock
 * \author S.LE GUEN
 * \date 06/28/2016
 */
//User includes
#include "rcc.h"

//ST includes
#include "stm32f10x_rcc.h"
#include "stm32f10x_flash.h"

/* macros =================================================================== */
/* constants ================================================================ */
/* types ==================================================================== */
/* structures =============================================================== */
/* private variables ======================================================== */
/* private functions ======================================================== */
/* entry points ============================================================= */
/* public variables ========================================================= */
/* internal public functions ================================================ */

/**
 * \fn void RCC_Init(void)
 * \brief Intialize GPIO used on the board
 */
void vd_RCC_Init(void)
{
  ErrorStatus HSEStartUpStatus; 
  /* RCC system reset(for debug purpose) */
  RCC_DeInit();

  /* Enable HSE */
  RCC_HSEConfig(RCC_HSE_ON);

  /* Wait till HSE is ready */
  HSEStartUpStatus = RCC_WaitForHSEStartUp();

  if(HSEStartUpStatus == SUCCESS)
  {
    /* HCLK = SYSCLK */
    RCC_HCLKConfig(RCC_SYSCLK_Div1); 
  
    /* PCLK2 = HCLK */
    RCC_PCLK2Config(RCC_HCLK_Div1); 

    /* PCLK1 = HCLK/2 */
    RCC_PCLK1Config(RCC_HCLK_Div2);

    /* Flash 2 wait state */
    FLASH_SetLatency(FLASH_Latency_2);
    /* Enable Prefetch Buffer */
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);

    /* PLLCLK = 8MHz * 9 = 72 MHz */
    RCC_PLLConfig(RCC_PLLSource_PREDIV1, RCC_PLLMul_9);

    /* Enable PLL */ 
    RCC_PLLCmd(ENABLE);

    /* Wait till PLL is ready */
    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
    {
    }

    /* Select PLL as system clock source */
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

    /* Wait till PLL is used as system clock source */
    while(RCC_GetSYSCLKSource() != 0x08)
    {
    }
  }

  /* TIM1, GPIOA and GPIOB clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_TIM1 | RCC_APB2Periph_GPIOA |
                         RCC_APB2Periph_GPIOB |RCC_APB2Periph_GPIOD, ENABLE);
                         
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC, ENABLE);
}
