//���Ķ������������ֵܱ�ʾ�����洢��ز���

#include<stdio.h>
#include"ChildSiblingTree.c"

void PrintElem(TElemType_CS e);

int main(int argc,char *argv[])
{
    CSTree T;

    printf("1\n ����InitTree_CS ����...\n");
    {
    printf("��ʼ��һ�ſ���T\n");
    InitTree_CS(&T);
    printf("\n");
    }
    PressEnter;

    printf("4\n ����TreeEmpty_CS ����..\n");
    {
    TreeEmpty_CS(T)?printf("TΪ�գ���\n"):printf("T��Ϊ�գ���\n");
    printf("\n");
    }
    PressEnter;

    printf("5\n ����CreateTree_CS ����...\n");
    {
    FILE *fp;
    printf("�����������д��������� T ...\n");
    printf("��Ϊʾ����¼���������� ��RAD^E^^B^CFG^H^K^^^^^...\n");
    fp = fopen("TestData_T.txt","r");
    CreateTree_CS(fp,&T);
    fclose(fp);
    printf("\n");
    }
    PressEnter;

    printf("21\n ����Print_CS ����...\n");
    {
    printf("�������Ľṹ��ӡ��T = \n");
    Print_CS(T);
    printf("\n");
    }
    PressEnter;

    printf("18\n ����LevelOrderTraverse_CS ����\n");
    {
    printf("��������� T = ");
    LevelOrderTraverse_CS(T,PrintElem);
    printf("\n\n");
    }
    PressEnter;

    printf("19\n ���� PreOrderTraverse_CS���� ..\n");
    {
    printf("ǰ�������T = ");
    PreOrderTraverse_CS(T,PrintElem);
    printf("\n\n");
    }
    PressEnter;

    printf("20\n  ����InOrderTraverse_CS ����...\n");
    {
    printf("���������T = ");
    InOrderTraverse_CS(T,PrintElem);
    printf("\n\n");
    }
    PressEnter;

    printf("6\n ����TreeDegree_CS ����...\n");
    {
    printf("T�Ķ�Ϊ:%d \n",TreeDegree_CS(T));
    printf("\n");
    }
    PressEnter;

    printf("7\n ����TreeDeptrh_CS����...\n");
    {
    printf("T ����%d��\n",TreeDepth_CS(T));
    printf("\n");
    }
    PressEnter;

    printf("8\n����Root_CS����...\n");
    {
    printf("T�ĸ��ڵ�Ϊ��%c \n",Root_CS(T));
    printf("\n");
    }
    PressEnter;

    printf("9\n ����Value_CS ����...\n");
    {
    printf("T�е�%d ���ڵ��ֵΪ��%c\n",2,Value_CS(T,2));
    printf("\n");
    }
    PressEnter;

    printf("10\n����Order_CS ����...\n");
    {
    printf("T��Ԫ��%c�ĵ�ַΪ�� 0x%X \n",'A',Order_CS(T,'A'));
    printf("\n");
    }
    PressEnter;

    printf("11\n ����Assign_CS ����...\n");
    {
    printf("���ڵ㡮B����ֵΪ��X����T = \n");
    Assign_CS(T,'B','X');
    Print_CS(T);
    printf("\n");
    }
    PressEnter;

    printf("12\n ����ChildValue_CS ����...\n");
    {
    printf("�ڵ� %c �ĵ�%d������Ϊ:%c\n",'A',2,ChildValue_CS(T,'A',2));
    printf("\n");
    }
    PressEnter;

    printf("13\n ����Sibling_CS����...\n");
    {
    printf("%c �����ֵ�Ϊ:%c ",'E',Sibling_CS(T,'E',0));
    printf("%c �����ֵ�Ϊ��%c \n",'D',Sibling_CS(T,'D',1));
    printf("\n");
    }
    PressEnter;

    printf("14,15,16\n ����InsertTree_CS �Ȳ���...\n");
    {
    FILE *fp;
    CSTree T0;

    printf("��������ӡ�� T0...\n");
    InitTree_CS(&T0);
    printf("��Ϊʾ����¼���������У�01^2^34^5^^^^...\n");
    fp = fopen("TestData_T0.txt","r");
    CreateTree_CS(fp,&T0);
    fclose(fp);
    Print_CS(T0);
    printf("��T0�޽�Ϊ %c�ĵ�%d��������T = \n",'X',1);
    InsertTree_CS(T,'X',1,T0);
    Print_CS(T);
    printf("\n");
    }
    PressEnter;


printf("17\n ����DeleteTree_CS ����...\n");
{
    printf("ɾ�� T�нڵ�%c �ĵ�%d��������T = \n",'0',3);
    DeleteTree_CS(T,'0',3);
    Print_CS(T);
    printf("\n");
}
PressEnter;

printf("2\n ����ClearTree_CS�Ȳ���...\n");
{
    ClearTree_CS(&T);
    TreeEmpty_CS(T)?printf("TΪ�գ�\n"):printf("T��Ϊ�գ���\n");
    printf("\n");
}
PressEnter;
}

void PrintElem(TElemType_CS e)
{
    printf("%c ",e);
}
