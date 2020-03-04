/************************************

  文件夹：02线性表 sequencelist

  内容：单链表顺序结构相关函数测试

 ***********************************/

#include <stdio.h>
#include "E:/E/DS/C02/01SequenceList/SequenceList.c"

//测试调用的函数原型

Status CmpGreater(LElemType_Sq e,LElemType_Sq data);		//函数功能：若元素data>e，返回TRUE，否则返回FALSE
void PrintElem(LElemType_Sq e);								//测试用函数，打印整形

int main(int argc,char **argv)				//对于这个**argv形参不是很了解，对应的实参可能是：
{											//指针数组，即char *p[10] ;
	SqList L;								//二维数组，如char pp[5][10];
	//int i;									//指针变量地址，如char *p; your_func( &p );
	//LElemType_Sq e;

	printf("NO.1\n函数InitList_Sq 测试…\n");		//1.函数InitList_Sq测试
	{
		printf("初始化顺序表L……\n");
		InitList_Sq(&L);
		printf("\n");
	}
	PressEnter;

	printf("NO.4\n函数ListEmpty_Sq 测试…\n");		//4.函数ListEmpty_Sq测试
	{
		ListEmpty_Sq(L)?printf("L为空！！\n"):printf("L不为空！\n");
		printf("\n");
	}
	PressEnter;



	system("pause");
	return 0;
}

Status CmpGreater(LElemType_Sq e,LElemType_Sq data)
{
	return data>e? TRUE:FALSE;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d",e);
}
