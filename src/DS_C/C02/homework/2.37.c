//2.37 双循环链表，将L改造为L’，即按奇偶次序，一趴不动，另一趴提出、倒序、连接在前一趴的后边。（隔一取一，中心对称，重连接）
//思路：首节点前后各放一指针，前指针指尾元素不动。后指针指向No.2元素，将No.2的 next No.3元素标准删除，并标准插入到队尾之后。然后后指针步进，到No.4元素，重复，删除No.5，插入到队尾，步进至No.6。直到后指针或后指针next碰到队尾指针时，break。

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/08DualCycleLinkedList/DualCycleLinkedList.c"

Status Algo_2_37(DuLinkList L);
void PrintElem(LElemType_DC e);

int main(int argc,char *argv[])
{
    DuLinkList L;
    int i;

    InitList_Dul(&L);
    for(i=1;i<=10;i++)
        ListInsert_Dul(L,i,i);
    for(i=2;i<=11;i++)
        ListInsert_Dul(L,i,i);
    ListTraverse_Dul(L,PrintElem);
    printf("\n\n");

    Algo_2_37(L);
    printf("重新排序后...\n");
    ListTraverse_Dul(L,PrintElem);
    printf("\n\n");

    return 0;
}

//核心函数：按照奇偶序列，将其中一列倒序后插入到前一列身后
Status Algo_2_37(DuLinkList L)
{
    DuLinkList head,tail,p;

    head = L->next;
    tail = L->prior;

    while(head!=tail)
    {
        if(head->next !=tail)
        {
        p = head->next;         //p指向No2

        p->next->prior = head;          //双链表标准删除操作
        head->next = p->next;
        p->next = tail->next;
        p->prior = tail;

        tail->next->prior = p;
        tail->next=p;                          //双链表标准插入动作

        head = head->next;              //head步进1，指向No3.完成一次循环
        }

        else
            break;          //如果碰到tail，或者下一个元素是tail说明工作完成，可以挑出循环。

    }
    return OK;
}

void PrintElem(LElemType_DC e)
{
    printf("%d ",e);

}
