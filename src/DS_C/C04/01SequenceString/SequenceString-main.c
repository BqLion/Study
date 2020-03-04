/***************************

串的相关函数测试

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

    printf("1\n函数StrAssign_Sq 测试...\n");
    {
    printf("为顺序串Tmp赋值...\n");
    StrAssign_Sq(Tmp,chars);
    printf("\n");
    }
    PressEnter;

    printf("5\n 函数 StrLength_Sq 测试...\n");
    {
    i = StrLength_Sq(Tmp);
    printf("Tmp的长度为 %d \n",i);
    printf("\n");
    }
    PressEnter;

    printf("14\n 函数StrPrint_Sq 测试...\n");
    {
        printf("Tmp中的元素为:Tmp = ");
        StrPrint_Sq(Tmp);
        printf("\n\n");
    }
    PressEnter;

    printf("2\n 函数StrCopy_Sq测试...\n");
    {
    printf("复制Tmp到S...\n");
    StrCopy_Sq(S,Tmp);
    printf("S中的元素为:S = ");
    StrPrint_Sq(S);
    printf("\n\n");
    }
    PressEnter;

    printf("4\n函数StrCompare_Sq 测试...\n");
    {
        printf("比较字符串Tmp 、S...\n");
        i= StrCompare_Sq(Tmp,S);
        i = 0?printf("Tmp==S!!\n"):(i<0?printf("Tmp<S!!\n"):printf("Tmp>S!!\n"));
        printf("\n");
    }
    PressEnter;

    printf("11\n 函数StrInsert_Sq测试...\n");
    {
    printf("将\"***\" 赋给T...\n");
    StrAssign_Sq(T,t);
    printf("在S的第5个字符前插入T...\n");
    StrInsert_Sq(S,5,T);
    printf("S中的元素为:S = ");
    StrPrint_Sq(S);
    printf("\n\n");
    }
    PressEnter;

    printf("9\n函数Index_Sq_1测试...\n");
    {
    printf("获取字符串\"***\"在S中第1个字符算起的第一次出现的位置...\n");
    i = Index_Sq_1(S,T,1);
    printf("\"***\" 在S中第1个字符后第一次出现的位置为%d \n",i);
    printf("\n");
    }
    PressEnter;

    printf("8\n 函数SubString_Sq 测试...\n");
    {
    printf("用Sub返回S中第5个字符起的第三个字符...\n");
    printf("Sub中的元素为:Sub = ");
    StrPrint_Sq(Sub);
    printf("\n\n");
    }
    PressEnter;

    printf("10\n 函数Replace_Sq、index_Sq_2测试...\n");
    {
    printf("将\"^^^^^\" 赋值给V...\n");
    StrAssign_Sq(V,v);
    printf("用\"^^^^^^\" 替换S中的\"***\" ...\n");
    Replace_Sq(S,T,V);
    printf("S中的元素为:S = ");
    StrPrint_Sq(S);
    printf("\n\n");
    }
    PressEnter;

    printf("12\n 函数StrDelete_Sq 测试...\n");
    {
    printf("删除S中第5个字符起的4个字符...\n");
    StrDelete_Sq(S,5,4);
    printf("S中的元素为S= ");
    StrPrint_Sq(S);
    printf("\n\n");
    }
    PressEnter;

    printf("6\n函数 ClearString_Sq 测试...\n");
    {
    printf("清空S前：");
    StrEmpty_Sq(S)?printf("为空！！\n"):printf("S不为空！\n");
    ClearString_Sq(S);
    printf("清空S后：");
    StrEmpty_Sq(S)?printf("S为空！！\n"):printf("S不为空！");
    printf("\n");
    }
    PressEnter;

    printf("7\n函数Concat_Sq 测试...\n");
    {
        printf("连接T和V形成Tmp ...\n");
        Concat_Sq(Tmp,T,V);
        printf("Tmp中的元素为：Tmp= ");
        StrPrint_Sq(Tmp);
        printf("\n\n");
    }
    PressEnter;

    return 0;
}
