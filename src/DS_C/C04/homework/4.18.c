//4.18编写算法，求串S所含不同字符的总数和每种字符的个数

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
    printf("S中不同的字符共计有%d个:\n",total[0]);
    for(i=1;i<=127;i++)
    {
        if(total[i]!=0)
        printf("字符\'%c\'有 %d个\n",i,total[i]);
    }
    printf("统计完毕...\n");
    printf("\n");

    return 0;
}

void Algo_4_18(SString S,int total[])
{
    int i;

    for(i=1;i<=S[0];i++)
{
if(!total[S[i]])        //total本身是个空的数组，有128个坑。这里判断如果total【S【i】】这个坑还从来没有被填过，说明是第一次出现，这时将计数器++
total[0]++;

total[S[i]]++;
}
}
