#include <REGX52.H>
#include "Delay.h"
#include "uart.h"

unsigned char sec;

void main(void)
{	
	UartInit();
	
	while(1)
	{

	}
}

//TODO: 增加LCD显示代码
void UART_Routine(void) interrupt 4
{
	if(RI == 1)
	{
		P2 = SBUF;
		UART_SendByte(SBUF);
		RI = 0;
	}
}