//4.14��׺ʽ��ǰ׺ʽ

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/SequenceList.c"
#include"E:/E/DS/C04/01SequenceString/SequenceString.c"

#define STACK_INIT_SIZE 100 //˳��ջ�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT 10

//���Ͷ���

typedef SString SElemType;          //ջԪ������Ϊ�ַ���������
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;


//���ຯ��ԭ��

Status InitStack_4_14(SqStack *S);
Status Push_4_14(SqStack *S,SElemType e);
Status Pop_4_14(SqStack *S,SElemType *e);
void StrCopy_S(SString T,SString S);
Stauts Concat_S(SString T,SString S1,SString S2);

int main(int argc,char *argv[])
{
    char *p = "-+a*bc/de";      //ת���ɺ�׺���� abc*+de/-  //��׺ǰ׺���ǴӺ���ǰ���ʹ�ǰ�����������
    int i;
    SqList P;
    SString Str;

    InitList_Sq(&P);
    for(i=1;i<=strlem(p);i++)
    ListInsert_Sq(&P,i,p[i-1]);

    printf("ǰ׺���ʽ��p = ");
    for(i=0;i<P.length;i++)
    printf("%c"P.elem[i]);
    printf("\n\n");

    Algo_4_14(P,Str);
    printf("��׺���ʽ��Str = ");
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

Status Push_4_14(SqStack *S��SElemType e)
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

Status Pop_4_14��SqStack *S,SElemType *e��
{
    int i;
    if((*S).top == (*S).base)
    return ERROR;

    (*S).top--;

    for(i=0;i<=(*((*S).top))[0];i++)
    (*e)[i] = (*((*S).top))[i];

    return OK;
}















