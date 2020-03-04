/************************

�ļ��У�06 ���Ͷ����� ��03Tri_BinaryTree

�ļ�����Tri_BinaryTree.h

���ݣ���������������洢�ṹ��ز����б�

*************************/

#ifndef TRI_BINARYTREE_H
#define TRI_BINARYTREE_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"


//�����������������ݽṹ����

typedef char TElemType_Tri;
typedef struct TBiTNode
{
    TElemType_Tri data;                  //�ڵ� Ԫ��
    struct TBiTNode* parent;          //˫�׽ڵ�ָ��
    struct TBiTNode* lchild;           //����ָ��
    struct TBiTNode* rchild;           //�Һ���ָ��
}TBiTNode;                                    //�������ڵ�
typedef TBiTNode* TBiTree;         //ָ��������ڵ��ָ��

typedef TBiTNode* TBiTree;        //ָ��������ڵ��ָ��

typedef TBiTree QElemType_L;

#include "E:/E/DS/C03/07LinkQueue/LinkQueue.c"

void InitBiTree_Tri(TBiTree *T);
//����ն�����

void ClearBiTree_Tri(TBiTree *T);

void DestroyBiTree_Tri(TBiTree *T);

Status BiTreeEmpty_Tri(TBiTree T);

void Create_Tri(TBiTree *T,FILE *fp);

Status CreateBiTree_Tri(FILE *fp,TBiTree *T);
//�������й��������

int BiTreeLength_Tri(TBiTree T);
//���ض���������

int BiTreeDepth_Tri(TBiTree T);
//���ض��������

Status Root_Tri(TBiTree T,TElemType_Tri *e);
//��e���ض������ĸ��ڵ�ֵ

TElemType_Tri Value_Tri(TBiTree p);
//����ĳ�ڵ��ֵ��pΪ�ڵ�ָ��

void Assign_Tri(TBiTree p,TElemType_Tri value);
//Ϊp��ָ�Ľ�㸳ֵ

TBiTree Point(TBiTree T,TElemType_Tri e);
//����ָ��T�Ľ���ָ��

TElemType_Tri Parent_Tri(TBiTree T,TElemType_Tri e);
//����ĳ�ڵ��˫�׽ڵ�ֵ

TElemType_Tri LeftChild_Tri(TBiTree T,TElemType_Tri e);

TElemType_Tri RightChild_Tri(TBiTree T,TElemType_Tri e);

TElemType_Tri LeftSibling_Tri(TBiTree T,TElemType_Tri e);

TElemType_Tri RightSibling_Tri(TBiTree T,TElemType_Tri e);

Status InsertBiTree_Tri(TBiTree T,TElemType_Tri e,TBiTree *T0,int LR);
//����T0���뵽��T�г�Ϊ�ڵ�e��������LRΪ������

Status DeleteBiTree_Tri(TBiTree T,TElemType_Tri e,int LR);

void LevelOrderTraverse_Tri(TBiTree T,void(Visit)(TElemType_Tri));
//�������������

void PreOrderTraverse_Tri(TBiTree T,void(Visit)(TElemType_Tri));
//ǰ�����������

void InOrderTraverse_Tri(TBiTree T,void(Visit)(TElemType_Tri));

void PostOrderTraverse_Tri(TBiTree T,void(Visit)(TElemType_Tri));
//�������������

void Print_Tri(TBiTree T);
//��ӡ

#endif // TRI_BINARYTREE_H












