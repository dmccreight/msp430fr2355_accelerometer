#include <stdint.h>

// GPIO registers
#define P1IN_REG (*((volatile uint8_t *) 0x200))
#define P1OUT_REG (*((volatile uint8_t *) 0x202))
#define P1DIR_REG (*((volatile uint8_t *) 0x204))
#define P1REN_REG (*((volatile uint8_t *) 0x206))
#define P1SEL0_REG  (*((volatile uint8_t *) 0x020A))
#define P1SEL1_REG  (*((volatile uint8_t *) 0x020C))

#define P2IN_REG (*((volatile uint8_t *) 0x201))
#define P2OUT_REG (*((volatile uint8_t *) 0x203))
#define P2DIR_REG (*((volatile uint8_t *) 0x205))
#define P2REN_REG (*((volatile uint8_t *) 0x207))
#define P2SEL0_REG  (*((volatile uint8_t *) 0x020B))
#define P2SEL1_REG  (*((volatile uint8_t *) 0x020D))

#define P3IN_REG (*((volatile uint8_t *) 0x220))
#define P3OUT_REG (*((volatile uint8_t *) 0x222))
#define P3DIR_REG (*((volatile uint8_t *) 0x224))
#define P3REN_REG (*((volatile uint8_t *) 0x226))
#define P3SEL0_REG  (*((volatile uint8_t *) 0x022A))
#define P3SEL1_REG  (*((volatile uint8_t *) 0x022C))

#define P4IN_REG (*((volatile uint8_t *) 0x221))
#define P4OUT_REG (*((volatile uint8_t *) 0x223))
#define P4DIR_REG (*((volatile uint8_t *) 0x225))
#define P4REN_REG (*((volatile uint8_t *) 0x227))
#define P4SEL0_REG  (*((volatile uint8_t *) 0x022B))
#define P4SEL1_REG  (*((volatile uint8_t *) 0x022D))

// UCA1 registers
#define UCA1CTLW0_REG  (*((volatile uint16_t *) 0x0580))
#define UCA1CTLW1_REG  (*((volatile uint16_t *) 0x0582))
#define UCA1BRW_REG  (*((volatile uint16_t *) 0x0586))
#define UCA1MCTLW_REG  (*((volatile uint16_t *) 0x0588))
#define UCA1STATW_REG  (*((volatile uint16_t *) 0x058A))
#define UCA1RXBUF_REG  (*((volatile uint16_t *) 0x058C))
#define UCA1TXBUF_REG  (*((volatile uint16_t *) 0x058E))
#define UCA1ABCTL_REG  (*((volatile uint16_t *) 0x0590))
#define UCA1IE_REG  (*((volatile uint16_t *) 0x059A))
#define UCA1IFG_REG  (*((volatile uint16_t *) 0x059C))

// ADC registers
#define ADCCTL0_REG  (*((volatile uint16_t *) 0x0700))
#define ADCCTL1_REG  (*((volatile uint16_t *) 0x0702))
#define ADCCTL2_REG  (*((volatile uint16_t *) 0x0704))
#define ADCMCTL0_REG  (*((volatile uint16_t *) 0x070A))
#define ADCMEM0_REG  (*((volatile uint16_t *) 0x0712))
#define ADCIFG_REG  (*((volatile uint16_t *) 0x071C))

// Timer B0 registers
#define TB0CTL_REG  (*((volatile uint16_t *) 0x0380))
#define TB0CCTL0_REG  (*((volatile uint16_t *) 0x0382))
#define TB0CCTL1_REG  (*((volatile uint16_t *) 0x0384))
#define TB0CCTL2_REG  (*((volatile uint16_t *) 0x0386))
#define TB0R_REG  (*((volatile uint16_t *) 0x0390))
#define TB0CCR0_REG  (*((volatile uint16_t *) 0x0392))
#define TB0CCR1_REG  (*((volatile uint16_t *) 0x0394))
#define TB0CCR2_REG  (*((volatile uint16_t *) 0x0396))
#define TB0EX0_REG  (*((volatile uint16_t *) 0x03A0))
#define TB0IV_REG  (*((volatile uint16_t *) 0x03AE))

