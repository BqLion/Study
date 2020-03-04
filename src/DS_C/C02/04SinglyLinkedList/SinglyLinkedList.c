/************************************

文件夹：C02/04SinglyLinkedList

文件名：SinglyLinkedList.c

算法： 2.8/2.9/2.10/2.11

************************************/

#ifndef SINGLYLINKDELIST_C
#define SINGLYLINKDELIST_c

#include "SinglyLinkedList.h"                   //线性表

Status InitList_L(LinkList *L)                  //初始化一个单链表，参数是LinkList 指向LNode节点的指针型的
{
    (*L) = (LinkList)malloc(sizeof(LNode));     //malloc返回一个NULL形的指针，指向申请的内存的头结点，并赋值给*L
    if(!(*L))
        exit(OVERFLOW);                         //如果*L等于0，做如下操作（返回溢出）
    (*L)->next = NULL;                          //单链表*L的next等于NULL

    return OK;
}

Status ClearList_L(LinkList L)                  //清除单链表，但保存头结点
{
    LinkList pre,p;

    if(!L)
        return ERROR;                           //如果单链表=0，即为空，则返回ERROR。

    pre = L ->next;                             //赋值pre等于头结点后边的第一个节点的值

    while(pre)                                  //当pre不等于0的时候，做如下循环：
    {                                           //把pre的下一个值赋值为p，然后把pre删了，然后如此后推
        p = pre->next;
        free(pre);
        pre = p;
    }
    L->next=NULL;                               //斩断头结点与列表的联系
    return OK;
}

void DestroyList_L(LinkList *L)                 //销毁所有节点
{
    LinkList p = *L;

    while(p)
    {
        p = (*L)->next;
        free(*L);
        (*L) = p;
    }
}

Status ListEmpty_L(LinkList L)          //链表探空
{
    if(L!=NULL && L->next==NULL)        //链表存在且只有头结点（链表不为空，但第一个头结点的next是null）
        return TRUE;
    else
        return FALSE;
}

int ListLength_L(LinkList L)     //测量链表长度的函数
{
    LinkList p;
    int i;

    if(L)                             //若链表不为零则做以下操作
    {
        i=0;
        p = L->next;                   //i是计数器，指针每后移一次就自增1；
        while(p)                      //p初始值是第一个元素，当p不为零的情况下（还没跑出界），一直步进1
        {
            i++;
            p = p->next;
        }
    }
    return i;
}

//算法2.8
Status GetElem_L(LinkList L,int i,LElemType_L *e)           //获取链表中第i个元素的值，并放入e中   注意辨析与顺序表的区别
{
    int j;
    LinkList p = L->next;          //顺序表形的指针p的地址值等于单链表的首节点的next（即第一个节点）

    j=1;
    p=L->next;

    while(p && j<i)            //当p不为空（未溢出）且还没到i处
    {
        j++;
        p = p->next;            //计数器加一，p步进一
    }

    if(!p||j>i)                 // 若p=null或者计步器显示已经超过i了还没有找到，即第i个元素不存在
        return ERROR;

    *e = p->data;                  // 若满足以上条件，找打了e，则把p所指的结构体的数据项赋值给e的数据项

    return OK;
}                                   //链表查找数据需要挨个后移查找，不能像顺序表那样直接定位


int LocateElem_L(LinkList L,LElemType_L e,Status(Compare)(LElemType_L,LElemType_L))     //定位元素的函数，功能：返回表L的第一个符合compare关系的元素位序
{
    int i;
    LinkList p;

    i= -1;                         //若i不存在则在最后返回此值-1.若存在则后边会被覆盖为其他值

    if(L)                         //若 L不等于0即存在，则做后边的操作：i初始化为0，p指向L的第一个节点
    {
        i = 0;
        p = L->next;

        while(p)        //当指针p不等于NULL的时候，即指针还未溢出的时候，循环做如下动作：
        {
            i++;

            if(!Compare(e,p->data))         //若两者不匹配，则p指针持续步进
                p = p->next;
            else
                break;
        }
    }

    return i;
}

/*银行排队算法中，此处两个函数不能直接使用，原因是结构不能直接比较*/

