/*单链表的就地逆置
原理：核心算法是Algo_2_22的最后几句。
思路如下：
1.所有元素next指针转向，由后转指前，头结点、NULL节点互换位置（人类思维）
2.以头结点为操作core的描述：转向后，队列从后往前依次是NULL、1、2、3、4、5…… 就按照这个顺序做头插法，做完后的队列就是倒置队列
3.先将NULL头插到头结点后，即 头结点 ->next = NULL;然后是排队依次头插
4.    1的next = 头结点的next；头结点的 next = 1；完成了1的头插，随后依次步进
*/

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

//函数原型

Status Algo_2_22(LinkList L);
void PrintElem(LElemType_L e);

int main(int argc,char *argv[])
{
    LinkList L;
    int i;

    if(InitList_L(&L))
    {
    for(i=1;i<=10;i++)
        ListInsert_L(L,i,i);
    }

    printf("L = ");
    ListTraverse_L(L,PrintElem);
    printf("\n\n");

    printf("逆置单链表...\n");
    Algo_2_22(L);
    printf("此时L =  ");
    ListTraverse_L(L,PrintElem);
    printf("\n\n");

    return 0;
}

//2.22单链表置逆的操作

Status Algo_2_22(LinkList L)
{
    LinkList pre,p;

    if(!L || !L->next)
        return ERROR;

        p = L->next;                //工作指针就位，指向链表的第一个元素
        L->next = NULL ;        //头插法插入第一个元素，即NULL

        while(p)
        {
        pre = p;
        p = p->next;
        pre->next = L->next;
        L->next = pre;
        }

        return OK;
}

    void PrintElem(LElemType_L e)
    {
        printf("%d ",e);

    }



