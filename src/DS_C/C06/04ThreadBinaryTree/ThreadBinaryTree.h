/***************************

�ļ��У�06���Ͷ����� 04/ThreadBinaryTree

�ļ�����ThreadBinaryTree.h

���ݣ�������������ز����б�

***************************/

#ifndef THREADBINARYTREE_H
#define THREADBINARYTREE_H

#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/Scanf.c"

//�������������Ͷ���
typedef char TElemType_Thr;
typedef enum {Link,Thread}PointerTag;       //link��0����������ָ���ӣ�Thread��1������ָ������
typedef struct ThrBiNode
{
    TElemType_Thr data;
    struct ThrBiNode *lchild;           //���Һ���ָ�룬���ұ�־��˫�׽ڵ�
    struct ThrBiNode *rchild;
    PointerTag LTag;
    PointerTag RTag;
    struct ThrBiNode *parent;
}ThrBiNode;
typedef ThrBiNode* ThrBiTree;

ThrBiTree pre;      //ȫ�ֱ���

Status CreateBiTree_Thr(FILE *fp,ThrBiTree *T);

void InTheading_Thr(ThrBiTree p);
//����ȫ������

Status InOrderThreading_Thr(ThrBiTree *Thrt,ThrBiTree T);
//�������������T��ȫ������

Status InOrderTraverse_Thr(ThrBiTree Thrt,void(Visit)(TElemType_Thr));
//�������������T��ȫ���������ǵݹ��㷨

void PreTreading_Thr(ThrBiTree p);
//������������

Status PreOrderThreading_Thr(ThrBiTree *Thrt,ThrBiTree T);
//�������������T����������������

Status PreOrderTraverse_Thr(ThrBiTree Thrt,void(Visit)(TElemType_Thr));
//���������ǰ�������������������ǵݹ��㷨��

void PosTheading_Thr(ThrBiTree p);
//���� ���������

Status PosOrderThreading_Thr(ThrBiTree *Thrt,ThrBiTree T);
//�������������T����������������

Status PosOrderTraverse_Thr(ThrBiTree Thrt,void(Visit)(TElemType_Thr));
//��������������������������ǵݹ��㷨

void ParentPtr_Thr(ThrBiTree Thrt);
//��������������������ڵ��˫�׽ڵ�ָ��

ThrBiTree Pos_NextPtr_Thr(ThrBiTree Thrt,ThrBiTree p);
//�ں����������������������ʱ��Ѱ�ҽڵ�p�ĺ��

#endif
