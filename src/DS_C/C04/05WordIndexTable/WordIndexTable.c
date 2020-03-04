//04��/05WordIndexTable

#ifndef WORDINDEXTABLE_H
#define WORDINDEXTABLE_H

#include"WordIndexTable.h"

void Main(char *bookinfo,char *bookidx)
{
    FILE *f,*G;
    char b[MaxLineLen];             //��Ŀ��ʱ������
    IdxListType idxlist;                //�ؼ���������        //��������
    int i;
    LElemType_E bno;                //���

    if(f = fopen(bookinfo,"r"))
    {
        if(g = fopen(bookidx,"w"))
        {
        InitIdxList(&idxlist);//��ʼ��������

        fgets(b,MaxLineLen,f); //�����ļ���һ��

        while(!feof(f))
        {
                GetLine(f);

                ExtractKeyWord(&bno);       //��ȡ�ؼ���

                InsIdxList(&idxlist,bno);       //��źͶ�Ӧ�Ĺؼ��ʲ��뵽������idxlist

        }

        PutText(g,idxlist);         //��g��д������
        }
        }
        fclose(g);
        fclose(f);
}

void InitIdxList(IdxListType *idxlist)
{
    char *chars = "�ؼ���        �������";            //��Ϊ������ı�ͷ

    StrAssign_H(&((*idxlist).item[0].key),chars);       //����item���У�item��Ĺؼ��֣�����ֵΪchars
    InitList_E(&((*idxlist).item[0].bnolist));                  //��ʼ��idxlist�������е�һ��item��ģ���ű�

    (*idxlist).num = 0;                                         //��ͷΪ��0����Ϣ
}

void GetLine(FILE *f)
{
    int len;

    fgets(gBuf,MaxLineLen,f);           //��getline��������Ҫ����ʹ�ã���ȡ��

    len = strlen(gBuf);                     //��ȡ�о��ǰ��д��ļ��ж�ȡ�������gBuf�У���ʱ˳���len�������

    gBuf[len-1] = '\0';             //���з��á�\0�� ����
}

void ExtractKeyWord(int *bno)           //��ȡ�ؼ��ʣ�extract����ȡ����˼
{
    char *title;
    FILE *fp;

    *bno = strtol(gBuf,&title,10);          //�ֱ𻺳����е��ַ���gBuf����Ŵ���bno����������title
    strlwr(title);                          //��д��Сд

    fp  = tmpfile();            //������ʱ�ļ�
    fprintf(fp,"%s",title);     //���ַ���д����ʱ�ļ���
    fseek(fp,0,SEEK_SET);   //�ļ�ָ���ƶ�����ʼλ��

    for(gWdList.last = 0;gWdList.last<MaxWordNum;gWdList.last++)
    {
        gWdList.str[gWdList.last] = (char*)malloc(MaxLineLen*sizeof(char));
        if(!gWdList.str[gWdList.last])
        exit(OVERFLOW);

        if(fscanf(fp,"%s",gWdList.str[gWdList.last])==EOF)
        break;
    }
}

//�㷨4.10

Status InsIdxList(IdxListType *idxlist,int bno)
{
    int i,j;
    Bool boo;
    HString wd;

    if(!gWdList.last)
    return ERROR;

    for(i=0;i<gWdList.last;i++)
    {
        GetWord(i,&wd);

        if(!isCommonWords(wd))  //��temp�л��������ʻ㣬�ж�һ���ǲ��ǳ��ôʣ�������ǵ���Ҫ����
        {
            j = Locate(*idxlist,wd,&boo);

            if(boo == FALSE)
            InsertNewKey(idxlist,j,wd);

            if(!InsertBook(idxlist,j,bno))

            return ERROR;


        }

    }

    return OK;
}

void PutText(FILE *g,IdxListType idxlist)
{
    int i,j,m,n;
    Link p;
    HString S;
    ELinkList L;

    for(i=0;i<=idxlist.num;i++)
    {
    S = idxlist.item[i].key;
    for(m=0;m<S.length;m++)
    fprintf(g,"%c",S.ch[m]);

    if(i)
    {
        for(j=1;j<18-idxlist.item.key.length;j++)
        fprintf(g," ");

        L= idxlist.item[i].bnolist;
        for(n=1,p=L.head->next;n<=L.len;n++)
        {
        printf(g,"%03d",p->data);
        p = p->next;
        if(p)
        fprintf(g," ");
        }
    }

    if(i!=idxlist.num)
    printf(g,"\n");
    }
}

void GetWord(int i,HString *wd)
{

    char *p = gWdList.str[i];
    StrAssign_H(wd,p);


}


int locate(IdxListType idxlist,HString wd,Bool *b)
{
    int i,m;

    for(i = idxlist.num;i>0&&(m = StrCpmare_H(idxlist.item[].key,wd))>0;i--);

    if(m==0&&idxlist.num!=0)
    {
        *b = TRUE;
        return i;


    }
    else
   { *b = FALSE;
    return i+1;
    }


}

void InsertNewKey(IdxListType *idxlist,int i ,HString wd)
{
    int j;
    for(j=(*idxlist).num;j>=i;j--)
    (*idxlist).item[j+1] = (*idxlist).item[j];

    StrCopy_H(&((*idxlist).item[i].key),wd);

    (*idxlist).num++;

    InitList_E(&((*idxlist).item[i].bnolist));

}

Status InsertBook(IdxListType *idxlist,int i,LElemType_E bno)
{
    Link p;
    if(!MakeNode_E(&p,bno))
    return ERROR;

    Append_E(&((*idxlist).item[i].bnolist),p);
    return OK;
}

Status isCommonWords(HString S)
{
    int i,len;
    char a[S.length+1];
    Status flag = FALSE;

    for(i=0;i<S.length;i++)
    a[i] = S.ch[i];
    a[i] = '\0';

    for(i=0;i<gWordList.last;i++)
    {
    if(!strcmpi(a,gWordList.str[i])
    {
    flag = TRUE;
    break;


    }


    }

    return flag;
}

#endif
