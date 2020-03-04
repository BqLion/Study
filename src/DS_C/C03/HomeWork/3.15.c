#include <stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

#define N 100

//���Ͷ���

typedef int SElemType;
typedef enum{Left,Right}StackName;
typedef struct
{
    SElemType s[N];             //˫��ջ�������СΪN��int t[2]�Ǵ��ջ��ָ��
    int t[2];
}TWStack;

//����ԭ��

void InitStack_TWS_3_15(TWStack *S);
Status Push_TWS_3_15(TWStack *S,StackName name,SElemType x);
Status Pop_TWS_3_15(TWStack *S,StackName name,SElemType *x);
void OutputStack_3_15(TWStack s,StackName name);

int main(int argc,char *argv[])
{
    TWStack S;
    int i,x;

    printf("��ʼ��ջ...\n");
    InitStack_TWS_3_15(&S);
    printf("\n");

    printf("������ջ��ѹ��Ԫ��...\n");
    for(i=1;i<=5;i++)
    {
        Push_TWS_3_15(&S,Left,i);
        Push_TWS_3_15(&S,Right,2*i);
    }
    printf("��ջ�е�Ԫ�أ���ջ�׵�ջ������");
    OutputStack_3_15(S,Left);
    printf("\n");
    printf("��ջ�е�Ԫ�أ���ջ�׵�ջ������");
    OutputStack_3_15(S,Right);
    printf("\n\n");

    printf("�ֱ𵯳�����ջ��ջ��Ԫ��...\n");
    Pop_TWS_3_15(&S,Left,&x);
    printf("��ջ��ջ��Ԫ��Ϊ: %d\n",x);
    Pop_TWS_3_15(&S,Right,&x);
    printf("��ջ��ջ�� Ԫ��Ϊ��%d\n",x);

    printf("��ջ�е�Ԫ�أ���ջ�׵�ջ������");
    OutputStack_3_15(S,Left);
    printf("\n");
    printf("��ջ�е�Ԫ�أ���ջ�׵�ջ������");
    OutputStack_3_15(S,Right);
    printf("\n\n");

    return 0;
}

void InitStack_TWS_3_15(TWStack *S)
{
    (*S).t[Left] = -1;              //ջ0��ջ��ָ��
    (*S).t[Right] = N;             //ջ1��ջ��ָ��
}

Status Push_TWS_3_15(TWStack *S,StackName name,SElemType x)    //��Ԫ��x��iջ
{
    if((*S).t[Left]+1==(*S).t[Right])                   //�������S����ָ��+1=��ָ�룬����ջ��ָ������������ջ����������
        return ERROR;

    switch(name)
    {
        case Left:
        (*S).t[name]++;
        break;

        case Right:
        (*S).t[name]--;
        break;
    }

    (*S).s[(*S).t[name]] = x;

    return OK;
}

Status Pop_TWS_3_15(TWStack *S,StackName name,SElemType *x)//ջ��Ԫ�س�ջ
{
    switch(name)
    {
    case Left:
        if((*S).t[name]  == -1)         //left������£�t==-1����ջ�գ����ش���
            return ERROR;

    *x = (*S).s[(*S).t[name]];          //��������Ԫ����x��ס
    (*S).t[name]--;
    break;

    case Right:
        if((*S).t[name]==N)
            return ERROR;

            *x = (*S).s[(*S).t[name]];
            (*S).t[name]++;
            break;
    }
}
//���ջ

void OutputStack_3_15(TWStack S,StackName name)
{
    int i;

    switch(name)
    {
    case Left:
    for(i=0;i<=S.t[name];i++)
        printf("%d ",S.s[i]);
        break;

    case Right:
        for(i=N-1;i>=S.t[name];i--)
            printf("%d ",S.s[i]);
        break;
    }
}






