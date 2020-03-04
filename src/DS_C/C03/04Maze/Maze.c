/**********************

文件夹：03栈和队列04Maze

文件名：maze.c

算法.3.3

*************************/

#ifndef MAZE_C
#define MZE_C

#include"Maze.h"

//算法3.3

Status MazePath(MazeType maze[][N],PosType start,PosType end)
{
    SqStack S;                                 //一个栈
    SElemType_Sq nodeInf;           //nodeinf储存当前通道块信息，int形的
    PosType curPos;                     //当前位置  ，之前的定义，x和y，是位置形的
    int curStep;                            //当前通道块序号  ，是int形的

    InitStack_Sq(&S);
    curPos = start;                 //经过初始化，迷宫的形状和出入口元素已经有了
    curStep = 1;                //定义现在的位置就是入口，步数等于1

    do
    {
    if(Pass(curPos,maze))           //循环做如下寻路操作：1，如果像本行所说，可pass，没走过没那就大胆往前走，前默认为east，右，同时留下足迹，标记这里已经走过了，同时负责记录足迹的栈，这是也把这个能走的方块的相关信息给压入栈去
        {
                FootPrint(curPos,maze);         //留下足迹，下次经过这里就是不能走了
                ShowMaze(maze);

                SetElemType(&nodeInf,curStep,curPos,East);      //给当前站的这个格子写入各种必要信息，然后可以向下一个格子迈进
                Push_Sq(&S,nodeInf);                            //给负责记录数据的S栈写入这个格子的nodeInf

                if(EqualPosType(curPos,end))            //最终找到了出口，返回寻路成功，否则 继续循环
                {
                    printf("寻路成功！！！\n\n");
                    return TRUE;
                }

                curPos = NextPos(curPos,East);
                curStep++;
                }

                else            //当前位置不能通过，也就是已经被走过了，或者是障碍物，墙之类的
                    {
                    if(!StackEmpty_Sq(S))       //当前位置不能通过，也不是空的，那就做如下操作（退回一步，然后判断上一步是否有其他的方向还没有探过，若不是，再推，若是，方向++，换个方向再探路）
                    {
                        Pop_Sq(&S,&nodeInf);        //先把这个节点从s中pop出来，回退

                        while(nodeInf.di==North &&!StackEmpty_Sq(S))
                        {
                            MarkPrint(nodeInf.seat,maze);       //如果是这种情况（不能通过，然后回退了，回退之后发现这个节点的四个方向都谈过了，都不行，说明是死路，mark一下）
                            ShowMaze(maze);

                            Pop_Sq(&S,&nodeInf);                //既然此路不通，那就再次回退pop
                        }

                        if(nodeInf.di<North)
                        {
                        maze[nodeInf.seat.x][nodeInf.seat.y] = ++nodeInf.di;     //退回来之后，发现四个方向并没有被探索完。那就++，换一个方向开始新的探索
                        ShowMaze(maze);

                        Push_Sq(&S,nodeInf);//发挥栈的作用，开了新路，那就开始压入，记录

                        curPos = NextPos(nodeInf.seat,nodeInf.di);
                        }
                    }
                    }
        }while(!StackEmpty_Sq(S));

        printf("\n寻路失败！！！\n\n");

        return FALSE;
    }

    void InitMaze(MazeType maze[][N],PosType *start,PosType *end)
    {
    int i,j,tmp;

    srand((unsigned)time(NULL));                //用系统时间做随机数种子

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i==0 || j==0 ||  i==N-1 || j == N-1)
                maze[i][j] =Wall;           //坐标比边界小1，这种情况就是外墙，赋值为wall
            else
            {
                tmp = rand()%X;         //生成随机数填充迷宫
                if(!tmp)
                maze[i][j] = Obstacle;           // 生成随机数，有1/X的概率是0，如果是0，就是障碍，否则就是下边的正常的通道
            else
                maze[i][j] = Way;
            }
        }
    }

    (*start).x = 1;
    (*start).y = 0;
    (*end).x = N-2;
    (*end).y = N-1;     //设置入口和出口

    maze[1][0] = maze[N-2][N-1] = Way;
    maze[1][1] = maze[N-2][N-1] = Way;
    }

void PrintMaze(MazeType maze[][N])
{
    int i,j;

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
            if(maze[i][j] == Wall)
                printf("█");
            else if(maze[i][j] == Obstacle)
                printf("▓");
            else if(maze[i][j]== East)//向东
                printf("→");
            else if(maze[i][j]== South)//向南
                printf("↓");
            else if(maze[i][j]== West)
                printf("←");
            else if(maze[i][j]== North)
                printf("↑");
            else if(maze[i][j]== DeadLock) //是死路
                printf("★");
            else
                printf("  ");               //还没走过的路


        if(j!=0 && j%(N-1)==0)     //打印的时候每嗝N个节点换行
            printf("\n");
        }
}

void ShowMaze(MazeType maze[][N])   //相当于刷新操作
{
    Wait(SleepTime);            //暂停
    system("cls");                  //清除屏幕上现有的内容
    PrintMaze(maze);            //然后重新画
}

Status EqualPosType(PosType seat1,PosType seat2)
{
    if(seat1.x == seat2.x &&seat1.y == seat2.y)
        return TRUE;
    else
        return ERROR;
}

Status Pass(PosType seat,MazeType maze[][N])        //判断能否通过，将seat的值xy都在maze里边判断一下，如果这个位置还是way，说明一不是障碍物，二还没有走过，所以判断为可以走，否则就是不行
{
    int x = seat.x;
    int y = seat.y;

    if(!IsCross(seat) && maze[x][y]==Way)   //节点不能越界
        return TRUE;
    else
        return ERROR;
}

void FootPrint(PosType seat,MazeType maze[][N])
{
    maze[seat.x][seat.y] = East;            //所谓留下足迹就是设置下一次的访问方向，这里也把way之类的值改成这个，下次就可以判断不能从这里走
}

void SetElemType(SElemType_Sq *e,int ord,PosType seat,int di)           //e这个元素传递进来了，一起进来的还有序数，坐标，方向等，直接照写就完事儿了
{
    (*e).ord = ord;
    (*e).seat = seat;
    (*e).di = di;
}

PosType NextPos(PosType seat,int di)           //传递进来坐标和di这个指示。根据di指示向东西南北，坐标也做相应的上下增减
{
    PosType tmp = seat;

    switch(di)
    {
        case East:   tmp.y++;
        break;
        case South:   tmp.x++;
        break;
        case West:   tmp.y--;
        break;
        case North:   tmp.x--;
        break;
    }
    return tmp;
}

Status IsCross(PosType seat)
{
    int x = seat.x;
    int y = seat.y;

    if(x<0 || y<0 || x>N-1 || y>N-1)               //判断是否越界函数，如果小于零，或者大于n-1就是越界了呗
        return TRUE;
    else
        return FALSE;
}

void MarkPrint(PosType seat,MazeType maze[][N])         //留下此路不同的标记，也就是把其他的什么标记，改成 DeadLock
{
    int  x= seat.x;
    int y = seat.y;

    maze[x][y] = DeadLock;
}
#endif // MAZE_C




