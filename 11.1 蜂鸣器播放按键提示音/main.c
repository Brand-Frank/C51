#include <REGX52.H>
#include "Delay.h"
#include "nixie.h"
#include "key.h"
#include "buzzer.h"

unsigned char KeyNum;

void main(void)
{
	NixieTube(1, 0);	//初始时第一位数码管显示为0
	while(1)
	{
		KeyNum = key();
		if(KeyNum)
		{
			Buzzer_Time(10);
			NixieTube(1, KeyNum);	//第一位数码管显示为对应按键值
		}
	}
}