#include "stm32f10x.h"

#include "drv_ili9320.h"
#include "drv_lcd.h"

//STemWin include
#include "lcdDrv.h"
#include "GUI.h"

/*
LCD_DrvTypeDef   ili9320_drv = 
{
  vd_drv_ili9320_Init,
  ili9320_ReadID,
  ili9320_DisplayOn,
  ili9320_DisplayOff,
  ili9320_SetCursor,
  ili9320_WritePixel,
  ili9320_ReadPixel,
  ili9320_SetDisplayWindow,
  ili9320_DrawHLine,
  ili9320_DrawVLine,
  ili9320_GetLcdPixelWidth,
  ili9320_GetLcdPixelHeight,
  ili9320_DrawBitmap,
  ili9320_DrawRGBImage,  
};
*/
void vd_drv_ili9320_Init(void)
{
    vd_LCD_Init();
}

void vd_drv_ili9320_SetCursor(u8 u8_x, u8 u8_y)
{
  vd_LCD_Write_Cmd(32, u8_y);
  vd_LCD_Write_Cmd(33, 319-u8_x);
}

void vd_ili9320_SetWindows(u16 u16_StartX,u16 u16_StartY,u16 u16_EndX,u16 u16_EndY)
{
  // Horizontal GRAM Start Address
  vd_LCD_Write_Cmd(0x0050, u16_StartY); 
  // Horizontal GRAM End Address
  vd_LCD_Write_Cmd(0x0051, u16_EndX);
  // Vertical GRAM Start Address
  vd_LCD_Write_Cmd(0x0052, 319-u16_StartX);
  // Vertical GRAM Start Address
  vd_LCD_Write_Cmd(0x0053, u16_EndY); 
}

void vd_ili9320_Clear(u16 u16_Value)
{
  u32 i;
  // Horizontal GRAM Start Address
  vd_LCD_Write_Cmd(0x0050, 0);
  // Horizontal GRAM End Address
  vd_LCD_Write_Cmd(0x0051, 239);
  // Vertical GRAM Start Address
  vd_LCD_Write_Cmd(0x0052, 0);
  // Vertical GRAM Start Address
  vd_LCD_Write_Cmd(0x0053, 319); 
  vd_LCD_Write_Cmd(32, 0);
  vd_LCD_Write_Cmd(33, 0);

  vd_LCD_Write_Reg(34);

  for(i=0;i<76800;i++)
  {
    vd_LCD_WR_Data(u16_Value);  
  }
}

u16 u16_ili9320_GetPoint(u16 u16_X,u16 u16_Y)
{
    vd_drv_ili9320_SetCursor(u16_X,u16_Y);
    
    vd_LCD_Write_Reg(34);
  
    return (u16_ili9320_ReadData());
}

void ili9320_SetPoint(u16 u16_x,u16 u16_y,u16 u16_Point)
{
    vd_LCD_Write_Cmd(32, u16_y);
    vd_LCD_Write_Cmd(33, 319-u16_x);
    vd_LCD_Write_Reg(34);
    vd_LCD_WR_Data(u16_Point);  
}

void ili9320_DrawPicture(u16 u16_StartX,u16 u16_StartY,u16 u16_EndX,u16 u16_EndY,u16 *u16p_pic)
{
    u16  u16_i;
    vd_ili9320_SetWindows(u16_StartX,u16_StartY,u16_EndX,u16_EndY);
    vd_drv_ili9320_SetCursor(u16_StartX,u16_StartY);	    
    for (u16_i=0;u16_i<(u16_EndX*u16_EndY);u16_i++)
    {
        vd_LCD_WR_Data(*u16p_pic++);
    }
}

void vd_ili9320_PutChar(u16 u16_x,u16 u16_y,u8 u16_c,u16 u16_charColor,u16 u16_bkColor)
{
  u16 u16_i = 0u;
  u16 u16_j = 0u;
  
  u8 u8_tmp_char = 0u;

  for (u16_i = 0u;u16_i < 16u; u16_i++)
  {
    u8_tmp_char = 0x3Cu;//DBG SLG : ascii_8x16[((u16_c-0x20u)*16u)+u16_i];
    for (u16_j =0;u16_j < 8u; u16_j++)
    {
      if ( (u8_tmp_char >> 7u-u16_j) & 0x01u == 0x01u)
        {
          ili9320_SetPoint(u16_x+u16_j,u16_y+u16_i,u16_charColor);
        }
        else
        {
          ili9320_SetPoint(u16_x+u16_j,u16_y+u16_i,u16_bkColor);
        }
    }
  }
}

void vd_ili9320_Test(void)
{
  u16 i,j;
  vd_drv_ili9320_SetCursor(0u,0u);
  
  for(i = 0u;i < 320u;i++)
  {
    for(j = 0u;j < 240u;j++)
    {
      if(i>279)vd_LCD_WR_Data(0x0000);
      else if(i>239)vd_LCD_WR_Data(0x001f);
      else if(i>199)vd_LCD_WR_Data(0x07e0);
      else if(i>159)vd_LCD_WR_Data(0x07ff);
      else if(i>119)vd_LCD_WR_Data(0xf800);
      else if(i>79)vd_LCD_WR_Data(0xf81f);
      else if(i>39)vd_LCD_WR_Data(0xffe0);
      else vd_LCD_WR_Data(0xffff);
    }
  }
  
}

u16 u16_ili9320_BGR2RGB(u16 u16_c)
{
  u16  u16_r, u16_g, u16_b;

  u16_b = (u16_c >> 0u)  & 0x1FFu;
  u16_g = (u16_c >> 5u)  & 0x3Fu;
  u16_r = (u16_c >> 11u) & 0x1Fu;
  
  return( (u16_b << 11u) + (u16_g << 5u) + (u16_r << 0u) );
}

void vd_ili9320_WriteIndex(u16 u16_idx)
{
    vd_LCD_Write_Reg(u16_idx);
}

void vd_ili9320_WriteData(u16 u16_dat)
{
    vd_LCD_WR_Data(u16_dat);
}

u16 u16_ili9320_ReadData(void)
{
  u16 u16_val = 0u;
  u16_val = u32_LCD_RD_data();
  return u16_val;
}

u16 u16_ili9320_ReadRegister(u16 u16_index)
{
  u16 u16_tmp;

  u16_tmp= *(volatile unsigned int *)(0x60000000);
  
  return u16_tmp;
}

void vd_ili9320_WriteRegister(u16 u16_index,u16 u16_dat)
{
   /************************************************************************
    **                                                                    **
    ** nCS       ----\__________________________________________/-------  **
    ** RS        ------\____________/-----------------------------------  **
    ** nRD       -------------------------------------------------------  **
    ** nWR       --------\_______/--------\_____/-----------------------  **
    ** DB[0:15]  ---------[index]----------[data]-----------------------  **
    **                                                                    **
    ************************************************************************/
    
    vd_LCD_Write_Cmd(u16_index,u16_dat);
}

void vd_ili9320_Reset(void)
{
    /***************************************
     **                                   **
     **  -------\______________/-------   **
     **         | <---Tres---> |          **
     **                                   **
     **  Tres: Min.1ms                    **
     ***************************************/
    
 
}

void vd_ili9320_BackLight(u8 u8_status)
{
    if ( u8_status >= 1 )
    {
      //GPIO_SetBits(GPIOC,LCD_BK);
    }
    else
    {
      //GPIO_ResetBits(GPIOC,LCD_BK);
    }
}

void vd_ili9320_Delay(vu32 vu32_nCount)
{
  for(; vu32_nCount != 0; vu32_nCount--);
}