#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//类型定义

typedef int QElemType;
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode;

typedef QNode* QueuePtr;
typedef struct
{
QueuePtr rear;
}LinkQueue;


Status InitQueue_3_28(LinkQueue *Q);                //初始化的是“队列”
Status EnQueue_3_28(LinkQueue *Q,QElemType e);
Status DeQueue_3_28(LinkQueue *Q,QElemType *e);         //增删的是“队列”+“元素”
void Output_3_28(LinkQueue Q);                          //输出的是“队列”

int main(int argc,char*argv[])
{
    LinkQueue Q;
    int i;
    QElemType e;

    printf("初始化队列...\n");
    InitQueue_3_28(&Q);
    printf("\n");

    printf("进行五次连续入队操作...\n");
    for(i=1;i<=5;i++)
    {
        EnQueue_3_28(&Q,i);
        printf("元素 \"%d\"  入队后，队列的元素为:",i);
        Output_3_28(Q);
        printf("\n");
    }
    printf("\n");

    printf("进行五次连续出队操作...\n");
    for(i=1;i<=5;i++)
    {
        DeQueue_3_28(&Q,&e);
        printf("元素\"%d\" 出队后，队列中的元素为：",e);
        Output_3_28(Q);
        printf("\n");
    }
    printf("\n");

    return 0;
}

//队列初始化

Status InitQueue_3_28(LinkQueue *Q)
{
    (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
    if(!(*Q).rear)
    exit(OVERFLOW);

    (*Q).rear->next = (*Q).rear;

    return OK;
}

//入队

Status EnQueue_3_28(LinkQueue *Q,QElemType e)       //入队
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)
    exit(OVERFLOW);
    p->data = e;

    p->next = (*Q).rear->next;          //标准的把p插入到q后边的操作：p指针指q后，q指p；尾指针移动到p
    (*Q).rear->next = p;
    (*Q).rear = p;

    return OK;
}

Status DeQueue_3_28(LinkQueue *Q,QElemType *e)
{
    QueuePtr h,p;
    h = (*Q).rear->next;                //h指向尾节点的next，也就是头结点，p指向头结点的next。需要出队的就是头结点的next。队列，从尾部加，从头部删
    if(h->next==(*Q).rear->next)
    return ERROR;

    p = h->next;
    *e = p->data;

    h->next = p->next;

    if(p==(*Q).rear)
    (*Q).rear = h;

    free(p);

    return OK;
}

void Output_3_28(LinkQueue Q)
{
    QueuePtr p;

    for(p=Q.rear->next->next;p!=Q.rear->next;p=p->next)
    printf("%d",p->data);
}


