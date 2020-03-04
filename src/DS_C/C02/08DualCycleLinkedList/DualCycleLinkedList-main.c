/*******************************

文件夹：C02/08DualCycleLinkedList

内容：双循环链表相关函数测试

*******************************/

#include<stdio.h>
#include"DualCycleLinkedList.c"

Status CmpGreater(LElemType_DC e,LElemType_DC data);        //CompareWhoisGreater 函数，若data>e，返回TRUE，否则返回FALSE
void PrintElem(LElemType_DC e);                         //测试函数，打印整形

int main(int argc,char**argv)
{
    DuLinkList L;
    int i;
    LElemType_DC e;

    printf("1.\n函数InitList_Dul 测试...\n");
    {
    printf("初始化双循环链表L...\n");
    InitList_Dul(&L);
    printf("\n");
    }
    PressEnter;

    printf("4.\n函数ListEmpty_Dul 测试...\n");
    {
        ListEmpty_Dul(L)?printf("L为空！！\n"):printf("L不为空！！\n");
        printf("\n");
    }
    PressEnter;


    printf("11.\n函数 ListInsert_Dul 测试...\n");
    {
        for(i=1;i<=6;i++)
        {
        printf("在L第%d 个位置插\"%d\"...\n",i,2*i);
        ListInsert_Dul(L,i,2*i);
        }
        ListTraverse_Dul(L,PrintElem);
        printf("\n");
    }
    PressEnter;

    //插入自己的测试insertDulN函数测试
    printf("VTVTVT\N 函数ListInsert_Duln 测试...\n");
    {

        ListInsert_Duln(L,4,100);
        ListTraverse_Dul(L,PrintElem);
        printf("\n");
    }
    PressEnter;


    printf("13.\n 函数ListTraverse_Dul 测试...\n");
    {
        printf("L中的元素为：L = ");
        ListTraverse_Dul(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;


    printf("5.\n函数ListLength_Dul测试...\n");
    {
        printf("L的长度为 %d \n",ListLength_Dul(L));
        printf("\n");
    }
    PressEnter;

    printf("12.\n函数 ListDelete_Dul 测试...\n");
    {
        ListDelete_Dul(L,6,&e);
        printf("删除L中第六个元素\"%d\"并把删除的数据保存在e中...\n ",e);
        printf("L中的元素为 L = ");
        ListTraverse_Dul(L,PrintElem);
        printf("\n\n");

    }
    PressEnter;

    printf("6.\n函数GetElem_Dul 测试...\n");
    {
        GetElem_Dul(L,4,&e);
        printf("L中第4个位置的元素为 \"%d\"\n",e);
        printf("\n");
    }
    PressEnter;

    printf("7.\n 函数LocateElem_Dul 测试...\n");
    {
        i = LocateElem_Dul(L,7,CmpGreater);
        printf("L中第一个元素值大于\"7\"的元素的位置为 %d \n",i);
        printf("\n");
    }
    PressEnter;

    printf("8.\n函数 PriorElem_Dul 测试... \n");
    {
        PriorElem_Dul(L,6,&e);
        printf("元素 \"6\" 的前驱为 \"%d\" \n",e);
        printf("\n");
    }
    PressEnter;

    printf("10\n 函数 GetElem_P测试...\n");
    {
        DuLinkList p;
        p =GetElemPtr_Dul(L,3);
        printf("链表第三个节点的指针为 0x%x,其对应的值为 \"%d\"  \n",p,*p);
        printf("\n");
    }
    PressEnter;

    printf("3.\n 函数ClearList_Dul 测试...\n");
    {
        printf("清空L前：");
        ListEmpty_Dul(L)?printf("L为空！！\n") : printf("L不为空！！\n");
        ClearList_Dul(L);
        printf("清空L后：");
        ListEmpty_Dul(L)?printf("L为空！！\n") : printf("L不为空！！\n");
        printf("\n");
    }
        PressEnter;

    printf("2. \n函数DestroyList_Dul 测试...\n");
    {
        printf("销毁L前");
        L?printf("L存在"): printf("L不存在");
        DestroyList_Dul(&L);
         printf("销毁L后");
        L?printf("L存在") : printf("L不存在");
        printf("\n");
    }
    PressEnter;

    return 0;
    }

    Status CmpGreater(LElemType_DC e,LElemType_DC data)
    {
        return data>e ? TRUE:FALSE;
    }

    void PrintElem(LElemType_DC e)
    {
        printf("%d",e);

    }







