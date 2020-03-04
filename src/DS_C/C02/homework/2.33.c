//2.33 将一个线性链表中含有的三类字符的数据元素，（char digth   others）三种，按三类分割成三个循环链表，每种链表只含一种元素
//思路：把每个元素步进取出放在一个temp中，然后用if（isalpha）  else if （isdight） else 来表示三种情况
//时间：21：39 结束时间：22:58

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//数据类型定义

typedef char LElemType_L;               //这次要判断是什么类型的字符，所以数据类型不是int了
typedef struct LNode
{
    LElemType_L data;
    struct LNode* next;
}LNode;
typedef LNode* LinkList;

Status Algo_2_33(LinkList L,LinkList L_char,LinkList L_num,LinkList L_other);       //功能函数，用于把L 分割为char  num   other三个分表
Status InitList_2_33(LinkList *L);         //初始化单链表
Status CreatList_2_33(LinkList L,int n,LElemType_L Data[]);     //create单链表
Status InitList_CL_2_33(LinkList *L);//初始化三个循环链表
void Output_2_33(LinkList L);//打印单链表下边是打印循环链表
void Output_CL_2_33(LinkList L);


int main(int argc,char *argv[])
{
    LinkList L,L_char,L_num,L_other;
    LElemType_L *a = "2poks++++2";

    InitList_2_33(&L);
    CreatList_2_33(L,10,a);

    printf("L = ");
    Output_2_33(L);
    printf("\n\n");

    printf("拆分单链表之后...\n");
    InitList_CL_2_33(&L_char);
    InitList_CL_2_33(&L_num);
    InitList_CL_2_33(&L_other);
    Algo_2_33(L,L_char,L_num,L_other);

    printf("L_char = ");
    Output_CL_2_33(L_char);
    printf("\n\n");
    printf("L_num = ");
    Output_CL_2_33(L_num);
    printf("\n\n");
    printf("L_other = ");
    Output_CL_2_33(L_other);
    printf("\n\n");

    return 0;
}

Status Algo_2_33(LinkList L,LinkList L_char,LinkList L_num,LinkList L_other)
{
        LinkList r,rc,rn,ro,s;

        if(!L)
            return ERROR;

        r = L->next;            //r指向主队列，其他三个r指向分队列，s就是temp，临时中转
        rc = L_char;
        rn = L_num;
        ro = L_other;

        while(r!=NULL)
        {
            s = (LinkList)malloc(sizeof(LNode));

            if(!s)
                exit(OVERFLOW);
            s->data = r->data;

            if(isalpha(r->data))            //如果r所指的data是个字符型的，就做如下操作。齐次的其他本结构也是判断是否是字符或者是否是其他类，操作方式同理。
            {
                s->next = rc->next;         //把工作指针s所指的东西插入到队列指针rn所指的元素的身后的标准操作
                rc->next = s;                  //1引（把待插入元素引出指针指向队列元素的身后）2换（把队列元素的next指针从原身后元素换为指向新的插队进来的元素）3挪（把工作指针rn挪动到新的对列尾去，也就是新插入元素的头上，等于步进1）
                rc  = rc->next;
            }
            else if(isdigit(r->data))
            {
                s->next = rn->next;
                rn->next = s;
                rn = rn->next;
            }
            else
            {
                s->next = ro->next;
                ro->next = s;
                ro = ro->next;

            }

            r = r->next;    // r在最后一个元素那听了下来，防止野指针步进1，置为NULL
            }
            return OK;
}

Status InitList_2_33(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L))
        exit(OVERFLOW);

    (*L)->next =NULL;

    return OK;

}


Status CreatList_2_33(LinkList L,int n,LElemType_L Data[])
{
    LinkList s,r;
    int i;

    if(!L || L->next )
        return ERROR;

    for(i=1,r=L;i<=n;i++)           //初始条件时计数器等于1，r指针指向表头
    {
        s = (LinkList)malloc(sizeof(LNode));
        if(!s)
            exit(OVERFLOW);
        s->data = Data[i-1];        //s这个temp从Data数组中取值

        s->next = r->next;      //在r后边插入s
        r->next = s;
        r =r->next;
    }
    return OK;
}


void Output_2_33(LinkList L)
{
    LinkList p;

    if(L)
    {
        p = L->next;
        while(p)
        {
            printf("%2c ",p->data);
            p = p->next;
        }
    }
}

Status InitList_CL_2_33(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L))
        exit(OVERFLOW);

    (*L)->next = *L;                //不能有野指针，循环链表的头结点的next要指向自己

    return OK;
}

void Output_CL_2_33(LinkList L)
{
    LinkList p;
    if(L)
    {
    p = L->next;
    while(p!=L)
    {
    printf("%2c ",p->data);
    p = p->next;
    }
    }
}
