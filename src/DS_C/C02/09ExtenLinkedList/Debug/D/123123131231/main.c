//3.31

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"
#include"E:/E/DS/C03/07LinkQueue/LinkQueue.c"

Status Algo_3_31(char c[]);

int main(int argc,char*argv[])
{
    char *a  = "abcdedcba@";
    char *b = "ababab@";

    if(Algo_3_31(a))
    printf("%s是回文！！\n",a);
    else
    printf("%s不是回文！！\n",a);
    printf("\n");

    if(Algo_3_31(b))
    printf("%s是回文！！\n",b);
    else
    printf("%s不是回文！！\n",b);
    printf("\n");

    return 0;
}

Status Algo_3_31(char c[])
{
    SqStack S;
    LinkQueue Q;
    SElemType_Sq e1;
    QElemType_L e2;
    int i;

    InitStack_Sq(&S);
    InitQueue_L(&Q);

    for(i=0;c[i]!='@';i++)      //将字符读入栈和队列
    {
    Push_Sq(&S,c[i]);
    EnQueue_L(&Q,c[i]);
    }


    while(!StackEmpty_Sq(S) && !QueueEmpty_L(Q))
    {
        Pop_Sq(&S,&e1);
        DeQueue_L(&Q,&e2);
        if(e1!=e2)
        return ERROR;
    }

    if(StackEmpty_Sq(S)&& QueueEmpty_L(Q))
    return OK;
}

