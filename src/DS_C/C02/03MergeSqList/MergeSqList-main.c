/***************************                           Ϊʲô�±��������Ժ�����ִ��ֱ�ӽ����ˣ�

�ļ��У�charpter02/03MergeSqList

���ݣ�˳���鲢�ĵ���غ�������

****************************/

#include <stdio.h>
#include "E:/E/DS/C02/03MergeSqList/MergeSqList.c"

void PrintElem(LElemType_Sq e);		//������ӡ���������ڴ�ӡ����

int main(int argc,char **argv)
{
	SqList La,Lb,Lc1,Lc2;
	LElemType_Sq a[4] = {3,5,8,11};
	LElemType_Sq b[7] = {2,6,8,9,11,15,20};
	int i;

	InitList_Sq(&La);			//��ʼ��La
	for(i=1;i<=4;i++)
		ListInsert_Sq(&La,i,a[i-1]);

	InitList_Sq(&Lb);			//��ʼ��Lb
	for(i=1;i<=7;i++)
		ListInsert_Sq(&Lb,i,b[i-1]);

	printf("La = ");			//���La
	ListTraverse_Sq(La,PrintElem);
	printf("\n");

	printf("Lb = ");			//���Lb
	ListTraverse_Sq(Lb,PrintElem);
	printf("\n\n");


	printf("�ϲ�La��LbΪLc1 = ��ʹ�������±귨��");//�ϲ�la��lb���㷨2.6
	MergeSqList_1(La,Lb,&Lc1);
	ListTraverse_Sq(Lc1,PrintElem);		//���lc1
	printf("\n\n");

	printf("�ϲ�La��LbΪLc2 =��ʹ��ָ�뷨��");   //�ϲ�la��lb���㷨2.7
	MergeSqList_2(La,Lb,&Lc2);
	ListTraverse_Sq(Lc2,PrintElem);		//���lc2
	printf("\n\n");


	system("pause");
	return 0;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d",e);
}


