/**********************************

�ļ���MPSet.h

���ݣ����鼯��ز����б�

**********************************/

#ifndef MFSET_H
#define MFSET_H

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"

//���鼯��������Ԫ�ص��������ٰ�֮ǰ�Ĺ�ϵһһ�鲢�ɼ�����ļ���

typedef int TElemType_P;
#include"E:/E/DS/C06/05ParentTree/ParentTree.c"           //�õ���˫�����ı�ʾ��

//˫�ױ�ʾ���Ľ���� int data + int parent,����ע����ʾ
/*********************
typedef struct PTNode
{
    TElemType_P data;
    int parent;
}PTNode;               //���Ľ��
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int n;          //���Ľ����
}PTree;                 //������
*********************/

typedef PTree MFSet;

typedef struct
{
    int i;
    int j;
}Node;

typedef struct
{
    Node nodes[MAX_TREE_SIZE];
    int n;
}Relation;

void Initial_mfset(FILE *fp,MFSet *S);

int find_mfset(MFSet S,int i);
//���Ҽ���S��i�����Ӽ��ĸ�

Status merge_mfset(MFSet *S,int i,int j);
//��Si Sj�Ĳ���

Status mix_mfset(MFSet *S,int i,int j);
//���Ϲ鲢��������һ���鲢�����ĸĽ���

int fix_mfset(MFSet *S,int i);
//���Ҽ���S��i�����Ӽ��ĸ����Ľ���

Status  BuildRelation_mfset(FILE *fp,Relation *R);
//������Ԫ�ȼ۹�ϵ

int EquivalenceClass_mfset_1(MFSet *S,Relation R);
//���ڵȼ۹�ϵR�¼���S�ĵȼ���

int SubsetCount_mfset(MFSet S);

void ShowSet_mfset(MFSet S);

#endif



