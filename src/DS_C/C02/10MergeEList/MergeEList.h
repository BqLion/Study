/*******************************

�ļ��У�C02/10 MergeEList.h

�ļ�����MergeEList.h

���ݣ��鲢��չ�ĵ�������ز����б�

********************************/

#ifndef MERGELIST_H
#define MERGELIST_H

#include<stdio.h>
#include"E:/E/DS/C02/09ExtenLinkedList/ExtenLinkedList.c"

//�鲢��չ�ĵ��������б�

Status MergeEList_L(ELinkList La,ELinkList Lb,ELinkList *Lc,int(Compare)(LElemType_E c1,LElemType_E c2));
//��01���㷨2.21 La��Lb��Ϊ�ǵݼ����У�����鲢Ϊһ���ǵݼ�����ĵ�����LC

int Cmp(LElemType_E c1,LElemType_E c2);     //��02���Ƚ�c1 c2��С������c1-c2

Status CreateList_ascend(FILE *fp,ELinkList *L,int count);   //(03)���ǽ������д���Ԫ�ظ���Ϊcount����չ������L

#endif // MERGELIST_H












