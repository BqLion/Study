/*********************************

�ļ��У�C02��07Difference

�ļ�����Difference.c

�㷨��2.17

********************************/

#ifndef DIFFERENCE_C
#define DIFFERENCE_C

#include "Difference.h"

void difference(SLinkList *S,LElemType_S A[],int len_A,LElemType_S B[],int len_B )          //һ������������S����������A/B����Ϊ���ϡ�
{
    int i,j;                                //����������
    int r,p,k;                          //����ָ��3��
    LElemType_S b;

    InitSpace_SL();                 //��ʼ��SPACE�ռ�
    *S = Malloc_SL();               //��S���������붯̬�ռ�
    r = *S;                             //����ָ��rָ��ǰ������S��β����Ҳ����ͷ������Ϊֻ��һ��Ԫ�����ڣ�
    SPACE[r].cur = 0;               //β�ڵ�ġ�ָ�롱Ҫ����

    for(j = 0;j<len_A;j++)              //�Ѽ���A������¼�빤����S��
    {
        i = Malloc_SL();                    //���䶯̬�ռ䣬iָ�򱾹������ͷ��
        SPACE[i].data = A[j];           //����A����Ԫ�������ʼ���ι�ӣ��õ���β�巨��
        SPACE[r].cur = i;                   //����β����nextָ��ָ��i��ָ��λ�ã�β��ɹ���
        r = i;                                      //rָ����ָ��Ԫ�ش�ԭ��β��Ϊ���ڵ��¶�βҲ����i��ָ��λ��
    }
    SPACE[r].cur = 0;                   //βָ���ÿ�


    for(j=0;j<len_B;j++)            //׼����B�������Ԫ�ض�����һ��
    {
        b = B[j];                           //�ڵ�Ԫ��b����ֵΪ����B��ͷԪ��
        p = *S;                             //p����ֵΪ�б�ָ��S��ָ��ֵ��������A��ͷ��㣩
        k = SPACE[*S].cur;          //kָ�򼯺�A�ĵ�һ���ڵ�
        while(k && SPACE[k].data !=b)       //ѭ��������kδ�����k��ָ��Ԫ�ص�dataֵ ����������b��װ��B���������ֵ
        {
            p = k;                                            //����һ��Ԫ��B������Ԫ��A��ʱ��ָ��A�������ָ�����������ֱ����A�������Ԫ�ض�����һ��
            k = SPACE[k].cur;
        }
        if(!k)                                                      //������ϵı�����������ˣ���û����A���ҵ�B����k�������������������Ͱ�B�����A��
        {
        i = Malloc_SL();                                    //i��׼������Ľ��
        SPACE[i].data = b;                                 //b��ֵ��������Ľ���data
        SPACE[i].cur = SPACE[r].cur;                //������Ľ�����µ�β����㣬����nextӦ�õ���ԭ����β������next
        SPACE[r].cur = i;                                   //ԭ����next����ָ��i
        }
        else
            {
                SPACE[p].cur = SPACE[k].cur;
                Free_SL(k);
                if(k = r)
                    r = p;
        }
        }
    }

#endif // DIFFERENCE_C
















