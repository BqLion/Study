#ifndef CHILDSIBLINGTREE_C
#define CHILDSIBLINGTREE_C

#include"ChildSiblingTree.h"

void InitTree_CS(CSTree *T)
{
    *T = NULL;
}

void ClearTree_CS(CSTree *T)
{
    if(*T)
    {
    if((*T)->firstchild)
    ClearTree_CS(&(*T)->firstchild);
    if((*T)->nextsibling)
    ClearTree_CS(&(*T)->nextsibling);
    free(*T);

    *T = NULL;      //�ݹ��ɾ��������֧�Ľ��
    }
}

void DestroyTree_CS(CSTree *T)
{

}

Status TreeEmpty_CS(CSTree T)
{
    return  T==NULL?TRUE:ERROR;
}

Status  CreateTree_CS(FILE *fp,CSTree *T)
{
    char ch;

    Scanf(fp,"%c",&ch);

    if(ch == '^')
        *T = NULL;
    else
    {
    *T = (CSTree)malloc(sizeof(CSNode));
    if(!(*T))
        exit(OVERFLOW);
    (*T)->data = ch;
    CreateTree_CS(fp,&(*T)->firstchild);
    CreateTree_CS(fp,&(*T)->nextsibling);
    }
    return OK;
}

int TreeDegree_CS(CSTree T)
{
    int i,j,max,tmp;
    CSTree Q[100];

    i = j = 0;
    max = -1;

    if(T)
    {
    max = 0;
    Q[j++] = T->firstchild;

    while(i<j)
    {
    tmp = 0;

    while(Q[i])             //tmp�Ǳ��ڵ�Ķȣ�Ҳ���Ǳ��ڵ�˫�׽ڵ��м�������
    {
    tmp ++;
    if(Q[i]->firstchild)
        Q[j++] = Q[i]->firstchild;      //Q[j++]�Ǳ��ڵ���ֵܣ����ν����У��ȴ��´α���������ʱ�����

    Q[i] = Q[i]->nextsibling;           //�ֵܲ�����tmp��������м����ֵ�
    }
    if(tmp>max)
        max = tmp;                          //�ѼƲ�����max��ȣ���ȭ����С����
    i++;
    }
    }

    return max;
}

int TreeDepth_CS(CSTree T)
{
    int row,max;
    SqStack S;
    CSTree tmp;

    row = 0;

    if(T)
    {
        InitStack_Sq(&S);
        Push_Sq(&S,T);
        row = max =1;

        while(!StackEmpty_Sq(S))
        {
            GetTop_Sq(S,&tmp);   //���ڵ��ջ����ȡջ�� Ԫ��

            while(tmp->firstchild)
            {
                Push_Sq(&S,tmp->firstchild);
                max++;
                if(row<max)
                    row = max;
                GetTop_Sq(S,&tmp);
            }       //���ѭ���ü�������ָ�������Ǳ����

            Pop_Sq(&S,&tmp);        //���Ԫ���׳�������

            if(tmp->nextsibling)
                Push_Sq(&S,tmp->nextsibling);       //���׺󣬼���ܷ�����ƶ������ܣ������ƶ������ص�һ��������Ǳ
            else
            {
                    while(!StackEmpty_Sq(S))
                    {
                    Pop_Sq(&S,&tmp);                    //���ܺ����ƶ��Ļ�����һ�����ټ���ܷ�����ƶ����ܾ��ƶ������ܾ����ˣ�������--
                    max--;

                    if(tmp->nextsibling)
                    {
                    Push_Sq(&S,tmp->nextsibling);//�����˲㣺ֱ���п��Ժ����ƶ��ĵط�Ϊֹ������ѭ����
                    break;
                    }
                    }
            }
        }
    }                                                                       //���������Թ�������Ѱ�������ȣ���Ҫ�л��ˡ�������Ѱ·���㷨����ջ���ֿ��Ե���洢�����ݽṹ�������ڽ�Լ˼ά����
        return row;
}


TElemType_CS Root_CS(CSTree T)
{
    if(T)
        return T->data;
    else
        return '\0';
}


TElemType_CS Value_CS(CSTree T,int i)
{
    int m,n,count;
    CSTree Q[100];

    if(T && i>0)
    {
    m = n = 0;
    count = 0;
    Q[n++]  = T;            //����ָ��n����һ��

    while(m<n)
    {
    while(Q[m])
    {
        count++;            //����������n�˾ͷ���data
        if(count==i)
            return Q[m]->data;

        if(Q[m]->firstchild)                //���mָ��ָ��Ԫ����child������һ����nָ��Ͱ�firstchild��ӣ�������һ��������˾ʹ���һ���firstchild�ǿ�ʼ����
            Q[n++] = Q[m]->firstchild;

        Q[m] = Q[m]->nextsibling;   //Q[m]��ʼ������һ������ֱ��׷������һ����nָ��
    }
    m++;
    }
    }
    return '\0';
}

