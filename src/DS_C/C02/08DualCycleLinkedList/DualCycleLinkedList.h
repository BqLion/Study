/****************************************

文件夹：C02/08DualCycleLinkedList

文件名：DualCycleLinkedList.h

内容：双向循环链表相关操作列表

****************************************/

#ifndef DUALCYCLELINKEDLIST_H
#define DUALCYCLELINKEDLIST_H

#include <stdio.h>
#include "E:/E/DS/C02/01SequenceList/Status.h"
#include "E:/E/DS/C02/01SequenceList/SequenceList.c"

/**************************

一般头文件会

1.包含进需要的头文件

2.定义使用的数据结构

3.声明使用的函数

*************************/

//双循环链表类型定义

typedef int LElemType_DC;               //双循环链表的数据类型叫这个
typedef struct DuLNode
{
    LElemType_DC data;                     //数据项
    struct DuLNode *prior;                 //前指针
    struct DuLNode *next;                   //后指针
}DuLNode;                                       //OK这个struct叫做DuLNode,即是双循环链表的结点
typedef DuLNode *DuLinkList;        //简洁起见，把指向节点元素的指针起个别名叫  DuLinkList

//双循环链表函数列表
Status InitList_Dul(DuLinkList *L);
//（01）初始化双链表L

Status ClearList_Dul(DuLinkList L);
//(02)  置空L

void DestroyList_Dul(DuLinkList *L);
//(03)销毁L

Status ListEmpty_Dul(DuLinkList L);
//(04)探空L

int ListLength_Dul(DuLinkList L);
//（05）返回L元素个数

Status GetElem_Dul(DuLinkList L,int i,LElemType_DC *e);
//(06)用e接受L中第i个元素

int LocateElem_Dul(DuLinkList L,LElemType_DC E,Status(Compare)(LElemType_DC,LElemType_DC));
//(07)返回L中第一个与e满足COMpare关系的元素的位序

Status PriorElem_Dul(DuLinkList L,LElemType_DC cur_e,LElemType_DC *pre_e);
//(08)用pre_e接受cur_e的前驱

Status NextElem_Dul(DuLinkList L,LElemType_DC cur_e,LElemType_DC *next_e);
//(09)用next_e接受cur_e的后继

DuLinkList GetElemPtr_Dul(DuLinkList L,int i);
//(10)返回L中指向第i个节点的指针

Status ListInsert_Dul(DuLinkList L,int i,LElemType_DC e);
//(11)算法2.18：在L第i个位置之前插入e

Status ListDelete_Dul(DuLinkList L,int i,LElemType_DC *e);
//(12)算法2.19：删除L第i个位置的值，并用e接受

void ListTraverse_Dul(DuLinkList L,void(Visit)(LElemType_DC));
//(13)用Visit函数访问L

#endif // DUALCYCLELINKEDLIST_H











