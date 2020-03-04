#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

Status Algo_2_15(LinkList ha,LinkList hb,LinkList *hc);
void PrintElem(LElemType_L e);

int main(int argc,char *argv[])
{
    LinkList ha,hb,hc;
    int i;

    if(InitList_L(&ha) && InitList_L(&hb) && InitList_L(&hc))
    {
        for(i=1;i<=5;i++)
            ListInsert_L(ha,i,i);
        for(i=1;i<=7;i++)
            ListInsert_L(hb,i,2*i);
    }

    printf("ha = ");
    ListTraverse_L(ha,PrintElem);
    printf("\n");
    printf("hb = ");
    ListTraverse_L(hb,PrintElem);
    printf("\n\n");

    Algo_2_15(ha,hb,&hc);
    printf("连接ha和hb之后的链表为 : \n hc=  ");
    ListTraverse_L(hc,PrintElem);
    printf("\n\n");

    return 0;
}

Status Algo_2_15(LinkList ha,LinkList hb,LinkList *hc)
{
    LinkList pa,pb;

    if(ha && hb)                //当两个表都不为空
    {
        pa = ha;
        pb = hb;

        while(pa->next && pb->next)         //当两个指针的下一个元素都不是空的时候都循环步进，直到其中一个指针下一个为空停下来
    {
        pa = pa->next;
        pb = pb->next;
    }

    if(!pa->next)           //停下来之后这两个if检查是谁停下来.如果pa较短停的是他，hc指向pa队列的头，然后pa的next指针指向hb的头，让hb接在ha的后边
    {
        *hc =ha;
        pa->next = hb->next;
    }

    if(!pb->next)
    {
        *hc = hb;
        pb->next = ha->next;
    }

    return OK;
    }

    return ERROR;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);
}






