/********************************

文件夹：charpter02线性表/03 MergeSqList

文件名：MergeSqList.h

内容：顺序表归并相关操作列表

********************************/

#ifndef MERGESQLIST_H
#define MERGESQLIST_H

#include <stdlib.h>
#include "E:/E/DS/C02/01SequenceList/SequenceList.c"

//顺序表归并函数列表

void MergeSqList_1(SqList La,SqList Lb,SqList *Lc);		//算法2.2：求C=A+B,A,B,C均为非递减序列
void MergeSqList_2(SqList La,SqList Lb,SqList *Lc);		//算法2.7：求C=A+B，A,B,C均为非递减序列

#endif
