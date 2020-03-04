/************************************

文件夹： C02/04 SinglyLinkedList

内容：单链表相关函数测试

************************************/

#include <stdio.h>
#include"SinglyLinkedList.c"

//函数原型

Status CmpGreater(LElemType_L e,LElemType_L data);      //测试函数，判断data是否大于e，若data大于e，返回TRUE
void PrintElem(LElemType_L e);                          //测试函数，用于打印整形

int main(int argc,char **argv)
{
    LinkList L;
    int i;
    LElemType_L e;

    printf("1\n 函数InitList_L测试 ...");            //1.函数初始化函数initList_L测试
    {
          printf("初始化单链表...");
          InitList_L(&L);                               //调用初始化函数，参数是L的取址
          printf("\n");
    }
    PressEnter;

    printf("4\n函数 ListEmpty_L 测试...、n");        //4.函数ListEmpty_L测试
    {
        ListEmpty_L(L) ? printf("L为空！！\n") : printf("L不为空！");
        printf("\n");
    }
    PressEnter;

    printf("10\n 函数 ListInsert_L 测试...\n");         //10.函数ListInsert_L测试
    {
        for(i=1;i<=6;i++)
        {
            printf("在L的第%d个位置插入\“%d\"...\n",i,2*i);
            ListInsert_L(L,i,2*i);
        }
        printf("\n");
    }

    printf("12\n函数 ListTraverse_L 测试...\n");
    {
        printf("L中的元素为：L =  ");
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    printf("5\n函数 ListLength_L 测试... \n");          //5.函数ListLegnth_L测试
    {
        printf(" L的长度为 %d \n",ListLength_L(L));
        printf("\n");
    }
    PressEnter;

    printf("11\n 函数 ListDelete_L测试... \n");     //函数ListDelete_L测试
    {
        ListDelete_L(L,6,&e);                       //删除第六个元素，并把删除的数值放在e中
        printf("删除L中第六个元素\ “%d\"...\n",e);
        printf("L中的第六个元素为 L：");
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    printf("6\n 函数GetElem_L测试...\n");
    {
        GetElem_L(L,4,&e);
        printf("L中第四个位置的元素为\"%d\" \n",e);
        printf("\n");
    }
    PressEnter;

    printf("7\n 函数 LocateElem_L测试...\n");           //7.函数LocateElem_L测试
    {
        i = LocateElem_L(L,7,CmpGreater);
        printf("L中第一个元素值大于\"7\"的元素位置为 %d \n",i);
        printf("\n");
    }
    PressEnter;

    printf("8\n函数 PriorElem_L 测试... \n");       //8 函数PriorElem_L测试
    {
        PriorELem_L(L,6,&e);
        printf("元素 \"6\"的前驱为\"%d\" \n",e);
        printf("\n");
    }
    PressEnter;

    printf("2 \n函数ClearList_L 测试... \n");       //2 函数ClearList_L测试
    {
        printf("清空L 前：");
        ListEmpty_L(L) ? printf("L为空！！\n") : printf("L不为空！！\n");        //a?b:c  就是说如果满足条件a则执行b否则执行c
        ClearList_L(L);
        printf("清空L后：");
        ListEmpty_L(L) ? printf("L为空！！\n") :  printf("L不为空！！\n");
    }
    PressEnter;

    printf("13 \n 函数CreateList_HL 测试...\n");        //头插入法建立单链表函数测试。回顾头插法：1.p指针指向头结点。2.q指针指向待插入的元素。3. q.next=p.next;p.next=q
    {
        FILE *fp;                                         //FILE是一个struct，被包含定义在<stdio.h>中
        LinkList L;
        printf("头插法建立单链表L = ");
        fp = fopen("TestData_HL.txt","r");              //fp变量被赋值为 测试文档传进来的数据
        CreateList_HL(fp,&L,5);                         //创建链表，地址为L，长度为5
        fclose(fp);                                     //关闭打开的文档
        ListTraverse_L(L,PrintElem);                    //遍历并打印各个元素
        printf("\n\n");
    }
    PressEnter;

    printf("14 \n 函数CreateList_TL 测试...\n");        //14 函数CreateList_TL测试
    {
        FILE *fp;
        LinkList L;
        printf("尾插法建立单链表L = ");
        fp = fopen("TestData_TL.txt","r");               //文件指针，指向待打开的数据源
        CreateList_TL(fp,&L,5);
        fclose(fp);
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    system("pause");
    return 0;

}   //main函数结束

Status CmpGreater(LElemType_L e,LElemType_L data)
{
    return data>e ? TRUE:FALSE;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);
}


















