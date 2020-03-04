/**************************************

  文件夹:charpter01

  文件名：SequenceList.h

  内容：顺序表相关操作列表

**************************************/

#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "E:/E/DS/C02/01SequenceList/Status.h"

//宏定义
#define LIST_INIT_SIZE	100
#define LISTINCREMENT	10

//顺序表类型定义
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemType_Sq;
#endif

typedef struct
{
	LElemType_Sq *elem;				//储存空间基址（指向第一个节点的指针）
	int length;						//当前顺序表长度
	int listsize;					//当前分配的储存容量
}SqList;							//顺序表0号单元正常使用（暂时不明白什么意思）

//顺序表的函数列表（基本操作）
extern Status InitList_Sq(SqList *L);		//(01)算法2.3初始化空顺序表L

extern void ClearList_Sq(SqList *L);		//(02)清空顺序表L

extern void DestroyList_Sq(SqList *L);		//(03)销毁顺序表L

extern Status ListEmpty_Sq(SqList L);		//(04)判断顺序表L是否为空

extern int ListLength_Sq(SqList L);		//(05)返回顺序表中元素个数

extern Status GetElem_Sq(SqList L,int i,LElemType_Sq *e);//(06)用元素e获取顺序表L中第i个元素并返回

extern int LocateElem_Sq(SqList L,LElemType_Sq e,Status(Compare)(LElemType_Sq,LElemType_Sq));//(07)算法2.6：返回顺序表L中首个与e满足Compare关系的元素的位序

extern Status PriorElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *pre_e);//(08)用pre_e接受cur_e的前驱（不明白为什么用*pre_e而不是pre_e）

extern Status NextElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *next_e);//(09)用next_e接受cur_e的后继（不明白同上，见到函数后辨析这个指针的问题）

extern Status ListInsert_Sq(SqList *L,int i,LElemType_Sq e);//(10)算法2.4：在顺序表的第i个位置插入元素e（参数用的是SqList的指针，可能是为了定位）

extern Status ListDelete_Sq(SqList *L,int i,LElemType_Sq *e);//(11)算法2.5：删除顺序表L上第i个位置的元素，并用e返回。

extern Status ListTraverse_Sq(SqList L,void(Visit)(LElemType_Sq));//(12)用Visit函数访问顺序表L并翻转顺序。

#endif






