/****************************************

�ļ��У�C02/08DualCycleLinkedList

�ļ�����DualCycleLinkedList.h

���ݣ�˫��ѭ��������ز����б�

****************************************/

#ifndef DUALCYCLELINKEDLIST_H
#define DUALCYCLELINKEDLIST_H

#include <stdio.h>
#include "E:/E/DS/C02/01SequenceList/Status.h"
#include "E:/E/DS/C02/01SequenceList/SequenceList.c"

/**************************

һ��ͷ�ļ���

1.��������Ҫ��ͷ�ļ�

2.����ʹ�õ����ݽṹ

3.����ʹ�õĺ���

*************************/

//˫ѭ���������Ͷ���

typedef int LElemType_DC;               //˫ѭ��������������ͽ����
typedef struct DuLNode
{
    LElemType_DC data;                     //������
    struct DuLNode *prior;                 //ǰָ��
    struct DuLNode *next;                   //��ָ��
}DuLNode;                                       //OK���struct����DuLNode,����˫ѭ������Ľ��
typedef DuLNode *DuLinkList;        //����������ָ��ڵ�Ԫ�ص�ָ�����������  DuLinkList

//˫ѭ���������б�
Status InitList_Dul(DuLinkList *L);
//��01����ʼ��˫����L

Status ClearList_Dul(DuLinkList L);
//(02)  �ÿ�L

void DestroyList_Dul(DuLinkList *L);
//(03)����L

Status ListEmpty_Dul(DuLinkList L);
//(04)̽��L

int ListLength_Dul(DuLinkList L);
//��05������LԪ�ظ���

Status GetElem_Dul(DuLinkList L,int i,LElemType_DC *e);
//(06)��e����L�е�i��Ԫ��

int LocateElem_Dul(DuLinkList L,LElemType_DC E,Status(Compare)(LElemType_DC,LElemType_DC));
//(07)����L�е�һ����e����COMpare��ϵ��Ԫ�ص�λ��

Status PriorElem_Dul(DuLinkList L,LElemType_DC cur_e,LElemType_DC *pre_e);
//(08)��pre_e����cur_e��ǰ��

Status NextElem_Dul(DuLinkList L,LElemType_DC cur_e,LElemType_DC *next_e);
//(09)��next_e����cur_e�ĺ��

DuLinkList GetElemPtr_Dul(DuLinkList L,int i);
//(10)����L��ָ���i���ڵ��ָ��

Status ListInsert_Dul(DuLinkList L,int i,LElemType_DC e);
//(11)�㷨2.18����L��i��λ��֮ǰ����e

Status ListDelete_Dul(DuLinkList L,int i,LElemType_DC *e);
//(12)�㷨2.19��ɾ��L��i��λ�õ�ֵ������e����

void ListTraverse_Dul(DuLinkList L,void(Visit)(LElemType_DC));
//(13)��Visit��������L

#endif // DUALCYCLELINKEDLIST_H











