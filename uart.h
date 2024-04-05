//***************************************************************************************
// LaunchPadFR2355 current project for UNL ECEN220
//***************************************************************************************

#ifndef UART_H
#define UART_H

#include <stdint.h>

extern void sendTxUARTByte(uint8_t x);
extern void initUART();
extern void checkRxUART(void);

#endif // UART_H
