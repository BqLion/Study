/*******************************

�ļ��У�03ջ�Ͷ��� 08CylSeqQueue

���ݣ�ѭ��������غ�������

*****************************/

#include <stdio.h>
#include"CylSeqQueue.c"

void PrintElem(QElemType_CSq e);

int main(int argc,char **argv)
{
    CSqQueue Q;
    int i;
    QElemType_CSq e;

    printf("1\n ����InitQueue_CSq ����...\n");
    {
        printf("��ʼ��ѭ��˳�����Q...\n");
        InitQueue_CSq(&Q);
        printf("\n");
    }
    PressEnter;

    printf("4\n ����QueueEmpty_CSq ����...\n");
    {
    QueueEmpty_CSq(Q)?printf("QΪ�գ���\n"):printf("Q��Ϊ�գ���\n");
    printf("\n");
    }
    PressEnter;

    printf("7\n����EnQueue_CSq ����...\n");
    {
        for(i=1;i<=6;i++)
        {
            printf("Ԫ��\"%2d\" ���Q��",2*i);
            EnQueue_CSq(&Q,2*i);
            printf("�ۼƵ�%d��Ԫ��...\n",QueueLength_CSq(Q));
        }
        printf("\n");
    }

    printf("9/n ����QueueTraverse_CSq ����...\n");
    {
        printf("Q�е�Ԫ�أ�Q = ");
        QueueTraverse_CSq(Q,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    printf("8\n���� DeQueue_CSq ����...\n");
    {
        DeQueue_CSq(&Q,&e);
        printf("��ͷԪ�� \"%d\"����...\n",e);
        printf("Q�е�Ԫ��Ϊ��Q = ");
        QueueTraverse_CSq(Q,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    printf("5\n ���� QueueLength_CSq ����...\n");
    {
        i = QueueLength_CSq(Q);
        printf("Q�ĳ���Ϊ%d \n",i);
        printf("\n");
    }
    PressEnter;

    printf("6\n����GetHead_CSq ����...\n");
    {
        GetHead_CSq(Q,&e);
        printf("��ͷԪ�ص�ֵΪ\"%d\" \n",e);
        printf("\n");
    }
    PressEnter;

    printf("3\n���� ClearQueue_CSq ����...\n");
    {
    printf("���Qǰ��");
    QueueEmpty_CSq(Q)?printf("QΪ�գ���\n"):printf("Q��Ϊ�գ���\n");
    ClearQueue_CSq(&Q);
    printf("���Q��");
    QueueEmpty_CSq(Q)?printf("QΪ�գ�����\n"):printf("Q��Ϊ�գ�\n");
    printf("\n");
    }
    PressEnter;

    printf("2\n����DestroyQueue_CSq ����...\n");
    {

        printf("����Qǰ:");
        Q.base !=NULL?printf("Q���ڣ���\n"):printf("Q�����ڣ���\n");
        DestroyQueue_CSq(&Q);
        printf("����Q��:");
        Q.base !=NULL?printf("Q���ڣ�\n"):printf("Q�����ڣ���\n");
        printf("\n");
    }
    PressEnter;

    return 0;
}


void PrintElem(QElemType_CSq e)
{
    printf("%d ",e);
}
