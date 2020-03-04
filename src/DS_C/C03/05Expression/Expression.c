/**********************************

文件夹：C03

文件名：Expression.c

算反3.4

******************************/

#ifndef EXPRESSION_C
#define EXPRESSION_C

#include "Expression.h"

OperandType EvaluateExpression(char exp[])      //从字符串exp读入表达式
{
    SqStack OPTR,OPND;          //数字栈和符号栈
    SElemType_Sq e,ch;
    OperatorType theta,x;       //符号
    OperandType a,b;             //数字
    int i;

    InitStack_Sq(&OPTR);
    Push_Sq(&OPTR,'#');
    InitStack_Sq(&OPND);            //初始化两个栈，把#这个开始符压入符号栈

    i = 0;
    ch = exp[i++];                      //temp压入exp中第一个元素

    while(ch!='#' ||GetTop_OPTR(OPTR)!='#')         //当栈顶元素和temp中都不是开始或者结束符号时
    {
        if(!In(ch))                     //如果temp中的数值不在In里，也就是不是符号，那就是数字，直接压入数字栈中
        {
            Push_Sq(&OPND,ch);
            ch = exp[i++];
        }
        else
        {
            switch(Precede(GetTop_OPTR(OPTR),ch))       //根据Precede函数判断的结果做如下操作：内比外高，做计算；内比外低，压入；内外相等，遇见括号，托括号
            {
            case'<':                            //内比外低，继续压入
                Push_Sq(&OPTR,ch);
                ch = exp[i++];
                break;

            case'=':
                Pop_Sq(&OPTR,&x);  //遇见括号，直接把内部的括号抛出来，外部的括号直接i++，也相当于删除了
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
    return GetTop_OPTR(OPND);   //返回的是数字栈中的最后一个元素，也就是总结果
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
    case'-':                                //加减号：只比左括号和结束符号大，除了这两种情况都要输出小
        if(o1=='('  ||  o1=='#')
            f = '<';
        else
            f = '>';
        break;

    case'*':
    case'/':                    //乘除符号，只有前边是乘除本身，或者是右括号（）
        if(o1=='*'||o1=='/'||o1==')')
        f = '>';
        else
        f = '<';
        break;

    case'(':                        //左括号是最大的
        if(o1==')')
        {
        printf("括号匹配错误！\n");
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
            printf("输入了错误的括号!\n");
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
                    printf("表达式中有多余括号！\n");
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








































