//���ɻ𳵵��ȵ�ָ������
//A�ֳ�����ջ��B�ֳ�����ջ���ٳ�ջ��A�ֳ����ٳ�ջ

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"

//����ԭ��

void Algo_3_16(char *En,char Con[]);

int main(int argc,char *argv[])
{
    char *En = "HSHHSHHHSSHSHHHS";
    char Ex[100],Con[100];

    printf("����������ң���������...\n");
    printf("����ǰ��ڴ��ĳ�������Ϊ��H��ʾӲϯ��S��ʾ��ϯ����\nEn(������) = ");
    printf("%s\n",En);
    printf("\n");

    printf("���ɵ�������...\n");
    Algo_3_16(En,Con);
    printf("��������Ϊ(I��ʾ��ջ��O��ʾ��ջ)��\nCon = ");
    printf("%s\n",Con);
    printf("\n");

    return 0;
}

//���ɳ����������

void Algo_3_16(char *En,char Con[])
{
    int i,j;
    SqStack S;
    SElemType_Sq e;

    InitStack_Sq(&S);
    i=j=0;

    while(En[i])
    {
        if(En[i]=='H')
        {
        Push_Sq(&S,En[i]);
        Con[j++] = 'I';
        }

    if(En[i]=='S')
    {
    Push_Sq(&S,En[i]);
    Pop_Sq(&S,&e);
    Con[j++]='I';
    Con[j++]='O';
    }

    i++;

    }


    while(!StackEmpty_Sq(S))
    {
        Pop_Sq(&S,&e);
        Con[j++] = 'o';
    }

    Con[j] = '\0';
}






