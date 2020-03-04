//2.26  仍然是求C = A ∩ B，数据结构改为单链表
//思路：跟顺序表一至，if pa = pb，将所指的数据用尾插法插入到Pc中，否则按照两个else if插入到对应的顺序表中

#include<stdio.h>
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

//函数原型

Status Algo_2_26(LinkList La,LinkList Lb,LinkList Lc);
void PrintElem(LElemType_L e);

int main(int argc,char argv[])
{
    LinkList La,Lb,Lc;
    int i;

    if(InitList_L(&La) && InitList_L(&Lb) && InitList_L(&Lc))       //链表创建成功
    {
        for(i=1;i<=10;i++)
            {
            ListInsert_L(La,i,i);
            ListInsert_L(Lb,i,2*i);
            }
    }

    printf("La = ");
    ListTraverse_L(La,PrintElem);
    printf("\n");

    printf("Lb = ");
    ListTraverse_L(Lb,PrintElem);
    printf("\n");

    Algo_2_26(La,Lb,Lc);
    printf("Lc= La∩Lb");
    ListTraverse_L(Lc,PrintElem);
    printf("\n\n");

    return 0;
}

Status Algo_2_26(LinkList La,LinkList Lb,LinkList Lc)
{
    LinkList pa,pb,pc,s;

    if(!La || !Lb)
        return ERROR;

    pa = La->next;
    pb = Lb->next;
    pc= Lc;

    while(pa && pb)
    {
        if(pa->data == pb->data)
        {
            s = (LinkList)malloc(sizeof(LNode));
            if(!s)
                exit(OVERFLOW);
            s->data = pa->data;
            s->next = NULL;

            pc->next = s;               //对s所指元素用尾插法插入到pc中

            pc = pc->next;
            pa = pa->next;
            pb = pb->next;
        }
        else if(pa->data <pb->data)
            pa = pa->next;
        else
            pb = pb->next;

    }
    return OK;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);
}





