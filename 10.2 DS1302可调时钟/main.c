#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"
#include "key.h"
#include "Timer0.h"

unsigned char KeyNum, MODE, TimeSetSelect;
//按下按键1，改变MODE
void TimeShow(void)
{
	DS1302_ReadTime();
	LCD_ShowNum(1, 1, DS1302_Time[0], 2);
	LCD_ShowNum(1, 4, DS1302_Time[1], 2);
	LCD_ShowNum(1, 7, DS1302_Time[2], 2);
	LCD_ShowNum(2, 1, DS1302_Time[3], 2);
	LCD_ShowNum(2, 4, DS1302_Time[4], 2);
	LCD_ShowNum(2, 7, DS1302_Time[5], 2);	
}

//按键2，设置年月日时分秒
void TimeSet(void)
{
	if(KeyNum == 2)	//切换 年/月/日/时/分/秒 6种单独的模式，初始化按2时没用
	{
		TimeSetSelect++;
		if(TimeSetSelect > 5)	TimeSetSelect = 0; //循环切换
		//(TimeSetSelect++) %= 6;	//另一种切换方式，越界清零
		
	}
	LCD_ShowNum(2, 10, TimeSetSelect, 2);	//TEST: 测试切换的按键
}

void main(void)
{
	LCD_Init();
	DS1302_Init();
	LCD_ShowString(1, 1, "  -  -  ");
	LCD_ShowString(2, 1, "  :  :  ");
	
	DS1302_SetTime();
	
	while(1)
	{
		KeyNum = key();
		if(KeyNum == 1)	//按键1连按交替改变按键模式
		{
			if(MODE == 0)	{	MODE = 1;	}
			else if(MODE == 1)	{	MODE = 0;	}
		}
		switch(MODE)	//交替调用两个函数:初始值为0，显示时间，当按下按键时，模式改为1，时间停止，可以设置时间
		{
			case 0:	TimeShow(); break;
			case 1:	TimeSet();	break;
		}
	}
}
