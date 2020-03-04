#include<stdio.h>
#include<ctype.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"

//函数原型
Status Algo_3_22(char c[],SElemType_Sq *Value);
char Operate(char a,char oper,char b);

int main(int argc,char *argv[])
{
    char c[] = "134*+62/-";
    SElemType_Sq value;

    printf("已知逆波兰表达式为: ");
    printf("%s\n",c);
    Algo_3_22(c,&value);
    printf("逆波兰式的结果为：%d\n",value-48);
    printf("\n");

    return 0;
}

//对逆波兰表达式求值
Status Algo_3_22(char c[],SElemType_Sq *Value)
{
    int i;
    SqStack S;
    SElemType_Sq a,b;

    InitStack_Sq(&S);
    i = 0;

    while(c[i])
    {
    if(isdigit(c[i]))
    Push_Sq(&S,c[i]);    //遇见数字
    else
    {
        Pop_Sq(&S,&b);
        Pop_Sq(&S,&a);
        Push_Sq(&S,Operate(a,c[i],b));                  //逆波兰表达式的符号位序已经按优先级排好了，遇见符号直接无脑抛出计算即可
    }

    i++;
    }

    Pop_Sq(&S,Value);

    if(!StackEmpty_Sq(S))
    return ERROR;

    else
    return OK;
}


char Operate(char a,char oper,char b)
{
    char c;
    switch(oper)
    {
        case'+':c = (a-48)+(b-48)+48;
        break;
        case'-':c = (a-48)-(b-48)+48;
        break;
        case'*':c = (a-48)*(b-48)+48;
        break;
        case'/':c = (a-48)/(b-48)+48;
        break;
    }

    return c;
}













