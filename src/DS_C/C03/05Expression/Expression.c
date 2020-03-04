/**********************************

�ļ��У�C03

�ļ�����Expression.c

�㷴3.4

******************************/

#ifndef EXPRESSION_C
#define EXPRESSION_C

#include "Expression.h"

OperandType EvaluateExpression(char exp[])      //���ַ���exp������ʽ
{
    SqStack OPTR,OPND;          //����ջ�ͷ���ջ
    SElemType_Sq e,ch;
    OperatorType theta,x;       //����
    OperandType a,b;             //����
    int i;

    InitStack_Sq(&OPTR);
    Push_Sq(&OPTR,'#');
    InitStack_Sq(&OPND);            //��ʼ������ջ����#�����ʼ��ѹ�����ջ

    i = 0;
    ch = exp[i++];                      //tempѹ��exp�е�һ��Ԫ��

    while(ch!='#' ||GetTop_OPTR(OPTR)!='#')         //��ջ��Ԫ�غ�temp�ж����ǿ�ʼ���߽�������ʱ
    {
        if(!In(ch))                     //���temp�е���ֵ����In�Ҳ���ǲ��Ƿ��ţ��Ǿ������֣�ֱ��ѹ������ջ��
        {
            Push_Sq(&OPND,ch);
            ch = exp[i++];
        }
        else
        {
            switch(Precede(GetTop_OPTR(OPTR),ch))       //����Precede�����жϵĽ�������²������ڱ���ߣ������㣻�ڱ���ͣ�ѹ�룻������ȣ��������ţ�������
            {
            case'<':                            //�ڱ���ͣ�����ѹ��
                Push_Sq(&OPTR,ch);
                ch = exp[i++];
                break;

            case'=':
                Pop_Sq(&OPTR,&x);  //�������ţ�ֱ�Ӱ��ڲ��������׳������ⲿ������ֱ��i++��Ҳ�൱��ɾ����
                ch = exp[i++];
                break;

            case'>':
                Pop_Sq(&OPTR,&theta);
                Pop_Sq(&OPND,&b);
                Pop_Sq(&OPND,&a);
                Push_Sq(&OPND,Operate(a,theta,b));
                break;
            }

        }

    }
    return GetTop_OPTR(OPND);   //���ص�������ջ�е����һ��Ԫ�أ�Ҳ�����ܽ��
}

OperatorType GetTop_OPTR(SqStack OPTR)
{
    SElemType_Sq e;
    GetTop_Sq(OPTR,&e);

    return e;
}

Status In(SElemType_Sq c)
{
    switch(c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
    case '#':
        return TRUE;
    default:
        return FALSE;
    }
}

OperatorType Precede(OperatorType o1,OperatorType o2)
{
    OperatorType f;

    switch(o2)
    {
    case'+':
    case'-':                                //�Ӽ��ţ�ֻ�������źͽ������Ŵ󣬳��������������Ҫ���С
        if(o1=='('  ||  o1=='#')
            f = '<';
        else
            f = '>';
        break;

    case'*':
    case'/':                    //�˳����ţ�ֻ��ǰ���ǳ˳����������������ţ���
        if(o1=='*'||o1=='/'||o1==')')
        f = '>';
        else
        f = '<';
        break;

    case'(':                        //������������
        if(o1==')')
        {
        printf("����ƥ�����\n");
        exit(ERROR);
        }
        else
            f = '<';
        break;

    case')':
        switch(o1)
        {
        case'(':
            f = '=';
            break;
        case'#':
            printf("�����˴��������!\n");
            exit(ERROR);
        default:
            f = '>';

        }
        break;

        case'#':
            switch(o1)
            {
                case'#':
                f = '=';
                break;
                case'(':
                    printf("���ʽ���ж������ţ�\n");
                    exit(ERROR);
                default:
                    f = '>';
                }
                }
            return f;
            }

OperandType Operate(OperandType a,OperatorType theta,OperandType b)
{
    int x,y,z;

    x = a - 48;
    y = b - 48;

    switch(theta)
    {
    case'+':
        return x+y+48;
        break;
    case'-':
        return x-y+48;
        break;
    case'*':
        return x*y+48;
        break;
    case'/':
        return x/y+48;
        break;
    }
}
#endif








































