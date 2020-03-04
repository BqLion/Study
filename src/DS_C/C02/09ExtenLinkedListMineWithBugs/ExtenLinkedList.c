/***********************************

�ļ��У�C02���Ա�

�ļ�����ExtenLinkedList.c

�㷨��2.20

**********************************/

#ifndef EXTENLINKEDLIST_C
#define EXTENLINKEDLIST_C

#include "ExtenLinkedList.h"

Status MakeNode_E(Link *p,LElemType_E e)    //�����½ڵ���p��ָ��λ�ã�e�����ݸ�ֵ֮
{
    *p = (Link)malloc(sizeof(ELNode));          //����ռ�
    if(!(*p))
        exit(OVERFLOW);

    (*p)->data = e;
    (*p)->next = NULL;    //���ָ���ÿ�

    return OK;
}

void FreeNode_E(Link *p)
{
    free(*p);
    *p = NULL;
}

Status InitList_E(ELinkList *L)
{
    Link p;

    p = (Link)malloc(sizeof(ELNode));
    if(!p)
        exit(OVERFLOW);
    p->next = NULL;

    (*L).head = (*L).tail = p;//p�ղ���������˿ռ䣬�����½���L�б��ͷ��βָ���ָ��p��λ�ã�Ȼ�����ֵΪ0
    (*L).len  = 0;

    return OK;
}

void ClearList_E(ELinkList *L)
{
        Link p,q;

        p = (*L).head->next;    //��ͷ�ļ��еĶ��壬ELinkList ��һ��struct����ָ��ͷβ����head/tailָ��ͳ���int���ɡ�ָ��pָ���ɾ����L��ͷ��Ԫ�ص�next�����׽ڵ��ߵĵ�һ��Ԫ��

        while(p)                    //��p������0��Ҳ����һȦ��û���ƻ�����ʱ���ظ������²�����
        {
            q = p->next;         //q����ֵΪp����һ��Ԫ��   ����һ
            free(p);                    //��p free��
            p = q;              //q���Ƶ�p�ϣ�����һ                 ���Ϲ���ѭ��
        }

        (*L).head->next = NULL;             //L��ͷָ�����һ��Ԫ���ÿգ���ֹҰָ��
        (*L).tail = (*L).head;                     //L ��βָ���ÿգ���ֹҰָ��
        (*L).len = 0;                                   //struct������Ԫ�ض����㡢�ÿգ�����������е�����
}

void DestroyList_E(ELinkList *L)
{
    ClearList_E(L);         //����clear��ͷ�����ָ��next�Ѿ���NULL��βָ����NULL��len=0
    free((*L).head);        //��һ���ͷ�ͷ���
    (*L).head = (*L).tail =NULL;    //L��ͷָ�롢βָ����ʱΪ�˷�ֹҰָ������ÿ�
}

void InsFirst_E(ELinkList *L,Link h,Link s)     //s����h��
{
     if(h==(*L).tail)
        (*L).tail = h->next;

    (*L).len++;

    s->next = h->next;
    h->next = s;


}

Status DelFirst_E(ELinkList *L,Link h,Link *q)      //ɾȥhָ��Ľ�㣬��q������ֵ
{
    *q = h->next;           //ָ��ָ���ָ��qָ��h��nextָ��

    if(*q)      //��h��next
    {
        h->next  = (*q)->next;      //h��ֻ��һ���ڵ�
        if(!h->next)
                (*L).tail = h;

        (*L).len--;

        return OK;
    }
    return ERROR;
}

void Append_E(ELinkList *L,Link s)          //��s����L��β��
{
    int count = 0;

    (*L).tail->next = s;//L�ı�βԪ�ص�nextָ��ָ��ָ��s��ָ��Ԫ�أ�

    while(s)                    //s����ָNULL
    {
        (*L).tail = s;          //L��βָ��ָ��s���±�β��
        s = s->next;           //s������s��β��                   ���ϣ�ֱ��������s���ף����ΪNULL��whileѭ������ֹ
        count++;                 //����������
    }

    (*L).len += count;     //��ĳ������Ӽ������Ƶ���ô��
}

