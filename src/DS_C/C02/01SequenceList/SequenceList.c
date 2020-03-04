/*********************************

  文件名：02线性表\01SequenceList

  文件名：SequenceList.c

  算法：2.3、2.4、2.5、2.6

  内容：线性表相关操作的具体实现

*********************************/

#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "E:/E/DS/C02/01SequenceList/SequenceList.h"   //包含之前的线性表的头文件

//算法 2.3

Status InitList_Sq(SqList *L)		//初始化顺序表的函数，参数是指向顺序表这个数据结构的指针
{
	(*L).elem=(LElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));		//指向顺序表的指针.elem即顺序表的元素项，等于强制转换为int形的malloc分配的内存空间
	if(!(*L).elem)					//若初始化失败，要报错
		exit(OVERFLOW);

	(*L).length=0;
	(*L).listsize=LIST_INIT_SIZE;

	return OK;
}

void ClearList_Sq(SqList *L)		//清空顺序表函数，参数仍然是指向顺序表这个数据结构的指针
{
	(*L).length=0;					//直接操作，*L这个顺序表的长度等于0，就OK了。
}


void DestroyList_Sq(SqList *L)		//删除顺序表的函数，包括了清空内存
{
	free((*L).elem);				//把顺序表的各项数据元素的内存都free掉了

	(*L).elem=NULL;					//free内存之后指针需置NULL，防止野指针
	(*L).length=0;
	(*L).listsize=0;
}

Status ListEmpty_Sq(SqList L)		//判断顺序表是否为空
{
	return L.length==0?TRUE:FALSE;
}

int ListLength_Sq(SqList L)

{
	return L.length;
}

Status GetElem_Sq(SqList L,int i,LElemType_Sq *e)	//获取顺序表L中第i个元素并放入e中返回e
{
	if(i<1||i>L.length)
		return ERROR;				//若i值不合法返回ERROR
	else
		*e=L.elem[i<1];

	return OK;
}

//算法2.6定位元素在顺序表中的位置

int LocateElem_Sq(SqList L,LElemType_Sq e,Status(Compare)(LElemType_Sq,LElemType_Sq))	//定位表L中与元素e满足compare关系的第一个元素在表L中的位序。
{
	int i=1;
	while(i<=L.length&&!Compare(e,L.elem[i-1]))			//当i小于表的长度并且不满足匹配条件时，循环自增1
		++i;

	if(i<=L.length)										//输出i的位序或没有满足条件的元素返回0
		return i;
	else
		return 0;
}

Status PriorElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *pre_e)		//把节点cur_e前驱节点的地址放入*pre_e中
{
	int i=1;

	if(L.elem[0]!=cur_e)		//首节点无前驱，如果cur_e是首节点则跳到尾部报错
	{
		while(i<L.length && L.elem[i]!=cur_e)		//当L的元素不等于cur_e的时候，i一直循环自增
			++i;

		if(i<L.length)								//一直增加到cur_e与当前元素相等，把当前元素的前一个元素赋值给pre_e
		{
			*pre_e=L.elem[i-1];
			return OK;
		}
	}

	return ERROR;				//对应上边首节点无前驱则报错
}

Status NextElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *next_e)		//把表L中元素cur_e的后继元素的地址放到*next_e中
{
	int i=0;

	while(i<L.length && L.elem[i]!=cur_e)					//先把cur_e找到再说别的
		++i;

	if(i<L.length-1)										//最后一个节点无后继，过滤掉这种特殊情况
	{
		*next_e=L.elem[i+1];
		return OK;
	}

	return ERROR;
}


//算法2.4
Status ListInsert_Sq(SqList *L,int i,LElemType_Sq e)		//给表L位置i处增加一个元素e
{
	LElemType_Sq *newbase;			//定义指针变量newbase，数据类型与表中元素相同
	LElemType_Sq *p,*q;				//定义指针变量P、Q，数据类型与表中元素相同

	if(i<1 || i>(*L).length+1)
		return ERROR;				//i值不合法，特殊情况报错

	if((*L).length>=(*L).listsize)  //储存空间L不够用了，用realloc开辟新的内存空间
	{
		newbase=(LElemType_Sq*)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(LElemType_Sq));   //realloc函数语法：（数据类型*）realloc（要改变内存的指针名，新申请的大小）
		if(!newbase)
			exit(OVERFLOW);

		(*L).elem=newbase;
		(*L).listsize+=LISTINCREMENT;
	}

	q=&(*L).elem[i-1];				//把待插入的位置赋值给指针q

	for(p=&(*L).elem[(*L).length-1];p>=q;--p)			//指针p指向表L的最后一个元素，然后依次前移直到碰上元素q
		*(p+1)=*p;										//待插入位置之后的每一个元素依次后移

	*q=e;												//把e插入刚才指的位置q处
	(*L).length++;										//length自增1

	return OK;											//总结：1.确定储存空间不够的情况下该怎么加长列表 2.用指针q指向待插入位置 3.指针p指向队列尾部，并依次前移 4.插入e，表长自增1

}

//算法2.5 删除列表中的元素

Status ListDelete_Sq(SqList *L,int i,LElemType_Sq *e)
{
	//int j;  (原教程中有定义这个int j，但是没有使用，先注释之)
	LElemType_Sq *p,*q;

	if(i<1||i>(*L).length)
		return ERROR;			//i值不合法的情况

	p=&(*L).elem[i-1];			//指针p指向待删除的元素位置
	*e=*p;						//把待删除的元素的值赋值给e
	q=(*L).elem + (*L).length - 1; //指针q指向表l的队列尾部

	for(++p;p<=q;++p)			//指向待删除位置的指针p依次后移直到指向队列尾部
		*(p-1)=*p;				//将从p开始的每一个元素依次往前挪一位

	(*L).length--;				//表长自减1

	return OK;

}

Status ListTraverse_Sq(SqList L,void(Visit)(LElemType_Sq))
{
	int i;

	for(i=0;i<L.length;i++)
		Visit(L.elem[i]);

	return OK;

}

#endif
