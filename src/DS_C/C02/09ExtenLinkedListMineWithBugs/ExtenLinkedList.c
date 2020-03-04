/***********************************

文件夹：C02线性表

文件名：ExtenLinkedList.c

算法：2.20

**********************************/

#ifndef EXTENLINKEDLIST_C
#define EXTENLINKEDLIST_C

#include "ExtenLinkedList.h"

Status MakeNode_E(Link *p,LElemType_E e)    //创建新节点在p所指的位置，e的数据赋值之
{
    *p = (Link)malloc(sizeof(ELNode));          //申请空间
    if(!(*p))
        exit(OVERFLOW);

    (*p)->data = e;
    (*p)->next = NULL;    //后继指针置空

    return OK;
}

void FreeNode_E(Link *p)
{
    free(*p);
    *p = NULL;
}

Status InitList_E(ELinkList *L)
{
    Link p;

    p = (Link)malloc(sizeof(ELNode));
    if(!p)
        exit(OVERFLOW);
    p->next = NULL;

    (*L).head = (*L).tail = p;//p刚才新申请好了空间，现在新建的L列表的头、尾指针均指向p的位置，然后表长赋值为0
    (*L).len  = 0;

    return OK;
}

void ClearList_E(ELinkList *L)
{
        Link p,q;

        p = (*L).head->next;    //如头文件中的定义，ELinkList 是一个struct，由指向头尾部的head/tail指针和常数int构成。指针p指向待删除的L的头部元素的next，即首节点后边的第一个元素

        while(p)                    //当p不等于0，也就是一圈还没有绕回来的时候，重复做如下操作：
        {
            q = p->next;         //q被赋值为p的下一个元素   步进一
            free(p);                    //把p free掉
            p = q;              //q后移到p上，步进一                 如上构成循环
        }

        (*L).head->next = NULL;             //L的头指针的下一个元素置空，防止野指针
        (*L).tail = (*L).head;                     //L 的尾指针置空，防止野指针
        (*L).len = 0;                                   //struct的三个元素都归零、置空，到此清空所有的数据
}

void DestroyList_E(ELinkList *L)
{
    ClearList_E(L);         //经过clear，头结点所指的next已经置NULL，尾指针置NULL。len=0
    free((*L).head);        //进一步释放头结点
    (*L).head = (*L).tail =NULL;    //L的头指针、尾指针这时为了防止野指针继续置空
}

void InsFirst_E(ELinkList *L,Link h,Link s)     //s插在h后
{
     if(h==(*L).tail)
        (*L).tail = h->next;

    (*L).len++;

    s->next = h->next;
    h->next = s;


}

Status DelFirst_E(ELinkList *L,Link h,Link *q)      //删去h指向的结点，用q接受其值
{
    *q = h->next;           //指向指针的指针q指向h的next指针

    if(*q)      //若h有next
    {
        h->next  = (*q)->next;      //h后只有一个节点
        if(!h->next)
                (*L).tail = h;

        (*L).len--;

        return OK;
    }
    return ERROR;
}

void Append_E(ELinkList *L,Link s)          //把s续在L的尾部
{
    int count = 0;

    (*L).tail->next = s;//L的表尾元素的next指针指向指针s所指的元素；

    while(s)                    //s若不指NULL
    {
        (*L).tail = s;          //L表尾指针指向s（新表尾）
        s = s->next;           //s步进至s的尾部                   以上：直到步进至s到底，溢出为NULL；while循环会终止
        count++;                 //计数器步进
    }

    (*L).len += count;     //表的长度增加计数器计的那么多
}

