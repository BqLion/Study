//������

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"

//������������Ͷ���

typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
}BiTNode;
typedef BiTNode* BiTree;                //�������ڵ�

typedef BiTree SElemType_Sq;        //ָ��˶������ڵ��ָ��
#include "E:/E/DS/C03/01SequenceStack/SequenceStack.c"

typedef struct
{
    BiTree left;
    BiTree right;
    int n;
}Node;              //�����˵�ǰ�ڵ����ָ�룬��ָ�룬�Լ���ǰ�ڵ�Ĵ���

void InitBiTree(BiTree *T);

void ClearBiTree(BiTree *T);

 void DestroyBiTree(BiTree *T);

 Status BiTreeEmpty(BiTree T);

 Status CreateBiTree(FILE *fp,BiTree *T);

 int BiTreeLength(BiTree T);

 int BiTreeDepth(BiTree T);

 Status Root(BiTree T,TElemType *e);
 //e���ض������ĸ����ֵ

 TElemType Value(BiTree p);
 //����ĳ�ڵ��ֵ��pΪ�ڵ�ָ��

 void Assign(BiTree p,TElemType value);
 //Ϊĳ�ڵ㸳ֵ��pΪ�ڵ�ָ��

 TElemType Parent(BiTree T,TElemType e);
 //����ĳ�ڵ��˫�׽ڵ�ֵ

 TElemType LeftChild(BiTree T,TElemType e);
 //����ĳ�ڵ�����ӽ��ֵ

 TElemType RightChild(BiTree T,TElemType e);

 TElemType LeftSibling(BiTree T,TElemType e);

 TElemType RightSibling(BiTree T,TElemType e);

  BiTree LocationBiTree_1(BiTree T,TElemType e);
  //��ȡָ��ڵ�e��ָ��

  BiTree LocationBiTree_2(BiTree T,TElemType e);

  Status InsertBiTree(BiTree T,TElemType e,BiTree T0,int LR);
  //��T0���뵽��T�г�Ϊ�ڵ�e��������LRΪ�����ǣ�T0ֻ��������

  Status DeleteBiTree(BiTree T,TElemType e,int LR);
  //ɾ��e�ڵ������������������LRΪɾ�����

  void LevelOrderTraverse(BiTree T,void(Visit)(TElemType));
  //�������������

  void PreOrderTraverse_1(BiTree T,void(Visit)(TElemType));
  //�������������

  Status PreOrderTraveser_2(BiTree T,Status(Visit)(TElemType));
  //�������������

  Status Root(BiTree T,TElemType *e);
  //��e���ض������ĸ��ڵ�ֵ

  TElemType Value(BiTree p);
  //����ĳ�ڵ��ֵ��pΪ�ڵ�ָ��

  void Assign(BiTree p,TElemType value);
  //Ϊĳ�ڵ㸳ֵ��pΪָ��ڵ�

TElemType Parent(BiTree T,TElemType e);
//����ĳ�ڵ��˫�׽ڵ�ֵ

TElemType LeftChild(BiTree T,TElemType e);

TElemType RightChild(BiTree T,TElemType e);

TElemType LeftSibling(BiTree T,TElemType e);

TElemType RightSibling(BiTree T,TElemType e);

BiTree LocationBiTree_1(BiTree T,TElemType e);
//��ȡָ��ڵ�e��ָ��

BiTree LocationBiTree_2(BiTree T,TElemType e);
//��ȡָ��ڵ�e��֮��

Status InsertBiTree(BiTree T,TElemType e,BiTree T0,int LR);
//����T0���뵽��T�г�Ϊ�ڵ�e��������LRΪ�����ǣ�T0ֻ��������

Status DeleteBiTree(BiTree T,TElemType e,int LR);
//ɾ��e�ڵ������������������LRΪɾ�����

void LevelOrderTraverse(BiTree,void(Visit)(TElemType));
//�������������

void PreOrderTraverse_1(BiTree T,void(Visit)(TElemType));

Status PreOrderTraveser_2(BiTree T,Status(Visit)(TElemType));
//�������������

#endif // BINARYTREE_H


















