//3.19判断三种括号是否正确配对{}[]()
//用一个栈来实现，遇见左括号就进栈，遇见右括号就让栈里边的元素出栈。出栈的时候做一个match检查，如果都是小/中/大括号，就是OK，否则就是匹配错误
//栈的思想和括号是一样的。括号成对出现，最先出现的一个右括号一定和最近的左括号，如果不匹配，则报错。

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"

//函数原型
Status Algo_3_19(char *s);
Status Matching(char a,char b);

 int main(int argc,char *argv[])
 {
    char *s = "(1+2)*3/{2/[4-5]*3-5*(8-7)}";

    printf("判断表达式 %s 括号是否匹配...\n",s);
    if(Algo_3_19(s))
    printf("表达式括号匹配!!!\n");
    else
    printf("表达式括号不匹配！！！\n");

    printf("\n");

    return 0;
 }

 //判断表达式括号是否匹配

 Status Algo_3_19(char *s)
 {
    SqStack S;
    SElemType_Sq e;
    int i;

    i = 0;
    InitStack_Sq(&S);

    while(s[i])
    {
        switch(s[i])            //当s[i]还不为空的是否，持续步进读数据，如果是三种左括号，则进栈
        {
        case'(':
        case'[':
        case'{':
            Push_Sq(&S,s[i]);
            break;
        case')':
        case']':
        case'}':
        if(StackEmpty_Sq(S))
        return ERROR;

        Pop_Sq(&S,&e);

        if(!Matching(e,s[i]))
        return ERROR;
        break;
        }
        i++;
    }

    if(StackEmpty_Sq(S))
    return OK;
    else
    return ERROR;
 }

 Status Matching(char a,char b)//判断括号是否匹配
 {
    switch(a)
    {
    case'(':
    if(b!=')')
    return ERROR;
    break;

     case'[':
    if(b!=']')
    return ERROR;
    break;

     case'{':
    if(b!='}')
    return ERROR;
    break;

    default:
    return ERROR;
    }

    return OK;
 }
