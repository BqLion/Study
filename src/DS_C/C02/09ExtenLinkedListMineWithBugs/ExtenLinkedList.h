/*****************************

文件夹：C02/09ExtenLinkedList.h

文件名：ExtenLinkedList.h

内容：扩展的单链表相关操作列表

备注：此程序是链表的加强版，各项操作、数据结构等重新定义，本质无变化

*******************************/
#ifndef EXTENLINKEDLIST_H
#define EXTENLINKEDLIST_H

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"

//扩展的单链表类型定义
#ifndef POLYNOMIAL_H                //在后边的多项式操作中，此类型需要重新定义
typedef int LElemType_E;
#endif // POLYNOMIAL_H

typedef struct ELNode       //定义节点类型
{
    LElemType_E data;
    struct ELNode *next;
}ELNode;

typedef ELNode *Link;
typedef ELNode *PositionPtr;
typedef struct
{
        Link head,tail;
        int len;
}ELinkList;             //定义线性链表的结构体，包含指向头结点和尾节点的指针，以及线性链表的长度

//扩展的单链表函数列表

Status MakeNode_E(Link *p,LElemType_E e);
//（1）分配由p指向e的结点

void FreeNode_E(Link *p);
//(2) 释放p指向的结点

Status InitList_E(ELinkList *L);
//（3）（初始化一个空的线性链表）

void ClearList_E(ELinkList *L);
//(4)重置线性链表L为空

void DestroyList_E(ELinkList *L);
//(5)销毁线性链表

void InsFirst_E(ELinkList *L,Link h,Link s);
//(6)h指向L其中的结点，将s指向的元素插入之后

Status DelFirst_E(ELinkList *L,Link h,Link *q);
//(7)h指向L中的一个节点，删去其，用q接受

void Append_E(ELinkList *L,Link s);
//(8)将s所指的一串节点连接在L的最后一个节点之后，并改变L的尾指针

Status Remove_E(ELinkList *L,Link *q);
//(09)删除L 的尾节点并用q接收，改变尾指针。

void InsBefore_E(ELinkList *L,Link *p,Link s);
//(10)将s所指节点插入p所指节点之前，并将p指向新插入的结点

void InsAfter_E(ELinkList *L,Link *p,Link s);
//（11）将s所直接点插入p所指节点之后，并将p指向新插入的结点

void SetCurElem_E(Link p,LElemType_E e);
//(12)用e更新p指向的结点中的值

LElemType_E GetCurElem_E(Link p);
//（13）返回p结点中的值

Status ListEmpty_E (ELinkList L);
//(14)判空

int ListLength_E(ELinkList L);
//（15）求长

PositionPtr GetHead_E(ELinkList L);
//(16)以指针形式返回L头结点的位置

PositionPtr GetLast_E(ELinkList L);
//(17)以指针形式返回L尾节点的位置

PositionPtr PriorPos_E(ELinkList L,Link p);
//(18)返回p指向的结点的前驱

PositionPtr NextPos_E(Link p);
//（19）返回p指向的结点的后继

Status LocatePos_E(ELinkList L,int i,Link p);
//(20)将*p指向L中第i个节点，i=0时为头结点

PositionPtr LocateElem_E(ELinkList L,LElemType_E e,Status(Compare)(LElemType_E,LElemType_E));
//（21）返回L中第一个与e满足compare关系的元素指针


Status ListTraverse_E(ELinkList L,void(Visit)(LElemType_E));
//(22)访问

Status ListInsert_L_E(ELinkList *L,int i,LElemType_E e);
//(23)算法2.20 在L第i个位置之前插入e

Status ListDelete_L_E(ELinkList *L,int i,LElemType_E *e);
//(24)删除L中第i个位置的值，并用e接受

#endif // EXTENLINKEDLIST_H





























