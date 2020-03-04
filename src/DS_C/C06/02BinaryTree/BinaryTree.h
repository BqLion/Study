//二叉树

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"

//二叉树相关类型定义

typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode;
typedef BiTNode* BiTree;                //二叉树节点

typedef BiTree SElemType_Sq;        //指向此二叉树节点的指针
#include "E:/E/DS/C03/01SequenceStack/SequenceStack.c"

typedef struct
{
    BiTree left;
    BiTree right;
    int n;
}Node;              //包含了当前节点的左指针，右指针，以及当前节点的次序

void InitBiTree(BiTree *T);

void ClearBiTree(BiTree *T);

 void DestroyBiTree(BiTree *T);

 Status BiTreeEmpty(BiTree T);

 Status CreateBiTree(FILE *fp,BiTree *T);

 int BiTreeLength(BiTree T);

 int BiTreeDepth(BiTree T);

 Status Root(BiTree T,TElemType *e);
 //e返回二叉树的根结点值

 TElemType Value(BiTree p);
 //返回某节点的值，p为节点指针

 void Assign(BiTree p,TElemType value);
 //为某节点赋值，p为节点指针

 TElemType Parent(BiTree T,TElemType e);
 //返回某节点的双亲节点值

 TElemType LeftChild(BiTree T,TElemType e);
 //返回某节点的左孩子结点值

 TElemType RightChild(BiTree T,TElemType e);

 TElemType LeftSibling(BiTree T,TElemType e);

 TElemType RightSibling(BiTree T,TElemType e);

  BiTree LocationBiTree_1(BiTree T,TElemType e);
  //获取指向节点e的指针

  BiTree LocationBiTree_2(BiTree T,TElemType e);

  Status InsertBiTree(BiTree T,TElemType e,BiTree T0,int LR);
  //将T0插入到树T中成为节点e的子树，LR为插入标记，T0只有左子树

  Status DeleteBiTree(BiTree T,TElemType e,int LR);
  //删除e节点的左子树或右子树，LR为删除标记

  void LevelOrderTraverse(BiTree T,void(Visit)(TElemType));
  //层序遍历二叉树

  void PreOrderTraverse_1(BiTree T,void(Visit)(TElemType));
  //先序遍历二叉树

  Status PreOrderTraveser_2(BiTree T,Status(Visit)(TElemType));
  //先序遍历二叉树

  Status Root(BiTree T,TElemType *e);
  //用e返回二叉树的根节点值

  TElemType Value(BiTree p);
  //返回某节点的值，p为节点指针

  void Assign(BiTree p,TElemType value);
  //为某节点赋值，p为指针节点

TElemType Parent(BiTree T,TElemType e);
//返回某节点的双亲节点值

TElemType LeftChild(BiTree T,TElemType e);

TElemType RightChild(BiTree T,TElemType e);

TElemType LeftSibling(BiTree T,TElemType e);

TElemType RightSibling(BiTree T,TElemType e);

BiTree LocationBiTree_1(BiTree T,TElemType e);
//获取指向节点e的指针

BiTree LocationBiTree_2(BiTree T,TElemType e);
//获取指向节点e的之恩

Status InsertBiTree(BiTree T,TElemType e,BiTree T0,int LR);
//将树T0插入到树T中成为节点e的子树，LR为插入标记，T0只有左子树

Status DeleteBiTree(BiTree T,TElemType e,int LR);
//删除e节点的左子树或右子树，LR为删除标记

void LevelOrderTraverse(BiTree,void(Visit)(TElemType));
//层序遍历二叉树

void PreOrderTraverse_1(BiTree T,void(Visit)(TElemType));

Status PreOrderTraveser_2(BiTree T,Status(Visit)(TElemType));
//先序遍历二叉树

#endif // BINARYTREE_H


















