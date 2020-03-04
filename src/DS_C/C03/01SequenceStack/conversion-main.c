/**********************

文件夹“C03/02Conversion

内容：进制转换相关函数测试

***********************/

#include "Conversion.c"

int main(int argc,char **argv)
{
    int i = 342391;

    printf("将10进制的数转换为8进制的数...\n");

    conversion(i);

    printf("\n\n");

    return 0;


}
