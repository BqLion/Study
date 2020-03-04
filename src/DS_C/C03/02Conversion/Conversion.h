//进值转换的算法，举例：十进制数字123，转换成8进制的数字，算法是123/8 =15……3,然后15/8 = 1…… 7,然后1/8 = 0……1，出的结果是倒序的，所以用栈的数据结构比较顺从思路。
/*******************************

文件夹:C03/Conversion

内容：进制转换相关操作

思路：循环将待转换数据除以转换的进制数并求余，然后将余数倒序，就是所得。

********************************/

#ifndef CONVERSION_H
#define CONVERSION_H

#include<stdio.h>
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"

//进制转换函数列表

void conversion(int i);

#endif
//没有额外的数据结构，头文件宏定义和其他函数需要声明
