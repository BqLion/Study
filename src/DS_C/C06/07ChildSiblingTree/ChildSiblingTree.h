//���Ķ�����������-�ֵܱ�ʾ����

#ifndef CHILDSIBLINGTREE_H
#define CHILDSIBLINGTREE_H

#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"

//���ݽṹ����

typedef char TElemType_CS;
typedef struct CSNode
{
    TElemType_CS data;
    struct CSNode* firstchild;
    struct CSNode* nextsibling;
}CSNode;

typedef CSNode* CSTree;

typedef CSTree SElemType_Sq;

#include "E:/E/DS/C03/01SequenceStack/SequenceStack.c"

void InitTree_CS(CSTree *T);

void ClearTree_CS(CSTree *T);

void DestroyTree_CS(CSTree *T);

Status TreeEmpty_CS(CSTree T);

Status CreateTree_CS(FILE *fp,CSTree *T);

int TreeDegree_CS(CSTree T);

int TreeDepth_CS(CSTree T);

TElemType_CS Root_CS(CSTree T);

TElemType_CS Value_CS(CSTree T,int i);

CSTree Order_CS(CSTree T,TElemType_CS e);
//����ָ��ڵ�e��ָ��

Status Assign_CS(CSTree T,TElemType_CS E,TElemType_CS value);
//�滻�ڵ�e��ֵΪvalue

TElemType_CS ChildValue_CS(CSTree T,TElemType_CS e,int order);

TElemType_CS Sibling_CS(CSTree T,TElemType_CS e,int mark);

int ChildCount_CS(CSTree T,TElemType_CS p);

CSTree ChildSeat_CS(CSTree T,TElemType_CS e,int i);

Status InsertTree_CS(CSTree T,TElemType_CS e,int i,CSTree t);

Status DeleteTree_CS(CSTree T,TElemType_CS e,int i);

void LevelOrderTraverse_CS(CSTree T,void(Visit)(TElemType_CS));

void PreOrderTraverse_CS(CSTree T,void(Visit)(TElemType_CS));

void InOrderTraverse_CS(CSTree T,void(Visit)(TElemType_CS));

void Print_CS(CSTree T);

#endif



