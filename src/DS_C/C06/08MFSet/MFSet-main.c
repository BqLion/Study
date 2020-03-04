#include <stdio.h>
#include"MFSet.c"

int main(int argc,char *argv[])
{
    FILE *fp;
    MFSet S;

    printf("1\n 函数Initial_mfset 测试...\n");
    {
        printf("初始化集合（作为示范录入十个元素）...\n");
        fp = fopen("TestData_S.txt","r");
        Initial_mfset(fp,&S);
        fclose(fp);
        printf("初始化完成，现在集合中非空子集均包含单个元素...\n");
        printf("\n");
    }
    PressEnter;

    printf("8,9 \n 函数ShowSet_mfset 等测试...\n");
    {
    printf("展示集合S  = ");
    ShowSet_mfset(S);
    printf("\n");
    }
    PressEnter;

    printf("2,3,6,7\n 函数EquivalenceClass_mfset_1等测试...\n");
    {
        Relation R1;

        printf("根据等价关系建立等价类...\n");
        printf("作为示范录入4个二元关系如：{(1,2),(3,4),(5,6),(7,9)}...\n");
        fp = fopen("TestData_R1.txt","r");
        BuildRelation_mfset(fp,&R1);
        fclose(fp);
        EquivalenceClass_mfset_1(&S,R1);
        printf("展示等价类 S = ");
        ShowSet_mfset(S);
        printf("\n");
    }
    PressEnter;

    printf("4,5,6,7-2函数EquivalenceClass_MFSET_2等测试...\n");
    {
    Relation R2;

    printf("根据某集合的等价关系建立起等价类...\n");
    printf("作为示范录入两个二元关系如：{（1,3），（5,7）}...\n");
    fp = fopen("TestData_R2.txt","r");
    BuildRelation_mfset(fp,&R2);
    fclose(fp);
    EquivalenceClass_mfset_2(&S,R2);
    printf("展示等价类 S=  ");
    ShowSet_mfset(S);
    printf("\n");
    }
    PressEnter;

    fclose(fp);
}


