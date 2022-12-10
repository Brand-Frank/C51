#include <REG52.H>
#include <intrins.h>

//#define ONE	/*	Press K1 and observe the phenomenon*/
//#define TWO	/*	put if-else sentence to the place before while	*/
#define THREE	

sbit LED_1 = P2^0;
sbit LED_2 = P2^1;
sbit K1 = P3^1;
sbit K2 = P3^0;

void Delay500ms();

#if defined ONE	/*Press K1, LED will on*/
void main(void){
	while(1)
	{
		if(K1 == 0)
			LED_1 = 0;
		else
			LED_1 = 1;
	}
}

#elif defined TWO	/*it will not on, because at the init-time, K1=1 and LED_1=1*/
void main(void){
	if(K1 == 0)	LED_1 = 0;
	else	LED_1 = 1;
	while(1)
	{
		
	}
}

#elif defined THREE	/* && operate */
void main(void){
	while(1)
	{
		if(K1 == 0 && K2 == 0)	LED_1 = 0;
		if(K1 == 0) LED_1 = 1;
	}
}

#endif

void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
