#include<stdio.h>
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

//函数原型

int Algo_2_13(LinkList L,LElemType_L x);
void PrintElem(LElemType_L e);

int main(int argc,char *argv[])
{
    LinkList L;
    int i;

    if(InitList_L(&L))
    {
        for(i=1;i<=10;i++)
        ListInsert_L(L,i,2*i);
    }

    printf("L = ");
    ListTraverse_L(L,PrintElem);
    printf("\n\n");

    printf("元素 \"12\" 在链表L 中的位置为 %d \n",Algo_2_13(L,12));
    printf("\n");

    return 0;
    }


    int Algo_2_13(LinkList L,LElemType_L x)
    {
        int i;
        LinkList p;

        if(L)
        {
            i = 1;
            p = L->next;
            while(p)
            {
            if(p->data==x)
                return i;
            i++;
            p = p->next;
            }
        }
        return 0;
    }



    void PrintElem(LElemType_L e)
    {
    printf("%d ",e);
    }

