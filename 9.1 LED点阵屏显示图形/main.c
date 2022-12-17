#include <REGX52.H>
#include "Matrix_LED.h"

void main(void)
{
	MatrixLED_Init();
	//P0 = 0;
	//_74HC595_WriteByte(0xaa);
	//MatricLED_ShowColumn(3, 0x40);
	while(1)
	{
		MatricLED_ShowColumn(0, 0x3c);
		MatricLED_ShowColumn(1, 0x42);
		MatricLED_ShowColumn(2, 0xa9);
		MatricLED_ShowColumn(3, 0x85);
		MatricLED_ShowColumn(4, 0x85);
		MatricLED_ShowColumn(5, 0xa9);
		MatricLED_ShowColumn(6, 0x42);
		MatricLED_ShowColumn(7, 0x3c);
	}
}