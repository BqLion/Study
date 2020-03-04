/******************************

文件夹：C03/02Conversion

文件名：Conversion.c

算法：3.1

******************************/

#ifndef CONVERSION_C
#define CONVERSION_C

#include "Conversion.h"

void conversion(int i)
{
    SqStack S;
    SElemType_Sq e;

    InitStack_Sq(&S);

    printf("十进制数 %d转换为八进制数后为 : ",i);   //不懂为什么源程序在右引号前边加了0

    while(i)                    //翻译为人类语言：当i不等于0的时候，也就是i还没有被除尽的时候，循环的把i对8取的 余数压进栈；然后i除以8，直到i被除尽为止
    {
        Push_Sq(&S,i%8);
        i = i/8;
    }

    while(!StackEmpty_Sq(S))            //然后把压进栈的所有的元素都吐出来，直到吐干净为止
    {
        Pop_Sq(&S,&e);
        printf("%d",e);
    }
}

#endif // CONVERSION_C