CSTree Order_CS(CSTree T,TElemType_CS e)
{
    int i,j,count;
    CSTree Q[100];

    i = j = 0;

    if(T)
    {
        Q[j++] = T;
        while(i<j)
        {
        while(Q[i]&& Q[i]->data !=e)
        {
        if(Q[i]->firstchild)
            Q[j++] = Q[i]->firstchild;

        Q[i] = Q[i]->nextsibling;
        }
        if(Q[i]&& Q[i]->data==e)
            return Q[i];

        i++;
        }
    }
    return NULL;
}

Status Assign_CS(CSTree T,TElemType_CS e,TElemType_CS value)
{
    int i,j,count;
    CSTree p;

    p = Order_CS(T,e);

    if(p)
    {
        p->data = value;
        return OK;
    }

    return ERROR;
}

TElemType_CS ChildValue_CS(CSTree T,TElemType_CS e,int order)
{
    int i,j,count;
    CSTree Q[100];

    count = -1;
    i = j = 0;

    if(T)
    {
    Q[j++]  = T;
    while(i<j)
    {
        while(Q[i] && Q[i]->data!=e)
        {
        if(Q[i]->firstchild)
            Q[j++] = Q[i]->firstchild;

        Q[i] = Q[i]->nextsibling;
        }
        if(Q[i] && Q[i]->data ==e)
            break;

        i++;
    }
    if(i<j)
    {
    count = 0;
    if(Q[i]->firstchild)
    {
    Q[i] =Q[i]->firstchild;
    while(Q[i])
    {
    count++;
    if(count==order)
        return Q[i]->data;
    Q[i] = Q[i]->nextsibling;
    }
    }
    }
    }
    return '\0';
}

TElemType_CS Sibling_CS(CSTree T,TElemType_CS e,int mark)
{
    int i,j,m,n;
    CSTree Q[100];
    TElemType_CS key[100] = {};

    i = j = 0;
    m = n = 0;

    if(T&&T->data!=e)
    {
    Q[j++] = T;
    key[n++] =  T->data;

    while(i<j)
    {
    while(Q[i])
    {
    if(Q[i]->firstchild)
    {
    Q[j++]  =Q[i]->firstchild;
    key[n++] = Q[i]->firstchild->data;
    }

    if(mark==0)
    {
    if(Q[i]->data ==e &&Q[i]->data==key[m])
        return '\0';

    if(Q[i]->nextsibling && Q[i]->nextsibling->data==e)
        return Q[i]->data;
    }
    else
    {
    if(Q[i]->data==e && Q[i]->nextsibling)
        return Q[i]->nextsibling->data;
    }
    Q[i] = Q[i]->nextsibling;
    }
    i++;
    m++;
    }
    }
    return '\0';
}

int ChildCount_CS(CSTree T,TElemType_CS p)
{
    int i,j,count;
    CSTree Q[100];

    count  = -1;
    i = j = 0;

    if(T)
    {
    Q[j++] = T;

    while(i<j)
    {
    while(Q[i] && Q[i]->data!=p)
    {
    if(Q[i]->firstchild)
        Q[j++] = Q[i]->firstchild;

    Q[i] = Q[i]->nextsibling;
    }
    if(Q[i]&& Q[i]->data ==p)
        break;

    i++;
    }
    if(i<j)
    {
    count = 0;
    if(Q[i]->firstchild)
    {
    Q[i] = Q[i]->firstchild;
    while(Q[i])
          {
            count++;
            Q[i] = Q[i]->nextsibling;
          }
    }
    }
    }
    return count;
}


CSTree ChildSeat_CS(CSTree T,TElemType_CS e,int i)
{
    TElemType_CS tmp;
    CSTree p;

    tmp = ChildValue_CS(T,e,i);

    if(tmp)
        p = Order_CS(T,tmp);
    return p;
}

