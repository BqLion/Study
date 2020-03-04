/**********************************

�ļ��У�C02/StaticLinkedList

�ļ�����StaticLinkedList.h

���ݣ���̬������ز����б�

TIPS: ��̬������һ����������±���������������ָ�빦�ܵ�����֮������������±������ָ������Ϊ��Щ�߼��������û��ָ��Ĺ���

��̬����Ĵ���ṹ˳������ƣ����ڴ����������洢�ģ������ڲ����ɾ��Ԫ�ص�ʱ����Ҫ�Ѻ�ߵ�����Ԫ�ض�Ų������Ϊ����ĺô���

***********************************/

#ifndef STATICLINEDLIST_H
#define STATICLINKEDLIST_H

#include<stdlib.h>                                  //�ṩmalloc��realloc��free��exitԭ��
#include"E:/E/DS/C02/01SequenceList/Status.h"

//�궨��

#define MAXSIZE 1000                            //��̬�������󳤶�

//��̬�������Ͷ���

typedef int SLinkList;
typedef int LElemType_S;
typedef struct
{
    LElemType_S data;
    int cur;                                    //cur���α꣬��ָ���ã������������±�
}Component[MAXSIZE];             //����ռ����ͣ�һ����Component�����飬�ռ���1000��

//ȫ�ֱ���
Component SPACE;                       //Component��� ��int������һ�� 1000�����ӵ����飬����Ԫ�صĽṹ���ϱ�def�� struct��



//��̬����ĺ����б�
void InitSpace_SL();        //��01���㷨2.14����ʼ���洢�ռ䣬��һά����SPACE�и��������� һ����ı��ÿռ䡣

int Malloc_SL();                //(02)�㷨2.15 Ϊ�����������붯̬�ռ䣬��ģ��malloc�ĺ�����

void Free_SL(int k);      //(03)�㷨2.16  :���±�Ϊk�Ŀ��нڵ���ڴ���ա�ģ��free������

int InitList_SL(SLinkList *H);  //��04��(��ʼ����̬��������ͷ���)

Status ClearList_SL(SLinkList H);   //��05���ÿ�����

void DestroyLsit_SL(SLinkList *H);//(06)��������

Status ListEmpty_SL(SLinkList H);   //(07)�п�

int ListLength_SL(SLinkList H);            //��08����

Status GetElem_SL(SLinkList H,int i,LElemType_S *e);    //��09��ȡֵ

int  LocateElem_SL(SLinkList H,LElemType_S e);      //��10���㷨2.13 ����Ԫ��e��λ��

Status PriorElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *pre_e);  //(11)�� cur_e��ǰ��Ԫ��pre_e

Status NextElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *next_e);        //(12) ��cur_e�ĺ��Ԫ��next_e

Status ListInsert_SL(SLinkList H,int i,LElemType_S e);  //(13) ����

Status ListDelete_SL(SLinkList H,int i,LElemType_S *e); //(14)ɾ��

Status ListTraverse_SL(SLinkList H,void(Visit)(LElemType_S));       //(15)˳���������

#endif // STATICLINEDLIST_H









