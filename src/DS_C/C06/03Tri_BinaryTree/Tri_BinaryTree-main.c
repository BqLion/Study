#include <stdio.h>
#include"Tri_BinaryTree.c"

void PrintElem(TElemType_Tri e);

int main(int argc,char *argv[])
{
        TBiTree T;

        printf("1\n 函数InitBiTree_Tri 测试...\n");
        {
        printf("初始化一个空二叉树T ...\n");
        InitBiTree_Tri(&T);
        printf("\n");
        }
        PressEnter;

        printf("4\n 函数BiTreeEmpty_Tri 测试...\n");
        {
        BiTreeEmpty_Tri(T)?printf("T为空\n"):printf("T不为空！");
        printf("\n");
        }
        PressEnter;

        printf("5,6\n 函数CreateBiTree_Tri 等 测试...\n");
        {
            FILE *fp;
            printf("按先序序列创建二叉树T ...\n");
            printf("作为示范，录入先序序列：ABDG^^^EH^^I^^CF^J^^^\n");
            fp = fopen("TestData_T.txt","r");
            CreateBiTree_Tri(fp,&T);
            fclose(fp);
            printf("\n");
        }
        PressEnter;

        printf("7,8\n 函数BiTreeLength_Tri、BiTreeDepth_Tri 测试...\n");
        {
        printf("T的长度为：%d,深度为 %d \n",BiTreeDepth_Tri(T),BiTreeDepth_Tri(T));
        printf("\n");
        }
        PressEnter;

        printf("20\n 函数LevelOrderTraverse_Tri 测试...\n");
        {
        printf("层序遍历二叉树 T = ");
        LevelOrderTraverse_Tri(T,PrintElem);
        printf("\n\n");

        }
        PressEnter;

        printf("21\n函数 PreOrderTraverse_Tri测试...\n");
        {
        printf("前序遍历二叉树T = ");
        PreOrderTraverse_Tri(T,PrintElem);
        printf("\n\n");
        }
        PressEnter;

        printf("22\n函数 InOrderTraverse_Tri测试...\n");
        {
        printf("中序遍历二叉树T = ");
        InOrderTraverse_Tri(T,PrintElem);
        printf("\n\n");

        }
        PressEnter;

        printf("23\n 函数PostOrderTraverse_Tri 测试...\n");
        {
            printf("后序遍历二叉树T = ");
            PostOrderTraverse_Tri(T,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("9\n 函数 Root_Tri 测试...\n");
        {
        TElemType_Tri e;

        Root_Tri(T,&e);
        printf("T的根节点为 %从\n,e");
        printf("\n");
        }
        PressEnter;

        printf("10\n 函数Value_Tri测试...\n");
        {
            TBiTree p;

            p = T->lchild->rchild->lchild;
            printf("指针p指向的节点值为%c \n",Value_Tri(p));
            printf("\n");
        }
        PressEnter;

        printf("11\n 函数Assign_Tri 测试...\n");
        {
        TBiTree p;
        p = T->lchild->rchild->lchild;
        Assign_Tri(p,'X');
        printf("将‘X’赋值给p指向的结点后，T=\n");
        Print_Tri(T);
        printf("\n");
        }
        PressEnter;

        printf("12,13\n 函数 Point，Parent测试...\n");
        {
        printf("'X'的双亲为 ：%c \n",Parent_Tri(T,'X'));
        printf("\n");
        }
        PressEnter;

        printf("14,15\n 函数LeftChild_Tri,RightChild_Tri测试...\n");
        {
        printf("'E'的左孩子节点值为：%c ，右孩子的节点值为%c\n",LeftChild_Tri(T,'E'),RightChild_Tri(T,'E'));
        printf("\n");
        }
        PressEnter;

        printf("16\n 函数LeftSibling_Tri 测试...\n");
        {
        printf("'I'的左兄弟为: %c\n",LeftSibling_Tri(T,'I'));
        printf("\n");
        }
        PressEnter;

        printf("17\n 函数RightSibling_Tri 测试...\n");
        {
        printf("'X' 的右兄弟为：%c\n",RightSibling_Tri(T,'X'));
        printf("\n");
        }
        PressEnter;

        printf("18\n 函数InsertBiTree_Tri 测试...\n");
        {
            FILE *fp;
            TBiTree T0;

            printf("创建并打印二叉树 T0 = \n");
            InitBiTree_Tri(&T0);
            fp = fopen("TestData_T0.txt","r");
            CreateBiTree_Tri(fp,&T0);
            fclose(fp);
            Print_Tri(T0);
            printf("将T0 插入到T中成为节点E的左子树后，T = \n");
            InsertBiTree_Tri(T,'E',&T0,0);
            Print_Tri(T);
            printf("\n");
        }
        PressEnter;

        printf("19\n 函数DeleteBiTree_Tri测试...\n");
        {
            printf("删除节点1 的右孩子节点后,T = \n");
            DeleteBiTree_Tri(T,'1',1);
            Print_Tri(T);
            printf("\n");

        }
        PressEnter;

        printf("2\n 函数 ClearBiTree_Tri 测试...\n");
        {
        ClearBiTree_Tri(&T);
        if(BiTreeEmpty_Tri(T))
        printf("T已经被清空！\n");
        printf("\n");
        }
        PressEnter;

        return 0;

        }

void  PrintElem(TElemType_Tri e)
{
printf("%c ",e);
}
