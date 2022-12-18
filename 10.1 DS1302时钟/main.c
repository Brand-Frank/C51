#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"

//#define FIRST_TEST
#define LAST

#if defined LAST
void main(void)
{
	LCD_Init();
	DS1302_Init();
	LCD_ShowString(1, 1, "  -  -  ");
	LCD_ShowString(2, 1, "  :  :  ");
	
	DS1302_SetTime();
	
	while(1)
	{
		DS1302_ReadTime();
		LCD_ShowNum(1, 1, DS1302_Time[0], 2);
		LCD_ShowNum(1, 4, DS1302_Time[1], 2);
		LCD_ShowNum(1, 7, DS1302_Time[2], 2);
		LCD_ShowNum(2, 1, DS1302_Time[3], 2);
		LCD_ShowNum(2, 4, DS1302_Time[4], 2);
		LCD_ShowNum(2, 7, DS1302_Time[5], 2);	
	}
}

#elif defined FIRST_TEST
unsigned char sec, min;
void main(void)
{
	LCD_Init();
	DS1302_Init();
	LCD_ShowString(1, 1, "RTC");
	
	DS1302_WriteByte(0x80, 0x55);
	
	while(1)
	{
		sec = DS1302_ReadByte(0x81);		//此时的sec为BCD码显示，需要转码为十进制
		min = DS1302_ReadByte(0x83);
		LCD_ShowNum(2, 1, sec/16*10+sec%16, 2);
		LCD_ShowNum(2, 3, min/16*10+min%16, 2);
		Delay(50);
	}
}

#endif