#include <REG52.H>
#include <intrins.h>

#define ONE
//#define TWO
//#define THREE

sbit D1 = P2^0;
sbit D2 = P2^1;
sbit D3 = P2^2;
sbit D4 = P2^3;
sbit D5 = P2^4;
sbit D6 = P2^5;
sbit D7 = P2^6;
sbit D8 = P2^7;

sbit K1 = P3^1;

void Delay(unsigned int ms);
//void Delay500ms();

#if defined ONE
void main(void)
{
	while(1)
	{
		D1 = 0;	//一开始灯是亮的，按一次，取一次反
		if(K1 == 0)
		{
			Delay(20);	//按下消抖(Press to remove shaking)
			while(K1 == 0);	//检测按键是否松开，没松开就一直停在此处，否则松开了，执行后面的语句(Check whether the key is released. If not, stop here all the time. If not, execute the following statement)
			Delay(20);	//松开消抖(Release to eliminate shaking)
			D1 = ~D1;
		}
	}
}

#elif defined TWO

#elif defined THREE


#endif

void Delay(unsigned int ms)		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	
	do
	{
		i = 2;
		j = 199;
		do
		{
			
			while (--j);
		} while (--i);
	}while(ms--);
	
}
