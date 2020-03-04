/***************************

 文件夹：charpter22/02union

 文件名：Union.h

 内容：求两线性表的并集相关操作列表

 **************************/

#ifndef UNION_H
#define UNION_H

#include "E:/E/DS/C02/01SequenceList/SequenceList.c"//include 线性表的各种基本操作

//并集函数列表

extern void Union(SqList *La,SqList Lb);
	//(01)算法2.1：A=A∪B

extern Status equal(LElemType_Sq e1,LElemType_Sq e2);
	//(02)判断两元素是否相等

#endif


