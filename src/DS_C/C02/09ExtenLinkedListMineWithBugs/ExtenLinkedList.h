/*****************************

�ļ��У�C02/09ExtenLinkedList.h

�ļ�����ExtenLinkedList.h

���ݣ���չ�ĵ�������ز����б�

��ע���˳���������ļ�ǿ�棬������������ݽṹ�����¶��壬�����ޱ仯

*******************************/
#ifndef EXTENLINKEDLIST_H
#define EXTENLINKEDLIST_H

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"

//��չ�ĵ��������Ͷ���
#ifndef POLYNOMIAL_H                //�ں�ߵĶ���ʽ�����У���������Ҫ���¶���
typedef int LElemType_E;
#endif // POLYNOMIAL_H

typedef struct ELNode       //����ڵ�����
{
    LElemType_E data;
    struct ELNode *next;
}ELNode;

typedef ELNode *Link;
typedef ELNode *PositionPtr;
typedef struct
{
        Link head,tail;
        int len;
}ELinkList;             //������������Ľṹ�壬����ָ��ͷ����β�ڵ��ָ�룬�Լ���������ĳ���

//��չ�ĵ��������б�

Status MakeNode_E(Link *p,LElemType_E e);
//��1��������pָ��e�Ľ��

void FreeNode_E(Link *p);
//(2) �ͷ�pָ��Ľ��

Status InitList_E(ELinkList *L);
//��3������ʼ��һ���յ���������

void ClearList_E(ELinkList *L);
//(4)������������LΪ��

void DestroyList_E(ELinkList *L);
//(5)������������

void InsFirst_E(ELinkList *L,Link h,Link s);
//(6)hָ��L���еĽ�㣬��sָ���Ԫ�ز���֮��

Status DelFirst_E(ELinkList *L,Link h,Link *q);
//(7)hָ��L�е�һ���ڵ㣬ɾȥ�䣬��q����

void Append_E(ELinkList *L,Link s);
//(8)��s��ָ��һ���ڵ�������L�����һ���ڵ�֮�󣬲��ı�L��βָ��

Status Remove_E(ELinkList *L,Link *q);
//(09)ɾ��L ��β�ڵ㲢��q���գ��ı�βָ�롣

void InsBefore_E(ELinkList *L,Link *p,Link s);
//(10)��s��ָ�ڵ����p��ָ�ڵ�֮ǰ������pָ���²���Ľ��

void InsAfter_E(ELinkList *L,Link *p,Link s);
//��11����s��ֱ�ӵ����p��ָ�ڵ�֮�󣬲���pָ���²���Ľ��

void SetCurElem_E(Link p,LElemType_E e);
//(12)��e����pָ��Ľ���е�ֵ

LElemType_E GetCurElem_E(Link p);
//��13������p����е�ֵ

Status ListEmpty_E (ELinkList L);
//(14)�п�

int ListLength_E(ELinkList L);
//��15����

PositionPtr GetHead_E(ELinkList L);
//(16)��ָ����ʽ����Lͷ����λ��

PositionPtr GetLast_E(ELinkList L);
//(17)��ָ����ʽ����Lβ�ڵ��λ��

PositionPtr PriorPos_E(ELinkList L,Link p);
//(18)����pָ��Ľ���ǰ��

PositionPtr NextPos_E(Link p);
//��19������pָ��Ľ��ĺ��

Status LocatePos_E(ELinkList L,int i,Link p);
//(20)��*pָ��L�е�i���ڵ㣬i=0ʱΪͷ���

PositionPtr LocateElem_E(ELinkList L,LElemType_E e,Status(Compare)(LElemType_E,LElemType_E));
//��21������L�е�һ����e����compare��ϵ��Ԫ��ָ��


Status ListTraverse_E(ELinkList L,void(Visit)(LElemType_E));
//(22)����

Status ListInsert_L_E(ELinkList *L,int i,LElemType_E e);
//(23)�㷨2.20 ��L��i��λ��֮ǰ����e

Status ListDelete_L_E(ELinkList *L,int i,LElemType_E *e);
//(24)ɾ��L�е�i��λ�õ�ֵ������e����

#endif // EXTENLINKEDLIST_H





























