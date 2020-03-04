//树和二叉树

//N皇后问题

#ifndef NQUEENS_H
#define NQUUENS_H

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

#define N 8

typedef int ChessBoard;

int order;

void InitChessBoard_CB(ChessBoard c[N][N]);

void Trial_CB(int i,ChessBoard c[N][N]);
//在指定大小棋盘上求出N皇后问题的各解

Status Layout_CB(int x,int y,ChessBoard c[N][N]);
//判断在x行y列放入棋子后棋盘布局是否合理

void Output_CB(ChessBoard c[N][N]);
//展示棋盘的布局

#endif
