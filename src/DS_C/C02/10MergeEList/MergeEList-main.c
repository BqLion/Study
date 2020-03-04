/****************************

文件名：CO2 /10 MergeEList-main.c

内容：归并扩展的单链表相关函数测试

****************************/

#include <stdio.h>
#include"MergeEList.c"

void PrintElem(LElemType_E e);

int main(int argc,char **argv)
{
    FILE *fp;
    ELinkList La,Lb,Lc;
    int m,n;

    m = 6;
    n = 7;
    printf("作为示例，La长度设定为%d,Lb设定为%d，创建La和Lb...\n",m,n);
    fp = fopen("TestData_La.txt","r");      //文件指针，指向数据源
    CreateList_ascend(fp,&La,m);
    fclose(fp);
    fp = fopen("TestData_Lb.txt","r");
    CreateList_ascend(fp,&Lb,n);
    fclose(fp);

    printf("La = ");
    ListTraverse_E(La,PrintElem);
    printf("\n");
    printf("Lb = ");
    ListTraverse_E(Lb,PrintElem);
    printf("\n\n");
    PressEnter;

    MergeEList_L(La,Lb,&Lc,Cmp);
    printf("合并La和Lb为Lc = ");
    ListTraverse_E(Lc,PrintElem);
    printf("\n\n");
    PressEnter;

    return 0;
}

void PrintElem(LElemType_E e)
{
    printf("%d ",e);
}









