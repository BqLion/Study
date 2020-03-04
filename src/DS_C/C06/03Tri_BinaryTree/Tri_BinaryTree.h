/************************

文件夹：06 树和二叉树 、03Tri_BinaryTree

文件名：Tri_BinaryTree.h

内容：二叉树三叉链表存储结构相关操作列表

*************************/

#ifndef TRI_BINARYTREE_H
#define TRI_BINARYTREE_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"


//二叉树三叉链表数据结构定义

typedef char TElemType_Tri;
typedef struct TBiTNode
{
    TElemType_Tri data;                  //节点 元素
    struct TBiTNode* parent;          //双亲节点指针
    struct TBiTNode* lchild;           //左孩子指针
    struct TBiTNode* rchild;           //右孩子指针
}TBiTNode;                                    //二叉树节点
typedef TBiTNode* TBiTree;         //指向二叉树节点的指针

typedef TBiTNode* TBiTree;        //指向二叉树节点的指针

typedef TBiTree QElemType_L;

#include "E:/E/DS/C03/07LinkQueue/LinkQueue.c"

void InitBiTree_Tri(TBiTree *T);
//构造空二叉树

void ClearBiTree_Tri(TBiTree *T);

void DestroyBiTree_Tri(TBiTree *T);

Status BiTreeEmpty_Tri(TBiTree T);

void Create_Tri(TBiTree *T,FILE *fp);

Status CreateBiTree_Tri(FILE *fp,TBiTree *T);
//先序序列构造二叉树

int BiTreeLength_Tri(TBiTree T);
//返回二叉树长度

int BiTreeDepth_Tri(TBiTree T);
//返回二叉树深度

Status Root_Tri(TBiTree T,TElemType_Tri *e);
//用e返回二叉树的根节点值

TElemType_Tri Value_Tri(TBiTree p);
//返回某节点的值，p为节点指针

void Assign_Tri(TBiTree p,TElemType_Tri value);
//为p所指的结点赋值

TBiTree Point(TBiTree T,TElemType_Tri e);
//返回指向T的结点的指针

TElemType_Tri Parent_Tri(TBiTree T,TElemType_Tri e);
//返回某节点的双亲节点值

TElemType_Tri LeftChild_Tri(TBiTree T,TElemType_Tri e);

TElemType_Tri RightChild_Tri(TBiTree T,TElemType_Tri e);

TElemType_Tri LeftSibling_Tri(TBiTree T,TElemType_Tri e);

TElemType_Tri RightSibling_Tri(TBiTree T,TElemType_Tri e);

Status InsertBiTree_Tri(TBiTree T,TElemType_Tri e,TBiTree *T0,int LR);
//将树T0插入到树T中成为节点e的子树，LR为插入标记

Status DeleteBiTree_Tri(TBiTree T,TElemType_Tri e,int LR);

void LevelOrderTraverse_Tri(TBiTree T,void(Visit)(TElemType_Tri));
//层序遍历二叉树

void PreOrderTraverse_Tri(TBiTree T,void(Visit)(TElemType_Tri));
//前序遍历二叉树

void InOrderTraverse_Tri(TBiTree T,void(Visit)(TElemType_Tri));

void PostOrderTraverse_Tri(TBiTree T,void(Visit)(TElemType_Tri));
//后序遍历二叉树

void Print_Tri(TBiTree T);
//打印

#endif // TRI_BINARYTREE_H












