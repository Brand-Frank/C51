#include "delay.h"

void Delay(unsigned char xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 199;
		do	{	while(--j);	}
		while(--i);
	}
}