//06数和二叉树测试

#include<stdio.h>
#include"BinaryTree.c"

void PrintElem(TElemType e);
Status PrintElement(TElemType e);

int main(int argc,char *argv[])
{
    BiTree T;

    printf("1\n 函数InitBiTree测试...\n");
    {
    printf("初始化一个空二叉树 T...\n");
    InitBiTree(&T);
    printf("\n");
    }
    PressEnter;

    printf("4\n函数BiTeeEmpty测试...\n");
    {
        BiTreeEmpty(T)?printf("T为空！\n"):printf("T不为空！！\n");
        printf("\n");
    }
    PressEnter;

    printf("5\n 函数CreateBiTree_Sq 测试...\n");
    {
        FILE *fp;

        printf("按先序序列创建二叉树...\n");
        printf("作为示范，录入先序序列：ABDG^^^EH^^I^^CF^J^^^\n");
        fp = fopen("TestData_T.txt","r");
        CreateBiTree(fp,&T);
        fclose(fp);
        printf("\n");
    }
    PressEnter;

    printf("23\n函数PrintTree 测试...\n");
    {
    printf("按二叉树的逻辑结构打印树:...\n");
    PrintTree(T);
    printf("\n");
    }
    PressEnter;

    printf("19\n函数LevelOrderTraverse测试...\n");
    {
        printf("层序遍历二叉树 T = ");
        LevelOrderTraverse(T,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    printf("20-1函数PreOrderTraverse_1测试...\n");
    {
    printf("前序遍历二叉树 T= ");
    PreOrderTraverse_1(T,PrintElem);
    printf("\n\n");

    }
    PressEnter;

    printf("20-2函数PreOrderTraverse_1测试...\n");
    {
    printf("前序遍历二叉树 T= ");
    PreOrderTraverse_2(T,PrintElem);
    printf("\n\n");

    }
    PressEnter;

    printf("21-1函数InOrderTraverse_1测试...\n");
    {
    printf("中序遍历二叉树 T= ");
    InOrderTraverse_1(T,PrintElem);
    printf("\n\n");
    }
    PressEnter;

    printf("22\n 函数PostOrderTraverse测试...\n");
    {
    printf("后序遍历二叉树 T= ");
    PreOrderTraverse_1(T,PrintElem);
    printf("\n\n");
    }
    PressEnter;

    printf("8\n 函数Root测试...\n");
    {
        TElemType e;

        Root(T,&e);
        printf("T的根节点为 :%c \n",e);
        printf("\n");
    }
    PressEnter;

    printf("9\n函数value 测试...\n");
    {
        BiTree p = T->lchild->rchild->lchild;

        printf("指针p指向的节点值为 %c \n",Value(p));
        printf("\n");

    }
    PressEnter;

    printf("10\n 函数Assign 测试...\n");
    {
    BiTree p = T->lchild->rchild->lchild;

    Assign(p,'X');
    printf("将 ’X‘赋值给p指向的结点后，T=\n");
    PrintTree(T);
    printf("\n");
    }
    PressEnter;

    printf("11\n 函数Parent测试...\n");
    {
    printf("'X'节点的双亲为%c \n",Parent(T,'X'));
    printf("\n");
    }
    PressEnter;

    printf("12,13 函数LeftChild,RightChild 测试...\n");
    {
    printf("'I'的左兄弟为 %c \n",LeftSibling(T,'I'));
    printf("\n");
    }
    PressEnter;

    printf("14\n  函数LeftSibling 测试...\n");
    {
    printf("'I'的左兄弟为：%c\n",LeftSibling(T,'I'));
    printf("\n");
    }
    PressEnter;

    printf("15\n  函数RightSibling 测试...\n");
    {
    printf("'I'的右兄弟为：%c\n",RightSibling(T,'X'));
    printf("\n");
    }
    PressEnter;

    printf("16-1  17\n 函数InsertBiTree等测试...\n");
    {
    FILE *fp;
    BiTree T0;

    printf("创建并打印二叉树 T0 = \n");
    InitBiTree(&T0);
    fp = fopen("TestData_T0.txt","r");
    CreateBiTree(fp,&T0);
    fclose(fp);
    PrintTree(T0);
    printf("将T0插入到T中成为节点‘E’的左子树后，T = \n");
    InsertBiTree(T,'E',T0,0);
    PrintTree(T);
    printf("\n");

    }
    PressEnter;

    printf("16-2,18 \n 函数DeleteBiTree等测试...\n");
    {
    printf("删除节点1 的右孩子后，T = \n");
    DeleteBiTree(T,'1',1);

    PrintTree(T);
    printf("\n");
    }
    PressEnter;

    printf("2\n 函数ClearBiTree 测试...\n");
    {
    ClearBiTree(&T);
    if(BiTreeEmpty(T))
        printf("T已被清空!\n");
    printf("\n");
    }
    PressEnter;
    return 0;
}

void PrintElem(TElemType e)
{
printf("%c ",e);
}

Status PrintElement(TElemType e)
{
printf("%c ",e);
return OK;
}

