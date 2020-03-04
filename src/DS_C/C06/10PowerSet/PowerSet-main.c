//测试

#include<stdio.h>
#include"PowerSet.c"

int main(int argc,char *argv[])
{
    LinkList A;

    printf("1\n 函数CreatePowerSet_PS  测试...\n");
    {
        FILE *fp;

        printf("创建集合A ...\n");
        fp = fopen(TestData_A.txt,"r");
        CreatePowerSet_PS(fp,&A);
        fclose(fp);
        printf("\n");
    }
    PressEnter;

    printf("3\n 函数Output_PS测试..\n");
    {
    printf("输出集合A = ");
    Output_PS(A);
    printf("\n");
    }
    PressEnter;

    printf("2\n 函数GetPowerSet_PS 测试...\n");
    {
        LinkList B;

        printf("计算集合的幂集...\n");
        printf("创建集合B临时的存储幂集单元....\n");
        InitList_L(&B);
        printf("依次输出求取的幂集中的各子集...\n");
        GetPowerSet_PS(1,A,B);
        printf("\n");
    }
    PressEnter;
}


