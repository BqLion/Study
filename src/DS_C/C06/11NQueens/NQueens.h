//���Ͷ�����

//N�ʺ�����

#ifndef NQUEENS_H
#define NQUUENS_H

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

#define N 8

typedef int ChessBoard;

int order;

void InitChessBoard_CB(ChessBoard c[N][N]);

void Trial_CB(int i,ChessBoard c[N][N]);
//��ָ����С���������N�ʺ�����ĸ���

Status Layout_CB(int x,int y,ChessBoard c[N][N]);
//�ж���x��y�з������Ӻ����̲����Ƿ����

void Output_CB(ChessBoard c[N][N]);
//չʾ���̵Ĳ���

#endif
