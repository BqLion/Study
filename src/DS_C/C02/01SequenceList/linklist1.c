#ifndef CROSSLIST_H
#define CROSSLIST_H

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

typedef int CElemType;
typedef struct OLNode;
{
    int i,j;
    CElemType e;
    struct OLNode *right;
    struct OLNode *down;
}OLNode;

typedef OLNode *OLink;
typedef OLNode *OLink;

typdef struct
{
    OLink *rhead;
    OLink *chead;
    int mu,nu,tu;
}CrossList;


#include "CrossList.h"
Status CreateSMatrix_OL(FILE *fp;int n)
{
    int count,k;
    OLNode *p,*q;
    CrossList *M;

    if(n<1)
    return ERROR;

    va_list ap;
    va_start(ap,n);

    for(count=1;count<=n;count++)
    {
    M=va_arg(ap,CrossList *);
    Scanf(fp,"%d%d%d",&((*M).mu),&((*M).nu),&((*M).tu));

    (*M).rhead = (OLink*)malloc(((*M).mu+1)*sizeof(OLink));

    if(!(*M).rhead)
    eixt(OVERFLOW);

    (*M).chead = (OLink *)malloc(((*M).nu+1)*sizeof(OLink));
    if(!(*M).chead)
    exit(OVERFLOW);

    for(k=0;k<=(*M).mu;++k)
    (*M).rhead[k] = NULL;
    for(k=0;k<=(*M).nu;++k)
    (*M).chead[k] = NULL;

    for(k=1;k<=(*M).tu;++k)
    {
    p = (OLNode*)malloc(sizeof(OLNode));
    if(!p)
    exit(OVERFLOW);

    Scanf(fp,"%d%d%d",&(p->i),&(p->j),&(p->e));
    p->right = p->down = NULL;

    if((*M).rhead[p->i]==NULL || (*M).rhead[p->i]->j>p->j)
    {
    p->right = (*M).rhead[p->i];
    (*M).rhead[p->i] = p;
    }
    else
    {
    for(q=(*M).rhead[p->i];(q->right)&&(q->right->j<p->j);q = q->right);
    if(q->j==p->j || ((q->right)&&q->right->j==p->j))
    {
    printf("此位置已经被占用！！\n");
    exit(ERROR);
    }

    p->right   = q->right;
    q->right = p;
    }

    if((*M).chead[p->j]==NULL || (*M).chead[p->j]->i>p->i
    {
    p->down = (*M).chead[p->j];
    (*M).chdead[p->j] = p;
    }
    else
    {
        for(q=(*M).chead[p->j];(q->down)&&(q->down->i<p->i);q=q->down);

        if(q->i==p->i || ((q->down)&&q->down->i==p->i))
        {
        printf("位置已经被占用")；
        exit(ERROR);
        }

        p->down  q->down;
        q->down = p;

    }

    }
    }

    va_end(ap);
    return OK;
}


void DestroySMatrix_OL(CrossList *M)
{

    int i;
    OLNode *p,*q;

    for(i=1;i<=(*M).mu;++i)
    {
    p=(*M).rhead[i];
    while(p)
    {
    q=p;
    p = p->right;
    free(q);
    }

    }

    free((*M).rhead);
    free((*M).chead);

    (*M).rhead = (*M.chead) = NULL;
    (*M).mu = (*M).nu  = (*M).tu = 0;
}

Status SubSMatrix_OL(CrossList M,CrossList N,CrossList *Q)
{
    int i;
    OLNode *pm,*pn,*p,*r,*l;

    if(M.mu!=N.mu || M.nu!=N.nu)
    {
    printf("两均沾不能相减！！\n");
    return ERROR;
    }
}
Q->mu = N.mu;
Q->nu = M.nu;
Q->tu = 0;

Q->rhead = (OLink*)malloc((Q->mu+1)*sizeof(OLink));
if(!Q->rhead)
exit(OVERFLOW);
Q->chead = (OLink*)malloc((Q->nu+1)*sizeof(OLink));
if(!Q->chead)
exit(OVERFLOW);

for(i=0;i<=Q->mu;++i)
Q->rhead[i] = NULL;
for(i=0;i<=Q->NU;++I)
Q->chead[i] = NULL;

for(i=1;i<=M.mu;++i)
{
pm = M.rhead[i];
pn = N.rhead[i];

while(pm && pn)
{
    if(pm->j == pn->j && pm->e-pn->e ==0)
    {
    pm = pm->right;
    pn  = pn->right;
    continue;
    }

    p = (OLNode*)malloc(sizeof(OLNode));

    if(!p)
    exit(OVERFLOW);

    if(pm->j<pn->j)
    {
    p->i = pm->i;
    p->j = pm->j;
    p->e = pm->e;
    pm = pm->right;
    }
    else if(pm->j>pn->j)
    {
    p->i = pn->i;
    p->j = pn->j;
    p->e = pn->e;
    pn = pn->right;
    }
    else
    {
    p->i = pm->i;
    p->j = pm->j;
    p->e = pm->e -pn->e;
    pm = pm->right;
    pn = pn->right;
    }

    p->right = p->down = NULL;

    Q->tu++;


}
}
