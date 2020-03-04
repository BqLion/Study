/****************************

04/01SequenceString

�ļ���: SequenceString.h

����:˳����ز����б�

****************************/

#ifndef SEQUENCESTRING_H
#define SEQUENCESTRING_H

#include <stdio.h>
#include<string.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

#define MAXSTRLEN 255

// ����˳��洢���Ͷ���
typedef unsigned char SString[MAXSTRLEN+1];

//˳�򴮺����б�

Status StrAssign_Sq(SString T,const char *chars);
//����һ��ֵ���ڳ���chars�Ĵ�T

void StrCopy_Sq(SString T,SString S);
//�ɴ����Ƶô�T

Status StrEmpty_Sq(SString S);
//̽��

int StrLength_Sq(SString S);
//�󴮳�

void ClearString_Sq(SString S);

Status Concat_Sq(SString T,SString S1,SString S2);      //�ϲ�

Status SubString_Sq(SString Sub,SString S,int pos,int len);         //�Ӵ�
//Sub����S����pos��ʼlen�����ȵ��Ӵ�

int Index_Sq_1(SString S,SString T,int pos);            //��λ
//����T��S�е�pos���ַ����һ�γ��ֵ�λ�ã��������򷵻�0

Status Index_Sq_2(SString S,SString T,int pos);
//ͬ��

Status Replace_Sq(SString S,SString T,SString V);
//��V�滻������S�У�������T��ȣ����Ӵ��������Ա���ȫ�滻������OK

Status StrInsert_Sq(SString S,int pos,SString T);
//��S�ĵ�pos��λ�ò���T������ȫ���뷵��OK�����򷵻�ERROR

Status StrDelete_Sq(SString S,int pos,int len);
//ɾ����pos��ʼlen���Ӵ�

void DestroyString_Sq(SString S);
//����

void StrPrint_Sq(SString S);

#endif
