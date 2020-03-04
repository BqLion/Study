//2.32给明明留有pre指针空间的单项循环列表完善为双向循环列表

#include <stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

typedef int LElemType_L;                //定义列表中的数据类型 ，本次为int
typedef struct LNode                    //定义列表节点的基本数据结构：1个类型为int的data域，一前一后两个指针域分别指向前后
{
    LElemType_L data;
    struct LNode* next;
    struct LNode* pre;
}LNode;
typedef LNode* LinkList;            //定义基类型为LNode 的指针LinkList

//函数原型
Status Algo_2_32(LinkList L);               //具体对列表操作的函数，参数是一个指向节点的指针
Status InitList_2_32(LinkList *L);          //初始化列表的函数，参数是一个指向节点的指针的指针，即二重指针
Status CreatList_2_32(LinkList L,int n,LElemType_L Data[]);    //
void Output_2_32(LinkList L);
void OutputReverse_2_32(LinkList L);

int main(int argc,char *argv[])
{
    PressEnter;

    LinkList L;
    LElemType_L a[10] = {1,2,3,4,5,6,7,8,9,10};

    PressEnter;

    InitList_2_32(&L);
    CreatList_2_32(L,10,a);

    PressEnter;

    printf("L = ");
    Output_2_32(L);
    printf("\n\n");

    PressEnter;

    printf("为链表设置前驱后继后逆序输出链表...\n");
    Algo_2_32(L);
    printf("L = ");

    PressEnter;

    OutputReverse_2_32(L);
    printf("\n\n");

    return 0;
}

Status Algo_2_32(LinkList L)
{
    LinkList r;                 //指向节点的指针r

    if(!L)
        return ERROR;   //如果L等于0则报错

    for(r= L;r->next!=L;r = r->next)        //当工作指针r不等于表头（没有绕一圈回来的时候），r持续步进，直至遍历本表
        r->next->pre = r;                       //遍历的时候对每一个r的next也就是下一个元素的pre域做逐个写入操作

    L->pre = r;                                     //遍历一圈完成，所有的结点都有了pre指针，除了头结点，这时单独将头结点赋值
    return OK;
}

Status InitList_2_32(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(LNode));             //初始化操作：给表头动态申请一个内存空间，表头的pre赋值为null（如题意），表头的next指针赋值为空防止野指针
    if(!(*L))
        exit(OVERFLOW);

    (*L)->pre = NULL;
    (*L)->next = L;

    return OK;
}

Status CreatList_2_32(LinkList L,int n,LElemType_L Data[])
{
    LinkList s,r;
    int i;

    if(!L || L->next !=L )       //排除特殊情况（初始化没初始化好的情况）：即L=空，或者L的next指针 没有妥善地置为零，等于其他的元素
        return ERROR;

    for(i=1,r = L;i<=n;i++)             //循环赋值，计数器i置为1，r指针指向表头，s指向新申请的内存。对列表赋值执行n次
    {
        s = (LinkList)malloc(sizeof(LNode));        //每次偶读给工作指针s这里申请内存空间
        if(!s)
            exit(OVERFLOW);
        s->data = Data[i-1];                            //新申请到的被工作指针s所指的内存空间里赋值data，标准的链表插入的步骤，即把s所指的值查到r后边。（1引，2换，3移指针）
        s->pre = NULL;

        s->next = r->next;                      //1引（新的后指针指向原的后元素）
        r->next = s;                                    //2换（原元素的后指针指向新的元素）
        r = r->next;                                //应当一直指向对列尾部的工作指针移位，步进一指向新的对列尾部
                                                            //然后跳上去开始新一轮的循环，重新申请动态内存空间，应该指向内存空间的工作指针s跳到新的空间去，完成一个循环的闭合
    }
        return OK;
}

void Output_2_32(LinkList L)
{
    LinkList p;

    if(L)                           //只有表存在才会有如下的操作
    {
        p  = L->next;          //p指向首元，当p没有绕一圈回来时循环做如下操作：1.打印所指元素的data值 2.步进1。
        while(p!=L)
        {
            printf("%2d ",p->data);
            p = p->next;
        }
    }
}

void OutputReverse_2_32(LinkList L)
{
    LinkList p;

    if(L)
    {
        p = L->pre;
        while(p !=L)
        {
        printf("%2d ",p->data);
        p = p->pre;
        }
    }
}


