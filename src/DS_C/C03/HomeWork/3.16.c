//生成火车调度的指令序列
//A种车厢入栈，B种车厢入栈后再出栈，A种车厢再出栈

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"

//函数原型

void Algo_3_16(char *En,char Con[]);

int main(int argc,char *argv[])
{
    char *En = "HSHHSHHHSSHSHHHS";
    char Ex[100],Con[100];

    printf("假设入口在右，出口在左...\n");
    printf("调度前入口处的车厢排列为（H表示硬席，S表示软席）：\nEn(从左到右) = ");
    printf("%s\n",En);
    printf("\n");

    printf("生成调度序列...\n");
    Algo_3_16(En,Con);
    printf("调度序列为(I表示入栈，O表示出栈)：\nCon = ");
    printf("%s\n",Con);
    printf("\n");

    return 0;
}

//生成车厢调度序列

void Algo_3_16(char *En,char Con[])
{
    int i,j;
    SqStack S;
    SElemType_Sq e;

    InitStack_Sq(&S);
    i=j=0;

    while(En[i])
    {
        if(En[i]=='H')
        {
        Push_Sq(&S,En[i]);
        Con[j++] = 'I';
        }

    if(En[i]=='S')
    {
    Push_Sq(&S,En[i]);
    Pop_Sq(&S,&e);
    Con[j++]='I';
    Con[j++]='O';
    }

    i++;

    }


    while(!StackEmpty_Sq(S))
    {
        Pop_Sq(&S,&e);
        Con[j++] = 'o';
    }

    Con[j] = '\0';
}






