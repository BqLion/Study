//2.31单循环链表删除前驱元素操作

#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

Status Algo_2_31(LinkList L,LinkList s);
void InitList_2_31(LinkList *L);
Status CreatList_2_31(LinkList *L,int n,LElemType_L Data[]);
void Output_2_31(LinkList L);

int main(int argc,char *argv[])
{
    LinkList L,s;
    int a[10]= {1,2,3,4,5,6,7,8,9,10};

    InitList_2_31(&L);
    CreatList_2_31(&L,10,a);

    printf("L  =  ");
    Output_2_31(L);
    printf("\n\n");

    s = L->next->next->next->next;
    printf("删除%d 的前驱之后...\n",s->data);
    Algo_2_31(L,s);
    printf("L = ");
    Output_2_31(L);
    printf("\n\n");

    return 0;
}

//删除S指向节点的前驱

Status Algo_2_31(LinkList L,LinkList s)
{
    LinkList r,p;

    if(s->next == s)                //如果要删除的结点的next节点还是本身（即本循环表中只有这一个元素）
        return ERROR;

        r = s;              //工作指针r指向s

        while(r->next->next !=s)
            r = r->next;                    //r指针持续步进至下下个元素是原本所指元素

     p = r->next;
     r->next = p->next;             //删除的标准步骤，工作指针p指向下一个元素，然后r的next跳过p指向后边的元素
     if(p==L)
        L = p->next;

     free(p);

     return OK;
}

void InitList_2_31(LinkList *L)         //所谓初始化一个链表，就是把它的表头指向NULL防止野指针
{
    *L = NULL;
}


Status CreatList_2_31(LinkList *L,int n,LElemType_L Data[])
{
    LinkList s,r;
    int i;

    if(*L)
        return ERROR;

    for(i=1;i<=n;i++)
    {
        s =  (LinkList)malloc(sizeof(LNode));
        s->data = Data[i-1];
        if(!s)
            exit(OVERFLOW);

        if(i==1)            //首次运行,s指表头，s-next指自己（1个元素，循环链表），r也指表头
        {
        *L = s;
        s->next = *L;
        r = *L;
        }

        else    //不是首次运行,假设是第二次运行：经过刚才的初始化，跳回for循环首句，s移动到新申请的结点去了，data已被填充。
        {         //插入s的操作：1.待插者下个指针指向后边2.原队列中元素的下个指针指向被插者3.原队列中的元素的工作指针步进1，指向新的对列尾
            s->next  = r->next;
            r->next = s;
            r = r->next;
        }
    }

    return OK;
}

void Output_2_31(LinkList L)
{
    LinkList p;

    if(L)                                           //遍历的过程：先把p指向表头，然后当p不等于表头的时候（还没绕回来的时候），持续输出并步进一，直到绕一圈回来
    {
        printf("%2d ",L->data);

        p = L->next;
        while(p!=L)
        {
            printf("%2d ",p->data);
            p = p->next;
        }
    }
}
