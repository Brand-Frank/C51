#include <REGX52.H>
#include <INTRINS.H>
#include "Delay.h"

sbit Buzzer = P2^5;

/**
 * @brief 蜂鸣器私有延时函数，延时500us
 * @param 无
 * @retval 无
 */
void Buzzer_Delay500us(void)		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}

/**
 * @brief 蜂鸣器发生
 * @param ms 发声时长
 * @retval 无
 */
void Buzzer_Time(unsigned int ms)	//蜂鸣器持续时间
{
	unsigned int i;
	for(i = 0; i < ms*2; i++)
	{
		Buzzer = !Buzzer;
		Buzzer_Delay500us();	// 蜂鸣器单次响应频率，500*2=1ms = 1000Hz频率(一个周期)
		//Delay(1);
	}
}