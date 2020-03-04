//2.33 ��һ�����������к��е������ַ�������Ԫ�أ���char digth   others�����֣�������ָ������ѭ������ÿ������ֻ��һ��Ԫ��
//˼·����ÿ��Ԫ�ز���ȡ������һ��temp�У�Ȼ����if��isalpha��  else if ��isdight�� else ����ʾ�������
//ʱ�䣺21��39 ����ʱ�䣺22:58

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//�������Ͷ���

typedef char LElemType_L;               //���Ҫ�ж���ʲô���͵��ַ��������������Ͳ���int��
typedef struct LNode
{
    LElemType_L data;
    struct LNode* next;
}LNode;
typedef LNode* LinkList;

Status Algo_2_33(LinkList L,LinkList L_char,LinkList L_num,LinkList L_other);       //���ܺ��������ڰ�L �ָ�Ϊchar  num   other�����ֱ�
Status InitList_2_33(LinkList *L);         //��ʼ��������
Status CreatList_2_33(LinkList L,int n,LElemType_L Data[]);     //create������
Status InitList_CL_2_33(LinkList *L);//��ʼ������ѭ������
void Output_2_33(LinkList L);//��ӡ�������±��Ǵ�ӡѭ������
void Output_CL_2_33(LinkList L);


int main(int argc,char *argv[])
{
    LinkList L,L_char,L_num,L_other;
    LElemType_L *a = "2poks++++2";

    InitList_2_33(&L);
    CreatList_2_33(L,10,a);

    printf("L = ");
    Output_2_33(L);
    printf("\n\n");

    printf("��ֵ�����֮��...\n");
    InitList_CL_2_33(&L_char);
    InitList_CL_2_33(&L_num);
    InitList_CL_2_33(&L_other);
    Algo_2_33(L,L_char,L_num,L_other);

    printf("L_char = ");
    Output_CL_2_33(L_char);
    printf("\n\n");
    printf("L_num = ");
    Output_CL_2_33(L_num);
    printf("\n\n");
    printf("L_other = ");
    Output_CL_2_33(L_other);
    printf("\n\n");

    return 0;
}

Status Algo_2_33(LinkList L,LinkList L_char,LinkList L_num,LinkList L_other)
{
        LinkList r,rc,rn,ro,s;

        if(!L)
            return ERROR;

        r = L->next;            //rָ�������У���������rָ��ֶ��У�s����temp����ʱ��ת
        rc = L_char;
        rn = L_num;
        ro = L_other;

        while(r!=NULL)
        {
            s = (LinkList)malloc(sizeof(LNode));

            if(!s)
                exit(OVERFLOW);
            s->data = r->data;

            if(isalpha(r->data))            //���r��ָ��data�Ǹ��ַ��͵ģ��������²�������ε��������ṹҲ���ж��Ƿ����ַ������Ƿ��������࣬������ʽͬ��
            {
                s->next = rc->next;         //�ѹ���ָ��s��ָ�Ķ������뵽����ָ��rn��ָ��Ԫ�ص����ı�׼����
                rc->next = s;                  //1�����Ѵ�����Ԫ������ָ��ָ�����Ԫ�ص����2�����Ѷ���Ԫ�ص�nextָ���ԭ���Ԫ�ػ�Ϊָ���µĲ�ӽ�����Ԫ�أ�3Ų���ѹ���ָ��rnŲ�����µĶ���βȥ��Ҳ�����²���Ԫ�ص�ͷ�ϣ����ڲ���1��
                rc  = rc->next;
            }
            else if(isdigit(r->data))
            {
                s->next = rn->next;
                rn->next = s;
                rn = rn->next;
            }
            else
            {
                s->next = ro->next;
                ro->next = s;
                ro = ro->next;

            }

            r = r->next;    // r�����һ��Ԫ����������������ֹҰָ�벽��1����ΪNULL
            }
            return OK;
}

Status InitList_2_33(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L))
        exit(OVERFLOW);

    (*L)->next =NULL;

    return OK;

}


Status CreatList_2_33(LinkList L,int n,LElemType_L Data[])
{
    LinkList s,r;
    int i;

    if(!L || L->next )
        return ERROR;

    for(i=1,r=L;i<=n;i++)           //��ʼ����ʱ����������1��rָ��ָ���ͷ
    {
        s = (LinkList)malloc(sizeof(LNode));
        if(!s)
            exit(OVERFLOW);
        s->data = Data[i-1];        //s���temp��Data������ȡֵ

        s->next = r->next;      //��r��߲���s
        r->next = s;
        r =r->next;
    }
    return OK;
}


void Output_2_33(LinkList L)
{
    LinkList p;

    if(L)
    {
        p = L->next;
        while(p)
        {
            printf("%2c ",p->data);
            p = p->next;
        }
    }
}

Status InitList_CL_2_33(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L))
        exit(OVERFLOW);

    (*L)->next = *L;                //������Ұָ�룬ѭ�������ͷ����nextҪָ���Լ�

    return OK;
}

void Output_CL_2_33(LinkList L)
{
    LinkList p;
    if(L)
    {
    p = L->next;
    while(p!=L)
    {
    printf("%2c ",p->data);
    p = p->next;
    }
    }
}
