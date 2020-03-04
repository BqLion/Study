//ThreadBinaryTree.c

#ifndef THREADBINARYTREE_C
#define THREADBINARYTREE_C

#include"ThreadBinaryTree.h"

//二叉树的各元素相对位置确定，各元素的父子指针确定
//存储结构固定，只是遍历的顺序有差。
//左右孩子的指针是确定的，不定的是直接前驱后继指针
//不同的遍历方式有不同的直接前驱后继，在tag域中有不同显示

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

    CreateBiTree_Thr(fp,&(*T)->rchild);         //递归建立二叉树
    if((*T)->rchild)
        (*T)->RTag = Link;
    else
        (*T)->RTag = Thread;
    }

    return OK;
}


void InThreading_Thr(ThrBiTree p)  //中序全线索化                 //本函数用于其他高级算法的线索化工序：其他的函数确定了遍历的相对顺序后，才可以确定下来pre和p的相对顺序。
{
    if(p)
    {
    InThreading_Thr(p->lchild);          //线索化左子树

    if(!p->lchild)                                  //为当前节点左子树建立前驱线索
    {
        p->LTag = Thread;
        p->lchild = pre;
    }

    if(!pre->rchild)
    {
        pre->RTag = Thread;
        pre->rchild = p;
    }

    pre = p;//指针步进，然后线索化右子树（递归）

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
    ThrBiTree p = Thrt->lchild;          //p指向二叉树根节点,从根节点开始循环，直到再次遇见根节点为止，一直步进循环

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
        if(!pre->rchild)            //前一个节点的右子树为空
        {
        pre->RTag = Thread;         //这个节点的tag值置为1，即是线索
        pre->rchild = p;               //指向下一个节点，也就是p
        }

        pre = p;                    //p步进

        PreThreading_Thr(p->lchild );           //递归对左孩子做线索化

        if(p->rchild && p->RTag ==Link)     //如果p的右孩子不为零，且p的右标志是0，线索话右子树

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
        node[i]->lchild->parent = node[i];          //让node[j++] = node[i]的左孩子，然后让node[i]的这个左孩子的parent等于node[i]，等于建立了node[i]  node[j++]的关系
    }

    if(node[i]->rchild)
    {
    node[j++] = node[i]->rchild;
    node[i]->rchild->parent= node[i];
    }
    i++;
    }
}

ThrBiTree Pos_NextPtr_Thr(ThrBiTree Thrt,ThrBiTree p)           //寻找p的后继（需注意线索二叉树特殊性）
{
    if(p==Thrt->lchild)         //p是根节点，也就是最后一个节点
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
