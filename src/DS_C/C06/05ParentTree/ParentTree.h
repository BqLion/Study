//树的双亲表示法

//不同于二叉树，二叉树默认两个孩子域的话就是孩子表示法，加上双亲就是双亲孩子双链表表示fa

//这里的树是更一般的树，包含二叉树

//用一个数组把data顺序装进去，同时有一个空间专门储存节点对应的parent下标

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
}PTNode;               //树的结点
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int n;          //树的结点数
}PTree;                 //树本身

void InitTree_P(PTree *T);

void ClearTree_P(PTree *T);

void DestroyTree(PTree *T);

Status TreeEmpty_P(PTree T);

Status CreateTree_P(FILE *fp,PTree *T);
//按照层序序列构造树

int TreeDegree_P(PTree T);
//树的度

int TreeDepth_P(PTree T);

TElemType_P Root_P(PTree T);
//返回树的根节点值

TElemType_P Value_P(PTree T,int i);
//返回树中第i个节点值（层序计数）

int Order_P(PTree T,TElemType_P e);
//返回结点e的值位置，指在数组中的位置

Status Assign_P(PTree *T,TElemType_P e,TElemType_P value);
//替换节点e的值为value

TElemType_P ChildValue_P(PTree T,TElemType_P e,int order);
//返回结点e的第order个孩子的值，从左往右计数

TElemType_P Sibling_P(PTree T,TElemType_P e,int mark);
//返回元素e的兄弟，mark标记左右

int ChildCount_P(PTree T,TElemType_P p);
//返回孩子的数量，-1表示没有

int ChildSeat_P(PTree T,TElemType_P p,int i);
//返回树T中p节点的第i个孩子，i=0定义为最后一个孩子

Status InsertChild_P(PTree *T,TElemType_P p,int i,TElemType_P e);
//将节点e插入为树T中p节点的第i个孩子，i=0定义为最后一个孩子

Status InsertTree_P(PTree *T,TElemType_P p,int i,PTree t);
//将树t插入到T中p节点的第i棵子树

Status DeleteTree_P(PTree *T,TElemType_P p,int i);
//删除树T中节点p的第i棵子树

void LevelOrderTraverse_P(PTree T,void(Visit)(TElemType_P));
//层序遍历树

void Print_P(PTree T);

#endif


