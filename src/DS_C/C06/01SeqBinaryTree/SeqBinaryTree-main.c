//二叉树函数测试

#include<stdio.h>
#include"SeqBinaryTree.c"

void PrintElem(char c);

int main(int argc,char *argv[])
{
    SqBiTree T;

    printf("1\n 函数InitBiTree_Sq 测试...\n");
    {
    printf("初始化空二叉树T...\n");
    InitBiTree_Sq(T);
    printf("\n");

    }
PressEnter;

printf("4\n函数BiTreeEmpty_Sq 测试...\n");
{
    BiTreeEmpty_Sq(T)?printf("T为空！\n"):printf("T 不为空！！\n");
    printf("\n");

}
PressEnter;

printf("5\n 函数 CreateBiTree_Le_Sq测试 ...\n");
{
    FILE *fp;

    printf("按照层序序列创建二叉树T ...\n");
    fp = fopen("TestData_Le.txt","r");
    CreateBiTree_Le_Sq(fp,T);
    fclose(fp);
    printf("\n");

}
PressEnter;

printf("29\n函数Print_Sq 测试...\n");
{
    printf("按二叉树的结构打印树T...\n");
    Print_Sq(T);
    printf("\n");


}
PressEnter;

printf("7,8 函数BiTreeLength_Sq /BiTreeDepth_Sq测试....\n");
{
    printf("T的长度为:%d，深度为:%d。\n ",BiTreeLength_Sq(T),BiTreeDepth_Sq(T));
    printf("\n");

}
PressEnter;


printf("17\n函数 LevelOrderTraverse_Sq测试 ...\n");
{
    printf("层序遍历二叉树 T = ");
    LevelOrderTraverse_Sq(T,PrintElem);
    printf("\n\n");

}
PressEnter;

printf("18\n 函数PreOrderTraverse_Sq 等测试...\n");
{
    printf("前序遍历二叉树 T = ");
    PreOrderTraverse_Sq(T,PrintElem,0);
    printf("\n\n");
}
PressEnter;

printf("19\n 函数InOrderTraverse_Sq 测试...\n");
{
    printf("中序遍历二叉树T = ");
    InOrderTraverse_Sq(T,PrintElem,0);
    printf("\n\n");
}
    PressEnter;

printf("20\n 函数PostOrderTraverse_Sq 等测试...\n");
{
    printf("后序遍历二叉树T = ");
    PostOrderTraverse_Sq(T,PrintElem,0);
    printf("\n\n");
}
PressEnter;

printf("9\n 函数Root_Sq 测试..\n");
{
    TElemType_Sq r;

    printf("T的根节点为 %c\n",r);
    Root_Sq(T,&r);
    printf("\n");


}
PressEnter;

printf("10\n 函数Value_Sq测试..\n");
{
Position p = {4,3};

printf("T中第%d 行第 %d列的值为 %c \n",p.level,p.order,Value_Sq(T,p));
printf("\n");

}
PressEnter;

printf("11\n 函数Assign_Sq 测试 ...\n");
{
    Position p ={4,3};

    printf("将%d层第%d列的结点赋值为 ‘X’后，T= \n ",p.level,p.order);
    Assign_Sq(T,p,'X');
    Print_Sq(T);
    printf("\n");


}
PressEnter;

printf("12\n 函数 Parent_Sq  测试...\n");
{
    printf("'X'结点的parents 为： %c \n",Parent_Sq(T,'X'));
    printf("\n");

}
PressEnter;

printf("13,14 \n 函数LeftChild_Sq,RightChild_Sq测试....");
{
    printf("'E' 的左孩子结点值为：%c,右孩子结点值为:%c\n",LeftChild_Sq(T,'E'),RightChild_Sq(T,'E'));
    printf("\n");


}
PressEnter;

printf("15\n 函数 LeftSibling_Sq测试...\n");
{
    printf("'I'的左兄弟为：%c\n",LeftSibling_Sq(T,'I'));
    printf("\n");

}
PressEnter;

printf("16\n 函数 RightSibling_Sq测试...\n");
{
    printf("'X'的右兄弟为：%c\n",RightSibling_Sq(T,'X'));
    printf("\n");

}
PressEnter;

printf("2\n 函数 ClearBiTree_Sq测试...\n");
{
    ClearBiTree_Sq(T);
    if(BiTreeEmpty_Sq(T))
    printf("T已被清空!\n");
    printf("\n");

}
PressEnter;

return 0;
}

void PrintElem(char c)
{
printf("%c ",c);
}
