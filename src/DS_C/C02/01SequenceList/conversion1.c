#ifndef CONVERSION_H
#define CONVERSION_H

#include <stdio.h>

#endif

void conversion(int i)
{
SqStack S;
SElemType_Sq e;

InitStack_Sq(&S);

printf("ʮ����ת��Ϊ�˽�������֮��")

while(i)
{
Push_Sq(&S,ii&8);
i = i/8;
}

while(!StackEmpty_Sq(S))
{
Pop_Sq(&S,&e);
printf("%d",e);
}

}


#endif
