//03ջ�Ͷ���

//�ļ�����Expression.h

//���ݣ����ʽ��ְ��ز����б�

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stdio.h>

//���Ͷ���

typedef char SElemType_Sq;              //���屾�����Ԫ�أ�����Ϊchar��

#include "E:/E/DS/C03/01SequenceStack/SequenceStack.c"

 typedef SElemType_Sq OperandType;          //������������char
 typedef SElemType_Sq OperatorType;         //���������Ҳ��char

 OperandType EvaluateExpression(char exp[]);     //���ʽ��ֵ�����ص�ֵ�ǲ�����������

 OperatorType GetTop_OPTR(SqStack OPTR);       //��ȡ������ջ��ջ��Ԫ�أ����ص�ֵ�������������

 Status In(SElemType_Sq c);                 //�ж�c�Ƿ��ڲ����������

 OperatorType Precede(OperatorType o1,OperatorType o2);         //һ�����������͵ĺ������Ƚ����������������ȼ�

 OperandType  Operate(OperandType a,OperatorType theta,OperandType b);          //���������һ�����ʽ��ֵ

 //˼·������ջ���ֱ�װ���ֺͷ��š���һ���ַ������������ı��ʽ��Ȼ�󰤸�ȡ��������temp�У����жϣ����Ƿ��ŵĻ���ֱ��������ջ�������ָ��++��������ַ���������temp�е��ַ����ַ�ջ�е�top��Ҳ��������������ַ��Ƚ����ȼ��ߵ͡������ջ����ַ����ȼ��ߣ�����3+2* ,��ʱ����Ҫ�ѷ�����ջ����Ϊ��֪����߻᲻���и��ߵģ������ջ������ȼ��ͣ�����3*2+�������������Ҫ���㣬�ַ�ջ��ջ��theta�У�����ջ��ջ���Σ���a b�У�Ȼ��operator��a��theta��b������������������ջ��Ȼ�󽫴�������ַ���ջ������ָ��++�����������ȼ���ȣ��������������ţ��������û������Ļ���

 #endif









