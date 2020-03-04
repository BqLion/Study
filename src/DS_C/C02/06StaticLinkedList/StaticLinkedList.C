/********************************************

文件夹：C02/06StaticLinkedList.c

文件名：StaticLinkedList.c

算法：2.13,2.14,2.15,2.16

******************************************/

#ifndef STATICLINKEDLIST_C
#define STATICLINKEDLIST_C

#include"StaticLinkedList.h"                //包含头文件

//算法2.14

void InitSpace_SL()             //首先初始化备用空间
{
    int i;                                 //i是个计数器

    for(i=0;i<MAXSIZE-1;i++)        //循环999次如下操作
        SPACE[i].cur =  i+1;              //把金属皮带的第二行的元素都赋值为计数器+1，即所有元素的下标项都初始化置为下一个元素的位序

    SPACE[MAXSIZE-1].cur = 0;//最后一位元素的下标置为空
}

//算法2.15

int Malloc_SL()         //从备用空间申请节点空间  。。 如上的函数已经申请了备用空间999个，但是如果静态链表需要使用的话需要逐个申请
{
    int i ;

    i = SPACE[0].cur;                                    //i被赋值为头结点的next，即第一个元素

    if(SPACE[0].cur)                                     //如果第一个space备用空间的下标不等于0（空间未被分配完）
    {
        SPACE[0].cur = SPACE[i].cur;            //头结点的next被赋值为原第一个节点的next，原第一个节点被删去，代表已经申请成功，需要被使用了
        return i;                                             //返回i的值，i即刚才申请的头结点的next值，即申请成功地原第一个节点的位序
    }
    else
        return 0;
}
//Malloc_SL就是从最开始初始化的1000个备用空间中按照从头到尾的顺序，取第一个元素出来，准备要使用它

//算法2.16

void Free_SL(int k)             //回收K节点的空间
{
    SPACE[k].cur = SPACE[0].cur;    //k节点的next被赋值为头结点的next
    SPACE[0].cur = k;                       //头结点的next被赋值为k，这两步等于把k节点按头插法插入了SPACE链表中，即从使用空间回到了备用空间，与malloc_SL是相反的操作
}

Status InitList_SL(SLinkList *H)        //初始化静态链表的函数，H为头结点指针（SLinkList经过def等价于int，这里就相当于是定义了 一个int形的指针）
{                                                        //不管定义的是一个指向静态链表的或者指向节点或者指向更复杂的结构体的指针，指针一直是一个八位的“门牌号”，里边就存了一个地址信息，指针不因指向的数据类型不同而区分大小
    *H = Malloc_SL();                         //指向 静态链表（本特例就是int形）的指针H的所指的内存地址上存储的数据，被赋值为MALLOC_SL函数返回的【备用空间的第一个空闲节点的位序】

    if(!(*H))                                        //如果指针指向的地址存储的数据项为空，则报错（所有的malloc函数都会紧跟的一句话）
        exit(OVERFLOW);                    //报错“OVERFLOW”

    SPACE[*H].cur = 0;                    //备用空间的“被指针H所指的那个元素“的next项被置为0，不再与备用空间SPACE关联”

    return OK;
}

Status ClearList_SL(SLinkList H)
{
    int p,q;

    if(!H)          //如果H不等于0则报错
        return ERROR;

        p = SPACE[H].cur;                           //复习SPACE定义：SPACE是一个componet形变量，component是一个拥有1000个 静态链表元素struct 静态链表备用空间
                                                                //p是个整形变量，在静态链表中充当“指针”的角色，p被赋值为第H个元素的cur变量，也就是第H个元素的下一个元素的位序，顺序的话，就是比H大1的数字

        while(p)                                           //当p不等于0的时候,即p指向的元素不为空的时候，循环做如下操作
        {
            SPACE[H].cur = SPACE[p].cur;      //第2个元素的next是3；第3个 元素的next是4。直接把第二个元素的next赋值为第三个元素的next也就是4，跳过第三个，相当于指针绕开中间元素，也就是在表里删除了中间元素
            Free_SL(p);                                     //第二个元素的next已经被赋值为4了，第三个元素可以被free掉了
            p = SPACE[H].cur;                         //H的next已经发生了变化，第2个元素的next已经是4了，所以p现在由3改为被赋值为4，从而使循环体可以run起来
        }

        return OK;
}

void DestroyLsit_SL(SLinkList *H)
{
    ClearList_SL(*H);           //清空静态链表里的元素

    Free_SL(*H);            //把头结点的存储空间也还给SPACE

    *H = 0;                //头结点置0；
}

Status ListEmpty_SL(SLinkList H)
{
    if(H && !SPACE[H].cur)              //在H不等于0，且H节点的next等于0，的情况下，返回真，否则返回假。即，若只有头结点则返回时空的，否则返回非空
        return TRUE;
    else
        return FALSE;
}

int ListLength_SL(SLinkList H)
{
    int count;
    int p;
    if(!H)
        exit(OVERFLOW);             //H等于0的时候返回错误

    count = 0;
    p = SPACE[H].cur;               //p等于头结点后的第一个节点

    while(p)                            //当p没有越界的时候循环步进，计数器同时自增1
    {
        count++;
        p = SPACE[p].cur;
    }
    return count;
}

