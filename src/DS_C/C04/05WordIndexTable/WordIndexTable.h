//4.5������������ز����б�

#ifndef WORDINDEXTABLE_H
#define WORDINDEXTABLE_H

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/09ExtenLinkedList/ExtenLinkedList.c"
#include"E:/E/DS/C04/02HeapString.c";

#define MaxBookNul 1000
#define MaxKeyNum 2500
#define MaxLineLen 500
#define MaxWordNum 10

//���ݽṹ����

typedef Status Bool;
typedef struct
{
    char *str[MaxWprdNum];      //�ַ�������
    int last;                                 //�ʱ�ĳ���
}WordListType;                  //�������ժ¼�Ĵʱ�

typedef struct
{
    HString key;
    ELinkList bnolist;
}IdxTermType;               //������ŵ��ǹؼ��ʺ���ŵ�����      //һ���ؼ��ʣ�һЩ���
//���ϱ������������Ͼ���������
typedef struct
{
    IdxTermType item[MaxKeyNum+1];
    int num;
}IdxListType;           //�������ղŶ����������ļ��ϣ�int num�����������Ŀ

//ȫ�ֱ���
char gBuf[MaxLineLen];      //�����Ļ�����

WordListType g WordList = {{"a","an","the","of","and","is","to","as","in","for"},10};//����ô�

WordListType gWdList;

void Main(char *bookinfo,char *bookidx);

void InitInxList(IdxListType *idxlist);
//��ʼ��������

void GetLine(FILE *f);
//����Ŀ��Ϣ���뻺����gBuf

void ExtractKeyWord(int *bno);//��������gBuf ����ȡ�����ؼ��ʵ��ʱ�gWdList,��Ŵ��bno��

Status InsIdxList(IdxListType *idxlist,int bno);    //�����bno��Ӧ�������ؼ��ʰ��մʵ��˳����뵽������idxlist

void PutText(FILE *g,IdxListType idxlist);
//�����ɵ�������idxList������ļ���

void GetWord(int i,HString *wd);
//��wd����gWdList�е�i���ؼ���

int Locate(IdxListType idxlist,HString wd,Bool *b);
//��ѯ��������idxList���Ƿ������wd��ȵĹؼ��ʣ������ڣ�������wd�ڴʻ���е�λ�ã�������boolΪTrue������boolΪFALSE��

void InsertNewKey(IdxListType *idxlist,int i,HString wd);
//��������idxlist ,�еĵ�iλ������wd����ؼ��ʣ�����ʼ��wd��������βnull

Status InsertBook(IdxListType *idxlist,int i,int bno);              //�������в���
//��������ĵ�i���в������Ϊbno������

Status isCommonWords(HString S);
//�ж�S�����Ĺؼ����Ƿ��ǳ��ô�


//�����ļ�
//���ļ��е������ͺ���𿪣��������ֱ���뵽�ʻ��(wordlist)�С�
//�����Щ�����ʻ�(key)����������(idxlist)���Ƿ���ڣ��������ڲ��룬�����ڼ����Լ������(bnolist)��













