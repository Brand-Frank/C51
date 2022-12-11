#include <REGX52.H>
#include <intrins.h>

#define ONE
//#define TWO
//#define THREE

typedef unsigned char u8;
sbit K1 = P3^1;
sbit D1 = P2^0;

/*	74HC138译码器	*/
sbit c = P2^4;
sbit b = P2^3;
sbit a = P2^2;

/*	8位数码管	*/
//0011-1111(0), 0000-0110(1), 0101-1011(2), 0100-1111(3), 0110-0110(4), 0110-1101(5), 0111-1101(6), 0000-0111(7), 1111-1111(8), 0110-1111(9)
u8 smg[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0xff, 0x6f};

void Delay(u8 xms);
void NixieTube(u8 location, u8 num);

/*	单片机直接扫描方式：硬件设备简单，但是会耗费大量的单片机CPU时间，
还有一种专用驱动芯片(TM1640)，内部自带显存、扫描电路
74HC595, 只需要5根线，而本示例需要3+8=11根线	*/
#if defined ONE	
void main(void)
{
	while(1)
	{
		/*
			通过延时来**消影**，给74HC254双向缓冲器延时缓冲，不然会把上一位数码管的数据传到它下一位数码管上
			产生原因： 位选 段选 ->(串位)-> 位选 段选 位选 段选 位选...
			解决方法：显示之后，将整段清零
		*/
		NixieTube(1, 1);	//Delay(5);
		NixieTube(2, 2);	//Delay(5);
		NixieTube(3, 3);	//Delay(5);
		NixieTube(4, 4);	//Delay(5);
		NixieTube(5, 5);	//Delay(5);
		NixieTube(6, 6);	//Delay(5);
		NixieTube(7, 7);	//Delay(5);
		NixieTube(8, 8);	//Delay(5);
	}
}

#elif defined TWO

#elif defined THREE

#endif

void NixieTube(u8 location, u8 num)
{
	switch(location)
	{
		case 8:	//LED1 -> Y0 -> 000
			c = 0; b = 0; a = 0;	break;
		case 7:	//LED1 -> Y1 -> 001
			c = 0; b = 0; a = 1;	break;
		case 6:	//LED1 -> Y2 -> 010
			c = 0; b = 1; a = 0;	break;
		case 5:	//LED1 -> Y3 -> 011
			c = 0; b = 1; a = 1;	break;
		case 4:	//LED1 -> Y4 -> 100
			c = 1; b = 0; a = 0;	break;
		case 3:	//LED1 -> Y5 -> 101
			c = 1; b = 0; a = 1;	break;
		case 2:	//LED1 -> Y6 -> 110
			c = 1; b = 1; a = 0;	break;
		case 1:	//LED1 -> Y7 -> 111
			c = 1; b = 1; a = 1;	break;
	}
	P0 = smg[num];	//Note: it's P0, not P2 !
	Delay(1);
	P0 = 0x00;	//Note: 消影
}

void Delay(u8 xms)
{
	u8 i, j;
	while(xms--)
	{
		i = 2;
		j = 199;
		do	{	while(--j);	}
		while(--i);
	}
}