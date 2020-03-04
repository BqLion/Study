/*************************

文件夹 ：05数组和广义表

SequenceArray.h

数组相关操作列表

**************************/

#ifndef SEQUENCEARRAY_H
#define SEQUENCEARRAY_H

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

#define MAX_ARRAY_DIM 8

typedef int AElemType_Sq;
typedef struct
{
    AElemType_Sq *base;         //数组元素基址
    int dim;                               //数组维数
    int *bounds;                       //数组维界基址（存放数组的行列信息）
    int *constants;                 //数组映像函数常量基址（存储跨越某个维度时需要跨过的元素个数）
}Array;

Status InitArray(Array *A,int dim,...);

Status DestroyArray(Array *A);

Status LocateArray(Array A,va_list ap,int *off);//求ap指示的值，在A中的相对位置

Status ValueArray(Array A,AElemType_Sq *e,...);
//取值

Status AssignArray(Array *A,AElemType_Sq e,...);

void ArrayPrint(Array A);

#endif // SEQUENCEARRAY_H






