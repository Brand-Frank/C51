/**
 * @file main.c
 * @author codebug (zhang_classmate@qq.com)
 * @brief 流水灯
 * @version 0.1
 * @date 2022-12-01 22:12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <REG52.H>
#include <INTRINS.H>

#define ONE
// #define TWO

void Delay500ms(); //@11.0592MHz

#ifdef ONE
void main(void)
{
    while (1)
    {
        P2 = 0xfe;  //1111-1110
        Delay500ms();
        P2 = 0xfd;  //1111-1101
        Delay500ms();
        P2 = 0xfb;  //1111-1011
        Delay500ms();
        P2 = 0xf7;  //1111-0111
        Delay500ms();
        P2 = 0xef;  //1110-1111
        Delay500ms();
        P2 = 0xdf;  //1101-1111
        Delay500ms();
        P2 = 0xbf;  //1011-1111
        Delay500ms();
        P2 = 0x7f;  //0111-1111
        Delay500ms();
    }
}

#else
void main(void)
{
    while (1)
    {
        P2 = 0xfe;  //1111-1110
        Delay500ms();
        P2 <<= 1;   //1111-1101
        Delay500ms();
        P2 <<= 1;  //1111-1011
        Delay500ms();
        P2 <<= 1;  //1111-0111
        Delay500ms();
        P2 <<= 1;  //1110-1111
        Delay500ms();
        P2 <<= 1;  //1101-1111
        Delay500ms();
        P2 <<= 1;  //1011-1111
        Delay500ms();
        P2 <<= 1;  //0111-1111
        Delay500ms();
    }
}
#endif

void Delay500ms() //@11.0592MHz
{
    unsigned char i, j, k;

    _nop_();
    i = 4;
    j = 129;
    k = 119;
    do
    {
        do
        {
            while (--k)
                ;
        } while (--j);
    } while (--i);
}
