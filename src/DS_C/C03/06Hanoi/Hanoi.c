/********************************

文件夹：C03/栈和队列、06汉诺塔

Hanoi.c

算法：3.5

********************************/

#ifndef HANOI_C
#define HANOI_C

#include "Hanoi.h"

//算法：3.5

void hanoi(int n,char x,char y,char z)
{
    if(n==1)
        move(x,1,z);
    else
    {
        hanoi(n-1,x,z,y);           //将x上n-1个圆盘，从x移动到y上，借助z辅助轴
        move(x,n,z);                 //x上第n个圆盘移动到z上
        hanoi(n-1,y,x,z);           //将y上n-1个圆盘从y移动到z轴上，借助x轴
    }
}

void  move(char x,int n,char z)
{
    gStep++;
    printf("第%2d步:将第%d 个圆盘从 %c移动到 %c \n",gStep,n,x,z);
}

#endif // HANOI_C









