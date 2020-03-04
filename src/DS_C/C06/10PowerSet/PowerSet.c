//Power_Set

#ifndef POWERSET_C
#define POWERSET_C

#include "PowerSet.h"

Status CreatePowerSet_PS(FILE *fp,LinkList *A)
{
    int i,j;
    PElemType e;

    InitList_L(A);
    Scanf(fp,"%d",&j);
    printf("录入集合A的元素个数 %d....\n",j);

    for(i=1;i<=j;i++)
    {
        Scanf(fp,"%d,&e");
        printf("录入第%d个元素：%d\n",i,e);
        ListInsert_L(*A,i,e);
    }

    return OK;
}

void GetPowerSet_PS(int i,LinkList A,LinkList B)
{
    int k;
    LElemType_L x;

    if(i>ListLength_L(A))
        Output_PS(B);
    else
    {
        GetElem_L(A,i,&x);
        k = ListLength_L(B);

        ListInsert_L(B,k+1,x);
        GetPowerSet_PS(i+1,A,B);

        ListDelete_L(B,k+1,&x);
        GetPowerSet_PS(i+1,A,B);
    }
}


void Output_PS(LinkList A)
{
    LinkList p;
    int len = ListLength_L(A);

    if(len)
    {
    for(p=A->next;p;p=p->next)
    printf("%d ",p->data);
    }
    else
        printf(" X ");

    printf("\n");
}

#endif


