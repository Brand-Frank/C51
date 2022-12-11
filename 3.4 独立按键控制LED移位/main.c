#include <REGX52.H>
#include <intrins.h>

#define ONE
#define TWO
#define THREE

sbit D1 = P2^0;
sbit D2 = P2^1;
sbit D3 = P2^2;
sbit D4 = P2^3;
sbit K1 = P3^1;
sbit K2 = P3^0;
typedef unsigned char uchar;

void Delay(uchar xms);

#if defined ONE
void main(void)
{
	uchar LEDNum = 0;
	P2 = ~(0x01);
	while(1)
	{
		if(K1 == 0)
		{
			Delay(20);
			while(K1 == 0);
			Delay(20);
			LEDNum++;
			LEDNum = (LEDNum >= 8) ? 0 : LEDNum;
			P2 = ~(0x01 << LEDNum);
		}
		if(K2 == 0)
		{
			Delay(20);
			while(K2 == 0);
			Delay(20);
			LEDNum = (LEDNum == 0) ? 7 : --LEDNum;
			P2 = ~(0x01 << LEDNum);	//Note: 都是基于0x01(0000-0001)来位移的
		}
	}
}

#elif defined TWO	//BUG
void main(void)
{
	uchar LEDNum = 1;
	while(1)
	{
		if(K1 == 0)
		{
			Delay(20);
			while(K1 == 0);
			Delay(20);
			P2 = ~LEDNum;
			LEDNum <<= LEDNum;
			LEDNum = (LEDNum < 8) ? LEDNum : 0;
		}
		
	}
}

#elif defined THREE

#endif

void Delay(uchar xms)
{
	uchar i, j;
	while(xms--)
	{
		i = 2;
		j = 199;
		do	{	while(--j);	}
		while(--i);
	}
}