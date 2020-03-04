//�ļ��У�05����͹����/02TripleSparseMarix


#ifndef TRIPLESPARSEMATRIX_H
#define TRIPLESPARSEMATRIX_H

#include <stdio.h>
#include<stdarg.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01Scanf.c"

#define MAXSIZE 400

//��Ԫ��ϵ���������Ͷ���
typedef int MElemType_TSq;
typedef struct
{
    int i,j;
    MElemType_TSq e;
}Triple;            //int i,j,e  ��������������Ϊһ����Ԫ�����ݽṹ

typedef struct
{
    Triple data[MAXSIZE+1];             //һϵ�е���Ԫ���飬�����˱�ʾ����Ԫ�������Լ��Ƕ��ٵ���Ԫ��
    int mu,nu,tu;                           //mu,nu,tu�ֱ��ʾ���� ���������������������Ԫ����
}TSMatrix;      //

Status CreateSMatrix_T(FILE *fp,int n,...);

void DestroySMatrix_T(TSMatrix *M);

void PrintSMatrix_T(TSMarix M);

void CopySMatrix_T(TSMatrix M,TSMatrix *T);

Status AddSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q);
//Q = M + N

Status SubSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q);
//Q = M - N

Status MultSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q);
//Q = M *  N

void TransposeSMatrix_T(TSMatrix M,TSMatrix *T);

void FastTransposeSMatrix_T(TSMatrix M,TSMatrix *T);
//�������ת��

#endif










