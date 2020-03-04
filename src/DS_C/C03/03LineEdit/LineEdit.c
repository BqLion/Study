//�б༭�����c�ļ����㷨��3.2

#ifndef LINEEDIT_C
#define LINEEDIT_C

#include"LineEdit.h"

//�㷨3.2

void LineEdit (char Buffer[])                   //��д��һ���༭�еĺ������������Ĳ�����Buffer������
{
    SqStack S;
    SElemType_Sq e;
    int i;
    char ch;

    InitStack_Sq(&S);

    i = 0;
    ch = Buffer[i++];
    while(ch!='\0')
    {
        while(ch!='\0' && ch!='\n')         //����0����������ջ������\n�������ջ��Ȼ����ս����µ�����
        {
            switch(ch)
            {
                case '#':Pop_Sq(&S,&e);   //����#���ž͵�����ɾ�����ղ������Ԫ��
                break;
                case '@':ClearStack_Sq(&S);//����@���ž����������������Ԫ��
                break;
                default:Push_Sq(&S,ch);     //������������ǣ��ǾͰ�ch�е�Ԫ��ѹջ
            }

            ch = Buffer[i++];//����������¸�Ԫ�ؽ���ch����ʼ��һ�ֵ�ѭ��
        }

        if(ch=='\n')
        {
            Push_Sq(&S,ch);
            StackTraverse_Sq(S,Print);
            ClearStack_Sq(&S);
            ch = Buffer[i++];
        }

        if(ch=='\n')
        {
            Push_Sq(&S,ch);
            StackTraverse_Sq(S,Print);
            ClearStack_Sq(&S);
            ch = Buffer[i++];
        }
    }
    if (ch=='0')
    {
        StackTraverse_Sq(S,Print);
        DestroyStack_Sq(&S);
    }
}


    void Print(SElemType_Sq e)
    {
    printf("%c",e);
    }

#endif // LINEEDIT_C
