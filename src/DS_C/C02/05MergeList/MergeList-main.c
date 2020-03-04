/**************************************

�ļ��У�C02/05MergeList

���ݣ��������鲢��غ�������

*************************************/

#include <stdio.h>
#include"MergeList.c"

void PrintElem(LElemType_L e);

int main(int argc,char **argv)
{
    FILE *fp;
    LinkList La,Lb,Lc;
    int m;

    m = 5;

    printf("��Ϊʾ����La�����趨Ϊ%d��Lb�趨Ϊ%d������La��Lb...\n",m,m);
    fp = fopen("TestData_HL.txt","r");          //�ļ�ָ�룬ָ������Դ
    CreateList_HL(fp,&La,m);
    fclose(fp);
    fp = fopen("TestData_TL.txt","r");          //�ļ�ָ�룬ָ������Դ
    CreateList_TL(fp,&Lb,m);
    fclose(fp);

    printf("La = ");
    ListTraverse_L(La,PrintElem);
    printf("\n");
    printf("Lb = ");
    ListTraverse_L(Lb,PrintElem);
    printf("\n\n");
    PressEnter;

    MergeList_L(La,&Lb,&Lc);
    printf("�ϲ�La��LbΪLc = ");
    ListTraverse_L(Lc,PrintElem);
    printf("\n\n");
    PressEnter;
    system("pause");
    return 0;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);
}










