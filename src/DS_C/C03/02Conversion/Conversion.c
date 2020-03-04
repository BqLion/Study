/******************************

�ļ��У�C03/02Conversion

�ļ�����Conversion.c

�㷨��3.1

******************************/

#ifndef CONVERSION_C
#define CONVERSION_C

#include "Conversion.h"

void conversion(int i)
{
    SqStack S;
    SElemType_Sq e;

    InitStack_Sq(&S);

    printf("ʮ������ %dת��Ϊ�˽�������Ϊ : ",i);   //����ΪʲôԴ������������ǰ�߼���0

    while(i)                    //����Ϊ�������ԣ���i������0��ʱ��Ҳ����i��û�б�������ʱ��ѭ���İ�i��8ȡ�� ����ѹ��ջ��Ȼ��i����8��ֱ��i������Ϊֹ
    {
        Push_Sq(&S,i%8);
        i = i/8;
    }

    while(!StackEmpty_Sq(S))            //Ȼ���ѹ��ջ�����е�Ԫ�ض��³�����ֱ���¸ɾ�Ϊֹ
    {
        Pop_Sq(&S,&e);
        printf("%d",e);
    }
}

#endif // CONVERSION_C


