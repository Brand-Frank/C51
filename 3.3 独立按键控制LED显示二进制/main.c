#include <reg52.h>
#include <intrins.h>

#define ONE
//#define TWO
//#define THREE

sbit D1 = P2^0;
sbit D2 = P2^1;
sbit D3 = P2^2;
sbit D4 = P2^3;
sbit K1 = P3^1;
typedef unsigned char uchar;

void Delay(uchar xms);

#if defined ONE
void main(void)
{
	while(1)
	{
		if(K1 == 0)
		{
			Delay(20);
			while(K1==0);
			Delay(20);
			D1 = ~D1;
		}
	}
}

#elif defined TWO

#elif defined THREE

#endif

void Delay(uchar xms)
{
	//_nop_();	//BUG: 会报错
	uchar i, j;
	//i = 2;	//BUG
	//j = 199;	//BUG: 延时有问题
	while(xms--)
	{
		i = 2;
		j = 199;
		do
		{
			while(--j);
		}
		while(--i);
		//xms--;
	}
		
}