Status Remove_E(ELinkList *L,Link *q)       //删除L的尾节点，并用q接收
{
    Link p;

    if(!(*L).len)               //特殊情况：若L的长度等于零则相应消除野指针并报错
    {
        *q = NULL;
        return ERROR;
    }

    p  = (*L).head;             //p指向头部
    *q  = (*L).tail;            //q指向队尾

    while(p->next!=(*L).tail)           //当p的下一个元素尚未走到队尾的时候
        p = p->next;                        //p循环步进1

    p->next = NULL;                     //经过上边的循环，p已经指向除尾元素外最后一个元素，这时把p的next指针置空
    (*L).tail = p;                             //p已经指向倒数第二个元素。列表的尾部指针这时改为指向p（也就是往前走了一格。抛弃原来的队尾）

    (*L).len--;                                    //L的长度--

    return OK;

}


void InsBefore_E(ELinkList *L,Link *p,Link s)     //把s指的东西插入到p的前边
{
    Link q;

    q = PriorPos_E(*L,*p);          //寻找p的前驱位置
    if(!q)
        q = (*L).head;                    //若p无前驱只有一个节点，那就让q指向表头
    //q现在已经成功指向p的前边
    s->next = *p;   //s的next指针指向p（插在p前）
    q->next = s;    //q也是工作指针，直接让q的next指向s，就完成了大体插入工作
    *p = s;            //p以前指向的位置现在 有变化，直接指向s，防止野指针

    (*L).len++;
}

void InsAfter_E(ELinkList *L,Link *p,Link s)
{
    if(*p == (*L).tail)
        (*L).tail = s;

    s->next = (*p)->next;
    (*p)->next = s;
    *p = s;

    (*L).len++;
}

void SetCurElem_E(Link p,LElemType_E e)
{
    p->data = e;

}

LElemType_E GetCurElem_E(Link p)
{
    return p->data;
}

Status ListEmpty_E(ELinkList L)
{
    if(L.len)
        return FALSE;
    else
        return TRUE;
}

int ListLength_E(ELinkList L)
{
    return L.len;
}

PositionPtr GetHead_E(ELinkList L)
{
    return L.len;
}

PositionPtr GetLast_E(ELinkList L)
{
    return L.tail;
}

PositionPtr PriorPos_E(ELinkList L,Link p)
{
    Link q;

    q= L.head->next;
    if(q==p)
        return NULL;
    else
    {
            while(q->next!=p)
            q = q->next;

    return q;
    }
}

PositionPtr NextPos_E(Link p)
{
    return p->next;
}

Status LocatePos_E(ELinkList L,int i,Link p)
{
    int count = 0;
    p = L.head;//p指针所指的指针“*p”  被赋值为L的头结点

    if(i<0 || i>L.len)
        return ERROR;

    while(count<i)
    {
        count++;
        p = p->next;   //没有够数时，p指针指向的“*p”指针持续   垂直于水平线地   后移
    }

    return OK;                 //这个程序结束的时候，*p指针指向的是第i个元素
}

PositionPtr LocateElem_E(ELinkList L,LElemType_E e,Status(Compare)(LElemType_E,LElemType_E))
{
    Link p = L.head->next;

    while(p && !(Compare(e,p->data)))       //当p不等于NULL且e与p不相等的时候持续做如下步进
        p = p->next;

    return  p;
}

Status ListTraverse_E(ELinkList L,void(Visit)(LElemType_E))
{
    Link p;
    int j;

    p = L.head->next;

    for(j=1;j<=L.len;j++)
    {
        Visit(p->data);
        p = p->next;
    }
    return OK;
}

//算法2.9的改写

Status ListInsert_L_E(ELinkList *L,int i,LElemType_E e)
{
    Link h,s;

    s = &e;

    LocatePos_E(*L,i,h);

    InsFirst_E(L,h,s);          //s插在h后边

    return OK;
}

Status ListDelete_L_E(ELinkList *L,int i,LElemType_E *e)
{
    Link p,q;

    if(i<1  ||  i>(*L).len)
        return ERROR;

    LocatePos_E(*L,i-1,&p);
    DelFirst_E(L,p,&q);

    *e = q->data;
    free(q);
    q = NULL;

    return OK;
}











#endif // EXTENLINKEDLIST_C













