//***************************************************************************************
// LaunchPadFR2355 current project for UNL ECEN220
//***************************************************************************************

#ifndef ADC_H
#define ADC_H

#include <stdint.h>

extern void initADC(void);
extern uint16_t getADCReading(void);
extern uint16_t getADCChxReading(uint8_t channel);


#endif // ADC_H
