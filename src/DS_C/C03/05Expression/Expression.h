//03栈和队列

//文件名：Expression.h

//内容：表达式求职相关操作列表

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stdio.h>

//类型定义

typedef char SElemType_Sq;              //定义本程序的元素；类型为char形

#include "E:/E/DS/C03/01SequenceStack/SequenceStack.c"

 typedef SElemType_Sq OperandType;          //操作数类型是char
 typedef SElemType_Sq OperatorType;         //运算符类型也是char

 OperandType EvaluateExpression(char exp[]);     //表达式求值，返回的值是操作数的类型

 OperatorType GetTop_OPTR(SqStack OPTR);       //获取操作符栈的栈顶元素，返回的值是运算符的类型

 Status In(SElemType_Sq c);                 //判断c是否在操作符集里边

 OperatorType Precede(OperatorType o1,OperatorType o2);         //一个操作符类型的函数，比较两个操作符的优先级

 OperandType  Operate(OperandType a,OperatorType theta,OperandType b);          //计算具体这一个表达式的值

 //思路：两个栈，分别装数字和符号。用一个字符串读入待处理的表达式，然后挨个取出，放在temp中，做判断，不是符号的话，直接入数字栈，数组的指针++；如果是字符，把现在temp中的字符与字符栈中的top，也就是离他最近的字符比较优先级高低。如果比栈里的字符优先级高，比如3+2* ,这时就需要把符号入栈，因为不知道后边会不会有更高的；如果比栈里的优先级低，比如3*2+；这种情况就需要计算，字符栈弹栈到theta中，数字栈弹栈两次，到a b中，然后operator（a，theta，b），将计算结果入数字栈，然后将待处理的字符入栈，数组指针++；如果相比优先级相等，就是遇见了括号，如果括号没出出错的话就

 #endif