Status Remove_E(ELinkList *L,Link *q)       //ɾ��L��β�ڵ㣬����q����
{
    Link p;

    if(!(*L).len)               //�����������L�ĳ��ȵ���������Ӧ����Ұָ�벢����
    {
        *q = NULL;
        return ERROR;
    }

    p  = (*L).head;             //pָ��ͷ��
    *q  = (*L).tail;            //qָ���β

    while(p->next!=(*L).tail)           //��p����һ��Ԫ����δ�ߵ���β��ʱ��
        p = p->next;                        //pѭ������1

    p->next = NULL;                     //�����ϱߵ�ѭ����p�Ѿ�ָ���βԪ�������һ��Ԫ�أ���ʱ��p��nextָ���ÿ�
    (*L).tail = p;                             //p�Ѿ�ָ�����ڶ���Ԫ�ء��б��β��ָ����ʱ��Ϊָ��p��Ҳ������ǰ����һ������ԭ���Ķ�β��

    (*L).len--;                                    //L�ĳ���--

    return OK;

}


void InsBefore_E(ELinkList *L,Link *p,Link s)     //��sָ�Ķ������뵽p��ǰ��
{
    Link q;

    q = PriorPos_E(*L,*p);          //Ѱ��p��ǰ��λ��
    if(!q)
        q = (*L).head;                    //��p��ǰ��ֻ��һ���ڵ㣬�Ǿ���qָ���ͷ
    //q�����Ѿ��ɹ�ָ��p��ǰ��
    s->next = *p;   //s��nextָ��ָ��p������pǰ��
    q->next = s;    //qҲ�ǹ���ָ�룬ֱ����q��nextָ��s��������˴�����빤��
    *p = s;            //p��ǰָ���λ������ �б仯��ֱ��ָ��s����ֹҰָ��

    (*L).len++;
}

void InsAfter_E(ELinkList *L,Link *p,Link s)
{
    if(*p == (*L).tail)
        (*L).tail = s;

    s->next = (*p)->next;
    (*p)->next = s;
    *p = s;

    (*L).len++;
}

void SetCurElem_E(Link p,LElemType_E e)
{
    p->data = e;

}

LElemType_E GetCurElem_E(Link p)
{
    return p->data;
}

Status ListEmpty_E(ELinkList L)
{
    if(L.len)
        return FALSE;
    else
        return TRUE;
}

int ListLength_E(ELinkList L)
{
    return L.len;
}

PositionPtr GetHead_E(ELinkList L)
{
    return L.len;
}

PositionPtr GetLast_E(ELinkList L)
{
    return L.tail;
}

PositionPtr PriorPos_E(ELinkList L,Link p)
{
    Link q;

    q= L.head->next;
    if(q==p)
        return NULL;
    else
    {
            while(q->next!=p)
            q = q->next;

    return q;
    }
}

PositionPtr NextPos_E(Link p)
{
    return p->next;
}

Status LocatePos_E(ELinkList L,int i,Link p)
{
    int count = 0;
    p = L.head;//pָ����ָ��ָ�롰*p��  ����ֵΪL��ͷ���

    if(i<0 || i>L.len)
        return ERROR;

    while(count<i)
    {
        count++;
        p = p->next;   //û�й���ʱ��pָ��ָ��ġ�*p��ָ�����   ��ֱ��ˮƽ�ߵ�   ����
    }

    return OK;                 //������������ʱ��*pָ��ָ����ǵ�i��Ԫ��
}

PositionPtr LocateElem_E(ELinkList L,LElemType_E e,Status(Compare)(LElemType_E,LElemType_E))
{
    Link p = L.head->next;

    while(p && !(Compare(e,p->data)))       //��p������NULL��e��p����ȵ�ʱ����������²���
        p = p->next;

    return  p;
}

Status ListTraverse_E(ELinkList L,void(Visit)(LElemType_E))
{
    Link p;
    int j;

    p = L.head->next;

    for(j=1;j<=L.len;j++)
    {
        Visit(p->data);
        p = p->next;
    }
    return OK;
}

//�㷨2.9�ĸ�д

Status ListInsert_L_E(ELinkList *L,int i,LElemType_E e)
{
    Link h,s;

    s = &e;

    LocatePos_E(*L,i,h);

    InsFirst_E(L,h,s);          //s����h���

    return OK;
}

Status ListDelete_L_E(ELinkList *L,int i,LElemType_E *e)
{
    Link p,q;

    if(i<1  ||  i>(*L).len)
        return ERROR;

    LocatePos_E(*L,i-1,&p);
    DelFirst_E(L,p,&q);

    *e = q->data;
    free(q);
    q = NULL;

    return OK;
}











#endif // EXTENLINKEDLIST_C













