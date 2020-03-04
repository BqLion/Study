//wenjianjia :  triplesparsematrix

#ifndef TRIPLESPARSEMATRIX_H
#define TRIPLESPARSEMATRIX_H

#include <stdio.h>
#include <stdarg.h>

#define MAXSIZE 400

typedef int MElemType_TSq;
typedef struct
{
        int i,j;
        MElemType_TSq e;
}Triple;
typedef struct
{
    Triple data[MAXSIZE+1];
    int mu,nu,tu;

}TSMatrix;

#ifndef TRIPLESPARSEMATRX_C
#define TRIPLESPARSEMATRIX_C

#include"TriplesarseMatrix.h"

Status CreateSMatrix_T(FILE *fp,int n)
{
    int count,k;
    TSMatrix *M;

    if(n<1)
    return ERROR;

    va_list ap;
    va_start(ap,n);

    for(count=1;count<=n;count++)
    {
    M=va_arg(ap,TSMatrix*);

    Scanf(fp;k<=(*M).tu;k++)
    Scanf(fp," %d%d%d",&((*M).data[k].i),&((*M).data[k].j),&((*M).data[k].e));
    }
    va_end(ap);

    return OK;
}

void DestroySMatrix_T(TSMatrix *M)
{
    (*M).mu= 0;
    (*M).nu= 0;
    (*M).tu= 0;
}

void PrintSMatrix_T(TSMatrix X)
{
    int r,c;
    int k =1;

    for(r=1;r<=M.mu;r++)
    {
    for(c=1;c<=M.nu;c++)
    {
    if(r==M.data[k].i && c==M.data[k].j)
    {
    printf("%3d ",M.data[k].e);
    k++;
    }
    else
    printf("  0  ");
    }
    printf("\n");
    }
}


void CopySMatrix_T(TSMatrix M,TSMatrix *T)
{
    (*T) = M;
}

Status AddSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q)
{
int m,n,k;

if(M.mu!N.mu || M.nu!=N.nu)
{
printf("two matrix cannot being added!!");
return ERROR;
}

Q->mu = M.mu;
Q->nu = M.nu;
Q->tu =  0;

m = n = k =1;

while(m<=M.tu && n<=N.tu)
{
if(M.data[m].i<N.data[n].i)
{
Q->data[k] = M.data[m];
m++;
}
else if(M.data[m].i>N.data[n].i)
{
Q->data[k]=N.data[n];
n++;
}
else
{
    if(M.data[m].j<N.data[n].j)
    {
    Q->data[k]=M.data[m];
    m++;
    }
    else if(M.data[m].j>N.data[n].j)
    {
    Q->data[k] = N.data[n];
    n++;
    }
    else
    {
    if(M.data[m].e+N.data[n].e)
    {
    Q->data[k].i = M.data[m].i;
    Q->data[k].j = M.data[m].j;
    Q->data[k].e = M.data[m].e +N.data[n].e;
    m++;
    n++;
    }
    else
    {
    m++;
    n++;
    continue;
    }
    }
}
k++;
Q->tu++;
}
while(m<=M.tu)
{
Q->data[k] = M.data[m];
m++;
k++;
Q->tu++;
}
while(n<=N.tu)
{
Q->data[k] = N.data[n];
n++;
k++;
Q->tu++;
}
return OK;
}

Status MultSMatrix_T(TSMatrix M,TSMatrix N,TSMatrix *Q)
{
    int m,n,i,j,k;
    MElemType_TSq c,c1,c2;

    if(M.nu!=N.mu)
    {
    printf("two matrix cannot do multply\n");
    return ERROR;
    }

    Q->mu = M.mu;
    Q_>nu = N.nu;
    Q->tu = 0;

    if(M.tu*N.tu)
    {
    for(i=1;i<=M.mu;i++)
        {
        for(j=1;j<=N.nu;j++)
            {
            c = 0;
            for(k=1;k<=M.mu;k++)
            {
            c1 = 0;
            for(m=1;m<M.tu;m++)
            {
            if(M.data[m].i==i && M.data[m].j == k)
            {
            c1 = M.data[m].e;
            break;
            }
            }

            c2 = 0;
            for(n=1;n<=N.tu;n++)
            {
                if(N.data[n].i==k && N.data[n].j==j)
                {
                c2 = N.data[n].e;
                break;
                }
            }

            if(c1 && c2)
            c +=c1*c2;
            }

            if(c)
            {
            Q->tu++;
            Q->data[Q->tu].i = i;
            Q->data[Q->tu].j = j;
            Q->data[Q->tu].e = c;
            }
            }
        }
    }

    return OK;
}







