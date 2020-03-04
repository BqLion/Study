/**********************************************

�ļ��У�charpter02/02Union

���ݣ��󲢼�����غ�������

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

	InitList_Sq(&La);		//��ʼ��La
	for(i=1;i<=5;i++)
		ListInsert_Sq(&La,i,a[i-1]);
	InitList_Sq(&Lb);		//��ʼ��Lb
	for(i=1;i<=7;i++)
		ListInsert_Sq(&Lb,i,b[i-1]);

	printf("La = ");
	ListTraverse_Sq(La,PrintElem);		//���La
	printf("\n");
	printf("Lb = ");
	ListTraverse_Sq(Lb,PrintElem);		//���Lb
	printf("\n\n");

	printf("La = La��Lb = ");			//���La��Lb������
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
