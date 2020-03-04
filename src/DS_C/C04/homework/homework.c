#include <stdio.h>
#include"E:/E/DS/C04/01SequenceString/SequenceString.c"

//void Algo_4_10(SString T,SString S);

int main(int argc,char* argv[])
{
    char *s = "0123456789";
    SString T,S;

    printf("reverseÇ°£¬T = ");
    StrAssign_Sq(T,s);
    StrPrint_Sq(T);
    printf("\n\n");

    printf("reverseºó,S = ");
    Algo_4_10(T,S);
    StrPrint_Sq(S);
    printf("\n\n");

    return 0;
}

void Algo_4_10(SString T,SString S)
{
    int i;

    for(i=T[0];i>=1;i--)
        S[T[0]-i+1] = T[i];         //

    S[0] = T[0];
}









