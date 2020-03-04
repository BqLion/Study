/******************************

文件夹：C03 /06Hanoi

内容：汉诺塔相关函数测试

***************************/

#include"Hanoi.c"

int main(int argc,char **argv)
{
    int n;
    char x = 'x';
    char y = 'y';
    char z = 'z';

    n = 5;

    printf("作为示例，假设圆盘个数为 %d，操作步骤如下...\n",n);

    hanoi(n,x,y,z);

    printf("\n");

    return 0;
}
