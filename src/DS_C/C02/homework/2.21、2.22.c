//2.21/2.22顺序表 单链表的就地逆置

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SequenceList/SequenceList.c"

//函数原型

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

    printf("逆置顺序表...\n");
    Algo_2_21(L);
    printf("此时L=  ");
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

    for(j=1,i=(L.length)/2;j<=i;j++)            //j等于表头，i等于表中间，j往表中间移动，所指的每一个元素都与相应的   “以表中为对称轴”  所对的元素互换
    {
        tmp = L.elem[j-1];              //tmp这个临时储存器储存表头的元素
        L.elem[j-1] = L.elem[L.length-j];           //最头的元素被赋值为最尾的元素，随后下一行最尾的元素被赋值为最头的元素，然后随着j++,头/尾指针均向中间移动
        L.elem[L.length-j] = tmp;

    }
    return OK;
}
void PrintElem(LElemType_Sq e)
{
    printf("%d ",e);

}



