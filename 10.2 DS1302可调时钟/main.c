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
	if(KeyNum == 2)	//Feature2: 切换 年/月/日/时/分/秒 6种单独的模式，初始化按2时没用
	{
		TimeSetSelect++;
		if(TimeSetSelect > 5)	TimeSetSelect = 0; //循环切换
		//(TimeSetSelect++) %= 6;	//另一种切换方式，越界清零
	}
	
	//Feature3: 年/月/日/时/分/秒 6种单独模式的加减
	if(KeyNum == 3) //时间+，通过操作DS1302_Time[]数组来指定年月日时分秒种的某个往上加
	{
		DS1302_Time[TimeSetSelect]++;
		/*	各个单独增加时的越界处理	*/
		if(DS1302_Time[0] > 99)	{ DS1302_Time[0] = 0; }	//年超过99后回到0
		if(DS1302_Time[1] > 12)	{ DS1302_Time[1] = 1; }	//月超过12月后回到1月
		/*	日超过28/29/30/31后回到1(判断平年与闰年)	*/
		if(DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 
			|| DS1302_Time[1]==8 || DS1302_Time[1]==10 || DS1302_Time[1]==12)	//一三五七八十腊，31天永不差
		{
			if(DS1302_Time[2] > 31)	{ DS1302_Time[2] = 1; }
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 || DS1302_Time[1]==11)	//4/6/9/11月30天
		{
			if(DS1302_Time[2] > 30)	{ DS1302_Time[2] = 1; }
		}
		else if(DS1302_Time[1] == 2)
		{
			if(DS1302_Time[0]%4 == 0)	//闰年
			{
				if(DS1302_Time[2] > 29)	{ DS1302_Time[2] = 1; }
			}
			else	//平年
			{
				if(DS1302_Time[2] > 28)	{ DS1302_Time[2] = 1; }
			}
		}
		if(DS1302_Time[3] > 23)	{ DS1302_Time[3] = 0; }	//时超过59后回到0
		if(DS1302_Time[4] > 59)	{ DS1302_Time[4] = 0; }	//分超过59后回到0
		if(DS1302_Time[5] > 59)	{ DS1302_Time[5] = 0; }	//秒超过59后回到0
	}
	if(KeyNum == 4) //时间-，通过操作DS1302_Time[]数组来指定年月日时分秒种的某个往下减
	{
		DS1302_Time[TimeSetSelect]--;
		/*	各个单独减小时的越界处理	*/
		if(DS1302_Time[0] < 0)	{ DS1302_Time[0] = 99; }	//年从0回到上世纪99年
		if(DS1302_Time[1] < 1)	{ DS1302_Time[1] = 12; }	//月从1月回到上一年12月
		/*	日超过28/29/30/31后回到1(判断平年与闰年)	*/
		if(DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 
			|| DS1302_Time[1]==8 || DS1302_Time[1]==10 || DS1302_Time[1]==12)	//一三五七八十腊，31天永不差
		{
			if(DS1302_Time[2] < 1)	{ DS1302_Time[2] = 31; }
			if(DS1302_Time[2] > 31)	{ DS1302_Time[2] = 1; }	//Note:应对日调到31时，月调整到小于31天的月时的不合理问题，如12-31(OK)->11-31(ERR)
		}
		else if(DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 || DS1302_Time[1]==11)	//4/6/9/11月30天
		{
			if(DS1302_Time[2] < 1)	{ DS1302_Time[2] = 30; }
			if(DS1302_Time[2] > 30)	{ DS1302_Time[2] = 1; }
		}
		else if(DS1302_Time[1] == 2)
		{
			if(DS1302_Time[0]%4 == 0)	//闰年
			{
				if(DS1302_Time[2] < 1)	{ DS1302_Time[2] = 29; }
				if(DS1302_Time[2] > 29)	{ DS1302_Time[2] = 1; }
			}
			else	//平年
			{
				if(DS1302_Time[2] < 1)	{ DS1302_Time[2] = 28; }
				if(DS1302_Time[2] > 28)	{ DS1302_Time[2] = 1; }
			}
		}
		if(DS1302_Time[3] < 0)	{ DS1302_Time[3] = 23; }	//从0回到23时
		if(DS1302_Time[4] < 0)	{ DS1302_Time[4] = 59; }	//从0回到59分
		if(DS1302_Time[5] < 0)	{ DS1302_Time[5] = 59; }	//从0回到59秒
	}
	
	LCD_ShowNum(1, 1, DS1302_Time[0], 2);
	LCD_ShowNum(1, 4, DS1302_Time[1], 2);
	LCD_ShowNum(1, 7, DS1302_Time[2], 2);
	LCD_ShowNum(2, 1, DS1302_Time[3], 2);
	LCD_ShowNum(2, 4, DS1302_Time[4], 2);
	LCD_ShowNum(2, 7, DS1302_Time[5], 2);	
	LCD_ShowNum(2, 10, TimeSetSelect, 2);	//TEST: 测试切换的按键
}

void main(void)
{
	LCD_Init();
	DS1302_Init();
	LCD_ShowString(1, 1, "  -  -  ");
	LCD_ShowString(2, 1, "  :  :  ");
	
	DS1302_SetTime();	//初始时间设置
	
	while(1)
	{
		KeyNum = key();
		if(KeyNum == 1)	//Feature1: 按键1连按交替改变按键模式
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
