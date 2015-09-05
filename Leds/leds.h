#ifndef _LEDS_H_
#define _LEDS_H_

#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
/* macros ============================================================== */
#define LED_D1_GPIO_PORT	GPIOC
#define LED_D1_GPIO_PIN		GPIO_Pin_6
#define LED_D1_GPIO_CLK     RCC_APB2Periph_GPIOC
#define LED_D1_GPIO_SPEED   GPIO_Speed_50MHz
#define LED_D1_GPIO_MODE    GPIO_Mode_Out_PP

#define LED_D2_GPIO_PORT	GPIOC
#define LED_D2_GPIO_PIN		GPIO_Pin_7
#define LED_D2_GPIO_CLK     RCC_APB2Periph_GPIOC
#define LED_D2_GPIO_SPEED   GPIO_Speed_50MHz
#define LED_D2_GPIO_MODE    GPIO_Mode_Out_PP

#define LED_D3_GPIO_PORT	GPIOD
#define LED_D3_GPIO_PIN		GPIO_Pin_13
#define LED_D3_GPIO_CLK     RCC_APB2Periph_GPIOD
#define LED_D3_GPIO_SPEED   GPIO_Speed_50MHz
#define LED_D3_GPIO_MODE    GPIO_Mode_Out_PP

#define LED_D4_GPIO_PORT	GPIOD
#define LED_D4_GPIO_PIN		GPIO_Pin_6
#define LED_D4_GPIO_CLK     RCC_APB2Periph_GPIOD
#define LED_D4_GPIO_SPEED   GPIO_Speed_50MHz
#define LED_D4_GPIO_MODE    GPIO_Mode_Out_PP
/* constants =========================================================== */
/* types =============================================================== */
/* structures ========================================================== */
/* internal public functions =========================================== */
/* entry points ======================================================== */
/* public variables ==================================================== */
/* inline public functions  ============================================ */
void initLeds(void);
void ledOn(GPIO_TypeDef *port,uint16_t pin);
void ledOff(GPIO_TypeDef *port,uint16_t pin);

#endif /*_LEDS_H_*/
