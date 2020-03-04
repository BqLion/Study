/***********************************
文件夹： C02/ 05MergeList

文件名：MergeList.H

内容：单链表归并相关操作列表

**********************************/

#ifndef MERGELIST_H
#define MERGELIST_H

#include<stdlib.h>              //提供malloc、realloc、free、exit原型
#include "E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"    //单链表相关操作

//单链表归并函数列表
void MergeList_L(LinkList La,LinkList *Lb,LinkList *Lc);

// (01)算法2.12：C=A+B,且保持元素相对位置不变。LC利用LA的头结点，LB中节点均插入LC中

#endif // MERGELIST_H
