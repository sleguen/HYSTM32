/**
 * \file main.c
 * \brief Fichier contenant la gestion des interruptions externes du STM32.
 * \author S.LE GUEN
 * \version 0.1
 * \date 05/09/2015
 */
#include "leds.h"
#include "exti.h"
/* macros ============================================================== */
/* constants =========================================================== */
/* types =============================================================== */
/* structures ========================================================== */
/* private variables =================================================== */
/* private functions =================================================== */
/* entry points ======================================================== */
/* public variables ==================================================== */
/* internal public functions =========================================== */
int main(void)
{
	initLeds();

	exti2Init();
	exti3Init();
	exti4Init();
	exti5Init();

    while(1)
    {
    }
}
