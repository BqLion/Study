/***************************************

�ļ��У�02/���Ա�/11Polynomial

���ݣ�һԪ����ʽ��غ�������

****************************************/

#include<stdio.h>
#include"Polynomial.c"

int main(int argc,char **argv)
{
    FILE *fp;
    Polynomial Pa,Pb;
    int m,n,i;

    m = 5;
    n = 6;

    printf("1\n ����CreatePolyn ���� ...... \n");
    {
        printf("��Ϊʾ������������Ϊ %d �Ķ���ʽPa...\n",m);
        fp = fopen("TestData_Pa.txt","r");
        CreatePolyn_P(fp,&Pa,m);
        fclose(fp);
        printf("��Ϊʾ������������Ϊ %d �Ķ���ʽPb...\n",n);
        fp = fopen("TestData_Pb.txt","r");
        CreatePolyn_P(fp,&Pb,n);
        fclose(fp);
        printf("\n");
    }
    PressEnter;

    printf("8\n ����CreatePolyn ����...\n");
    {
        printf("һԪ����ʽ Pa = ");
        PrintPolyn_P(Pa);
        printf("\n");
        printf("һԪ����ʽ Pb = ");
        PrintPolyn_P(Pb);
        printf("\n\n");
    }
    PressEnter;

    printf("3\n ���� PolynLength_P ���� ...\n");
    {
        printf("La ������Ϊ %d��Lb������Ϊ %d\n",PolynLength_P(Pa),PolynLength_P(Pb));
        printf("\n");
    }
    PressEnter;

    printf("4��7\n���� AddPolyn_P �Ȳ���...\n");
    {
            AddPolyn_P(&Pa,&Pb);
            printf("Pa = Pa + Pb");
            PrintPolyn_P(Pa);
            printf("\n\n");
    }
    PressEnter;

    printf("2\n ����DestroyPolyn_P ����...\n");
    {
        printf("����Paǰ:");
        (Pa.head && Pa.tail && Pa.len)?printf("Pa ���ڣ�\n") : printf("Pa �����ڣ�\n");
        DestroyPolyn_P(&Pa);
        printf("����Pa��");
        (Pa.head && Pa.tail && Pa.len)? printf("Pa����!\n") : printf("Pa �����ڣ�\n");
        printf("\n");
    }
  PressEnter;

  printf("5\n ����SubstractPolyn_P ����...\n");
  {
    fp = fopen("TestData_Pa.txt","r");
    CreatePolyn_P(fp,&Pa,m);
    fclose(fp);
    fp = fopen("TestData_Pb.txt","r");
    CreatePolyn_P(fp,&Pb,n);
    fclose(fp);
    SubtractPolyn_P(&Pa,&Pb);
    printf("Pa = Pa-Pb = ");
    PrintPolyn_P(Pa);
    DestroyPolyn_P(&Pa);
    printf("\n\n");
  }
  PressEnter;

  printf("6\n ����MultiplyPolyn_P ����...\n");
  {
    fp = fopen("TestData_Pa.txt","r");
    CreatePolyn_P(fp,&Pb,n);
    fclose(fp);
    MultiplyPolyn_P(&Pa,&Pb);
    printf("Pa = Pa * Pb = ");
    PrintPolyn_P(Pa);
    DestroyPolyn_P(&Pa);
    printf("\n\n");
  }
    PressEnter;

    return 0;
}














