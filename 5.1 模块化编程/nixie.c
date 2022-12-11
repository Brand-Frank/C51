#include <REG52.H>
#include "nixie.h"
#include "delay.h"

/*	74HC138译码器	*/
sbit c = P2^4;
sbit b = P2^3;
sbit a = P2^2;

/*	8位数码管	*/
//	0011-1111(0), 0000-0110(1), 0101-1011(2), 0100-1111(3), 0110-0110(4), 
//	0110-1101(5), 0111-1101(6), 0000-0111(7), 1111-1111(8), 0110-1111(9)
unsigned char smg[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0xff, 0x6f};

void NixieTube(unsigned char location, unsigned char num)
{
	switch(location)
	{
		case 8:	//LED1 -> Y0 -> 000
			c = 0; b = 0; a = 0;	break;
		case 7:	//LED1 -> Y1 -> 001
			c = 0; b = 0; a = 1;	break;
		case 6:	//LED1 -> Y2 -> 010
			c = 0; b = 1; a = 0;	break;
		case 5:	//LED1 -> Y3 -> 011
			c = 0; b = 1; a = 1;	break;
		case 4:	//LED1 -> Y4 -> 100
			c = 1; b = 0; a = 0;	break;
		case 3:	//LED1 -> Y5 -> 101
			c = 1; b = 0; a = 1;	break;
		case 2:	//LED1 -> Y6 -> 110
			c = 1; b = 1; a = 0;	break;
		case 1:	//LED1 -> Y7 -> 111
			c = 1; b = 1; a = 1;	break;
	}
	P0 = smg[num];	//Note: it's P0, not P2 !
	Delay(1);
	P0 = 0x00;	//Note: 消影
}