//2.29  删除A表中 B C 都出现的元素。思路：b c用两个指针步进，直到两者相等时停下。这时与A相比，谁小谁往前步进，直至相等。相等后duiA实施删除操作，这里是顺序表删除操作用的是两个指针循环自赋值的方法。

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/SequenceList.c"

void Algo_2_29(SqList *La,SqList Lb,SqList Lc);
void PrintElem(LElemType_Sq e);

int main(int argc,char argv[])
{
    SqList La,Lb,Lc;
    int i;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int b[] = {1,2,3,4,5,6,7,8,8,9,10};
    int c[] = {1,2,3,4,5,6,7,8,11,12};

    if(InitList_Sq(&La) && InitList_Sq(&Lb) && InitList_Sq(&Lc))
    {
        for(i=1;i<=10;i++)
        {
        ListInsert_Sq(&La,i,a[i-1]);
        ListInsert_Sq(&Lb,i,b[i-1]);
        ListInsert_Sq(&Lc,i,c[i-1]);
        }
    }

    printf("La  = ");
    ListTraverse_Sq(La,PrintElem);
    printf("\n");
    printf("Lb  = ");
    ListTraverse_Sq(Lb,PrintElem);
    printf("\n");
    printf("Lc  = ");
    ListTraverse_Sq(Lc,PrintElem);
    printf("\n");

    Algo_2_29(&La,Lb,Lc);
    printf("La = La - Lb∩Lc");
    ListTraverse_Sq(La,PrintElem);
    printf("\n\n");

    return 0;
}

void Algo_2_29(SqList *La,SqList Lb,SqList Lc)
{
    int i,j,k,count;

    i= j=k=0;
    count = 0;

    while(i<(*La).length  && j<Lb.length && k<Lc.length)
    {
        if(Lb.elem[j]<Lc.elem[k])
            j++;
        else if(Lb.elem[j]>Lc.elem[k])          //Lb 或 Lc不相等两者步进至相等
            k++;
        else                                                   //Lb与Lc相等了就与La相比，相等则删除A，不相等则同理步进至相等
        {
            while(i<(*La).length && (*La).elem[i]<Lb.elem[j])
            {
                (*La).elem[count] = (*La).elem[i];                      //La小了，自我赋值后步进
                count++;
                i++;
            }

        while(i<(*La).length && (*La).elem[i] == Lb.elem[j])            //La与LbLc相等，这时就将La步进
        i++;

        if(i<(*La).length)
        {
        j++;
        k++;

        }

        }

    }

    while(i<(*La).length)
    {
    (*La).elem[count] = (*La).elem[i];
    count++;
    i++;

    }
    (*La).length = count;

}

void PrintElem(LElemType_Sq e)
{
    printf("%d ",e);
}






