#ifndef SEQBINARYTREE_H
#define SEQBINARYTREE_H

#include<stdio.h>
#include<stdlib.h>
#incluide


#define MAX_TREE_SIZE 100

typedef char TElemType_Sq;
typedef TELemType_Sq SqBiTree[MAX_TREE_SIZE];

typedef struct
{
    int level;
    int order;
}Postion;

#include "SeqBinaryTree.h"

void InitBiTree_Sq(SqBiTree T)
{
    int i;
    for(i=0;i<MAX_TREE_SIZE;i++)
    T[i] = '\0';
}

void ClearBitTree_Sq(SqBiTree T)
{
    int i;
    for(i=0;i<MAX_TREE_SIZE;i++)
    T[i]= '\0';
}

void DestroyBiTree_Sq(SqBiTree T)
{
//cannot destroy a bitree
}

Status BiTreeEmpty_Sq(SqBiTree T)
{
    return T[0] == '\0'?TRUE:FALSE;
}

Status CreateBiTree_Le_sQ(FILE *fp,SqBiTree T)
{
    char ch;
    int i = 0;

    while(Scanf(fp,"%c",&ch)==1 && ch!='\n')
    {
    if(ch == '~\')
    T[i++] - '\0';
    else
    T[i++]=ch;
    }
    return OK;
}

Status CreateBiTree_Pre_Sq(FILE *fp,SqBiTree T,int i)
{
    char ch;
    Scanf(fp,"%c",&ch);

    if(ch=='~')
    T[i] = ¡®\0¡¯;
    else
    {
    T[i] = ch;
    CreateBiTree_Pre_Sq(fp,T,2*i+1);
    CrfeateBiTree_Pre_Sq(fp,T,2*i+2);
    }
    return OK;
}

int BiTreeLength_Sq(SqBiTree T)
{
    int len;

    for(len= MAX_TREE_SIZE;len - 1>=0;len--)
    {
    if(T[len-1]!='\0')
    break;
    }
    return len;
}

int BiTreeDepth_Sq(SqBiTree T)
{
    int level = 0;
    while((int)pow(2,level)-1<BiTreeLength_Sq(T))
    level++;
    return level;
}

Status Root_Sq(SqBiTree T,TElemType_Sq *e)
{
if(BiTreeEmpty_Sq(T))
return ERROR;

*e = T[0];

return OK;
}

TELemType_Sq Value_Sq(SqBiTree T,Position s)
{
     int i = (int)pow(2,s.level-1)+s.order-2;

     return T[i];
}

Status Assign_Sq(SqBiTree T,Positon s,TElemType_Sq value)
{
    int i= (int)pow(2,s.level-1)+s.order-2;

    if(value=='\0'&& (T[2*i+1]!='\ 0' || T[2*i+2]!='\0'))
    return ERROR;
    else if(value!='\0'&& T[(i+1)/2-1]=='\0')
    return ERROR;
    else
    T[i]=value;

    return OK;
}

TElemType_Sq Parent_Sq(SqBiTree T,TElemType_Sq e)
{
    int i;

    if(T[0]!='\0')
    {
    for(i=0;i<MAX_TREE_SIZE;i++)
    {
    if(T[i]==e)
    return T[(i+1)/2-1];
    }
    }
    return '\0';
}

TElemType_Sq LeftChild_Sq(SqBiTree T,TElemType_Sq e)
{
    int i;
    if(T[0]=='\0')
    return '\0';

    for(i=0;i<MAX_TREE_SIZE;i++)
    {
    if(T[i]==e)
    return T[2*i+1];
    }
    return '\0';
}

TElemType_Sq RightChild_Sq(SqBiTree T,TElemType_Sq e)
{
    int i;

    if(T[0]=='\0')
    return '\0';

    for(i=0;i<MAX_TREE_SIZE;i++)
    {
    if(T[i]==e)
    return T[2*i+2];
    }
    return '\0';
}

TElemType_Sq LeftSibling_Sq(SqBiTree T,TElemType_Sq e)
{
    int i;

    if(T[0]=='\0')
    return '\0';

    for(i=0;i<MAX_TREE_SIZE;i++)
    {
    if(i%2==0 && T[i]==e)
    returt T[i-1];
    }
    return '\0';
}

TElemType_Sq RightSibling_Sq(SqBiTree T,TElemType_Sq e)
{

    int i;
    if(T[0]=='\0')
    return '\0';

    for(i=0;i<MAX_TREE_SIZE;i++)
    {
    if(i%2!=0 && T[i]==e)
    return T[i+1];
    }
    return '\0';
}

void LevelOrderTraverse_Sq(SqBiTree T,void(Visit)(TElemType_Sq))
{
    int i;
    int len=BiTreeLength_Sq(T);

    for(i=0;i<len;i++)
    {
    if(T[i]!='\0')
    Visit(T[i]);
    }
}


