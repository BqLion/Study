#include <stdio.h>

#include"SequenceArray.c"

//以二维数组为例测试

int main(int argc,char **argv)
{

    Array A;
    printf("1\n 初始化一个2行三列的二维数组A ...\n");
    {
    InitArray(&A,2,2,3);
    printf("\n");
    }
PressEnter;

printf("5\n 函数 AssignArray测试...\n");
{
    int i,j;
    AElemType_Sq e= 0;

    for(i=0;i<A.bounds[0];i++)
    {
    for(j=0;j<A.bounds[1];j++)
    {
    printf("赋值：A[%d][%d] = %d\n",i,j,++e);
    AssignArray(&A,e,i,j);
    }

    }
    printf("\n");
}
PressEnter;

printf("6\n 函数 ArrayPrint 测试...\n");
{
    printf("A = ");
    ArrayPrint(A);
    printf("\n\n");

}
PressEnter;

printf("3,4\n 函数 LocateArray  ValueArray 测试...\n");
{
    AElemType_Sq e;

    printf("获取A中下表为(1,1)的元素的值，Locate用于求出A【1】【1】的相对位置...\n");
    ValueArray(A,&e,1,1);
    printf("A[1][1] = %d \n",e);
    printf("\n");

}
PressEnter;

printf("2\n函数 DestroyArray 测试 ...\n");
{
    printf("销毁A前：");
    A.dim!=0?printf("A存在！\n"):printf("A不存在！！\n");
    DestroyArray(&A);
    printf("销毁A后：");
    A.dim!=0?printf("A存在！\n"):printf("A不存在！！！\n");
    printf("\n");
}
PressEnter;

return 0;
}
