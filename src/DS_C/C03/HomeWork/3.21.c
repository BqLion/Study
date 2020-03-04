#include<stdio.h>
#include<ctype.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C03/01SequenceStack/SequenceStack.c"
//����ԭ��

void Algo_3_21(char *s,char c[]);
Status Priority(char a,char b);

int main(int argc,char *argv[])
{
    char *s = "a+b*c-d/e";
    char c[100];

    printf("��׺���ʽΪ:  ");
    printf("%s\n",s);
    printf("\n");

    Algo_3_21(s,c);
    printf("���ɵĺ�׺���ʽ��");
    printf("%s\n,c");
    printf("\n");

    return 0;
}

void Algo_3_21(char *s,char c[])
{
    int i,j;
    SqStack S;
    SElemType_Sq e;

    InitStack_Sq(&S);
    i = j = 0;

    while(s[i]!='\0')
    {
        if(isalpha(s[i]))
        c[j++] = s[i];
        else
        {
            while(!StackEmpty_Sq(S))
            {
                GetTop_Sq(S,&e);        //ѭ��������ȡջ��Ԫ�أ���ջ��Ԫ�رȴ��������������۸ߣ���ջ���׳������򣺽���ѭ�����Ѵ�����Ԫ���׳���������һ��������Ԫ�ء�

                if(Priority(e,s[i]))
                {
                Pop_Sq(&S,&e);
                c[j++] = e;
                }
                else
                    break;
            }

            Push_Sq(&S,s[i]);
        }

        i++;
    }


    while(!StackEmpty_Sq(S))
    {
        Pop_Sq(&S,&e);
        c[j++] = e;
    }

    c[j] = '\0';
}

//�Ƚ������a��b�����ȼ�
Status Priority(char a,char b)
{
    switch(a)
    {
    case'*':
    case'/':
    return OK;          //a>b
    break;

    case'+':
    case'-':
    if(b=='+' || b=='-')
    return OK;   //a>b
    else
    return ERROR;  //a<b
    break;
    }
}








