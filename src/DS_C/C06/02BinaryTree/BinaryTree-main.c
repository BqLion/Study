//06���Ͷ���������

#include<stdio.h>
#include"BinaryTree.c"

void PrintElem(TElemType e);
Status PrintElement(TElemType e);

int main(int argc,char *argv[])
{
    BiTree T;

    printf("1\n ����InitBiTree����...\n");
    {
    printf("��ʼ��һ���ն����� T...\n");
    InitBiTree(&T);
    printf("\n");
    }
    PressEnter;

    printf("4\n����BiTeeEmpty����...\n");
    {
        BiTreeEmpty(T)?printf("TΪ�գ�\n"):printf("T��Ϊ�գ���\n");
        printf("\n");
    }
    PressEnter;

    printf("5\n ����CreateBiTree_Sq ����...\n");
    {
        FILE *fp;

        printf("���������д���������...\n");
        printf("��Ϊʾ����¼���������У�ABDG^^^EH^^I^^CF^J^^^\n");
        fp = fopen("TestData_T.txt","r");
        CreateBiTree(fp,&T);
        fclose(fp);
        printf("\n");
    }
    PressEnter;

    printf("23\n����PrintTree ����...\n");
    {
    printf("�����������߼��ṹ��ӡ��:...\n");
    PrintTree(T);
    printf("\n");
    }
    PressEnter;

    printf("19\n����LevelOrderTraverse����...\n");
    {
        printf("������������� T = ");
        LevelOrderTraverse(T,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    printf("20-1����PreOrderTraverse_1����...\n");
    {
    printf("ǰ����������� T= ");
    PreOrderTraverse_1(T,PrintElem);
    printf("\n\n");

    }
    PressEnter;

    printf("20-2����PreOrderTraverse_1����...\n");
    {
    printf("ǰ����������� T= ");
    PreOrderTraverse_2(T,PrintElem);
    printf("\n\n");

    }
    PressEnter;

    printf("21-1����InOrderTraverse_1����...\n");
    {
    printf("������������� T= ");
    InOrderTraverse_1(T,PrintElem);
    printf("\n\n");
    }
    PressEnter;

    printf("22\n ����PostOrderTraverse����...\n");
    {
    printf("������������� T= ");
    PreOrderTraverse_1(T,PrintElem);
    printf("\n\n");
    }
    PressEnter;

    printf("8\n ����Root����...\n");
    {
        TElemType e;

        Root(T,&e);
        printf("T�ĸ��ڵ�Ϊ :%c \n",e);
        printf("\n");
    }
    PressEnter;

    printf("9\n����value ����...\n");
    {
        BiTree p = T->lchild->rchild->lchild;

        printf("ָ��pָ��Ľڵ�ֵΪ %c \n",Value(p));
        printf("\n");

    }
    PressEnter;

    printf("10\n ����Assign ����...\n");
    {
    BiTree p = T->lchild->rchild->lchild;

    Assign(p,'X');
    printf("�� ��X����ֵ��pָ��Ľ���T=\n");
    PrintTree(T);
    printf("\n");
    }
    PressEnter;

    printf("11\n ����Parent����...\n");
    {
    printf("'X'�ڵ��˫��Ϊ%c \n",Parent(T,'X'));
    printf("\n");
    }
    PressEnter;

    printf("12,13 ����LeftChild,RightChild ����...\n");
    {
    printf("'I'�����ֵ�Ϊ %c \n",LeftSibling(T,'I'));
    printf("\n");
    }
    PressEnter;

    printf("14\n  ����LeftSibling ����...\n");
    {
    printf("'I'�����ֵ�Ϊ��%c\n",LeftSibling(T,'I'));
    printf("\n");
    }
    PressEnter;

    printf("15\n  ����RightSibling ����...\n");
    {
    printf("'I'�����ֵ�Ϊ��%c\n",RightSibling(T,'X'));
    printf("\n");
    }
    PressEnter;

    printf("16-1  17\n ����InsertBiTree�Ȳ���...\n");
    {
    FILE *fp;
    BiTree T0;

    printf("��������ӡ������ T0 = \n");
    InitBiTree(&T0);
    fp = fopen("TestData_T0.txt","r");
    CreateBiTree(fp,&T0);
    fclose(fp);
    PrintTree(T0);
    printf("��T0���뵽T�г�Ϊ�ڵ㡮E������������T = \n");
    InsertBiTree(T,'E',T0,0);
    PrintTree(T);
    printf("\n");

    }
    PressEnter;

    printf("16-2,18 \n ����DeleteBiTree�Ȳ���...\n");
    {
    printf("ɾ���ڵ�1 ���Һ��Ӻ�T = \n");
    DeleteBiTree(T,'1',1);

    PrintTree(T);
    printf("\n");
    }
    PressEnter;

    printf("2\n ����ClearBiTree ����...\n");
    {
    ClearBiTree(&T);
    if(BiTreeEmpty(T))
        printf("T�ѱ����!\n");
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

