//***************************************************************************************
// LaunchPadFR2355 current project for UNL ECEN220
//***************************************************************************************

#include <msp430.h>
#include <stdint.h>

void delayInMsec(uint32_t delay)
{
    while (delay--)
    {
        // Assumes CPU clock is 24 MHz
        __delay_cycles(24000);
    }
}
