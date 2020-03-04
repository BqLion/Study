//3.20染色问题，二维数组中，用0到k表示颜色，置换点（i,j）以及和它同色的相邻点的颜色。

//此算法类似于迷宫寻路算法

//定义了一个int形二维数组，可视为“图纸”，由颜色构成。
//定义了一个stack，装的是elemType（横坐标，纵坐标，下一个方位【也作为判断是否被访问过的依据】）。这个stack其实是"对图纸的操作手册"，一步步指示该如何在图纸上寻路，遇见障碍该如何退回



#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//宏定义

#define SleepTime 2
#define Row 10
#define Col 17

//类型定义
typedef enum{east,south,west,north}Direction;       //定义方向的集合
typedef enum{color_1,color_2,color_3,color_4}Color;     //定义颜色的集合

typedef struct
{
    int x;
    int y;
    int di;
}SElemType;                                            //栈储存的元素类型

//函数原型

void Coloring_3_20(int g[][17],SElemType start);    //染色
void InitGrap(int g[][17],SElemType *start);//初始化图像区域，和染色的起点
void PaintGrap(int g[][17]);
void ShowGrap(int g[][17]);//上边的PaintGrap是把数据类型，转换为屏幕上的图像。本函数Show是把上函数的图像固定在屏幕上，system"pause"
Status Pass(SElemType e,int g[][17]);           //经过函数，经过这个点的时候，判断是否需要染色
void Mark(SElemType *e,int g[][17]);                //经过函数判断出结果后，如果需要染色，就让Mark函数染之、
Status NextPos(SElemType *e);                          //获取下一个该染色的方位。
Status IsCross(SElemType e);//判断是否越界

int main(int argc,char **argv)
{
    int g[Row][Col];
    SElemType start;            //定义一个像素单位，为start点

    InitGrap(g,start);
    PaintGrap(g);
    Coloring_3_20(g,start);

    return 0;
}

//染色函数：

void Coloring_3_20(int g[][Col],SElemType start)
{
    SElemType e;
    SElemType stack[10000];//操作集，储存了从起点开始，如何在图纸上走的路径，如果遇见了障碍，如何回退的手册。程序根据这个栈手册，依次在图纸上执行。
    int top = -1;

    e = start;
    do
    {
        if(Pass(e,g))               //判断图纸上是否是1，如果是，说明需要染色：
        {
        Mark(&e,g);         //染色具体操作：图纸上颜色“1”改为“2”。操作手册上，这个坐标里的“下一个方位”由null改为east。
        ShowGrap(g);
        stack[++top] = e;       //把染了色的元素的相应信息进操作手册的栈
        NextPos(&e);            //把下一个要访问的方位输入操作手册的temp变量
        }
    else
    {
        if(top!=-1)
        {
            e = stack[top--];       //如果e步进到的这个位置不需要染色，则需要回退。

            while(e.di ==North && top !=-1)     //当回退一步，仍然没有位置可访问的时候，继续循环后退
                e = stack[top--];

            if(e.di<North)              //如果终于找到还能访问的地点，这时让这个stack中的e的方位值加1，在把next函数调用一下，继续访问
            {
            e.di++;
            stack[++top]   = e;
            NextPos(&e);
            }
        }
    }
    }while(top!=-1);
}


//初始化























