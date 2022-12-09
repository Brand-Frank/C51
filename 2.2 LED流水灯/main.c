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

// #define ONE
// #define TWO
#define THREE

void Delay500ms(); //@11.0592MHz

#ifdef ONE // 可行
void main(void)
{
    while (1)
    {
        P2 = 0xfe; // 1111-1110
        Delay500ms();
        P2 = 0xfd; // 1111-1101
        Delay500ms();
        P2 = 0xfb; // 1111-1011
        Delay500ms();
        P2 = 0xf7; // 1111-0111
        Delay500ms();
        P2 = 0xef; // 1110-1111
        Delay500ms();
        P2 = 0xdf; // 1101-1111
        Delay500ms();
        P2 = 0xbf; // 1011-1111
        Delay500ms();
        P2 = 0x7f; // 0111-1111
        Delay500ms();
    }
}

#elif defined TWO // TWO流水方式不同
void main(void)
{
    while (1)
    {
        P2 = 0xfe; // 1111-1110
        Delay500ms();
        P2 <<= 1; // 1111-1100
        Delay500ms();
        P2 <<= 1; // 1111-1000
        Delay500ms();
        P2 <<= 1; // 1111-0000
        Delay500ms();
        P2 <<= 1; // 1110-0000
        Delay500ms();
        P2 <<= 1; // 1100-0000
        Delay500ms();
        P2 <<= 1; // 1000-0000
        Delay500ms();
        P2 <<= 1; // 0000-0000
        Delay500ms();
        P2 = 0xff;
        Delay500ms();
    }
}

#elif defined THREE // BUG:流水方式不同，需要改进
void main()
{
    unsigned int cnt = 1;
    P2 = 0xfe; // 1111-1110
    while (1)
    {
        Delay500ms();
        P2 <<= 1;
        cnt++;
        if (cnt % 8 == 0)
            P2 = 0xfe;
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
