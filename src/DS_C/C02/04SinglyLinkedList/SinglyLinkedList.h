/********************************

文件夹：C02/04SinglyLinkedList

文件名：SinglyLinkedList.h

内容:单链表相关操作列表

********************************/

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKDELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "E:/E/DS/C02/01SequenceList/Status.h"
#include "E:/E/DS/C02/01SequenceList/Scanf.c"

/*单链表类型定义*/

#ifndef BANKQUEUING_H       //后边的模拟银行排队算法中，此类型需要重新定义
typedef int LElemType_L;

/*单链表结构体定义*/
typedef struct LNode
{
    LElemType_L data;          //根据上边的typedef 就是定义了一个int data，代表是数据项
    struct LNode *next;        //嵌套定义了一个指向LNode（自身）形的指针，起名next
}LNode;
typedef LNode *LinkList;       //定义了LNode（指向节点形的指针）别名为 LinkList
#endif // BANKQUEUING_H


/*单链表（带头结点的）函数列表*/
Status InitList_L(LinkList *L);        //（1）初始化单链表，LinkList根据之前定义，为指向节点LNode的指针，而LinkList *L则为指向指针的指针

Status ClearList_L(LinkList L);        //（2）置空单链表，头结点保留，参数是LinkList形的指针

void DestroyList_L(LinkList *L);       //（3）销毁单链表L，连同节点一起销毁

Status ListEmpty_L(LinkList L);        //(4)检查单链表L是否为空

int ListLength_L(LinkList L);           //(5)返回单链表L的元素个数

Status GetElem_L(LinkList L,int i,LElemType_L *e);  //(6)算法2.8，获取元素。用e接受单链表L上的第i个元素

int LocateElem_L(LinkList L,LElemType_L e,Status(Compare)(LElemType_L,LElemType_L)); //(7)返回单链表L中第一个与e满足Compare关系的元素位序

Status PriorElem_L(LinkList L,LElemType_L cur_e,LElemType_L *pre_e);                //(8)前驱函数。用pre_e去接收cur_e的前驱

Status_NextElem_L(LinkList L,LElemType_L);                                           //(9)后继函数，用next_e接收cur_e的后继

Status ListInsert_L(LinkList L,int i,LElemType_L e);                                //（10）算法2.9，在单链表L第i个位置前插入e

Status ListDelete_L(LinkList L,int i,LElemType_L *e);                               //(11)算法2.10：删除线性表L 第i个位置的值，并用e接收

Status ListTraverse_L(LinkList L,void(Visit)(LElemType_L));                         //（12）用visit 函数遍历访问单链表L

Status CreateList_HL(FILE *fp,LinkList *L,int n);                                   //(13)算法2.11：头插法建立单链表L（逆序输入）

Status CreateList_TL(FILE *fp,LinkList *L,int n);                                   //(14)尾插法建立单链表L（顺序输入）

#endif // SINGLYLINKEDLIST_H
















