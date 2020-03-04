//多项式：编写算法求多项式本身的值，多项式相减的值
//时间复杂度：因为要遍历p1 p2,所以时间复杂度为O(n1+n2)
//时间0:00    完成1:12
#include<stdio.h>
#include<math.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

typedef struct
{
    int coef;               //系数
    int exp;                //指数
}PolyTerm;                                  //多项式数据结构的结点
typedef struct
{                                                               //多项式的顺序存储结构
        PolyTerm *data;
        int last;                                           //多项式项数
}SqPoly;                                                  //多项式本身，也就是一个顺序存储表

int Algo_2_39(SqPoly P,int x);
Status Algo_2_40(SqPoly Pa,SqPoly Pb,SqPoly *Pc);           //三个多项式，做相减的操作
Status CreatPoly_Sq(SqPoly *P,int n,PolyTerm Data[]);
void OutputPoly_Sq(SqPoly P);

int main(int argc,char *argv[])
{
    PressEnter;

    SqPoly Pa,Pb,Pc;
    PolyTerm a[5] = {{-2,1},{4,3},{11,5},{-7,7},{8,9}};             //内存存储结构上来说这是一个顺序存储表，单个结点有两个数据分别是指数和系数。逻辑结构上这是一个多项式
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

    printf("题2.39验证...\n");
    printf("计算多项式Pa的值 Pa = %d",Algo_2_39(Pa, 2));
    printf("\n");
    printf("计算多项式Pb的值 Pb = %d",Algo_2_39(Pb,2));
    printf("\n\n");

    printf("题2.40验证...\n");
    Algo_2_40(Pa,Pb,&Pc);
    printf("Pcn(x) = ");
    OutputPoly_Sq(Pc);
    printf("\n");
    printf("计算多项式Pc的值 Pc = %d",Algo_2_39(Pc,2));
    printf("\n\n");
    return 0;
}

//求多项式的值
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
        if(Pa.data[i].exp<Pb.data[j].exp)           //队列A（被减数）中的元素的次数要小一些：
        {
        (*Pc).data[k++] = Pa.data[i];                 //Pc这个相对应的项就取A里边的值,A被取过值，可步进
        i++;
        }
    else if(Pa.data[i].exp>Pb.data[j].exp)          //被减数的项的次数比Pb减数的大，这时直接减pB，次数不变，系数反转
    {
    (*Pc).data[k].coef = -Pb.data[j].coef;
    (*Pc).data[k].exp = Pb.data[j].exp;
    k++;
    j++;

    }
    else
    {
    sum = Pa.data[i].coef - Pb.data[j].coef; //项数相等就直接减，如果减后不为零，则做如下操作
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
