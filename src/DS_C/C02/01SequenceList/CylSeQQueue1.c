#ifndef CYCLEQQUEUE_H
#define CYCLEQQUEUE_H

#include<stdio.h>
#include<stdlib.h>

#define MAXQSIZE 1000

typedef int QElemType_CSq;

typedef struct
{
QElemType_CSq *base;
int front;
int rear;
}CSqQueue;

Status InitQueue_CSq(CSqQueue *Q)
{
    (*Q).base = (QElemType_CSq *)malloc(MAXQSIZE*sizeof(QElemType_CSq));
    if(!(*Q).base)
    exit(OVERFLOW);

    (*Q).front = (*Q).rear = 0;

    return OK;

}



void ClearQueue_CSq(CSqQueue *Q)
{
(*Q).front = (*Q).rear = 0;
}

void DestroyQueue_CSq(CSqUueue *Q)
{
    if((*Q).base)
    free((*Q).base);

    (*Q).base = NULL;
    (*Q).front = (*Q).rear = 0;

}


Status QueueEmpty_CSq(CSqQueue Q)
{
    if((*Q).base)
    free((*Q).base);

    (*Q).base = NULL;
    (*Q).front = (*Q).rear = 0;
}

Status GetHead_CSq(CSqQueue Q,QElemType_CSq *e)
{
    if(Q.front ==Q.rear)
    return ERROR;

    *e = Q.base[Q.front];

    return OK;
}

Status EnQueue_CSq(CSqQueue *Q,QElemType_CSq e)
{
    if(((*Q).rear+1)%MAXQSIZE==(*Q).front);
        return ERROR

        (*Q).base[(*Q).rear]= e'
        (*Q).rear = ((*Q).rear+1)%MAXQSIZE;

        return OK;
}


Status DeQueue_CSq(CSqQueue *Q,QElemType_CSq *e)
{
if((*Q).front == (*Q).rear)
return ERROR;
*e = (*Q).base[(*Q).front];
(*Q).front = ((*Q).front+1)%MAXQSIZE;

return OK;
}


void QueueTraverse_CSq(CSqQueue Q,void(Visit)(QElemType_CSq))
{

    int i = Q.front;
    while(i!=Q.rear)
    {
    Visit(Q.base[i]);
    i = (i+1)%MAXQsize;
    }
}