#ifndef BANKQUEUING_C

Status PriorELem_L(LinkList L,LElemType_L cur_e,LElemType_L *pre_e)         //提取前驱元素的函数。表L，把元素cur_e的前驱元素赋值给*pre_e
{
    LinkList p,suc;

    if(L)                   //当L存在，执行如下操作
    {
        p = L->next;        //指针p等于头结点后边第一个元素的地址

        if(p->data!=cur_e)  //cur_e如果是第一个节点的话则报错，因为第一个几点无前驱节点
            {
                while(p->next)  // 如果p节点有后继（不为零），则循环做如下操作
                {
                    suc = p->next;
                    if(suc->data == cur_e)     //指针SUC指向p节点的后一个节点，若后一个节点的值等于cur_e
                    {
                        *pre_e = p->data;      //把p指针所指的值赋值给pre_e
                        return OK;             //并返回1
                    }
                    p = suc;                   //p再往后挪1，指向suc即cur_e所指的位置
                }

            }
    }
    return ERROR;                             //开头那几个特殊情况的if，返回错误
}

Status NextElem_L(LinkList L,LElemType_L cur_e,LElemType_L *next_e)     //取next元素的值，赋值给next_e
{
    LinkList p,suc;                         //节点形指针p和suc

    if(L)                                   //表L不为空的话做如下操作
    {
        p = L->next;                        //p指向头结点

        while(p && p->next)                 //当p和p->next均不为零的情况下循环做如下操作
        {
            suc = p->next;
            if(suc && p->data == cur_e)    //当suc不等于null（不溢出），且p->data等于cur_e的话（即成功找到了 ）
               {
                *next_e=suc->data;          //把suc指针所指的data赋值给*next_e
                return OK;
               }
                if(suc)                             //把p的位置挪到suc上，即p步进1，回到循环体首位后suc步进2.if的条件时suc！=null，也就是一直要循环到指针跑出列表。
                    p = suc;
                else
                    break;
         }
    }

    return ERROR;
}
#endif


/*算法2.9*/

Status ListInsert_L(LinkList L,int i ,LElemType_L e)           //增函数，把表L的第i个元素前插入元素e
{                                                              //链表的插入比顺序表简单，只用断开、连接相应的指针即可，不用把增加元素的后续一列元素全部移位
        LinkList p,s;
        int j;

        p=L;
        j=0;

        while(p && j<i-1)                       //寻找第i-1个节点的循环，条件是头指针p不等于null即未溢出，且计数器j<i-1;
        {
            p = p->next;                        //p持续步进
            ++j;                                //j计数器自增1。   i++是先引用后自增1；++i是先自增1再引用。
        }                                       //循环结束的时候，p指针指向i-1节点

        if(!p || j>i-1)                         //如果指针p溢出或者j计步器显示跑过了，返回错误
            return ERROR;

        s = (LinkList)malloc(sizeof(LNode));    //指针s指向 类型为LinkList形的 内存空间，size是一个Lnode
        if(!s)
            exit(OVERFLOW);                         //若分配的s=0，则报错
        s->data = e;                                 //插入操作的核心步骤
        s->next = p->next;                          //把待插入的数值赋值给刚分配空间的指针s的data位，然后先将s的next指针指向p的后一位，再把p的指针指向s，就构成了连接。注意要先新建指针，再断开。
        p->next = s;

        return OK;
}


//算法2.10 删除链表的元素

