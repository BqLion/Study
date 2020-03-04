/*************************

�ļ��� ��05����͹����

SequenceArray.h

������ز����б�

**************************/

#ifndef SEQUENCEARRAY_H
#define SEQUENCEARRAY_H

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

#define MAX_ARRAY_DIM 8

typedef int AElemType_Sq;
typedef struct
{
    AElemType_Sq *base;         //����Ԫ�ػ�ַ
    int dim;                               //����ά��
    int *bounds;                       //����ά���ַ����������������Ϣ��
    int *constants;                 //����ӳ����������ַ���洢��Խĳ��ά��ʱ��Ҫ�����Ԫ�ظ�����
}Array;

Status InitArray(Array *A,int dim,...);

Status DestroyArray(Array *A);

Status LocateArray(Array A,va_list ap,int *off);//��apָʾ��ֵ����A�е����λ��

Status ValueArray(Array A,AElemType_Sq *e,...);
//ȡֵ

Status AssignArray(Array *A,AElemType_Sq e,...);

void ArrayPrint(Array A);

#endif // SEQUENCEARRAY_H






