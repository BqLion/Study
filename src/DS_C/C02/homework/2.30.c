//2.30 Ҫ�����һ��һ������A = A- B��C���õ��ǵ���������ݽṹ

//�ٴ��ܽ�˼·������һ��while��pa && pb && pc��ѭ����pb pc���롣Ȼ��paһ��while��pa && pa->data<pb->data��,ѭ����pa���ڻ����pb
//��pa=pb,��ִ��ѭ��ֱ��paɾ����ϣ���pa>pb����������һ���׶Σ�Ҳ����if��pa������ʱ���paû���磬pb  pc������




#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

Status Algo_2_30(LinkList La,LinkList Lb,LinkList Lc);
void PrintElem(LElemType_L e);

int main(int argc,char*argv[])
{
    LinkList La,Lb,Lc;
    int i;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int b[] = {1,2,3,4,5,6,7,8,8,9,11};
    int c[] = {1,2,3,4,5,6,7,8,11,12};

    if(InitList_L(&La) && InitList_L(&Lb) && InitList_L(&Lc))
    {
        for(i=1;i<=10;i++)
    {
        ListInsert_L(La,i,a[i-1]);
        ListInsert_L(Lb,i,b[i-1]);
        ListInsert_L(Lc,i,c[i-1]);

    }

    }

    printf("La = ");
    ListTraverse_L(La,PrintElem);
    printf("\n");
    printf("Lb = ");
    ListTraverse_L(Lb,PrintElem);
    printf("\n");
    printf("Lc = ");
    ListTraverse_L(Lc,PrintElem);
    printf("\n\n");

    Algo_2_30(La,Lb,Lc);
    printf("La = La - Lb��Lc = ");
    ListTraverse_L(La,PrintElem);
    printf("\n\n");

    return 0;
}

Status Algo_2_30(LinkList La,LinkList Lb,LinkList Lc)
{
    LinkList pa,pb,pc,pre;

    if(!La || !Lb || !Lc)
        return ERROR;

    pa = La->next;                  //��˳���ɾ������ͨ���ж���ָ�룻���������ͨ����preָ���pָ��
    pb = Lb->next;
    pc = Lc->next;
    pre = La;

    while(pa && pb && pc)
    {
        if(pb->data<pc->data)
            pb = pb->next;
        else if(pb->data>pc->data)
            pc = pc->next;
        else
        {
        while(pa && pa->data<pb->data)
        {
            pre = pa;
            pa = pa->next;
        }

        while(pa && pa->data==pb->data)//��pa��pb��ȣ���pa��ɾ������
        {
            pre->next = pa->next;//ɾ��������˼·��pre��nextԽ��paָ��pa��next��free��pa֮��pa�ٴε���pre��next��
            free(pa);
            pa = pre->next;

        }

        if(pa)
        {
        pb = pb->next;
        pc = pc->next;
        }
        }
    }
    return OK;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);
}