Status ListDelete_L(LinkList L,int i,LElemType_L *e)           //删除函数。作用是删除表L的第i个元素，并将删除的元素放在*e里
{
    LinkList pre,p;
    int j;

    pre = L;     //pre等于链表L的头结点
    j = 1;

    while(pre->next && j<i)             //当pre的next不等于0（还未溢出表）且计数器j显示还未跑过的时候做如下循环
    {
        pre = pre->next;                //pre指针持续滑动步进直至pre指向第i个目标元素的前一个元素
        ++j;                            //j计数器自增1
    }

    if(!pre->next || j>i)       //特殊情况，pre跑溢出了或者计数器j显示已经跑过i了，则报错
        return ERROR;


    //经过如上的while循环，指针pre已经指向了第i-1个元素的位置，

    p = pre->next;                  //工作指针p直接指向pre元素的后继元素，美滋滋

    //工作指针p指向了待删除元素，pre指针指向了待删除元素的前一个元素，两指针各就各位

                                    //如下三句是本算法的核心操作
    pre->next = p->next;            //待删除元素的前一个元素的后即指针直接跳过待删除元素，指向待删除元素的后继元素。这一步事实上已经完成了链表中的删除操作，遍历的时候不会再遍历到待删除元素上
    *e = p->data;                   //把待删除节点的元素值赋值到变量e里边作为保存
    free(p);                        //释放p指针指向的空间

    return OK;
}


Status ListTraverse_L(LinkList L,void(Visit)(LElemType_L))          //遍历函数，把表L遍历一遍
{
    LinkList p;

    if(!L)
        return ERROR;           //参数传递进来的表L若为空就返回ERROR
    else
        p = L->next;            //若情况正常L不为空，p就指向头结点


    while (p)                   //当p不为NULL即还没溢出的时候,重复做如下操作
    {
        Visit(p->data);         //遍历visit p的所有元素
        p = p->next;            //p步进1
    }

    return OK;
}

//算法2.11 头插法建立链表

Status CreateList_HL(FILE *fp,LinkList *L,int n)
{
    int i;
    LinkList p;
    LElemType_L tmp;

    *L = (LinkList)malloc(sizeof(LNode));   //建立表L的头结点
    if(!(*L))                               //如果L=0则报错
        exit(OVERFLOW);
    (*L)->next = NULL;                        //表L的头结点的next等于NULL，建立了一个空表只有头结点

    for(i=1;i<=n;++i)                       //++i即先自增1，后引用i，所以也就是i第一次引用的时候就已经是2了
    {
        if(Scanf(fp,"%d",&tmp)==1)          //如果能从fp中扫描到东西的话
        {
            p = (LinkList)malloc(sizeof(LNode)); //给指针p分配一个结点的内存空间
            if(!p)
                exit (OVERFLOW);                //如果分配内存不成功p=0则返回溢出

            p->data = tmp;                      //头插法的关键步骤：将之前scanf到的数据tmp赋值给p指针的data项
            p->next = (*L)->next;               // 然后将待插入的结点p的next指针指向头结点的next
            (*L)->next = p;                     //然后将头结点的next指针指向p，就像普通的insert函数insert一个数据一样
        }
        else
            return ERROR;
    }
    return OK;
}

Status CreateList_TL(FILE *fp,LinkList *L,int n)    //尾插发建立一个链表
{
    int i;
    LinkList p,q;
    LElemType_L tmp;

    *L = (LinkList)malloc(sizeof(LNode));          //待建立的链表L指针*L分配一个sizeof LNode的 内存空间
    if(!(*L))                                      //malloc之后紧跟的标准语句，防止内存分配失败
        exit(OVERFLOW);
    (*L)->next = NULL;                             //建立表*L的头结点

    for(i=1,q=*L;i<=n;++i)                        //计数器i初始化为1，指针q指向头结点*L【因为是初始化，所以不得不指向头结点，但是抽象意义上指针q指向的是尾节点】
    {
        if(Scanf(fp,"%d",&tmp)==1)
        {
            p = (LinkList)malloc(sizeof(LNode));  //指针p指向一个新分配的LNode大小的内存空间的首部。与指针q的形状相似
            if(!p)                                 //malloc之后的标准语句，如果p=NULL代表内存分配失败，返回OVERFLOW
                exit(OVERFLOW);
            p->data = tmp;                          //【理解在这里卡过】读到的tmp值赋值给p的data项，p现在指向的是待插入项
            q->next = p;                            //【q这个指针指向的是队尾元素！】把q的next指针指向p
            q = q->next;                            // 然后q步进1，指向新的队尾元素
        }
        else
            return ERROR;
    }

    q->next = NULL;                                 //插入工作完成后，q的next指向null，即队尾最后一个元素的next指针置空

    return OK;

}

#endif // SINGLYLINKDELIST_C






























