/**
 * \file main.c
 * \brief Entry point of the application
 * HYSTM32_100P board.
 * \author S.LE GUEN
 * \date 06/28/2016
 */

//STM32 includes
#include "misc.h"

//User includes
#include "rcc.h"
#include "gpio.h"
#include "fsmc.h"
#include "drv_lcd.h"
#include "delay.h"

//STemWin includes
#include "GUI.h"
#include "WM.h"

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
 * \fn int main(void)
 * \brief Entry point of the application
 */
int main(void)
{
    vd_RCC_Init();
    vd_GPIO_Init();    
    vd_FSMC_Init();
    
    vd_delay_Init();
    
    SysTick_Config(SystemCoreClock / 1000u);
    
    GUI_Init();
    GUI_Clear();
    GUI_SetFont(&GUI_Font20_1);
    GUI_DispStringAt("Hello world!", (LCD_GetXSize()-100u)/2u, (LCD_GetYSize()-100u)/2u);
    GUI_DispStringAt("STemWin ok !", (LCD_GetXSize()-100u)/2u, (LCD_GetYSize()-10u)/2u);

    WM_SetCreateFlags(WM_CF_MEMDEV);

    while(1)
    {
    }
}
