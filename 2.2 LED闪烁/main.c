/**
 * @file main.c
 * @author codebug (zhang_classmate@qq.com)
 * @brief LED闪烁
 * @version 0.1
 * @date 2022-12-01 22:12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <REG52.H>
#include <INTRINS.H>

void Delay500ms(); //@11.0592MHz

int main(void)
{
    while (1)
    {
        P2 = 0xfe; // 1111-1110
        Delay500ms();
        P2 = 0xff; // 1111-1111
        Delay500ms();
    }
    // return 0;
}

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

void delay(int ms)
{
    int i, j;
    for (i = 0; i <= 100; i++)
        for (j = 0; j <= ms; j++)
            ;
}