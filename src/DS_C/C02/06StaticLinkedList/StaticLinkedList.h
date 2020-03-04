/**********************************

文件夹：C02/StaticLinkedList

文件名：StaticLinkedList.h

内容：静态链表相关操作列表

TIPS: 静态链表是一种用数组的下表来替代正常链表的指针功能的链表，之所以用数组的下标来替代指针是因为有些高级语言里边没有指针的功能

静态链表的储存结构顺序表相似，在内存中是连续存储的，但是在插入和删除元素的时候不需要把后边的所有元素都挪动（身为链表的好处）

***********************************/

#ifndef STATICLINEDLIST_H
#define STATICLINKEDLIST_H

#include<stdlib.h>                                  //提供malloc、realloc、free、exit原型
#include"E:/E/DS/C02/01SequenceList/Status.h"

//宏定义

#define MAXSIZE 1000                            //静态链表的最大长度

//静态链表类型定义

typedef int SLinkList;
typedef int LElemType_S;
typedef struct
{
    LElemType_S data;
    int cur;                                    //cur是游标，做指针用，区别于数组下标
}Component[MAXSIZE];             //链表空间类型：一个叫Component的数组，空间是1000个

//全局变量
Component SPACE;                       //Component类比 与int，就是一个 1000个格子的数组，数组元素的结构是上边def的 struct。



//静态链表的函数列表
void InitSpace_SL();        //（01）算法2.14：初始化存储空间，将一维数组SPACE中各分量链成 一个大的备用空间。

int Malloc_SL();                //(02)算法2.15 为插入数据申请动态空间，【模仿malloc的函数】

void Free_SL(int k);      //(03)算法2.16  :将下标为k的空闲节点的内存回收【模仿free函数】

int InitList_SL(SLinkList *H);  //（04）(初始化静态链表，建立头结点)

Status ClearList_SL(SLinkList H);   //（05）置空链表

void DestroyLsit_SL(SLinkList *H);//(06)销毁链表

Status ListEmpty_SL(SLinkList H);   //(07)判空

int ListLength_SL(SLinkList H);            //（08）求长

Status GetElem_SL(SLinkList H,int i,LElemType_S *e);    //（09）取值

int  LocateElem_SL(SLinkList H,LElemType_S e);      //（10）算法2.13 返回元素e的位序

Status PriorElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *pre_e);  //(11)求 cur_e的前驱元素pre_e

Status NextElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *next_e);        //(12) 求cur_e的后继元素next_e

Status ListInsert_SL(SLinkList H,int i,LElemType_S e);  //(13) 插入

Status ListDelete_SL(SLinkList H,int i,LElemType_S *e); //(14)删除

Status ListTraverse_SL(SLinkList H,void(Visit)(LElemType_S));       //(15)顺序遍历访问

#endif // STATICLINEDLIST_H









