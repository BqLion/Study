#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//���Ͷ���

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


Status InitQueue_3_28(LinkQueue *Q);                //��ʼ�����ǡ����С�
Status EnQueue_3_28(LinkQueue *Q,QElemType e);
Status DeQueue_3_28(LinkQueue *Q,QElemType *e);         //��ɾ���ǡ����С�+��Ԫ�ء�
void Output_3_28(LinkQueue Q);                          //������ǡ����С�

int main(int argc,char*argv[])
{
    LinkQueue Q;
    int i;
    QElemType e;

    printf("��ʼ������...\n");
    InitQueue_3_28(&Q);
    printf("\n");

    printf("�������������Ӳ���...\n");
    for(i=1;i<=5;i++)
    {
        EnQueue_3_28(&Q,i);
        printf("Ԫ�� \"%d\"  ��Ӻ󣬶��е�Ԫ��Ϊ:",i);
        Output_3_28(Q);
        printf("\n");
    }
    printf("\n");

    printf("��������������Ӳ���...\n");
    for(i=1;i<=5;i++)
    {
        DeQueue_3_28(&Q,&e);
        printf("Ԫ��\"%d\" ���Ӻ󣬶����е�Ԫ��Ϊ��",e);
        Output_3_28(Q);
        printf("\n");
    }
    printf("\n");

    return 0;
}

//���г�ʼ��

Status InitQueue_3_28(LinkQueue *Q)
{
    (*Q).rear = (QueuePtr)malloc(sizeof(QNode));
    if(!(*Q).rear)
    exit(OVERFLOW);

    (*Q).rear->next = (*Q).rear;

    return OK;
}

//���

Status EnQueue_3_28(LinkQueue *Q,QElemType e)       //���
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)
    exit(OVERFLOW);
    p->data = e;

    p->next = (*Q).rear->next;          //��׼�İ�p���뵽q��ߵĲ�����pָ��ָq��qָp��βָ���ƶ���p
    (*Q).rear->next = p;
    (*Q).rear = p;

    return OK;
}

Status DeQueue_3_28(LinkQueue *Q,QElemType *e)
{
    QueuePtr h,p;
    h = (*Q).rear->next;                //hָ��β�ڵ��next��Ҳ����ͷ��㣬pָ��ͷ����next����Ҫ���ӵľ���ͷ����next�����У���β���ӣ���ͷ��ɾ
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


