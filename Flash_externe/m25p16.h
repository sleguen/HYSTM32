#ifndef _M25P16_H_
#define _M25P16_H_

#include "misc.h"


/* macros ============================================================== */

/******************/
/* M25P16 GENERAL */
/******************/

#define DUMMY_BYTE 0xA5

/* Flag position of the status register */
#define M25P16_WEL_BIT_IDX (0x02)
#define M25P16_WIP_BIT_IDX (0x01)

/* Command set */
#define CMD_READ_IDENTIFCATION      (0x9F)
#define CMD_WRITE_ENABLE            (0x06)
#define CMD_WRITE_DISABLE           (0x04)
#define CMD_READ_STATUS_REGISTER    (0x05)
#define CMD_PAGE_PROGRAM            (0x02)
#define CMD_PAGE_READ               (0x03)
#define CMD_ERASE_SECTOR			(0xD8)

/* M25P16 SPI CONFIGURATION */
#define M25P16_SPI_GPIO_PORT    GPIOA
#define M25P16_SPI_GPIO_CLK     RCC_APB2Periph_GPIOA
#define M25P16_SPI_GPIO_SPEED   GPIO_Speed_10MHz
#define M25P16_SPI_GPIO_MODE    GPIO_Mode_AF_PP

/* MOSI --> PA7 */
#define M25P16_MOSI_GPIO_PIN    GPIO_Pin_7

/* MISO --> PA6 */
#define M25P16_MISO_GPIO_PIN    GPIO_Pin_6

/* SCK --> PA5 */
#define M25P16_SCK_GPIO_PIN     GPIO_Pin_5

/* CS --> PA4 */
#define M25P16_CS_GPIO_PIN      GPIO_Pin_4


/* SPI1 Configuration */
#define M25P16_SPI_PORT         SPI1
#define M25P16_SPI_PORT_CLK     RCC_APB2Periph_SPI1

#define UID_CONTENT_LENGTH 16

/* constants =========================================================== */
/* types =============================================================== */
/* structures ========================================================== */
typedef struct
{
	uint8_t manuId;
	uint8_t memType;
	uint8_t memCapacity;
	uint8_t uidLength;
    uint8_t uidContent[UID_CONTENT_LENGTH];
}FlashId;
/* internal public functions =========================================== */
/* entry points ======================================================== */
/* public variables ==================================================== */
/* public functions  =================================================== */
void m25p16GpioInit(void);
void m25p16SpiInit(void);
void m25p16WriteEnable(void);
void m25p16WriteDisable(void);
uint8_t m25p16ReadStatusRegister(void);
void m25p16ReadIdentification(FlashId* flash);
void m25p16WritePage(const uint32_t adress,const uint8_t data);
uint8_t m25p16WriteBuffer(const uint32_t adress,uint8_t* pData, const uint8_t length);
uint8_t m25p16ReadBuffer(const uint32_t adress,uint8_t* pData, const uint8_t length);
void m25p16Read(const uint32_t adress, uint32_t *pData);
void m25p16EraseSector(const uint32_t adress);
void m25p16CheckRdsrForWip(void);
#endif /*_M25P16_H_*/
