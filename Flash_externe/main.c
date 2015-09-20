/**
 * \file m25p16.c
 * \brief main du programme
 * \author S.LE GUEN
 * \version 0.1
 * \date 03/09/2015
 */
#include <string.h>

#include "m25p16.h"

#define BUFFER_SIZE     (16)
#define SECTOR_NUMBER_0 (0x00)

uint8_t writeBuf[BUFFER_SIZE];
uint8_t readBuf[BUFFER_SIZE];

int main(void)
{
	uint8_t idx;
	uint32_t data = 0x00000000;
	uint32_t adress;
	FlashId flashInfo;

	//Init GPIOA
	m25p16GpioInit();
	//Init SPI1
	m25p16SpiInit();

	//Read identification code for M25P16
	m25p16ReadIdentification(&flashInfo);

	//Sector to erase
    adress = SECTOR_NUMBER_0;

    //Initialize read and write buffer with 0x00
    memset(&writeBuf[0],0,BUFFER_SIZE);
    memset(&readBuf[0],0,BUFFER_SIZE);

    //Fill write buffer with data
    for(idx=0x00;idx<BUFFER_SIZE;idx++)
    {
    	writeBuf[idx] = idx;
    }


    //Before writting, we must erase the selected sector
	m25p16EraseSector(adress);

	m25p16WriteBuffer(adress,&writeBuf[0],BUFFER_SIZE);
	m25p16ReadBuffer(adress,&readBuf[0],BUFFER_SIZE);

	idx = 0xFF;

    while(1)
    {
    }
}
