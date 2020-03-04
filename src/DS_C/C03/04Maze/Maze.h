/**********************

迷宫寻路算法：穷举法

对每一条可能的通道都做出探索，直到找到出去的路。

在穷举遍历中，需要保存来时的路径，如果后边遇到错误的路径，则需要回退到上一次正确的状态，这个“回退”的动作就是运用栈这个数据结构的好时机

**********************/

/*

文件夹:C03/04Maze

Maze.h

内容：迷宫相关操作列表

*/

#ifndef MAZE_H
#define MAZE_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//宏定义

#define N 15        //N是迷宫大小N*N
#define X 4          //X 用于随机数取余，生成的随机数范围是0到X-1

#define SleepTime 2     //休眠时间间隔

//迷宫类型定义
typedef enum                    //枚举类型
{
    Wall,                               //外墙
    Obstacle,                       //障碍物
    Way,                            //路径
    DeadLock,                       //路径上的死胡同
    East,South,West,North   //访问方向，东南西北
}MazeNode;

typedef struct
{
    int x;
    int y;
}PosType;           //通道块的横纵坐标定义

typedef struct                  //通道块的各种信息
{
    int ord;                    // 通道块的“序号”
    PosType seat;          //通道块的坐标位置，这个PosType 就是上边定义的struct
    int di;                         //方位，东南西北
}SElemType_Sq;

#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"
typedef int MazeType;           //迷宫元素类型

//迷宫函数列表
Status MazePath(MazeType maze[][N],PosType start,PosType end);

//迷宫寻路算法（穷举法）

void InitMaze(MazeType maze[][N],PosType *start,PosType *end);
//迷宫的初始化，包括出口入口的初始化（都通过传递进来的出口 入口参数确定了，迷宫的带下也由MazeType maze【】【N】确定了）

void PrintMaze(MazeType maze[][N]);
//在屏幕上画出迷宫

void ShowMaze(MazeType maze[][N]);
//迷宫的显示

Status EqualPosType(PosType a,PosType b);
//比较迷宫中两个通道块是否是同一通道块

Status Pass(PosType seat,MazeType Maze[][N]);
//判断此通道块是否未被访问

void FootPrint(PosType seat,MazeType maze[][N]);
//遇到未访问节点时留下初始的足迹

void SetElemType(SElemType_Sq *e,int ord,PosType seat,int di);
//更新通道块的信息

PosType NextPos(PosType seat,int di);
//当前通道块的后继

Status IsCross(PosType seat);
//判断当前位置是否越界

void MarkPrint(PosType seat,MazeType maze[][N]);
//标记当前位置上的通道块不可访问

#endif // MAZE_H








