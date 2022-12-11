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
	uchar LED_num = 0;
	while(1)
	{
		if(K1 == 0)
		{
			Delay(20);
			while(K1==0);
			Delay(20);
			LED_num++;		// 0000-0001	0000-0010	0000-0011
			//P2++;	//(1111-1111)++ --> 0000-0000 --> 0000-0001 --> 0000-0010
			P2 = ~LED_num;	// 1111-1110	1111-1101	1111-1100	//二进制显示
		}
	}
}

#elif defined TWO
void main(void)
{
	while(1)
	{
		if(K1 == 0)
		{
			Delay(20);
			while(K1==0);
			Delay(20);
			//D1 = ~D1;
			P2++;	//(1111-1111)++ --> 0000-0000 --> 0000-0001	//binary-lighting
			//P2 = ~P2;	//BUG: 灯不亮
		}
	}
}

#elif defined THREE	//BUG
void main(void)
{
	uchar tmp1 = 0xff;
	while(1)
	{
		if(K1 == 0)
		{
			P2 = tmp1;								0000-0000
			Delay(20);
			while(K1==0);	//未松开时会显示上面的P2值
			Delay(20);
			//D1 = ~D1;
			P2++;	//(1111-1111)++ --> 0000-0000 --> 0000-0001	//binary-lighting
			//P2 = ~P2;	//BUG: 灯不亮
			tmp1 = P2;	//显示P2的取反值 0000-0000	  0000-0001
			P2 = ~P2;	//保存P2值		 1111-1111	  1111-1110
		}
	}
}

#endif

void Delay(uchar xms)
{
	//_nop_();	//BUG: 会报错
	uchar i, j;
	//i = 2;	//BUG
	//j = 199;	//BUG: 延时有问题，时间会更长
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