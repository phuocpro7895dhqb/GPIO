#include <msp430.h> 
/*
 * main.c
 */
void TimerA0Init();
void LedInit();
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	TimerA0Init();
	LedInit();
	while(1){

	}
}
void TimerA0Init(){
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
	TA0CTL |= TASSEL_2 | MC_3 |TAIE;
	TA0CCR0 = 50000;
	_BIS_SR(GIE);
}
void LedInit(){
	P2DIR |= BIT0;
	P2OUT |= BIT0;
}
#pragma vector = TIMER0_A1_VECTOR
__interrupt void timerA(void){
	if(TA0IV == 10){
		P2OUT ^= BIT0;
	}
}
