#include <REG52.H>
#include "delay.h"
#include "nixie.h"

#define ONE
//#define TWO
//#define THREE

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
