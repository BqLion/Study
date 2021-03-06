//06树和二叉树/02BinaryTree

#ifndef  BINARYTREE_C
#define BINARYTREE_C

#include"BinaryTree.h"

void InitBiTree(BiTree *T)
{
    *T = NULL;
}

void ClearBiTree(BiTree *T)
{
    if(*T)
    {
    if((*T)->lchild)
        ClearBiTree(&((*T)->lchild));
    if((*T)->rchild)
        ClearBiTree(&((*T)->rchild));
    free(*T);

    *T = NULL;
    }
}

void DestroyBiTree(BiTree *T)
{
//二叉树无法销毁
}

Status BiTreeEmpty(BiTree T)
{
    return T==NULL?TRUE:ERROR;
}

Status CreateBiTree(FILE *fp,BiTree *T)
{
    char ch;

    Scanf(fp,"%c",&ch);

    if(ch == '^')
        *T =  NULL;
    else
        {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(!(*T))
            exit (OVERFLOW);
            (*T)->data = ch;
        CreateBiTree(fp,&(*T)->lchild);
        CreateBiTree(fp,&(*T)->rchild);
        }

    return OK;
}

int BiTreeLength(BiTree T)
{
    Node node[100];
    int i,len;

    i = len = 0;

    if(T)
    {
        node[i].left = T->lchild;
        node[i].right = T->rchild;
        node[i].n = 1;
        if(node[i].n>len)
            len = node[i].n;

        while(i>=0)
        {
        while(node[i].left)
        {
            node[i+1].left = node[i].left->lchild;
            node[i+1].right = node[i].left->rchild;
            node[i+1].n = 2*node[i].n;
            node[i].left = NULL;
            i++;
            if(node[i].n>len)
                len = node[i].n;
        }

        if(node[i].right)
        {
        node[i+1].left = node[i].right->lchild;
        node[i+1].right = node[i].right->rchild;
        node[i+1].n = 2*node[i].n +1;
        node[i].right = NULL;
        i++;
        if(node[i].n>len)
            len = node[i].n;
        }
        if(node[i].left == NULL && node[i].right==NULL)
            i--;
        }
    }
    return len;
}


int BiTreeDepth(BiTree T)
{
    int LD,RD;

    if(T==NULL)
        return 0;

    else
    {
    LD = BiTreeDepth(T->lchild);
    RD = BiTreeDepth(T->rchild);            //递归到底然后返回深度

    return (LD>=RD?LD:RD)+1;
    }
}

Status Root(BiTree T,TElemType *e)
{
    if(!T)
        return ERROR;
    else
    {
    *e = T->data;
    return OK;
    }
}

TElemType Value(BiTree p)
{
    return p->data;
}

void Assign(BiTree p,TElemType value)
{
    p->data = value;
}

TElemType Parent(BiTree T,TElemType e)
{
    BiTNode node[100];
    int i = 0;

    if(T==NULL || (T!=NULL && e==T->data))
        return '\0';

    node[i] = *T;

    while(i>=0)
    {
        while (node[i].lchild)
        {
        if(node[i].lchild->data==e)
            return node[i].data;
        node[i+1] = *(node[i].lchild);
        node[i].lchild = NULL;
        i++;
        }                               //当左孩子不为零的时候一直往左走，遇见零停下，经过的位置都置零

    if(node[i].rchild)
    {
        if(node[i].rchild->data==e)
            return node[i].data;
        node[i+1]=*(node[i].rchild);
        node[i].rchild = NULL;
        i++;                        //当左孩子为零，右孩子不为零的时候往右走一步
    }
    if(node[i].lchild==NULL && node[i].rchild==NULL)
        i--;                //左右都为零，退一步
    }
    if(i<0)
        return '\0';


}

