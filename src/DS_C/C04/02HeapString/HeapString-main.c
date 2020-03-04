//04/02HeapString

#include<stdio.h>
#include"HeapString.c"

int main(int argc,char **argv)
{
    char *chars = "abcdefg";
    char *t = "***";
    char *v = "^^^^";
    HString S,Tmp,T,V,Sub;
    int i;

    printf("1\n ����InitString_H ����...\n");
    {
        printf("��ʼ���մ�Tmp ...\n");
        InitString_H(&Tmp);
        printf("\n");
    }
    PressEnter;

    printf("2\n ���� StrAssign_H����...\n");
    {
    printf("ΪTmp��ֵ%s ...\n",chars);
    StrAssign_H(&Tmp,chars);
    printf("\n");
    }
    PressEnter;

    printf("4\n ���� StrEmpty_H ����...\n");
    {
        StrEmpty_H(Tmp)?printf("TmpΪ�գ���\n"):printf("tmp��Ϊ�գ�\n");
        printf("\n");
    }
        PressEnter;

    printf("6\n ����StrLength_H����...\n");
    {
     i = StrLength_H(Tmp);
     printf("Tmp �ĳ���Ϊ %d \n",i);
     printf("\n");
    }
        PressEnter;

    printf("15\n ���� StrPrint_H����...\n");
    {
            printf("Tmp�е�Ԫ��Ϊ:Tmp = ");
            StrPrint_H(Tmp);
            printf("\n\n");
    }
        PressEnter;

   printf("3\n ����StrCopy_H ����...\n");
   {
   printf("����Tmp ��S...\n");
   StrCopy_H(&S,Tmp);
   printf("S�е�Ԫ��Ϊ:S= ");
   StrPrint_H(S);
   printf("\n\n");
   }
   PressEnter;


   printf("5\n ����StrCompare_H���� ...\n");
   {
        printf("�Ƚ��ַ���Tmp ��S...\n");
        i = StrCompare_H(Tmp,S);
        i == 0?printf("Tmp==S!!\n"):(i<0?printf("Tmp<S!!!\n"):printf("Tmp>S!!\n"));
        printf("\n");
   }
   PressEnter;

   printf("10\n ���� Index_H���� ...\n");
   {
    printf("��ȡ�ַ���\"***\" ��S�дӵ�1���ַ�����ĵ�һ�γ��ֵ�λ��...\n");
    i = Index_H(S,T,1);
    printf("\"***\" ��S�е�1���ַ����һ�γ��ֵ�λ��Ϊ%d \n",i);
    printf("\n");
   }
    PressEnter;

   printf("9\n ����SubString_H����...\n");
   {
   printf("��\"^^^\"����ΪV  ...\n");
   StrAssign_H(&V,v);
   printf("��\"^^^^\" �滻S�е� \"***\"...\n");
   Replace_H(&S,T,V);

   printf("S�е�Ԫ��Ϊ ��S = ");
   StrPrint_H(S);
   printf("\n\n");
   }
    PressEnter;

    printf("7\n ���� ClearString_H����...\n");
    {
    printf("���Sǰ��");
    StrEmpty_H(S)?printf("SΪ�գ���\n"):printf("S��Ϊ�գ�\n");
    ClearString_H(&S);
    printf("���S��");
    StrEmpty_H(S)?printf("SΪ�գ���\n"):printf("S��Ϊ�գ�\n");
    printf("\n");
    }
    PressEnter;

    printf("8\n ����Concat_H����...\n");
    {
    printf(" ����T��V�γ�Tmp...\n");
    Concat_H(&Tmp,T,V);
    printf("Tmp�е�Ԫ��Ϊ��Tmp= ");
    StrPrint_H(Tmp);
    printf("\n\n");
    }
    PressEnter;
    return 0;
}
