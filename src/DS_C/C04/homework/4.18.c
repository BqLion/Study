//4.18��д�㷨����S������ͬ�ַ���������ÿ���ַ��ĸ���

#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C04/01SequenceString/SequenceString.c"

void Algo_4_18(SString S,int total[]);
int main(int argc,char *argv[])
{
    char *s = "asdasjoaifjawgopiwapoawja[aaaaaaaaaaaaaaaaaaaaaaaaawg]ag,csaf.awfgawga[]w214151a5f325";
    SString S;
    int total[128] = {};
    int i;

    StrAssign_Sq(S,s);
    printf("S = ");
    StrPrint_Sq(S);
    printf("\n\n");

    Algo_4_18(S,total);
    printf("S�в�ͬ���ַ�������%d��:\n",total[0]);
    for(i=1;i<=127;i++)
    {
        if(total[i]!=0)
        printf("�ַ�\'%c\'�� %d��\n",i,total[i]);
    }
    printf("ͳ�����...\n");
    printf("\n");

    return 0;
}

void Algo_4_18(SString S,int total[])
{
    int i;

    for(i=1;i<=S[0];i++)
{
if(!total[S[i]])        //total�����Ǹ��յ����飬��128���ӡ������ж����total��S��i��������ӻ�����û�б������˵���ǵ�һ�γ��֣���ʱ��������++
total[0]++;

total[S[i]]++;
}
}