TElemType LeftChild(BiTree T,TElemType e)
{
    BiTNode node[100];
    int i = 0;

    if(!T)
        return '\0';

    node[i] = *T;

    while(i>=0)
    {
        while(node[i].data!=e && node[i].lchild)
        {
        node[i+1] =*(node[i].lchild);
        node[i].lchild = NULL;
        i++;
        }                       //找左孩子：先找原结点。源节点不对就一直向左下降，直到找到源节点或者左边为空
    if(node[i].data==e)                 //如果找到源节点了就直接返回
    {
    if(node[i].lchild)
        return node[i].lchild->data;
    else
        return '\0';
        }

        if(node[i].rchild)          //如果不是找到源节点了而是左边空了，就向右挪一步
        {
        node[i+1] = *(node[i].rchild);
        node[i].rchild = NULL;
        i++;
        }

        if(node[i].lchild ==NULL && node[i].rchild==NULL && node[i].data!=e)
            i--;                            //如果两边都是空，往回退一步
    }
    if(i<0)
        return '\0';

}

TElemType RightChild(BiTree T,TElemType e)
{
    BiTNode node[100];
    int i = 0;

    if(!T)
        return '\0';

    node[i] = *T;

    while(i>=0)
    {
        while(node[i].data!=e && node[i].lchild)
        {
            node[i+1] = *(node[i].lchild);
            node[i].lchild = NULL;
            i++;
        }

    if(node[i].data==e)
    {
    if(node[i].rchild)
        return node[i].rchild->data;
    else
        return '\0';
    }

    if(node[i].rchild)
    {
    node[i+1]= *(node[i].rchild);
    node[i].rchild = NULL;
    i++;
    }
    if(node[i].lchild)
    {
    node[i+1] =*(node[i].rchild);
    node[i].rchild = NULL;
    i++;
    }
    if(node[i].lchild==NULL && node[i].rchild==NULL)
        i--;
    }
    if(i<0)
    return '\0';

}

TElemType  LeftSibling(BiTree T,TElemType e)
{
    BiTNode node[100];
    int i = 0;

    if(T==NULL || (T!=NULL && e==T->data))
        return '\0';

    node[i] = *T;

    while(i>0)
    {
    while(node[i].rchild)
    {
    if(node[i].rchild->data==e)
    {
    if(node[i].lchild)
        return node[i].lchild->data;
    else
        return '\0';
    }

    node[i+1] = *(node[i].rchild);
    node[i].rchild = NULL;
    i++;
    }

    if(node[i].lchild)
    {
    if(node[i].lchild->data==e)
        return '\0';
    node[i+1] = *(node[i].lchild);
    node[i].lchild = NULL;
    i++;
    }
    if(node[i].lchild==NULL && node[i].rchild==NULL)
        i--;
    }
    if(i<0)
    return '\0';
}


TElemType RightSibling(BiTree T,TElemType e)
{
    BiTNode node[100];
    int i = 0;

    if(T==NULL || (T!=NULL && e==T->data))
        return '\0';

    node[i] = *T;

    while(i>=0)
          {
          while(node[i].lchild)
            {
            if(node[i].lchild->data==e)
            {
            if(node[i].rchild)
                return node[i].rchild->data;
            else
                return '\0';
            }
            node[i+1]= *(node[i].lchild);
            node[i].lchild = NULL;
            i++;
            }

          if(node[i].rchild)
          {
          if(node[i].rchild->data==e)
            return '\0';
          node[i+1]= *(node[i].rchild);
          node[i].rchild = NULL;
          i++;
          }

          if(node[i].lchild == NULL && node[i].rchild==NULL)
            i--;
          }
    if(i<0)
        return '\0';
}


BiTree LocationBiTree_1(BiTree T,TElemType e)
{
    BiTNode node[100];
    int i = 0;

    if(T==NULL)
        return NULL;

    if(T->data==e)
    return T;

    node[i] = *T;

    while(i>=0)
    {
    while(node[i].lchild)
    {
    if(node[i].lchild->data==e)
        return node[i].lchild;
    node[i+1] = *(node[i].lchild);
    node[i].lchild = NULL;
    i++;
    }
    if(node[i].rchild)
    {
    if(node[i].rchild->data==e)
        return node[i].rchild;
    node[i+1] = *(node[i].rchild);
    node[i].rchild = NULL;
    i++;
    }
    if(node[i].lchild==NULL && node[i].rchild==NULL)
        i--;
    }
    if(i<0)
    return NULL;

}

