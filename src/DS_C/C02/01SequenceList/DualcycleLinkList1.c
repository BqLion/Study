#ifndef DUALCYCLELINKEDLIST_H
#define DUALCYCLELINKEDLIST_H

#include<stdlib.h>

typedef int LElemType_DC;
typedef struct DuLNode
{
    LElemType_DC data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode;
typedef DuLNode * DuLinkList;



#include DualCycleLinkedList.h

Status INitList_Dul(DulLinkList *L)
{
    *L = (DulLinkList)malloc(sizeof(DuLNode));
    if(!(*L))
    exit(OVERFLOW);

    (*L)->next = (*L)->prior = *L;

    return OK;
}

Status ClearList_Dul(DuLinkList L)
{
    DuLinkList p,q;

    p = L->next;

    while(p!=L)
    {
    q = p->next;
    free(p);
    p = q;
    }
    L->next = L->prior = L;
    return OK;
}

void DestroyList_Dul(DuLinkList *L)
{
ClearList_DuL(*L);

free(*L);

*L = NULL;
}

Status DestroyList_Dul(DuLinkList *L)
{
    ClearList_Dul(*L);

    free(*L);

    *L = NULL;
}


Status ListEmpty_Dul(DuLinkList L)
{
    if(L  &&  L->next ==L && L->prior== L)
    return TRUE;
    else
    retrun  FALSE;
}

int ListLength_Dul(DuLinkList L)
{
    DuLinkList p;
    int count;

    if(L)
    {
    count = 0;
    p =L;
    while(p->next!=L)
    {
    count++;
    p = p->next;
    }
    }
    return count;

}

Status GetElem_Dul(DuLinkList L,int i,LElemType_DC *e)
{
DuLinkList p;
int count;

if(L)
{
count = 1;

p = L->next;

while(p!=L && count<i)
{
count++;
p = p->next;
}

if(p£¡=L)
{
*e = p->data;
return OK;
}
}
return ERROR;
}

int LocateElem_Dul(DuLinkList L,LElemType_DC e,Status(Compare)(LElemType_DC,LElemType_DC))
{
DuLinkList p;
int count;

if(L)
{
count = 1;
p = L->next;

while(p!=L && !Compare(e,p->data))
{
count++;
p = p->next;
}
}
if(p!=L)
return count;
}
return 0;
}


Status PriorElem_Dul(DuLinkList L,LElemType_DC cur_e,LElemType_DC *pre_e)
{
DuLinkList p;
if(L)
{
p = L->next;

while(p!=L && p->data!=cue_e)
p = p->next;

if(p!=L && p->prior!=L)
{
*pre_e = p->prior->data;
return OK;
}
}
return ERROR;
}


Status NextElem_DuL(DuLinkList L,LElemType_DC cur_e,LElemType_DC *next_e)
{
DuLinkList p;

if(L)
{
p = L->next;

while(p!=L && p->data!=cur_e)
p = p->next;

if(p!=L && p->next!=L)
{
*next_e = p->next->data;
return OK;
}
}
return ERROR;
}


DuLinkList GetElemPtr_DuL(DuLinkList L,int i)
{
 int count;
 DuLinkList p;

 if(L && i>0)
 {
 count = 1;
 p = L->next;

 while(p!=L && count<i)
 {
 count++;
 p = p->next;
 }
 if(p!=L)
 return p;
 }
 return NULL;
}


Status ListInsert_Dul(DuLinkList L,int i,LElemType_DC e)
{
DuLinkList p,s;

if(i<1 || i>ListLength_DuL(L)+1)
return ERROR;

p = GetElemPtr_Dul(L,i);

if(!p)
p = L;

s = (DuLinkList)malloc(sizeof(DulNode));
if(!s)
exit(OVERFLOW);
s->data = e;
s->prior = p->prior;
s->next= p;
p->prior->next = s;
p->prior = s;

return OK;
}

Status ListDelete_DuL(DuLinkList L,int i,LElemType_DC *e)
{

DuLinkList p ;
if(!(p = GetElemPtr_Dul(L,i)))
return ERROR;

*e = p->data;
p->prior->next = p->next;
p->next->prior = p->prior;

free(p);
p = NULL;

return OK;
}

void ListTraverse_Dul(DuLinkList L,void(Visit)(LElemType_DC))
{
DuLinkList p;

p = L->next;

while(p!=L)
{
Visit(p->data);
p = p->next;
}
}

#endif




