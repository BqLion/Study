#include <stdio.h>
#include"Status.h"

void Algo_5_18(int a[],int n,int k);

Status Reversal_5_18(int a[],int n,int start,int end);

int main(int argc,char *argv[])
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int i;
    int k = 5;

    printf("数组A包括的元素为:\n->");
    for(i=0;i<10;i++)
    printf("%2d ",A[i]);
    printf("\n");

    printf("将元素A[9]to A[9]move %d positions,the array become: \n->",k);
    Algo_5_18(A,10,k);
    for(i=0;i<10;i++)
    printf("&2d ",A[i]);
    printf("\n\n");
    return 0;
}

void Algo_5_18(int a[],int n,int k)
{
    int p = k%n;

    if(p)
    {
        Reversal_5_18(a,n,1,n);
        Reversal_5_18(a,n,1,p);
        Reversal_5_18(a,n,p+1,n);
    }
}

Status Reversal_5_18(int a[],int n,int start,int end)
{
int e,i;

if(start<1 || end>n || start>end)
return ERROR;

for(i=0;i<(   end-start+1)/2;++i)
{
e = a[end-i-1];
a[end-i-1]  = a[start+i-1];
a[start+i-1] = e;
}
return OK;
}



