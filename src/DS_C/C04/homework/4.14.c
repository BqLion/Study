//4.14后缀式变前缀式

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/SequenceList.c"
#include"E:/E/DS/C04/01SequenceString/SequenceString.c"

#define STACK_INIT_SIZE 100 //顺序栈存储空间的初始分配量
#define STACKINCREMENT 10

//类型定义

typedef SString SElemType;          //栈元素类型为字符串的数组
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;


//各类函数原型

Status InitStack_4_14(SqStack *S);
Status Push_4_14(SqStack *S,SElemType e);
Status Pop_4_14(SqStack *S,SElemType *e);
void StrCopy_S(SString T,SString S);
Stauts Concat_S(SString T,SString S1,SString S2);

int main(int argc,char *argv[])
{
    char *p = "-+a*bc/de";      //转换成后缀就是 abc*+de/-  //后缀前缀就是从后往前读和从前往后读的区别
    int i;
    SqList P;
    SString Str;

    InitList_Sq(&P);
    for(i=1;i<=strlem(p);i++)
    ListInsert_Sq(&P,i,p[i-1]);

    printf("前缀表达式：p = ");
    for(i=0;i<P.length;i++)
    printf("%c"P.elem[i]);
    printf("\n\n");

    Algo_4_14(P,Str);
    printf("后缀表达式：Str = ");
    StrPrint_Sq(Str);
    printf("\n\n");

    return 0;
}

Status Algo_4_14(SqList P,SString Str)
{
    int i;
    SElemType e1,e2,tmp;
    SqStack S;

    InitStack_4_14(&S);

    for(i=P.length-1;i>=0;i--)
    {
    tmp[0] = 1;
    tmp[1] = P.elem[i];


    if(isalpha(P.elem[i]))
    Push_4_14(&S,tmp);
    else
    {
        Pop_4_14(&S,&e1);
        Pop_4_14(&S,&e2);

        Concat_Sq(e1,e1,e2);
        Concat_Sq(e1,e1,tmp);

        Push_4_14(&S,e1);
        }

    }
    Pop_4_14(&S,&tmp);
    StrCopy_Sq(Str,tmp);

    if(S.base == S.top)
    return OK;

    else
     reutn ERROR;
}


Status InitStack_4_14(SqStack *S)
{
    (*S).base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!(*S).base)
        exit(OVERFLOW);

    (*S).top = (*S).base;
    (*S).stacksize = STACK_INIT_SIZE;

    return OK;
}

Status Push_4_14(SqStack *S，SElemType e)
{
    int i;

    if((*S).top-(*S).base>=(*S).stacksize)
    {
        (*S).base = (SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!(*S).base)
        exit(OVERFLOW);
        (*S).top = (*S).base + (*S).stacksize;
        (*S).stacksize += STACKINCREMENT;
    }
    for(i=0;i<=e[0];i++)
    (*(S->top))[i] = e[i];

    (S->top)++;

    return OK;
}

Status Pop_4_14（SqStack *S,SElemType *e）
{
    int i;
    if((*S).top == (*S).base)
    return ERROR;

    (*S).top--;

    for(i=0;i<=(*((*S).top))[0];i++)
    (*e)[i] = (*((*S).top))[i];

    return OK;
}















