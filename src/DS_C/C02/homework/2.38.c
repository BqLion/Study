//2.38 双向循环链表plus :每个节点除了pre，data，next三个域之外，还多了一个freq域。freq初始化值都是0，每被访问一次freq就++,各结点按照freq的大小降序排列。
//构造这个数据结构并构造这个LOCATA算法。
//思路：构造数据结构就是在原双链表的结点的基础上加了一个freq域。locate算法：按照pre p两个工作指针去访问值。每次访问freq++，每次访问后对freq和前置元素的freq作比较，如果比前置的元素大，则有如下操作：
//需要调整p的位置。用pre这个侦查指针步退，并同时与p所指元素做比较，当pre终于比大，停下来，把p挪到pre的后边来，这里是合适的位置。比如
//（10）（5）（5）（5）（5）->（10）（5）（5）（5）（6），这时pre侦查，找到第一个元素是比6大的，停在10上，把p所指的6插入到10身后。
//时间“22:27   完成：23:41

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//数据结构定义
typedef int LElemType_DC;
typedef struct DuLNode
{
    LElemType_DC data;
    struct DuLNode *prior;
    struct DuLNode *next;
    int freq;
}DuLNode;
typedef DuLNode *DuLinkList;            //就是双链表的数据结构形，多了一个int freq而已

//函数原型
int Algo_2_38(DuLinkList L,LElemType_DC e);
Status CreatList_DuL_2_38(DuLinkList *L,int n,LElemType_DC Data[]);
Status Output_DuL_2_38(DuLinkList L);

int main (int argc,char *argv[])
{
    DuLinkList L,p;
    int i;
    LElemType_DC data[10] = {1,2,3,4,5,6,7,8,9,10};
    LElemType_DC tmp[10] = {1,2,2,2,3,4,4,5,5,9};

    CreatList_DuL_2_38(&L,10,data);
    printf("初始化的链表L为 :");
    Output_DuL_2_38(L);
    printf("\n\n");

    for(i=1;i<=10;i++)
        Algo_2_38(L,tmp[i-1]);
    printf("访问以后：L = ");
    Output_DuL_2_38(L);
    printf("\n\n");
    printf("对应访问次数：");
    for(p=L->next;p!=L;p = p->next)
        printf("%2d ",p->freq);
    printf("\n\n");

    return 0;
}

//核心的定位算法：
int Algo_2_38(DuLinkList L,LElemType_DC e)
{
    DuLinkList p,pre;
    int i;

    if(!L ||L->next == L )      //当整个链表为空Destroyed 或者只有头结点Deleted,这种情况返回错误
    return 0;

    i = 1;
    pre = L;
    p = L->next;
    while(p!=L && p->data!=e)
    {
    i++;
    pre = p;
    p = p->next;
    }  //定位e，吧p和pre挪过去

    if(p!=L)//没有绕一圈扑空了，找到了元素
    {
    p->freq++;      //被locate的这个元素自增1

    while(pre!=L && pre->freq<p->freq)  //这个条件相当重要，做了freq加一的操作之后，要检查本元素和前一个元素相比是否比前元素大，若比其大，pre要倒车，直到倒到头结点或者比p大的元素为止，然后下一步的操作就是把p逃出来，放在pre的后边，实现了排序
    {
    i--;
    pre = pre->prior;
    }

    if(pre->next!=p)        //检查一下刚才哪一步做了没，如果没做，pre的下一个元素肯定是p，跳过。如果做了，则不满足，执行挖出->归队的操作
    {
        p->next->prior = p->prior;
        p->prior->next= p->next;            //取出

        p->next = pre->next;
        p->prior = pre;
        pre->next->prior = p;
        pre->next =p;                               //放回
    }

    return i;               //本函数的本分是定位，所以返回i这个位序，加一个freq并以此排序，是额外的功能（相当于查找并排序了）
    }

    return 0;           //定位失败，返回0
    }

Status  CreatList_DuL_2_38(DuLinkList *L,int n,LElemType_DC Data[])     //从无到有创建
{
    DuLinkList s,h;
    int i;

    *L = (DuLinkList)malloc(sizeof(DuLNode));
    if(!(*L))
        exit(OVERFLOW);
    (*L)->next = (*L)->prior = *L;

    for(i=1,h=*L;i<=n;i++)
    {
        s = (DuLinkList)malloc(sizeof(DuLNode));
        if(!s)
            exit(OVERFLOW);
        s->data =Data[i-1];
        s->freq =0;

        s->next = *L;
        s->prior = h;
        h->next = s;

        if(h==*L)
            h->prior = s;

        h = h->next;
    }
}

Status Output_DuL_2_38(DuLinkList L)
{
    DuLinkList p;

    if(!L)
        return ERROR;

    else
    {
     p = L->next;
     while(p!=L)
     {
        printf("%2d ",p->data);
        p = p->next;
     }
    }
    return OK;
}






























