#ifndef _ILI_9320_H_
#define _ILI_9320_H_

void vd_drv_ili9320_Init(void);
void vd_drv_ili9320_Init(void);
void vd_drv_ili9320_SetCursor(u8 u8_x, u8 u8_y);
void vd_ili9320_SetWindows(u16 u16_StartX,u16 u16_StartY,u16 u16_EndX,u16 u16_EndY);
void vd_ili9320_Clear(u16 u16_Value);
u16 u16_ili9320_GetPoint(u16 u16_X,u16 u16_Y);
void ili9320_SetPoint(u16 u16_x,u16 u16_y,u16 u16_Point);
void ili9320_DrawPicture(u16 u16_StartX,u16 u16_StartY,u16 u16_EndX,u16 u16_EndY,u16 *u16p_pic);
void vd_ili9320_PutChar(u16 u16_x,u16 u16_y,u8 u16_c,u16 u16_charColor,u16 u16_bkColor);
void vd_ili9320_Test(void);
u16 u16_ili9320_BGR2RGB(u16 u16_c);
void vd_ili9320_WriteIndex(u16 u16_idx);
void vd_ili9320_WriteData(u16 u16_dat);
u16 u16_ili9320_ReadData(void);
u16 u16_ili9320_ReadRegister(u16 u16_index);
void vd_ili9320_WriteRegister(u16 u16_index,u16 u16_dat);
void vd_ili9320_Reset(void);
void vd_ili9320_BackLight(u8 u8_status);
void vd_ili9320_Delay(vu32 vu32_nCount);

#endif /*_ILI_9320_H_*/