//幂集相关操作列表
//幂集其实就是原集合中的所有的子集，包括空集和全集  构成的集族
//要注意求幂集的运算中，对递归的应用

#ifndef POWERSET_H
#define POWERSET_H

#include<stdio.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"
#include"E:/E/DS/C02/01SeuqenceList/Scanf.c"
#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"

typedef LElemType_L PElemType;

Status CreatPowerSet_PS(FILE *fp,LinkList *A);

void GetPowerSet_PS(int i,LinkList A,LinkList B);

void Output_PS(LinkList A);

#endif

