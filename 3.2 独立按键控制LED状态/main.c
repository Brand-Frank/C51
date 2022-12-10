#include <REG52.H>
#include <intrins.h>

#define ONE
//#define TWO
//#define THREE

sbit LED_1 = P2^0;
sbit LED_2 = P2^1;
sbit LED_3 = P2^2;
sbit LED_4 = P2^3;
sbit LED_5 = P2^4;
sbit LED_6 = P2^5;
sbit LED_7 = P2^6;
sbit LED_8 = P2^7;

void Delay(unsigned int ms);
//void Delay500ms();

#if defined ONE
void main(void)
{
	while(1)
	{
		LED_1 = 0;
		LED_2 = 1;
		//Delay500ms();
		Delay(50000);
		LED_1 = 1;
		LED_2 = 0;
		//Delay500ms();
		Delay(50000);
	}
}

#elif defined TWO

#elif defined THREE


#endif

void Delay(unsigned int ms)		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		do
		{
			while(ms--);
		}
		while (--j);
	} while (--i);
}

//void Delay500ms()		//@11.0592MHz
//{
//	unsigned char i, j, k;

//	_nop_();
//	i = 4;
//	j = 129;
//	k = 119;
//	do
//	{
//		do
//		{
//			while (--k);
//		} while (--j);
//	} while (--i);
//}
