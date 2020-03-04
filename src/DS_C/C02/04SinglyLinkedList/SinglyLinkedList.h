/********************************

�ļ��У�C02/04SinglyLinkedList

�ļ�����SinglyLinkedList.h

����:��������ز����б�

********************************/

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKDELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "E:/E/DS/C02/01SequenceList/Status.h"
#include "E:/E/DS/C02/01SequenceList/Scanf.c"

/*���������Ͷ���*/

#ifndef BANKQUEUING_H       //��ߵ�ģ�������Ŷ��㷨�У���������Ҫ���¶���
typedef int LElemType_L;

/*������ṹ�嶨��*/
typedef struct LNode
{
    LElemType_L data;          //�����ϱߵ�typedef ���Ƕ�����һ��int data��������������
    struct LNode *next;        //Ƕ�׶�����һ��ָ��LNode�������ε�ָ�룬����next
}LNode;
typedef LNode *LinkList;       //������LNode��ָ��ڵ��ε�ָ�룩����Ϊ LinkList
#endif // BANKQUEUING_H


/*��������ͷ���ģ������б�*/
Status InitList_L(LinkList *L);        //��1����ʼ��������LinkList����֮ǰ���壬Ϊָ��ڵ�LNode��ָ�룬��LinkList *L��Ϊָ��ָ���ָ��

Status ClearList_L(LinkList L);        //��2���ÿյ�����ͷ��㱣����������LinkList�ε�ָ��

void DestroyList_L(LinkList *L);       //��3�����ٵ�����L����ͬ�ڵ�һ������

Status ListEmpty_L(LinkList L);        //(4)��鵥����L�Ƿ�Ϊ��

int ListLength_L(LinkList L);           //(5)���ص�����L��Ԫ�ظ���

Status GetElem_L(LinkList L,int i,LElemType_L *e);  //(6)�㷨2.8����ȡԪ�ء���e���ܵ�����L�ϵĵ�i��Ԫ��

int LocateElem_L(LinkList L,LElemType_L e,Status(Compare)(LElemType_L,LElemType_L)); //(7)���ص�����L�е�һ����e����Compare��ϵ��Ԫ��λ��

Status PriorElem_L(LinkList L,LElemType_L cur_e,LElemType_L *pre_e);                //(8)ǰ����������pre_eȥ����cur_e��ǰ��

Status_NextElem_L(LinkList L,LElemType_L);                                           //(9)��̺�������next_e����cur_e�ĺ��

Status ListInsert_L(LinkList L,int i,LElemType_L e);                                //��10���㷨2.9���ڵ�����L��i��λ��ǰ����e

Status ListDelete_L(LinkList L,int i,LElemType_L *e);                               //(11)�㷨2.10��ɾ�����Ա�L ��i��λ�õ�ֵ������e����

Status ListTraverse_L(LinkList L,void(Visit)(LElemType_L));                         //��12����visit �����������ʵ�����L

Status CreateList_HL(FILE *fp,LinkList *L,int n);                                   //(13)�㷨2.11��ͷ�巨����������L���������룩

Status CreateList_TL(FILE *fp,LinkList *L,int n);                                   //(14)β�巨����������L��˳�����룩

#endif // SINGLYLINKEDLIST_H
















