//2.23�鲢������������㷨

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

//����ԭ��

Status Algo_2_23_1(LinkList La,LinkList *Lb,LinkList *Lc);
Status Algo_2_23_2(LinkList La,LinkList *Lb,LinkList *Lc);
void PrintElem(LElemType_L e);

int main(int argc,char *argv[])
{
    LinkList La,Lb,Lc;
    int i,mark;

    if(InitList_L(&La)&&InitList_L(&Lb)&&InitList_L(&Lc))   //�������ɹ�
    {
        for(i=1;i<=5;i++)
        {
            ListInsert_L(La,i,2*i-1);
            ListInsert_L(Lb,i,2*i);
        }
    }

    printf("��֤��2.23�ķ���...");
    fflush(stdin);
    scanf("%d",&mark);
    printf("\n");

    printf("�����õ�����Ϊ ��\n");
    printf("La = ");
    ListTraverse_L(La,PrintElem);
    printf("\n");
    printf("Lb = ");
    ListTraverse_L(Lb,PrintElem);
    printf("\n\n");

    if(mark==1)
    {
        printf("�� 2.23 ����1 ��֤...\n");
        Algo_2_23_1(La,&Lb,&Lc);
    }

    printf("�鲢La��LbΪLC = ");
    ListTraverse_L(La,PrintElem);
    printf("\n\n");

    return 0;
}

//�鲢����������

//˳������

Status Algo_2_23_1(LinkList La,LinkList *Lb,LinkList *Lc)
{
    LinkList prea,pa,pb;
    if(!La || (*Lb) || (!La->next && !(*Lb)->next))         //�鲢��֮ǰ�������һ�������ڣ������������ǿյģ�����
        return ERROR;

        *Lc = La;                   //������ָ���λ��Lc��ͷ��La��ͷ��λ�ã�preaָ��La�ĵ�һ��Ԫ�أ�paָ��La�ĵڶ���Ԫ��,pbָ��Lb�ĵ�һ��Ԫ��
        prea = La;
        pa = La->next;
        pb=  (*Lb)->next;

        while(pa && pb)
        {
            (*Lb)->next = pb->next;
            prea = pa;
            pa = pa->next;
            prea->next = pb;
            pb->next = pa;
            prea = pb;
            pb = (*Lb)->next;
        }
        if(!pa)
            prea->next = pb;

        free(*Lb);
        *Lb = NULL;

        return OK;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);


}



