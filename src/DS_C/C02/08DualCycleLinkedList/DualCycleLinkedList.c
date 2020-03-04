/************************************

�ļ��У�C02/08DualCycleLinkedList

�ļ�����DualCycleLinkedList.c

�㷨��2.18/2.19

*************************************/

#ifndef DUALCYCLELINKEDLIST_C
#define DUALCYCLELINKEDLIST_C

#include "DualCycleLinkedList.h"

Status InitList_Dul(DuLinkList *L)          //��ʼ���ĺ�����������һ��ָ��ͷָ���ָ��
{
    *L = (DuLinkList)malloc(sizeof(DuLNode));  //ָ��ָ��̬����Ľ��ռ���ײ�
    if(!(*L))
        exit(OVERFLOW);

    (*L)->next = (*L)->prior = *L;                  //�׸��ڵ㻹û���������������ֻ���ú����׶˵�ָ�룬ǰ��ָ�붼ָ����������ڴ�ڵ�����

    return OK;
}

Status ClearList_Dul(DuLinkList L)
{
    DuLinkList p,q;//ָ������Ľ���ε�ָ��p,q

    p = L->next;    //pָ��L���׸�Ԫ��

    while(p!=L)        //��p������L��ʱ��ѭ�������²���������һȦ��pָ���ص�����֮ǰָ��L
    {
        q= p->next;    //ָ��qָ�����p֮���Ԫ��
        free(p);            //��p�ͷŵ�
        p = q;              //p����1                                     ����ȥ����q�ٲ���1�����ѭ��
    }

    //��������ʱ��ǰ��ָ���Lָ�붼��Ϊһ��
    L->next = L->prior = L;

    return OK;
}

void DestroyList_Dul(DuLinkList *L)
{
    ClearList_Dul(*L);

    free(*L);           //���ϱߵ���պ����Ļ����ϰ�ͷ���LҲ�������

    *L = NULL;     //��ֹҰָ�룬��L��ΪNULL
}


Status  ListEmpty_Dul(DuLinkList L)
{
    if(L && L->next==L && L->prior == L)        //���L������0��ǰ��ָ�붼����L��ʱ�����˱���ͷ��㣬������Ԫ�أ����ڣ���Ϊ��
            return TRUE;
    else
            return FALSE;
}

int ListLength_Dul(DuLinkList L)
{
    DuLinkList p;
    int count;

    if(L)
    {
        count = 0;
        p = L;

        while(p->next!=L)
        {
            count++;
            p=p->next;
        }
    }

    return count;
    }

Status GetElem_Dul(DuLinkList L,int i,LElemType_DC *e)
{
    DuLinkList p;
    int count;

    if(L)
    {
        count = 1;
        p = L->next;

        while(p!=L && count<i)         //p��û��һȦ��������Ҳ��û��theԪ�ص�ʱ�򣬼�������������1��ָ��p��������1
        {
            count++;
            p = p->next;
        }

    if(p!=L)                                                //����ѭ��������֮���ж�һ�����ƻ��������Ļ���ָ��ָ����ָ��Ԫ��ͣ������
    {
        *e = p->data;                                       //���pָ��û��ָ��L ,���ǾͰ�p��ָ��data��ֵ��e�Ϳ��Է�����ȷ�ˣ��������û���ҵ�����Ҫ����ERROR
        return OK;
    }
    }
    return ERROR;
}

int LocateElem_Dul(DuLinkList L,LElemType_DC e,Status(Compare)(LElemType_DC,LElemType_DC))
{
    DuLinkList p;
    int count;

    if(L)
    {
            count = 1;
            p = L->next;

            while(p!=L && !Compare(e,p->data))         //���ҵı�׼��������ָ��δ���������δ����ʱ�������ظ����²���
            {
            count ++;                                                       //������������ָ�벽��

            p = p->next;
            }

            if(p!=L)
                return count;
    }
    return 0;
}

