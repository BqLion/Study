//堆串： 本质还是串，不过内存是用malloc动态分配的，不是普通串用数组储存

/***********************

文件夹：C04/02HeapString

文件名：HeapString.h

内容：堆串相关操作列表

************************/

#ifndef HEAPSTRING_H
#define HEAPSTRING_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

typedef struct
{
    char *ch;
    int length;
}HString;

void InitString_H(HString *S);

Status StrAssign_H(HString *T,char *chars);

Status StrCopy_H(HString *T,HString S);

Status StrEmpty_H(HString S);

Status StrCompare_H(HString S,HString T);

int StrLength_H(HString S);

Status ClearString_H(HString *S);

Status Concat_H(HString *T,HString S1,HString S2);

Status SubString_H(HString *Sub,HString S,int pos,int len);

int Index_H(HString S,HString T,int pos);

Status Replace_H(HString *S,HString T,HString V);

Status StrInsert_H(HString *S,int pos,HString T);

Status StrDelete_H(HString *S,int pos,int len);

void DestroyString_H(HString *S);

void StrPrint_H(HString S);

#endif // HEAPSTRING_H







