#define Seg_Port P2OUT
#define Seg_Dir P2DIR
#define Sel_Port P1OUT
#define Sel_Dir P1DIR
#define Seg1 BIT0
#define Seg2 BIT1
#define Seg3 BIT2
#define Seg4 BIT3
void Seg7Init();
void SegLed(unsigned short num); // print 1 digit
void SegNumber(unsigned int number); // print number with 4 digits
void Seg7Init(){
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
	Seg_Dir = 0xFF;
	Seg_Port = 0xFF;
	Sel_Dir |= (Seg1 | Seg2 | Seg3 | Seg4);
	Sel_Port |= (Seg1 | Seg2 | Seg3 | Seg4);
}
void SegLed(unsigned short num){
     switch(num){
     case 0: Seg_Port = 0x03; break;
     case 1: Seg_Port = 0x9f; break;
     case 2: Seg_Port = 0x25; break;
     case 3: Seg_Port = 0x0D; break;
     case 4: Seg_Port = 0x99; break;
     case 5: Seg_Port = 0x49; break;
     case 6: Seg_Port = 0x41; break;
     case 7: Seg_Port = 0x1f; break;
     case 8: Seg_Port = 0x01; break;
     case 9: Seg_Port = 0x09; break;
     }
}
void SegNumber(unsigned int number){
	unsigned short a, b, c, d;
	a = number/1000;
	b = (number%1000)/100;
	c = (number%100)/10;
	d = (number%10);
	Sel_Port &= ~Seg1;
	SegLed(a);
	__delay_cycles(3000);
	Sel_Port |= Seg1;
	Sel_Port &= ~Seg2;
	SegLed(b);
	__delay_cycles(3000);
	Sel_Port |= Seg2;
	Sel_Port &= ~Seg3;
	SegLed(c);
	__delay_cycles(3000);
	Sel_Port |= Seg3;
	Sel_Port &= ~Seg4;
	SegLed(d);
	__delay_cycles(3000);
	Sel_Port |= Seg4;
}
