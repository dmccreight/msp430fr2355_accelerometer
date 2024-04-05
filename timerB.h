//***************************************************************************************
// LaunchPadFR2355 current project for UNL ECEN220
//***************************************************************************************

#ifndef TIMER_B_H
#define TIMER_B_H

#include <stdint.h>

extern volatile uint32_t g_msecTick;

extern void initTimerB0(void);
extern void initTimerB1(void);

#endif // TIMER_B_H
