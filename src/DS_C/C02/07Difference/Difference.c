/*********************************

文件夹：C02、07Difference

文件名：Difference.c

算法：2.17

********************************/

#ifndef DIFFERENCE_C
#define DIFFERENCE_C

#include "Difference.h"

void difference(SLinkList *S,LElemType_S A[],int len_A,LElemType_S B[],int len_B )          //一个工作静链表S，两个数组A/B扮演为集合。
{
    int i,j;                                //计数器两个
    int r,p,k;                          //工作指针3个
    LElemType_S b;

    InitSpace_SL();                 //初始化SPACE空间
    *S = Malloc_SL();               //给S工作表申请动态空间
    r = *S;                             //工作指针r指向当前工作表S的尾部（也就是头部！因为只有一个元素现在）
    SPACE[r].cur = 0;               //尾节点的“指针”要置零

    for(j = 0;j<len_A;j++)              //把集合A先如数录入工作表S中
    {
        i = Malloc_SL();                    //分配动态空间，i指向本工作表的头部
        SPACE[i].data = A[j];           //集合A从首元素数据项开始依次归队，用的是尾插法；
        SPACE[r].cur = i;                   //队列尾部的next指针指向i所指的位置（尾插成功）
        r = i;                                      //r指针所指的元素从原队尾变为现在的新队尾也就是i所指的位置
    }
    SPACE[r].cur = 0;                   //尾指针置空


    for(j=0;j<len_B;j++)            //准备把B数组里的元素都遍历一遍
    {
        b = B[j];                           //节点元素b被赋值为数组B的头元素
        p = *S;                             //p被赋值为列表指针S所指的值（即集合A的头结点）
        k = SPACE[*S].cur;          //k指向集合A的第一个节点
        while(k && SPACE[k].data !=b)       //循环条件：k未溢出且k所指的元素的data值 不等于容器b里装的B数组里的数值
        {
            p = k;                                            //当第一个元素B不等于元素A的时候，指向A组的两个指针持续步进，直到把A组的所有元素都遍历一遍
            k = SPACE[k].cur;
        }
        if(!k)                                                      //如果如上的遍历过程完结了，还没有在A里找到B，则k就溢出，出现这种情况就把B插入进A里
        {
        i = Malloc_SL();                                    //i对准新申请的结点
        SPACE[i].data = b;                                 //b赋值给新申请的结点的data
        SPACE[i].cur = SPACE[r].cur;                //新申请的结点是新的尾部结点，它的next应该等于原队列尾部结点的next
        SPACE[r].cur = i;                                   //原结点的next现在指向i
        }
        else
            {
                SPACE[p].cur = SPACE[k].cur;
                Free_SL(k);
                if(k = r)
                    r = p;
        }
        }
    }

#endif // DIFFERENCE_C
















