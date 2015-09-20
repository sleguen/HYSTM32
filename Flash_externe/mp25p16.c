/**
 * \file m25p16.c
 * \brief Driver de la flash spi externe M25P16
 * \author S.LE GUEN
 * \version 0.1
 * \date 03/09/2015
 */
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_spi.h"

#include "m25p16.h"

/* macros ============================================================== */
/* constants =========================================================== */
#define MAX_BUFFER_SIZE (256)

//Error code
#define FLASH_BUFFER_ERROR    (0x00)
#define FLASH_BUFFER_OK       (0x01)

/* types =============================================================== */
/* structures ========================================================== */
/* private variables =================================================== */
/* private functions =================================================== */
static void csHigh(void)
{
	/* Deselect : Chip Select high */
	GPIO_SetBits(M25P16_SPI_GPIO_PORT, M25P16_CS_GPIO_PIN);
}

static void csLow(void)
{
	/* Deselect : Chip Select high */
	GPIO_ResetBits(M25P16_SPI_GPIO_PORT, M25P16_CS_GPIO_PIN);
}

static uint8_t sendSPI1Byte(uint8_t byte)
{
	while(SPI_I2S_GetFlagStatus(M25P16_SPI_PORT, SPI_I2S_FLAG_TXE) == RESET);

	SPI_I2S_SendData(M25P16_SPI_PORT, byte);

	while(SPI_I2S_GetFlagStatus(M25P16_SPI_PORT, SPI_I2S_FLAG_RXNE) == RESET);

	return SPI_I2S_ReceiveData(M25P16_SPI_PORT);

}

static uint8_t readSPI1Byte(void)
{
	return (sendSPI1Byte(DUMMY_BYTE));
}
/* entry points ======================================================== */
/* public variables ==================================================== */
/* public functions ==================================================== */

/**
 * \fn void m25p16GpioInit(void)
 * \brief Init gpio pin for spi communication. This function must be called
 * before m25p16SpiInit.
 */
void m25p16GpioInit(void)
{
	  GPIO_InitTypeDef GPIO_InitStructure;

	  RCC_APB2PeriphClockCmd(M25P16_SPI_GPIO_CLK | RCC_APB2Periph_AFIO, ENABLE);

	  /* Enable SPI1 clock */
	  RCC_APB2PeriphClockCmd(M25P16_SPI_PORT_CLK, ENABLE);

	  GPIO_InitStructure.GPIO_Pin   = M25P16_MOSI_GPIO_PIN |
			                          M25P16_SCK_GPIO_PIN;

	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
	  GPIO_Init(M25P16_SPI_GPIO_PORT, &GPIO_InitStructure);

	  GPIO_InitStructure.GPIO_Pin   = M25P16_MISO_GPIO_PIN;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
	  GPIO_Init(M25P16_SPI_GPIO_PORT, &GPIO_InitStructure);

	  GPIO_InitStructure.GPIO_Pin   = M25P16_CS_GPIO_PIN;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	  GPIO_Init(M25P16_SPI_GPIO_PORT, &GPIO_InitStructure);

	  csHigh();
}

/**
 * \fn uint8_t m25p16SpiInit(void)
 * \brief Init spi communication for m25p16 memory. To be called after m25p16GpioInit
 */
void m25p16SpiInit(void)
{
	SPI_InitTypeDef   SPI_InitStructure;

    SPI_InitStructure.SPI_Direction         = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStructure.SPI_Mode              = SPI_Mode_Master;
    SPI_InitStructure.SPI_DataSize          = SPI_DataSize_8b;
    SPI_InitStructure.SPI_CPOL              = SPI_CPOL_High;
    SPI_InitStructure.SPI_CPHA              = SPI_CPHA_2Edge;
    SPI_InitStructure.SPI_NSS               = SPI_NSS_Soft;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
    SPI_InitStructure.SPI_FirstBit          = SPI_FirstBit_MSB;
    SPI_InitStructure.SPI_CRCPolynomial     = 7;
    SPI_Init(M25P16_SPI_PORT, &SPI_InitStructure);

    SPI_Cmd(M25P16_SPI_PORT, ENABLE);
}


/**
 * \fn void m25p16WriteEnable(void)
 */
void m25p16WriteEnable(void)
{
   csLow();

   sendSPI1Byte(CMD_WRITE_ENABLE);

   csHigh();
}

/**
 * \fn void m25p16WriteDisable(void)
 */
void m25p16WriteDisable(void)
{
   csLow();

   sendSPI1Byte(CMD_WRITE_DISABLE);

   csHigh();
}

/**
 * \fn uint8_t m25p16ReadStatusRegister(void)
 * \brief Read the status register of flash memory
 * \return Status of the flash memory
 */
uint8_t m25p16ReadStatusRegister(void)
{
	uint8_t status;

	csLow();

	sendSPI1Byte(CMD_READ_STATUS_REGISTER);

	status = readSPI1Byte();

	csHigh();

	return (status);
}

/**
 * \fn void m25p16ReadIdentification(FlashId* flash)
 * \brief Read m25p16 indentification
 * \param flash Structure where the identification data will be stored
 */
