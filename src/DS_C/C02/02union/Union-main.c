/**********************************************

文件夹：charpter02/02Union

内容：求并集的相关函数测试

**********************************************/

#include <stdio.h>
#include "E:/E/DS/C02/02Union/Union.c"
void PrintElem(LElemType_Sq e);

int main(int argc,char **argv)
{
	SqList La,Lb;
	LElemType_Sq a[5]={5,2,1,3,9};
	LElemType_Sq b[7]={7,2,6,9,11,3,10};
	int i;

	InitList_Sq(&La);		//初始化La
	for(i=1;i<=5;i++)
		ListInsert_Sq(&La,i,a[i-1]);
	InitList_Sq(&Lb);		//初始化Lb
	for(i=1;i<=7;i++)
		ListInsert_Sq(&Lb,i,b[i-1]);

	printf("La = ");
	ListTraverse_Sq(La,PrintElem);		//输出La
	printf("\n");
	printf("Lb = ");
	ListTraverse_Sq(Lb,PrintElem);		//输出Lb
	printf("\n\n");

	printf("La = La∪Lb = ");			//输出La并Lb的内容
	Union(&La,Lb);
	ListTraverse_Sq(La,PrintElem);
	printf("\n\n");
	system("pause");
	return 0;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d",e);
}
