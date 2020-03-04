#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

Status Algo_2_16(LinkList *la,LinkList *lb,int i,int j,int len);
Status Algo_2_17(LinkList *L,int i,LElemType_L b);
Status Algo_2_18(LinkList *L,int i);
void InitList_2_16(LinkList *L);
void Output_2_16(LinkList L);

int main(int argc,char *argv[])
{
    int i;
    LinkList la,lb;

    InitList_2_16(&la);
    InitList_2_16(&lb);
    printf("��Ŀ2.17����...\n");



    for(i=1;i<=10;i++)
    {
        Algo_2_17(&la,i,2*i-1);
        Algo_2_17(&lb,i,2*i);
    }


    printf("����õ���ͷ�ڵ�����Ϊ :\n");
    printf("la = ");



    Output_2_16(la);
    printf("\n");


    printf("lb = ");
    Output_2_16(lb);
    printf("\n\n");



    printf("��Ŀ2.16 ��֤ ...\n");
    printf("��la�еڶ����ڵ��������ڵ���뵽lb�ĵ������ڵ�֮ǰ...\n");
    Algo_2_16(&la,&lb,2,6,5);
    printf("la = ");
    Output_2_16(la);
    printf("lb = ");
    Output_2_16(lb);
    printf("\n\n");

    return 0;
}

//��2.16 ɾ��la�е�i���ڵ����len���ڵ㲢��ӵ�lb�е�j���ڵ�֮ǰ

//�����е�������ͷ��㣬˼·���ų����������������ȱ�ǵ�i-1��i��i+len-1���ڵ㣬ɾ��len���ڵ㣬Ȼ���ǳ�j-1���ڵ㣬����ǰ�ߡ�

Status Algo_2_16(LinkList *la,LinkList *lb,int i,int j,int len)
{
    LinkList p,q,s,prep;
    int count;

    if(i<0 || j<0 || len<0)
        return ERROR;

    p = *la;        //pָ��ͷ
    count = 1;
    prep = NULL;
    while (p && count<i)        //�ҵ�i�ڵ㣬pָ��ȥ
    {
        prep  = p;
        p = p->next;
        count++;
    }

    if(!p)
        return ERROR; //�Ҳ�����i��Ԫ�ر���


    q = p;              //��i+len-1���ڵ㣬qָ��ȥ
    while(q || count<i+len-1)
    {
        q = q->next;
        count++;
    }

    if(!q)
        return ERROR;

    if(!prep)
        *la = q->next;      //i=1�����
        else
            prep->next = q->next;

        if(j==1)
        {
            q->next = *lb;
            *lb = p;                    //��Ϊû��ͷ��㣬i=1��������������˵
        }
        else
        {
            s = *lb;            //sָ��ָ���ͷ
            count =1;
            while(s && count<j-1)
            {
                s = s->next;
                count++;
            }
            if(!s)
                return ERROR;

            q->next = s->next;
            s->next = p;

            return OK;
        }
}

//��b����ΪL�ĵ�i���ڵ�

//����Ŀ�е�������ͷ���

Status Algo_2_17(LinkList *L,int i,LElemType_L b)
{
    LinkList p,q;
    int count;

    p  = (LinkList)malloc(sizeof(LNode));           //����ռ䣬����ΪLNode
    if(!p)
        exit(OVERFLOW);
    p->data = b;

    if(i>0)
    {
        if(i==1)
        {
            p->next = *L;
            *L = p;
            return OK;
        }
        else
        {
            if(*L)
            {
                count = 1;
                q = *L;
                while(count<i-1 && q)       //q�ƶ���i-1ǰ
                {
                    count++;
                    q = q->next;
                }
                if(q)                               //q����������һ�������Բ���
                {
                    p->next = q->next;  //pָ��i��Ȼ���׼�Ĳ���
                    q->next = p;
                    return OK;
                }
            }
    }
}
return ERROR;
}


//ɾ��L�ĵ�i���ڵ�

Status Algo_2_18(LinkList *L,int i)
{
    LinkList p,q;
    int count;

    if(i>1)
    {
        p = *L;
        count = 1;
        while(p && count<i-1)
        {
            count++;
            p = p->next;
        }

        if(p)
        {
            if(count>i-1)
            {
            *L = (*L)->next;
            free(p);
            return OK;
            }
            else
            {
                    if(p->next)
                    {

                    q = p->next;
                    p->next = q->next;
                    free(q);
                    return OK;
                    }
            }
        }
    }
    return ERROR;
}

void InitList_2_16(LinkList *L)
{
    *L = NULL;
}

void Output_2_16(LinkList L)
{
    LinkList p = L;

    while(p)
    {
    printf("%2d ",p->data);
    p= p->next;

    }


}
