#include <stdio.h>

#include"SequenceArray.c"

//�Զ�ά����Ϊ������

int main(int argc,char **argv)
{

    Array A;
    printf("1\n ��ʼ��һ��2�����еĶ�ά����A ...\n");
    {
    InitArray(&A,2,2,3);
    printf("\n");
    }
PressEnter;

printf("5\n ���� AssignArray����...\n");
{
    int i,j;
    AElemType_Sq e= 0;

    for(i=0;i<A.bounds[0];i++)
    {
    for(j=0;j<A.bounds[1];j++)
    {
    printf("��ֵ��A[%d][%d] = %d\n",i,j,++e);
    AssignArray(&A,e,i,j);
    }

    }
    printf("\n");
}
PressEnter;

printf("6\n ���� ArrayPrint ����...\n");
{
    printf("A = ");
    ArrayPrint(A);
    printf("\n\n");

}
PressEnter;

printf("3,4\n ���� LocateArray  ValueArray ����...\n");
{
    AElemType_Sq e;

    printf("��ȡA���±�Ϊ(1,1)��Ԫ�ص�ֵ��Locate�������A��1����1�������λ��...\n");
    ValueArray(A,&e,1,1);
    printf("A[1][1] = %d \n",e);
    printf("\n");

}
PressEnter;

printf("2\n���� DestroyArray ���� ...\n");
{
    printf("����Aǰ��");
    A.dim!=0?printf("A���ڣ�\n"):printf("A�����ڣ���\n");
    DestroyArray(&A);
    printf("����A��");
    A.dim!=0?printf("A���ڣ�\n"):printf("A�����ڣ�����\n");
    printf("\n");
}
PressEnter;

return 0;
}
