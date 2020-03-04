/************************************

�ļ��У� C02/04 SinglyLinkedList

���ݣ���������غ�������

************************************/

#include <stdio.h>
#include"SinglyLinkedList.c"

//����ԭ��

Status CmpGreater(LElemType_L e,LElemType_L data);      //���Ժ������ж�data�Ƿ����e����data����e������TRUE
void PrintElem(LElemType_L e);                          //���Ժ��������ڴ�ӡ����

int main(int argc,char **argv)
{
    LinkList L;
    int i;
    LElemType_L e;

    printf("1\n ����InitList_L���� ...");            //1.������ʼ������initList_L����
    {
          printf("��ʼ��������...");
          InitList_L(&L);                               //���ó�ʼ��������������L��ȡַ
          printf("\n");
    }
    PressEnter;

    printf("4\n���� ListEmpty_L ����...��n");        //4.����ListEmpty_L����
    {
        ListEmpty_L(L) ? printf("LΪ�գ���\n") : printf("L��Ϊ�գ�");
        printf("\n");
    }
    PressEnter;

    printf("10\n ���� ListInsert_L ����...\n");         //10.����ListInsert_L����
    {
        for(i=1;i<=6;i++)
        {
            printf("��L�ĵ�%d��λ�ò���\��%d\"...\n",i,2*i);
            ListInsert_L(L,i,2*i);
        }
        printf("\n");
    }

    printf("12\n���� ListTraverse_L ����...\n");
    {
        printf("L�е�Ԫ��Ϊ��L =  ");
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    printf("5\n���� ListLength_L ����... \n");          //5.����ListLegnth_L����
    {
        printf(" L�ĳ���Ϊ %d \n",ListLength_L(L));
        printf("\n");
    }
    PressEnter;

    printf("11\n ���� ListDelete_L����... \n");     //����ListDelete_L����
    {
        ListDelete_L(L,6,&e);                       //ɾ��������Ԫ�أ�����ɾ������ֵ����e��
        printf("ɾ��L�е�����Ԫ��\ ��%d\"...\n",e);
        printf("L�еĵ�����Ԫ��Ϊ L��");
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    printf("6\n ����GetElem_L����...\n");
    {
        GetElem_L(L,4,&e);
        printf("L�е��ĸ�λ�õ�Ԫ��Ϊ\"%d\" \n",e);
        printf("\n");
    }
    PressEnter;

    printf("7\n ���� LocateElem_L����...\n");           //7.����LocateElem_L����
    {
        i = LocateElem_L(L,7,CmpGreater);
        printf("L�е�һ��Ԫ��ֵ����\"7\"��Ԫ��λ��Ϊ %d \n",i);
        printf("\n");
    }
    PressEnter;

    printf("8\n���� PriorElem_L ����... \n");       //8 ����PriorElem_L����
    {
        PriorELem_L(L,6,&e);
        printf("Ԫ�� \"6\"��ǰ��Ϊ\"%d\" \n",e);
        printf("\n");
    }
    PressEnter;

    printf("2 \n����ClearList_L ����... \n");       //2 ����ClearList_L����
    {
        printf("���L ǰ��");
        ListEmpty_L(L) ? printf("LΪ�գ���\n") : printf("L��Ϊ�գ���\n");        //a?b:c  ����˵�����������a��ִ��b����ִ��c
        ClearList_L(L);
        printf("���L��");
        ListEmpty_L(L) ? printf("LΪ�գ���\n") :  printf("L��Ϊ�գ���\n");
    }
    PressEnter;

    printf("13 \n ����CreateList_HL ����...\n");        //ͷ���뷨���������������ԡ��ع�ͷ�巨��1.pָ��ָ��ͷ��㡣2.qָ��ָ��������Ԫ�ء�3. q.next=p.next;p.next=q
    {
        FILE *fp;                                         //FILE��һ��struct��������������<stdio.h>��
        LinkList L;
        printf("ͷ�巨����������L = ");
        fp = fopen("TestData_HL.txt","r");              //fp��������ֵΪ �����ĵ�������������
        CreateList_HL(fp,&L,5);                         //����������ַΪL������Ϊ5
        fclose(fp);                                     //�رմ򿪵��ĵ�
        ListTraverse_L(L,PrintElem);                    //��������ӡ����Ԫ��
        printf("\n\n");
    }
    PressEnter;

    printf("14 \n ����CreateList_TL ����...\n");        //14 ����CreateList_TL����
    {
        FILE *fp;
        LinkList L;
        printf("β�巨����������L = ");
        fp = fopen("TestData_TL.txt","r");               //�ļ�ָ�룬ָ����򿪵�����Դ
        CreateList_TL(fp,&L,5);
        fclose(fp);
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    system("pause");
    return 0;

}   //main��������

Status CmpGreater(LElemType_L e,LElemType_L data)
{
    return data>e ? TRUE:FALSE;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);
}


















