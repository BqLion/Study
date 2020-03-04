#include <stdio.h>
#include"MFSet.c"

int main(int argc,char *argv[])
{
    FILE *fp;
    MFSet S;

    printf("1\n ����Initial_mfset ����...\n");
    {
        printf("��ʼ�����ϣ���Ϊʾ��¼��ʮ��Ԫ�أ�...\n");
        fp = fopen("TestData_S.txt","r");
        Initial_mfset(fp,&S);
        fclose(fp);
        printf("��ʼ����ɣ����ڼ����зǿ��Ӽ�����������Ԫ��...\n");
        printf("\n");
    }
    PressEnter;

    printf("8,9 \n ����ShowSet_mfset �Ȳ���...\n");
    {
    printf("չʾ����S  = ");
    ShowSet_mfset(S);
    printf("\n");
    }
    PressEnter;

    printf("2,3,6,7\n ����EquivalenceClass_mfset_1�Ȳ���...\n");
    {
        Relation R1;

        printf("���ݵȼ۹�ϵ�����ȼ���...\n");
        printf("��Ϊʾ��¼��4����Ԫ��ϵ�磺{(1,2),(3,4),(5,6),(7,9)}...\n");
        fp = fopen("TestData_R1.txt","r");
        BuildRelation_mfset(fp,&R1);
        fclose(fp);
        EquivalenceClass_mfset_1(&S,R1);
        printf("չʾ�ȼ��� S = ");
        ShowSet_mfset(S);
        printf("\n");
    }
    PressEnter;

    printf("4,5,6,7-2����EquivalenceClass_MFSET_2�Ȳ���...\n");
    {
    Relation R2;

    printf("����ĳ���ϵĵȼ۹�ϵ������ȼ���...\n");
    printf("��Ϊʾ��¼��������Ԫ��ϵ�磺{��1,3������5,7��}...\n");
    fp = fopen("TestData_R2.txt","r");
    BuildRelation_mfset(fp,&R2);
    fclose(fp);
    EquivalenceClass_mfset_2(&S,R2);
    printf("չʾ�ȼ��� S=  ");
    ShowSet_mfset(S);
    printf("\n");
    }
    PressEnter;

    fclose(fp);
}


