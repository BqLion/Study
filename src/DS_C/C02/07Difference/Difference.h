/******************************

文件夹：C02、07 Difference

文件名：Difference.h

内容：算法2.17相关操作列表

TIPS:

本算法就是求解集合A,B的对称差 运算，即A△B = (A-B)∪(B-A)。求的是集合A与B刨除相同部分后取的并集

用静态链表来处理此问题的思路就是建立静态链表A，包含集合A中所有的元素，然后遍历集合B，若B中元素不在A中，将其加入A中，否则删除A中的相应元素。

*****************************/

#ifndef DIFFERENCE_H
#define DIFFERENCE_H

#include <stdio.h>
#include"E:/E/DS/C02/01SequenceList/Scanf.c"
#include"E:/E/DS/C02/06StaticLinkedList/StaticLinkedList.c"         //包含了静态链表的头文件

//算法2.17求集合A B对称差的算法实现

void difference(SLinkList *S,LElemType_S A[],int len_A,LElemType_S B[],int len_B);

#endif // DIFFERENCE_H