Status GetElem_SL(SLinkList H,int i,LElemType_S *e)
{
    int count,p;

    if(!H || i<1 || i>MAXSIZE-2)
        return ERROR;                   //异常情况先排除掉

    count = 0;
    p = SPACE[H].cur;           //计数器置零，工作“指针”指向第一个元素

    while(p)                        //指针p没有溢出的情况下，计数器循环自增1，直到计数器等于要get元素的位序，这时e被赋值为元素的data
    {
    count++;

        if(count ==i)
        {
            *e = SPACE[p].data;
        return OK;
        }

    p = SPACE[p].cur;
    }
}

//算法2.13

int LocateElem_SL(SLinkList H,LElemType_S e)
{

    int k,count;

    count = 1;

    if(H && SPACE[H].cur)               //如果传进来的H表表头和后继元素都存在说明此表非空，可做如下操作：
    {
        k = SPACE[H].cur;                   //参数k被赋值为头结点的next，（可理解为指向首个节点的指针）

        while(k &&SPACE[k].data!=e)     //当指针k不为零（未溢出）且 步进的指针k所指的data的时候说明还没有到位，这时候指针要一直步进
            {
                count ++;
                k = SPACE[k].cur;
            }

            if(k)
                return count;               //经历了如上循环，如果k不等于0（说明没有吧k循环的溢出了），return 计数器所显示的数字
    }
    return 0;
}

Status PriorElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *pre_e)           //前置元素
{
    int  p,q;

    if(H)
    {
        p = SPACE[H].cur;               //p指针等于第一个元素的下标

        if(p && SPACE[p].data!=cur_e)   //如果指针p不等于0，且SPACE的data还没有指到cur_e
        {

            q = SPACE[p].cur;            //q等于p指针的下一个元素的下标

            while(q && SPACE[q].data!=cur_e)    //q指针等于p指针的下一个
            {
                p = q;
                q = SPACE[q].cur;
            }

                if(q)
                {
                *pre_e = SPACE[p].data;
                return OK;
                }
        }
    }
    return ERROR;
}

Status NextElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *next_e)       //取cur_e的下一个元素next_e
{
    int p;

    if(H)
    {
        p = SPACE[H].cur;                               //若传进来的表H不等于0，“指针”（下标）p被赋值为H的头结点

        while(p && SPACE[p].data != cur_e)  //当p没有步进至溢出，且p指针所指的元素的data不等于cur_e的时候，p持续步进
            p = SPACE[p].cur;

        if(p && SPACE[p].cur)       //上边那个循环会在SPACE[p].data 等于cur_e或者p=0的时候停止循环，这里需判断p和p。next是不是等于零，若等于零说明所指的是最后一个节点，这种情况是不存在后继节点的，需要用下一个else报错，否则，就出去p所指的元素的下一个元素就OK了
        {
            p = SPACE[p].cur;
            *next_e = SPACE[p].data;
            return OK;
        }
    }
    return ERROR;
}

Status ListInsert_SL(SLinkList H,int i,LElemType_S e)
{
    int count,k,p;

    if(!H)                  //如果链表不存在返回错误
        return ERROR;

    if (i>0)
    {
        count = 0;
        k = H;                  //k指向头结点

        while(k && count<i-1)           //当k指针还没有跑出界而且count计数器显示还没有到位的时候
        {
            count ++;
            k = SPACE[k].cur;               //计数器循环自增1，k指针循环步进往后挪
        }

    if(k)               //上边那个循环结束了，两种结果：1.k指到改指的位置 2.k经过遍历没找到该着的东西，最后溢出为0，这个if就是为了排除k=0的情况
    {
        p = Malloc_SL();    //k找到该指的位置了，动态申请内存分配
        if(!p)                      //如果p等于0则报错  即：如果内存分配失败，返回错误
            return ERROR;

        SPACE[p].data =e;                   //p是新申请的空间，把e的数值赋给他
        SPACE[p].cur = SPACE[k].cur;        //p的指针指向要插入的元素的next，思路和链表插入时一至
        SPACE[k].cur = p;                           //前一个元素的next指向p

        return OK;
        }
    }
    return ERROR;
}

Status ListDelete_SL(SLinkList H,int i,LElemType_S *e)
{
    int count,k,p;

    if(!H)
        return  ERROR;              //链表不存在要报错

    if(i>0)
    {
        count = 0;
        k = H;                     //k指向链表H的头结点

        while(k && count <i-1)      //寻找删除元素的前一个位置
        {
            count ++;
            k = SPACE[k].cur;               //没找到的话计数器自增1，指针k也跟着循环步进前移
        }

    if (k && SPACE[k].cur)          //经过上述的循环找到了第i-1个元素的位置，这时排除掉i-1是在最后一个位置，后边没有可删的了
    {
        p = SPACE[k].cur;    //k指向i-1,p指向i 这个被删除的元素的位置
        *e = SPACE[p].data; //把要删除的p的位置的data赋值给e，然后就可以执行接下来的删除操作了。思路和单链表是一样的
        SPACE[k].cur = SPACE[p].cur; //前一个节点的next指针直接指向本节点的next，直接跳过本节点while等于删除了本节点
        Free_SL(p);             //把p所指的元素所占据的SPACE 空间给释放了

        return OK;
    }
    }

    return ERROR;
}

Status ListTraverse_SL(SLinkList H,void(Visit)(LElemType_S))
{
    int p;

    if(!H)
        return ERROR;               //若链表不存在或为空返回错误

    p = SPACE[H].cur;               //p"指针"被赋值为头结点

    while (p)                       //p还不为0还没溢出的时候循环做如下的操作
    {
    Visit(SPACE[p].data);       //访问指针所指的元素的数据
    p = SPACE[p].cur;           //指针向前步进1

    }
    return OK;
}

#endif // STATICLINKEDLIST_C


















