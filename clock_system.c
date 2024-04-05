#include <msp430.h>
#include <stdint.h>
#include "myRegisters.h"


void InitializeClockSystem(void)
{
    // pointers to registers

    // Configure two FRAM waitstate as required by the device datasheet for MCLK
    // operation at 24MHz(beyond 8MHz) before configuring the clock system.
    FRCTL0_REG = (0xA5 << 8) | (2 << 4);

    __bis_SR_register(SCG0);        // disable FLL

    // Reference section 3.3 from MSP430 users guide
    CSCTL3_REG = (1 << 4);                   // REFOLP = 0: low power disabled
                                    // SELREF = 0: FLL reference source = XT1CLK
                                    // FLLREFDIV = 0: div by 1
    CSCTL0_REG = 0;                   // clear DCO and MOD registers
    CSCTL1_REG = (7 << 1);            // DCORSEL = 7: DCO 24 MHz
    CSCTL2_REG = (731 << 0) | (0 << 12);                 // FLLD = 0: FLL loop divider = 1
                                    // FLLN = 731: N of DCO i.e. (731 + 1) * 32.768kHz = 23.986 MHz

    __bic_SR_register(SCG0);        // enable FLL

    // wait for FLL to lock
    while(((CSCTL7_REG) & (3 << 8)) != 0)
    {
        // wait
    }

    CSCTL4_REG = (1 << 8);            // SELMS = 000b: MCLK and SMCLK source is DCOCLKDIV
                                    // SELA = 01b:  ACLK source is REFO
}
