/************************

�ļ��С�03ջ�Ͷ��� 04Maze

���ݣ��Թ��ĺ�������

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

        printf("���������Ƿ����ã�(Y/N)��");
        scanf("%c",&Re);
    }
    return 0;
}
