//对进制转换函数进行测试

#include"Conversion.c"

int main(int argc,char **argv)
{
    int i = 342391;

    printf("将十进制的数转换为八进制数...\n");

    conversion(i);

    printf("\n\n");

    return 0;
}
