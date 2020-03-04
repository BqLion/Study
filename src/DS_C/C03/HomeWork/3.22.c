#include<stdio.h>
#include<ctype.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"

//����ԭ��
Status Algo_3_22(char c[],SElemType_Sq *Value);
char Operate(char a,char oper,char b);

int main(int argc,char *argv[])
{
    char c[] = "134*+62/-";
    SElemType_Sq value;

    printf("��֪�沨�����ʽΪ: ");
    printf("%s\n",c);
    Algo_3_22(c,&value);
    printf("�沨��ʽ�Ľ��Ϊ��%d\n",value-48);
    printf("\n");

    return 0;
}

//���沨�����ʽ��ֵ
Status Algo_3_22(char c[],SElemType_Sq *Value)
{
    int i;
    SqStack S;
    SElemType_Sq a,b;

    InitStack_Sq(&S);
    i = 0;

    while(c[i])
    {
    if(isdigit(c[i]))
    Push_Sq(&S,c[i]);    //��������
    else
    {
        Pop_Sq(&S,&b);
        Pop_Sq(&S,&a);
        Push_Sq(&S,Operate(a,c[i],b));                  //�沨�����ʽ�ķ���λ���Ѿ������ȼ��ź��ˣ���������ֱ�������׳����㼴��
    }

    i++;
    }

    Pop_Sq(&S,Value);

    if(!StackEmpty_Sq(S))
    return ERROR;

    else
    return OK;
}


char Operate(char a,char oper,char b)
{
    char c;
    switch(oper)
    {
        case'+':c = (a-48)+(b-48)+48;
        break;
        case'-':c = (a-48)-(b-48)+48;
        break;
        case'*':c = (a-48)*(b-48)+48;
        break;
        case'/':c = (a-48)/(b-48)+48;
        break;
    }

    return c;
}













