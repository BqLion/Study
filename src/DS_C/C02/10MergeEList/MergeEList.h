/*******************************

文件夹：C02/10 MergeEList.h

文件名：MergeEList.h

内容：归并扩展的单链表相关操作列表

********************************/

#ifndef MERGELIST_H
#define MERGELIST_H

#include<stdio.h>
#include"E:/E/DS/C02/09ExtenLinkedList/ExtenLinkedList.c"

//归并扩展的单链表函数列表

Status MergeEList_L(ELinkList La,ELinkList Lb,ELinkList *Lc,int(Compare)(LElemType_E c1,LElemType_E c2));
//（01）算法2.21 La与Lb均为非递减排列，将其归并为一个非递减排序的单链表LC

int Cmp(LElemType_E c1,LElemType_E c2);     //（02）比较c1 c2大小，返回c1-c2

Status CreateList_ascend(FILE *fp,ELinkList *L,int count);   //(03)按非降序序列创建元素个数为count的扩展单链表L

#endif // MERGELIST_H












