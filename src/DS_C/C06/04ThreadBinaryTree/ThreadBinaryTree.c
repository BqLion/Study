//ThreadBinaryTree.c

#ifndef THREADBINARYTREE_C
#define THREADBINARYTREE_C

#include"ThreadBinaryTree.h"

//�������ĸ�Ԫ�����λ��ȷ������Ԫ�صĸ���ָ��ȷ��
//�洢�ṹ�̶���ֻ�Ǳ�����˳���в
//���Һ��ӵ�ָ����ȷ���ģ���������ֱ��ǰ�����ָ��
//��ͬ�ı�����ʽ�в�ͬ��ֱ��ǰ����̣���tag�����в�ͬ��ʾ

Status CreateBiTree_Thr(FILE *fp,ThrBiTree *T)
{

    TElemType_Thr ch;

    Scanf(fp,"%c",&ch);

    if(ch=='^')
        *T= NULL;

    else
    {
    *T = (ThrBiTree)malloc(sizeof(ThrBiNode));
    if(!*T)
        exit(OVERFLOW);
    (*T)->data = ch;

    CreateBiTree_Thr(fp,&(*T)->lchild);
    if((*T)->lchild)
        (*T)->LTag = Link;
    else
        (*T)->LTag = Thread;

    CreateBiTree_Thr(fp,&(*T)->rchild);         //�ݹ齨��������
    if((*T)->rchild)
        (*T)->RTag = Link;
    else
        (*T)->RTag = Thread;
    }

    return OK;
}


void InThreading_Thr(ThrBiTree p)  //����ȫ������                 //���������������߼��㷨�����������������ĺ���ȷ���˱��������˳��󣬲ſ���ȷ������pre��p�����˳��
{
    if(p)
    {
    InThreading_Thr(p->lchild);          //������������

    if(!p->lchild)                                  //Ϊ��ǰ�ڵ�����������ǰ������
    {
        p->LTag = Thread;
        p->lchild = pre;
    }

    if(!pre->rchild)
    {
        pre->RTag = Thread;
        pre->rchild = p;
    }

    pre = p;//ָ�벽����Ȼ�����������������ݹ飩

    InThreading_Thr(p->rchild);
    }
}



Status InOrderThreading_Thr(ThrBiTree *Thrt,ThrBiTree T)
{
        *Thrt=(ThrBiTree)malloc(sizeof(ThrBiNode));
        if(!*Thrt)
            exit(OVERFLOW);

        (*Thrt)->data = '\0';
        (*Thrt)->LTag = Link;
        (*Thrt)->RTag = Thread;
        (*Thrt)->rchild = *Thrt;

        if(!T)
            (*Thrt)->lchild = *Thrt;
        else
            {
            (*Thrt)->lchild = T;
        pre = *Thrt;

        InThreading_Thr(T);

        pre ->rchild = *Thrt;
        pre->RTag = Thread;
        (*Thrt)->rchild = pre;
            }

    return OK;
}

Status InOrderTraverse_Thr(ThrBiTree Thrt,void(Visit)(TElemType_Thr))
{
    ThrBiTree p = Thrt->lchild;          //pָ����������ڵ�,�Ӹ��ڵ㿪ʼѭ����ֱ���ٴ��������ڵ�Ϊֹ��һֱ����ѭ��

    while(p!=Thrt)
    {
    while(p->LTag==Link)
        p = p->lchild;

    Visit(p->data);

    while(p->RTag==Thread && p->rchild!=Thrt)
    {
        p = p->rchild;
        Visit(p->data);
    }

            p = p->rchild;
    }

        return OK;


}

void PreThreading_Thr(ThrBiTree p)
{
    if(p)
    {
        if(!pre->rchild)            //ǰһ���ڵ��������Ϊ��
        {
        pre->RTag = Thread;         //����ڵ��tagֵ��Ϊ1����������
        pre->rchild = p;               //ָ����һ���ڵ㣬Ҳ����p
        }

        pre = p;                    //p����

        PreThreading_Thr(p->lchild );           //�ݹ��������������

        if(p->rchild && p->RTag ==Link)     //���p���Һ��Ӳ�Ϊ�㣬��p���ұ�־��0��������������

            PreThreading_Thr(p->rchild);
    }
}


