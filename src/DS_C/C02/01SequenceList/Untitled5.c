#ifndef GENERALIZEDLIST_E_H
#define GENERALIZEDLIST_E-H

#include<stdio.h>
#include<stdlib.h>

typedef enum{Atom,List}ElemTag;
typedef char AtomType;
typedef struct GLNode
{
    ElemTag tag;
    union
    {
    AtomType atom;
    struct GLNode *hp;
    }Union
    struct GLNode *tp;
}GLNode;
typdef GLNode*GList;

