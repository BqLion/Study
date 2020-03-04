//文件夹：05数组和广义表/02TripleSparseMarix


#ifndef TRIPLESPARSEMATRIX_H
#define TRIPLESPARSEMATRIX_H

#include <stdio.h>
#include<stdarg.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01Scanf.c"

#define MAXSIZE 400

//三元组系数矩阵类型定义
typedef int MElemType_TSq;
typedef struct
{
    int i,j;
    MElemType_TSq e;
}Triple;            //int i,j,e  三个整数，定义为一个三元的数据结构

typedef struct
{
    Triple data[MAXSIZE+1];             //一系列的三元数组，放满了表示矩阵元素在哪以及是多少的三元。
    int mu,nu,tu;                           //mu,nu,tu分别表示的是 矩阵的行数，列数，非零元个数
}TSMatrix;      //

Status CreateSMatrix_T(FILE *fp,int n,...);

void DestroySMatrix_T(TSMatrix *M);

void PrintSMatrix_T(TSMarix M);

void CopySMatrix_T(TSMatrix M,TSMatrix *T);

Status AddSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q);
//Q = M + N

Status SubSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q);
//Q = M - N

Status MultSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q);
//Q = M *  N

void TransposeSMatrix_T(TSMatrix M,TSMatrix *T);

void FastTransposeSMatrix_T(TSMatrix M,TSMatrix *T);
//矩阵快速转置

#endif










