/******************************************

�ļ���C02/08ExtenLinkedList-main.c

���ݣ���չ�ĵ�������غ�������

*******************************************/

#include<stdio.h>
#include"E:/E/DS/C02/09ExtenLinkedList/ExtenLinkedList.c"

//����ԭ��

Status CmpGreater(LElemType_E e,LElemType_E data);          //�ж�data�Ƿ����e����data>e������TRUE
void PrintElem(LElemType_E e);

int main(int argc,char **argv)
{
                                                                                                                                                                                                                                                                ELinkList L;
        Link p,q,s;
        PositionPtr r;
        int i;
        LElemType_E e;

        printf("��3\n������LnitList_E����...\n");
        {
            printf("��ʼ����չ�ĵ�����L...\n");
            InitList_E(&L);
            printf("\n");
            ListTraverse_E(L,PrintElem);//����
        }
        PressEnter;

        printf("��14\n�� ����ListEmpty_E ����...\n");
        {
            ListEmpty_E(L) ? printf(" L Ϊ�գ���\n"):printf("L ��Ϊ�գ���\n");
            printf("\n");
            ListTraverse_E(L,PrintElem);//����
        }
        PressEnter;

        printf("��23\n������ ListInsert_L_E ����...\n");
        ListTraverse_E(L,PrintElem);//����
        {
            for(i=1;i<=6;i++)
            {
                printf("��L��%d��λ�ò��� \"%d\" ... \n",i,2*i);
                ListInsert_L_E(&L,i,2*i);
            }
             ListTraverse_E(L,PrintElem);//����
            printf("\n");
        }
        PressEnter;

        printf("��15\n������ ListLength_E ����...\n");
        {        ListTraverse_E(L,PrintElem);//����
            i = ListLength_E(L);
                 ListTraverse_E(L,PrintElem);//����
            printf("L �� ����Ϊ%d \n",i);
            printf("\n");
        }
        PressEnter;

        printf("��24\n�� ����ListDelete_E ����...\n");
        {       ListTraverse_E(L,PrintElem);//����
            ListDelete_L_E(&L,6,&e);
                ListTraverse_E(L,PrintElem);//����
            printf("ɾ��L �еĵ�6��Ԫ�� \"%d\"...  \n",e);
            printf("L �е�Ԫ��Ϊ�� L=");
            ListTraverse_E(L,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("��20\n������LocatePos_E ����...\n");
        {
            LocatePos_E(L,3,&p);
            printf("L�е�����Ԫ��\"%d\" �ĵ�ַΪ 0x%x  \n",p->data,p);
            printf("\n");
        }
        PressEnter;

        printf("��18\n������ PriorPos_E ����...\n");
        {
            r = PriorPos_E(L,p);
            printf("ָ��pָ���Ԫ��\"%d\"  ��ǰ��Ԫ��Ϊ \"%d\"  \n",p->data,r->data);
            printf("\n");
        }
        PressEnter;

        printf("��19\n�� ���� NextPos_E����... \n");
        {
            r = NextPos_E(p);
            printf("ָ��pָ���Ԫ��\"%d\" �ĺ��Ԫ��Ϊ \"%d\"  \n",p->data,r->data);
            printf("\n");
        }
        PressEnter;

        printf("��21\n������LocateElem_E ����...\n");
        {
            r = LocateElem_E(L,7,CmpGreater);
            printf("L�е�һ��Ԫ��ֵ����7��Ԫ��\"%d\"�ĵ�ַΪ0x%x \n",r->data,r);
            printf("\n");
        }
        PressEnter;

        printf("��1\n������ MakeNode_E ����...\n");
        {
            printf("�����ڵ�p ...\n");
            MakeNode_E(&p,101);
            printf("�����ڵ�q...\n");
            MakeNode_E(&q,202);
            printf("\n");
        }
        PressEnter;

        printf("��13\n������ GetCurElem_E ����...\n");
        {
        e = GetCurElem_E(p);
        printf("�ڵ�p��ֵΪ\"%d\" \n",e);
        e=  GetCurElem_E(q);
        printf("�ڵ�q��ֵΪ\"%d\" \n",e);
        printf("\n");
        }
        PressEnter;

        printf("��12\n������ SetCurElem_E ����...\n");
        {
            printf("�� 888 �滻p�ڵ��е�ֵ...\n");
            SetCurElem_E(p,888);
            printf("�ڵ�p��ֵΪ\"%d\"  \n",p->data);
            printf("\n");
        }
        PressEnter;

        printf("��2\n������ FreeNode_E ����..\n");
        {
            printf("����p�ڵ�ǰ��");
            p? printf("p���ڣ�!\n"):printf("p �����ڣ���\n");
            FreeNode_E(&p);
            printf("���ٽڵ�p��");
            p?printf("p ���ڣ�\n"):printf("p �����ڣ���\n");
            printf("\n");
        }
        PressEnter;

        printf("��8\n������Append_E ����...\n");
        {
            printf("��q�ڵ����L�����һ���ڵ�֮��");
            Append_E(&L,q);
            printf("L�е�Ԫ��Ϊ��L = ");
            ListTraverse_E(L,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("��\n��9\n���� Remove_E ����...\n");
        {
        printf("ɾ��L�����һ���ڵ㣬��p����ɾ���Ľ��...\n");
        Remove_E(&L,&p);
        printf("L�е�Ԫ��Ϊ��L=  ");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
        }
        PressEnter;

        printf("��6\n�� ���� InsFirst_E ����...\n");
        {
            printf("����ֵΪ 303 �Ľ�� p ...\n");
            MakeNode_E(&p,303);
            printf("��qָ��L�е�4�� Ԫ��...\n");
            LocatePos_E(L,4,&q);
            printf("��p�ڵ���뵽����q��Ϊͷ��������ĵ�һ���ڵ�֮ǰ...\n");
            InsFirst_E(&L,q,p);
            printf("L�е�Ԫ��Ϊ:L=");
            ListTraverse_E(L,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("�� 16\n �� ���� GetHead_E ����...\n");
        {
            p = GetHead_E(L);
            printf("L ͷָ��Ϊp = L.head = 0x%x  \n",p);
            printf("\n");
        }
        PressEnter;

        printf("��17\n�� ����GetLast_E ����...\n");
        {
            q = GetLast_E(L);
            printf("L ��βָ��Ϊq = L.tail = 0x%x \n",q);
            printf("\n");
        }
        PressEnter;

        printf("��10\n������ InsBefore_E ����...\n");
        {
            printf("����ֵΪ404�Ľ�� s...\n");
            MakeNode_E(&s,404);
            printf("���ڵ�s���뵽β�ڵ�q֮ǰ...\n");
            InsBefore_E(&L,&q,s);
            printf("��ǰL��ֵΪ��L = ");
            ListTraverse_E(L,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("��11\n�� ���� InsAfter_E ����...\n");
        {
            printf("����ֵΪ505�Ľ��s...\n");
            MakeNode_E(&s,505);
            printf("��s���뵽ͷ���p֮��...\n");
            InsAfter_E(&L,&p,s);
            printf("L�е�Ԫ��Ϊ��L= ");
            ListTraverse_E(L,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("��4\n������ ClearList_Ec����...\n");
        {
            printf("���Lǰ��");
            ListEmpty_E(L)?printf("LΪ�գ�����\n"):printf("L��Ϊ�գ�������\n");
            ClearList_E(&L);
            printf("���L�� ��");
            ListEmpty_E(L)?printf("LΪ�գ�����\n"):printf("L��Ϊ�գ�������\n");
            printf("\n");
        }
        PressEnter;

        printf("��5\n�� ���� DestroyList_E ����...\n");
        {
            printf("����Lǰ��");
            L.head != NULL && L.tail!=NULL ?  printf("L ���ڣ�����\n"):printf("L�����ڣ�����\n");
            DestroyList_E(&L);
            printf("����L��");
            L.head!=NULL &&L.tail!=NULL ? printf("L ���ڣ���\n"):printf("L�����ڣ�����\n");
            printf("\n");
        }
        PressEnter;

        return 0;
}

Status CmpGreater(LElemType_E e,LElemType_E data)
{
    return data>e ? TRUE:FALSE;
}

void PrintElem(LElemType_E e)
{
    printf("%d,e");
}
