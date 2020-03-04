//线索树的测试

#include<stdio.h>
#include"ThreadBinaryTree.c"

void PrintElem(TElemType_Thr e);

int main(int argc,char *argv[])
{
    ThrBiTree Thrt1,Thrt2,Thrt3;
    ThrBiTree T1,T2,T3;
    int mark;

    printf("1\n函数CreateBiTree_Thr 测试...\n");
    {
        FILE *fp;

        printf("按照先序序列创建二叉树...\n");
        printf("作为示范，录入先序序列：ABDG^^^EH^^I^^CF^J^^^\n");
        fp = fopen("TestData_T.txt","r");
        CreateBiTree_Thr(fp,&T1);
        fseek(fp,0,SEEK_SET);
        CreateBiTree_Thr(fp,&T2);
        fseek(fp,0,SEEK_SET);
        CreateBiTree_Thr(fp,&T3);
        fclose(fp);
        printf("\n");
    }
    PressEnter;

    printf("2\n 测试先序 后继线索二叉树\n");
    {
        printf("5,6 \n 函数PreThreading_Thr、PreOrderThreading_Thr 测试\n");
        printf("将T1 先序后继线索化为Thrt1\n");
        PreOrderThreading_Thr(&Thrt1,T1);
        printf("\n");
    }
    PressEnter;

    printf("\n 测试中序全线索二叉树\n ");
    printf("\n 函数InThreading_Thr,InOrderThreading_Thr测试\n");
    {
    printf("将T2中序全线索化为Thrt2 \n");
    InOrderThreading_Thr(&Thrt2,T2);
    printf("\n");
    }
    PressEnter;

    printf("4\n 函数InOrderTraverse_Thr 测试\n");
    {
        printf("中旬遍历 Thrt2 = ");
        {
        InOrderTraverse_Thr(Thrt2,PrintElem);
        printf("\n\n");
        }
    }
    PressEnter;

    printf("8,9\n  函数 PostThreading_Thr PosOrderThreading_Thr测试\n");
    {
    printf("将T3后继线索化我Thrt3 \n");
    PosOrderThreading_Thr(&Thrt3,T3);
    printf("\n");
    }
    PressEnter;

    printf("10,12\n 函数PosOrderTraverse_Thr 等测试\n ");
    {
        printf("后序遍历Thrt3 = ");
        PosOrderTraverse_Thr(Thrt3,PrintElem);
        printf("\n\n");
    }
    PressEnter;
    return 0;
    }

    void PrintElem(TElemType_Thr e)
    {
    printf("%c ",e);
    }


