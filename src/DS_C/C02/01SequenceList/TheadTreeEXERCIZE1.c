#include  <stdio.h>
#include<stdlib.h>

Status Algo_6_41(BiTree T,TElemType *e,int *order,int k);
int Algo_6_42(BiTree T);
void Algo_6_43(BiTree T);
int Algo_6_44(BiTree T,TElemType x);
void Algo_6_45(BiTree *T,TElemType x);
void Algo_6_46(BiTree T,BiTree *Tx);
void Algo_6_47(BiTree T);
BiTree Algo_6_48(BiTree T,TElemType p,TElemType q);

int main(int argc,char *argv[])
{
    BiTee T,Tx,Tmp;
    TElemType e;
    int k,order;
    char x;
    FILE *fp;
    int mark;

    return 0;
}
//6.41q�����������е�k���ڵ��ֵ

Status Algo_6_41(BiTree T,TElemType *e,int *order,int k)
{
    if(T)
    {
    (*order)++;     //order��������

    if(*order==k)
    {
    *e = T->data;
    return OK;          //when count to k,return the answer
    }
    else
    {
    if(Algo_6_41(T->lchild,e,order,k))
    return OK;
    if(Algo_6_41(T->rchild,e,order,k))
    return OK;
    }
    }
    return ERROR;
}

int Algo_6_42(BiTree T)
{
    int count = 0;

    if(T)
    {
    if(T->lchild==NULL && T->rchild==NULL)
    count++;
    else
    {
    count += Algo_6_42(T->lchild);
    count += Algo_6_42(T->rchild);
    }
    }
    return count;
}

void Algo_6_43(BiTree T)
{
    BiTree p;

    if(T)
    {
    p = T->lchild;
    T->lchild =T->rchild;
    T->rchild = p;

    Algo_6_43(T->lchild);
    Algo_6_43(T->rchild);
    }
}

//6.54 ��˳�������ʽ������

#include <stdio.h>
#include <stdlib.h>
#include

Status Algo_6_54(BiTree *T,TElemType sa[100]);

int main(int argc,char *argv[])
{
    BiTree T;
    TElemType sa[100],e;
    FILE *fp;
    int i;

    i=0;
    fp = fopen("Data/Algo_6_54.txt","r");
    Scanf(fp,"%c",&e);
    while(!feof(fp))
    {
    sa[++i] = e;
    Scanf(fp,"%c",&e);
    }
    fclose(fp);
    sa[0] = i;

    printf("������������˳������ΪT->ABCDEF^G^HI^J\n");
    InitBiTree(&T);
    Algo_6_54(&T,sa);
    printf("\n");

    printf("������TΪ�� \n");
    PrintTree(T);
    printf("\n");
    return 0;
}

Status Algo_6_54(BiTree *T,TElemType sa[100])
{
    int len =sa[0];
    int i,k;
    BiTree p;
    BiTree node[100];

    for(i=1;k=1;i<=sa[0];i++)
    {
    if(sa[i]=='^')
    p = NULL;
    else
    {
    p = (BiTree)malloc(sizeof(BiTNode));
    if(!p)
    exit(OVERFLOW);
    p->data = sa[i];
    p->lchild = p->rchild = NULL;
    }
    }
    if(i==1)
    *T = p;
    else
    {
    while(i/2!=k)
    k++;

    if(i==2*k)
    node[k] ->lchild = p;
    if(i==2*k+1)
    node[k] ->rchild = p;
    }
    node[i]  = p;
}
return OK;



//������ ���������Ķ�������Ѱ��p�ĺ��  ˼·�����p�к�������ֱ�ӷ��ء�û������˵���������Һ��ӡ�����������Һ��ӡ�
//������������ֱ�ӷ���������û������˵������������Һ��ӡ��к���û�ã������Ѿ��������ˡ�������ڵ����Һ��ӣ����ظ��ڵ㡣��������ӵ������ֵܣ����ظ��ڵ㡣��������ֵܣ�ָ���ƶ������ֵ����ϣ���ѭ�����У������ȵ�������ġ�ѭ����ָ�������Ȼ����̽��û���ң�û�о������ˣ��еĻ��ƶ����ң�ѭ������ѭ����������һ��ָ�������������Ҿ��ƶ����ң�û���Ҿ������ˣ�

#include <stdio.h>
#include ""

ThrBiTree Algo_6_56(ThrBiTree p);
ThrBiTree Algo_6_57(ThrBiTree p);

int main(int argc,char *argv[])
{
    int mark;
    ThrBiTree Thrt,T;
    ThrBiTree p;
    FILE *fp;

    p = T->lchild;

    if(mark==1)
    {
    p = Algo_6_56(p);
    }
    if(mark==2)
    {
    p = Algo_6_57(p);
    }
    return 0;
}



ThrBiTree Algo_6_56(ThrBiTree p)
{
    if(p->RTag==Thread)
    p= p->rchild;
    else
    {
    if(p->lchild)
    p = p->lchild;
    else
    p = p->rchild;
    }
    if(p->data)
    return p;
    else
    return NULL;
}

ThrBiTree Algo_6_57(ThrBiTree p)
{
    if(p->parent  ==NULL)
    return NULL;
    else
    {
    if(P->RTag == Thread)
    return p->rchild;
    else
    {
    if(p= p->parent->rchild)
    return p->parent;
    else
    {
    if(p->parent->RTag!=Link)
    p = p->parent;
    else
    {
    p=p->parent->rchild;
    while(1)
    {
    while(p->lchild)
     p = p->lchild;

     if(p->rchild&& p->RTag!=Thread)
     p = p->rchild;
     else
     break;
    }
    }
    return p;
    }
    }
    }
}


