#ifndef MFSET_C
#define MFSET_C

#include"MFSet.h"

void Initial_mfset(FILE *fp,MFSet *S)
{
    int i;
    Scanf(fp,"%d",&(S->n));

    for(i=1;i<=S->n;i++)
    {
    Scanf(fp,"%d",&i);
    S->nodes[i].data = i;
    S->nodes[i].parent  = -1;
    }//ԭ�ӻ������е�����ȡ��������data��parent��-1
}

int find_mfset(MFSet S,int i)           //�Ҹ��ڵ㣬���ǲ��ϵ��ҵ���ֱ����<0
{
    int j;

    if(i<1 || i>S.n)
    return -1;

    for(j=i;S.nodes[j].parent>0;j=S.nodes[j].parent);

    return j;
}


Status merge_mfset(MFSet *S,int i,int j)
{
    if(i<1 || j<1 || i>S->n || j>S->n)
    return ERROR;

    if(i!=j)
    S->nodes[i].parent = j;   //�ϲ����ǰ�һ�����ϵĸ��ڵ�ĵ�ָ��ָ����һ�����ڵ�

    return OK;
}

Status mix_mfset(MFSet *S,int i,int j)          //�鲢�Ĺ��̣���������ԭ�ӻ��Ľ��ĸ��ڵ�ָ�붼��-1��������Ϊ�����鲢����Ա�϶���Ǹ����ڵ�ģ���Ա�������ĸ�ֵ��
{
    if(i<1 || j<1 || i>S->n || j>S->n)
    return ERROR;

    if(S->nodes[i].parent > S->nodes[j].parent)
    {
    S->nodes[j].parent += S->nodes[i].parent;
    S->nodes[i].parent = j;
    }
    else
    {
    S->nodes[i].parent += S->nodes[j].parent;
    S->nodes[j].parent = i;
    }
    return OK;
}

int fix_mfset(MFSet *S,int i)           //�����򵥵ذ� һ�����ĸ��ڵ�ĸ�ָ��ָ����һ���ڵ������򵥺ϲ�
{                                                   //��Ѱ��ԭ���ĸ������ĵ�ʱ��ѭ��Ѱ�����˹���˳��ѹ��·��
    int j,k,t;

    if(i<1 || i>S->n)
    return -1;

    for(j=i;S->nodes[j].parent>0;j=S->nodes[j].parent);

    for(k=i;k!=j;k=t)
    {
    t = S->nodes[k].parent;         //tmpװ�ظ��ڵ��λ��
    S->nodes[k].parent = j;         //���ڵ�ָ��j������ڵ㣬�ϱߵ�tmp����Ϊ�����ڵ�
    }
    return j;
}

Status BuildRelation_mfset(FILE *fp,Relation *R)
{
    int k;

    Scanf(fp,"%d",&(R->n));

    if(R->n<0)
    return ERROR;

    for(k=1;k<=R->n;k++)
    Scanf(fp,"%d%d",&(R->nodes[k-1].i),&(R->nodes[k-1].j));

    return OK;
}

Status EquivalenceClass_mfset_1(MFSet *S,Relation R)    //���ڵȼ۹�ϵR�¼���S�ĵȼ���
{
    int k,x,y;

    for(k=0;k<R.n;k++)
    {
        x = find_mfset(*S,R.nodes[k].i);            //���Ҽ���S��i�����Ӽ��ĸ�
        y = find_mfset(*S,R.nodes[k].j);
        merge_mfset(S,x,y);
    }
    return OK;
}

Status EquivalenceClass_mfset_2(MFSet *S,Relation R)
{
    int k,x,y;

    for(k=0;k<R.n;k++)
    {
    x = fix_mfset(S,R.nodes[k].i);
    y = fix_mfset(S,R.nodes[k].j);
    mix_mfset(S,x,y);
    }
    return OK;
}

int SubsetCount_mfset(MFSet S)
{
    int i,count;

    for(i=1,count=0;i<=S.n;i++)
    {
    if(S.nodes[i].parent<0)
    count++;
    }
    return count;
}

void ShowSet_mfset(MFSet S)
{
    int i,j,k,count;
    int a[MAX_TREE_SIZE][MAX_TREE_SIZE] = {};
    int tmp[MAX_TREE_SIZE] = {};

    for(i=1;i<=S.n;i++)
    {
    j = find_mfset(S,i);
    if(j>0)
    {
        tmp[j]++;
        a[j][tmp[j]] = S.nodes[i].data;
    }
    }

    k = SubsetCount_mfset(S);

    printf("{");
    count = 0;

    for(i=1;i<=S.n;i++)
    {
    for(j=1;j<=S.n;j++)
    {

        if(a[i][j])
        {
        if(j==1)
        printf("{%d",a[i][j]);
        else
        printf(",%d",a[i][j]);

        if(j==tmp[i])
        {
        count++;
        printf("}");
        if(count!=k)
            printf(", ");
        }
        }
    }
    }
    printf("}\n");
}

#endif // MFSET_C





