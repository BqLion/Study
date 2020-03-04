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
    printf("题目2.17测试...\n");



    for(i=1;i<=10;i++)
    {
        Algo_2_17(&la,i,2*i-1);
        Algo_2_17(&lb,i,2*i);
    }


    printf("创造好的无头节点链表为 :\n");
    printf("la = ");



    Output_2_16(la);
    printf("\n");


    printf("lb = ");
    Output_2_16(lb);
    printf("\n\n");



    printf("题目2.16 验证 ...\n");
    printf("将la中第二个节点起的五个节点插入到lb的第六个节点之前...\n");
    Algo_2_16(&la,&lb,2,6,5);
    printf("la = ");
    Output_2_16(la);
    printf("lb = ");
    Output_2_16(lb);
    printf("\n\n");

    return 0;
}

//题2.16 删除la中第i个节点起的len个节点并添加到lb中第j个节点之前

//本题中的链表无头结点，思路是排除参数有误的情况后先标记第i-1、i、i+len-1个节点，删除len个节点，然后标记出j-1个节点，续在前边。

Status Algo_2_16(LinkList *la,LinkList *lb,int i,int j,int len)
{
    LinkList p,q,s,prep;
    int count;

    if(i<0 || j<0 || len<0)
        return ERROR;

    p = *la;        //p指表头
    count = 1;
    prep = NULL;
    while (p && count<i)        //找第i节点，p指过去
    {
        prep  = p;
        p = p->next;
        count++;
    }

    if(!p)
        return ERROR; //找不到第i个元素报错


    q = p;              //找i+len-1个节点，q指过去
    while(q || count<i+len-1)
    {
        q = q->next;
        count++;
    }

    if(!q)
        return ERROR;

    if(!prep)
        *la = q->next;      //i=1的情况
        else
            prep->next = q->next;

        if(j==1)
        {
            q->next = *lb;
            *lb = p;                    //因为没有头结点，i=1的情况特殊领出来说
        }
        else
        {
            s = *lb;            //s指针指向表头
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

//将b插入为L的第i个节点

//本题目中的链表无头结点

Status Algo_2_17(LinkList *L,int i,LElemType_L b)
{
    LinkList p,q;
    int count;

    p  = (LinkList)malloc(sizeof(LNode));           //申请空间，长度为LNode
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
                while(count<i-1 && q)       //q移动到i-1前
                {
                    count++;
                    q = q->next;
                }
                if(q)                               //q如果不是最后一个，可以插入
                {
                    p->next = q->next;  //p指向i，然后标准的插入
                    q->next = p;
                    return OK;
                }
            }
    }
}
return ERROR;
}


//删除L的第i个节点

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
