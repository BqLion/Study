//ʶ��ĳ�ַ������Ƿ����ĳ��ɹ���
//���������@��Ϊ��β����&��Ϊ�Գ����ģ�A��B�ֱ𲻺�������ʶ��@  &;

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"

//����ԭ��

Status Algo_3_17(char *s);

int main(int argc,char *argv[])
{
    char *s = "a+b-c&c-b+a@";

    printf("�ж�����%s �Ƿ�Ϲ�...\n\n",s);
    if(Algo_3_17(s))
    printf("������������!\n");
    else
    printf("���в��������⣡��\n");

    printf("\n");

    return 0;
}

Status Algo_3_17(char *s)
{
    SqStack S;
    SElemType_Sq e;
    int i;

    InitStack_Sq(&S);
    i = 0;

    while(s[i]!='@' && s[i]!='&')           //���ַ���ǰһ��ѹ��ջ��
    {
        Push_Sq(&S,s[i]);
        i++;
    }

    if(s[i]!='@')                                   //���ַ���ʣ�µ�һ�����
    {
    i++;
    while(!StackEmpty_Sq(S) && s[i]!='@')      //ѭ����ֹ�����ǣ�ջSΪ���ˣ������ַ�����������ֹ��
    {
        Pop_Sq(&S,&e);                                              //ѭ����ջ�е��ַ��׳�����e��ס
        if(s[i]!=e)                                                            //����׳���ֵ��ָ����ָ���ַ�����һ���ͱ���
        return ERROR;
        i++;
    }
    }

    if(StackEmpty_Sq(S) && s[i]=='@')
    return OK;
    else
    return ERROR;

}


