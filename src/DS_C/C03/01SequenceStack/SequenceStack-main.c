/**************************************

文件夹C03/01Sequence
Stack

内容：顺序栈相关函数测试

*************************************/

#include<stdio.h>
#include"SequenceStack.c";

void PrintElem(SElemType_Sq e);

int main(int argc,char **argv)
{
    SqStack S;
    int i;
    SElemType_Sq e;

    printf("1\n 函数InitStack测试...\n");
    {
        printf("初始化顺序栈S ...\n");
        InitStack_Sq(&S);
        printf("\n");
    }
    PressEnter;

    printf("4\n 函数StackEmpty 测试...\n");
    {
        StackEmpty_Sq(S)?printf("S 为空！！！\n"):printf("S不为空！！！\n");
        printf("\n");
    }
    PressEnter;

    printf("7\n 函数Push测试...\n");
    {
        for(i=1;i<=6;i++)
        {
        printf("将 \"%2d\" 压入栈S ",2*i);
        Push_Sq(&S,2*i);
        printf("（累计第 %d 个元素）...\n",S.top-S.base);
        }
        printf("\n");
    }
        PressEnter;

        printf("9\n 函数 StackTraverse 测试...\n");
        {
            printf("S 中的元素为 :S = ");
            StackTraverse_Sq(S,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("8\n 函数Pop测试...\n");
        {
            Pop_Sq(&S,&e);
            printf("栈顶元素\"d\" 出栈...\n",e);
            printf("S中的元素为:S = ");
            StackTraverse_Sq(S,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("5\n 函数StackLength 测试...\n");
        {
            i = StackLength_Sq(S);
            printf("S的长度为 %d \n",i);
            printf("\n");
        }
        PressEnter;

        printf("6\n 函数GetTop 测试...\n");
        {
            GetTop_Sq(S,&e);
            printf("栈顶的元素的值为 \"%d\"   \n",e);
            printf("\n");
        }
        PressEnter;

        printf("3\n  函数ClearStack 测试...\n");
        {
            printf("清空S 前:");
            StackEmpty_Sq(S)?printf("S为空！！\n"):printf("S不为空！！\n");
            ClearStack_Sq(&S);
            printf("清空S后：");
            StackEmpty_Sq(S)?printf("S为空！！\n"):printf("S不为空！！\n");
        }
            PressEnter;

        printf("2 \n 函数DestroyStack 测试...\n");
        {
            printf("销毁S 前：");
            S.base!=NULL && S.top!=NULL ? printf("S  存在！ \n"):printf("S 不存在！！\n");
            DestroyStack_Sq(&S);
            printf("销毁S后:");
            S.base!=NULL && S.top!=NULL ?printf("S 存在！！\n"):printf("S 不存在！！\n");;
            printf("\n");
        }
        PressEnter;
        return 0;
}

void PrintElem(SElemType_Sq e)
{
    printf("%d ",e);

}




