//4.5建立索引表相关操作列表

#ifndef WORDINDEXTABLE_H
#define WORDINDEXTABLE_H

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/09ExtenLinkedList/ExtenLinkedList.c"
#include"E:/E/DS/C04/02HeapString.c";

#define MaxBookNul 1000
#define MaxKeyNum 2500
#define MaxLineLen 500
#define MaxWordNum 10

//数据结构定义

typedef Status Bool;
typedef struct
{
    char *str[MaxWprdNum];      //字符串数组
    int last;                                 //词表的长度
}WordListType;                  //这个就是摘录的词表

typedef struct
{
    HString key;
    ELinkList bnolist;
}IdxTermType;               //索引项，放的是关键词和书号的索引      //一个关键词，一些书号
//对上边这个单项，做集合就是索引表：
typedef struct
{
    IdxTermType item[MaxKeyNum+1];
    int num;
}IdxListType;           //索引表，刚才定义的所以项的集合，int num是索引项的数目

//全局变量
char gBuf[MaxLineLen];      //书名的缓存区

WordListType g WordList = {{"a","an","the","of","and","is","to","as","in","for"},10};//各项常用词

WordListType gWdList;

void Main(char *bookinfo,char *bookidx);

void InitInxList(IdxListType *idxlist);
//初始化索引表

void GetLine(FILE *f);
//将数目信息读入缓存区gBuf

void ExtractKeyWord(int *bno);//将缓存区gBuf 中提取书名关键词到词表gWdList,书号存进bno中

Status InsIdxList(IdxListType *idxlist,int bno);    //将书号bno对应的书名关键词按照词典的顺序插入到索引表idxlist

void PutText(FILE *g,IdxListType idxlist);
//将生成的索引表idxList输出到文件中

void GetWord(int i,HString *wd);
//用wd返回gWdList中第i个关键词

int Locate(IdxListType idxlist,HString wd,Bool *b);
//查询在索引表idxList中是否存在于wd相等的关键词，若存在，将返回wd在词汇表中的位置，并复制bool为True，否则bool为FALSE。

void InsertNewKey(IdxListType *idxlist,int i,HString wd);
//将索引表idxlist ,中的第i位，插入wd这个关键词，并初始化wd中索引表尾null

Status InsertBook(IdxListType *idxlist,int i,int bno);              //索引表中插入
//在索引表的第i项中插入书号为bno的索引

Status isCommonWords(HString S);
//判断S包含的关键词是否是常用词


//读入文件
//将文件中的书名和号码拆开，将书名分别插入到词汇表(wordlist)中。
//检查这些书名词汇(key)，在索引表(idxlist)中是否存在，若不存在插入，若存在加上自己的书号(bnolist)。













