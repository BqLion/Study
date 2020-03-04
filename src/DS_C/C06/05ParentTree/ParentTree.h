//����˫�ױ�ʾ��

//��ͬ�ڶ�������������Ĭ������������Ļ����Ǻ��ӱ�ʾ��������˫�׾���˫�׺���˫�����ʾfa

//��������Ǹ�һ�����������������

//��һ�������data˳��װ��ȥ��ͬʱ��һ���ռ�ר�Ŵ���ڵ��Ӧ��parent�±�

#ifndef PARENTTREE_H
#define PARENTTREE_H

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"

#define MAX_TREE_SIZE 100

#ifndef MFSET_H
typedef char TElemType_P;
#endif

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

void InitTree_P(PTree *T);

void ClearTree_P(PTree *T);

void DestroyTree(PTree *T);

Status TreeEmpty_P(PTree T);

Status CreateTree_P(FILE *fp,PTree *T);
//���ղ������й�����

int TreeDegree_P(PTree T);
//���Ķ�

int TreeDepth_P(PTree T);

TElemType_P Root_P(PTree T);
//�������ĸ��ڵ�ֵ

TElemType_P Value_P(PTree T,int i);
//�������е�i���ڵ�ֵ�����������

int Order_P(PTree T,TElemType_P e);
//���ؽ��e��ֵλ�ã�ָ�������е�λ��

Status Assign_P(PTree *T,TElemType_P e,TElemType_P value);
//�滻�ڵ�e��ֵΪvalue

TElemType_P ChildValue_P(PTree T,TElemType_P e,int order);
//���ؽ��e�ĵ�order�����ӵ�ֵ���������Ҽ���

TElemType_P Sibling_P(PTree T,TElemType_P e,int mark);
//����Ԫ��e���ֵܣ�mark�������

int ChildCount_P(PTree T,TElemType_P p);
//���غ��ӵ�������-1��ʾû��

int ChildSeat_P(PTree T,TElemType_P p,int i);
//������T��p�ڵ�ĵ�i�����ӣ�i=0����Ϊ���һ������

Status InsertChild_P(PTree *T,TElemType_P p,int i,TElemType_P e);
//���ڵ�e����Ϊ��T��p�ڵ�ĵ�i�����ӣ�i=0����Ϊ���һ������

Status InsertTree_P(PTree *T,TElemType_P p,int i,PTree t);
//����t���뵽T��p�ڵ�ĵ�i������

Status DeleteTree_P(PTree *T,TElemType_P p,int i);
//ɾ����T�нڵ�p�ĵ�i������

void LevelOrderTraverse_P(PTree T,void(Visit)(TElemType_P));
//���������

void Print_P(PTree T);

#endif


