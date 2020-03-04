#include<stdio.h>
#include"HuffmanTree.c"

int main(int argc,char *argv[])
{
    HuffmanTree HT;
    HuffmanCode HC;

    printf("1\n 函数InitTree_HT 测试....\n");
    {
        printf("初始化哈夫曼树 HT...\n");
        InitTree_HT(&HT);
        printf("\n");
    }
    PressEnter;

    printf("2、3 函数CreateHuffmanTree_HT 等测试...\n");
    {
    FILE *fp;

    printf("创建哈夫曼树 HT ..\n");
    printf("作为示范，输入八个节点的权值（5,29,7,8,14,23,3,11）....\n");
    fp = fopen("TestData_HT.txt","r");
    CreateHuffmanTree_HT(fp,&HT);
    fclose(fp);
    printf("\n");
    }
    PressEnter;

    printf("5\n 函数ShowHuffmanTree_HT测试...\n");
    {
    printf("展示哈夫曼树 HT = \n");
    ShowHuffmanTree_HT(HT);
    printf("\n");
    }
    PressEnter;

    printf("4-2 \n 函数HuffmanCodeing_HT_1 测试...\n");
    printf("计算哈夫曼编码HC ...\n");
    HuffmanCodeing_HT_2(HT,&HC);
    printf("\n");
    PressEnter;

    printf("6\n 函数ShowHuffmancode_HT 测试...\n");
    printf("展示哈夫曼编码HC =  \n");
    ShowHuffmanCode_HT(HT,HC);
    printf("\n");
    PressEnter;
}
