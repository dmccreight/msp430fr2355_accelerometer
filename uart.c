//***************************************************************************************
// LaunchPadFR2355 current project for UNL ECEN220
//***************************************************************************************

#include <msp430.h>
#include <stdint.h>
#include "myRegisters.h"
#include "uart.h"

#define CMD_BUFFER_LENGTH 20

uint8_t rxBytes[CMD_BUFFER_LENGTH];
uint8_t rxIndex = 0;


void initUART()
{
    /*
     * Reference section 22.3.1 eUSCI_A Initialization and Reset
     *
     * The recommended eUSCI_A initialization/reconfiguration process is:
     * 1. Set UCSWRST
     * 2. Initialize all eUSCI_A registers while UCSWRST = 1 (including UCAxCTL1).
     * 3. Configure ports.
     * 4. Clear UCSWRST
     * 5. Enable interrupts (optional) using UCRXIE or UCTXIE.
     */

    // 1. UART in reset
    // UCSSELx = 2: clock source SMCLK (24 MHz)
    // UCSWRST = 1: software reset enabled
    UCA1CTLW0_REG = (1 << 0) | (2 << 6);

    // 2. init all eUSCI_A registers
    //

    // Set the baud rate to 9600
    // UCOS16 = 1: over-sampling mode enabled
    // N = 24 MHz / baud rate
    // N = 2500
    // UCBRx = INT(N/16) = 156
    // UCBRFx = INT([(N/16) - INT(N/16)] x 16) = 4
    // UCBRSx = 0x00 (from lookup table)
    UCA1BRW_REG = 156;
    UCA1MCTLW_REG = (0x00 << 8) | (4 << 4) | (1 << 0);

    // 3. pin mux P4.3 and P4.2 as UART pins i.e. SELx = 01b
    P4SEL1_REG = 0x00; // write 0000 0000b to P4SEL1 register
    P4SEL0_REG = 0x0C; // set pins (TXD and RXD) function to UART (0000 1100b)

    // 4. clear UCSWRST
    UCA1CTLW0_REG = UCA1CTLW0_REG & ~(0x0001);

    // 5. Enable Rx interrupt
    UCA1IE_REG = (1 << 0);
}

void sendTxUARTByte(uint8_t x)
{
    uint16_t temp;
    // wait for IFG flag to be 1 i.e. TXBUF is empty
    temp = UCA1IFG_REG;
    while ((temp & 0x0002) == 0x0000)
    {
        temp = UCA1IFG_REG;
    }

    UCA1TXBUF_REG = x;
}

void sendTxUARTBytes(uint8_t * msg)
{
    while(*msg != 0)
    {
        // write to TXBUFF
        UCA1TXBUF_REG = *msg;

        while ((UCA1IFG_REG & 0x0002) == 0x0000)
        {
            // do nothing until TXBUF is empty
        }

        // now increment point to next character
        msg = msg + 1;
    }
}


// EUSC1A interrupt service routine
#pragma vector=EUSCI_A1_VECTOR
__interrupt void UART_ISR (void)
{
    // read rx byte out of RXBUF register
    uint8_t temp = UCA1RXBUF_REG;
    if (rxIndex < sizeof(rxBytes))
    {
        rxBytes[rxIndex] = temp;
        rxIndex = rxIndex + 1;
    }
}

void checkRxUART(void)
{
    uint8_t i;
    uint8_t cmd[3];

    /*
     * 1. check if I have available bytes
     * 2. check and act on valid commands
     * 3. potentially remove one byte
     */
    __disable_interrupt();
    if (rxIndex >= 3)
    {
        cmd[0] = rxBytes[0];
        cmd[1] = rxBytes[1];
        cmd[2] = rxBytes[2];

        // remove one byte
        for (i = 0; i < CMD_BUFFER_LENGTH - 1; i++)
        {
            rxBytes[i] = rxBytes[i+1];
        }
        rxIndex = rxIndex - 1;

    }
    __enable_interrupt();


        // I have enough bytes
        if (cmd[2] == '\r')
        {
            // command present, validate &  act on it
            switch (cmd[0])
            {
                case 'R':
                    // command opcode is a 'R'
                    if (cmd[1] == '0')
                    {
                        // turn off Red LED
                    }
                    else if (cmd[1] == '1')
                    {
                        // turn on Red LED
                    }
                    break;

                case 'G':
                    // command opcode is a 'G'
                    if (cmd[1] == '0')
                    {
                        // turn off Green LED
                    }
                    else if (cmd[1] == '1')
                    {
                        // turn on Green LED
                    }
                    break;

                default:
                    // unsupported command opcode
                    break;
            }

        }

}