Status PreOrderThreading_Thr(ThrBiTree *Thrt,ThrBiTree T)
{
    *Thrt=(ThrBiTree)malloc(sizeof(ThrBiNode));
    if(!*Thrt)
        exit(OVERFLOW);

    (*Thrt)->data = '\0';
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = NULL;

    if(!T)
        (*Thrt)->lchild = (*Thrt)->rchild = *Thrt;
    else
    {
    (*Thrt)->lchild = T;
    pre = *Thrt;

    PreThreading_Thr(T);

    pre->RTag = Thread;
    pre ->rchild =*Thrt;
    }

    return OK;
}


Status PreOrderTraverse_Thr(ThrBiTree Thrt,void(Visit)(TElemType_Thr))
{
    ThrBiTree p = Thrt;

    while(p->rchild!=Thrt)
    {
        while(p->lchild)
        {
            p = p->lchild;
            Visit(p->data);
        }
    if(p->rchild!=Thrt)
    {
    p = p->rchild;
    Visit(p->data);
    }
    }
    return OK;
}

void PosTheading_Thr(ThrBiTree p)
{
    if(p)
    {
    if(!p->rchild)
    {
        p->RTag = Thread;
        p->rchild = pre;
    }
    pre = p;

    if(p->RTag!=Thread)
        PosTheading_Thr(p->rchild);

    PosTheading_Thr(p->lchild);
    }
}

Status PosOrderThreading_Thr(ThrBiTree *Thrt,ThrBiTree T)
{
    *Thrt=(ThrBiTree)malloc(sizeof(ThrBiNode));
    if(!*Thrt)
        exit(OVERFLOW);

    (*Thrt)->data = '\0';
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = *Thrt;

    if(!T)
        (*Thrt)->lchild = *Thrt;
    else
    {
    (*Thrt)->lchild = *Thrt;

    pre =*Thrt;

    PosTheading_Thr(T);

    (*Thrt)->rchild = T;
    }
    return OK;
}


Status PosOrderTraverse_Thr(ThrBiTree Thrt,void(Visit)(TElemType_Thr))
{
    ThrBiTree p = Thrt->lchild;

    if(p!=Thrt)
    {
    while(1)
    {
    while(p->lchild)
     p = p->lchild;

     if(p->rchild && p->RTag!=Thread)
        p = p->rchild;
     else
        break;
    }
    while(p)
    {
    Visit(p->data);
    p = Pos_NextPtr_Thr(Thrt,p);
    }

    }
    return OK;
}

void ParentPtr_Thr(ThrBiTree T)
{

    ThrBiTree node[100];
    int i,j;

    i = j = 0;

    if(T)
        node[j++] =T;
    node[i]->parent = NULL;

    while(i<j)
    {
    if(node[i]->lchild)
    {
        node[j++] = node[i]->lchild;
        node[i]->lchild->parent = node[i];          //��node[j++] = node[i]�����ӣ�Ȼ����node[i]��������ӵ�parent����node[i]�����ڽ�����node[i]  node[j++]�Ĺ�ϵ
    }

    if(node[i]->rchild)
    {
    node[j++] = node[i]->rchild;
    node[i]->rchild->parent= node[i];
    }
    i++;
    }
}

ThrBiTree Pos_NextPtr_Thr(ThrBiTree Thrt,ThrBiTree p)           //Ѱ��p�ĺ�̣���ע�����������������ԣ�
{
    if(p==Thrt->lchild)         //p�Ǹ��ڵ㣬Ҳ�������һ���ڵ�
        return NULL;


    else
    {
    if(p->RTag==Thread)
    return p->rchild;
    else
    {
        if(p==p->parent->rchild)
        return p->parent;
    else
    {
    if(p->parent->RTag!=Link)
    p = p->parent;
    else
    {
        p = p->parent->rchild;
    while(1)
    {
    while(p->lchild)
        p = p->lchild;

    if(p->rchild && p->RTag!=Thread)
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

#endif // THREADBINARYTREE_C
