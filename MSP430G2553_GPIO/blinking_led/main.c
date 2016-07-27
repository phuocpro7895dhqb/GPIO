#include <msp430.h> 

/*
 * main.c
 */
void delay(unsigned long time);
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	P1DIR |= 0x01;
	P1OUT |= 0x01;
	BCSCTL1 = CALBC1_1MHZ; // choose clock frequency 1MHz
	DCOCTL = CALDCO_1MHZ;
	while(1){
		__delay_cycles(1000000); // delay 1s
		P1OUT &= 0xFE;
		__delay_cycles(1000000); // delay 1s
		P1OUT |= 0x01;

	}
}
