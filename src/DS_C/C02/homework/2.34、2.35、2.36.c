/*2.34 异或指针链表：
思路：每个LNode都存在一个Single指针指向它。data域存的是data，指针域存的是前后节点的single指针的异或，异或单独用一个函数表达。边界条件：若前或者后没有single指针则存的是NULL。
*/
//开始时间：14:27 结束时间：20:31
#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//数据结构定义

typedef char XElemType;             //数据类型是char形
typedef struct XorNode              //定义节点的数据结构，由data和指针LRPtr组成
{
    XElemType data;
    struct XorNode *LRPtr;
}XorNode;

typedef XorNode* XorPointer;   //指向节点的指针
typedef struct                              //定义链表的数据结构，由左右两个指向节点的指针构成
{
    XorPointer Left;
    XorPointer Right;
}XorLinkedList;

typedef XorLinkedList* Xor;     //Xor是指向链表的指针

//各种函数的类型定义

Status Algo_2_34_1(Xor L,int mark);
Status Algo_2_34_2(Xor L,int mark);
Status Algo_2_35(Xor L,int i,XElemType e);
Stauts Algo_2_36(Xor L,int i,char *e);
XorPointer XorP_XorL(XorPointer p,XorPointer q);
Status Init_XorL(Xor *L);
Stauts Create_XorL(Xor L,int n,XElemType Data[]);
XorPointer Prior_Next_Ptr_XorL(Xor L,XorPointer cur,int mark);
int Length_XorL(Xor L);
XorPointer GetElemPtr_XorL(Xor L,int i);

int main(int argc,char **argv)
{
    Xor L;                                                          //定义了一个表，一个数据类型，一个n
    XElemType e;
    int n = 9;
    XElemType *data = "123456789";      //节点元素形的指针的值被赋值为这个

    Init_XorL(&L);                                      //初始化，创建表，顺序输出，逆序输出。
    Craete_XorL(L,n,data);
    printf(" 2.34验证...\n");
    printf("顺序输出L...");
    Algo_2_34_1(L,0);
    printf("\n");
    printf("逆序输出...\n");
    Algo_2_34_1(L,1);
    printf("\n\n");

    printf("题2.35验证...\n");         //插入后输出，删除后输出
    Algo_2_35(L,5,'*');
    printf("插入‘*’为L的第五个节点后顺序输出...\n");
    Algo_2_34_2(L,0);
    printf("\n\n");

    printf("题2.36验证...\n");
    Algo_2_36(L,5,&e);
    printf("删除L 的第五个节点‘%c’后逆序输出 ...\n",e);
    Algo_2_34_2(L,1);
    printf("\n\n");

    return 0;
}

//初始化异或指针链表L

Stauts Init_XorL(Xor *L)
{
    *L = (Xor)malloc(sizeof(XorLinkedList));
    if(!(*L))
        exit(OVERFLOW);

    (*L)->Left = NULL;                  //异或指针表的本身结构比较简单：一个左指针一个右指针，一个表头，给表头分配空间，左右指针置空即可完成初始化
    (*L)->Right = NULL;

    return OK;

}

//创建异或指针链表L

Status Create_XorL(Xor L ,int n,XElemType Data[])
{
    int i;
    XorPointer pre_l,pre_m,pre_r;

    pre_l = pre_m = NULL;           //前中后三个指针，前中置空，后指向分配的空间

    for(i=1;i<=n;i++)
    {
        pre_r = (XorPointer)malloc (sizeof(XorNode));
        if(!pre_r)
            exit(OVERFLOW);

        pre_r->data = Data[i-1];            //后指针的data域从数组中取元素
        if(i==1)
            L->Left = pre_r;               //首次执行，将L->Left 左指针指向pre_r这个元素上

        //以上是列表创建的前边界动作
        //pre_r 从数列中拿数，然后把pre_r安放进队列，即现在在队列尾部的m的指针域要做相应操作，将r所指的元素拉进来，拉进来之后，队列Right指针要变化，指向新的对列尾，然后新的对列尾的指针域也要做相应调整，然后l m r三个指针按顺序步进，开始新一轮循环

        if(pre_m)
            pre_m->LRPtr = XorP_XorL(pre_l,pre_r);  //pre_m经过第一次循环后步进1不为空了，也就是从第二次循环的时候开始，作为主要操作指针的pre_m（居中）所指的元素的指针域可以被赋值为pre_l 和pre_r的异或。
        L->Right =pre_r;
        pre_r->LRPtr = XorP_XorL(pre_m,NULL);
        pre_l = pre_m;
        pre_m = pre_r;
    }

    return  OK;
}

