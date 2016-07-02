/**
 * \file delay.c
 * \brief This file provide function to manage time delay based on Systick
 * Interupt
 * \author S.LE GUEN
 * \date 06/28/2016
 */

//User includes
#include "delay.h"

/* macros =================================================================== */
/* constants ================================================================ */
/* types ==================================================================== */
/* structures =============================================================== */
/* private variables ======================================================== */
static u32 u32_msDelay = 0u;
/* private functions ======================================================== */
/* entry points ============================================================= */
/* public variables ========================================================= */
/* internal public functions ================================================ */

/**
 * \fn void vd_delay_Init(void)
 * \brief Intialize the variable who contains the value of ms elapsed since
 * the begining
 */
void vd_delay_Init(void)
{
    u32_msDelay = 0u;
}

/**
 * \fn void vd_delay_IncTick(void)
 * \brief Increment the ms counter
 */
void vd_delay_IncTick(void)
{
    u32_msDelay++;
}

/**
 * \fn u32 u32_delay_GetTick(void)
 * \brief Get the value of the ms counter
 * \param none
 * \return u32_msDelay The value of the ms counter
 */
u32 u32_delay_GetTick(void)
{
    return (u32_msDelay);
}