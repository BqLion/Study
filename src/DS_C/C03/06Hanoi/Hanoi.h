//递归，记住山成虎老师的ppt，先引出来一队，入栈，然后再依次出栈，清空递归的栈

#ifndef HANOI_H
#define HANOI_H

#include<stdio.h>
#include<stdlib.h>
//全局变量

int gStep;

void  hanoi(int n,char x,char y,char z);
//汉诺塔求解问题，以y为辅助轴，将n个圆盘从x移动到z

void move(char x,int n,char z);

//将第n个圆盘从x移动到z

#endif