//获取当前节点cur的前驱mark=0或后继mark=1

XorPointer Prior_Next_Ptr_XorL(Xor L,XorPointer cur,int mark)
{
    XorPointer p_l,p_m,p_r;

    if(mark!=1 && mark!=0)
        return NULL;

    if(mark == 1)
    {
        p_l = NULL;//       -1
        p_m = L->left;//            0

        while(p_m!=cur)
        {
        p_r = XorP_XorL(p_l,p_m->LRPtr);    //1            //异或指针链表中表示p_m的next的方法：求A,B的异或，其中B等于A+C，所以异或就是C,也就是next元素
        p_l = p_m;
        p_m = p_r;              //三个指针不断步进,直到p_m等于cur元素，这时返回cur的下一个元素就OK，也就是【异或（p_l、p_m的PTR）】
        }

        p_r = XorP_XorL(p_l,p_m->LRPtr);

        return p_r;
    }

    if(mark==0)         //从右向左，求前驱，思路是同理的，求（p_r 和 p_m‘PTR）的异或
    {
    p_m = L->Right;         //边界条件
    p_r = NULL;
    while(p_m!=cur)
    {
        p_l = XorP_XorL(p_r,p_m->LRPtr);
        p_r = p_m;
        p_m = p_l;
    }

    p_l = XorP_XorL(p_m->LRPtr,p_r);

    return p_l;
    }
}

//(05)获取L的长度

int Length_XorL(Xor L)
{
    int count;
    XorPointer p,pre,psuc;

    if(!L)
        exit(OVERFLOW);

    count = 0;
    pre = NULL;
    p = L->Left;

    while(p)
    {
        count++;
        psuc = XorP_XorL(pre,p->LRPtr);
        pre = p;
        p = psuc;               //持续步进至队列尾部，count不断++最后返回count。 最后的边界条件是：倒数第二个和最后一个左右的异或，最后一个左不说，右是NULL，所以异或是NULL，p等于NULL，循环终止退出。
    }
    return count;
}

//（返回指向第i个节点的指针）

XorPointer GetElemPtr_XorL(Xor L,int i)
{
    int count;
    XorPointer p,pre,psuc;          //左中右三个指针

    if(!L || !L->Left)
        return ERROR;

    if(i<1)
        return ERROR;

    count =1;                   //计数器从1开始算，左置空，中为1，右为1的next，在异或表里就是中的左右 与左的异或，结果得右。用这种方式与依次步进，得到待指的元素。
    pre = NULL;
    p =  L->Left;

    while (count<i && p)
    {
        psuc = XorP_XorL(pre,p->LRPtr);
        pre = p;
        p = psuc;
        count++;
    }
    return p;
}

//输出L，mark表示输出方向
Status Algo_2_34_1(Xor L,int mark)
{
    XorPointer cur;

    if(mark!=1 && mark !=0)
        return ERROR;

    if(!L || !->Left)
        return ERROR;

    if(mark==0)
    {
        cur = L->Left;
        do
        {
            printf("%c ",cur->data);
            cur = Prior_Next_Ptr_XorL(L,cur,!mark);
        }while(cur);
    }

    if(mark==0)
    {
        cur = L->Left;
        do
        {
        printf("%c ",cur->data);
        cur = Prior_Next_Ptr_XorL(L,cur,!mark);
        }while(cur);
    }
    return OK;
}

