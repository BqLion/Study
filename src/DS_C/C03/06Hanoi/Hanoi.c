/********************************

�ļ��У�C03/ջ�Ͷ��С�06��ŵ��

Hanoi.c

�㷨��3.5

********************************/

#ifndef HANOI_C
#define HANOI_C

#include "Hanoi.h"

//�㷨��3.5

void hanoi(int n,char x,char y,char z)
{
    if(n==1)
        move(x,1,z);
    else
    {
        hanoi(n-1,x,z,y);           //��x��n-1��Բ�̣���x�ƶ���y�ϣ�����z������
        move(x,n,z);                 //x�ϵ�n��Բ���ƶ���z��
        hanoi(n-1,y,x,z);           //��y��n-1��Բ�̴�y�ƶ���z���ϣ�����x��
    }
}

void  move(char x,int n,char z)
{
    gStep++;
    printf("��%2d��:����%d ��Բ�̴� %c�ƶ��� %c \n",gStep,n,x,z);
}

#endif // HANOI_C









