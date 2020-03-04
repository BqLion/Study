 /*********************

 ����˫�ױ�ʾ����غ�������

 *******************/

 #include<stdio.h>
 #include"ParentTree.c"

 void PrintElem(TElemType_P e);

 int main(int argc,char *argv[])
 {
    PTree T,T0;

    printf("1\n ���� InitTree_P����...\n");
    {
        InitTree_P(&T);
        printf("��ʼ������T�����ڵ�ΪֹĬ����Ϊ0...\n");
        printf("\n");
    }
    PressEnter;

    printf("4\n ����TreeEmpty_P ����...\n");
    {
    TreeEmpty_P(T)?printf("TΪ�գ���\n"):printf("T��Ϊ�գ���\n");
    printf("\n");
    }
    PressEnter;

    printf("5\n ����CreateTree_P ����...\n");
    {
        FILE *fp;

        fp=fopen("TestData_T.txt","r");
        CreateTree_P(fp,&T);
        fclose(fp);
        printf("\n");
    }
    PressEnter;

    printf("19\n ����LevelOrderTraverse_P����...\n");
    {
    printf("��������� T=");
    LevelOrderTraverse_P(T,PrintElem);
    printf("\n\n");
    }
    PressEnter;

    printf("20\m ����Print_P ����...\n");
    {
    printf("��ӡ�� T = \n");
    Print_P(T);
    printf("\n");
    }
    PressEnter;

    printf("6\n ����TreeDegree_P ����...\n");
    {
    printf("T�Ķ�Ϊ��%d\n",TreeDegree_P(T));
    printf("\n");
    }
    PressEnter;

    printf("7\n ����TreeDepth_P ����...\n");
    {
    printf("T����%d ��\n",TreeDepth_P(T));
    printf("\n");
    }
    PressEnter;

    printf("8\n ����Root_P����...\n");
    {
    printf("T �ĸ��ڵ�Ϊ�� %c \n",Root_P(T));
    printf("\n");
    }
    PressEnter;

    printf("9\n ����Value_P����\n");
    {
        printf("T�е�%d���ڵ�ֵΪ��%c\n",2,Value_P(T,2));
        printf("\n");
    }
    PressEnter;

    printf("10\n ���� Order_P����...\n");
    {
    printf("T��Ԫ��%c��λ��Ϊ��%d\n",'A',Order_P(T,'A'));
    printf("\n");
    }
    PressEnter;

    printf("11\n ����Assign_P����...\n");
    {
    printf("���ڵ㡮B����ֵΪ ��X����T= \n");
    Assign_P(&T,'B','X');
    Print_P(T);
    printf("\n");
    }
    PressEnter;

    printf("12\n ����ChildValue_P����...\n");
    {
    printf("%c �ĵ�%d������Ϊ��%c\n",'A',2,ChildValue_P(T,'A',2));
    printf("\n");
    }
    PressEnter;

    printf("13\n ����Sibling_P ����...\n");
    {
    printf("%c �����ֵ�Ϊ %c,%c�����ֵ�Ϊ:%c \n",'E',Sibling_P(T,'E',0),'D',Sibling_P(T,'E',0));
    printf("\n");
    }
    PressEnter;

    printf("14,15,16,17\n ���� InsertTree_P�Ȳ���...\n");
    {
    FILE *fp;
    printf("��������ӡ��T0 ...\n");
    InitTree_P(&T0);
    fp = fopen("TestData_T0.txt","r");
    CreateTree_P(fp,&T0);
    fclose(fp);
    Print_P(T0);
    printf("����T0����Ϊ��T�нڵ�%c�ĵ�%d��������T = \n",'X',1);
    InsertTree_P(&T,'X',1,T0);
    Print_P(T);
    printf("\n");
    }
    PressEnter;

    printf("18\n ����DeleteTree_P ���� ...\n");
    {
    printf("ɾ��T�нڵ�%c�ĵ�%d��������T = \n",'0',3);
    DeleteTree_P(&T,'0',3);
    Print_P(T);
    printf("\n");
    }
    PressEnter;

    printf("2\n ����ClearTree_P����..\n");
    {
    ClearTree_P(&T);
    TreeEmpty_P(T)?printf("TΪ�գ���\n"):printf("T��Ϊ�գ�\n");
    printf("\n");
    }
    PressEnter;
 }
 void PrintElem(TElemType_P e)
 {
    printf("%c ",e);
 }


