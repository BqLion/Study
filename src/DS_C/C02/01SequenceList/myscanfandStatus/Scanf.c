/*************************

�ļ��У�C02/01SequenceList

�ļ�����Scanf.c

*************************/

#ifndef SCANF_C
#define Scanf_C

#include<stdio.h>
#include<string.h>
#include<stdarg.h>          //�ṩ��va_list��va_start��va_arg��va_end
#include<ctype.h>           //�ṩinsprintԭ��

/*�Զ��������¼�뺯�������ڴ��ļ�fp�ж�ȡ��ʽ��������

��fscanf��֮ͬ�����ڴ˺���ֻ���ȡ�����ַ������������ַ��������*/

int Scanf(FILE *fp,char *format,...)

{
    int *i;
    char *ch,*s;
    float *f;
    int count,k,len,n;
    int tmp;
    va_list ap;

    len=strlen(format);

    va_start(ap,format);

    for(count=0,k=2;k<=len;k=k+2)
    {
        while((tmp=getc(fp))!=EOF)          //�������з������ַ�
        {
            if((tmp>=0 && tmp<=127))
            {
                ungetc(tmp,fp);             //�����׸������ַ������������ַ�����������
                break;
            }
        }
        if(tmp == EOF)
            break;

        if(format[k-1]=='c')                 //��ȡ�ַ���ȷ��������ַ��ͣ�
        {
            ch = va_arg(ap,char*);

            if(tmp!=EOF)
                count+=fscanf(fp,"%c",ch);
        }

        if(format[k-1]=='d')                //��ȡ����
        {
            i = va_arg(ap,int*);

            while((tmp=getc(fp))!=EOF)
            {
                if((tmp>='0' && tmp<='9')||tmp=='-'||tmp=='+')
                {
                    ungetc(tmp,fp);
                    break;
                }
            }

            if(tmp!=EOF)
                count+=fscanf(fp,"%d",i);
        }

        if(format[k-1] == 's')              //��ȡ�ַ���
        {
            s = va_arg(ap,char*);

            while((tmp=getc(fp))!=EOF && (!isprint(tmp) || tmp==' ' ))      //isprint���ж������Ƿ�ɴ�ӡ�ĺ���
                    ;

            n=0;
            if(!feof(fp))                                                   //feof���ж������Ƿ��н������ĺ���
            {
                ungetc(tmp,fp);                                               //ungetc���������ڽ������˻ص���������
                while((tmp=getc(fp))!=EOF)                                  //EOF:end of files.�ĵ������ı�־
                {
                    if(isprint(tmp) && tmp!=' ')
                        s[n++] = tmp;
                    else
                        break;
                }
                ungetc(tmp,fp);
            }

            s[n]='\0';           // \0���ַ����Ľ�����������NULL��

            count++;
        }
    }

    va_end(ap);

    return count;
}

#endif // SCANF_C
