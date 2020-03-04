//识别某字符串，是否符合某组成规则
//具体规则：以@作为结尾。以&作为对称中心，A、B分别不含不含标识符@  &;

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"

//函数原型

Status Algo_3_17(char *s);

int main(int argc,char *argv[])
{
    char *s = "a+b-c&c-b+a@";

    printf("判断序列%s 是否合规...\n\n",s);
    if(Algo_3_17(s))
    printf("序列满足题意!\n");
    else
    printf("序列不满足题意！！\n");

    printf("\n");

    return 0;
}

Status Algo_3_17(char *s)
{
    SqStack S;
    SElemType_Sq e;
    int i;

    InitStack_Sq(&S);
    i = 0;

    while(s[i]!='@' && s[i]!='&')           //把字符串前一半压入栈中
    {
        Push_Sq(&S,s[i]);
        i++;
    }

    if(s[i]!='@')                                   //把字符串剩下的一半遍历
    {
    i++;
    while(!StackEmpty_Sq(S) && s[i]!='@')      //循环终止条件是：栈S为空了，或者字符串遇见了终止符
    {
        Pop_Sq(&S,&e);                                              //循环把栈中的字符抛出，用e接住
        if(s[i]!=e)                                                            //如果抛出的值和指针所指的字符串不一样就报错
        return ERROR;
        i++;
    }
    }

    if(StackEmpty_Sq(S) && s[i]=='@')
    return OK;
    else
    return ERROR;

}


