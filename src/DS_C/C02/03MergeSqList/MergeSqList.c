/*******************************

文件夹：charpter02/03MergeList

文件名：MergeSqList.c

算法：2.2、2.7

*******************************/

#ifndef MERGESQLIST_C
#define MERGESQLIST_C

#include "E:/E/DS/C02/03MergeSqList/MergeSqList.h"

//算法2.2

void MergeSqList_1(SqList La,SqList Lb,SqList *Lc) //调用顺序表函数进行合并
{
	int La_len,Lb_len;
	int i,j,k;
	LElemType_Sq ai,bj;

	i=j=1;
	k=0;

	InitList_Sq(Lc);
	La_len=ListLength_Sq(La);
	Lb_len=ListLength_Sq(Lb);

	while(i<=La_len && j<=Lb_len)
	{
		GetElem_Sq(La,i,&ai);
	GetElem_Sq(Lb,j,&bj);

	if (ai<=bj)
		{
				ListInsert_Sq(Lc,++k,ai);
				i++;
		}
	else
		{
				ListInsert_Sq(Lc,++k,bj);
				j++;
			}
	}
	while(i<=La_len)
	{
		GetElem_Sq(La,i++,&ai);
		ListInsert_Sq(Lc,++k,ai);
	}

	while(j<=Lb_len)
	{
		GetElem_Sq(Lb,j++,&bj);
		ListInsert_Sq(Lc,++k,bj);
	}
}

//算法2.7

void MergeSqList_2(SqList La,SqList Lb,SqList *Lc)
{
	LElemType_Sq *pa,*pb,*pc;
	LElemType_Sq *pa_last,*pb_last;

	pa=La.elem;		//指针pa指向列表第一个元素
	pb=Lb.elem;		//指针pb指向列表第一个元素

	(*Lc).listsize=(*Lc).length=La.length+Lb.length;	//没有用InitLis_Sq创建Lc，直接把La和Lb的长度相加得到Lc的长度
	pc=(*Lc).elem=(LElemType_Sq*)malloc((*Lc).listsize*sizeof(LElemType_Sq));    //指针pc指向Lc的第一个元素的位置，其位置用malloc函数分配
	if(!pc)
		exit(OVERFLOW);				//如果pc不等于0（为假）,则报错；

	pa_last=La.elem + La.length - 1;		//pa_last这个指针指向La的最后一个元素
	pb_last=Lb.elem + Lb.length - 1;		//pb_last这个指针直线Lb的最后一个元素


	while(pa<=pa_last && pb<=pb_last)		//用指针的位置判断：la和lb均未被扫描完
	{
		if (*pa <= *pb)
		*pc++ = *pa++;						//若pa指针实时指向的数据小于等于pb指针所指的数据，把pa指向的值赋值给pc，否则把pb指向的值赋值给pc
		else
		*pc++ = *pb++;
	}

	while(pa<=pa_last)						//若表la没有被扫描完，把剩下的给lc
		*pc++ = *pa++;

	while(pb<=pb_last)						//若表lb没有被扫描完，把剩下的给lc
		*pc++ = *pb++;

}


#endif
