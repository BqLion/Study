#include <stdio.h>

 void Algo_6_37(BiTree T);
 void Algo_6_38(BiTree T);

 int main(int argc,char *argv[])
 {
    BiTree T;
    FILE *fp;

    return 0;
 }

 void Algo_6_37(BiTree T)
 {
    SqStack S;
    SElemType_Sq e;

    if(!BiTreeEmpty(T))
    {
    InitStack_Sq(&S);
    Push_Sq(&S,T);

    While(!StackEmpty_Sq(S))
    {
    GetTop_Sq(S,&e);
    printf("%c ",e->data);

    if(e->lchild)
    Push_Sq(&S,e->lchild);
    else
    {
    {
    while(!StackEmpty_Sq(S))
    {
    Pop_Sq(&S,&e);

    if(e->rchild)
    {
    Push_Sq(&S,e->rchild);
    break;
    }
    }
    }
    }




    }
    }
 }



