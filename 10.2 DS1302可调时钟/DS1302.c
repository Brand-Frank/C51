#include <REGX52.H>

sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;

#define DS1302_SECOND	0x80	// 秒
#define DS1302_MINUTE	0x82	// 分钟
#define DS1302_HOUR		0x84	// 时
#define DS1302_DATE		0x86	// 日
#define DS1302_MONTH	0x88	// 月
#define DS1302_DAY		0x8A	// 星期
#define DS1302_YEAR		0x8C	// 年
#define DS1302_WP		0x8E	// 写保护

char DS1302_Time[] = {22, 12, 18, 12, 59, 55, 7};

void DS1302_Init(void)
{
	DS1302_CE = 0;
	DS1302_SCLK = 0;
}

/**
 * @brief 
 * @param 
 * @retval 
 * @note 根据时序图来写程序，先写指令说明需要操作什么，后写数据
 */
void DS1302_WriteByte(unsigned char Command, unsigned char Data)
{
	unsigned char i;
	DS1302_CE = 1;
	
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Command & (0x01 << i);
		DS1302_SCLK = 1;
		//Delay(1);		//51的速度慢，所以不需要延时
		DS1302_SCLK = 0;
	}
	
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Data & (0x01 << i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	
	DS1302_CE = 0;
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i, Data = 0x00;
	Command |= 0x01;	//初始设置为读命令
	DS1302_CE = 1;
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Command & (0x01 << i);
		DS1302_SCLK = 0;
		DS1302_SCLK = 1;
	}
	
	for(i = 0; i < 8; i++)
	{
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
		if(DS1302_IO)	{ Data |= (0x01 << i); }
	}
	
	DS1302_CE = 0;
	DS1302_IO = 0;
	return Data;
}

void DS1302_SetTime(void)
{
	DS1302_WriteByte(DS1302_WP, 0x00);	//关闭写保护
	DS1302_WriteByte(DS1302_YEAR, DS1302_Time[0]/10*16+DS1302_Time[0]%10);	//十进制需要转化为BCD码存进去
	DS1302_WriteByte(DS1302_MONTH, DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_WriteByte(DS1302_DATE, DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_WriteByte(DS1302_HOUR, DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_WriteByte(DS1302_MINUTE, DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS1302_WriteByte(DS1302_SECOND, DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS1302_WriteByte(DS1302_DAY, DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	DS1302_WriteByte(DS1302_WP, 0x80);	//打开写保护
}

void DS1302_ReadTime(void)
{
	unsigned char temp;
	
	temp = DS1302_ReadByte(DS1302_YEAR);	//读取的是BCD码，需要转换成十进制
	DS1302_Time[0] = temp/16*10 + temp%16;
	
	temp = DS1302_ReadByte(DS1302_MONTH);
	DS1302_Time[1] = temp/16*10 + temp%16;
	
	temp = DS1302_ReadByte(DS1302_DATE);
	DS1302_Time[2] = temp/16*10 + temp%16;
	
	temp = DS1302_ReadByte(DS1302_HOUR);
	DS1302_Time[3] = temp/16*10 + temp%16;
	
	temp = DS1302_ReadByte(DS1302_MINUTE);
	DS1302_Time[4] = temp/16*10 + temp%16;
	
	temp = DS1302_ReadByte(DS1302_SECOND);
	DS1302_Time[5] = temp/16*10 + temp%16;
	
	temp = DS1302_ReadByte(DS1302_DAY);
	DS1302_Time[6] = temp/16*10 + temp%16;
}