/************************
�ļ��У�C02/11Polynomial

�ļ�����Polynomial.h

���ݣ�һԪ����ʽ��ز����б�

**************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<stdio.h>
#include<stdlib.h>

//����ʽ���Ͷ���
typedef struct                  //��ʾ����ʽ����
{
    float coef;                     //ϵ��
    int expn;                       //ָ��
}LElemType_E;           //���¶�����չ�����Ա��е�Ԫ������     LElemType_E �����Ա�Ԫ������֮�⣬Ҳ�ж���ʽ������֮��

#include"E:/E/DS/C02/09ExtenLinkedList/ExtenLinkedList.c"
typedef LElemType_E ElemType_P;                 //һԪ����ʽ������
typedef ELinkList Polynomial;                        //һԪ����ʽ

//һԪ����ʽ�����б�

void CreatePolyn_P(FILE *fp,Polynomial *P,int m);
//(01)�㷨2.22 ��������Ϊm��һԪ����ʽ ��File�ж�ȡ���ݣ�ָ��Polynomial(����ʽ)��ָ��P����ʵ����ָ��ElinkList(�ɳ���len��head��tailͷβָ�빹��)��ָ�롣

void DestroyPolyn_P(Polynomial *P);
//(02)����һԪ����ʽ

int PolynLength_P(Polynomial P);
//(03)����һԪ����ʽ������

void AddPolyn_P(Polynomial *Pa,Polynomial *Pb);
//��04���㷨2.23��һԪ����ʽ�ӷ�Pa=Pa+Pb,����Pb

void SubtractPolyn_P(Polynomial *Pa,Polynomial *Pb);
//��05��һԪ����ʽ����Pa=Pa-Pb,����Pb

void MultiplyPolyn_P(Polynomial *Pa,Polynomial *Pb);
//(06)һԪ����ʽ�˷�Pa=Pa*Pb,����Pb

int Cmp_exp(ElemType_P c1,ElemType_P c2);
//(07)�Ƚ�c1��c2��ָ���Ĵ�С

void PrintPolyn_P(Polynomial P);
//(08)��ӡ���һԪ����ʽ

#endif // POLYNOMIAL_H












