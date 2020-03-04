/***************************************

文件夹：02/线性表/11Polynomial

内容：一元多项式相关函数测试

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

    printf("1\n 函数CreatePolyn 测试 ...... \n");
    {
        printf("作为示范，创建项数为 %d 的多项式Pa...\n",m);
        fp = fopen("TestData_Pa.txt","r");
        CreatePolyn_P(fp,&Pa,m);
        fclose(fp);
        printf("作为示范，创建项数为 %d 的多项式Pb...\n",n);
        fp = fopen("TestData_Pb.txt","r");
        CreatePolyn_P(fp,&Pb,n);
        fclose(fp);
        printf("\n");
    }
    PressEnter;

    printf("8\n 函数CreatePolyn 测试...\n");
    {
        printf("一元多项式 Pa = ");
        PrintPolyn_P(Pa);
        printf("\n");
        printf("一元多项式 Pb = ");
        PrintPolyn_P(Pb);
        printf("\n\n");
    }
    PressEnter;

    printf("3\n 函数 PolynLength_P 测试 ...\n");
    {
        printf("La 的项数为 %d，Lb的项数为 %d\n",PolynLength_P(Pa),PolynLength_P(Pb));
        printf("\n");
    }
    PressEnter;

    printf("4、7\n函数 AddPolyn_P 等测试...\n");
    {
            AddPolyn_P(&Pa,&Pb);
            printf("Pa = Pa + Pb");
            PrintPolyn_P(Pa);
            printf("\n\n");
    }
    PressEnter;

    printf("2\n 函数DestroyPolyn_P 测试...\n");
    {
        printf("销毁Pa前:");
        (Pa.head && Pa.tail && Pa.len)?printf("Pa 存在！\n") : printf("Pa 不存在！\n");
        DestroyPolyn_P(&Pa);
        printf("销毁Pa后：");
        (Pa.head && Pa.tail && Pa.len)? printf("Pa存在!\n") : printf("Pa 不存在！\n");
        printf("\n");
    }
  PressEnter;

  printf("5\n 函数SubstractPolyn_P 测试...\n");
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

  printf("6\n 函数MultiplyPolyn_P 测试...\n");
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














