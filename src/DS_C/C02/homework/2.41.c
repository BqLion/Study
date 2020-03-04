//2.41.2.42��ѭ��������Ϊ����ʽ�Ĵ���ṹ������������ż����ֽ�Ϊ��������ʽ
//˼·������������͸������ݽṹ�������󵼵ȹ��ܾ�����ѧ��������ʽ��easy����

#include<stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

typedef struct
{
    int coef;
    int exp;
}PolyTerm;                      //

typedef struct PolyNode
{
    PolyTerm data;
    struct PolyNode *next;
}PolyNode;

typedef PolyNode *PolyLink;
typedef PolyLink LinkedPoly;

Status Algo_2_41(LinkedPoly P);
Status Algo_2_42(LinkedPoly *P,LinkedPoly *P_Odd,LinkedPoly *P_Even);
Status CreatPoly_L(LinkedPoly *P,int n,PolyTerm Data[]);
Status OutputPoly_L(LinkedPoly P);

int main(int argc,char *argv[])
{
    LinkedPoly P1,P2;               //ָ������ڵ��ε�ָ�룬�������Ϊһ����ı�ͷ��Ҳ����һ��������
    PolyTerm a[7] = {-2,1,4,2,2,3,11,5,-7,6,8,9,-3,10};

    CreatPoly_L(&P1,7,a);
    CreatPoly_L(&P2,7,a);
    printf("Pn(x) = ");
    printf("%d ",P1->next->next->data.coef);
    OutputPoly_L(P1);
    printf("\n\n");

    printf("��2.41����...\n");
    {
        Algo_2_41(P1);
        printf("�����ʽ�ĵ�����֮��...\n");
        printf("Pn(x) = ");
        OutputPoly_L(P1);
        printf("\n\n");
    }

    printf("��2.42����...\n");
    {
    LinkedPoly P_odd,P_even;
    Algo_2_42(&P2,&P_odd,&P_even);
    printf("����ָ����ż�Բ�ֶ���ʽ֮��...\n");
    printf("����� P_odd = ");
    OutputPoly_L(P_odd);
    printf("\n");
    printf("ż���� P_EVEN = ");
    OutputPoly_L(P_even);
    printf("\n\n");
    }
}


//����
Status Algo_2_41(LinkedPoly P)
{
    LinkedPoly r,pre;

    if(!P)
        return ERROR;

    pre = P;
    r = P->next;                //��������ָ���λ���ֱ�ָ���ͷ����Ԫ��
    while(r!=P)
    {
        if(r->data.exp)                     //�������ʽ����Ĵ�����Ϊ�㣬�����󵼲������������Ϊ�㣬���ǳ������ɾȥ�ڵ㣬free��
        {
        r->data.coef *= r->data.exp;
        r->data.exp--;
        pre = r;
        }
        else
        {
        pre->next = r->next;
        free(r);
        }
        r = pre->next;                        //r���������һ��ѭ������
    }
    return OK;
}

//��2.42��ָ����ż�Բ�ֶ���ʽ
Status Algo_2_42(LinkedPoly *P,LinkedPoly *P_Odd,LinkedPoly *P_Even)
{
    LinkedPoly r,s,p,q;

    *P_Odd = (LinkedPoly)malloc(sizeof(PolyNode));          //��odd even���ͷָ����䴢��ռ�
    *P_Even = (LinkedPoly)malloc(sizeof(PolyNode));           //˼·����if(s->data.exp%2)��s��ָ��Ԫ�ص�ָ����2�����Ƿ�Ϊ0���ж���ż�ԣ������Ƶ���ǰ��

    if(!(*P_Odd) || !(*P_Even))
        exit(OVERFLOW);
    (*P_Odd)->next = *P_Odd;
    (*P_Even)->next = *P_Even;          //��ʼ����nextָ��������ָ���Լ�

    if(!(*P))
        return ERROR;

    p = *P_Odd;         //ָ��ָ���ָ�����ֵ��������ָ��ָ�룬�ø�����ָ��ָ���ͷ
    q = *P_Even;
    r = (*P)->next;

    while(r!=(*P))
    {
    s = r;
    r =r->next;

    if(s->data.exp%2)           //s��ָԪ�ص�ָ�� �Զ����࣬������0������������˵��������
    {
        s->next  = p->next;
        p->next = s;
        p= p->next;
    }
    else
    {
        s->next = q->next;
        q->next = s;
        q = q->next;
    }
    }
    free(*P);
    *P = NULL;
}

Status CreatPoly_L(LinkedPoly *P,int n,PolyTerm Data[])           //��ʼ��һ��P����ַ��*P,������n��dataֵ��data
{
    int i;
    LinkedPoly s,r;

    *P = (LinkedPoly)malloc(sizeof(PolyNode));
    if(!(*P))
        exit(OVERFLOW);
    (*P)->next = *P;

    for(i=0,r=*P;i<n;i++)
    {
    s = (LinkedPoly)malloc(sizeof(PolyNode));
    if(!s)
        exit(OVERFLOW);
    s->data = Data[i];

    s->next = r->next;
    r->next = s;
    r = r->next;
    }
    return OK;
}

Status OutputPoly_L(LinkedPoly P)
{
    int i;
    LinkedPoly r;

    if(!P)
        return ERROR;

    for(r=P->next;r!=P;r=r->next)               //ֻҪr���ָ�뻹û����Ȧ��ɣ���������
    {
        if(r==P->next)                                  //����Ĵ�ӡ���裺�����жϣ���rָ���ڱ�ͷ���ǵ�һ�δ�ӡ����ֱ������ַ������ô�+-���ţ���ߵ�һ��Ҫ��+-��
            printf("%d ",r->data.coef);
        else
        {
            if(r->data.coef<0)                          //С����-��
            {
                printf(" - ");
                printf("%d",-r->data.coef);         //���磬��-7x^2��,������˹����ӡʱ�������ǡ�-���ţ�Ȼ���ǡ�7�����������-7��Ҫ�ѷ��ŷ�תһ��
            }
            else
            {
                printf(" + ");
                printf("%d",r->data.coef);
            }
        }
    if(r->data.exp)     //��������Ǵ��ڵģ�����Ҫ��ӡ��ߵ�x�������������1����Ҫ��ӡ^��������
    {
    printf("x");

    if(r->data.exp!=1)
        printf("^%d",r->data.exp);
    }

    }
    return OK;
}


