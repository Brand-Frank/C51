#include <REGX52.H>
#include "Delay.h"
#include "uart.h"

unsigned char sec;

void main(void)
{
	unsigned char i;
	unsigned char str[] = {'H', 'e', 'l', 'l', 'o', ' '};
	
	//UART_Init();
	UartInit();
	//UART_SendByte(0x66);
	
	while(1)
	{
//		UART_SendByte(sec);
//		sec++;
//		Delay(1000);
		for(i = 0; i < (sizeof(str)/sizeof(str[0])); i++)
		{
			UART_SendByte(str[i]);
		}
		Delay(1000);
	}
}