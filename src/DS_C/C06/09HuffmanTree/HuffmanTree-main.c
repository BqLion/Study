#include<stdio.h>
#include"HuffmanTree.c"

int main(int argc,char *argv[])
{
    HuffmanTree HT;
    HuffmanCode HC;

    printf("1\n ����InitTree_HT ����....\n");
    {
        printf("��ʼ���������� HT...\n");
        InitTree_HT(&HT);
        printf("\n");
    }
    PressEnter;

    printf("2��3 ����CreateHuffmanTree_HT �Ȳ���...\n");
    {
    FILE *fp;

    printf("������������ HT ..\n");
    printf("��Ϊʾ��������˸��ڵ��Ȩֵ��5,29,7,8,14,23,3,11��....\n");
    fp = fopen("TestData_HT.txt","r");
    CreateHuffmanTree_HT(fp,&HT);
    fclose(fp);
    printf("\n");
    }
    PressEnter;

    printf("5\n ����ShowHuffmanTree_HT����...\n");
    {
    printf("չʾ�������� HT = \n");
    ShowHuffmanTree_HT(HT);
    printf("\n");
    }
    PressEnter;

    printf("4-2 \n ����HuffmanCodeing_HT_1 ����...\n");
    printf("�������������HC ...\n");
    HuffmanCodeing_HT_2(HT,&HC);
    printf("\n");
    PressEnter;

    printf("6\n ����ShowHuffmancode_HT ����...\n");
    printf("չʾ����������HC =  \n");
    ShowHuffmanCode_HT(HT,HC);
    printf("\n");
    PressEnter;
}
