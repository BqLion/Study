//��������������

#include<stdio.h>
#include"SeqBinaryTree.c"

void PrintElem(char c);

int main(int argc,char *argv[])
{
    SqBiTree T;

    printf("1\n ����InitBiTree_Sq ����...\n");
    {
    printf("��ʼ���ն�����T...\n");
    InitBiTree_Sq(T);
    printf("\n");

    }
PressEnter;

printf("4\n����BiTreeEmpty_Sq ����...\n");
{
    BiTreeEmpty_Sq(T)?printf("TΪ�գ�\n"):printf("T ��Ϊ�գ���\n");
    printf("\n");

}
PressEnter;

printf("5\n ���� CreateBiTree_Le_Sq���� ...\n");
{
    FILE *fp;

    printf("���ղ������д���������T ...\n");
    fp = fopen("TestData_Le.txt","r");
    CreateBiTree_Le_Sq(fp,T);
    fclose(fp);
    printf("\n");

}
PressEnter;

printf("29\n����Print_Sq ����...\n");
{
    printf("���������Ľṹ��ӡ��T...\n");
    Print_Sq(T);
    printf("\n");


}
PressEnter;

printf("7,8 ����BiTreeLength_Sq /BiTreeDepth_Sq����....\n");
{
    printf("T�ĳ���Ϊ:%d�����Ϊ:%d��\n ",BiTreeLength_Sq(T),BiTreeDepth_Sq(T));
    printf("\n");

}
PressEnter;


printf("17\n���� LevelOrderTraverse_Sq���� ...\n");
{
    printf("������������� T = ");
    LevelOrderTraverse_Sq(T,PrintElem);
    printf("\n\n");

}
PressEnter;

printf("18\n ����PreOrderTraverse_Sq �Ȳ���...\n");
{
    printf("ǰ����������� T = ");
    PreOrderTraverse_Sq(T,PrintElem,0);
    printf("\n\n");
}
PressEnter;

printf("19\n ����InOrderTraverse_Sq ����...\n");
{
    printf("�������������T = ");
    InOrderTraverse_Sq(T,PrintElem,0);
    printf("\n\n");
}
    PressEnter;

printf("20\n ����PostOrderTraverse_Sq �Ȳ���...\n");
{
    printf("�������������T = ");
    PostOrderTraverse_Sq(T,PrintElem,0);
    printf("\n\n");
}
PressEnter;

printf("9\n ����Root_Sq ����..\n");
{
    TElemType_Sq r;

    printf("T�ĸ��ڵ�Ϊ %c\n",r);
    Root_Sq(T,&r);
    printf("\n");


}
PressEnter;

printf("10\n ����Value_Sq����..\n");
{
Position p = {4,3};

printf("T�е�%d �е� %d�е�ֵΪ %c \n",p.level,p.order,Value_Sq(T,p));
printf("\n");

}
PressEnter;

printf("11\n ����Assign_Sq ���� ...\n");
{
    Position p ={4,3};

    printf("��%d���%d�еĽ�㸳ֵΪ ��X����T= \n ",p.level,p.order);
    Assign_Sq(T,p,'X');
    Print_Sq(T);
    printf("\n");


}
PressEnter;

printf("12\n ���� Parent_Sq  ����...\n");
{
    printf("'X'����parents Ϊ�� %c \n",Parent_Sq(T,'X'));
    printf("\n");

}
PressEnter;

printf("13,14 \n ����LeftChild_Sq,RightChild_Sq����....");
{
    printf("'E' �����ӽ��ֵΪ��%c,�Һ��ӽ��ֵΪ:%c\n",LeftChild_Sq(T,'E'),RightChild_Sq(T,'E'));
    printf("\n");


}
PressEnter;

printf("15\n ���� LeftSibling_Sq����...\n");
{
    printf("'I'�����ֵ�Ϊ��%c\n",LeftSibling_Sq(T,'I'));
    printf("\n");

}
PressEnter;

printf("16\n ���� RightSibling_Sq����...\n");
{
    printf("'X'�����ֵ�Ϊ��%c\n",RightSibling_Sq(T,'X'));
    printf("\n");

}
PressEnter;

printf("2\n ���� ClearBiTree_Sq����...\n");
{
    ClearBiTree_Sq(T);
    if(BiTreeEmpty_Sq(T))
    printf("T�ѱ����!\n");
    printf("\n");

}
PressEnter;

return 0;
}

void PrintElem(char c)
{
printf("%c ",c);
}
