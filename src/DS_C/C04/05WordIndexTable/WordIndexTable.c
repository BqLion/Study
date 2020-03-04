//04串/05WordIndexTable

#ifndef WORDINDEXTABLE_H
#define WORDINDEXTABLE_H

#include"WordIndexTable.h"

void Main(char *bookinfo,char *bookidx)
{
    FILE *f,*G;
    char b[MaxLineLen];             //书目临时缓存区
    IdxListType idxlist;                //关键词索引表        //就是索引
    int i;
    LElemType_E bno;                //书号

    if(f = fopen(bookinfo,"r"))
    {
        if(g = fopen(bookidx,"w"))
        {
        InitIdxList(&idxlist);//初始化索引表

        fgets(b,MaxLineLen,f); //跳过文件第一行

        while(!feof(f))
        {
                GetLine(f);

                ExtractKeyWord(&bno);       //提取关键词

                InsIdxList(&idxlist,bno);       //书号和对应的关键词插入到索引表idxlist

        }

        PutText(g,idxlist);         //向g中写入数据
        }
        }
        fclose(g);
        fclose(f);
}

void InitIdxList(IdxListType *idxlist)
{
    char *chars = "关键词        书号索引";            //作为索引表的表头

    StrAssign_H(&((*idxlist).item[0].key),chars);       //索引item表中，item项，的关键字，被赋值为chars
    InitList_E(&((*idxlist).item[0].bnolist));                  //初始化idxlist索引表中第一个item项的，书号表

    (*idxlist).num = 0;                                         //表头为第0条信息
}

void GetLine(FILE *f)
{
    int len;

    fgets(gBuf,MaxLineLen,f);           //此getline函数，需要反复使用，读取行

    len = strlen(gBuf);                     //读取行就是把行从文件中读取搭到缓冲区gBuf中，这时顺便把len求出来。

    gBuf[len-1] = '\0';             //换行符用‘\0‘ 代替
}

void ExtractKeyWord(int *bno)           //提取关键词，extract是提取的意思
{
    char *title;
    FILE *fp;

    *bno = strtol(gBuf,&title,10);          //分别缓冲区中的字符换gBuf，书号存入bno，书名存入title
    strlwr(title);                          //大写变小写

    fp  = tmpfile();            //建立临时文件
    fprintf(fp,"%s",title);     //把字符串写进临时文件中
    fseek(fp,0,SEEK_SET);   //文件指针移动到起始位置

    for(gWdList.last = 0;gWdList.last<MaxWordNum;gWdList.last++)
    {
        gWdList.str[gWdList.last] = (char*)malloc(MaxLineLen*sizeof(char));
        if(!gWdList.str[gWdList.last])
        exit(OVERFLOW);

        if(fscanf(fp,"%s",gWdList.str[gWdList.last])==EOF)
        break;
    }
}

//算法4.10

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

        if(!isCommonWords(wd))  //从temp中获得了这个词汇，判断一下是不是常用词，如果不是的需要插入
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
