#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

//����ԭ��
Status Algo_2_24(LinkList La,LinkList *Lb,LinkList *Lc);
void PrintElem(LElemType_L e);

int main(int argc,char *argv[])
{
    LinkList La,Lb,Lc;
    int i,mark;

    if(InitList_L(&La) && InitList_L(&Lb)&&InitList_L(&Lc))           //�������ɹ�
    {
        for(i=1;i<=5;i++)
            {
                ListInsert_L(La,i,2*i-1);
                ListInsert_L(Lb,i,2*i);
            }
    }

    printf("�����õ�����Ϊ:\n");
    printf("La = ");
    ListTraverse_L(La,PrintElem);
    printf("\n");
    printf("Lb = ");
    ListTraverse_L(Lb,PrintElem);
    printf("\n\n");

    Algo_2_24(La,&Lb,&Lc);
    printf("�鲢La��LbΪLc = ");
    ListTraverse_L(Lc,PrintElem);
    printf("\n\n");

    return 0;
}
//�鲢��������������Ϊһ���ݼ�������

Status Algo_2_24(LinkList La,LinkList *Lb,LinkList *Lc)
{
    LinkList pa,pb,s;

    if(!La || !Lb || (!La->next && !(*Lb)->next))       //La��Lb��һ�������ڻ���������Ϊ�յ�ʱ�򱨴�
        return ERROR;

        *Lc = La;                       //˼·�� la����lc��ͷ������ָ���λ�����paָ��la�׽ڵ㣬pbָ��lb�׽ڵ㡣
        pa = La->next;
        pb = (*Lb)->next;
        La->next = NULL;        //La�����Ҫ��Ϊ�±�ģ�������Ҫ��ͷ�巨ʵ��������һ�а���ͷ�巨ʵ�������ԭ��βԪ��NULL�����

        while(pa && pb)
    {
        if(pa->data <= pb->data)            //paС���Ͳ���pa
        {
            s = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = s;
        }
        else
        {
        s = pb->next;                          //else ����pb
        pb->next = La->next;
        La->next = pb;
        pb = s;
        }
    }

    while(pa)
    {
    s = pa->next;
    pa->next = La->next;
    La->next = pa;
    pa = s;
    }

    while(pb)
    {
        s = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = s;
    }
    free(*Lb);

    return OK;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);

}




