/**************************************

�ļ���C03/01Sequence
Stack

���ݣ�˳��ջ��غ�������

*************************************/

#include<stdio.h>
#include"SequenceStack.c";

void PrintElem(SElemType_Sq e);

int main(int argc,char **argv)
{
    SqStack S;
    int i;
    SElemType_Sq e;

    printf("1\n ����InitStack����...\n");
    {
        printf("��ʼ��˳��ջS ...\n");
        InitStack_Sq(&S);
        printf("\n");
    }
    PressEnter;

    printf("4\n ����StackEmpty ����...\n");
    {
        StackEmpty_Sq(S)?printf("S Ϊ�գ�����\n"):printf("S��Ϊ�գ�����\n");
        printf("\n");
    }
    PressEnter;

    printf("7\n ����Push����...\n");
    {
        for(i=1;i<=6;i++)
        {
        printf("�� \"%2d\" ѹ��ջS ",2*i);
        Push_Sq(&S,2*i);
        printf("���ۼƵ� %d ��Ԫ�أ�...\n",S.top-S.base);
        }
        printf("\n");
    }
        PressEnter;

        printf("9\n ���� StackTraverse ����...\n");
        {
            printf("S �е�Ԫ��Ϊ :S = ");
            StackTraverse_Sq(S,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("8\n ����Pop����...\n");
        {
            Pop_Sq(&S,&e);
            printf("ջ��Ԫ��\"d\" ��ջ...\n",e);
            printf("S�е�Ԫ��Ϊ:S = ");
            StackTraverse_Sq(S,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("5\n ����StackLength ����...\n");
        {
            i = StackLength_Sq(S);
            printf("S�ĳ���Ϊ %d \n",i);
            printf("\n");
        }
        PressEnter;

        printf("6\n ����GetTop ����...\n");
        {
            GetTop_Sq(S,&e);
            printf("ջ����Ԫ�ص�ֵΪ \"%d\"   \n",e);
            printf("\n");
        }
        PressEnter;

        printf("3\n  ����ClearStack ����...\n");
        {
            printf("���S ǰ:");
            StackEmpty_Sq(S)?printf("SΪ�գ���\n"):printf("S��Ϊ�գ���\n");
            ClearStack_Sq(&S);
            printf("���S��");
            StackEmpty_Sq(S)?printf("SΪ�գ���\n"):printf("S��Ϊ�գ���\n");
        }
            PressEnter;

        printf("2 \n ����DestroyStack ����...\n");
        {
            printf("����S ǰ��");
            S.base!=NULL && S.top!=NULL ? printf("S  ���ڣ� \n"):printf("S �����ڣ���\n");
            DestroyStack_Sq(&S);
            printf("����S��:");
            S.base!=NULL && S.top!=NULL ?printf("S ���ڣ���\n"):printf("S �����ڣ���\n");;
            printf("\n");
        }
        PressEnter;
        return 0;
}

void PrintElem(SElemType_Sq e)
{
    printf("%d ",e);

}




