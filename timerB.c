//***************************************************************************************
// LaunchPadFR2355 current project for UNL ECEN220
//***************************************************************************************

#include <msp430.h>
#include <stdint.h>
#include "myRegisters.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

//#define USE_ACLK_TIMERB0

volatile uint32_t g_msecTick = 0;

void initTimerB0(void)
{
    /*
     * When the device is out of reset (BOR or POR), the timer is at stop condition
     * and all registers have default values. To start the timer from the default condition:
     * • Write 1 to the TBCLR bit (TBCLR = 1) to clear TBxR, clock divider state, and the counter direction.
     * • If necessary, write initial counter value to TBxR.
     * • Initialize TBxCCRn.
     * • Apply desired configuration to TBxIV, TBIDEX, and TBxCCTLn.
     * • Apply desired configuration to TBxCTL including to MC bits.
     */

#ifdef USE_ACLK_TIMERB0
    // Write a 1 to TBCLR register bit
    TB0CTL_REG = (1 << 2);

    // config TBxIV, TBIDEX, and TBxCCTLn registers
    // TBIDEX = 0: Input divider = 1
    TB0EX0_REG = 0;

    // CCIE[4] = 1; compare/capture interrupt enabled
    TB0CCTL0_REG = (1 << 4);

    // TB0R counts at ACLK/1/1 = 32 kHz / 1 = 32 counts per second
    // Set compare register to trigger compare interrupt once per msec
    // 0.001 * 32768 = 32
    TB0CCR0_REG = 32;

    // config TBxCTL register
    // TBSSEL[9-8] = 1; input clock source is ACLK (32.768 kHz)
    // ID[7-6] = 0; clock divider = 1
    // MC[5-4] = 1; Up mode; timer counts up to TB0CL0
    // TBIE[1] = 0; Timer_B interrupt disabled
    TB0CTL_REG = (1 << 8) | (0 << 6) | (1 << 4);
#else
    // Write a 1 to TBCLR register bit
    TB0CTL_REG = (1 << 2);

    // config TBxIV, TBIDEX, and TBxCCTLn registers
    // TBIDEX = 111b: Input divider = 8
    TB0EX0_REG = 7;

    // CCIE[4] = 1; compare/capture interrupt enabled
    TB0CCTL0_REG = (1 << 4);

    // TB0R counts at SMCLK/8/8 = 24 MHz / 64 = 375,000 counts per second
    // Set compare register to trigger compare interrupt once per msec
    // 0.001 * 375,000 = 375
    TB0CCR0_REG = 375 -1;

    // config TBxCTL register
    // TBSSEL[9-8] = 2; input clock source is SMCLK (24 MHz)
    // ID[7-6] = 3; clock divider = 8
    // MC[5-4] = 1; Up mode; timer counts up to TB0CL0
    // TBIE[1] = 0; Timer_B interrupt disabled
    TB0CTL_REG = (2 << 8) | (3 << 6) | (1 << 4);
#endif
}

// TB0CCR0 or CCIFG0
#pragma vector=TIMER0_B0_VECTOR
__interrupt void TimerB0_ISR (void)
{
    // ISR called every 1 msec
    g_msecTick++;
}

void initTimerB1(void)
{
    /*
     * When the device is out of reset (BOR or POR), the timer is at stop condition
     * and all registers have default values. To start the timer from the default condition:
     * • Write 1 to the TBCLR bit (TBCLR = 1) to clear TBxR, clock divider state, and the counter direction.
     * • If necessary, write initial counter value to TBxR.
     * • Initialize TBxCCRn.
     * • Apply desired configuration to TBxIV, TBIDEX, and TBxCCTLn.
     * • Apply desired configuration to TBxCTL including to MC bits.
     *
     *
     * Configure TimerB1 to generate a PWM signal
     * - timer in Up Mode
     * - outmode reset/set
     * - pin mux P2.0 (i.e. TB1.1) function to the timer
     */

    // Write a 1 to TBCLR register bit
    TB1CTL_REG = (1 << 2);

    // TBIDEX = 111b: Input divider = 8
    TB1EX0_REG = 7;

    // CCIE[4] = 0; compare/capture interrupt disabled
    TB1CCTL0_REG = 0;
    // OUTMOD[7-5] = 111b; Reset/set
    // CCIE[4] = 0; compare/capture interrupt disabled
    TB1CCTL1_REG = (7 << 5);

    // TB0R counts at SMCLK/8/8 = 24 MHz / 64 = 375000 counts per second
    // CCR0 register sets period e.g. Time * 375000 = CCR0
    // CCR1 register sets % duty cycle e.g. 100/1000 = 10%
    TB1CCR0_REG = 1000;
    TB1CCR1_REG = 100;

    // config TBxCTL register
    // TBSSEL[9-8] = 2; input clock source is SMCLK (24 MHz)
    // ID[7-6] = 3; clock divider = 8
    // MC[5-4] = 1; Up mode; timer counts up to TB0CL0
    // TBIE[1] = 0; Timer_B interrupt disabled
    TB1CTL_REG = (2 << 8) | (3 << 6) | (1 << 4);

    // Pin mux - Reference datasheet Table 6-64
    // Set P2.0 (TB1.1 to an output)
    // Set PSEL0 = 01b for TB.1 function
    P2DIR_REG |= 0x01; // set direction to output
    P2SEL0_REG |= 0x01; // PSEL0 = 01b
    P2SEL1_REG &= ~(0x01); // PSEL0 = 01b
}

// TB0CCR0 or CCIFG0
#pragma vector=TIMER1_B0_VECTOR
__interrupt void TimerB1_ISR (void)
{
}
