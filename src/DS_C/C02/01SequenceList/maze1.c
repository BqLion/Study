#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 15
#define X 4
#define SleepTime 2

typedef enum
{
Wall,
Obstacle,
Way,
DeadLock,
East,South,West,North
}MazeNode;

typedef struct
{
int x;
int y;
}PosType;

typedef struct
{
int ord;
PosType seat;
int di;
}SElemType_Sq;

#endif

Status MazePath(MazeType maze[][N],PosType start,PosType end)
{
    SqStack S;
    SElemType_Sq nodeInf;
    PosType curPos;
    int curStep;

    InitStack_Sq(&S);
    curPos = start;
    curStep = 1;

    do
    {
    if(Pass(curPos,maze))
    {
    FootPrint(curPos,maze);
    Showmaze(maze);

    SetSElemType(&nodeInf,curStep,curPos,East);
    Push_Sq(&S,nodeInf);

    if(EqualPosType(curPos,end))
    {
    printf("\n寻路成功！！\n\n");
    return TRUE;
    }
    curPos = NextPos(curPos,East);
    curStep++;
    }
    else
    {
    if(!StackEmpty-SQ(s))
    {
    Pop_Sq(&S,&nodeInf);
    while(nodeInf.di==North && !StackEmpty_Sq(S))
    {
    MarkPrint(nodeInf.seat,maze);
    ShowMaze(maze);

    Pop_Sq(&S,&nodeInf);
    }

    if(nodeInf.di<North)
    {
    maze[nodeInf.seat.x][nodeInf.seat.y] = ++nodeInf.di;
    ShowMaze(maze);
    Push_Sq(&S,nodeInf);

    curPos = NextPos(nodeInf.seat,nodeInf.di);
    }
    }
    }
    }while(!StackEmpty_Sq(S));

    printf("\n 寻路失败！！\n\n");
    return FALSE;

}

void InitMaze(MazeType maze[][N],PosType *start,PosType #end)
{
int i,j,tmp;

srand((unsigned)time(NULL));

for(i=0;i<N;i++)
{
    for(j=0;j<N;j++)
    {
    if(i==0 || j==0 || i==N-1 || j==N-1)
    maze[i][j] = Wall;
    else
    {
    tmp = rand()%X;
    if(!tmp)
    maze[i][j] = Obstacle;
    else
    maze[i][j] =way;
    }
    }
}

(*start).x = 1;
(*start).y = 0;
(*end).x = N-2;
(*end).y = N-2;

maze[1][0] = maze[N-2][N-1] = Way;
maze[1][1] = maze[N-2][N-2] = Way;
}

