//4.11编写算法，求r = s - s∩t

#include<stdio.h>
#include"E:/E/DS/C04/01SequenceString/SequenceString.c"

void  Algo_4_11(SString R,SString S,SString T,int a[]);

int main(int argc,char *argv[])
{
    int a[MAXSTRLEN+1];
    char *s = "amdhcjgfdlpindefcopgkqikeb";
    char *t = "mhjlpinopkqik";
    SString T,S,R;
    int i;

    printf("初始化S和T ...\n");
    StrAssign_Sq(S,s);
    StrAssign_Sq(T,t);
    printf("\n");

    printf("S = ");
    StrPrint_Sq(S);
    printf("\n");
    printf("T = ");
    StrPrint_Sq(T);
    printf("\n\n");

    Algo_4_11(R,S,T,a);
    printf("R = ");
    StrPrint_Sq(R);
    printf("\n");
    printf("a = ");
    for(i=1;i<=a[0];i++)
    printf("%d ",a[i]);
    printf("\n\n");

    return 0;
}

void Algo_4_11(SString R,SString S,SString T,int a[])
{
    int i,p;
    SString Tmp;

    StrAssign_Sq(R,"");
    Tmp[0] = 1;

    for(i=1,a[0] = 0;i<=S[0];i++)
    {
        Tmp[1] = S[i];

        p = Index_Sq_1(T,Tmp,1);

        if(!p)
         p  = Index_Sq_1(R,Tmp,1);

        if(!p)
        {
        a[0]++;
        a[a[0]] = i;
        StrInsert_Sq(R,a[0],Tmp);

        }

    }

}

