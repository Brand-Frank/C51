#include <REGX52.H>
#include <INTRINS.H>
#include "Timer0.h"
#include "LCD1602.h"

//unsigned int sec=55, min=59, hour=23;
unsigned int sec, min, hour;

void main(void)
{
	LCD_Init();
	Timer0_Init();
	
	LCD_ShowString(1, 1, "Clock:");
	LCD_ShowString(2, 3, ":  :");
	
	while(1)
	{
		LCD_ShowNum(2, 1, hour, 2);
		LCD_ShowNum(2, 4, min, 2);
		LCD_ShowNum(2, 7, sec, 2);
	}
}


/*	中断函数会一直执行，因为没有关中断，每次赋初值后计时都是1000us=1ms,500次后执行一些操作	*/
unsigned int cnt;
void Timer0_Routine(void) interrupt 1	//定时器/计数器初始化函数
{
	TL0 = 0x18;	//每次进中断之后都需要重新赋初值
	TH0 = 0xFC;
	cnt++;
	if(cnt >= 1000)
	{
		sec++;	//定时1s, sec计数器加一
		if(sec >= 60)
		{
			sec = 0;
			min++;
			if(min >= 60)
			{
				sec = 0;
				min = 0;
				hour++;
				if(hour = 24)
				{
					hour = 0;
				}
			}
		}
		cnt = 0;
	}
}