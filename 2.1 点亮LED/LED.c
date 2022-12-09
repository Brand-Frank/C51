#include <REG52.H>

void delay(int ms);

int main(void)
{
	int cnt = 0;
	P2 = 0xfe;	//1111 1110
	while(1)
	{
		delay(100);
		P2 <<= 1;
		if(cnt==8)
		{
			P2 = 0xff;
			cnt = 0;
		}
		cnt++;
	}
	while(1){}
	return 0;
}

/*	ÑÓÊ±º¯Êýdelay()	*/
void delay(int ms)
{
	int i, j;
	for(i = 1; i <= 100; i++)
	{
		for(j = 1; j <= ms; j++);
	}
}