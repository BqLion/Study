//�ݼ���ز����б�
//�ݼ���ʵ����ԭ�����е����е��Ӽ��������ռ���ȫ��  ���ɵļ���
//Ҫע�����ݼ��������У��Եݹ��Ӧ��

#ifndef POWERSET_H
#define POWERSET_H

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SeuqenceList/Scanf.c"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

typedef LElemType_L PElemType;

Status CreatPowerSet_PS(FILE *fp,LinkList *A);

void GetPowerSet_PS(int i,LinkList A,LinkList B);

void Output_PS(LinkList A);

#endif

