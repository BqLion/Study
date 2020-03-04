/*******************************

�ļ��У�C02/08DualCycleLinkedList

���ݣ�˫ѭ��������غ�������

*******************************/

#include<stdio.h>
#include"DualCycleLinkedList.c"

Status CmpGreater(LElemType_DC e,LElemType_DC data);        //CompareWhoisGreater ��������data>e������TRUE�����򷵻�FALSE
void PrintElem(LElemType_DC e);                         //���Ժ�������ӡ����

int main(int argc,char**argv)
{
    DuLinkList L;
    int i;
    LElemType_DC e;

    printf("1.\n����InitList_Dul ����...\n");
    {
    printf("��ʼ��˫ѭ������L...\n");
    InitList_Dul(&L);
    printf("\n");
    }
    PressEnter;

    printf("4.\n����ListEmpty_Dul ����...\n");
    {
        ListEmpty_Dul(L)?printf("LΪ�գ���\n"):printf("L��Ϊ�գ���\n");
        printf("\n");
    }
    PressEnter;


    printf("11.\n���� ListInsert_Dul ����...\n");
    {
        for(i=1;i<=6;i++)
        {
        printf("��L��%d ��λ�ò�\"%d\"...\n",i,2*i);
        ListInsert_Dul(L,i,2*i);
        }
        ListTraverse_Dul(L,PrintElem);
        printf("\n");
    }
    PressEnter;

    //�����Լ��Ĳ���insertDulN��������
    printf("VTVTVT\N ����ListInsert_Duln ����...\n");
    {

        ListInsert_Duln(L,4,100);
        ListTraverse_Dul(L,PrintElem);
        printf("\n");
    }
    PressEnter;


    printf("13.\n ����ListTraverse_Dul ����...\n");
    {
        printf("L�е�Ԫ��Ϊ��L = ");
        ListTraverse_Dul(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;


    printf("5.\n����ListLength_Dul����...\n");
    {
        printf("L�ĳ���Ϊ %d \n",ListLength_Dul(L));
        printf("\n");
    }
    PressEnter;

    printf("12.\n���� ListDelete_Dul ����...\n");
    {
        ListDelete_Dul(L,6,&e);
        printf("ɾ��L�е�����Ԫ��\"%d\"����ɾ�������ݱ�����e��...\n ",e);
        printf("L�е�Ԫ��Ϊ L = ");
        ListTraverse_Dul(L,PrintElem);
        printf("\n\n");

    }
    PressEnter;

    printf("6.\n����GetElem_Dul ����...\n");
    {
        GetElem_Dul(L,4,&e);
        printf("L�е�4��λ�õ�Ԫ��Ϊ \"%d\"\n",e);
        printf("\n");
    }
    PressEnter;

    printf("7.\n ����LocateElem_Dul ����...\n");
    {
        i = LocateElem_Dul(L,7,CmpGreater);
        printf("L�е�һ��Ԫ��ֵ����\"7\"��Ԫ�ص�λ��Ϊ %d \n",i);
        printf("\n");
    }
    PressEnter;

    printf("8.\n���� PriorElem_Dul ����... \n");
    {
        PriorElem_Dul(L,6,&e);
        printf("Ԫ�� \"6\" ��ǰ��Ϊ \"%d\" \n",e);
        printf("\n");
    }
    PressEnter;

    printf("10\n ���� GetElem_P����...\n");
    {
        DuLinkList p;
        p =GetElemPtr_Dul(L,3);
        printf("����������ڵ��ָ��Ϊ 0x%x,���Ӧ��ֵΪ \"%d\"  \n",p,*p);
        printf("\n");
    }
    PressEnter;

    printf("3.\n ����ClearList_Dul ����...\n");
    {
        printf("���Lǰ��");
        ListEmpty_Dul(L)?printf("LΪ�գ���\n") : printf("L��Ϊ�գ���\n");
        ClearList_Dul(L);
        printf("���L��");
        ListEmpty_Dul(L)?printf("LΪ�գ���\n") : printf("L��Ϊ�գ���\n");
        printf("\n");
    }
        PressEnter;

    printf("2. \n����DestroyList_Dul ����...\n");
    {
        printf("����Lǰ");
        L?printf("L����"): printf("L������");
        DestroyList_Dul(&L);
         printf("����L��");
        L?printf("L����") : printf("L������");
        printf("\n");
    }
    PressEnter;

    return 0;
    }

    Status CmpGreater(LElemType_DC e,LElemType_DC data)
    {
        return data>e ? TRUE:FALSE;
    }

    void PrintElem(LElemType_DC e)
    {
        printf("%d",e);

    }







