//2.25 用顺序表的数据结构求C = A∪B。其中取SequenceList的值，用的是La.elem[i]这种形式取的，因为顺序表是以数组的形式存储的

//思路：指针pa指向A，pb指向B，然后依次比较，if(PA>PB;PB++)if(PA<PB;PA++)else：把并集的值赋到PC上去，然后三个指针同时++
//开始时间：17:50 完成时间：18:04 用时十五分钟
#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/SequenceList.c"

//函数原型

void Algo_2_25(SqList La,SqList Lb,SqList *Lc);
void PrintElem(LElemType_Sq e);

int main(int argc,char argv[])
{
    SqList La,Lb,Lc;
    int i;
    //原作无如下两行，为测试if是否能同时完成初始化而写
    InitList_Sq(&La);
    InitList_Sq(&Lb);
    //if后边跟的InitList_Sq  是仅仅做判断用还是同时完成了初始化的任务？
    if(InitList_Sq(&La) && InitList_Sq(&Lb))
    {
        for(i=1;i<=10;i++)
        {
            ListInsert_Sq(&La,i,i);
            ListInsert_Sq(&Lb,i,2*i);
        }
    }

    printf("La = ");
    ListTraverse_Sq(La,PrintElem);
    printf("\n");
    printf("Lb  = ");
    ListTraverse_Sq(Lb,PrintElem);
    printf("\n\n");

    InitList_Sq(&Lc);
    Algo_2_25(La,Lb,&Lc);
    printf("Lc = La∩Lb =  ");
    ListTraverse_Sq(Lc,PrintElem);
    printf("\n\n");

    return 0;
}

//实现A∩B的功能函数

void Algo_2_25(SqList La,SqList Lb,SqList *Lc)
{
    int i,j,k;

    i = j = 0;
    k = 1;

    while(i<La.length && j<Lb.length)
    {
        if(La.elem[i]<Lb.elem[j])
            i++;
        else if(La.elem[i]>Lb.elem[j])
            j++;
        else
        {
        ListInsert_Sq(Lc,k,La.elem[i]);
        k++;
        i++;
        j++;
        }
    }
}

void PrintElem(LElemType_Sq e)
{
    printf("%d ",e);
}
