//LineEdit-main �����ĵ�

//03ջ�Ͷ���

//��غ�������

#include"LineEdit.c"

int main(int argc,char*argv[])
{
    char *buf = "whil##ilr#e(s#*s)\noutcha@  putchar(*s=#++);";

    printf("��Ϊʾ�����û�������ı�����Ϊ:\n");
    printf("%s\n",buf);
    printf("\n");
    printf("���뺽�༭����...\n");
    printf("������ţ� #   ����ɾ����һԪ�أ���@������ɾ����ǰ�����У�\n");
    printf("                      \\n ����ȷ�ϴ������󣬡�\\0�������������.\n");
    printf("���մ洢������Ϊ: \n");
    LineEdit(buf);
    printf("\n\n");

    return 0;
}
