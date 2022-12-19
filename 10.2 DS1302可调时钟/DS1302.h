#ifndef __DS1302_H__
#define __DS1302_H__

extern char DS1302_Time[];

void DS1302_Init(void);
void DS1302_WriteByte(unsigned char Command, unsigned char Data);
unsigned char DS1302_ReadByte(unsigned char Command);

void DS1302_SetTime(void);
void DS1302_ReadTime(void);

#endif // __DS1302_H__