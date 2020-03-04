/*******************************

�ļ��У�C04/01

�ļ���:SequenceString

�㷨4.1  4.2   4.3  4.4

*****************************/

#ifndef SEQUENCESTRING_C
#define SEQUENCESTRING_C

#include"SequenceString.h"

Status StrAssign_Sq(SString T,const char *chars)            //����T��ֵ
{
    int i,len;

    len = strlen(chars);

    if(len>MAXSTRLEN)
    return ERROR;
    else
    {
        T[0] = len;                         //ѭ����ֵ�����е�һ���ַ���������ַ�������
        for(i=1;i<=len;i++)
        T[i] = chars[i-1];

        return OK;
    }
}

void StrCopy_Sq(SString T,SString S)
{
    int i;

    for(i=0;i<=S[0];i++)
        T[i] = S[i];
}

Status StrEmpty_Sq(SString S)
{
     if(S[0]==0)
     return TRUE;
     else
     return FALSE;
}

int StrCompare_Sq(SString S,SString T)
{
    int i = 1;

    while(i<=S[0] && i<=T[0])
    {
    if(S[i]==T[i])
    i++;
    else
    return S[i]-T[i];
    }

    return S[0]-T[0];           //����һ�������ز�һ�����ַ�����١�������/ĸ����ϵ�����س��Ȳ�ࡣ����ȣ����س��Ȳ��Ϊ0
}

int StrLength_Sq(SString S)
{
    return S[0];
}

void ClearString_Sq(SString S)
{
    S[0] = 0;
}

void DestroyString_Sq(SString S)
{
//˳�򴮲��ܱ�����
}

//4.2
Status Concat_Sq(SString T,SString S1,SString S2)
{
    int i;

    for(i=1;i<=S1[0];i++)
    T[i] = S1[i];

    if(S1[0]+S2[0]<=MAXSTRLEN)          //û�������ƴ����
    {
    for(i=1;i<=S2[0];i++)
    T[S1[0]+i] = S2[i];

    T[0] = S1[0]+S2[0];

    return OK;
    }

    else
    {
        for(i=1;S1[0]+i<=MAXSTRLEN;i++)         //����ˣ�ƴ�Ӷ�������٣���255Ϊֹ
            T[S1[0]+i] = S2[i];

            T[0] = MAXSTRLEN;

    return ERROR;
    }
}

Status SubString_Sq(SString Sub,SString S,int pos,int len)
{
    int i;

    if(pos<1 || pos>S[0] || len<0 || pos+len-1>S[0])
    return ERROR;

    for(i=1;i<=len;i++)                 // ���û�б���Ļ������S��pos��ʼ len�����ȵ��ַ���
        Sub[i] = S[pos+i-1];

    Sub[0] = len;

    return OK;
}

//�㷨4.1

int Index_Sq_1(SString S,SString T,int pos)
{
    int s,t;
    SString Sub;            //SubString_Sq ��ȡS�е�pos��λ����t�����ȵ��ַ������ص�Sub�С�
                                  //������Index�Ƿ��أ���һ�����ַ�T��ͬ��S�ַ�������ʼλ�á�   1.��һ��S��ȡT���ȵ��ַ���  2.ȡ����֮����T�Ƚϣ������ͬ��OK
    if(pos>0)
    {
    s = StrLength_Sq(S);
    t = StrLength_Sq(T);

    if(s && t)
    {
        while(pos+t-1<=s)
        {
        SubString_Sq(Sub,S,pos,t);

        if(!StrCompare_Sq(Sub,T))
        return pos;

        pos++;
        }
    }
    }
    return 0;
}

int Index_Sq_2(SString S,SString T,int pos)
{
    int i = pos;
    int j = 1;

    if(pos<1)
    return 0;

    while(i<=S[0] && j<=T[0])
    {
        if(S[i]==T[j])
        {
        i++;
        j++;
        }
        else
        {
        i = i - (j-1) + 1;
        j = 1;
        }
    }

    if(j>T[0]&&T[0])
    return i-T[0];
    else
    return 0;
}

Status Replace_Sq(SString S,SString T,SString V)
{
    int i;

    i = Index_Sq_2(S,T,1);

    while(S[0]-T[0]+V[0]<=MAXSTRLEN && i)
    {
        StrDelete_Sq(S,i,T[0]);
        StrInsert_Sq(S,i,V);

        i += V[0];

        i = Index_Sq_2(S,T,i);
    }

    if(i==0)
    return OK;
    else
    return ERROR;
}

Status StrInsert_Sq(SString S,int pos,SString T)
{
    int i;

    if(pos<1 || pos>S[0]+1 || S[0]+T[0]>MAXSTRLEN)
        return ERROR;

        for(i=S[0];i>=pos;i--)
        S[i+T[0]]  = S[i];

        for(i=pos;i<=pos+T[0]-1;i++)
        S[i] = T[i-pos+1];

        S[0] += T[0];

        return OK;
}

Status StrDelete_Sq(SString S,int pos,int len)
{
    int i;
    if(pos<1 || pos+len-1>S[0] || len<0)
    return ERROR;

    for(i = pos+len;i<=S[0];i++)
        S[i-len] = S[i];

        S[0] -=len;

        return OK;
}

void StrPrint_Sq(SString S)
{
    int i;

    for(i=1;i<=S[0];i++)
    printf("%c",S[i]);
}

#endif

