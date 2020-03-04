//2.29  ɾ��A���� B C �����ֵ�Ԫ�ء�˼·��b c������ָ�벽����ֱ���������ʱͣ�¡���ʱ��A��ȣ�˭С˭��ǰ������ֱ����ȡ���Ⱥ�duiAʵʩɾ��������������˳���ɾ�������õ�������ָ��ѭ���Ը�ֵ�ķ�����

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
    printf("La = La - Lb��Lc");
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
        else if(Lb.elem[j]>Lc.elem[k])          //Lb �� Lc��������߲��������
            k++;
        else                                                   //Lb��Lc����˾���La��ȣ������ɾ��A���������ͬ���������
        {
            while(i<(*La).length && (*La).elem[i]<Lb.elem[j])
            {
                (*La).elem[count] = (*La).elem[i];                      //LaС�ˣ����Ҹ�ֵ�󲽽�
                count++;
                i++;
            }

        while(i<(*La).length && (*La).elem[i] == Lb.elem[j])            //La��LbLc��ȣ���ʱ�ͽ�La����
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






