#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password;
unsigned int cnt = 0;
#define PASS 2345

#define ONE
//#define TWO

#ifdef ONE
void main(void)
{
	LCD_Init();
	LCD_ShowString(1, 1, "Password:");
	
	while(1)
	{
		KeyNum = MatrixKey();
		if(KeyNum)	//如果这里不作判断，则按键按下去后瞬间显示对应按键，然后显示00
		{
			if(KeyNum <= 10)	//S1-S10,输入密码
			{
				if(cnt < 4)
				{
					Password *= 10;			//左移一位；
					Password += KeyNum % 10;		//获取一位密码
					cnt++;
				}
				LCD_ShowNum(2, 1, Password, 4);
			}
			if(KeyNum == 11)	//如果S11按键按下，确认
			{
				if(Password == PASS)	//如果密码正确，显示OK
				{
					LCD_ShowString(1, 14, "OK ");
					Password = 0;	//密码清理
					cnt = 0;	//计数清零，继续输入
					LCD_ShowNum(2, 1, Password, 4);	//更新显示
				}
				else	//否则显示ERR
				{
					LCD_ShowString(1, 14, "ERR");
					Password = 0;	//密码清理
					cnt = 0;	//计数清零，继续输入
					LCD_ShowNum(2, 1, Password, 4);	//更新显示
				}
			}
			if(KeyNum == 12)	//如果S12按键按下，取消
			{
				LCD_ShowString(1, 14, "ESC");
				Password = 0;	//密码清理
				cnt = 0;	//计数清零，继续输入
				LCD_ShowNum(2, 1, Password, 4);
				Delay(1000);
				LCD_ShowString(1, 14, "   ");
			}
		}
	}
}

#elif defined TWO

#endif