#ifndef SEQUENCESTACK_C
#define SEQUENCESTACK_C

#include "SequenceStack.h"

Status InitStack_Sq(SqStack *S)
{
    (*S).base = (SElemType_Sq *)malloc(STACK_INIT_SIZE*sizeof(SElemType_Sq));
    if(!(*S).base)
        exit(OVERFLOW);

    (*S).top = (*S).base;
    (*S).stacksize = STACK_INIT_SIZE;

    return OK;
}

Status DestroyStack_Sq(SqStack *S)
{
    free((*S).base);

    (*S).base = NULL;
    (*S).top = NULL;
    (*S).stacksize = 0;

    return OK;
}

Status  ClearStack_Sq(SqStack *S)
{
    (*S).top  = (*S).base;

    return OK;
}

Status StackEmpty_Sq(SqStack S)
{
    if(S.top == S.base)
        return 1;
    else
        return 0;
}

int StackLength_Sq(SqStack S)
{
    return S.top - S.base;
}

Status GetTop_Sq(SqStack S,SElemType_Sq *e)
{
    if(S.top == S.base)
        return ERROR;

    *e = *(S.top - 1);
    return OK;
}

Status Push_Sq(SqStack *S,SElemType_Sq e)
{
    if((*S).top-(*S).base>=(*S).stacksize)
    {
        (*S).base = (SElemType_Sq *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType_Sq));
        if(!(*S).base)
            exit(OVERFLOW);
        (*S).top = (*S).base + (*S).stacksize;
        (*S).stacksize+=STACKINCREMENT;
    }

    *(S->top) = e;      //栈顶指针的值指向e
    (S->top)++;         //站定指针的位置步进

    return OK;
}

Status Pop_Sq(SqStack *S,SElemType_Sq *e)
{
    if((*S).top==(*S).base)         //如果首位指针在一起，则报错
        return ERROR;

    (*S).top--;
    *e = *((*S).top);                   //弹栈操作：top指针步减，再赋值


    return OK;
}


Status StackTraverse_Sq(SqStack S,void(Visit)(SElemType_Sq))
{
    SElemType_Sq *p = S.base;

    while(p<S.top)
        Visit(*p++);

    return OK;

}
#endif // SEQUENCESTACK_C




