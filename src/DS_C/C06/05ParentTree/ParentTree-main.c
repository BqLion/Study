 /*********************

 树的双亲表示法相关函数测试

 *******************/

 #include<stdio.h>
 #include"ParentTree.c"

 void PrintElem(TElemType_P e);

 int main(int argc,char *argv[])
 {
    PTree T,T0;

    printf("1\n 函数 InitTree_P测试...\n");
    {
        InitTree_P(&T);
        printf("初始化空树T，根节点为止默认设为0...\n");
        printf("\n");
    }
    PressEnter;

    printf("4\n 函数TreeEmpty_P 测试...\n");
    {
    TreeEmpty_P(T)?printf("T为空！！\n"):printf("T不为空！！\n");
    printf("\n");
    }
    PressEnter;

    printf("5\n 函数CreateTree_P 测试...\n");
    {
        FILE *fp;

        fp=fopen("TestData_T.txt","r");
        CreateTree_P(fp,&T);
        fclose(fp);
        printf("\n");
    }
    PressEnter;

    printf("19\n 函数LevelOrderTraverse_P测试...\n");
    {
    printf("层序遍历树 T=");
    LevelOrderTraverse_P(T,PrintElem);
    printf("\n\n");
    }
    PressEnter;

    printf("20\m 函数Print_P 测试...\n");
    {
    printf("打印树 T = \n");
    Print_P(T);
    printf("\n");
    }
    PressEnter;

    printf("6\n 函数TreeDegree_P 测试...\n");
    {
    printf("T的度为：%d\n",TreeDegree_P(T));
    printf("\n");
    }
    PressEnter;

    printf("7\n 函数TreeDepth_P 测试...\n");
    {
    printf("T共有%d 层\n",TreeDepth_P(T));
    printf("\n");
    }
    PressEnter;

    printf("8\n 函数Root_P测试...\n");
    {
    printf("T 的跟节点为： %c \n",Root_P(T));
    printf("\n");
    }
    PressEnter;

    printf("9\n 函数Value_P测试\n");
    {
        printf("T中第%d个节点值为：%c\n",2,Value_P(T,2));
        printf("\n");
    }
    PressEnter;

    printf("10\n 函数 Order_P测试...\n");
    {
    printf("T中元素%c的位置为：%d\n",'A',Order_P(T,'A'));
    printf("\n");
    }
    PressEnter;

    printf("11\n 函数Assign_P测试...\n");
    {
    printf("将节点‘B’赋值为 ‘X’后，T= \n");
    Assign_P(&T,'B','X');
    Print_P(T);
    printf("\n");
    }
    PressEnter;

    printf("12\n 函数ChildValue_P测试...\n");
    {
    printf("%c 的第%d个孩子为：%c\n",'A',2,ChildValue_P(T,'A',2));
    printf("\n");
    }
    PressEnter;

    printf("13\n 函数Sibling_P 测试...\n");
    {
    printf("%c 的左兄弟为 %c,%c的右兄弟为:%c \n",'E',Sibling_P(T,'E',0),'D',Sibling_P(T,'E',0));
    printf("\n");
    }
    PressEnter;

    printf("14,15,16,17\n 函数 InsertTree_P等测试...\n");
    {
    FILE *fp;
    printf("创建并打印树T0 ...\n");
    InitTree_P(&T0);
    fp = fopen("TestData_T0.txt","r");
    CreateTree_P(fp,&T0);
    fclose(fp);
    Print_P(T0);
    printf("将树T0插入为树T中节点%c的第%d棵子树后，T = \n",'X',1);
    InsertTree_P(&T,'X',1,T0);
    Print_P(T);
    printf("\n");
    }
    PressEnter;

    printf("18\n 函数DeleteTree_P 测试 ...\n");
    {
    printf("删除T中节点%c的第%d棵子树后，T = \n",'0',3);
    DeleteTree_P(&T,'0',3);
    Print_P(T);
    printf("\n");
    }
    PressEnter;

    printf("2\n 函数ClearTree_P测试..\n");
    {
    ClearTree_P(&T);
    TreeEmpty_P(T)?printf("T为空！！\n"):printf("T不为空！\n");
    printf("\n");
    }
    PressEnter;
 }
 void PrintElem(TElemType_P e)
 {
    printf("%c ",e);
 }


