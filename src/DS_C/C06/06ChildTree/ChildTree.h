//树的孩子链表+双亲顺序表存储表示

#ifndef CHILDTREE_H
#define CHILDTREE_H

#include<stdio.h>
#include<stdlib.h>
#include "E:/E/DS/C02/01SequenceList/Status.h"
#include "E:/E/DS/C02/01SequenceList/Scanf.c"
#include "E:/E/DS/C03/07LinkQueue/LinkQueue.c"
#include "E:/E/DS/C03/01SequenceStack/SequenceStack.c"

#define MAX_TREE_SIZE 100

//数据结构：
//一个孩子链表，节点CTNode，由child（孩子在数组中的坐标）+指针指向下一个CTNode构成
//一个双亲表示法构成的顺序表。节点是CTBode，由parent（双亲在数组中的坐标）+本身数据+ChildPtr指向孩子头的指针构成

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
//返回树中第i个节点值，按层序计数

int Order_C(CTree T,TElemType_C e);
//返回结点e的位置

Status Assign_C(CTree *T,TElemType_C e,TElemType_C value);
//替换节点e的值为value

TElemType_C ChildValue_C(CTree T,TElemType_C e,int order);
//返回e的第order个孩子的值（从左往右计数）

TElemType_C Sibling_C_1(CTree T,TElemType_C e,int mark);

int Sibling_C_2(CTree T,int order,int mark);

int ChildCount_C(CTree T,TElemType_C p);
//返回结点p的孩子个数

int ChildSeat_C(CTree T,TElemType_C p,int i);
//返回T中p节点的第i个孩子

ChildPtr SiblingSeat_C(CTree T,TElemType_C p);
//返回孩子在链表中指向元素p的指针

Status InsertChild_C(CTree *T,TElemType_C p,int i ,TElemType_C e);

Status InsertTree_C(CTree *T,TElemType_C p,int i,CTree t);

Status DeleteTree_C(CTree *T,TElemType_C p,int i);

void LevelOrderTraverse_C(CTree T,void(Visit)(TElemType_C));

void Print_C_1(CTree T);

void Print_C_2(CTree T,int start,int step);

void ShowTree_C(CTree T);
//展示树的存储结构

#endif



