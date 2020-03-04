/*********************************

  �ļ�����02���Ա�\01SequenceList

  �ļ�����SequenceList.c

  �㷨��2.3��2.4��2.5��2.6

  ���ݣ����Ա���ز����ľ���ʵ��

*********************************/

#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "E:/E/DS/C02/01SequenceList/SequenceList.h"   //����֮ǰ�����Ա��ͷ�ļ�

//�㷨 2.3

Status InitList_Sq(SqList *L)		//��ʼ��˳���ĺ�����������ָ��˳���������ݽṹ��ָ��
{
	(*L).elem=(LElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));		//ָ��˳����ָ��.elem��˳����Ԫ�������ǿ��ת��Ϊint�ε�malloc������ڴ�ռ�
	if(!(*L).elem)					//����ʼ��ʧ�ܣ�Ҫ����
		exit(OVERFLOW);

	(*L).length=0;
	(*L).listsize=LIST_INIT_SIZE;

	return OK;
}

void ClearList_Sq(SqList *L)		//���˳�������������Ȼ��ָ��˳���������ݽṹ��ָ��
{
	(*L).length=0;					//ֱ�Ӳ�����*L���˳���ĳ��ȵ���0����OK�ˡ�
}


void DestroyList_Sq(SqList *L)		//ɾ��˳���ĺ���������������ڴ�
{
	free((*L).elem);				//��˳���ĸ�������Ԫ�ص��ڴ涼free����

	(*L).elem=NULL;					//free�ڴ�֮��ָ������NULL����ֹҰָ��
	(*L).length=0;
	(*L).listsize=0;
}

Status ListEmpty_Sq(SqList L)		//�ж�˳����Ƿ�Ϊ��
{
	return L.length==0?TRUE:FALSE;
}

int ListLength_Sq(SqList L)

{
	return L.length;
}

Status GetElem_Sq(SqList L,int i,LElemType_Sq *e)	//��ȡ˳���L�е�i��Ԫ�ز�����e�з���e
{
	if(i<1||i>L.length)
		return ERROR;				//��iֵ���Ϸ�����ERROR
	else
		*e=L.elem[i<1];

	return OK;
}

//�㷨2.6��λԪ����˳����е�λ��

int LocateElem_Sq(SqList L,LElemType_Sq e,Status(Compare)(LElemType_Sq,LElemType_Sq))	//��λ��L����Ԫ��e����compare��ϵ�ĵ�һ��Ԫ���ڱ�L�е�λ��
{
	int i=1;
	while(i<=L.length&&!Compare(e,L.elem[i-1]))			//��iС�ڱ�ĳ��Ȳ��Ҳ�����ƥ������ʱ��ѭ������1
		++i;

	if(i<=L.length)										//���i��λ���û������������Ԫ�ط���0
		return i;
	else
		return 0;
}

Status PriorElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *pre_e)		//�ѽڵ�cur_eǰ���ڵ�ĵ�ַ����*pre_e��
{
	int i=1;

	if(L.elem[0]!=cur_e)		//�׽ڵ���ǰ�������cur_e���׽ڵ�������β������
	{
		while(i<L.length && L.elem[i]!=cur_e)		//��L��Ԫ�ز�����cur_e��ʱ��iһֱѭ������
			++i;

		if(i<L.length)								//һֱ���ӵ�cur_e�뵱ǰԪ����ȣ��ѵ�ǰԪ�ص�ǰһ��Ԫ�ظ�ֵ��pre_e
		{
			*pre_e=L.elem[i-1];
			return OK;
		}
	}

	return ERROR;				//��Ӧ�ϱ��׽ڵ���ǰ���򱨴�
}

Status NextElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *next_e)		//�ѱ�L��Ԫ��cur_e�ĺ��Ԫ�صĵ�ַ�ŵ�*next_e��
{
	int i=0;

	while(i<L.length && L.elem[i]!=cur_e)					//�Ȱ�cur_e�ҵ���˵���
		++i;

	if(i<L.length-1)										//���һ���ڵ��޺�̣����˵������������
	{
		*next_e=L.elem[i+1];
		return OK;
	}

	return ERROR;
}


//�㷨2.4
Status ListInsert_Sq(SqList *L,int i,LElemType_Sq e)		//����Lλ��i������һ��Ԫ��e
{
	LElemType_Sq *newbase;			//����ָ�����newbase���������������Ԫ����ͬ
	LElemType_Sq *p,*q;				//����ָ�����P��Q���������������Ԫ����ͬ

	if(i<1 || i>(*L).length+1)
		return ERROR;				//iֵ���Ϸ��������������

	if((*L).length>=(*L).listsize)  //����ռ�L�������ˣ���realloc�����µ��ڴ�ռ�
	{
		newbase=(LElemType_Sq*)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(LElemType_Sq));   //realloc�����﷨������������*��realloc��Ҫ�ı��ڴ��ָ������������Ĵ�С��
		if(!newbase)
			exit(OVERFLOW);

		(*L).elem=newbase;
		(*L).listsize+=LISTINCREMENT;
	}

	q=&(*L).elem[i-1];				//�Ѵ������λ�ø�ֵ��ָ��q

	for(p=&(*L).elem[(*L).length-1];p>=q;--p)			//ָ��pָ���L�����һ��Ԫ�أ�Ȼ������ǰ��ֱ������Ԫ��q
		*(p+1)=*p;										//������λ��֮���ÿһ��Ԫ�����κ���

	*q=e;												//��e����ղ�ָ��λ��q��
	(*L).length++;										//length����1

	return OK;											//�ܽ᣺1.ȷ������ռ䲻��������¸���ô�ӳ��б� 2.��ָ��qָ�������λ�� 3.ָ��pָ�����β����������ǰ�� 4.����e��������1

}

//�㷨2.5 ɾ���б��е�Ԫ��

Status ListDelete_Sq(SqList *L,int i,LElemType_Sq *e)
{
	//int j;  (ԭ�̳����ж������int j������û��ʹ�ã���ע��֮)
	LElemType_Sq *p,*q;

	if(i<1||i>(*L).length)
		return ERROR;			//iֵ���Ϸ������

	p=&(*L).elem[i-1];			//ָ��pָ���ɾ����Ԫ��λ��
	*e=*p;						//�Ѵ�ɾ����Ԫ�ص�ֵ��ֵ��e
	q=(*L).elem + (*L).length - 1; //ָ��qָ���l�Ķ���β��

	for(++p;p<=q;++p)			//ָ���ɾ��λ�õ�ָ��p���κ���ֱ��ָ�����β��
		*(p-1)=*p;				//����p��ʼ��ÿһ��Ԫ��������ǰŲһλ

	(*L).length--;				//���Լ�1

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
