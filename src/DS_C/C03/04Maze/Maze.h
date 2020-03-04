/**********************

�Թ�Ѱ·�㷨����ٷ�

��ÿһ�����ܵ�ͨ��������̽����ֱ���ҵ���ȥ��·��

����ٱ����У���Ҫ������ʱ��·�������������������·��������Ҫ���˵���һ����ȷ��״̬����������ˡ��Ķ�����������ջ������ݽṹ�ĺ�ʱ��

**********************/

/*

�ļ���:C03/04Maze

Maze.h

���ݣ��Թ���ز����б�

*/

#ifndef MAZE_H
#define MAZE_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//�궨��

#define N 15        //N���Թ���СN*N
#define X 4          //X ���������ȡ�࣬���ɵ��������Χ��0��X-1

#define SleepTime 2     //����ʱ����

//�Թ����Ͷ���
typedef enum                    //ö������
{
    Wall,                               //��ǽ
    Obstacle,                       //�ϰ���
    Way,                            //·��
    DeadLock,                       //·���ϵ�����ͬ
    East,South,West,North   //���ʷ��򣬶�������
}MazeNode;

typedef struct
{
    int x;
    int y;
}PosType;           //ͨ����ĺ������궨��

typedef struct                  //ͨ����ĸ�����Ϣ
{
    int ord;                    // ͨ����ġ���š�
    PosType seat;          //ͨ���������λ�ã����PosType �����ϱ߶����struct
    int di;                         //��λ����������
}SElemType_Sq;

#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"
typedef int MazeType;           //�Թ�Ԫ������

//�Թ������б�
Status MazePath(MazeType maze[][N],PosType start,PosType end);

//�Թ�Ѱ·�㷨����ٷ���

void InitMaze(MazeType maze[][N],PosType *start,PosType *end);
//�Թ��ĳ�ʼ��������������ڵĳ�ʼ������ͨ�����ݽ����ĳ��� ��ڲ���ȷ���ˣ��Թ��Ĵ���Ҳ��MazeType maze������N��ȷ���ˣ�

void PrintMaze(MazeType maze[][N]);
//����Ļ�ϻ����Թ�

void ShowMaze(MazeType maze[][N]);
//�Թ�����ʾ

Status EqualPosType(PosType a,PosType b);
//�Ƚ��Թ�������ͨ�����Ƿ���ͬһͨ����

Status Pass(PosType seat,MazeType Maze[][N]);
//�жϴ�ͨ�����Ƿ�δ������

void FootPrint(PosType seat,MazeType maze[][N]);
//����δ���ʽڵ�ʱ���³�ʼ���㼣

void SetElemType(SElemType_Sq *e,int ord,PosType seat,int di);
//����ͨ�������Ϣ

PosType NextPos(PosType seat,int di);
//��ǰͨ����ĺ��

Status IsCross(PosType seat);
//�жϵ�ǰλ���Ƿ�Խ��

void MarkPrint(PosType seat,MazeType maze[][N]);
//��ǵ�ǰλ���ϵ�ͨ���鲻�ɷ���

#endif // MAZE_H