// Timer B1 registers
#define TB1CTL_REG  (*((volatile uint16_t *) 0x03C0))
#define TB1CCTL0_REG  (*((volatile uint16_t *) 0x03C2))
#define TB1CCTL1_REG  (*((volatile uint16_t *) 0x03C4))
#define TB1CCTL2_REG  (*((volatile uint16_t *) 0x03C6))
#define TB1R_REG  (*((volatile uint16_t *) 0x03D0))
#define TB1CCR0_REG  (*((volatile uint16_t *) 0x03D2))
#define TB1CCR1_REG  (*((volatile uint16_t *) 0x03D4))
#define TB1CCR2_REG  (*((volatile uint16_t *) 0x03D6))
#define TB1EX0_REG  (*((volatile uint16_t *) 0x03E0))
#define TB1IV_REG  (*((volatile uint16_t *) 0x03EE))

// WDT
#define WDTCTL_REG  (*((volatile uint16_t *) 0x01CC))
#define WDT_PASSWORD (0x5A00)

// SAC0
#define SAC0OA_REG  (*((volatile uint16_t *) 0x0C80))
#define SAC0PGA_REG  (*((volatile uint16_t *) 0x0C82))
#define SAC0DAC_REG  (*((volatile uint16_t *) 0x0C84))
#define SAC0DAT_REG  (*((volatile uint16_t *) 0x0C86))
#define SAC0DATSTS_REG  (*((volatile uint16_t *) 0x0C88))
#define SAC0IV_REG  (*((volatile uint16_t *) 0x0C8A))

// SAC1
#define SAC1OA_REG  (*((volatile uint16_t *) 0x0C90))
#define SAC1PGA_REG  (*((volatile uint16_t *) 0x0C92))
#define SAC1DAC_REG  (*((volatile uint16_t *) 0x0C94))
#define SAC1DAT_REG  (*((volatile uint16_t *) 0x0C96))
#define SAC1DATSTS_REG  (*((volatile uint16_t *) 0x0C98))
#define SAC1IV_REG  (*((volatile uint16_t *) 0x0C9A))

// SAC2
#define SAC2OA_REG  (*((volatile uint16_t *) 0x0CA0))
#define SAC2PGA_REG  (*((volatile uint16_t *) 0x0CA2))
#define SAC2DAC_REG  (*((volatile uint16_t *) 0x0CA4))
#define SAC2DAT_REG  (*((volatile uint16_t *) 0x0CA6))
#define SAC2DATSTS_REG  (*((volatile uint16_t *) 0x0CA8))
#define SAC2IV_REG  (*((volatile uint16_t *) 0x0CAA))

// SAC3
#define SAC3OA_REG  (*((volatile uint16_t *) 0x0CB0))
#define SAC3PGA_REG  (*((volatile uint16_t *) 0x0CB2))
#define SAC3DAC_REG  (*((volatile uint16_t *) 0x0CB4))
#define SAC3DAT_REG  (*((volatile uint16_t *) 0x0CB6))
#define SAC3DATSTS_REG  (*((volatile uint16_t *) 0x0CB8))
#define SAC3IV_REG  (*((volatile uint16_t *) 0x0CBA))

#define FRCTL0_REG  (*((volatile uint16_t *) 0x01A0))
#define CSCTL0_REG  (*((volatile uint16_t *) 0x0180))
#define CSCTL1_REG  (*((volatile uint16_t *) 0x0182))
#define CSCTL2_REG  (*((volatile uint16_t *) 0x0184))
#define CSCTL3_REG  (*((volatile uint16_t *) 0x0186))
#define CSCTL4_REG  (*((volatile uint16_t *) 0x0188))
#define CSCTL7_REG  (*((volatile uint16_t *) 0x018E))

