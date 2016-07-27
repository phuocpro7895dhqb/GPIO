#include <msp430.h> 

/*
 * main.c
 */
#include "Nhim7Seg.h"
void interruptInit();
volatile unsigned int i = 0;
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	Seg7Init();
	interruptInit();
	while(1){
		SegNumber(i);
	}
}
void interruptInit(){
	P1DIR &= ~BIT5;
	P1REN |= BIT5;
	P1OUT |= BIT5;
	P1IE |= BIT5;
	P1IES |= BIT5;
	P1IFG &= ~BIT5;
	_BIS_SR(GIE);

}
#pragma vector = PORT1_VECTOR
__interrupt void Port(void)
{
	i++;
	P1IFG &= ~BIT5;
}
