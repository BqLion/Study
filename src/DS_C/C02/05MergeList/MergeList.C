/*****************************************************

文件夹：C02/05MergeList

文件名：MergeList.c

算法：2.12

******************************************************/

#ifndef MERGELIST_C
#define MERGELIST_C

#include"MergeList.h"                   //包含归并链表的头文件

//算法2.12

void MergeList_L(LinkList La,LinkList *Lb,LinkList *Lc)     //传入的三个参数是三个单链表
{
    LinkList pa,pb,pc;              //定义三个参数是三个工作指针，下边三行是工作指针的初始化

    pa = La->next;                  //工作指针pa指向待归并列表La的首节点
    pb = (*Lb)->next;             //工作指针pb指向待归并列表Lb的首节点
    pc = *Lc = La;                     //工作指针pc指向链表Lc的首节点，which等于链表La的首节点

    while(pa && pb)                 //pa pb都未溢出的情况下持续做如下循环
    {
        if(pa->data <= pb->data)        //pa比pb小就插入pa否则插入pb，pa pb所指的la lb有个前提条件就是事先已经是有序的了
        {                                               // 尾插法的思路。把pa所指元素尾插到pc所指元素的后边
            pc->next = pa;                    //LC的对列尾元素就是pc所指元素，pc->next原本所指元素是NULL，现在改指向待插入元素pa
            pc = pa;                                //工作指针pc应始终指LC队列尾元素，所以工作指针pc移位到pa上
            pa = pa->next;                     //工作指针pa应该始终指向LA队列首位元素，所以pa移位pa->next所指的元素上。      注：这时，原pa->next这条指针还没有断，如果下一次操作仍然是插La上的值的话，就直接照写，如果是插入LB上的值，这个指针会直接改指LB，所以这里不用多花费一步去把【原pa->next置NULL】
        }
        else
        {
            pc->next = pb;                  //与上述同理
            pc = pb;
            pb = pb->next;
        }


    }
    pc->next = pa ? pa:pb;              //插入剩下没没插完的元素，因为是有序的所以直接全部照搬进去就OK

    free(*Lb);                                      //把最后的结点FREE掉
    *Lb = NULL;



}

#endif










