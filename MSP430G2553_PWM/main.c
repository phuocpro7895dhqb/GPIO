#include <msp430.h> 

/*
 * main.c
 */
void PWMInit();
void PWMWrite(unsigned int number);
void LedInit();
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	LedInit();
	PWMInit();
	while(1){
	}
}
void PWMInit(){
	DCOCTL = 0;
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
	TA0CCTL1 = OUTMOD_7;
	TA0CCR0 = 1000;
	TA0CCR1 = 200;
	TA0CTL = TASSEL_2 + MC_1;
}
void PWMWrite(unsigned int number){
	TA0CCR1 = number;
}
void LedInit(){
	P2DIR|= BIT0;
	P2SEL |= BIT0;
}
