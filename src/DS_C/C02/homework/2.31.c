//2.31��ѭ������ɾ��ǰ��Ԫ�ز���

#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

Status Algo_2_31(LinkList L,LinkList s);
void InitList_2_31(LinkList *L);
Status CreatList_2_31(LinkList *L,int n,LElemType_L Data[]);
void Output_2_31(LinkList L);

int main(int argc,char *argv[])
{
    LinkList L,s;
    int a[10]= {1,2,3,4,5,6,7,8,9,10};

    InitList_2_31(&L);
    CreatList_2_31(&L,10,a);

    printf("L  =  ");
    Output_2_31(L);
    printf("\n\n");

    s = L->next->next->next->next;
    printf("ɾ��%d ��ǰ��֮��...\n",s->data);
    Algo_2_31(L,s);
    printf("L = ");
    Output_2_31(L);
    printf("\n\n");

    return 0;
}

//ɾ��Sָ��ڵ��ǰ��

Status Algo_2_31(LinkList L,LinkList s)
{
    LinkList r,p;

    if(s->next == s)                //���Ҫɾ���Ľ���next�ڵ㻹�Ǳ�������ѭ������ֻ����һ��Ԫ�أ�
        return ERROR;

        r = s;              //����ָ��rָ��s

        while(r->next->next !=s)
            r = r->next;                    //rָ��������������¸�Ԫ����ԭ����ָԪ��

     p = r->next;
     r->next = p->next;             //ɾ���ı�׼���裬����ָ��pָ����һ��Ԫ�أ�Ȼ��r��next����pָ���ߵ�Ԫ��
     if(p==L)
        L = p->next;

     free(p);

     return OK;
}

void InitList_2_31(LinkList *L)         //��ν��ʼ��һ���������ǰ����ı�ͷָ��NULL��ֹҰָ��
{
    *L = NULL;
}


Status CreatList_2_31(LinkList *L,int n,LElemType_L Data[])
{
    LinkList s,r;
    int i;

    if(*L)
        return ERROR;

    for(i=1;i<=n;i++)
    {
        s =  (LinkList)malloc(sizeof(LNode));
        s->data = Data[i-1];
        if(!s)
            exit(OVERFLOW);

        if(i==1)            //�״�����,sָ��ͷ��s-nextָ�Լ���1��Ԫ�أ�ѭ��������rҲָ��ͷ
        {
        *L = s;
        s->next = *L;
        r = *L;
        }

        else    //�����״�����,�����ǵڶ������У������ղŵĳ�ʼ��������forѭ���׾䣬s�ƶ���������Ľ��ȥ�ˣ�data�ѱ���䡣
        {         //����s�Ĳ�����1.�������¸�ָ��ָ����2.ԭ������Ԫ�ص��¸�ָ��ָ�򱻲���3.ԭ�����е�Ԫ�صĹ���ָ�벽��1��ָ���µĶ���β
            s->next  = r->next;
            r->next = s;
            r = r->next;
        }
    }

    return OK;
}

void Output_2_31(LinkList L)
{
    LinkList p;

    if(L)                                           //�����Ĺ��̣��Ȱ�pָ���ͷ��Ȼ��p�����ڱ�ͷ��ʱ�򣨻�û�ƻ�����ʱ�򣩣��������������һ��ֱ����һȦ����
    {
        printf("%2d ",L->data);

        p = L->next;
        while(p!=L)
        {
            printf("%2d ",p->data);
            p = p->next;
        }
    }
}
