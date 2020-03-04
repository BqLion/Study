 //3.1ջ�����
 /*********************************

 �ļ��У�C03/01SequenceStack

 �ļ�����SequenceStack.h

 ���ݣ�˳��ջ��ز����б�

 *********************************/

 #ifndef SEQUENCESTACK_H
 #define SEQUENCESTACK_H

 #include<stdio.h>
 #include<stdlib.h>
 #include"E:/E/DS/C02/01SequenceList/Status.h"

 //�궨��
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

//˳��ջ���Ͷ���
//���Թ������ʽ���������������������ֵ������㷨�У���������Ҫ���¶���
#if  !defined MAZE_H                           && \
      !defined EXPRESSION_H                && \
      !defined BINARYTREE_H                && \
      !defined CHILDSIBLINGTREE_H     && \
      !defined Question_8
typedef int SElemType_Sq;

#endif

typedef struct
{
    SElemType_Sq *base;                 //ջ�ṹ�Ķ��壺�ڹ���ǰ�����ٺ�base��ֵΪNULL
    SElemType_Sq *top;                   //ջ��ָ��
    int stacksize;                             //���ڷ���Ĵ���ռ䣬��ջ��Ԫ��Ϊ��λ
} SqStack;

//˳��ջ�����б�

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






