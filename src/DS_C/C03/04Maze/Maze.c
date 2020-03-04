/**********************

�ļ��У�03ջ�Ͷ���04Maze

�ļ�����maze.c

�㷨.3.3

*************************/

#ifndef MAZE_C
#define MZE_C

#include"Maze.h"

//�㷨3.3

Status MazePath(MazeType maze[][N],PosType start,PosType end)
{
    SqStack S;                                 //һ��ջ
    SElemType_Sq nodeInf;           //nodeinf���浱ǰͨ������Ϣ��int�ε�
    PosType curPos;                     //��ǰλ��  ��֮ǰ�Ķ��壬x��y����λ���ε�
    int curStep;                            //��ǰͨ�������  ����int�ε�

    InitStack_Sq(&S);
    curPos = start;                 //������ʼ�����Թ�����״�ͳ����Ԫ���Ѿ�����
    curStep = 1;                //�������ڵ�λ�þ�����ڣ���������1

    do
    {
    if(Pass(curPos,maze))           //ѭ��������Ѱ·������1�����������˵����pass��û�߹�û�Ǿʹ���ǰ�ߣ�ǰĬ��Ϊeast���ң�ͬʱ�����㼣����������Ѿ��߹��ˣ�ͬʱ�����¼�㼣��ջ������Ҳ��������ߵķ���������Ϣ��ѹ��ջȥ
        {
                FootPrint(curPos,maze);         //�����㼣���´ξ���������ǲ�������
                ShowMaze(maze);

                SetElemType(&nodeInf,curStep,curPos,East);      //����ǰվ���������д����ֱ�Ҫ��Ϣ��Ȼ���������һ����������
                Push_Sq(&S,nodeInf);                            //�������¼���ݵ�Sջд��������ӵ�nodeInf

                if(EqualPosType(curPos,end))            //�����ҵ��˳��ڣ�����Ѱ·�ɹ������� ����ѭ��
                {
                    printf("Ѱ·�ɹ�������\n\n");
                    return TRUE;
                }

                curPos = NextPos(curPos,East);
                curStep++;
                }

                else            //��ǰλ�ò���ͨ����Ҳ�����Ѿ����߹��ˣ��������ϰ��ǽ֮���
                    {
                    if(!StackEmpty_Sq(S))       //��ǰλ�ò���ͨ����Ҳ���ǿյģ��Ǿ������²������˻�һ����Ȼ���ж���һ���Ƿ��������ķ���û��̽���������ǣ����ƣ����ǣ�����++������������̽·��
                    {
                        Pop_Sq(&S,&nodeInf);        //�Ȱ�����ڵ��s��pop����������

                        while(nodeInf.di==North &&!StackEmpty_Sq(S))
                        {
                            MarkPrint(nodeInf.seat,maze);       //������������������ͨ����Ȼ������ˣ�����֮��������ڵ���ĸ�����̸���ˣ������У�˵������·��markһ�£�
                            ShowMaze(maze);

                            Pop_Sq(&S,&nodeInf);                //��Ȼ��·��ͨ���Ǿ��ٴλ���pop
                        }

                        if(nodeInf.di<North)
                        {
                        maze[nodeInf.seat.x][nodeInf.seat.y] = ++nodeInf.di;     //�˻���֮�󣬷����ĸ�����û�б�̽���ꡣ�Ǿ�++����һ������ʼ�µ�̽��
                        ShowMaze(maze);

                        Push_Sq(&S,nodeInf);//����ջ�����ã�������·���ǾͿ�ʼѹ�룬��¼

                        curPos = NextPos(nodeInf.seat,nodeInf.di);
                        }
                    }
                    }
        }while(!StackEmpty_Sq(S));

        printf("\nѰ·ʧ�ܣ�����\n\n");

        return FALSE;
    }

    void InitMaze(MazeType maze[][N],PosType *start,PosType *end)
    {
    int i,j,tmp;

    srand((unsigned)time(NULL));                //��ϵͳʱ�������������

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i==0 || j==0 ||  i==N-1 || j == N-1)
                maze[i][j] =Wall;           //����ȱ߽�С1���������������ǽ����ֵΪwall
            else
            {
                tmp = rand()%X;         //�������������Թ�
                if(!tmp)
                maze[i][j] = Obstacle;           // �������������1/X�ĸ�����0�������0�������ϰ�����������±ߵ�������ͨ��
            else
                maze[i][j] = Way;
            }
        }
    }

    (*start).x = 1;
    (*start).y = 0;
    (*end).x = N-2;
    (*end).y = N-1;     //������ںͳ���

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
                printf("��");
            else if(maze[i][j] == Obstacle)
                printf("��");
            else if(maze[i][j]== East)//��
                printf("��");
            else if(maze[i][j]== South)//����
                printf("��");
            else if(maze[i][j]== West)
                printf("��");
            else if(maze[i][j]== North)
                printf("��");
            else if(maze[i][j]== DeadLock) //����·
                printf("��");
            else
                printf("  ");               //��û�߹���·


        if(j!=0 && j%(N-1)==0)     //��ӡ��ʱ��ÿ��N���ڵ㻻��
            printf("\n");
        }
}

void ShowMaze(MazeType maze[][N])   //�൱��ˢ�²���
{
    Wait(SleepTime);            //��ͣ
    system("cls");                  //�����Ļ�����е�����
    PrintMaze(maze);            //Ȼ�����»�
}

Status EqualPosType(PosType seat1,PosType seat2)
{
    if(seat1.x == seat2.x &&seat1.y == seat2.y)
        return TRUE;
    else
        return ERROR;
}

Status Pass(PosType seat,MazeType maze[][N])        //�ж��ܷ�ͨ������seat��ֵxy����maze����ж�һ�£�������λ�û���way��˵��һ�����ϰ������û���߹��������ж�Ϊ�����ߣ�������ǲ���
{
    int x = seat.x;
    int y = seat.y;

    if(!IsCross(seat) && maze[x][y]==Way)   //�ڵ㲻��Խ��
        return TRUE;
    else
        return ERROR;
}

void FootPrint(PosType seat,MazeType maze[][N])
{
    maze[seat.x][seat.y] = East;            //��ν�����㼣����������һ�εķ��ʷ�������Ҳ��way֮���ֵ�ĳ�������´ξͿ����жϲ��ܴ�������
}

void SetElemType(SElemType_Sq *e,int ord,PosType seat,int di)           //e���Ԫ�ش��ݽ����ˣ�һ������Ļ������������꣬����ȣ�ֱ����д�����¶���
{
    (*e).ord = ord;
    (*e).seat = seat;
    (*e).di = di;
}

PosType NextPos(PosType seat,int di)           //���ݽ��������di���ָʾ������diָʾ�����ϱ�������Ҳ����Ӧ����������
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

    if(x<0 || y<0 || x>N-1 || y>N-1)               //�ж��Ƿ�Խ�纯�������С���㣬���ߴ���n-1����Խ������
        return TRUE;
    else
        return FALSE;
}

void MarkPrint(PosType seat,MazeType maze[][N])         //���´�·��ͬ�ı�ǣ�Ҳ���ǰ�������ʲô��ǣ��ĳ� DeadLock
{
    int  x= seat.x;
    int y = seat.y;

    maze[x][y] = DeadLock;
}
#endif // MAZE_C




