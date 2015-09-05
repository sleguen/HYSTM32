#include "leds.h"
/* macros ============================================================== */
/* constants =========================================================== */
/* types =============================================================== */
/* structures ========================================================== */
/* private variables =================================================== */
/* private functions =================================================== */
/* internal public functions =========================================== */
/* public variables ==================================================== */
/* entry points ======================================================== */
int main(void)
{
	int i;

	initLeds();

	while(1)
	{
		ledOn(LED_D1_GPIO_PORT,LED_D1_GPIO_PIN);
		ledOn(LED_D2_GPIO_PORT,LED_D2_GPIO_PIN);
		ledOn(LED_D3_GPIO_PORT,LED_D3_GPIO_PIN);
		ledOn(LED_D4_GPIO_PORT,LED_D4_GPIO_PIN);

		for(i=0;i<0x500000;i++);

		ledOff(LED_D1_GPIO_PORT,LED_D1_GPIO_PIN);
		ledOff(LED_D2_GPIO_PORT,LED_D2_GPIO_PIN);
		ledOff(LED_D3_GPIO_PORT,LED_D3_GPIO_PIN);
		ledOff(LED_D4_GPIO_PORT,LED_D4_GPIO_PIN);

		for(i=0;i<0x500000;i++);

	}

}
