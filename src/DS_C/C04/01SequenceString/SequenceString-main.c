/***************************

������غ�������

***************************/

#include <stdio.h>
#include"SequenceString.c"

int main(int argc,char **argv)
{
    char *chars = "abcdefg";
    char *t = "***";
    char *v = "^^^^^";
    SString S,Tmp,T,V,Sub;
    int i;

    printf("1\n����StrAssign_Sq ����...\n");
    {
    printf("Ϊ˳��Tmp��ֵ...\n");
    StrAssign_Sq(Tmp,chars);
    printf("\n");
    }
    PressEnter;

    printf("5\n ���� StrLength_Sq ����...\n");
    {
    i = StrLength_Sq(Tmp);
    printf("Tmp�ĳ���Ϊ %d \n",i);
    printf("\n");
    }
    PressEnter;

    printf("14\n ����StrPrint_Sq ����...\n");
    {
        printf("Tmp�е�Ԫ��Ϊ:Tmp = ");
        StrPrint_Sq(Tmp);
        printf("\n\n");
    }
    PressEnter;

    printf("2\n ����StrCopy_Sq����...\n");
    {
    printf("����Tmp��S...\n");
    StrCopy_Sq(S,Tmp);
    printf("S�е�Ԫ��Ϊ:S = ");
    StrPrint_Sq(S);
    printf("\n\n");
    }
    PressEnter;

    printf("4\n����StrCompare_Sq ����...\n");
    {
        printf("�Ƚ��ַ���Tmp ��S...\n");
        i= StrCompare_Sq(Tmp,S);
        i = 0?printf("Tmp==S!!\n"):(i<0?printf("Tmp<S!!\n"):printf("Tmp>S!!\n"));
        printf("\n");
    }
    PressEnter;

    printf("11\n ����StrInsert_Sq����...\n");
    {
    printf("��\"***\" ����T...\n");
    StrAssign_Sq(T,t);
    printf("��S�ĵ�5���ַ�ǰ����T...\n");
    StrInsert_Sq(S,5,T);
    printf("S�е�Ԫ��Ϊ:S = ");
    StrPrint_Sq(S);
    printf("\n\n");
    }
    PressEnter;

    printf("9\n����Index_Sq_1����...\n");
    {
    printf("��ȡ�ַ���\"***\"��S�е�1���ַ�����ĵ�һ�γ��ֵ�λ��...\n");
    i = Index_Sq_1(S,T,1);
    printf("\"***\" ��S�е�1���ַ����һ�γ��ֵ�λ��Ϊ%d \n",i);
    printf("\n");
    }
    PressEnter;

    printf("8\n ����SubString_Sq ����...\n");
    {
    printf("��Sub����S�е�5���ַ���ĵ������ַ�...\n");
    printf("Sub�е�Ԫ��Ϊ:Sub = ");
    StrPrint_Sq(Sub);
    printf("\n\n");
    }
    PressEnter;

    printf("10\n ����Replace_Sq��index_Sq_2����...\n");
    {
    printf("��\"^^^^^\" ��ֵ��V...\n");
    StrAssign_Sq(V,v);
    printf("��\"^^^^^^\" �滻S�е�\"***\" ...\n");
    Replace_Sq(S,T,V);
    printf("S�е�Ԫ��Ϊ:S = ");
    StrPrint_Sq(S);
    printf("\n\n");
    }
    PressEnter;

    printf("12\n ����StrDelete_Sq ����...\n");
    {
    printf("ɾ��S�е�5���ַ����4���ַ�...\n");
    StrDelete_Sq(S,5,4);
    printf("S�е�Ԫ��ΪS= ");
    StrPrint_Sq(S);
    printf("\n\n");
    }
    PressEnter;

    printf("6\n���� ClearString_Sq ����...\n");
    {
    printf("���Sǰ��");
    StrEmpty_Sq(S)?printf("Ϊ�գ���\n"):printf("S��Ϊ�գ�\n");
    ClearString_Sq(S);
    printf("���S��");
    StrEmpty_Sq(S)?printf("SΪ�գ���\n"):printf("S��Ϊ�գ�");
    printf("\n");
    }
    PressEnter;

    printf("7\n����Concat_Sq ����...\n");
    {
        printf("����T��V�γ�Tmp ...\n");
        Concat_Sq(Tmp,T,V);
        printf("Tmp�е�Ԫ��Ϊ��Tmp= ");
        StrPrint_Sq(Tmp);
        printf("\n\n");
    }
    PressEnter;

    return 0;
}
