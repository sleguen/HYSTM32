/**
 * \file delay.h
 * \brief Function protoypes used to manage time delay
 * \author S.LE GUEN
 * \date 06/28/2016
 */

#ifndef _DELAY_H
#define _DELAY_H_

//ST includes
#include "stm32f10x.h"

/* macros =================================================================== */
/* constants ================================================================ */
/* types ==================================================================== */
/* structures =============================================================== */
/* internal public functions ================================================ */
/* entry points ============================================================= */
/* public variables ========================================================= */
extern u32 u32_msDelay;
/* prototypes =============================================================== */
extern void vd_delay_Init(void);
extern void vd_delay_IncTick(void);
extern u32 u32_delay_GetTick(void);

#endif /* _DELAY_H_ */