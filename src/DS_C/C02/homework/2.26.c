//2.26  ��Ȼ����C = A �� B�����ݽṹ��Ϊ������
//˼·����˳���һ����if pa = pb������ָ��������β�巨���뵽Pc�У�����������else if���뵽��Ӧ��˳�����

#include<stdio.h>
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

//����ԭ��

Status Algo_2_26(LinkList La,LinkList Lb,LinkList Lc);
void PrintElem(LElemType_L e);

int main(int argc,char argv[])
{
    LinkList La,Lb,Lc;
    int i;

    if(InitList_L(&La) && InitList_L(&Lb) && InitList_L(&Lc))       //�������ɹ�
    {
        for(i=1;i<=10;i++)
            {
            ListInsert_L(La,i,i);
            ListInsert_L(Lb,i,2*i);
            }
    }

    printf("La = ");
    ListTraverse_L(La,PrintElem);
    printf("\n");

    printf("Lb = ");
    ListTraverse_L(Lb,PrintElem);
    printf("\n");

    Algo_2_26(La,Lb,Lc);
    printf("Lc= La��Lb");
    ListTraverse_L(Lc,PrintElem);
    printf("\n\n");

    return 0;
}

Status Algo_2_26(LinkList La,LinkList Lb,LinkList Lc)
{
    LinkList pa,pb,pc,s;

    if(!La || !Lb)
        return ERROR;

    pa = La->next;
    pb = Lb->next;
    pc= Lc;

    while(pa && pb)
    {
        if(pa->data == pb->data)
        {
            s = (LinkList)malloc(sizeof(LNode));
            if(!s)
                exit(OVERFLOW);
            s->data = pa->data;
            s->next = NULL;

            pc->next = s;               //��s��ָԪ����β�巨���뵽pc��

            pc = pc->next;
            pa = pa->next;
            pb = pb->next;
        }
        else if(pa->data <pb->data)
            pa = pa->next;
        else
            pb = pb->next;

    }
    return OK;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);
}





