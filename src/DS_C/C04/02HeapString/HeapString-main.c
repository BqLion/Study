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

    printf("1\n 函数InitString_H 测试...\n");
    {
        printf("初始化空串Tmp ...\n");
        InitString_H(&Tmp);
        printf("\n");
    }
    PressEnter;

    printf("2\n 函数 StrAssign_H测试...\n");
    {
    printf("为Tmp赋值%s ...\n",chars);
    StrAssign_H(&Tmp,chars);
    printf("\n");
    }
    PressEnter;

    printf("4\n 函数 StrEmpty_H 测试...\n");
    {
        StrEmpty_H(Tmp)?printf("Tmp为空！！\n"):printf("tmp不为空！\n");
        printf("\n");
    }
        PressEnter;

    printf("6\n 函数StrLength_H测试...\n");
    {
     i = StrLength_H(Tmp);
     printf("Tmp 的长度为 %d \n",i);
     printf("\n");
    }
        PressEnter;

    printf("15\n 函数 StrPrint_H测试...\n");
    {
            printf("Tmp中的元素为:Tmp = ");
            StrPrint_H(Tmp);
            printf("\n\n");
    }
        PressEnter;

   printf("3\n 函数StrCopy_H 测试...\n");
   {
   printf("复制Tmp 到S...\n");
   StrCopy_H(&S,Tmp);
   printf("S中的元素为:S= ");
   StrPrint_H(S);
   printf("\n\n");
   }
   PressEnter;


   printf("5\n 函数StrCompare_H测试 ...\n");
   {
        printf("比较字符串Tmp 、S...\n");
        i = StrCompare_H(Tmp,S);
        i == 0?printf("Tmp==S!!\n"):(i<0?printf("Tmp<S!!!\n"):printf("Tmp>S!!\n"));
        printf("\n");
   }
   PressEnter;

   printf("10\n 函数 Index_H测试 ...\n");
   {
    printf("获取字符串\"***\" 在S中从第1个字符算起的第一次出现的位置...\n");
    i = Index_H(S,T,1);
    printf("\"***\" 在S中第1个字符后第一次出现的位置为%d \n",i);
    printf("\n");
   }
    PressEnter;

   printf("9\n 函数SubString_H测试...\n");
   {
   printf("将\"^^^\"复制为V  ...\n");
   StrAssign_H(&V,v);
   printf("用\"^^^^\" 替换S中的 \"***\"...\n");
   Replace_H(&S,T,V);

   printf("S中的元素为 ：S = ");
   StrPrint_H(S);
   printf("\n\n");
   }
    PressEnter;

    printf("7\n 函数 ClearString_H测试...\n");
    {
    printf("清空S前：");
    StrEmpty_H(S)?printf("S为空！！\n"):printf("S不为空！\n");
    ClearString_H(&S);
    printf("清空S后：");
    StrEmpty_H(S)?printf("S为空！！\n"):printf("S不为空！\n");
    printf("\n");
    }
    PressEnter;

    printf("8\n 函数Concat_H测试...\n");
    {
    printf(" 连接T和V形成Tmp...\n");
    Concat_H(&Tmp,T,V);
    printf("Tmp中的元素为：Tmp= ");
    StrPrint_H(Tmp);
    printf("\n\n");
    }
    PressEnter;
    return 0;
}
