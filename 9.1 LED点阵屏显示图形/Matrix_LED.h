#ifndef __MATRIX_LED_H__
#define __MATRIX_LED_H__

/*	使用的是main.c中的REGX52.h，main.c首先调用本头文件	*/
sbit RCK = P3^5;	//RCLK
sbit SCK = P3^6;	//SRCLK
sbit SER = P3^4;

#define MATRIX_LED_PORT P0

void MatrixLED_Init(void);
void _74HC595_WriteByte(unsigned char Byte);
void MatricLED_ShowColumn(unsigned char Byte, unsigned char Data);

#endif // __MATRIX_LED_H__