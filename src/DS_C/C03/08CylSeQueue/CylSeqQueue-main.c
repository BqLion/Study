/*******************************

文件夹：03栈和队列 08CylSeqQueue

内容：循环队列相关函数测试

*****************************/

#include <stdio.h>
#include"CylSeqQueue.c"

void PrintElem(QElemType_CSq e);

int main(int argc,char **argv)
{
    CSqQueue Q;
    int i;
    QElemType_CSq e;

    printf("1\n 函数InitQueue_CSq 测试...\n");
    {
        printf("初始化循环顺序队列Q...\n");
        InitQueue_CSq(&Q);
        printf("\n");
    }
    PressEnter;

    printf("4\n 函数QueueEmpty_CSq 测试...\n");
    {
    QueueEmpty_CSq(Q)?printf("Q为空！！\n"):printf("Q不为空！！\n");
    printf("\n");
    }
    PressEnter;

    printf("7\n函数EnQueue_CSq 测试...\n");
    {
        for(i=1;i<=6;i++)
        {
            printf("元素\"%2d\" 入队Q，",2*i);
            EnQueue_CSq(&Q,2*i);
            printf("累计第%d个元素...\n",QueueLength_CSq(Q));
        }
        printf("\n");
    }

    printf("9/n 函数QueueTraverse_CSq 测试...\n");
    {
        printf("Q中的元素：Q = ");
        QueueTraverse_CSq(Q,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    printf("8\n函数 DeQueue_CSq 测试...\n");
    {
        DeQueue_CSq(&Q,&e);
        printf("队头元素 \"%d\"出队...\n",e);
        printf("Q中的元素为：Q = ");
        QueueTraverse_CSq(Q,PrintElem);
        printf("\n\n");
    }
    PressEnter;

    printf("5\n 函数 QueueLength_CSq 测试...\n");
    {
        i = QueueLength_CSq(Q);
        printf("Q的长度为%d \n",i);
        printf("\n");
    }
    PressEnter;

    printf("6\n函数GetHead_CSq 测试...\n");
    {
        GetHead_CSq(Q,&e);
        printf("队头元素的值为\"%d\" \n",e);
        printf("\n");
    }
    PressEnter;

    printf("3\n函数 ClearQueue_CSq 测试...\n");
    {
    printf("清空Q前：");
    QueueEmpty_CSq(Q)?printf("Q为空！！\n"):printf("Q不为空！！\n");
    ClearQueue_CSq(&Q);
    printf("清空Q后：");
    QueueEmpty_CSq(Q)?printf("Q为空！！！\n"):printf("Q不为空！\n");
    printf("\n");
    }
    PressEnter;

    printf("2\n函数DestroyQueue_CSq 测试...\n");
    {

        printf("销毁Q前:");
        Q.base !=NULL?printf("Q存在！！\n"):printf("Q不存在！！\n");
        DestroyQueue_CSq(&Q);
        printf("销毁Q后:");
        Q.base !=NULL?printf("Q存在！\n"):printf("Q不存在！！\n");
        printf("\n");
    }
    PressEnter;

    return 0;
}


void PrintElem(QElemType_CSq e)
{
    printf("%d ",e);
}
