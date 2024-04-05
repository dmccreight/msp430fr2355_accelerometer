//***************************************************************************************
// LaunchPadFR2355 current project for UNL ECEN220
//***************************************************************************************

#include <msp430.h>
#include <stdint.h>
#include "myRegisters.h"


void initADC(void)
{
    // ADCSHTx[11-8] = 1; 8 ADCCLKs in sampling period
    // ADCON[4] = 1; turn ADC on
    // ADCENC[1] = 0; ADC disabled
    ADCCTL0_REG = (1 << 8) | (1 << 4);

    // ADCSHSx[11-10] = 00b; ADCSC bit starts sample-and-hold
    // ADCSHP[9] = 1; SAMPCON signal is sourced from sampling timer
    // ADCDIVx[7-5] = 101b; ADC clock divider = \6 (24MHz/6 = 4 MHz)
    // ADCSSELx[4-3] = 11b; ADC clock source = SMCLK
    // ADCCONSEQx[2-1] = 00b; Single-channel single-conversion
    ADCCTL1_REG = (1 << 9) | (5 << 5) | (3 << 3);

    // ADCPDIVx[9-8] = 00b; ADC pre-divider = 1
    // ADCRES[5-4] = 10b; 12-bit resolution
    // ADCSR[2] = 0b; ADC sampling rate up to 200ksps
    ADCCTL2_REG = (2 << 4);

    // ADCSREFx[6-4] = 000b; Vr+ = Vcc, Vr- = GND
    // ADCINCHx[3-0] = 0001b; Input channel A1 (P1.1)
    ADCMCTL0_REG = (0 << 4) | (1 << 0);

    // ADCENC[1] = 1; ADC enabled
    ADCCTL0_REG |= (1 << 1);
}

uint16_t getADCReading(void)
{

    // start a conversion
    ADCCTL0_REG = ADCCTL0_REG | (0x0001); // set ADSC bit

    // wait on ADCBUSY signal to clear
    while((ADCCTL1_REG & 0x0001) == 0x0001)
    {
        // waiting!!!
    }

    return ADCMEM0_REG;
}

uint16_t getADCChxReading(uint8_t channel)
{
}
