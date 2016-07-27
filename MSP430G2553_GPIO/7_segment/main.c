#include <msp430.h> 

/*
 * main.c
 */
#define SEG_PORT P2OUT
#define SEG_DIR P2DIR
void SegLed(short num);
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
	SEG_DIR = 0xFF;
	while(1){
		SegLed(7);
	}
}
void SegLed(short num){
     switch(num){
     case 0: SEG_PORT = 0x03; break;
     case 1: SEG_PORT = 0x9f; break;
     case 2: SEG_PORT = 0x25; break;
     case 3: SEG_PORT = 0x0D; break;
     case 4: SEG_PORT = 0x99; break;
     case 5: SEG_PORT = 0x49; break;
     case 6: SEG_PORT = 0x41; break;
     case 7: SEG_PORT = 0x1f; break;
     case 8: SEG_PORT = 0x01; break;
     case 9: SEG_PORT = 0x09; break;
     }
}
