//行编辑程序的c文件，算法：3.2

#ifndef LINEEDIT_C
#define LINEEDIT_C

#include"LineEdit.h"

//算法3.2

void LineEdit (char Buffer[])                   //编写这一个编辑行的函数，传进来的参数是Buffer缓冲区
{
    SqStack S;
    SElemType_Sq e;
    int i;
    char ch;

    InitStack_Sq(&S);

    i = 0;
    ch = Buffer[i++];
    while(ch!='\0')
    {
        while(ch!='\0' && ch!='\n')         //遇见0就销毁整个栈，遇见\n输出整个栈，然后清空接受新的输入
        {
            switch(ch)
            {
                case '#':Pop_Sq(&S,&e);   //遇见#符号就弹出（删除）刚才输入的元素
                break;
                case '@':ClearStack_Sq(&S);//遇见@符号就清空整个缓冲区的元素
                break;
                default:Push_Sq(&S,ch);     //如果两个都不是，那就把ch中的元素压栈
            }

            ch = Buffer[i++];//参数数组的下个元素进入ch，开始新一轮的循环
        }

        if(ch=='\n')
        {
            Push_Sq(&S,ch);
            StackTraverse_Sq(S,Print);
            ClearStack_Sq(&S);
            ch = Buffer[i++];
        }

        if(ch=='\n')
        {
            Push_Sq(&S,ch);
            StackTraverse_Sq(S,Print);
            ClearStack_Sq(&S);
            ch = Buffer[i++];
        }
    }
    if (ch=='0')
    {
        StackTraverse_Sq(S,Print);
        DestroyStack_Sq(&S);
    }
}


    void Print(SElemType_Sq e)
    {
    printf("%c",e);
    }

#endif // LINEEDIT_C
