/****************************

04/01SequenceString

文件名: SequenceString.h

内容:顺序串相关操作列表

****************************/

#ifndef SEQUENCESTRING_H
#define SEQUENCESTRING_H

#include <stdio.h>
#include<string.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

#define MAXSTRLEN 255

// 串的顺序存储类型定义
typedef unsigned char SString[MAXSTRLEN+1];

//顺序串函数列表

Status StrAssign_Sq(SString T,const char *chars);
//生成一个值等于常量chars的串T

void StrCopy_Sq(SString T,SString S);
//由串复制得串T

Status StrEmpty_Sq(SString S);
//探空

int StrLength_Sq(SString S);
//求串长

void ClearString_Sq(SString S);

Status Concat_Sq(SString T,SString S1,SString S2);      //合并

Status SubString_Sq(SString Sub,SString S,int pos,int len);         //子串
//Sub返回S串从pos开始len个长度的子串

int Index_Sq_1(SString S,SString T,int pos);            //定位
//返回T在S中第pos个字符后第一次出现的位置，不存在则返回0

Status Index_Sq_2(SString S,SString T,int pos);
//同上

Status Replace_Sq(SString S,SString T,SString V);
//用V替换（主串S中，所有与T相等）的子串，若可以被完全替换，返回OK

Status StrInsert_Sq(SString S,int pos,SString T);
//在S的第pos个位置插入T，可完全插入返回OK，否则返回ERROR

Status StrDelete_Sq(SString S,int pos,int len);
//删除从pos开始len个子串

void DestroyString_Sq(SString S);
//销毁

void StrPrint_Sq(SString S);

#endif
