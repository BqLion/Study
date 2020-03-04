//2.25 ��˳�������ݽṹ��C = A��B������ȡSequenceList��ֵ���õ���La.elem[i]������ʽȡ�ģ���Ϊ˳��������������ʽ�洢��

//˼·��ָ��paָ��A��pbָ��B��Ȼ�����αȽϣ�if(PA>PB;PB++)if(PA<PB;PA++)else���Ѳ�����ֵ����PC��ȥ��Ȼ������ָ��ͬʱ++
//��ʼʱ�䣺17:50 ���ʱ�䣺18:04 ��ʱʮ�����
#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/SequenceList.c"

//����ԭ��

void Algo_2_25(SqList La,SqList Lb,SqList *Lc);
void PrintElem(LElemType_Sq e);

int main(int argc,char argv[])
{
    SqList La,Lb,Lc;
    int i;
    //ԭ�����������У�Ϊ����if�Ƿ���ͬʱ��ɳ�ʼ����д
    InitList_Sq(&La);
    InitList_Sq(&Lb);
    //if��߸���InitList_Sq  �ǽ������ж��û���ͬʱ����˳�ʼ��������
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
    printf("Lc = La��Lb =  ");
    ListTraverse_Sq(Lc,PrintElem);
    printf("\n\n");

    return 0;
}

//ʵ��A��B�Ĺ��ܺ���

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