void m25p16ReadIdentification(FlashId* flash)
{
	csHigh();
	csLow();

	sendSPI1Byte(CMD_READ_IDENTIFCATION);

	flash->manuId      = readSPI1Byte();
	flash->memType     = readSPI1Byte();
	flash->memCapacity = readSPI1Byte();

	csHigh();
}

/**
 * \fn void m25p16WritePage(uint32_t adress)
 * \brief Write data byte into the serial flash
 * \param adress Page adress to be written
 * \data Data to write
 */
void m25p16WritePage(const uint32_t adress,const uint8_t data)
{
    m25p16WriteEnable();

	csHigh();
	csLow();

	//Send Page Program command
	sendSPI1Byte(CMD_PAGE_PROGRAM);

	//Send adress where the datas will be written
	sendSPI1Byte( (adress & 0xFF0000) >> 16 );
	sendSPI1Byte( (adress & 0x00FF00) >> 8  );
	sendSPI1Byte( (adress & 0x0000FF) >> 0  );

	//Write the required data
	sendSPI1Byte( data );

	csHigh();

	m25p16CheckRdsrForWip();
}

/**
 * \fn uint8_t m25p16WriteBuffer(const uint32_t adress,uint8_t* pData, const uint8_t length)
 * \brief  Write data byte into the serial flash
 * \param adress Page adress to be written
 * \param pData Data pointer
 * \param length Length of data to write in the flash memory
 */
uint8_t m25p16WriteBuffer(const uint32_t adress,uint8_t* pData, const uint8_t length)
{
	uint8_t result;
    uint8_t idx;


    //Init return code by default
    result = FLASH_BUFFER_ERROR;

    if( length < MAX_BUFFER_SIZE )
    {
		m25p16WriteEnable();

		csHigh();
		csLow();

		//Send Page Program command
		sendSPI1Byte(CMD_PAGE_PROGRAM);

		//Send adress where the datas will be written
		sendSPI1Byte( (adress & 0xFF0000) >> 16 );
		sendSPI1Byte( (adress & 0x00FF00) >> 8  );
		sendSPI1Byte( (adress & 0x0000FF) >> 0  );

		//Write the required data
		for(idx=0; idx < length; idx++)
		{
			sendSPI1Byte( pData[idx] );
		}

		csHigh();

		m25p16CheckRdsrForWip();

		result = FLASH_BUFFER_OK;
    }

    return (result);
}


/**
 * \fn uint8_t m25p16ReadBuffer(const uint32_t adress,uint8_t* pData, const uint8_t length)
 * \brief  Write data byte into the serial flash
 * \param adress Page adress to be written
 * \param pData Data pointer
 * \param length Length of data to write in the flash memory
 */
uint8_t m25p16ReadBuffer(const uint32_t adress,uint8_t* pData, const uint8_t length)
{
	uint8_t result;
    uint8_t idx;


    result = FLASH_BUFFER_ERROR;

    if( length < MAX_BUFFER_SIZE )
    {
		m25p16WriteEnable();

		csHigh();
		csLow();

		//Send Page Program command
		sendSPI1Byte(CMD_PAGE_READ);

		//Send adress where the datas will be written
		sendSPI1Byte( (adress & 0xFF0000) >> 16 );
		sendSPI1Byte( (adress & 0x00FF00) >> 8  );
		sendSPI1Byte( (adress & 0x0000FF) >> 0  );

		//Write the required data
		for(idx=0; idx < length; idx++)
		{
			pData[idx] = readSPI1Byte();
		}

		csHigh();

		m25p16CheckRdsrForWip();

		result = FLASH_BUFFER_OK;
    }

    return (result);
}

/**
 * \fn void m25p16Read(const uint32_t adress, uint32_t *pData)
 * \brief Read data into the serial flash
 * \param adress Flash adress to be read
 */
void m25p16Read(const uint32_t adress, uint32_t *pData)
{
	csHigh();
	csLow();

	//Send Page Program command
	sendSPI1Byte(CMD_PAGE_READ);

	//Send adress where the datas will be written
	sendSPI1Byte( (adress & 0xFF0000) >> 16 );
	sendSPI1Byte( (adress & 0x00FF00) >> 8  );
	sendSPI1Byte( (adress & 0x0000FF) >> 0  );

	//Write the required data
    *pData = readSPI1Byte();

	csHigh();
}

/**
 * \fn void m25p16EraseSector(const uint32_t adress)
 * \brief Write data byte into the serial flash
 * \param adress
 */
void m25p16EraseSector(const uint32_t adress)
{
    m25p16WriteEnable();

	csHigh();
	csLow();

	//Send Page Program command
	sendSPI1Byte(CMD_ERASE_SECTOR);

	//Send flash adress sector who will be erased
	sendSPI1Byte( (adress & 0xFF0000) >> 16 );
	sendSPI1Byte( (adress & 0xFF00)   >> 8  );
	sendSPI1Byte( (adress & 0xFF)     >> 0  );

	csHigh();

	m25p16CheckRdsrForWip();
}

/**
 * \fn void m25p16CheckRdsrForWip(void)
 * \brief Wait the end of write
 */

void m25p16CheckRdsrForWip(void)
{
  uint8_t result = 0;

  csLow();

  sendSPI1Byte(CMD_READ_STATUS_REGISTER);

  do
  {
	  result = readSPI1Byte();
  }while ((result & M25P16_WIP_BIT_IDX) == SET);

  csHigh();
}
