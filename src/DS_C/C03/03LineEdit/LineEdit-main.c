//LineEdit-main 测试文档

//03栈和队列

//相关函数测试

#include"LineEdit.c"

int main(int argc,char*argv[])
{
    char *buf = "whil##ilr#e(s#*s)\noutcha@  putchar(*s=#++);";

    printf("作为示范，用户输入的文本内容为:\n");
    printf("%s\n",buf);
    printf("\n");
    printf("进入航编辑程序...\n");
    printf("特殊符号： #   代表删除上一元素，“@”代表删除当前输入行，\n");
    printf("                      \\n 代表确认此行无误，“\\0”代表输入结束.\n");
    printf("最终存储的内容为: \n");
    LineEdit(buf);
    printf("\n\n");

    return 0;
}
