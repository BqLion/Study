/*������ľ͵�����
ԭ�������㷨��Algo_2_22����󼸾䡣
˼·���£�
1.����Ԫ��nextָ��ת���ɺ�תָǰ��ͷ��㡢NULL�ڵ㻥��λ�ã�����˼ά��
2.��ͷ���Ϊ����core��������ת��󣬶��дӺ���ǰ������NULL��1��2��3��4��5���� �Ͱ������˳����ͷ�巨�������Ķ��о��ǵ��ö���
3.�Ƚ�NULLͷ�嵽ͷ���󣬼� ͷ��� ->next = NULL;Ȼ�����Ŷ�����ͷ��
4.    1��next = ͷ����next��ͷ���� next = 1�������1��ͷ�壬������β���
*/

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

//����ԭ��

Status Algo_2_22(LinkList L);
void PrintElem(LElemType_L e);

int main(int argc,char *argv[])
{
    LinkList L;
    int i;

    if(InitList_L(&L))
    {
    for(i=1;i<=10;i++)
        ListInsert_L(L,i,i);
    }

    printf("L = ");
    ListTraverse_L(L,PrintElem);
    printf("\n\n");

    printf("���õ�����...\n");
    Algo_2_22(L);
    printf("��ʱL =  ");
    ListTraverse_L(L,PrintElem);
    printf("\n\n");

    return 0;
}

//2.22����������Ĳ���

Status Algo_2_22(LinkList L)
{
    LinkList pre,p;

    if(!L || !L->next)
        return ERROR;

        p = L->next;                //����ָ���λ��ָ������ĵ�һ��Ԫ��
        L->next = NULL ;        //ͷ�巨�����һ��Ԫ�أ���NULL

        while(p)
        {
        pre = p;
        p = p->next;
        pre->next = L->next;
        L->next = pre;
        }

        return OK;
}

    void PrintElem(LElemType_L e)
    {
        printf("%d ",e);

    }



