/******************************

�ļ��У�C03 /06Hanoi

���ݣ���ŵ����غ�������

***************************/

#include"Hanoi.c"

int main(int argc,char **argv)
{
    int n;
    char x = 'x';
    char y = 'y';
    char z = 'z';

    n = 5;

    printf("��Ϊʾ��������Բ�̸���Ϊ %d��������������...\n",n);

    hanoi(n,x,y,z);

    printf("\n");

    return 0;
}
