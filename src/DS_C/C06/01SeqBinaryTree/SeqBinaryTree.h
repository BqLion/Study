/****************

�ļ���06���Ͷ�����

SeqBinaryTree.h

���ݣ�������˳��洢�ṹ��ز����б�

**************/

#ifndef  SEQBINARYTREE_H
#define SEQBINARYTREE_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"

#define MAX_TREE_SIZE 100

//������(˳��洢�ṹ)������Ͷ���
typedef char TElemType_Sq;
typedef TElemType_Sq SqBiTree[MAX_TREE_SIZE];

typedef struct
{
    int level;              //�ڵ����ڲ�
    int order;             //�ڵ��ڱ���ı��
}Position;              //��ν�ڵ�ı�ţ��洢�ṹ�����飩

void InitBiTree_Sq(SqBiTree T);

void ClearBiTree_Sq(SqBiTree T);

void DestroyBiTree_Sq(SqBiTree T);

Status BiTreeeEmpty_Sq(SqBiTree T);

Status CreateBiTree_Le_Sq(FILE *fp,SqBiTree T);
//����
Status CreateBiTree_Pre_Sq(FILE *fp,SqBiTree T,int i);
//����
int BiTreeLength_Sq(SqBiTree T);
//���ض���������
int BiTreeDepth_Sq(SqBiTree T);

Status Root_Sq(SqBiTree T,TElemType_Sq *e);
 //���ض������ĸ�

 TElemType_Sq Value_Sq(SqBiTree T,Position s);
 //��������ĳλ�õĽ��ֵ

 Status Assign_Sq(SqBiTree T,Position s,TElemType_Sq value);
 //������ĳλ�õĽ�㸳ֵ

 TElemType_Sq Parent_Sq(SqBiTree T,TElemType_Sq e);
 //����˫�׽ڵ�ֵ

 TElemType_Sq LeftChild_Sq(SqBiTree T,TElemType_Sq e);
 //����ĳ�ڵ�����ӽڵ�ֵ

 TElemType_Sq RightChild_Sq(SqBiTree T,TElemType_Sq e);
 //����ĳ�ڵ���Һ��ӽڵ�ֵ

 TElemType_Sq LeftChild_Sq(SqBiTree T,TElemType_Sq e);
 //����ĳ�ڵ�����ֵܽڵ�ֵ

 TElemType_Sq LeftChild_Sq(SqBiTree T,TElemType_Sq e);
 //����ĳ�ڵ�����ֵܽڵ�ֵ

 void LevelOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq));
 //�� �� ����

 void PreOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq),int i);
 //ǰ �� ����

  void InlOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq));
 //�� �� ����

 void PostOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq));
 //�� �� ����

void Print_Sq(SqBiTree T);

#endif


