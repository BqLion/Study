/*********************************

文件夹：C02、线性表

内容：静态链表相关函数测试

***********************************/

#include <stdio.h>
#include"StaticLinkedList.c"        //包含之前的静态链表的头文件

void PrintElem(LElemType_S e);      //测试函数，用于打印整形

int main(int argc,char **argv)
{
        SLinkList H;
        LElemType_S e;
        int i;

        printf("1.\n函数InitSpace_SL测试...\n");                //测试始化SPACE函数
       {
        printf("初始化静态链表的备用空间SPACE...\n");
        InitSpace_SL();
        printf("\n");
       }
       PressEnter;

       printf("2.\n函数Malloc_SL,InitList_SL测试...\n");//函数malloc_SL,InitList_SL测试
        {
            printf("初始化静态链表H，用mallco_SL申请空间...\n");
            InitList_SL(&H);//在已经初始化好的SPACE空间上初始化SL表
            printf("\n");
        }
    PressEnter;

    printf("7.\n函数ListEmpty_SL测试...\n");            //4.测试探空函数ListEmpty_SL;
    {
    ListEmpty_SL(H)?printf("H为空！！\n"):printf("H不为空！...\n");
    printf("\n");
    }
    PressEnter;

    printf("13\n函数ListInsert_SL测试...\n");           //13函数ListInsert_SL测试
    {
        for(i=1;i<=6;i++)
        {
            printf("在H的第 %d 个位置插入\"%d\"  ...\n",i,2*i);
            ListInsert_SL(H,i,2*i);
        }
        printf("\n");
    }
    PressEnter;

    printf("15\n 函数ListTraverse_SL测试...\n");        //函数ListTraverse_SL测试
    {
            printf("H中的元素为：H=");
            ListTraverse_SL(H,PrintElem);
            printf("\n\n");
    }
    PressEnter;

    printf("8\n 函数ListLength_SL测试...\n");       //8函数ListLength_SL测试
    {
            printf("H的长度为%d\n",ListLength_SL(H));
            printf("\n");
    }
    PressEnter;

    printf("3、14\n函数Free_SL、ListDelete_SL测试...\n");     //3.14函数Free_SL/ListDelete_SL测试
    {
        ListDelete_SL(H,6,&e);
        printf("删除H中的第六个元素\"%d\",用Free_SL释放空间...\n",e);
        printf("H中的元素为 H= ");
        ListTraverse_SL(H,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    printf("9\n函数GetElem_SL测试...\n");       //9.函数GetElem_SL测试
    {
        GetElem_SL(H,4,&e);
        printf("H中第四个位置的元素为\“%d\" \n",e);
        printf("\n");
    }
    PressEnter;

    printf("10\n 函数LocateElem_SL测试...\n");      //10. 函数LocateElem_SL测试
    {
        printf("元素\"8\" 在H中的位序为 %d \n",LocateElem_SL(H,8));
        printf("\n");
    }
    PressEnter;

    printf("11\n函数PriorElem_SL测试...\n");        //11.函数PirorElem_SL测试
    {
        PriorElem_SL(H,6,&e);
        printf("元素 \“6\" 的前驱为 \"%d\"  \n",e);
        printf("\n");
    }
    PressEnter;

    printf("12\n函数NextElem_SL测试...\n");          //12.函数NextElem_SL测试
    {
        NextElem_SL(H,6,&e);
        printf("元素 \"6\"的后继为 \"%d\" \n",e);
        printf("\n");
    }
    PressEnter;

    printf("5\n 函数ClearList_SL测试...\n");        //5.函数ClearList_SL测试
    {
    printf("清空H前：");
    ListEmpty_SL(H)?printf("H为空！！\n"):printf("H 不为空！！\n");
    ClearList_SL(H);
    printf("清空H后");
    ListEmpty_SL(H)?printf("H 为空！！\n"):printf(" H 不为空！！\n");
    printf("\n");
    }
    PressEnter;

    printf("6\n 函数DestroyList_SL测试...\n");              //6.DestroyList_SL测试
    {
        printf("销毁 H 前");
        H ? printf(" H 存在！ \n"): printf(" H 不存在！！\n");
        DestroyLsit_SL(&H);
        printf("销毁H后：");
        H ? printf("H 存在！！\n"):printf("H不存在！！\n");
        printf("\n");
    }
        PressEnter;
    return 0;
}

void PrintElem(LElemType_S e)
{
    printf("%d",e);
}











