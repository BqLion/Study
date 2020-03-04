//行编辑程序是模仿文本输入的过程，对输入中的退格/替换等操作做出相应

//本程序采用的测试方式是将输入预先保存到一个字符串中，然后对字符串进行处理后再输出，不用手动输入，简化测试流程

/*********************

文件夹：C03/03LineEdit

文件名：LineEdit.h

内容：行编辑程序相关操作列表

*********************/

#ifndef LINEEDIT_H
#define LINEEDIT_H

#include<stdio.h>
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"

//行编辑程序函数列表

void LineEdit(char Buffer[]);

void Print(SElemType_Sq e);

#endif









