#include <msp430.h> 
#include "Nhim7Seg.h"
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    Seg7Init();
    while(1){
    	SegNumber(1234);
    }
}
