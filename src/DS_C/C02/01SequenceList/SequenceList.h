/**************************************

  �ļ���:charpter01

  �ļ�����SequenceList.h

  ���ݣ�˳�����ز����б�

**************************************/

#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "E:/E/DS/C02/01SequenceList/Status.h"

//�궨��
#define LIST_INIT_SIZE	100
#define LISTINCREMENT	10

//˳������Ͷ���
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemType_Sq;
#endif

typedef struct
{
	LElemType_Sq *elem;				//����ռ��ַ��ָ���һ���ڵ��ָ�룩
	int length;						//��ǰ˳�����
	int listsize;					//��ǰ����Ĵ�������
}SqList;							//˳���0�ŵ�Ԫ����ʹ�ã���ʱ������ʲô��˼��

//˳���ĺ����б�����������
extern Status InitList_Sq(SqList *L);		//(01)�㷨2.3��ʼ����˳���L

extern void ClearList_Sq(SqList *L);		//(02)���˳���L

extern void DestroyList_Sq(SqList *L);		//(03)����˳���L

extern Status ListEmpty_Sq(SqList L);		//(04)�ж�˳���L�Ƿ�Ϊ��

extern int ListLength_Sq(SqList L);		//(05)����˳�����Ԫ�ظ���

extern Status GetElem_Sq(SqList L,int i,LElemType_Sq *e);//(06)��Ԫ��e��ȡ˳���L�е�i��Ԫ�ز�����

extern int LocateElem_Sq(SqList L,LElemType_Sq e,Status(Compare)(LElemType_Sq,LElemType_Sq));//(07)�㷨2.6������˳���L���׸���e����Compare��ϵ��Ԫ�ص�λ��

extern Status PriorElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *pre_e);//(08)��pre_e����cur_e��ǰ����������Ϊʲô��*pre_e������pre_e��

extern Status NextElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *next_e);//(09)��next_e����cur_e�ĺ�̣�������ͬ�ϣ�����������������ָ������⣩

extern Status ListInsert_Sq(SqList *L,int i,LElemType_Sq e);//(10)�㷨2.4����˳���ĵ�i��λ�ò���Ԫ��e�������õ���SqList��ָ�룬������Ϊ�˶�λ��

extern Status ListDelete_Sq(SqList *L,int i,LElemType_Sq *e);//(11)�㷨2.5��ɾ��˳���L�ϵ�i��λ�õ�Ԫ�أ�����e���ء�

extern Status ListTraverse_Sq(SqList L,void(Visit)(LElemType_Sq));//(12)��Visit��������˳���L����ת˳��

#endif






