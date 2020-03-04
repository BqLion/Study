/**************************

内容：树的孩子链表的存储

***************************/

#include<stdio.h>
#include"ChildTree.c"

void PrintElem(TElemType_C e);

int main(int argc,char *argv[])
{
    CTree T,T0;
    FILE *fp;
    printf("1\n 函数InitTree_C 测试...\n");
    {
    printf("初始化一颗空树……\n");
    fp = fopen("TestData_T.txt","r");
    InitTree_C(fp,&T);
    printf("\n");
    }
PressEnter;

printf("5\n 函数TreeEmpty_C测试...\n");
{
    TreeEmpty_C(T)?printf("T为空！\n"):printf("T不为空！！\n");
    printf("\n");
}
PressEnter;

printf("6\n 函数CreateTree_C测试...\n");
{
    CreateTree_C(fp,&T);
    fclose(fp);
    printf("\n");
}
PressEnter;

printf("22\n函数LevelOrderTraverse_C 测试...\n");
{
    printf("层序遍历树T = ");
    LevelOrderTraverse_C(T,PrintElem);
    printf("\n\n");
}
PressEnter;

printf("8-2 ,Print_C等测试...\n");
{
    printf("打印树 T = \n");
    Print_C_1(T);
    printf("\n");
}
PressEnter;

printf("24\n 函数ShowTree_T 测试...\n");
{
    printf("展示树的结构 T = \n");
    ShowTree_C(T);
    printf("\n");
}
PressEnter;

printf("7\n函数TreeDegree_C测试...\n");
{
printf("T的度为: %d \n",TreeDegree_C(T));
printf("\n");
}
PressEnter;

printf("8-1函数TreeDepth_C_1 测试...\n");
{
    printf("T共有%d 层\n",TreeDepth_C_1(T));
    printf("\n");
}
PressEnter;

printf("10\n 函数Root_C测试...\n");
{
    printf("T的根节点为： %c \n",Root_C(T));
    printf("\n");
}
PressEnter;

printf("11\n 函数Value_C 测试...\n");
{
    printf("T中第%d 个节点的值为%c \n",2,Value_C(T,2));
    printf("\n");
}
PressEnter;

printf("12\n函数Order_C 测试...\n");
{
    printf("T中元素%c 的位置为：%d \n",'A',Order_C(T,'A'));
    printf("\n");
}
PressEnter;

printf("13,23-2\n 函数Assign_C测试...\n");
{
    printf("将节点B 赋值为 X 后，T = \n");
    Assign_C(&T,'B','X');
    Print_C_2(T,T.r,0);
    printf("\n");
}
PressEnter;

printf("14\n 函数ChildValue_C测试...\n");
{
    printf("节点%c 第%d个孩子为：%c\n",'A',2,ChildValue_C(T,'A',2));
    printf("\n");
}
PressEnter;

printf("15-1,15-2\n 函数Sibling_C_1,Sibing_C_2测试...\n");
{
    printf("%c 的左兄弟为：%c,%c 的右兄弟为：%c\n",'E',Sibling_C_1(T,'E',0),'D',T.nodes[Sibling_C_1(T,'E',1)]);
    printf("\n");
}
PressEnter;

printf("函数16,17,18,19,20,InsertTree_C等测试...\n");
{
    printf("创建并打印T0...\n");
    fp = fopen("TestData_T0.txt","r");
    InitTree_C(fp,&T0);
    CreateTree_C(fp,&T0);
    fclose(fp);
    Print_C_1(T0);
    printf("\n");
    printf("将T0嫁接为%c的第%d棵子树后，T = ...\n",'X',1);
    InsertTree_C(&T,'X',1,T0);
    Print_C_1(T);
    printf("\n");
    ShowTree_C(T);
    printf("\n");
}
PressEnter;

printf("21\n 函数DeleteTree_C 测试...\n");
{
    printf("删除T中节点%c 的第%d棵子树后，T = \n",'0',3);
    DeleteTree_C(&T,'0',3);
    Print_C_1(T);
    printf("\n");
    ShowTree_C(T);
    printf("\n");
}
PressEnter;

printf("2,3\n 函数ClearTree_C 等测试...\n");
{
    ClearTree_C(&T);
    TreeEmpty_C(T)?printf("T为空！！\n"):printf("T不为空！！\n");
    printf("\n");
}
    PressEnter;
}

void PrintElem(TElemType_C e)
{
    printf("%c ",e);
}

