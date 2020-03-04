 //3.1栈与队列
 /*********************************

 文件夹：C03/01SequenceStack

 文件名：SequenceStack.h

 内容：顺序栈相关操作列表

 *********************************/

 #ifndef SEQUENCESTACK_H
 #define SEQUENCESTACK_H

 #include<stdio.h>
 #include<stdlib.h>
 #include"E:/E/DS/C02/01SequenceList/Status.h"

 //宏定义
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

//顺序栈类型定义
//在迷宫，表达式，二叉树二叉链表，孩子兄弟树等算法中，此类型需要重新定义
#if  !defined MAZE_H                           && \
      !defined EXPRESSION_H                && \
      !defined BINARYTREE_H                && \
      !defined CHILDSIBLINGTREE_H     && \
      !defined Question_8
typedef int SElemType_Sq;

#endif

typedef struct
{
    SElemType_Sq *base;                 //栈结构的定义：在构造前，销毁后，base的值为NULL
    SElemType_Sq *top;                   //栈顶指针
    int stacksize;                             //当期分配的储存空间，以栈内元素为单位
} SqStack;

//顺序栈函数列表

Status InitStack_Sq(SqStack *S);

Status DestroyStack_Sq(SqStack *S);

Status ClearStack_Sq(SqStack *S);

Status StackEmpty_Sq(SqStack S);

Status StackLength_Sq(SqStack S);

Status GetTop_Sq(SqStack S,SElemType_Sq *e);

Status Push_Sq(SqStack *S,SElemType_Sq e);

Status Pop_Sq(SqStack *S,SElemType_Sq *e);

Status StackTraverse_Sq(SqStack S,void(Visit)(SElemType_Sq));

#endif // SEQUENCESTACK_H






