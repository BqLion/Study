/***************************

文件夹：06树和二叉树 04/ThreadBinaryTree

文件名：ThreadBinaryTree.h

内容：线索二叉树相关操作列表

***************************/

#ifndef THREADBINARYTREE_H
#define THREADBINARYTREE_H

#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"

//线索二叉树类型定义
typedef char TElemType_Thr;
typedef enum {Link,Thread}PointerTag;       //link是0，代表正常指向孩子，Thread是1，代表指向线索
typedef struct ThrBiNode
{
    TElemType_Thr data;
    struct ThrBiNode *lchild;           //左右孩子指针，左右标志，双亲节点
    struct ThrBiNode *rchild;
    PointerTag LTag;
    PointerTag RTag;
    struct ThrBiNode *parent;
}ThrBiNode;
typedef ThrBiNode* ThrBiTree;

ThrBiTree pre;      //全局变量

Status CreateBiTree_Thr(FILE *fp,ThrBiTree *T);

void InTheading_Thr(ThrBiTree p);
//中序全线索化

Status InOrderThreading_Thr(ThrBiTree *Thrt,ThrBiTree T);
//中序遍历二叉树T，全线索化

Status InOrderTraverse_Thr(ThrBiTree Thrt,void(Visit)(TElemType_Thr));
//中序遍历二叉树T，全线索话，非递归算法

void PreTreading_Thr(ThrBiTree p);
//先序后继线索化

Status PreOrderThreading_Thr(ThrBiTree *Thrt,ThrBiTree T);
//先序遍历二叉树T，并将其后继线索化

Status PreOrderTraverse_Thr(ThrBiTree Thrt,void(Visit)(TElemType_Thr));
//先序遍历，前序后继线索二叉树，（非递归算法）

void PosTheading_Thr(ThrBiTree p);
//后序 后继线索化

Status PosOrderThreading_Thr(ThrBiTree *Thrt,ThrBiTree T);
//后序遍历二叉树T，并将其后继线索话

Status PosOrderTraverse_Thr(ThrBiTree Thrt,void(Visit)(TElemType_Thr));
//后序遍历后序后继线索二叉树，非递归算法

void ParentPtr_Thr(ThrBiTree Thrt);
//层序遍历二叉树建立各节点的双亲节点指针

ThrBiTree Pos_NextPtr_Thr(ThrBiTree Thrt,ThrBiTree p);
//在后序遍历后序后继线索二叉树时，寻找节点p的后继

#endif
