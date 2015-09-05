/**
 * \file leds.c
 * \brief Fichier contenant la gestion des interruptions externes du STM32.
 * \author S.LE GUEN
 * \version 0.1
 * \date 03/09/2015
 */
#include "leds.h"

/* macros ============================================================== */
/* constants =========================================================== */
/* types =============================================================== */
/* structures ========================================================== */
/* private variables =================================================== */
/* private functions =================================================== */
/* entry points ======================================================== */
/* public variables ==================================================== */
/* internal public functions =========================================== */

/**
 * \fn void initLeds(void)
 * \brief Initialisation des leds de la board HY-STM32
 */
void initLeds(void)
{
	  GPIO_InitTypeDef GPIO_InitStructure;

	  /* Initialisation de la clock du port GPIO de D1 D2 D3 et D4 */
      RCC_APB2PeriphClockCmd(LED_D1_GPIO_CLK |
    		  	  	  	  	 LED_D2_GPIO_CLK |
    		  	  	  	  	 LED_D3_GPIO_CLK |
    		  	  	  	  	 LED_D4_GPIO_CLK,
    		  	  	  	  	 ENABLE);

      /* Initialisation du port GPIO associé à D1 */
	  GPIO_InitStructure.GPIO_Speed = LED_D1_GPIO_SPEED;
	  GPIO_InitStructure.GPIO_Mode  = LED_D1_GPIO_MODE;
	  GPIO_InitStructure.GPIO_Pin   = LED_D1_GPIO_PIN ;
	  GPIO_Init(LED_D1_GPIO_PORT, &GPIO_InitStructure);

      /* Initialisation du port GPIO associé à D2 */
	  GPIO_InitStructure.GPIO_Speed = LED_D2_GPIO_SPEED;
	  GPIO_InitStructure.GPIO_Mode  = LED_D2_GPIO_MODE;
	  GPIO_InitStructure.GPIO_Pin   = LED_D2_GPIO_PIN ;
	  GPIO_Init(LED_D2_GPIO_PORT, &GPIO_InitStructure);

      /* Initialisation du port GPIO associé à D3 */
	  GPIO_InitStructure.GPIO_Speed = LED_D3_GPIO_SPEED;
	  GPIO_InitStructure.GPIO_Mode  = LED_D3_GPIO_MODE;
	  GPIO_InitStructure.GPIO_Pin   = LED_D3_GPIO_PIN ;
	  GPIO_Init(LED_D3_GPIO_PORT, &GPIO_InitStructure);

      /* Initialisation du port GPIO associé à D4 */
	  GPIO_InitStructure.GPIO_Speed = LED_D4_GPIO_SPEED;
	  GPIO_InitStructure.GPIO_Mode  = LED_D4_GPIO_MODE;
	  GPIO_InitStructure.GPIO_Pin   = LED_D4_GPIO_PIN ;
	  GPIO_Init(LED_D4_GPIO_PORT, &GPIO_InitStructure);
}

/**
 * \fn void initLeds(void)
 * \brief Allume une led
 * \param port Pointeur representant le port GPIO
 * \param pin  Valeur representant le numero de la pin associee a la led
 */
void ledOn(GPIO_TypeDef *port,uint16_t pin)
{
	GPIO_SetBits(port,pin);
}

/**
 * \fn void initLeds(void)
 * \brief Eteind une led
 * \param port Pointeur representant le port GPIO
 * \param pin  Valeur representant le numero de la pin associee a la led
 */
void ledOff(GPIO_TypeDef *port,uint16_t pin)
{
	GPIO_ResetBits(port,pin);
}


