/************************************

  �ļ��У�02���Ա� sequencelist

  ���ݣ�������˳��ṹ��غ�������

 ***********************************/

#include <stdio.h>
#include "E:/E/DS/C02/01SequenceList/SequenceList.c"

//���Ե��õĺ���ԭ��

Status CmpGreater(LElemType_Sq e,LElemType_Sq data);		//�������ܣ���Ԫ��data>e������TRUE�����򷵻�FALSE
void PrintElem(LElemType_Sq e);								//�����ú�������ӡ����

int main(int argc,char **argv)				//�������**argv�ββ��Ǻ��˽⣬��Ӧ��ʵ�ο����ǣ�
{											//ָ�����飬��char *p[10] ;
	SqList L;								//��ά���飬��char pp[5][10];
	//int i;									//ָ�������ַ����char *p; your_func( &p );
	//LElemType_Sq e;

	printf("NO.1\n����InitList_Sq ���ԡ�\n");		//1.����InitList_Sq����
	{
		printf("��ʼ��˳���L����\n");
		InitList_Sq(&L);
		printf("\n");
	}
	PressEnter;

	printf("NO.4\n����ListEmpty_Sq ���ԡ�\n");		//4.����ListEmpty_Sq����
	{
		ListEmpty_Sq(L)?printf("LΪ�գ���\n"):printf("L��Ϊ�գ�\n");
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
