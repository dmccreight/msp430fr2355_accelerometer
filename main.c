#include <msp430.h>
#include <stdint.h>
#include "clock_system.h"
#include "uart.h"
#include "myRegisters.h"
#include "adc.h"
#include "timerB.h"


void main(void) {

    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    InitializeClockSystem();
    initUART();
    initADC();
    initTimerB0();

    /*
     * configure all GPIO here
     * P1.0: red LED
     */
    P1DIR_REG |= 0x01;                      // Set P1.0 to output direction
    P1OUT_REG = P1OUT_REG & ~(1 << 0);      // turn off RED led

    __enable_interrupt(); // sets GIE bit i.e. enables global interrupts

    sendTxUARTBytes("firmware version 1.0.0\r\n");

    while(1)
    {
        checkRxUART();
    }
}



