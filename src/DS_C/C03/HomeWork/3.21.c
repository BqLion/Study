#include<stdio.h>
#include<ctype.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"
//函数原型

void Algo_3_21(char *s,char c[]);
Status Priority(char a,char b);

int main(int argc,char *argv[])
{
    char *s = "a+b*c-d/e";
    char c[100];

    printf("中缀表达式为:  ");
    printf("%s\n",s);
    printf("\n");

    Algo_3_21(s,c);
    printf("生成的后缀表达式：");
    printf("%s\n,c");
    printf("\n");

    return 0;
}

void Algo_3_21(char *s,char c[])
{
    int i,j;
    SqStack S;
    SElemType_Sq e;

    InitStack_Sq(&S);
    i = j = 0;

    while(s[i]!='\0')
    {
        if(isalpha(s[i]))
        c[j++] = s[i];
        else
        {
            while(!StackEmpty_Sq(S))
            {
                GetTop_Sq(S,&e);        //循环做：获取栈顶元素，若栈顶元素比待处理的运算符出价高，把栈顶抛出。否则：结束循环，把待处理元素抛出，步进下一个待处理元素。

                if(Priority(e,s[i]))
                {
                Pop_Sq(&S,&e);
                c[j++] = e;
                }
                else
                    break;
            }

            Push_Sq(&S,s[i]);
        }

        i++;
    }


    while(!StackEmpty_Sq(S))
    {
        Pop_Sq(&S,&e);
        c[j++] = e;
    }

    c[j] = '\0';
}

//比较运算符a、b的优先级
Status Priority(char a,char b)
{
    switch(a)
    {
    case'*':
    case'/':
    return OK;          //a>b
    break;

    case'+':
    case'-':
    if(b=='+' || b=='-')
    return OK;   //a>b
    else
    return ERROR;  //a<b
    break;
    }
}








