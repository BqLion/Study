/****************

文件夹06树和二叉树

SeqBinaryTree.h

内容：二叉树顺序存储结构相关操作列表

**************/

#ifndef  SEQBINARYTREE_H
#define SEQBINARYTREE_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"

#define MAX_TREE_SIZE 100

//二叉树(顺序存储结构)相关类型定义
typedef char TElemType_Sq;
typedef TElemType_Sq SqBiTree[MAX_TREE_SIZE];

typedef struct
{
    int level;              //节点所在层
    int order;             //节点在本层的编号
}Position;              //所谓节点的编号（存储结构是数组）

void InitBiTree_Sq(SqBiTree T);

void ClearBiTree_Sq(SqBiTree T);

void DestroyBiTree_Sq(SqBiTree T);

Status BiTreeeEmpty_Sq(SqBiTree T);

Status CreateBiTree_Le_Sq(FILE *fp,SqBiTree T);
//层序
Status CreateBiTree_Pre_Sq(FILE *fp,SqBiTree T,int i);
//先序
int BiTreeLength_Sq(SqBiTree T);
//返回二叉树长度
int BiTreeDepth_Sq(SqBiTree T);

Status Root_Sq(SqBiTree T,TElemType_Sq *e);
 //返回二叉树的跟

 TElemType_Sq Value_Sq(SqBiTree T,Position s);
 //返回树中某位置的结点值

 Status Assign_Sq(SqBiTree T,Position s,TElemType_Sq value);
 //给书中某位置的结点赋值

 TElemType_Sq Parent_Sq(SqBiTree T,TElemType_Sq e);
 //返回双亲节点值

 TElemType_Sq LeftChild_Sq(SqBiTree T,TElemType_Sq e);
 //返回某节点的左孩子节点值

 TElemType_Sq RightChild_Sq(SqBiTree T,TElemType_Sq e);
 //返回某节点的右孩子节点值

 TElemType_Sq LeftChild_Sq(SqBiTree T,TElemType_Sq e);
 //返回某节点的左兄弟节点值

 TElemType_Sq LeftChild_Sq(SqBiTree T,TElemType_Sq e);
 //返回某节点的右兄弟节点值

 void LevelOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq));
 //层 序 遍历

 void PreOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq),int i);
 //前 序 遍历

  void InlOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq));
 //中 序 遍历

 void PostOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq));
 //后 序 遍历

void Print_Sq(SqBiTree T);

#endif


