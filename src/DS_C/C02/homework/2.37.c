//2.37 ˫ѭ��������L����ΪL����������ż����һſ��������һſ���������������ǰһſ�ĺ�ߡ�����һȡһ�����ĶԳƣ������ӣ�
//˼·���׽ڵ�ǰ�����һָ�룬ǰָ��ָβԪ�ز�������ָ��ָ��No.2Ԫ�أ���No.2�� next No.3Ԫ�ر�׼ɾ��������׼���뵽��β֮��Ȼ���ָ�벽������No.4Ԫ�أ��ظ���ɾ��No.5�����뵽��β��������No.6��ֱ����ָ����ָ��next������βָ��ʱ��break��

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/08DualCycleLinkedList/DualCycleLinkedList.c"

Status Algo_2_37(DuLinkList L);
void PrintElem(LElemType_DC e);

int main(int argc,char *argv[])
{
    DuLinkList L;
    int i;

    InitList_Dul(&L);
    for(i=1;i<=10;i++)
        ListInsert_Dul(L,i,i);
    for(i=2;i<=11;i++)
        ListInsert_Dul(L,i,i);
    ListTraverse_Dul(L,PrintElem);
    printf("\n\n");

    Algo_2_37(L);
    printf("���������...\n");
    ListTraverse_Dul(L,PrintElem);
    printf("\n\n");

    return 0;
}

//���ĺ�����������ż���У�������һ�е������뵽ǰһ�����
Status Algo_2_37(DuLinkList L)
{
    DuLinkList head,tail,p;

    head = L->next;
    tail = L->prior;

    while(head!=tail)
    {
        if(head->next !=tail)
        {
        p = head->next;         //pָ��No2

        p->next->prior = head;          //˫�����׼ɾ������
        head->next = p->next;
        p->next = tail->next;
        p->prior = tail;

        tail->next->prior = p;
        tail->next=p;                          //˫�����׼���붯��

        head = head->next;              //head����1��ָ��No3.���һ��ѭ��
        }

        else
            break;          //�������tail��������һ��Ԫ����tail˵��������ɣ���������ѭ����

    }
    return OK;
}

void PrintElem(LElemType_DC e)
{
    printf("%d ",e);

}
