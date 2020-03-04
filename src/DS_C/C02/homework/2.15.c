#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

Status Algo_2_15(LinkList ha,LinkList hb,LinkList *hc);
void PrintElem(LElemType_L e);

int main(int argc,char *argv[])
{
    LinkList ha,hb,hc;
    int i;

    if(InitList_L(&ha) && InitList_L(&hb) && InitList_L(&hc))
    {
        for(i=1;i<=5;i++)
            ListInsert_L(ha,i,i);
        for(i=1;i<=7;i++)
            ListInsert_L(hb,i,2*i);
    }

    printf("ha = ");
    ListTraverse_L(ha,PrintElem);
    printf("\n");
    printf("hb = ");
    ListTraverse_L(hb,PrintElem);
    printf("\n\n");

    Algo_2_15(ha,hb,&hc);
    printf("����ha��hb֮�������Ϊ : \n hc=  ");
    ListTraverse_L(hc,PrintElem);
    printf("\n\n");

    return 0;
}

Status Algo_2_15(LinkList ha,LinkList hb,LinkList *hc)
{
    LinkList pa,pb;

    if(ha && hb)                //����������Ϊ��
    {
        pa = ha;
        pb = hb;

        while(pa->next && pb->next)         //������ָ�����һ��Ԫ�ض����ǿյ�ʱ��ѭ��������ֱ������һ��ָ����һ��Ϊ��ͣ����
    {
        pa = pa->next;
        pb = pb->next;
    }

    if(!pa->next)           //ͣ����֮��������if�����˭ͣ����.���pa�϶�ͣ��������hcָ��pa���е�ͷ��Ȼ��pa��nextָ��ָ��hb��ͷ����hb����ha�ĺ��
    {
        *hc =ha;
        pa->next = hb->next;
    }

    if(!pb->next)
    {
        *hc = hb;
        pb->next = ha->next;
    }

    return OK;
    }

    return ERROR;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);
}






