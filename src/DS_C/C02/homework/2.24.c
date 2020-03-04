#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

//函数原型
Status Algo_2_24(LinkList La,LinkList *Lb,LinkList *Lc);
void PrintElem(LElemType_L e);

int main(int argc,char *argv[])
{
    LinkList La,Lb,Lc;
    int i,mark;

    if(InitList_L(&La) && InitList_L(&Lb)&&InitList_L(&Lc))           //链表创建成功
    {
        for(i=1;i<=5;i++)
            {
                ListInsert_L(La,i,2*i-1);
                ListInsert_L(Lb,i,2*i);
            }
    }

    printf("创建好的链表为:\n");
    printf("La = ");
    ListTraverse_L(La,PrintElem);
    printf("\n");
    printf("Lb = ");
    ListTraverse_L(Lb,PrintElem);
    printf("\n\n");

    Algo_2_24(La,&Lb,&Lc);
    printf("归并La和Lb为Lc = ");
    ListTraverse_L(Lc,PrintElem);
    printf("\n\n");

    return 0;
}
//归并两个递增单链表为一个递减单链表

Status Algo_2_24(LinkList La,LinkList *Lb,LinkList *Lc)
{
    LinkList pa,pb,s;

    if(!La || !Lb || (!La->next && !(*Lb)->next))       //La或Lb有一个不存在或者两个均为空的时候报错
        return ERROR;

        *Lc = La;                       //思路： la就是lc的头。工作指针就位情况：pa指向la首节点，pb指向lb首节点。
        pa = La->next;
        pb = (*Lb)->next;
        La->next = NULL;        //La这个表要做为新表的，所以需要用头插法实现逆序。这一行把用头插法实现逆序的原队尾元素NULL插进来

        while(pa && pb)
    {
        if(pa->data <= pb->data)            //pa小，就插入pa
        {
            s = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = s;
        }
        else
        {
        s = pb->next;                          //else 插入pb
        pb->next = La->next;
        La->next = pb;
        pb = s;
        }
    }

    while(pa)
    {
    s = pa->next;
    pa->next = La->next;
    La->next = pa;
    pa = s;
    }

    while(pb)
    {
        s = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = s;
    }
    free(*Lb);

    return OK;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);

}




