/************************

文件夹“03栈和队列 04Maze

内容：迷宫的函数测试

********************/
#include"Maze.c"

int main(int argc,char *argv[])
{
    MazeType maze[N][N];
    PosType start,end;
    SElemType_Sq e;
    char Re = 'Y';

    while(Re=='Y' || Re == 'y')
    {
        InitMaze(maze,&start,&end);
        ShowMaze(maze);
        MazePath(maze,start,end);

        printf("带哥请问是否重置？(Y/N)：");
        scanf("%c",&Re);
    }
    return 0;
}
