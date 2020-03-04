/************************************

文件夹：C02/08DualCycleLinkedList

文件名：DualCycleLinkedList.c

算法：2.18/2.19

*************************************/

#ifndef DUALCYCLELINKEDLIST_C
#define DUALCYCLELINKEDLIST_C

#include "DualCycleLinkedList.h"

Status InitList_Dul(DuLinkList *L)          //初始化的函数，参数是一个指向头指针的指针
{
    *L = (DuLinkList)malloc(sizeof(DuLNode));  //指针指向动态申请的结点空间的首部
    if(!(*L))
        exit(OVERFLOW);

    (*L)->next = (*L)->prior = *L;                  //首个节点还没有申请出来，这是只能让函数首端的指针，前后指针都指向新申请的内存节点哪里

    return OK;
}

Status ClearList_Dul(DuLinkList L)
{
    DuLinkList p,q;//指向链表的结点形的指针p,q

    p = L->next;    //p指向L的首个元素

    while(p!=L)        //当p不等于L的时候循环做如下操作，遍历一圈后p指针会回到队列之前指向L
    {
        q= p->next;    //指针q指向的是p之后的元素
        free(p);            //把p释放掉
        p = q;              //p步进1                                     翻上去就是q再步进1，如此循环
    }

    //最后结束的时候：前后指针和L指针都归为一起
    L->next = L->prior = L;

    return OK;
}

void DestroyList_Dul(DuLinkList *L)
{
    ClearList_Dul(*L);

    free(*L);           //在上边的清空函数的基础上把头结点L也给清除了

    *L = NULL;     //防止野指针，把L置为NULL
}


Status  ListEmpty_Dul(DuLinkList L)
{
    if(L && L->next==L && L->prior == L)        //如果L不等于0且前后指针都等于L的时候代表此表有头结点，无其他元素，存在，但为空
            return TRUE;
    else
            return FALSE;
}

int ListLength_Dul(DuLinkList L)
{
    DuLinkList p;
    int count;

    if(L)
    {
        count = 0;
        p = L;

        while(p->next!=L)
        {
            count++;
            p=p->next;
        }
    }

    return count;
    }

Status GetElem_Dul(DuLinkList L,int i,LElemType_DC *e)
{
    DuLinkList p;
    int count;

    if(L)
    {
        count = 1;
        p = L->next;

        while(p!=L && count<i)         //p还没绕一圈回来并且也还没到the元素的时候，计数器持续步进1，指针p持续步进1
        {
            count++;
            p = p->next;
        }

    if(p!=L)                                                //以上循环结束了之后，判断一下是绕回来结束的还是指针指到所指的元素停下来的
    {
        *e = p->data;                                       //如果p指针没有指向L ,这是就把p所指的data赋值给e就可以返回正确了，否则就是没有找到，需要返回ERROR
        return OK;
    }
    }
    return ERROR;
}

int LocateElem_Dul(DuLinkList L,LElemType_DC e,Status(Compare)(LElemType_DC,LElemType_DC))
{
    DuLinkList p;
    int count;

    if(L)
    {
            count = 1;
            p = L->next;

            while(p!=L && !Compare(e,p->data))         //查找的标准操作：当指针未溢出且条件未满足时，持续重复如下操作
            {
            count ++;                                                       //计数器步进，指针步进

            p = p->next;
            }

            if(p!=L)
                return count;
    }
    return 0;
}

Status PriorElem_Dul(DuLinkList L,LElemType_DC cur_e,LElemType_DC *pre_e)
{
    DuLinkList p;

    if(L)
    {
        p = L->next;
        while(p!=L&&p->data!=cur_e)
            p  = p->next;                               //p 指针指向头结点，当p指针未跑回来且p所指的data不满足条件的情况下，p持续步进

        if(p!=L && p->prior!=L)             //p不为首节点（错误）、p的前序结点不为首节点（这样就不用求前序节点了）
        {
            *pre_e = p->prior->data;        //把p指针的前序结点的data赋值给pre_e就完事儿了
            return OK;
        }
    }
    return ERROR;
}

Status NextElem_Dul(DuLinkList L,LElemType_DC cur_e,LElemType_DC *next_e)
{
    DuLinkList p;
    if(L)
    {
        p   =L->next;

        while(p!=L && p->data!=cur_e)
            p = p->next;

        if(p!=L && p->next!=L)
        {
            *next_e = p->next->data;
            return OK;
        }
    }
    return ERROR;
}

DuLinkList GetElemPtr_Dul(DuLinkList L,int i)
{
    int count;
    DuLinkList p;

    if(L && i>0)
    {
    count = 1;
    p = L->next;

    while(p!=L && count<i)
    {
    count++;
    p = p->next;
    }

    if(p!=L)
        return p;
    }
    return NULL;
}

//算法2.18

//与课本双链表插入的算法略有不同，根源是本GetElemP_Dul不同
Status ListInsert_Dul(DuLinkList L,int i ,LElemType_DC e)
{
    DuLinkList p,s;

    if(i<1 || i>ListLength_Dul(L)+1)        //先对i做出限制
            return ERROR;

    p = GetElemPtr_Dul(L,i);//获取的是指向L第i个元素的指针
    if(!p)
        p = L;              //若p=NULL，那么i已经超出了正常的界限，这时需要让野指针p指向表头

    s = (DuLinkList)malloc(sizeof(DuLNode));
    if(!s)
            exit(OVERFLOW);                 //两个工作指针，p指向待插入的结点，s指向新分配的内存空间头部

    s->data = e;            //待插入的数据项先复制给s所指的data

    s->prior = p->prior;            //s所指的元素：1.s前驱指针指向p的前驱 2.s的后继指针指向p 3.p的前驱的后继指针指向s 4.p的前驱指针指向s
    s->next = p;
    p->prior->next = s;
    p->prior = s;

    return OK;
}



//自己测试：插入节点q到节点p后方的算法
//实际测试结果：被插入的结点的指针，采用发射-发射-接收-接收，和发射-接收-发射-接收 两种连接方式均可

Status ListInsert_Duln(DuLinkList L,int i,LElemType_DC e)
{
    DuLinkList p,q;
    if(i<1 || i>ListLength_Dul(L) +1)
        return ERROR;
    p = GetElemPtr_Dul(L,i);
    if (!p)
         p = L;

    q = (DuLinkList)malloc(sizeof(DuLNode));
    if(!q)
        exit(OVERFLOW);

    q->data = e;

    q->next = p->next;
    q->prior = p;
    p->next->prior = q;
    p->next = q;

    return OK;


}











//算法2.19
Status ListDelete_Dul(DuLinkList L, int i,LElemType_DC *e)
{
    DuLinkList p;

    if(!(p=GetElemPtr_Dul(L,i)))            //i的值不合法则报错
        return ERROR;


    *e = p->data;               //p指向待删除的结点，p的前序指针的后继指向p的后继，p的后继的前序指针指向p的前序
    p->prior->next = p->next;
    p->next->prior = p->prior;

    free(p);
    p =NULL;

    return OK;
}

void ListTraverse_Dul(DuLinkList L,void(Visit)(LElemType_DC))
{
    DuLinkList p;

    p = L->next;

    while(p!=L)
    {
        Visit(p->data);
        p = p->next;


    }


}

#endif // DUALCYCLELINKEDLIST_C









