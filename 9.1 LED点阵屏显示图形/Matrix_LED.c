#include <REGX52.H>//Note: 注意这里的头文件需要显示在点阵屏显示头文件前面或者放在Matrix_LED.h文件中，这样点阵屏头文件里的P0和P3口的使用才不会报错
#include "Matrix_LED.h"
#include "Delay.h"

/**
 * @brief 点阵屏初始化
 * @param 无
 * @retval 无
 */
void MatrixLED_Init(void)
{
	SCK = 0;
	RCK = 0;
}

/**
 * @brief 74HC595写入一个字节
 * @param 要写入的一个字节
 * @retval 无
 */
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i = 0; i < 8; i++)
	{
		SER = Byte & (0x80 >> i);	//(1000-0000) 相当于等于1，非零即一，等效于下面的方式
		//if(byte & 0x80)	SER = 1;
		SCK = 1;	// 初始为0，置一的时候上升沿有效，寄存器中的值将发生移位
		SCK = 0;	// 置为0，为下一次上升做准备
	}
	RCK = 1;	// 初始为0，置一的时候上升沿有效，寄存器中的8位值将整体移到输出寄存器中
	RCK = 0;	// 置为0，为下一次上升做准备
}

/**
 * @brief LCD点阵屏显示一列数据
 * @param Column 要选择的列，范围：0~7，0在点阵屏最左边
 * @param Data 选择列显示数据，最高位在点阵屏上部，1为，0为灭
 * @retval 无
 */
void MatricLED_ShowColumn(unsigned char Column, unsigned char Data)
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT = ~(0x80 >> Column);
	Delay(1);				// 消除残影
	MATRIX_LED_PORT = 0xff;	// 位清零
}