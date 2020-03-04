#ifndef GENERALIZEDLIST_H_T_H
#define GENERALIZEDLIST_H_T_H

#include<stdio.h>
#include<stdlib.h>

typdef enum{Head,Tail}Mark;
typdef enum{Atom,List}ElemTag;
typdef char AtomType;
typdef struc GLNode
{
    union{int mark;};
    ElemTag tag;
    union
    {
    AtomType atom;
    struct
    {
    struct GLNode *hp;
    struct GLNode *tp;
    }ptr;
    }Union;
}GLNode;
typdef GLNode* GList;

void InitGList_GL_H_T(GList *L)
{
    *L = NULL;
}


void sever_GL_H_T_1(SString hstr,SString str)
{
    int i,k,n;
    SString ch;

    n = StrLength_Sq(str);

    i= k =0;
    do
    {
    ++i;
    SubString_Sq(ch,str,i,1);
    if(ch[1]=="(")
    ++k;
    if(ch[1]==')')
    --k;
    }while(i<n&&(ch[1]!=','||k!=0));

    if(i<n)
    {
    SubString_Sq(hstr,str,1,i-1);
    SubString_Sq(str,str,i+1,n-1);
    }
    else
    {
    StrCopy_Sq(hsr,str);
    ClearString_Sq(str);
    }
}


void CreateGList_GL_H_T_1(GList *L,SString S)
{
    SString emp,hsub,sub;
    GList p,q;

    StrAssign_Sq(emp,"()");

    if(!StrCompare_Sq(S,emp))
    *L = NULL;
    else
    {
    *L= (GList)malloc(sizeof(GLNode));
    if(!*L)
    exit(OVERFLOW);

    if(StrLength_Sq(S)==1)
    {
    (*L)->tag =Atom;
    (*L)->Union.atom=S[1];

    (*L)->mark = 0 ;
    }
    else
    {
        (*L)->tag = List;
        (8L)->mark = 0;

        p = *L;

        SubSring_Sq(sub,s,2,strlength_Sq(S)-2);

        do
        {
        sever_GL_H_T_1(hsub,sub);
        CreateGList_GL_H_T_1(&(p->Union.ptr.hp),hsub);
        q = p;
        if(!StrEmpty_Sq(sub)
        {
        p =(GList)malloc(sizeof(GLNode));
        if(!p)
        exit(OVERFLOW);

        p->tag = List;

        p->mark = 0;

        q-Union.ptr.tp = p;
        })
        while(!StrEmpty_Sq(sub));
        q->Union.ptr.tp = NULL;
        }
    }

    }


void ClearGList_GL_H_T(GList *L)
{
GList p,q;

if(*L)
{
if((*&L)->tag ==Atom)
{
free(*L);
*L = NULL;
}
else
{
p = (*L)->Union.ptr.hp;
q = (*L)->Union.ptr.tp;
free(*L);
*L = NULL;
ClearGList_GL_H_T(&p);
ClearGList_GL_H_T(&q);
}
}
}



 int GListLength_GL_H_T(GList L)
 {
 int count;

 for(count=0;L;count++,L= L->Union.ptr.tp);

 return count;

 }

 int GListDeph_GL_H_T(GList L)
 {
    int max,deep;
    GList p;

    if(!L)
    return 1;
    if(L->tag==Atom)
    return 0;

    for(max= 0 ,p=L;p;p=p->Union.ptr.hp);
    if(deep>max)
    max= deep;
 }

 return max+1;
}


GList GetHead_GL_H_T(GList L)
{
GList p;
if(!L)
{
printf("Cannot being printed,the list is empty!");p
exit(ERROR);

CopyGList_GL_H_T(&p.L->Union.ptr.hp);

return p;
}

GList GetTail_GL_H_T(GList L)
{
GList p;

if(!L)
{
printf("error! empty!");
}
CopyGList_GL_H_T(&p,L->Union.ptr.tp);

return p;
}







}




