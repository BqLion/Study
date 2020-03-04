/*********************************

文件夹：charpter02/02union

文件名：Union.c

算法：2.1归并两个线性表的具体实现

*********************************/

#ifndef UNION_C
#define UNION_C
#include "E:/E/DS/C02/01SequenceList/SequenceList.h"
#include "Union.h"  //把之前的各种定义过的函数、变量都包含在之前写的同名头文件里边了

//算法2.1 归并两个线性表

void Union(SqList *La,SqList Lb)
{
	int La_len,Lb_len;
	int i;
	LElemType_Sq e;

	La_len=ListLength_Sq(*La);		//求顺序表长度的函数
	Lb_len=ListLength_Sq(Lb);

	for(i=1;i<=Lb_len;i++)			//把Lb往La里边归并
	{
		GetElem_Sq(Lb,i,&e);		//GetElem_Sq函数，三个参数分别是线性表Lb，第i个元素，获取e元素（根据e元素的位置）		即：把Lb挨个每个元素都取一遍放在e里
		if(!LocateElem_Sq(*La,e,equal))	//如果LOCATE函数不等于0执行以下操作（若与e满足equal关系的元素不在La这个线性表中则） 即：每次都把Lb里边的元素都与La里的元素匹配一下，如果没有重复的，做以下操作：
			ListInsert_Sq(La,++La_len,e);//把e（Lb里的元素insert到La里边来）
	}
}

Status equal(LElemType_Sq e1,LElemType_Sq e2)  //equal函数在这里用于判断线性表中的元素是否相等，若相等返回1，不相等返回0.
{
	return e1 == e2 ? TRUE:FALSE;
}

#endif
