//���ĺ�������+˫��˳���洢��ʾ

#ifndef CHILDTREE_H
#define CHILDTREE_H

#include<stdio.h>
#include<stdlib.h>
#include "E:/E/DS/C02/01SequenceList/Status.h"
#include "E:/E/DS/C02/01SequenceList/Scanf.c"
#include "E:/E/DS/C03/07LinkQueue/LinkQueue.c"
#include "E:/E/DS/C03/01SequenceStack/SequenceStack.c"

#define MAX_TREE_SIZE 100

//���ݽṹ��
//һ�����������ڵ�CTNode����child�������������е����꣩+ָ��ָ����һ��CTNode����
//һ��˫�ױ�ʾ�����ɵ�˳����ڵ���CTBode����parent��˫���������е����꣩+��������+ChildPtrָ����ͷ��ָ�빹��

typedef char TElemType_C;
typedef struct CTNode
{
    int child;
    struct CTNode* next;
}CTNode;

typedef CTNode* ChildPtr;
typedef struct
{
    int parent;
    TElemType_C data;
    ChildPtr firstchild;
}CTBox;
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int r;
    int n;
}CTree;

void InitTree_C(FILE *FP,CTree *T);

void ClearTree_C(CTree *T);

void DestroyTree_C(CTree *T);

Status TreeEmpty_C(CTree T);

Status CreateTree_C(FILE *fp,CTree *T);

int TreeDegree_C(CTree T);

int TreeDepth_C_1(CTree T);

int TreeDepth_C_2(CTree T);

int Depth_C(CTree T,int i);

TElemType_C Root_C(CTree T);

TElemType_C Value_C(CTree T,int i);
//�������е�i���ڵ�ֵ�����������

int Order_C(CTree T,TElemType_C e);
//���ؽ��e��λ��

Status Assign_C(CTree *T,TElemType_C e,TElemType_C value);
//�滻�ڵ�e��ֵΪvalue

TElemType_C ChildValue_C(CTree T,TElemType_C e,int order);
//����e�ĵ�order�����ӵ�ֵ���������Ҽ�����

TElemType_C Sibling_C_1(CTree T,TElemType_C e,int mark);

int Sibling_C_2(CTree T,int order,int mark);

int ChildCount_C(CTree T,TElemType_C p);
//���ؽ��p�ĺ��Ӹ���

int ChildSeat_C(CTree T,TElemType_C p,int i);
//����T��p�ڵ�ĵ�i������

ChildPtr SiblingSeat_C(CTree T,TElemType_C p);
//���غ�����������ָ��Ԫ��p��ָ��

Status InsertChild_C(CTree *T,TElemType_C p,int i ,TElemType_C e);

Status InsertTree_C(CTree *T,TElemType_C p,int i,CTree t);

Status DeleteTree_C(CTree *T,TElemType_C p,int i);

void LevelOrderTraverse_C(CTree T,void(Visit)(TElemType_C));

void Print_C_1(CTree T);

void Print_C_2(CTree T,int start,int step);

void ShowTree_C(CTree T);
//չʾ���Ĵ洢�ṹ

#endif



