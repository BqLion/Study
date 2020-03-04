//2.38 ˫��ѭ������plus :ÿ���ڵ����pre��data��next������֮�⣬������һ��freq��freq��ʼ��ֵ����0��ÿ������һ��freq��++,����㰴��freq�Ĵ�С�������С�
//����������ݽṹ���������LOCATA�㷨��
//˼·���������ݽṹ������ԭ˫����Ľ��Ļ����ϼ���һ��freq��locate�㷨������pre p��������ָ��ȥ����ֵ��ÿ�η���freq++��ÿ�η��ʺ��freq��ǰ��Ԫ�ص�freq���Ƚϣ������ǰ�õ�Ԫ�ش��������²�����
//��Ҫ����p��λ�á���pre������ָ�벽�ˣ���ͬʱ��p��ָԪ�����Ƚϣ���pre���ڱȴ�ͣ��������pŲ��pre�ĺ�����������Ǻ��ʵ�λ�á�����
//��10����5����5����5����5��->��10����5����5����5����6������ʱpre��飬�ҵ���һ��Ԫ���Ǳ�6��ģ�ͣ��10�ϣ���p��ָ��6���뵽10���
//ʱ�䡰22:27   ��ɣ�23:41

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//���ݽṹ����
typedef int LElemType_DC;
typedef struct DuLNode
{
    LElemType_DC data;
    struct DuLNode *prior;
    struct DuLNode *next;
    int freq;
}DuLNode;
typedef DuLNode *DuLinkList;            //����˫��������ݽṹ�Σ�����һ��int freq����

//����ԭ��
int Algo_2_38(DuLinkList L,LElemType_DC e);
Status CreatList_DuL_2_38(DuLinkList *L,int n,LElemType_DC Data[]);
Status Output_DuL_2_38(DuLinkList L);

int main (int argc,char *argv[])
{
    DuLinkList L,p;
    int i;
    LElemType_DC data[10] = {1,2,3,4,5,6,7,8,9,10};
    LElemType_DC tmp[10] = {1,2,2,2,3,4,4,5,5,9};

    CreatList_DuL_2_38(&L,10,data);
    printf("��ʼ��������LΪ :");
    Output_DuL_2_38(L);
    printf("\n\n");

    for(i=1;i<=10;i++)
        Algo_2_38(L,tmp[i-1]);
    printf("�����Ժ�L = ");
    Output_DuL_2_38(L);
    printf("\n\n");
    printf("��Ӧ���ʴ�����");
    for(p=L->next;p!=L;p = p->next)
        printf("%2d ",p->freq);
    printf("\n\n");

    return 0;
}

//���ĵĶ�λ�㷨��
int Algo_2_38(DuLinkList L,LElemType_DC e)
{
    DuLinkList p,pre;
    int i;

    if(!L ||L->next == L )      //����������Ϊ��Destroyed ����ֻ��ͷ���Deleted,����������ش���
    return 0;

    i = 1;
    pre = L;
    p = L->next;
    while(p!=L && p->data!=e)
    {
    i++;
    pre = p;
    p = p->next;
    }  //��λe����p��preŲ��ȥ

    if(p!=L)//û����һȦ�˿��ˣ��ҵ���Ԫ��
    {
    p->freq++;      //��locate�����Ԫ������1

    while(pre!=L && pre->freq<p->freq)  //��������൱��Ҫ������freq��һ�Ĳ���֮��Ҫ��鱾Ԫ�غ�ǰһ��Ԫ������Ƿ��ǰԪ�ش��������preҪ������ֱ������ͷ�����߱�p���Ԫ��Ϊֹ��Ȼ����һ���Ĳ������ǰ�p�ӳ���������pre�ĺ�ߣ�ʵ��������
    {
    i--;
    pre = pre->prior;
    }

    if(pre->next!=p)        //���һ�¸ղ���һ������û�����û����pre����һ��Ԫ�ؿ϶���p��������������ˣ������㣬ִ���ڳ�->��ӵĲ���
    {
        p->next->prior = p->prior;
        p->prior->next= p->next;            //ȡ��

        p->next = pre->next;
        p->prior = pre;
        pre->next->prior = p;
        pre->next =p;                               //�Ż�
    }

    return i;               //�������ı����Ƕ�λ�����Է���i���λ�򣬼�һ��freq���Դ������Ƕ���Ĺ��ܣ��൱�ڲ��Ҳ������ˣ�
    }

    return 0;           //��λʧ�ܣ�����0
    }

Status  CreatList_DuL_2_38(DuLinkList *L,int n,LElemType_DC Data[])     //���޵��д���
{
    DuLinkList s,h;
    int i;

    *L = (DuLinkList)malloc(sizeof(DuLNode));
    if(!(*L))
        exit(OVERFLOW);
    (*L)->next = (*L)->prior = *L;

    for(i=1,h=*L;i<=n;i++)
    {
        s = (DuLinkList)malloc(sizeof(DuLNode));
        if(!s)
            exit(OVERFLOW);
        s->data =Data[i-1];
        s->freq =0;

        s->next = *L;
        s->prior = h;
        h->next = s;

        if(h==*L)
            h->prior = s;

        h = h->next;
    }
}

Status Output_DuL_2_38(DuLinkList L)
{
    DuLinkList p;

    if(!L)
        return ERROR;

    else
    {
     p = L->next;
     while(p!=L)
     {
        printf("%2d ",p->data);
        p = p->next;
     }
    }
    return OK;
}






























