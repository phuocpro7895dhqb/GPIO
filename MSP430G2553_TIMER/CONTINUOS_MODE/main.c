#include <msp430.h> 
#include "Nhim7Seg.h"
/*
 * main.c
 */
volatile unsigned int i = 0;
volatile unsigned int a = 0;
void TimerAInit();
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    TimerAInit();
    Seg7Init();
    while(1){
    	SegNumber(a);
    }
}
void TimerAInit(){
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
	TA0CTL |= TASSEL_2 | MC_2 | TAIE; // page 370
	_BIS_SR(GIE);
}
#pragma vector = TIMER0_A1_VECTOR
__interrupt void Timer_A_1(void){
	if(TA0IV == 10) // page 370
	{
		i++;
		if(i == 5)
		{
			a++;
			i = 0;
		}
	}
}
