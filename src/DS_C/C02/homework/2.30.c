//2.30 要求和上一题一样，求A = A- B∩C，用的是单链表的数据结构

//再次总结思路：上来一个while（pa && pb && pc）循环到pb pc对齐。然后pa一个while（pa && pa->data<pb->data）,循环到pa大于或等于pb
//若pa=pb,则执行循环直至pa删除完毕，若pa>pb，则跳到下一个阶段，也就是if（pa），这时如果pa没出界，pb  pc步进。




#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

Status Algo_2_30(LinkList La,LinkList Lb,LinkList Lc);
void PrintElem(LElemType_L e);

int main(int argc,char*argv[])
{
    LinkList La,Lb,Lc;
    int i;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int b[] = {1,2,3,4,5,6,7,8,8,9,11};
    int c[] = {1,2,3,4,5,6,7,8,11,12};

    if(InitList_L(&La) && InitList_L(&Lb) && InitList_L(&Lc))
    {
        for(i=1;i<=10;i++)
    {
        ListInsert_L(La,i,a[i-1]);
        ListInsert_L(Lb,i,b[i-1]);
        ListInsert_L(Lc,i,c[i-1]);

    }

    }

    printf("La = ");
    ListTraverse_L(La,PrintElem);
    printf("\n");
    printf("Lb = ");
    ListTraverse_L(Lb,PrintElem);
    printf("\n");
    printf("Lc = ");
    ListTraverse_L(Lc,PrintElem);
    printf("\n\n");

    Algo_2_30(La,Lb,Lc);
    printf("La = La - Lb∩Lc = ");
    ListTraverse_L(La,PrintElem);
    printf("\n\n");

    return 0;
}

Status Algo_2_30(LinkList La,LinkList Lb,LinkList Lc)
{
    LinkList pa,pb,pc,pre;

    if(!La || !Lb || !Lc)
        return ERROR;

    pa = La->next;                  //对顺序表删除操作通常有二重指针；对链表操作通常有pre指针和p指针
    pb = Lb->next;
    pc = Lc->next;
    pre = La;

    while(pa && pb && pc)
    {
        if(pb->data<pc->data)
            pb = pb->next;
        else if(pb->data>pc->data)
            pc = pc->next;
        else
        {
        while(pa && pa->data<pb->data)
        {
            pre = pa;
            pa = pa->next;
        }

        while(pa && pa->data==pb->data)//若pa与pb相等，对pa做删除操作
        {
            pre->next = pa->next;//删除操作的思路：pre的next越过pa指向pa的next，free掉pa之后，pa再次等于pre的next；
            free(pa);
            pa = pre->next;

        }

        if(pa)
        {
        pb = pb->next;
        pc = pc->next;
        }
        }
    }
    return OK;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);
}

