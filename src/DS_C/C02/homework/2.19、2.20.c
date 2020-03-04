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

    printf("原链表L =  ");
    ListTraverse_L(L,PrintElem);
    printf("\n\n");

    printf("题2.19测试....\n");
    printf("删除表中大于 %d 且小于 %d 的元素之后...\n",mink,maxk_1);
    Algo_2_19_1(L,mink,maxk_1);
    printf("L  =  ");
    ListTraverse_L(L,PrintElem);
    printf("\n");

    printf("删除链表中大于 %d 且小于 %d 的元素之后...\n",mink,maxk_2);
    Algo_2_19_2(L,mink,maxk_2);
    printf("L = ");
    ListTraverse_L(L,PrintElem);
    printf("\n\n");

    printf("题2.20测试...\n");
    printf("去掉表中重复元素...\n");
    Algo_2_20(L);
    printf("L = ");
    ListTraverse_L(L,PrintElem);
    printf("\n\n");

    return 0;
}
//题2.19删除表中元素位序大于mink小于maxk之间的结点

Status Algo_2_19_1(LinkList L,int mink,int maxk)
{
    LinkList p,pre,s;

    if(!L || !L->next)              //若是空表则无法删除
        return ERROR;

    if(mink>=maxk)              //阈值设置错误，无法删除
        return ERROR;

        pre = L;
        p = pre->next;              //pre指针指向表首位，p指向头结点

        while(p && p->data<maxk)
        {
            if(p->data<=mink)       //如果p指针在数列左侧还没进到mink则持续右移
            {
            pre = p;
            p =  p->next;
            }
            else
            {
            s = p;                                //s指向p的位置随后会free（s）；pre的next跳过p指向后边，实现的是删除的操作
            pre->next = p->next;
            p = p->next;
            free(s);
            }
        }

        return OK;
}

//方法二：

Status Algo_2_19_2(LinkList L,int mink,int maxk)
{
    LinkList p,pre,s;

    if(!L || !L->next)
        return ERROR;

    if(mink>=maxk)
        return ERROR;

    pre = L;
    p = pre->next;

    while(p && p->data<=mink)           //未到下限，步进
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

//删除表中值相同的多余节点

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






