#include "uart.h"
#include <REGX52.H>

/**
 * @brief 串口初始化，配置相关寄存器（stc-isp）
 * @param 无
 * @retval 无
 */
void UartInit(void)		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFD;		//设定定时初值
	TH1 = 0xFD;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
}

/**
 * @brief 串口初始化，配置相关寄存器（江科大）
 * @param 无
 * @retval 无
 */
void UART_Init(void)	//4800bps@12MHz
{
	SCON = 0x40;	//0100-0000
	PCON |= 0x80;
	
	/*	定时器T1	*/
	TMOD &= 0x0f;
	TMOD |= 0x20;
	TH1 = 0xf3;
	TL1 = 0xf3;
	ET1 = 0;
	TR1 = 1;
}

/**
 * @brief 串口发送一个字节数据
 * @param Byte 要发送的一个字节数据
 * @retval 无
 */
void UART_SendByte(unsigned char byte)
{
	SBUF = byte;
	while(TI == 0);
	TI = 0;
}

//TODO: send_string()
/**
 * @brief 串口发送一段字符串
 * @param Byte 要发送的一段字符串
 * @retval 无
 */
//void UART_SendString(unsigned char byte)
//{
//	unsigned char temp, i;
//	for(i = 0; i < 6; i++)
//	{
//		
//	}
//}