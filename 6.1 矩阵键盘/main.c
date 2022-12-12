#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"

unsigned char KeyNum;

#define ONE
//#define TWO

#ifdef ONE
void main(void)
{
	LCD_Init();
	LCD_ShowString(1, 1, "MatrixKey:");
	
	
	while(1)
	{
		KeyNum = MatrixKey();
		if(KeyNum)	//如果这里不作判断，则按键按下去后瞬间显示对应按键，然后显示00
		{
			LCD_ShowNum(2, 1, KeyNum, 2);
		}
	}
}

#elif defined TWO

#endif