Status PriorElem_Dul(DuLinkList L,LElemType_DC cur_e,LElemType_DC *pre_e)
{
    DuLinkList p;

    if(L)
    {
        p = L->next;
        while(p!=L&&p->data!=cur_e)
            p  = p->next;                               //p ָ��ָ��ͷ��㣬��pָ��δ�ܻ�����p��ָ��data����������������£�p��������

        if(p!=L && p->prior!=L)             //p��Ϊ�׽ڵ㣨���󣩡�p��ǰ���㲻Ϊ�׽ڵ㣨�����Ͳ�����ǰ��ڵ��ˣ�
        {
            *pre_e = p->prior->data;        //��pָ���ǰ�����data��ֵ��pre_e�����¶���
            return OK;
        }
    }
    return ERROR;
}

Status NextElem_Dul(DuLinkList L,LElemType_DC cur_e,LElemType_DC *next_e)
{
    DuLinkList p;
    if(L)
    {
        p   =L->next;

        while(p!=L && p->data!=cur_e)
            p = p->next;

        if(p!=L && p->next!=L)
        {
            *next_e = p->next->data;
            return OK;
        }
    }
    return ERROR;
}

DuLinkList GetElemPtr_Dul(DuLinkList L,int i)
{
    int count;
    DuLinkList p;

    if(L && i>0)
    {
    count = 1;
    p = L->next;

    while(p!=L && count<i)
    {
    count++;
    p = p->next;
    }

    if(p!=L)
        return p;
    }
    return NULL;
}

//�㷨2.18

//��α�˫���������㷨���в�ͬ����Դ�Ǳ�GetElemP_Dul��ͬ
Status ListInsert_Dul(DuLinkList L,int i ,LElemType_DC e)
{
    DuLinkList p,s;

    if(i<1 || i>ListLength_Dul(L)+1)        //�ȶ�i��������
            return ERROR;

    p = GetElemPtr_Dul(L,i);//��ȡ����ָ��L��i��Ԫ�ص�ָ��
    if(!p)
        p = L;              //��p=NULL����ôi�Ѿ������������Ľ��ޣ���ʱ��Ҫ��Ұָ��pָ���ͷ

    s = (DuLinkList)malloc(sizeof(DuLNode));
    if(!s)
            exit(OVERFLOW);                 //��������ָ�룬pָ�������Ľ�㣬sָ���·�����ڴ�ռ�ͷ��

    s->data = e;            //��������������ȸ��Ƹ�s��ָ��data

    s->prior = p->prior;            //s��ָ��Ԫ�أ�1.sǰ��ָ��ָ��p��ǰ�� 2.s�ĺ��ָ��ָ��p 3.p��ǰ���ĺ��ָ��ָ��s 4.p��ǰ��ָ��ָ��s
    s->next = p;
    p->prior->next = s;
    p->prior = s;

    return OK;
}



//�Լ����ԣ�����ڵ�q���ڵ�p�󷽵��㷨
//ʵ�ʲ��Խ����������Ľ���ָ�룬���÷���-����-����-���գ��ͷ���-����-����-���� �������ӷ�ʽ����

Status ListInsert_Duln(DuLinkList L,int i,LElemType_DC e)
{
    DuLinkList p,q;
    if(i<1 || i>ListLength_Dul(L) +1)
        return ERROR;
    p = GetElemPtr_Dul(L,i);
    if (!p)
         p = L;

    q = (DuLinkList)malloc(sizeof(DuLNode));
    if(!q)
        exit(OVERFLOW);

    q->data = e;

    q->next = p->next;
    q->prior = p;
    p->next->prior = q;
    p->next = q;

    return OK;


}











//�㷨2.19
Status ListDelete_Dul(DuLinkList L, int i,LElemType_DC *e)
{
    DuLinkList p;

    if(!(p=GetElemPtr_Dul(L,i)))            //i��ֵ���Ϸ��򱨴�
        return ERROR;


    *e = p->data;               //pָ���ɾ���Ľ�㣬p��ǰ��ָ��ĺ��ָ��p�ĺ�̣�p�ĺ�̵�ǰ��ָ��ָ��p��ǰ��
    p->prior->next = p->next;
    p->next->prior = p->prior;

    free(p);
    p =NULL;

    return OK;
}

void ListTraverse_Dul(DuLinkList L,void(Visit)(LElemType_DC))
{
    DuLinkList p;

    p = L->next;

    while(p!=L)
    {
        Visit(p->data);
        p = p->next;


    }


}

#endif // DUALCYCLELINKEDLIST_C









