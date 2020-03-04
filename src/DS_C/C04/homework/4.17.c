#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C04/01SequenceString/SequenceString.c"

//函数原型
Status Algo_4_15(SString T,char *chars);
int Algo_4_16(SString S,SString T);
Status Algo_4_17(SString S,SString T,SString V);

int main(int argc,char *argv[])
{
    char *t = "ab**c*de***fg";
    char *t = "ab**c*de***fh";
    int i;
    SString T,S,M1,M2;

    printf("4.15测试...\n");
    Algo_4_15(T,t);
    Algo_4_15(S,s);
    printf("T = ");
    StrPrint_Sq(T);
    printf("\n");
    printf("S = ");

    printf("题4.16验证...\n");
    i = Algo_4_16(S,T);
    if(i>0)
    printf("S>T\n");
    else if(i<0)
    printf("S<T\n");
    else
    printf("S==T\n");
    printf("\n");

    printf("题4.17验证...\n");
    Algo_4_15(M1,"**");
    Algo_4_15(M2,"^");
    Algo_4_17(S,M1,M2);
    printf("用\"^\"替换 \"**\" 后:S = ");
    StrPrint_Sq(S);
    printf("\n\n");

    return 0;
}

Status Algo_4_15(SString T,char *chars)
{
    int i,len;

    len = strlen(chars);

    if(len>MAXSTRLEN)
    return ERROR;
    else
    {
        T[0]=  len;
        for(i=1;i<=len;i++)
        T[i] = chars[i-1];

        return OK;

    }

}
//字符串比较

int Algo_4_16(SString S,SString T)
{
    int i = 1;

    while(i<=S[0]&&i<=T[0])
    {
    if(S[i]==T[i])
    i++;
    else
    return S[i] - T[i];
    }
    return S[0]-T[0];

}


Status Algo_4_17(SString S,SString T,SString V)
{
    int count = 1;
    int i,j,k;
    SString Tmp_beh;

    i = count;
    j = 1;

    while(i>=1 && i<=S[0]&& j<=T[0])
    {
    if(S[i]==T[j])
    {
    i++;
    j++;
    }
    else
    {
    i= i-(j-1)+1;
    j = 1;
    }
    }
    if(j>T[0]&&T[0]!=0)
    count = i-T[0];
    else
    count = 0;

    while(S[0]-T[0]+V[0]<=MAXSTRLEN&& count!=0)
    {
    Tmp_beh[0] = S[0]-i+1;
    for(k=1;k<S[0]-i+1;k++)
    Tmp_beh[k] = S[k+i-1];

    S[0] = S[0]-T[0]+V[0];
    for(k=1;k<=V[0];k++)
    S[k+count-1] = V[k];

    for(k= count+V[0];k<=S[0];k++)
    S[k] = Tmp_beh[k-count-V[0]+1];

    count+=V[0];

    i = count;
    j = 1;
    while(i>1 && i<S[0]&& j<=T[0])
    {
    if(S[i]==T[j])
    {
    i++;
    j++;
    }
    else
    {
    i = i-(j-1)+1;
    j = 1;
    }
    }
    if(j>T[0] && T[0]!=0)
    count = i-T[0];
    else
    count=0;

    }
    if(count ==0)
    return OK;
    else
    return ERROR;
}

