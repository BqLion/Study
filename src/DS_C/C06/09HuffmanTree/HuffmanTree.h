//HuffmaTree.h

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SeuqenceList/Scanf.c"

#define MAX_TREE_SIZE 100

typedef struct
{
    unsigned int weight;
    unsigned int parent;
    unsigned int lchild;
    unsigned int rchild;
}HTNode;

typedef HTNode* HuffmanTree;
typedef char* HCNode;
typedef HCNode* HuffmanCode;

void InitTree_HT(HuffmanTree *HT);

Status CreateHuffmanTree_HT(FILE *fp,HuffmanTree *HT);

Status Select_HT(HuffmanTree HT,int end,int *order_1,int *order_2);
//�ڹ��������ڵ�������ѡ��Ȩֵ��С��δ�������������ڵ����ţ�order_1,order_2

Status HuffmanCodeing_HT_1(HuffmanTree HT,HuffmanCode *HC);
//����������������ֵ

Status HuffmanCodeing_HT_2(HuffmanTree HT,HuffmanCode *HC)��

void ShowHuffmanTree_HT(HuffmanTree HT);
//չʾ��������

void ShowHuffmanCode_HT(HuffmanTree HT,HuffmanCode HC);

#endif