BiTree LocationBiTree_2(BiTree T,TElemType e)
{
    BiTree p = NULL;

    if(T)
    {
    if(T->data ==e)
        p=T;
    else
    {
    if(p=LocationBiTree_2(T->lchild,e))
        return p;
    if(p=LocationBiTree_2(T->rchild,e))
        return p;
    }
    }
    return p;               //递归查找
}


Status InsertBiTree(BiTree T,TElemType e,BiTree T0,int LR)
{
    BiTree p = LocationBiTree_1(T,e);

    if(p)
    {
        T0->rchild = LR?p->rchild:p->lchild;
        LR?(p->rchild=T0):(p->lchild=T0);

        return OK;


    }
return ERROR;

}

Status DeleteBiTree(BiTree T,TElemType e,int LR)
{
    BiTree p = LocationBiTree_2(T,e);

    if(p)
    {
    LR?ClearBiTree(&(p->rchild)):ClearBiTree(&(p->lchild));

    return OK;
    }

    return ERROR;

}

void LevelOrderTraverse(BiTree T,void(Visit)(TElemType))
{
    int i,j;
    BiTree p[100];

    i=j=0;

    if(T)
        p[j++] = T;

    while(i<j)
    {
    Visit(p[i]->data);
    if(p[i]->lchild)
        p[j++] = p[i]->lchild;
    if(p[i]->rchild)
        p[j++]  = p[i]->rchild;
    i++;
    }
}

void PreOrderTraverse_1(BiTree T,void(Visit)(TElemType))
{
    if(T)
    {
    Visit(T->data);
    PreOrderTraverse_1(T->lchild,Visit);
    PreOrderTraverse_1(T->rchild,Visit);
    }
}

void PreOrderTraverse_2(BiTree T,Status(Visit)(TElemType))
{
    if(T)
    {
    if(Visit(T->data));
    {
    PreOrderTraverse_1(T->lchild,Visit);
    PreOrderTraverse_1(T->rchild,Visit);
    }
    return OK;
    }
    else
        return ERROR;
}

void InOrderTraverse_1(BiTree T,void(Visit)(TElemType))
{
    if(T)
    {
    InOrderTraverse_1(T->lchild,Visit);
    Visit(T->data);
    InOrderTraverse_1(T->rchild,Visit);
    }
}


void PostOrderTraverse(BiTree T,void(Visit)(TElemType))
{
    if(T)
    {
    PostOrderTraverse(T->lchild,Visit);
    PostOrderTraverse(T->rchild,Visit);
    Visit(T->data);
    }
}

void PrintTree(BiTree T)
{
    int row,col;
    int i,j,m,l,r;
    BiTNode a[100][100] = {};

    if(T)
    {
    row = BiTreeDepth( T);          //总行数
    col = pow(2,row)-1;                //总列数

    for(i=1;i<=row-1;i++)
    {
    for(j=1;j<=pow(2,i-1);j++)
    {
        m = (2*j-1)*pow(2,row-i);
        l = (4*j-3)*pow(2,row-i-1);
        r = (4*j-1)*pow(2,row-i-1);

        if(i==1)
            a[i][m] = *T;

        if(a[i][m].lchild)
            a[i+1][l] = *(a[i][m].lchild);
        if(a[i][m].rchild)
            a[i+1][r] = *(a[i][m].rchild);

    }

    }

    for(i=1;i<=row;i++)
    {
    for(j=1;j<=col;j++)
    {
    if(a[i][j].data)
        printf("%c",a[i][j].data);
    else
        printf(" ");
    }
    printf("\n");
    }

    }


}

#endif // BINARYTREE_C



