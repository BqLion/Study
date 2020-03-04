#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

Status Algo_2_19_1(LinkList L,int mink,int maxk);
Status Algo_2_19_2(LinkList L,int mink,int maxk);
Status Algo_2_20(LinkList L);
void PrintElem(LElemType_L e);

int main(int argc,char *argv[])
{
    LinkList L;
    int mink,maxk_1,maxk_2,i;
    int a[] = {1,2,3,4,5,6,7,7};

    mink = 2;
    maxk_1 = 4;
    maxk_2 = 6;

    InitList_L(&L);

    for(i = 0;i<8;i++)
        ListInsert_L(L,i+1,a[i]);

    printf("ԭ����L =  ");
    ListTraverse_L(L,PrintElem);
    printf("\n\n");

    printf("��2.19����....\n");
    printf("ɾ�����д��� %d ��С�� %d ��Ԫ��֮��...\n",mink,maxk_1);
    Algo_2_19_1(L,mink,maxk_1);
    printf("L  =  ");
    ListTraverse_L(L,PrintElem);
    printf("\n");

    printf("ɾ�������д��� %d ��С�� %d ��Ԫ��֮��...\n",mink,maxk_2);
    Algo_2_19_2(L,mink,maxk_2);
    printf("L = ");
    ListTraverse_L(L,PrintElem);
    printf("\n\n");

    printf("��2.20����...\n");
    printf("ȥ�������ظ�Ԫ��...\n");
    Algo_2_20(L);
    printf("L = ");
    ListTraverse_L(L,PrintElem);
    printf("\n\n");

    return 0;
}
//��2.19ɾ������Ԫ��λ�����minkС��maxk֮��Ľ��

Status Algo_2_19_1(LinkList L,int mink,int maxk)
{
    LinkList p,pre,s;

    if(!L || !L->next)              //���ǿձ����޷�ɾ��
        return ERROR;

    if(mink>=maxk)              //��ֵ���ô����޷�ɾ��
        return ERROR;

        pre = L;
        p = pre->next;              //preָ��ָ�����λ��pָ��ͷ���

        while(p && p->data<maxk)
        {
            if(p->data<=mink)       //���pָ����������໹û����mink���������
            {
            pre = p;
            p =  p->next;
            }
            else
            {
            s = p;                                //sָ��p��λ������free��s����pre��next����pָ���ߣ�ʵ�ֵ���ɾ���Ĳ���
            pre->next = p->next;
            p = p->next;
            free(s);
            }
        }

        return OK;
}

//��������

Status Algo_2_19_2(LinkList L,int mink,int maxk)
{
    LinkList p,pre,s;

    if(!L || !L->next)
        return ERROR;

    if(mink>=maxk)
        return ERROR;

    pre = L;
    p = pre->next;

    while(p && p->data<=mink)           //δ�����ޣ�����
    {
    pre = p;
    p = p->next;
    }

    if(p)
    {
    while(p && p->data<=maxk)
    {
    s = p;
    pre->next = p->next;
    p = p->next;
    free(s);
    }
    return OK;
    }
}

//ɾ������ֵ��ͬ�Ķ���ڵ�

Status Algo_2_20(LinkList L)
{
    LinkList p,pre,s;

    if(!L || !L->next)
        return ERROR;

    pre = L->next;
    p = pre->next;

    while(p)
    {
    if(pre->data == p->data)
    {
        s = p;
        pre->next = p->next;
        p = p->next;
        free(s);
    }
    else
    {
    pre = p;
    p = p->next;
    }
    }
    return OK;
}

void PrintElem(LElemType_L e)
{
printf("%d ",e);

}






