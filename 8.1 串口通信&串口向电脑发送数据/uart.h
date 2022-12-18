#ifndef __UART_H__
#define __UART_H__

void UartInit(void);	//9600bps@11.0592MHz
void UART_Init(void);	//4800bps@12MHz
void UART_SendByte(unsigned char byte);
//void UART_SendString(unsigned char byte);

#endif // __UART_H__