#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

//#define ONE
#define TWO

#ifdef ONE
void main(void)
{
	LCD_Init();
	LCD_ShowChar(1, 1, 'A');
	LCD_ShowString(1, 3, "Hello");
	LCD_ShowNum(1, 9, 1234, 3);
	LCD_ShowNum(1, 12, 1234, 5);
	LCD_ShowSignedNum(2, 1, -15, 2);
	LCD_ShowHexNum(2, 5, 0xAA, 2);
	LCD_ShowBinNum(2, 8, 0xAA, 8);
	
	while(1);
}

#elif defined TWO
int result = 0;
void main(void)
{
	LCD_Init();
	while(1)
	{
		result++;
		Delay(1000);
		LCD_ShowNum(1, 1, result, 2);
	}
}

#endif