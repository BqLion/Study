//定义块链串的基本操作

#include<stdio.h>
#include<string.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

typedef LElemType_L strElem;
typedef LNode strNode;
typedef LinkList String;

//函数原型

Status StrAssign_4_21(String *S,char *chars);
Status StrCopy_4_21(String *S,String T);
int StrCompare_4_21(String S，String T);
int StrLength_4_21(String S);
Status Concat_4_21(String *R,String S,String T);
Status SubString_4_21(String *Sub,String S,int pos,int len);
void StrPrint_4_21(String S);

int main(int argc,char *argv[])
{
    char *chars = "@@***#*%%%****(((((*****)))";
    String S,T,R,Sub;
    int i;

    StrAssign_4_21(&T,chars);
    printf("T=  ");
    StrPrint_4_21(T);
    printf("\n\n");

    StrCopy_4_21(&S,T);
    printf("S=  ");
    StrPrint_4_21(S);
    printf("\n\n");

    i = StrCompare_4_21(S,T);
    if(i>0)
    printf("S>T\n");
    else if(i<0)
    printf("S<T\n");
    else
    printf(S = T\n);
    printf("\n");

    i = StrLength_4_21(S);
    printf("S_Len = %d\n,i");
    printf("\n");

    Concat_4_21(&R,S,T);
    printf("R = ");
    StrPrint_4_21(R);
    printf("\n\n");

    SubString_4_21(&Sub,S,11,4);
    printf("Sub = ");
    StrPrint_4_21(Sub);
    printf("\n\n");

    return 0;
}

//字符串赋值
Status StrAssign_4_21(String *S,char *chars)
{
    int i,len;
    String s,p;

    len = strlen(chars);

    InitList_L(S);

    for(i=1,p=*S;I<=len;i++)
    {
    s= (String)malloc(sizeof(strNode));
    if(!s)
    exit(OVERFLOW);
    s->data = chars[i-1];

    s->next = p->next;

    p ->next = s;
    p = p->next;


    }

    return OK;
}

//字符串复制

Status StrCopy_4_21(String *S,String T)
{
    String r,p,s;

    if(!T)
    return ERROR;

    InitList_L(S);
    for(r = *S,p = T->next;p;p=p->next)         //r指向待分配的位置，p指向待复制的字符串T，t没出界的时候就持续步进
    {
    s = (String)malloc(sizeof(strNode));
    if(!s)
    exit(OVERFLOW);
    s->data = p->data;

    s->next= r->next;

    r->next = s;
    r= r->next;
    }
    return OK;
}

int StrCompare_4_21(String S,String T)
{
    String p,q;

    if(S && T)
    {
     p = S->mext;
     q = T->next;

     while(p&&q)
     {
     if(p->data!=q->data)
     return p->data-q->data;

     p = p->next;
     q = q->next;
     }
        reutrn ListLength_L(S)-ListLength_L(T);

    }


}


