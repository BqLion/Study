//HuffmanTree.c

#ifndef HUFFMANTREE_C
#define HUFFMANTREE_C

#include "HuffmanTree.h"

void InitTree_HT(HuffmanTree *HT)
{
    *HT = NULL;
}

Status CreateHuffmanTree_HT(FILE *fp,HuffmanTree *HT)
{
    int m,n;
    int w[MAX_TREE_SIZE];
    HuffmanTree p;
    int i;
    int s1,s2;

    Scanf(fp,"%d",&n);
    printf("录入哈夫曼树叶子节点个数 -> %d\n",n);

    printf("依次录入个叶子节点的权值-> ");
    for(i=1;i<=n;i++)
    {
        Scanf(fp,"%d",&w[i]);
        printf("%d ",w[i]);
    }
    printf("\n");

    m = 2*n - 1;            //有效节点是m个

    *HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
    if(!(*HT))
    exit(OVERFLOW);

    (*HT)[0].weight = n; //整个树的存储结构：用0号单元的权值存储哈弗曼树叶子个数

    for(i=1;i<=m;i++)
    {
        if(i<=n)
        (*HT)[i].weight =w[i];
        else
        (*HT)[i].weight = 0;

        (*HT)[i].parent = 0;
        (*HT)[i].lchild = 0;
        (*HT)[i].rchild = 0;
    }

    for(i=n+1;i<=m;i++)             //双亲域：开始建立关系
    {
    Select_HT(*HT,i-1,&s1,&s2);             //找出权值最小的两个树

    (*HT)[s1].parent = (*HT)[s2].parent = i;        //儿子认爹，依次从双亲域的第一个开始

    (*HT)[i].lchild = s1;                                         //爹认儿子
    (*HT)[i].rchild = s2;
    (*HT)[i].weight = (*HT)[s1].weight +(*HT)[s2].weight;       //权值相加
    }
    return OK;
}

Status Select_HT(HuffmanTree HT,int end,int *order_1,int *order_2)
{
    HuffmanTree p;
    int i,count;
    int m,n,tmp;

    if(end<2)
        return ERROR;

    for(i=1,count=1;i<=end;i++)
    {
    if(HT[i].parent == 0)
    {
    if(count==1)
        m=i;
    if(count=2)
        n=i;
        count++;
    }
    if(count>2)
        break;
    }
    if(HT[m].weight>HT[n].weight)
    {
    tmp = n;
    n = m;
    m = tmp;
    }

    i = (m>n?m:n) + 1;
    while(i<=end)
    {
    if(HT[i].parent==0)
    {
    if(HT[i].weight<HT[m].weight)
    {
    n = m;
    m = i;
    }
    else
    {
    if(HT[i].weight>=HT[m].weight && HT[i].weight<HT[n].weight)
    n = i;
    }
    }
    i++;
    }
    *order_1 = HT[m].weight <=HT[n].weight?m:n;
    *order_2 = HT[m].weight>=HT[n].weight?m:n;

    return OK;
}

Status HuffmanCodeing_HT_1(HuffmanTree HT,HuffmanCode *HC)
{
    char *code;
    int n,i;
    int start,c,f;

    n = HT[0].weight;               //第一个节点的权值存的是总节点个数

    *HC = (HuffmanCode)malloc((n+1)*sizeof(HCnode));
    if(!(*HC))
        exit(OVERFLOW);

    code = (char*)malloc(n*sizeof(char));
    if(!code)
    exit(OVERFLOW);

    code[n-1] = '\0';
    for(i=1;i<=n;i++)
    {
    start = n-1;
    for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
    {
    if(HT[f].lchild==c)
        code[--start] = '0';
    lese
        code[--start] = '1';
    }

    (*HC)[i] = (char*)malloc((n-start)*sizeof(char));

    strcpy((*HC)[i],&code[start]);
    }
    free(code);
}

Status HuffmanCodeing_HT_2(HuffmanTree HT,Huffmancode *HC)
{
    int m,n,i;
    int cdlen;
    int p,mark[MAX_TREE_SIZE];
    char *code;

    n = HT[0].weight;
    m = 2*n-1;

    *HC = (HuffmanCode)malloc((n+1)*sizeof(HCNode));
    if(!(*HC))
        exit(OVERFLOW);

    code = (char*)malloc(n*sizeof(char));
    if(!code)
        exit(OVERFLOW);

    for(i=1;i<=n;i++)
        code[i] = '\0';

    for(i=1;i<=n;i++)
        mark[i]= 0;

    p = m;
    cdlen = 0;
    while(p)
    {
    if(mark[p]==0)
    {
    mark[p] = 1;
    if(HT[p].lchild!=0)
    {
        p = HT[p].lchild;
        code[cdlen] = '0';
        cdlen++;
    }
    else
    {
    if(HT[p].lchild==0)
    {
    (*HC)[p] = (char*)malloc((cdlen+!)*sizeof(char));
    strcpy((*HC)[p],code);
    }
    }
    }
    else
    {
    if(mark[p]==1)
    {
    mark[p]=2;
    if(HT[p].rchild!=0)
    {
    p = HT[p].rchild;
    code[cdlen] = '1';
    cdlen++;
    }
    }
    else
    {
    p = HT[p].parent;
    cdlen--;
    code[cdlen] = '\0';
    }
    }
    }
    free(code);
}

void ShowHuffmanTree_HT(HuffmanCode HT)
{
    int i;
    printf("|————|————|————|————|————|\n");
    printf("| *order  | weight | parent   | lchild   | rchild   |\n");
    for(i=0;i<=2*HT[0].weight-1;i++)
    {
    if(i==0)
        printf("|   %2d    |   %4d     |     --      |      --     |      --     |\n",i,HT[i].weight);
    else
        printf("|   %2d    |   %4d     |     %2d     |     %2d    |     %2d    |\n",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
    }
    printf("|————|————|————|————|————|\n");
}

void ShowHuffmanCode_HT(HuffmanCode HT,HuffmanCode HC)
{
    int i;

    printf("|————|————|————|——————|\n");
    printf("|  *order |  weight|              |  哈夫曼编码  |\n");
    for(i=1;i<=HT[0].weight;i++)
        printf("|    %2d   |  %4d    |------->%-14s |\n",i,HT[i].weight,HC[i]);
    printf("|————|————|————|——————|\n");
}
#endif // HUFFMANTREE_C

