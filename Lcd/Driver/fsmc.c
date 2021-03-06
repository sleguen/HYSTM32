/**
 * \file stm32_fsmc.h
 * \brief Function protoypes used to manage time delay
 * \author S.LE GUEN
 * \date 06/28/2016
 */
//User includes
#include "fsmc.h"

//ST includes
#include "stm32f10x_rcc.h"
#include "stm32f10x_fsmc.h"

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
 * \fn void FSMC_Init(void)
 * \brief Intialize FSMC bus
 */
void vd_FSMC_Init(void)
{
  FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
  FSMC_NORSRAMTimingInitTypeDef  p;
  
  //Activate FSMC peripheral clock
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);

  p.FSMC_AddressSetupTime      = 0x02;
  p.FSMC_AddressHoldTime       = 0x00;
  p.FSMC_DataSetupTime         = 0x05;
  p.FSMC_BusTurnAroundDuration = 0x00;
  p.FSMC_CLKDivision           = 0x00;
  p.FSMC_DataLatency           = 0x00;
  p.FSMC_AccessMode            = FSMC_AccessMode_B;

  FSMC_NORSRAMInitStructure.FSMC_Bank                  = FSMC_Bank1_NORSRAM1;
  FSMC_NORSRAMInitStructure.FSMC_DataAddressMux        = FSMC_DataAddressMux_Disable;
  FSMC_NORSRAMInitStructure.FSMC_MemoryType            = FSMC_MemoryType_NOR;
  FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth       = FSMC_MemoryDataWidth_16b;
  FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode       = FSMC_BurstAccessMode_Disable;
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity    = FSMC_WaitSignalPolarity_Low;
  FSMC_NORSRAMInitStructure.FSMC_WrapMode              = FSMC_WrapMode_Disable;
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive      = FSMC_WaitSignalActive_BeforeWaitState;
  FSMC_NORSRAMInitStructure.FSMC_WriteOperation        = FSMC_WriteOperation_Enable;
  FSMC_NORSRAMInitStructure.FSMC_WaitSignal            = FSMC_WaitSignal_Disable;
  FSMC_NORSRAMInitStructure.FSMC_ExtendedMode          = FSMC_ExtendedMode_Disable;
  FSMC_NORSRAMInitStructure.FSMC_WriteBurst            = FSMC_WriteBurst_Disable;
  FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
  FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct     = &p;	  

  FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure); 

  /* Enable FSMC Bank1_SRAM Bank */
  FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);  
}
