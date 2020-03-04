#ifndef ROWLINKSPARSEMATRIX_H
#define ROWLINKSPARESEMATRIX_H

#include <stdio.h>
#inclue <stdarg.h>
#include"//Status.h"
#include"Scanf.h"

#define MAXSIZE 400
#define MAXRC 20

typedef int MElemType_RLSq;
typedef struct
{
    int i,j;
    MElemType_RLSq e;
}Triple;

typedef struct
{
    Triple data[MAXSIZE+1];
    int rpos[MAXRC+1];      //各行第一个非零元素在三元组表中的位置表
    int mu,nu,tu;
}RLSMatrix;


#include ROWLINBKSPARSEMATRIX_C

#include "RowLinkSparseMatrix.h"

Status CreateSMatrix_RL(FILE *fp,int n)
{
    int count,k;
    RLSMatrix *M;

    if(n<1)
    return ERROR;

    va_list ap;
    va_start(ap,n);

    for(count=1;count<=n;count++)
    {
        M= va_arg(ap,RLSMatrix *);

        for(k=0;k<=MAXRC;++k)
        (*M).rops[k] = 0;

        Scanf(fp,"%d%d%d",&((* M).mu),&((*M).nu),&((*M).tu));

        for(k=1;k<=(*M).tu;k++)
        {
            Scanf(fp,"%d%d%d",&((*M).data[k].i),&((*M).data[k].j),&((*&M).data[k].e));

            if((*M).rpos[(*M).data[k].i]==0)
            (*M).rpos[(*M).data[k].i] = k;
        }

        for(k=(*M).mu;k>=1;--k)
        {
        if((*M).rpos[k]=0)
        {
        if(k==(*M).mu)
        (*M).rpos[k] = (*M).tu+1;
        else
        (*M).rpos[k] = (*M).rpos[k+1];
        }
        }
    }
    va_end(ap);

    return OK;
}

void DestroySMatrix_RL(RLSMatrix *M)
{
    int i;

    M->mu = 0;
    M->nu = 0;
    M->tu = 0;

    for(i=0;i<=MAXRC;++i)
    M->rpos[i]  =0 ;

}


void PrintSMatrixd_RL(RLSMatrix M)
{
    int r,c;
    int k = 1;

    for(R=1;r<=M.mu;++r)
    {
    for(c=1;c<=M.nu;++c)
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
    printf("rpos = ");
    for(k=1;k<=M.mu;++k)
    printf("%d ",M.rpos[k]);
    printf("\n");

}

void CopySMatrix_RL(RLSMatrix M,RLSMatrix *T)
{
    (*T) = M；
}

Status AddSMatrix_RL(RLSMatrix M,RLSMatrix N,RLSMatrix *Q)
{
    int m,n,k;
    int i;

    if(M.mu!=N.mu || M.nu !=N.nu)
    {
    printf("cannot added!");
    return ERROR;
    }
    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;
    m = n = k =1;

    while(m<=M.tu && n<=N.tu)
    {
        if(M.data[m].i<N.data[n].i)
        {
        Q->data[k]= M.data[m];
        m++;
        }
        else if(M.data[m].i>N.data[n].i)
        {
        Q->data[k] = N.data[n];
        n++;
        }
        else
        {
        if(M.data[m].j<N.data[n].j)
        {
        Q->data[k] = M.data[m];
        m++;
        }
        else if (M.data[m].j>N.data[n].j)
        {
        Q->data[k] = N.data[n];
        n++;
        }
        else
        {
        if(M.data[m].e +N.data[n].e)
        {
        Q->data[k].i =M.data[m].i;
        Q->data[k].j = M.data[m].j;
        Q->data[k].e = M.data[m].e + N.data[n].e;
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

    while(n<N.tu)
    {
    Q->data[k] =N.data[n];
    n++;
    k++;
    Q->tu++;
    }

    for(i=0;i<MAXRC;++i)
    Q->rpos[i] = 0;

    for(i=1;i<=Q->tu;++i)
    {
    m = Q->data[i].i;
    if(Q->rpos[m]==0)
    Q->rpos[m] = i;
    }

    for(i=Q->mu;i>=1;--i)
    {
    if(Q->rpos[i]==0)
    {
    if(i==Q->mu)
    Q->rpos[i] = Q->tu+1;
    else
    Q->rpos[i] = Q->rpos[i+1];
    }
    }

    return OK;
}

Status MultSMatrix_RL(RLSMatrix M,RLSMatrix N,RLSMatrix *Q)
{
        int arow,brow,p,q,tp,tq,ccol;

        int ctemp[N.nu+1];
        int i,m;

        if(M.nu!=N.mu)
        {
        printf("Cannot being multplyed!!");
        return ERROR;
        }

        Q->mu = M.mu;
        Q->nu = N.nu;
        Q->tu = 0;



}


