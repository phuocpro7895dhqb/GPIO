#include <msp430.h> 

/*
 * main.c
 */
void fromrighttoleft();
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	BCSCTL1 = CALBC1_1MHZ; // choose 1MHz clock
	DCOCTL = CALDCO_1MHZ;
	P1DIR = 0xFF;
	while(1){
		P1OUT = 0xFF;
		fromrighttoleft();
	}
}
void fromrighttoleft(){
	unsigned short i = 0;
	for(i = 0; i < 8; i++){
		P1OUT <<= 1;
		__delay_cycles(100000); // delay 300 ms
	}
	__delay_cycles(100000);
}
