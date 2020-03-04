#include <stdio.h>
#include <stdlib.h>
#include"E:/E/DS/C02/01SequenceList/SequenceList.c"

//函数测试原型：

int Algo_2_12(SqList A,SqList B);
void PrintElem(LElemType_Sq e);

int main(int argc,char *argv[])
{
    int i,mark;
    SqList A,B;
    int a[7] = {1,2,3,4,5,9,12};
    int b[7] = {1,2,3,4,5,11,12};

    InitList_Sq(&A);
    InitList_Sq(&B);

    for(i=1;i<=7;i++)
    {
        ListInsert_Sq(&A,i,a[i-1]);
        ListInsert_Sq(&B,i,b[i-1]);
    }

    printf("构建完成的顺序表为：\n");
    printf("A = ");
    ListTraverse_Sq(A,PrintElem);
    printf("\n");
    printf("B = ");
    ListTraverse_Sq(B,PrintElem);
    printf("\n\n");
    mark = Algo_2_12(A,B);
    printf("后缀结果比较：");
    if(mark<0)
        printf("A<B\n");
    else if(mark >1)
        printf("A>B\n");
    else
        printf("A==B\n");
    printf("\n");

    return 0;
}


//比较顺序表后缀大小

int  Algo_2_12(SqList A,SqList B)
{
    int i;
    i = 0;

    while(i<A.length && i<B.length)
    {
        if(A.elem[i]>B.elem[i])
            return 1;
        else if(A.elem[i]<B.elem[i])
            return -1;
        else
            i++;
    }

    if(i<A.length)
        return 1;
    else if(i<B.length)
        return -1;
    else
        return 0;
}

void PrintElem(LElemType_Sq e)
{
    printf("%d ",e);
}






