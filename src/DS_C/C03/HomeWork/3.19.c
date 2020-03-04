//3.19�ж����������Ƿ���ȷ���{}[]()
//��һ��ջ��ʵ�֣����������žͽ�ջ�����������ž���ջ��ߵ�Ԫ�س�ջ����ջ��ʱ����һ��match��飬�������С/��/�����ţ�����OK���������ƥ�����
//ջ��˼���������һ���ġ����ųɶԳ��֣����ȳ��ֵ�һ��������һ��������������ţ������ƥ�䣬�򱨴�

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"

//����ԭ��
Status Algo_3_19(char *s);
Status Matching(char a,char b);

 int main(int argc,char *argv[])
 {
    char *s = "(1+2)*3/{2/[4-5]*3-5*(8-7)}";

    printf("�жϱ��ʽ %s �����Ƿ�ƥ��...\n",s);
    if(Algo_3_19(s))
    printf("���ʽ����ƥ��!!!\n");
    else
    printf("���ʽ���Ų�ƥ�䣡����\n");

    printf("\n");

    return 0;
 }

 //�жϱ��ʽ�����Ƿ�ƥ��

 Status Algo_3_19(char *s)
 {
    SqStack S;
    SElemType_Sq e;
    int i;

    i = 0;
    InitStack_Sq(&S);

    while(s[i])
    {
        switch(s[i])            //��s[i]����Ϊ�յ��Ƿ񣬳������������ݣ���������������ţ����ջ
        {
        case'(':
        case'[':
        case'{':
            Push_Sq(&S,s[i]);
            break;
        case')':
        case']':
        case'}':
        if(StackEmpty_Sq(S))
        return ERROR;

        Pop_Sq(&S,&e);

        if(!Matching(e,s[i]))
        return ERROR;
        break;
        }
        i++;
    }

    if(StackEmpty_Sq(S))
    return OK;
    else
    return ERROR;
 }

 Status Matching(char a,char b)//�ж������Ƿ�ƥ��
 {
    switch(a)
    {
    case'(':
    if(b!=')')
    return ERROR;
    break;

     case'[':
    if(b!=']')
    return ERROR;
    break;

     case'{':
    if(b!='}')
    return ERROR;
    break;

    default:
    return ERROR;
    }

    return OK;
 }
