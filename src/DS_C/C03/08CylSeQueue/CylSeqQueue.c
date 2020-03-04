// 03栈和队列 08CylSeQueue

//文件名：CylSeQueue.c

#ifndef CYLSEQQUEUE_C
#define CYLSEQQUEUE_C

#include"CylSeqQueue.h"

Status InitQueue_CSq(CSqQueue *Q)
{
    (*Q).base = (QElemType_CSq*)malloc(MAXQSIZE*sizeof(QElemType_CSq));
    if(!(*Q).base)
    exit(OVERFLOW);

    (*Q).front = (*Q).rear
 = 0;

 return OK;
}

void ClearQueue_CSq(CSqQueue *Q)
{
    (*Q).front = (*Q).rear = 0;
}

void DestroyQueue_CSq(CSqQueue *Q)
{
    if((*Q).base)                   //base是一个指向节点的指针，需要将*base换为0，base=NULL
        free((*Q).base);            //front和rear是两个整形，直接置0即可

    (*Q).base = NULL;
    (*Q).front = (*Q).rear = 0;
}

Status QueueEmpty_CSq(CSqQueue Q)
{
    if(Q.front==Q.rear)
        return TRUE;

    else
        return FALSE;

}

int QueueLength_CSq(CSqQueue Q)
{
    return (Q.rear - Q.front +MAXQSIZE)%MAXQSIZE;  //加上MAXQSIZE 再对这个数求余，是一种实现循环的手段。
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
    if(((*Q).rear+1)%MAXQSIZE == (*Q).front)          //1001%1000 = 1，队列真正的满了
        return ERROR;

        (*Q).base[(*Q).rear] = e;                                    //rear队列尾在上边，先把e的值赋值给数组base[Q.rear],然后将rear指针++，也就是上移即可
        (*Q).rear = ((*Q).rear+1)%MAXQSIZE;

        return OK;
}

Status DeQueue_CSq(CSqQueue *Q,QElemType_CSq *e)
{
    if((*Q).front == (*Q).rear)
        return ERROR;

    *e = (*Q).base[(*Q).front];                 //e被赋值为待删除元素
    (*Q).front = ((*Q).front+1)%MAXQSIZE;           //front指针++,为了防止溢出，%maxqsize

    return OK;
}

void QueueTraverse_CSq(CSqQueue Q,void(Visit)(QElemType_CSq))
{
    int i = Q.front;

    while(i!=Q.rear)
    {
        Visit(Q.base[i]);
        i = (i+1)%MAXQSIZE;                 //当i不等于Q的尾指针的时候，循环步进，反复利用求余符号实现逻辑上的循环

    }


}

#endif // CYLSEQQUEUE_C











