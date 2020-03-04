//2.41.2.42用循环链表作为多项式的储存结构，求倒数，按奇偶次项分解为两个多项式
//思路：正常建立表和各种数据结构，具体求导等功能就做数学处理，多项式求导easy描述

#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

typedef struct
{
    int coef;
    int exp;
}PolyTerm;                      //

typedef struct PolyNode
{
    PolyTerm data;
    struct PolyNode *next;
}PolyNode;

typedef PolyNode *PolyLink;
typedef PolyLink LinkedPoly;

Status Algo_2_41(LinkedPoly P);
Status Algo_2_42(LinkedPoly *P,LinkedPoly *P_Odd,LinkedPoly *P_Even);
Status CreatPoly_L(LinkedPoly *P,int n,PolyTerm Data[]);
Status OutputPoly_L(LinkedPoly P);

int main(int argc,char *argv[])
{
    LinkedPoly P1,P2;               //指向单链表节点形的指针，可以理解为一个表的表头，也就是一个单链表
    PolyTerm a[7] = {-2,1,4,2,2,3,11,5,-7,6,8,9,-3,10};

    CreatPoly_L(&P1,7,a);
    CreatPoly_L(&P2,7,a);
    printf("Pn(x) = ");
    printf("%d ",P1->next->next->data.coef);
    OutputPoly_L(P1);
    printf("\n\n");

    printf("题2.41测试...\n");
    {
        Algo_2_41(P1);
        printf("求多项式的导函数之后...\n");
        printf("Pn(x) = ");
        OutputPoly_L(P1);
        printf("\n\n");
    }

    printf("题2.42测试...\n");
    {
    LinkedPoly P_odd,P_even;
    Algo_2_42(&P2,&P_odd,&P_even);
    printf("按照指数奇偶性拆分多项式之后...\n");
    printf("奇次幂 P_odd = ");
    OutputPoly_L(P_odd);
    printf("\n");
    printf("偶次幂 P_EVEN = ");
    OutputPoly_L(P_even);
    printf("\n\n");
    }
}


//求导数
Status Algo_2_41(LinkedPoly P)
{
    LinkedPoly r,pre;

    if(!P)
        return ERROR;

    pre = P;
    r = P->next;                //两个工作指针就位，分别指向表头和首元素
    while(r!=P)
    {
        if(r->data.exp)                     //如果多项式的项的次数不为零，进行求导操作，如果次数为零，即是常数项，需删去节点，free掉
        {
        r->data.coef *= r->data.exp;
        r->data.exp--;
        pre = r;
        }
        else
        {
        pre->next = r->next;
        free(r);
        }
        r = pre->next;                        //r步进，完成一次循环动作
    }
    return OK;
}

//题2.42按指数奇偶性拆分多项式
Status Algo_2_42(LinkedPoly *P,LinkedPoly *P_Odd,LinkedPoly *P_Even)
{
    LinkedPoly r,s,p,q;

    *P_Odd = (LinkedPoly)malloc(sizeof(PolyNode));          //给odd even表的头指针分配储存空间
    *P_Even = (LinkedPoly)malloc(sizeof(PolyNode));           //思路：用if(s->data.exp%2)即s所指的元素的指数对2求余是否为0来判断奇偶性，并复制到表前。

    if(!(*P_Odd) || !(*P_Even))
        exit(OVERFLOW);
    (*P_Odd)->next = *P_Odd;
    (*P_Even)->next = *P_Even;          //初始化，next指针拐弯回来指向自己

    if(!(*P))
        return ERROR;

    p = *P_Odd;         //指向指针的指针的求值等于其所指的指针，让各工作指针指向表头
    q = *P_Even;
    r = (*P)->next;

    while(r!=(*P))
    {
    s = r;
    r =r->next;

    if(s->data.exp%2)           //s所指元素的指数 对二求余，不等于0，即有余数，说明是奇数
    {
        s->next  = p->next;
        p->next = s;
        p= p->next;
    }
    else
    {
        s->next = q->next;
        q->next = s;
        q = q->next;
    }
    }
    free(*P);
    *P = NULL;
}

Status CreatPoly_L(LinkedPoly *P,int n,PolyTerm Data[])           //初始化一个P表，地址在*P,项数是n，data值是data
{
    int i;
    LinkedPoly s,r;

    *P = (LinkedPoly)malloc(sizeof(PolyNode));
    if(!(*P))
        exit(OVERFLOW);
    (*P)->next = *P;

    for(i=0,r=*P;i<n;i++)
    {
    s = (LinkedPoly)malloc(sizeof(PolyNode));
    if(!s)
        exit(OVERFLOW);
    s->data = Data[i];

    s->next = r->next;
    r->next = s;
    r = r->next;
    }
    return OK;
}

Status OutputPoly_L(LinkedPoly P)
{
    int i;
    LinkedPoly r;

    if(!P)
        return ERROR;

    for(r=P->next;r!=P;r=r->next)               //只要r这个指针还没有绕圈完成，持续步进
    {
        if(r==P->next)                                  //具体的打印步骤：本行判断，若r指针在表头，是第一次打印，就直接输出字符，不用带+-符号，后边的一律要带+-号
            printf("%d ",r->data.coef);
        else
        {
            if(r->data.coef<0)                          //小于零-号
            {
                printf(" - ");
                printf("%d",-r->data.coef);         //比如，“-7x^2”,储存如斯。打印时，首先是“-”号，然后是“7”，储存的是-7就要把符号反转一下
            }
            else
            {
                printf(" + ");
                printf("%d",r->data.coef);
            }
        }
    if(r->data.exp)     //如果项数是存在的，就需要打印后边的x，如果次数不是1，就要打印^“次数”
    {
    printf("x");

    if(r->data.exp!=1)
        printf("^%d",r->data.exp);
    }

    }
    return OK;
}


