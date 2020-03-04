//����ʽ����д�㷨�����ʽ�����ֵ������ʽ�����ֵ
//ʱ�临�Ӷȣ���ΪҪ����p1 p2,����ʱ�临�Ӷ�ΪO(n1+n2)
//ʱ��0:00    ���1:12
#include<stdio.h>
#include<math.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

typedef struct
{
    int coef;               //ϵ��
    int exp;                //ָ��
}PolyTerm;                                  //����ʽ���ݽṹ�Ľ��
typedef struct
{                                                               //����ʽ��˳��洢�ṹ
        PolyTerm *data;
        int last;                                           //����ʽ����
}SqPoly;                                                  //����ʽ����Ҳ����һ��˳��洢��

int Algo_2_39(SqPoly P,int x);
Status Algo_2_40(SqPoly Pa,SqPoly Pb,SqPoly *Pc);           //��������ʽ��������Ĳ���
Status CreatPoly_Sq(SqPoly *P,int n,PolyTerm Data[]);
void OutputPoly_Sq(SqPoly P);

int main(int argc,char *argv[])
{
    PressEnter;

    SqPoly Pa,Pb,Pc;
    PolyTerm a[5] = {{-2,1},{4,3},{11,5},{-7,7},{8,9}};             //�ڴ�洢�ṹ����˵����һ��˳��洢������������������ݷֱ���ָ����ϵ�����߼��ṹ������һ������ʽ
    PolyTerm b[5] = {{3,2},{-5,3},{12,4},{-7,7},{6,11}};

      PressEnter;

    CreatPoly_Sq(&Pa,5,a);
    CreatPoly_Sq(&Pb,5,b);
    printf("Pan(x) = ");

    PressEnter;
    OutputPoly_Sq(Pa);
    printf("\n");
    printf("Pbn(X) = ");
    OutputPoly_Sq(Pb);
    printf("\n\n");

    PressEnter;

    printf("��2.39��֤...\n");
    printf("�������ʽPa��ֵ Pa = %d",Algo_2_39(Pa, 2));
    printf("\n");
    printf("�������ʽPb��ֵ Pb = %d",Algo_2_39(Pb,2));
    printf("\n\n");

    printf("��2.40��֤...\n");
    Algo_2_40(Pa,Pb,&Pc);
    printf("Pcn(x) = ");
    OutputPoly_Sq(Pc);
    printf("\n");
    printf("�������ʽPc��ֵ Pc = %d",Algo_2_39(Pc,2));
    printf("\n\n");
    return 0;
}

//�����ʽ��ֵ
int Algo_2_39(SqPoly P,int x)
{
    int i,sum;

    for(i = 0,sum=0;i<P.last;i++)
        sum+= P.data[i].coef *(int)(pow(x,P.data[i].exp));

    return sum;
}
//2.40 Pc = Pa - Pb

Status Algo_2_40(SqPoly Pa,SqPoly Pb,SqPoly *Pc)
{
    int i,j,k,sum;

    (*Pc).data = (PolyTerm *)malloc((Pa.last+Pb.last)*sizeof(PolyTerm));
    if(!(*Pc).data)
        exit(OVERFLOW);

    i = j = k = 0;

    while(i<Pa.last && j<Pb.last)
    {
        if(Pa.data[i].exp<Pb.data[j].exp)           //����A�����������е�Ԫ�صĴ���ҪСһЩ��
        {
        (*Pc).data[k++] = Pa.data[i];                 //Pc������Ӧ�����ȡA��ߵ�ֵ,A��ȡ��ֵ���ɲ���
        i++;
        }
    else if(Pa.data[i].exp>Pb.data[j].exp)          //����������Ĵ�����Pb�����Ĵ���ʱֱ�Ӽ�pB���������䣬ϵ����ת
    {
    (*Pc).data[k].coef = -Pb.data[j].coef;
    (*Pc).data[k].exp = Pb.data[j].exp;
    k++;
    j++;

    }
    else
    {
    sum = Pa.data[i].coef - Pb.data[j].coef; //������Ⱦ�ֱ�Ӽ����������Ϊ�㣬�������²���
    if(sum)
    {
        (*Pc).data[k].coef = sum;
        (*Pc).data[k].exp = Pa.data[i].exp;
        k++;
    }

    i++;
    j++;

    }
    }

    while(i<Pa.last)
    {
    (*Pc).data[k++] = Pa.data[i];
    i++;
    }

    while(j<Pb.last)
    {
        (*Pc).data[k].coef = -Pb.data[j].coef;
        (*Pc).data[k].exp = Pb.data[j].exp;
        k++;
        j++;

    }
    (*Pc).last = k;

    return OK;
}


Status CreatPoly_Sq(SqPoly *P,int n,PolyTerm Data[])
{
    int i ;
    (*P).last = n;
    (*P).data = (PolyTerm *)malloc(n*sizeof(PolyTerm));
    if(!(*P).data)
        exit(OVERFLOW);

    for(i=0;i<=n;i++)
    (*P).data[i]= Data[i];

    return OK;
}


void OutputPoly_Sq(SqPoly P)
{
    int i;

    for(i=0;i<P.last;i++)
    {
    if(i==0)
        printf("%d ",P.data[i].coef);
    else
    {
        if(P.data[i].coef<0)
        {
        printf(" - ");
        printf("%d ",-P.data[i].coef);
        }
        else
        {
            printf(" + ");
            printf("%d ",P.data[i].coef);
        }
        }

    if(P.data[i].exp)
    {
        printf("x");
        if(P.data[i].exp!=1)
            printf("^%d",P.data[i].exp);

    }
    }


}
