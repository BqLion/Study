//树的二叉链表（孩子兄弟表示法）存储相关测试

#include<stdio.h>
#include"ChildSiblingTree.c"

void PrintElem(TElemType_CS e);

int main(int argc,char *argv[])
{
    CSTree T;

    printf("1\n 函数InitTree_CS 测试...\n");
    {
    printf("初始化一颗空树T\n");
    InitTree_CS(&T);
    printf("\n");
    }
    PressEnter;

    printf("4\n 函数TreeEmpty_CS 测试..\n");
    {
    TreeEmpty_CS(T)?printf("T为空！！\n"):printf("T不为空！！\n");
    printf("\n");
    }
    PressEnter;

    printf("5\n 函数CreateTree_CS 测试...\n");
    {
    FILE *fp;
    printf("按照先序序列创建二叉树 T ...\n");
    printf("作为示例，录入先序序列 ：RAD^E^^B^CFG^H^K^^^^^...\n");
    fp = fopen("TestData_T.txt","r");
    CreateTree_CS(fp,&T);
    fclose(fp);
    printf("\n");
    }
    PressEnter;

    printf("21\n 函数Print_CS 测试...\n");
    {
    printf("按照树的结构打印树T = \n");
    Print_CS(T);
    printf("\n");
    }
    PressEnter;

    printf("18\n 函数LevelOrderTraverse_CS 测试\n");
    {
    printf("层序遍历树 T = ");
    LevelOrderTraverse_CS(T,PrintElem);
    printf("\n\n");
    }
    PressEnter;

    printf("19\n 函数 PreOrderTraverse_CS测试 ..\n");
    {
    printf("前序遍历树T = ");
    PreOrderTraverse_CS(T,PrintElem);
    printf("\n\n");
    }
    PressEnter;

    printf("20\n  函数InOrderTraverse_CS 测试...\n");
    {
    printf("中序遍历树T = ");
    InOrderTraverse_CS(T,PrintElem);
    printf("\n\n");
    }
    PressEnter;

    printf("6\n 函数TreeDegree_CS 测试...\n");
    {
    printf("T的度为:%d \n",TreeDegree_CS(T));
    printf("\n");
    }
    PressEnter;

    printf("7\n 函数TreeDeptrh_CS测试...\n");
    {
    printf("T 共有%d层\n",TreeDepth_CS(T));
    printf("\n");
    }
    PressEnter;

    printf("8\n函数Root_CS测试...\n");
    {
    printf("T的根节点为：%c \n",Root_CS(T));
    printf("\n");
    }
    PressEnter;

    printf("9\n 函数Value_CS 测试...\n");
    {
    printf("T中第%d 个节点的值为：%c\n",2,Value_CS(T,2));
    printf("\n");
    }
    PressEnter;

    printf("10\n函数Order_CS 测试...\n");
    {
    printf("T中元素%c的地址为： 0x%X \n",'A',Order_CS(T,'A'));
    printf("\n");
    }
    PressEnter;

    printf("11\n 函数Assign_CS 测试...\n");
    {
    printf("将节点‘B’赋值为‘X’后，T = \n");
    Assign_CS(T,'B','X');
    Print_CS(T);
    printf("\n");
    }
    PressEnter;

    printf("12\n 函数ChildValue_CS 测试...\n");
    {
    printf("节点 %c 的第%d个孩子为:%c\n",'A',2,ChildValue_CS(T,'A',2));
    printf("\n");
    }
    PressEnter;

    printf("13\n 函数Sibling_CS测试...\n");
    {
    printf("%c 的左兄弟为:%c ",'E',Sibling_CS(T,'E',0));
    printf("%c 的右兄弟为：%c \n",'D',Sibling_CS(T,'D',1));
    printf("\n");
    }
    PressEnter;

    printf("14,15,16\n 函数InsertTree_CS 等测试...\n");
    {
    FILE *fp;
    CSTree T0;

    printf("创建并打印树 T0...\n");
    InitTree_CS(&T0);
    printf("作为示例，录入先序序列：01^2^34^5^^^^...\n");
    fp = fopen("TestData_T0.txt","r");
    CreateTree_CS(fp,&T0);
    fclose(fp);
    Print_CS(T0);
    printf("将T0嫁接为 %c的第%d棵子树后，T = \n",'X',1);
    InsertTree_CS(T,'X',1,T0);
    Print_CS(T);
    printf("\n");
    }
    PressEnter;


printf("17\n 函数DeleteTree_CS 测试...\n");
{
    printf("删除 T中节点%c 的第%d棵子树后，T = \n",'0',3);
    DeleteTree_CS(T,'0',3);
    Print_CS(T);
    printf("\n");
}
PressEnter;

printf("2\n 函数ClearTree_CS等测试...\n");
{
    ClearTree_CS(&T);
    TreeEmpty_CS(T)?printf("T为空！\n"):printf("T不为空！！\n");
    printf("\n");
}
PressEnter;
}

void PrintElem(TElemType_CS e)
{
    printf("%c ",e);
}
