/**************************

���ݣ����ĺ�������Ĵ洢

***************************/

#include<stdio.h>
#include"ChildTree.c"

void PrintElem(TElemType_C e);

int main(int argc,char *argv[])
{
    CTree T,T0;
    FILE *fp;
    printf("1\n ����InitTree_C ����...\n");
    {
    printf("��ʼ��һ�ſ�������\n");
    fp = fopen("TestData_T.txt","r");
    InitTree_C(fp,&T);
    printf("\n");
    }
PressEnter;

printf("5\n ����TreeEmpty_C����...\n");
{
    TreeEmpty_C(T)?printf("TΪ�գ�\n"):printf("T��Ϊ�գ���\n");
    printf("\n");
}
PressEnter;

printf("6\n ����CreateTree_C����...\n");
{
    CreateTree_C(fp,&T);
    fclose(fp);
    printf("\n");
}
PressEnter;

printf("22\n����LevelOrderTraverse_C ����...\n");
{
    printf("���������T = ");
    LevelOrderTraverse_C(T,PrintElem);
    printf("\n\n");
}
PressEnter;

printf("8-2 ,Print_C�Ȳ���...\n");
{
    printf("��ӡ�� T = \n");
    Print_C_1(T);
    printf("\n");
}
PressEnter;

printf("24\n ����ShowTree_T ����...\n");
{
    printf("չʾ���Ľṹ T = \n");
    ShowTree_C(T);
    printf("\n");
}
PressEnter;

printf("7\n����TreeDegree_C����...\n");
{
printf("T�Ķ�Ϊ: %d \n",TreeDegree_C(T));
printf("\n");
}
PressEnter;

printf("8-1����TreeDepth_C_1 ����...\n");
{
    printf("T����%d ��\n",TreeDepth_C_1(T));
    printf("\n");
}
PressEnter;

printf("10\n ����Root_C����...\n");
{
    printf("T�ĸ��ڵ�Ϊ�� %c \n",Root_C(T));
    printf("\n");
}
PressEnter;

printf("11\n ����Value_C ����...\n");
{
    printf("T�е�%d ���ڵ��ֵΪ%c \n",2,Value_C(T,2));
    printf("\n");
}
PressEnter;

printf("12\n����Order_C ����...\n");
{
    printf("T��Ԫ��%c ��λ��Ϊ��%d \n",'A',Order_C(T,'A'));
    printf("\n");
}
PressEnter;

printf("13,23-2\n ����Assign_C����...\n");
{
    printf("���ڵ�B ��ֵΪ X ��T = \n");
    Assign_C(&T,'B','X');
    Print_C_2(T,T.r,0);
    printf("\n");
}
PressEnter;

printf("14\n ����ChildValue_C����...\n");
{
    printf("�ڵ�%c ��%d������Ϊ��%c\n",'A',2,ChildValue_C(T,'A',2));
    printf("\n");
}
PressEnter;

printf("15-1,15-2\n ����Sibling_C_1,Sibing_C_2����...\n");
{
    printf("%c �����ֵ�Ϊ��%c,%c �����ֵ�Ϊ��%c\n",'E',Sibling_C_1(T,'E',0),'D',T.nodes[Sibling_C_1(T,'E',1)]);
    printf("\n");
}
PressEnter;

printf("����16,17,18,19,20,InsertTree_C�Ȳ���...\n");
{
    printf("��������ӡT0...\n");
    fp = fopen("TestData_T0.txt","r");
    InitTree_C(fp,&T0);
    CreateTree_C(fp,&T0);
    fclose(fp);
    Print_C_1(T0);
    printf("\n");
    printf("��T0�޽�Ϊ%c�ĵ�%d��������T = ...\n",'X',1);
    InsertTree_C(&T,'X',1,T0);
    Print_C_1(T);
    printf("\n");
    ShowTree_C(T);
    printf("\n");
}
PressEnter;

printf("21\n ����DeleteTree_C ����...\n");
{
    printf("ɾ��T�нڵ�%c �ĵ�%d��������T = \n",'0',3);
    DeleteTree_C(&T,'0',3);
    Print_C_1(T);
    printf("\n");
    ShowTree_C(T);
    printf("\n");
}
PressEnter;

printf("2,3\n ����ClearTree_C �Ȳ���...\n");
{
    ClearTree_C(&T);
    TreeEmpty_C(T)?printf("TΪ�գ���\n"):printf("T��Ϊ�գ���\n");
    printf("\n");
}
    PressEnter;
}

void PrintElem(TElemType_C e)
{
    printf("%c ",e);
}

