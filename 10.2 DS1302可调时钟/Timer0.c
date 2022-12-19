#include <REGX52.H>
#include "Timer0.h"

/**
 * @brief 定时器0初始化
 * @param 无
 * @retval 无
 */
void Timer0_Init(void)	// 1毫秒@11.0592MHz
{
	/*	TMOD	*/
	//TMOD = 0x01;
	/*	操纵其中某些位而不影响其它位	*/
	TMOD = TMOD & 0xf0;	//把TMOD的低4位清零，高4位保持不变	1010-0011 & 1111-0000 = 1010-0000
	TMOD = TMOD | 0x01;	//把TMOD的低4位置1，高4位保持不变(Note: 使其不影响定时器T1的数据)	1010-0000 & 0000-0001 = 1010-0001
	
	/*	TCON	*/
	TF0 = 0;	//定时器/计数器T0溢出中断标志
	TR0 = 1;	//定时器T0的运行控制位
	/*	计时器初值: 65535-65435=1000us=1ms	*/
	//TH0 = 64535 / 256;	//取高8位
	//TL0 = 64535 % 256;	//取低8位
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	
	/*	中断允许控制寄存器: IE	*/
	EA = 1;		//开总中断
	ET0 = 1;	//T0溢出中断允许

	/*	中断优先级控制寄存器: IP	*/
	PT0 = 0;	//低中断优先级
}

/**
 * @brief 定时器中断函数模板
 * @param 无
 * @retval 无
 */
/*
//unsigned int cnt;
void Timer0_Routine(void) interrupt 1	//定时器/计数器初始化函数
{
	static unsigned int cnt;
	TH0 = 64535 / 256;	//每次进中断之后都需要重新赋初值
	TL0 = 64535 % 256;
	cnt++;
	if(cnt >= 1000)
	{
		P2_0 = ~P2_0;
		cnt = 0;
	}
}
*/