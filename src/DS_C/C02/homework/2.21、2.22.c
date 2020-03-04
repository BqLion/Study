//2.21/2.22˳��� ������ľ͵�����

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/SequenceList.c"

//����ԭ��

Status Algo_2_21(SqList L);
void PrintElem(LElemType_Sq e);

int main(int argc,char argv[])
{
    SqList  L;
    int i;

    if(InitList_Sq(&L))
    {
    for(i=1;i<=10;i++)
        ListInsert_Sq(&L,i,i);
    }

    printf("L = ");
    ListTraverse_Sq(L,PrintElem);
    printf("\n\n");

    printf("����˳���...\n");
    Algo_2_21(L);
    printf("��ʱL=  ");
    ListTraverse_Sq(L,PrintElem);
    printf("\n\n");

    return 0;
}


Status Algo_2_21(SqList L)
{
    int i;
    int j;
    LElemType_Sq tmp;

    if(L.length==0)
        return ERROR;

    for(j=1,i=(L.length)/2;j<=i;j++)            //j���ڱ�ͷ��i���ڱ��м䣬j�����м��ƶ�����ָ��ÿһ��Ԫ�ض�����Ӧ��   ���Ա���Ϊ�Գ��ᡱ  ���Ե�Ԫ�ػ���
    {
        tmp = L.elem[j-1];              //tmp�����ʱ�����������ͷ��Ԫ��
        L.elem[j-1] = L.elem[L.length-j];           //��ͷ��Ԫ�ر���ֵΪ��β��Ԫ�أ������һ����β��Ԫ�ر���ֵΪ��ͷ��Ԫ�أ�Ȼ������j++,ͷ/βָ������м��ƶ�
        L.elem[L.length-j] = tmp;

    }
    return OK;
}
void PrintElem(LElemType_Sq e)
{
    printf("%d ",e);

}



