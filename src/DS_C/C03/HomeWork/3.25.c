#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

int Algo_3_25_1(int n);
int Algo_3_25_2(int n);

int main(int argc,char *argv[])
{
    prinf("F(5) = %d\n,Algo_3_25_1(5)");
    printf("\n");
    printf("F(10) = %d\n",Algo_3_25_2(10));
    printf("\n");

    return 0;
}

//µ›πÈº∆À„

int Algo_3_25_1(int n)
{
    if(n<0)
    exit(ERROR);

    if(!n)
    return n+1;

    else

    return (2*Algo_3_25_1(n/2));
}

//µ¸¥˙









