/**
 * \file drv_lcd.c
 * \brief Function to initialize and drive the LCD screen mounted on
 * HYSTM32_100P board. The component is the LGDP4532 with GRAM (Graphics RAM)
 * \author S.LE GUEN
 * \date 06/28/2016
 */

//ST library includes
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

//User includes
#include "drv_lcd.h"

/* macros =================================================================== */
//disp Data ADDR
#define BANK1_LCD_D    ((u32)0x60020000u)

//disp Reg ADDR
#define BANK1_LCD_C    ((u32)0x60000000u)

/* constants ================================================================ */
/* types ==================================================================== */
/* structures =============================================================== */
/* private variables ======================================================== */
/* private functions ======================================================== */
static void vd_LCD_Delay(__IO u32 u32_nCount);
static void vd_LCD_Write_Cmd(u32 u32_index,u32 u32_val);
/* entry points ============================================================= */
/* public variables ========================================================= */
/* internal public functions ================================================ */

/**
 * \fn void vd_LCD_Init(void)
 * \brief Initialize LCD screen
 */
void vd_LCD_Init(void)
{
   //Reset LCD
   GPIO_ResetBits(GPIOE, GPIO_Pin_1);
   vd_LCD_Delay(0xAFFFu);					   
   GPIO_SetBits(GPIOE, GPIO_Pin_1 );		 
   vd_LCD_Delay(0xAFFF);	

   vd_LCD_Write_Cmd(0x0000,0x0001);
   vd_LCD_Delay(10);

   vd_LCD_Write_Cmd(0x0015u,0x0030);
   vd_LCD_Write_Cmd(0x0011u,0x0040);
   vd_LCD_Write_Cmd(0x0010u,0x1628);
   vd_LCD_Write_Cmd(0x0012u,0x0000);
   vd_LCD_Write_Cmd(0x0013u,0x104d);
   vd_LCD_Delay(10);
   vd_LCD_Write_Cmd(0x0012u,0x0010);
   vd_LCD_Delay(10);
   vd_LCD_Write_Cmd(0x0010,0x2620);
   vd_LCD_Write_Cmd(0x0013,0x344d);
   vd_LCD_Delay(10);

   vd_LCD_Write_Cmd(0x0001,0x0100);
   vd_LCD_Write_Cmd(0x0002,0x0300);
   vd_LCD_Write_Cmd(0x0003,0x1030);
   vd_LCD_Write_Cmd(0x0008,0x0604);
   vd_LCD_Write_Cmd(0x0009,0x0000);
   vd_LCD_Write_Cmd(0x000A,0x0008);

   vd_LCD_Write_Cmd(0x0041,0x0002);
   vd_LCD_Write_Cmd(0x0060,0x2700);
   vd_LCD_Write_Cmd(0x0061,0x0001);
   vd_LCD_Write_Cmd(0x0090,0x0182);
   vd_LCD_Write_Cmd(0x0093,0x0001);
   vd_LCD_Write_Cmd(0x00a3,0x0010);
   vd_LCD_Delay(10);

   vd_LCD_Write_Cmd(0x30,0x0000);		
   vd_LCD_Write_Cmd(0x31,0x0502);		
   vd_LCD_Write_Cmd(0x32,0x0307);		
   vd_LCD_Write_Cmd(0x33,0x0305);		
   vd_LCD_Write_Cmd(0x34,0x0004);		
   vd_LCD_Write_Cmd(0x35,0x0402);		
   vd_LCD_Write_Cmd(0x36,0x0707);		
   vd_LCD_Write_Cmd(0x37,0x0503);		
   vd_LCD_Write_Cmd(0x38,0x1505);		
   vd_LCD_Write_Cmd(0x39,0x1505);
   vd_LCD_Delay(10);

   vd_LCD_Write_Cmd(0x0007,0x0001);
   vd_LCD_Delay(10);
   vd_LCD_Write_Cmd(0x0007,0x0021);
   vd_LCD_Write_Cmd(0x0007,0x0023);
   vd_LCD_Delay(10);
   vd_LCD_Write_Cmd(0x0007,0x0033);
   vd_LCD_Delay(10);
   vd_LCD_Write_Cmd(0x0007,0x0133);
}

/**
 * \fn static void vd_LCD_Delay(__IO u32 u32_nCount)
 * \brief Set a delay
 * \param[IN] u32_nCount Value used to perform the delay
 */
static void vd_LCD_Delay(__IO u32 u32_nCount)
{
  for( ; u32_nCount != 0u; u32_nCount--);
}

/**
 * \fn void vd_LCD_Write_Cmd(u32 u32_index,u32 u32_val)
 * \brief Write into the LCD driver
 * \param[IN] u32_index Used to choose the register
 * \param[IN] u32_val Value to set into the selected register
 */
static void vd_LCD_Write_Cmd(u32 u32_index,u32 u32_val)
{	
    *(__IO u16 *) (BANK1_LCD_C) = u32_index;	
    *(__IO u16 *) (BANK1_LCD_D) = u32_val;
}