/**************************************
 *                                    *
 * 文件夹: ▲03 栈和队列\07 LinkQueue *
 *                                    *
 * 文件名: LinkQueue.h                *
 *                                    *
 * 内  容: 链队相关操作列表           *
 *                                    *
 *************************************/

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

#if !defined BANKQUEUING_H && !defined TRI_BINARYTREE_H

typedef int QElemType_L;
#endif


typedef struct QNode
{
    QElemType_L data;
    struct QNode *next;
}QNode;
typedef QNode* QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status InitQueue_L(LinkQueue *Q);

void ClearQueue_L(LinkQueue *Q);

void DestroyQueue_L(LinkQueue *Q);

Status QueueEmpy_L(LinkQueue Q);

int QueueLength_L(LinkQueue Q);

Status GetHead_L(LinkQueue Q,QElemType_L *e);

Status EnQueue_L(LinkQueue *Q,QElemType_L e);

Status DeQueue_L(LinkQueue *Q,QElemType_L *e);

void QueueTraverse_L(LinkQueue Q,void(Visit)(QElemType_L));

#endif // LINKQUEUE_H

