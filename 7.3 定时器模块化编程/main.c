#include <REGX52.H>
#include <INTRINS.H>
#include "Timer0.h"
#include "key.h"

unsigned char KeyNum = 0;
unsigned char LEDMode = 0;

//#define ONE
#define TWO

void main(void)
{
	P2 = 0xfe;
	Timer0_Init();
	while(1)
	{
		KeyNum = key();	//如果没有按键按下，则下面不执行，直接进行定时器中断
		if(KeyNum)
		{
			if(KeyNum == 1)
			{
				LEDMode++;
				if(LEDMode >= 2) LEDMode = 0;
			}
			//if(KeyNum == 1) P2_0 = ~P2_0;
			//if(KeyNum == 2) P2_1 = ~P2_1;
			//if(KeyNum == 3) P2_2 = ~P2_2;
			//if(KeyNum == 4) P2_3 = ~P2_3;
		}
	}
}

#if defined ONE
void Timer0_Init()
{
	/*	TMOD	*/
	TMOD = 0x01;
	
	/*	TCON	*/
	TF0 = 0;	//定时器/计数器T0溢出中断标志
	TR0 = 1;	//定时器T0的运行控制位
	/*	计时器初值: 65535-65435=1000us=1ms	*/
	TH0 = 64535 / 256;	//取高8位
	TL0 = 64535 % 256;	//取低8位
	
	/*	中断允许控制寄存器: IE	*/
	EA = 1;		//开总中断
	ET0 = 1;	//T0溢出中断允许

	/*	中断优先级控制寄存器: IP	*/
	PT0 = 0;
}

unsigned int cnt;
void Timer0_Routine(void) interrupt 1	//定时器/计数器初始化函数
{
	TH0 = 64535 / 256;	//每次进中断之后都需要重新赋初值
	TL0 = 64535 % 256;
	cnt++;
	if(cnt >= 1000)
	{
		P2_0 = ~P2_0;
		cnt = 0;
	}
}

#elif defined TWO

/*	中断函数会一直执行，因为没有关中断，每次赋初值后计时都是1000us=1ms,500次后执行一些操作	*/
unsigned int cnt;
void Timer0_Routine(void) interrupt 1	//定时器/计数器初始化函数
{
	//TH0 = 64535 / 256;	//每次进中断之后都需要重新赋初值
	//TL0 = 64535 % 256;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	cnt++;
	//if(cnt >= 500)
	if(cnt == 500)
	{
		if(LEDMode == 0) //第0次或偶数次，左移
			P2 = _crol_(P2, 1);	//1111-1110 --> 1111-1101 --> 1111-1011,开发板灯从左向右亮
		if(LEDMode == 1)
			P2 = _cror_(P2, 1);
		//P2_0 = ~P2_0;
		cnt = 0;
	}
}

#endif