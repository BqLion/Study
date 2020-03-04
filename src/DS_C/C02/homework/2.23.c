//2.23归并两个单链表的算法

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

//函数原型

Status Algo_2_23_1(LinkList La,LinkList *Lb,LinkList *Lc);
Status Algo_2_23_2(LinkList La,LinkList *Lb,LinkList *Lc);
void PrintElem(LElemType_L e);

int main(int argc,char *argv[])
{
    LinkList La,Lb,Lc;
    int i,mark;

    if(InitList_L(&La)&&InitList_L(&Lb)&&InitList_L(&Lc))   //链表创建成功
    {
        for(i=1;i<=5;i++)
        {
            ListInsert_L(La,i,2*i-1);
            ListInsert_L(Lb,i,2*i);
        }
    }

    printf("验证题2.23的方法...");
    fflush(stdin);
    scanf("%d",&mark);
    printf("\n");

    printf("创建好的链表为 ：\n");
    printf("La = ");
    ListTraverse_L(La,PrintElem);
    printf("\n");
    printf("Lb = ");
    ListTraverse_L(Lb,PrintElem);
    printf("\n\n");

    if(mark==1)
    {
        printf("题 2.23 方法1 验证...\n");
        Algo_2_23_1(La,&Lb,&Lc);
    }

    printf("归并La和Lb为LC = ");
    ListTraverse_L(La,PrintElem);
    printf("\n\n");

    return 0;
}

//归并两个单链表

//顺序连接

Status Algo_2_23_1(LinkList La,LinkList *Lb,LinkList *Lc)
{
    LinkList prea,pa,pb;
    if(!La || (*Lb) || (!La->next && !(*Lb)->next))         //归并表之前，如果有一个表不存在，或者两个表都是空的，报错
        return ERROR;

        *Lc = La;                   //各工作指针就位，Lc表头是La表头的位置，prea指向La的第一个元素，pa指向La的第二个元素,pb指向Lb的第一个元素
        prea = La;
        pa = La->next;
        pb=  (*Lb)->next;

        while(pa && pb)
        {
            (*Lb)->next = pb->next;
            prea = pa;
            pa = pa->next;
            prea->next = pb;
            pb->next = pa;
            prea = pb;
            pb = (*Lb)->next;
        }
        if(!pa)
            prea->next = pb;

        free(*Lb);
        *Lb = NULL;

        return OK;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);


}



