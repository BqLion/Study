/**********************************

文件：MPSet.h

内容：并查集相关操作列表

**********************************/

#ifndef MFSET_H
#define MFSET_H

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"

//并查集：将所有元素单个化，再按之前的关系一一归并成几个大的集合

typedef int TElemType_P;
#include"E:/E/DS/C06/05ParentTree/ParentTree.c"           //用的是双亲树的表示法

//双亲表示法的结点是 int data + int parent,如下注释所示
/*********************
typedef struct PTNode
{
    TElemType_P data;
    int parent;
}PTNode;               //树的结点
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int n;          //树的结点数
}PTree;                 //树本身
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
//查找集合S中i所在子集的跟

Status merge_mfset(MFSet *S,int i,int j);
//求Si Sj的并集

Status mix_mfset(MFSet *S,int i,int j);
//集合归并函数，上一个归并函数的改进版

int fix_mfset(MFSet *S,int i);
//查找集合S中i所在子集的根，改进版

Status  BuildRelation_mfset(FILE *fp,Relation *R);
//建立二元等价关系

int EquivalenceClass_mfset_1(MFSet *S,Relation R);
//求在等价关系R下集合S的等价类

int SubsetCount_mfset(MFSet S);

void ShowSet_mfset(MFSet S);

#endif



