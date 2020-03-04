/*****************************

文件夹：C02/homework/2.10

****************************/

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/SequenceList.c"

Status Algo_2_10(SqList *a,int i ,int k);
void PrintElem(LElemType_Sq e);

int main(int argc,char *argv[])
{
    SqList L;
    int i;

    if(InitList_Sq(&L))
    {
        for(i=1;i<=20;i++)
            ListInsert_Sq(&L,i,i);
    }

    printf("L = ");
    ListTraverse_Sq(L,PrintElem);
    printf("\n\n");
    printf("删除第五个元素起的十个元素...\n");
    Algo_2_10(&L,5,10);
    printf("此时L = ");
    ListTraverse_Sq(L,PrintElem);
    printf("\n\n");

    return 0;
}

Status Algo_2_10(SqList *a,int i,int k)
{
    int j,count;

    if(i<1 || i>(*a).length ||k<0 || i+k-1>(*a).length)
        return ERROR;

    for(count =1;count<k;count++)
        {
        for(j = i+1;j<=(*a).length;j++)
        (*a).elem[j-1] = (*a).elem[j];

        (*a).length--;
        }



    return OK;
}

void PrintElem(LElemType_Sq e)
{
    printf("%d ",e);

}