//输出L，mark表示输出方向：
//不借助前驱后继函数遍历链表
Status Algo_2_34_2(Xor L,int mark)
{
    XorPointer p_l,p_m,p_r;

    if(mark!=1 && mark!=0)
        return ERROR;

    if(!L && ！L->Left)
        return ERROR;           //如果L或者L的头元素为NULL 则返回错误

    if(mark == 0)
    {
        p_l =NULL;
        p_m = L->Left;

        while(p_m)
        {
            printf("%c ",p_m->data);
            p_r = XorP_XorL(p_l,p_m->LRPtr);
            p_l = p_m;
            p_m = p_r;
        }
    }

    if(mark == 1)
    {
    p_m = L->Right;
    p_r = NULL;

    while(p_m)
    {
        printf("%c ",p_m->data);
        p_l = XorP_XorL(p_m->LRPtr,p_r);
        p_r = p_m;
        p_m = p_l;
    }
    }
    return OK;
}

//将元素e插入到第i个节点之前

Status Algo_2_35(Xor L,int i,XElemType e)
{
        XorPointer s,i_pre_pre,i_pre,i_suc;

        if(!L)
        return ERROR;

        if(i<1 || i>Length_XorL(L)+1)
            return ERROR;

        s = (XorPointer)malloc(sizeof(XorNode));
        if(!s)
            return OVERFLOW;
        s->data = e;

        i_cur = GetElemPtr_XorL(L,i);
        i_pre = GetElemPtr_XorL(L,i-1);
        i_pre_pre = GetElemPtr_XorL(L,i-2);         //三个工作指针指向中，前一，前二。

        if(!i_cur)          //如果要插入的位序这里是空，则需验证前一个位序是否为空，如果前边一个位序是空，则说明链表为空，插入为首节点，如果前一个位序存在，则证明i-1是最后一个元素，i刚好出界，这是用尾插法
        {
            if(!i_pre)          //如果前一个位序为空，则是空表，头插
            {
                s->LRPtr = NULL;
                L->Left = s;
            }
            else                //如果前一个位序不为空，则i刚好溢出在队列尾，尾插法即可
            {
                s->LRPtr = i_pre;//s的指针域应该是i_pre和NULL的异或，应该也还是i_pre,这是队列尾部元素的特征
                i_pre->LRPtr = XorP_XorL(i_pre_pre,s);//就跟链表一样，第一步是新引，第二部是连上
            }

        L->Right = s;
        }
        else
        {
        i_suc = XorP_XorL(i_pre,i_cur->LRPtr);//next指针赋值为i位序的下一个，异或的运算结果是next，NULL，代表的是cur的next元素，也是队列尾元素

        s->LRPtr = XorP_XorL(i_pre,i_cur);//s的指针域被赋值为pre和cur之间的那个元素，即插入元素已经把指针引出，对着cur，下一步是原pre元素指针域的调整

        if(!i_pre)
            L->Left = s;
        else
            i_pre ->LRPtr = XorP_XorL(i_pre_pre,s);
        }
    return OK;
}

//删除第i个节点，并用e接受节点中元素值
Status Algo_2_36(Xor L,int i,char *e)
{
    XorPointer i_pre_pre,i_pre,i_cur,i_suc,i_suc_suc;

    if(i<1 || i<L.length_XorL(L))
        return ERROR;

    if(!L ||!L->Left)
        return ERROR;

    i_cur = GetElemPtr_XorL(L,i);
    *e = i_cur->data;

    i_pre = GetElemPtr_XorL(L,i-1);
    i_suc = GetElemPtr_XorL(L,i+1);

    if(!i_suc)
    {
        L->Right = i_pre;

        if(!i_pre)
            L->Left = NULL;
        else
            i_pre->LRPtr = Xor}P_XorL(i_pre->LRPtr,i_cur);
    }
    else
    {
        if(!i_pre)
        {
            L->Left = i_suc;
            i_suc->LRPtr = XorP_XorL(i_cur,i_suc->LRPtr);
        }
    else
    {
    i_pre_pre = XorP_XorL(i_pre->LRPtr,i_cur);
    i_suc_suc = XorP_XorL(i_cur,i_suc->LRPtr);
    i_pre->LRPtr = XorP_XorL(i_pre_pre,i_suc);
    i_suc->LRPtr = XorP_XorL(i_pre,i_suc_suc);
    }
    }
    free(i_cur);
    i_cur = NULL;
    return OK;
}






