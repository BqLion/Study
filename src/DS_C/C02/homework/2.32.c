//2.32����������preָ��ռ�ĵ���ѭ���б�����Ϊ˫��ѭ���б�

#include <stdio.h>
#include<stdlib.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

typedef int LElemType_L;                //�����б��е��������� ������Ϊint
typedef struct LNode                    //�����б�ڵ�Ļ������ݽṹ��1������Ϊint��data��һǰһ������ָ����ֱ�ָ��ǰ��
{
    LElemType_L data;
    struct LNode* next;
    struct LNode* pre;
}LNode;
typedef LNode* LinkList;            //���������ΪLNode ��ָ��LinkList

//����ԭ��
Status Algo_2_32(LinkList L);               //������б�����ĺ�����������һ��ָ��ڵ��ָ��
Status InitList_2_32(LinkList *L);          //��ʼ���б�ĺ�����������һ��ָ��ڵ��ָ���ָ�룬������ָ��
Status CreatList_2_32(LinkList L,int n,LElemType_L Data[]);    //
void Output_2_32(LinkList L);
void OutputReverse_2_32(LinkList L);

int main(int argc,char *argv[])
{
    PressEnter;

    LinkList L;
    LElemType_L a[10] = {1,2,3,4,5,6,7,8,9,10};

    PressEnter;

    InitList_2_32(&L);
    CreatList_2_32(L,10,a);

    PressEnter;

    printf("L = ");
    Output_2_32(L);
    printf("\n\n");

    PressEnter;

    printf("Ϊ��������ǰ����̺������������...\n");
    Algo_2_32(L);
    printf("L = ");

    PressEnter;

    OutputReverse_2_32(L);
    printf("\n\n");

    return 0;
}

Status Algo_2_32(LinkList L)
{
    LinkList r;                 //ָ��ڵ��ָ��r

    if(!L)
        return ERROR;   //���L����0�򱨴�

    for(r= L;r->next!=L;r = r->next)        //������ָ��r�����ڱ�ͷ��û����һȦ������ʱ�򣩣�r����������ֱ����������
        r->next->pre = r;                       //������ʱ���ÿһ��r��nextҲ������һ��Ԫ�ص�pre�������д�����

    L->pre = r;                                     //����һȦ��ɣ����еĽ�㶼����preָ�룬����ͷ��㣬��ʱ������ͷ��㸳ֵ
    return OK;
}

Status InitList_2_32(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(LNode));             //��ʼ������������ͷ��̬����һ���ڴ�ռ䣬��ͷ��pre��ֵΪnull�������⣩����ͷ��nextָ�븳ֵΪ�շ�ֹҰָ��
    if(!(*L))
        exit(OVERFLOW);

    (*L)->pre = NULL;
    (*L)->next = L;

    return OK;
}

Status CreatList_2_32(LinkList L,int n,LElemType_L Data[])
{
    LinkList s,r;
    int i;

    if(!L || L->next !=L )       //�ų������������ʼ��û��ʼ���õ����������L=�գ�����L��nextָ�� û�����Ƶ���Ϊ�㣬����������Ԫ��
        return ERROR;

    for(i=1,r = L;i<=n;i++)             //ѭ����ֵ��������i��Ϊ1��rָ��ָ���ͷ��sָ����������ڴ档���б�ִֵ��n��
    {
        s = (LinkList)malloc(sizeof(LNode));        //ÿ��ż��������ָ��s���������ڴ�ռ�
        if(!s)
            exit(OVERFLOW);
        s->data = Data[i-1];                            //�����뵽�ı�����ָ��s��ָ���ڴ�ռ��︳ֵdata����׼���������Ĳ��裬����s��ָ��ֵ�鵽r��ߡ���1����2����3��ָ�룩
        s->pre = NULL;

        s->next = r->next;                      //1�����µĺ�ָ��ָ��ԭ�ĺ�Ԫ�أ�
        r->next = s;                                    //2����ԭԪ�صĺ�ָ��ָ���µ�Ԫ�أ�
        r = r->next;                                //Ӧ��һֱָ�����β���Ĺ���ָ����λ������һָ���µĶ���β��
                                                            //Ȼ������ȥ��ʼ��һ�ֵ�ѭ�����������붯̬�ڴ�ռ䣬Ӧ��ָ���ڴ�ռ�Ĺ���ָ��s�����µĿռ�ȥ�����һ��ѭ���ıպ�
    }
        return OK;
}

void Output_2_32(LinkList L)
{
    LinkList p;

    if(L)                           //ֻ�б���ڲŻ������µĲ���
    {
        p  = L->next;          //pָ����Ԫ����pû����һȦ����ʱѭ�������²�����1.��ӡ��ָԪ�ص�dataֵ 2.����1��
        while(p!=L)
        {
            printf("%2d ",p->data);
            p = p->next;
        }
    }
}

void OutputReverse_2_32(LinkList L)
{
    LinkList p;

    if(L)
    {
        p = L->pre;
        while(p !=L)
        {
        printf("%2d ",p->data);
        p = p->pre;
        }
    }
}


