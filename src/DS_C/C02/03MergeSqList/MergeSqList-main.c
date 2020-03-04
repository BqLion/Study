/***************************                           为什么下边两个测试函数不执行直接结束了？

文件夹：charpter02/03MergeSqList

内容：顺序表归并的的相关函数测试

****************************/

#include <stdio.h>
#include "E:/E/DS/C02/03MergeSqList/MergeSqList.c"

void PrintElem(LElemType_Sq e);		//声明打印函数，用于打印整形

int main(int argc,char **argv)
{
	SqList La,Lb,Lc1,Lc2;
	LElemType_Sq a[4] = {3,5,8,11};
	LElemType_Sq b[7] = {2,6,8,9,11,15,20};
	int i;

	InitList_Sq(&La);			//初始化La
	for(i=1;i<=4;i++)
		ListInsert_Sq(&La,i,a[i-1]);

	InitList_Sq(&Lb);			//初始化Lb
	for(i=1;i<=7;i++)
		ListInsert_Sq(&Lb,i,b[i-1]);

	printf("La = ");			//输出La
	ListTraverse_Sq(La,PrintElem);
	printf("\n");

	printf("Lb = ");			//输出Lb
	ListTraverse_Sq(Lb,PrintElem);
	printf("\n\n");


	printf("合并La和Lb为Lc1 = （使用数组下标法）");//合并la与lb，算法2.6
	MergeSqList_1(La,Lb,&Lc1);
	ListTraverse_Sq(Lc1,PrintElem);		//输出lc1
	printf("\n\n");

	printf("合并La和Lb为Lc2 =（使用指针法）");   //合并la与lb，算法2.7
	MergeSqList_2(La,Lb,&Lc2);
	ListTraverse_Sq(Lc2,PrintElem);		//输出lc2
	printf("\n\n");


	system("pause");
	return 0;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d",e);
}


