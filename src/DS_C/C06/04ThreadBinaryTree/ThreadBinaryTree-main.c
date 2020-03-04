//�������Ĳ���

#include<stdio.h>
#include"ThreadBinaryTree.c"

void PrintElem(TElemType_Thr e);

int main(int argc,char *argv[])
{
    ThrBiTree Thrt1,Thrt2,Thrt3;
    ThrBiTree T1,T2,T3;
    int mark;

    printf("1\n����CreateBiTree_Thr ����...\n");
    {
        FILE *fp;

        printf("�����������д���������...\n");
        printf("��Ϊʾ����¼���������У�ABDG^^^EH^^I^^CF^J^^^\n");
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

    printf("2\n �������� �������������\n");
    {
        printf("5,6 \n ����PreThreading_Thr��PreOrderThreading_Thr ����\n");
        printf("��T1 ������������ΪThrt1\n");
        PreOrderThreading_Thr(&Thrt1,T1);
        printf("\n");
    }
    PressEnter;

    printf("\n ��������ȫ����������\n ");
    printf("\n ����InThreading_Thr,InOrderThreading_Thr����\n");
    {
    printf("��T2����ȫ������ΪThrt2 \n");
    InOrderThreading_Thr(&Thrt2,T2);
    printf("\n");
    }
    PressEnter;

    printf("4\n ����InOrderTraverse_Thr ����\n");
    {
        printf("��Ѯ���� Thrt2 = ");
        {
        InOrderTraverse_Thr(Thrt2,PrintElem);
        printf("\n\n");
        }
    }
    PressEnter;

    printf("8,9\n  ���� PostThreading_Thr PosOrderThreading_Thr����\n");
    {
    printf("��T3�����������Thrt3 \n");
    PosOrderThreading_Thr(&Thrt3,T3);
    printf("\n");
    }
    PressEnter;

    printf("10,12\n ����PosOrderTraverse_Thr �Ȳ���\n ");
    {
        printf("�������Thrt3 = ");
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