Status InsertTree_CS(CSTree T,TElemType_CS e,int i ,CSTree t)
{
    int j,k0;
    CSTree p,q;

    k0 =  ChildCount_CS(T,e);

    if(k0<0 || i<0 || i>k0+1)
        return ERROR;

    if(i==0)
        j = k0+1;
    else
        j = i;

    if(j==1)            //����ǲ��ڵ�һλ�����⴦����ΪҪ����firstchild
    {
    p = Order_CS(T,e);
    t->nextsibling = p->firstchild;
    p->firstchild = t;
    }
    else                      //����ǲ����м䣬���Ծ���һ����ͨ�Ĳ�������Ĳ���
    {
    q = ChildSeat_CS(T,e,j-1);
    t->nextsibling = q->nextsibling;
    q->nextsibling = t;
    }
    return OK;
}


Status DeleteTree_CS(CSTree T,TElemType_CS e,int i)
{
    TElemType_CS tmp;
    CSTree p,q;

    if(i==1)
    {
    p =Order_CS(T,e);
    if(!p)
        return ERROR;

    q= p->firstchild->nextsibling;
    p->firstchild->nextsibling = NULL;
    ClearTree_CS(&(p->firstchild));
    p->firstchild =q;
    }
    else
    {
    p = ChildSeat_CS(T,e,i-1);
    if(!p)
        return ERROR;
    q = p->nextsibling->nextsibling = NULL;
    ClearTree_CS(&(p->nextsibling));
    p->nextsibling= q;
    }

    return OK;
}

void LevelOrderTraverse_CS(CSTree T,void(Visit)(TElemType_CS))
{
    int i,j;
    CSTree Q[100];

    i = j = 0;

    if(T)
        Q[j++] = T;

    while(i<j)
    {
    while(Q[i])
    {
        Visit(Q[i]->data);

        if(Q[i]->firstchild)
            Q[j++] = Q[i]->firstchild;
                                                                //������һɨ�裬�����к��ӵģ��ѵ�һ������������ӵ���ߴ���ȡ
        Q[i] = Q[i]->nextsibling;
    }
    i++;
    }
}


void PreOrderTraverse_CS(CSTree T,void(Visit)(TElemType_CS))
{
    if(T)
    {
    Visit(T->data);
    PreOrderTraverse_CS(T->firstchild,Visit);               //�ݹ�ط��ʣ�������������ȷ��ʽڵ㣬Ȼ���Ǻ��ӣ�Ȼ�����ֵܡ���ͨ�Ķ��������ǣ�1.�ڵ�  2.����  3.�Һ���
    PreOrderTraverse_CS(T->nextsibling,Visit);
    }
}

void InOrderTraverse_CS(CSTree T,void(Visit)(TElemType_CS))
{
    if(T)
    {
    InOrderTraverse_CS(T->firstchild,Visit);
    Visit(T->data);
    InOrderTraverse_CS(T->nextsibling,Visit);
    }
}

void Print_CS(CSTree T)
{

    typedef struct
    {
    TElemType_CS e;
    int x;
    int y;
    }Node;

    SqStack S;
    SElemType_Sq tmp;
    Node node[100];
    int row,col,row_max,k,i,j;
    char a[100][100] = {};
    int m,n;

    k = 0;

    if(T)
    {
        InitStack_Sq(&S);
        Push_Sq(&S,T);

        row = col = 0;
        row_max = 0;

        while(!StackEmpty_Sq(S))
        {
        GetTop_Sq(S,&tmp);

        node[k].e = tmp->data;
        node[k].x = col;
        node[k].y  = row;
        k++;

        while(tmp->firstchild)
        {
        Push_Sq(&S,tmp->firstchild);
        row++;
        if(row_max<row)
            row_max = row;
        GetTop_Sq(S,&tmp);

        node[k].e = tmp->data;
        node[k].x  = col;
        node[k].y = row;
        k++;
            }

        Pop_Sq(&S,&tmp);

        if(tmp->nextsibling)
        {
        Push_Sq(&S,tmp->nextsibling);
        col++;
        }
        else
        {
        while(!StackEmpty_Sq(S))
        {
        Pop_Sq(&S,&tmp);
        row--;

        if(tmp->nextsibling)
        {
        Push_Sq(&S,tmp->nextsibling);
        col++;
        break;
        }
        }
        }
        }

        for(i=0;i<k;i++)
            a[node[i].x][3*node[i].y] = node[i].e;

        for(i=0;i<=col;i++)
        {
        for(j=0;j<3*row_max;j++)
        {
        if(a[i][j])
        printf("%c",a[i][j]);
        else
            printf(".");
        }
        printf("\n");
        }
    }
    else
        printf("�����޷���ӡ!!!\n");
}

#endif // CHILDSIBLINGTREE_C




