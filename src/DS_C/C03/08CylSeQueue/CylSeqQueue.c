// 03ջ�Ͷ��� 08CylSeQueue

//�ļ�����CylSeQueue.c

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
    if((*Q).base)                   //base��һ��ָ��ڵ��ָ�룬��Ҫ��*base��Ϊ0��base=NULL
        free((*Q).base);            //front��rear���������Σ�ֱ����0����

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
    return (Q.rear - Q.front +MAXQSIZE)%MAXQSIZE;  //����MAXQSIZE �ٶ���������࣬��һ��ʵ��ѭ�����ֶΡ�
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
    if(((*Q).rear+1)%MAXQSIZE == (*Q).front)          //1001%1000 = 1����������������
        return ERROR;

        (*Q).base[(*Q).rear] = e;                                    //rear����β���ϱߣ��Ȱ�e��ֵ��ֵ������base[Q.rear],Ȼ��rearָ��++��Ҳ�������Ƽ���
        (*Q).rear = ((*Q).rear+1)%MAXQSIZE;

        return OK;
}

Status DeQueue_CSq(CSqQueue *Q,QElemType_CSq *e)
{
    if((*Q).front == (*Q).rear)
        return ERROR;

    *e = (*Q).base[(*Q).front];                 //e����ֵΪ��ɾ��Ԫ��
    (*Q).front = ((*Q).front+1)%MAXQSIZE;           //frontָ��++,Ϊ�˷�ֹ�����%maxqsize

    return OK;
}

void QueueTraverse_CSq(CSqQueue Q,void(Visit)(QElemType_CSq))
{
    int i = Q.front;

    while(i!=Q.rear)
    {
        Visit(Q.base[i]);
        i = (i+1)%MAXQSIZE;                 //��i������Q��βָ���ʱ��ѭ�����������������������ʵ���߼��ϵ�ѭ��

    }


}

#endif // CYLSEQQUEUE_C











