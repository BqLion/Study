//2.14 ʵ�ֵ�����������Ȳ���Length��L��

#include<stdio.h>
#include<E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c>

int Algo_2_14(LinkList  L);
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

    printf("L=");
    ListTraverse_L(L,PrintElem);
    printf("\n");

    printf("����L�ĳ����� %d \n",Algo_2_14(L));
    printf("\n");

    return 0;
}

int Algo_2_14(LinkList L)
{
    return ListLength_L(L);
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);
}
