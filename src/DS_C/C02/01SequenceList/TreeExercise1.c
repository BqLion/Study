#include <stdio.h>

#define MAX 100
Status Algo_6_33(int L[MAX+1],int R[MAX+1],int v,int u);

Status Algo_6_34(int T[MAX+1],int v,int u);

int main(int argc,char *argv[])
{
    int T[MAX+1] = {0,0,1,1,2,2,3,5,5,6};
    int L[MAX+1] = {0,2,4,6,0,7,0,0,0,0};
    int R[MAX+1]  = {0,3,5,0,0,8,9,0,0,0};
    int v,u;

    printf("作为示例，建立树： 序号1 2 3 4 5 6 7 8 9\n");
    printf("                              L[n] 2 4 6 0 7 0 0 0 0\n");
    printf("                              R[n] 3 5 0 0 8 9 0 0 0\n");
    printf("                              T[n] 0 1 1 2 2 3 5 5 6\n");
    printf("\n");

}

//following 2 alrogima are used to judge whether u is v1s grandson

Status Algo_6_34(int T[MAX+1],int v,int u)
{
    int(T[u]==v)
    return TRUE;
    else
    {
    if(T[u] && Algo_6_34(T,v,T[u]))
    return TURE;
    }
    return FALSE;
}

Status Algo_6——33(int L[MAX+1],int R[MAX+1],int v,int u)
{
    if(L[v]==u || R[v]==u)
    return TURE;

    else
    {
    if(L[v]&& Algo_6_33(L,R,L[v],u))
    return TRUE;
    if(R[v] && Algo_6_33(L,R,R[v],u))
    return TRUE;
    }
    return FLASE;
}

//6.36判断两颗二叉树是否相似？相似的判断条件就是两棵树都为空，或者两棵树在形态上完全一致（该空都空该有都有，指示数值不同），思路是递归依次左右往下走判断是否为空？

#include <stdio.h>
#include ""

Status Algo_6_36(BiTree B1,BiTree B2);

int main(inr argc,char *argv[])
{
    BiTree B1,B2,B3;
    FILE *fp;
    char tmp;

    InitBiTree(&B1);
    InitBiTree(&B2)；
    InitBiTree(*B3);

    printf("创建二叉树（先序序列）B1->ABD^^E^^C^^...\n");
    printf("                                   B2->ABD^^E^^C^^...\n");
    printf("                                   B3->ABD^^E^^C^^...\n");
    fp = fopen("Data");
    CreateBiTree(fp,&B1);
    Scanf(fp,"%c",&tmp);
    CreateBiTree(fp,&B2);
    Scanf(fp,"%c",&tmp);
    CreateBiTree(fp,&B3);
    fclose(fp);
    printf("\n");

    if(Alg_6_36(B1,B2))
        printf("b1与b2相似！\n");
        else
        printf("B1and b2 not similar");

        if(Algo_6_36(B2,B3))
        printf("B2与B3不相似！！\n");
        printf("\n");

        return 0;
}

Status Algo_6_36(BiTree B1,BiTree B2)
{
if(BiTreeEmpty(B1) && BiTreeEmpty(B2))
return TRUE;
else
{
if(!BiTreeEmpty(B1) && !BiTreeEmpty(B2))
{
if(Algo_6_36(B1->lchild,B2->lchild)&&Algo_6_36(B1->rchild,B2->rchild))
    return TRUE;
}
}

return FALSE;
}


