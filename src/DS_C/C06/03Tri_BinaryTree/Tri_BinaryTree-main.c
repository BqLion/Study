#include <stdio.h>
#include"Tri_BinaryTree.c"

void PrintElem(TElemType_Tri e);

int main(int argc,char *argv[])
{
        TBiTree T;

        printf("1\n ����InitBiTree_Tri ����...\n");
        {
        printf("��ʼ��һ���ն�����T ...\n");
        InitBiTree_Tri(&T);
        printf("\n");
        }
        PressEnter;

        printf("4\n ����BiTreeEmpty_Tri ����...\n");
        {
        BiTreeEmpty_Tri(T)?printf("TΪ��\n"):printf("T��Ϊ�գ�");
        printf("\n");
        }
        PressEnter;

        printf("5,6\n ����CreateBiTree_Tri �� ����...\n");
        {
            FILE *fp;
            printf("���������д���������T ...\n");
            printf("��Ϊʾ����¼���������У�ABDG^^^EH^^I^^CF^J^^^\n");
            fp = fopen("TestData_T.txt","r");
            CreateBiTree_Tri(fp,&T);
            fclose(fp);
            printf("\n");
        }
        PressEnter;

        printf("7,8\n ����BiTreeLength_Tri��BiTreeDepth_Tri ����...\n");
        {
        printf("T�ĳ���Ϊ��%d,���Ϊ %d \n",BiTreeDepth_Tri(T),BiTreeDepth_Tri(T));
        printf("\n");
        }
        PressEnter;

        printf("20\n ����LevelOrderTraverse_Tri ����...\n");
        {
        printf("������������� T = ");
        LevelOrderTraverse_Tri(T,PrintElem);
        printf("\n\n");

        }
        PressEnter;

        printf("21\n���� PreOrderTraverse_Tri����...\n");
        {
        printf("ǰ�����������T = ");
        PreOrderTraverse_Tri(T,PrintElem);
        printf("\n\n");
        }
        PressEnter;

        printf("22\n���� InOrderTraverse_Tri����...\n");
        {
        printf("�������������T = ");
        InOrderTraverse_Tri(T,PrintElem);
        printf("\n\n");

        }
        PressEnter;

        printf("23\n ����PostOrderTraverse_Tri ����...\n");
        {
            printf("�������������T = ");
            PostOrderTraverse_Tri(T,PrintElem);
            printf("\n\n");
        }
        PressEnter;

        printf("9\n ���� Root_Tri ����...\n");
        {
        TElemType_Tri e;

        Root_Tri(T,&e);
        printf("T�ĸ��ڵ�Ϊ %��\n,e");
        printf("\n");
        }
        PressEnter;

        printf("10\n ����Value_Tri����...\n");
        {
            TBiTree p;

            p = T->lchild->rchild->lchild;
            printf("ָ��pָ��Ľڵ�ֵΪ%c \n",Value_Tri(p));
            printf("\n");
        }
        PressEnter;

        printf("11\n ����Assign_Tri ����...\n");
        {
        TBiTree p;
        p = T->lchild->rchild->lchild;
        Assign_Tri(p,'X');
        printf("����X����ֵ��pָ��Ľ���T=\n");
        Print_Tri(T);
        printf("\n");
        }
        PressEnter;

        printf("12,13\n ���� Point��Parent����...\n");
        {
        printf("'X'��˫��Ϊ ��%c \n",Parent_Tri(T,'X'));
        printf("\n");
        }
        PressEnter;

        printf("14,15\n ����LeftChild_Tri,RightChild_Tri����...\n");
        {
        printf("'E'�����ӽڵ�ֵΪ��%c ���Һ��ӵĽڵ�ֵΪ%c\n",LeftChild_Tri(T,'E'),RightChild_Tri(T,'E'));
        printf("\n");
        }
        PressEnter;

        printf("16\n ����LeftSibling_Tri ����...\n");
        {
        printf("'I'�����ֵ�Ϊ: %c\n",LeftSibling_Tri(T,'I'));
        printf("\n");
        }
        PressEnter;

        printf("17\n ����RightSibling_Tri ����...\n");
        {
        printf("'X' �����ֵ�Ϊ��%c\n",RightSibling_Tri(T,'X'));
        printf("\n");
        }
        PressEnter;

        printf("18\n ����InsertBiTree_Tri ����...\n");
        {
            FILE *fp;
            TBiTree T0;

            printf("��������ӡ������ T0 = \n");
            InitBiTree_Tri(&T0);
            fp = fopen("TestData_T0.txt","r");
            CreateBiTree_Tri(fp,&T0);
            fclose(fp);
            Print_Tri(T0);
            printf("��T0 ���뵽T�г�Ϊ�ڵ�E����������T = \n");
            InsertBiTree_Tri(T,'E',&T0,0);
            Print_Tri(T);
            printf("\n");
        }
        PressEnter;

        printf("19\n ����DeleteBiTree_Tri����...\n");
        {
            printf("ɾ���ڵ�1 ���Һ��ӽڵ��,T = \n");
            DeleteBiTree_Tri(T,'1',1);
            Print_Tri(T);
            printf("\n");

        }
        PressEnter;

        printf("2\n ���� ClearBiTree_Tri ����...\n");
        {
        ClearBiTree_Tri(&T);
        if(BiTreeEmpty_Tri(T))
        printf("T�Ѿ�����գ�\n");
        printf("\n");
        }
        PressEnter;

        return 0;

        }

void  PrintElem(TElemType_Tri e)
{
printf("%c ",e);
}
