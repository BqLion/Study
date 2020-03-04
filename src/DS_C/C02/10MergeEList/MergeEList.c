/******************************************

文件夹：C02/10MergeELis

文件名：MergeEList.c

算法：2.21

******************************************/

#ifndef MERGEELIST_C
#define MERGEELIST_C

#include "MergeEList.h"

//算法2.21
Status MergeEList_L(ELinkList La,ELinkList Lb,ELinkList *Lc,int(Compare)(LElemType_E c1,LElemType_E c2))
{
    Link ha,hb,pa,pb,q;
    LElemType_E c1,c2;

    if(!InitList_E(Lc))
        return ERROR;                   //存储分配失败则返回ERROR

    ha = GetHead_E(La);         //ha指向la头结点
    hb = GetHead_E(Lb);        //hb指向lb头结点
    pa = NextPos_E(ha);        //pa指向la第一个节点
    pb = NextPos_E(hb);      //pb指向lb第一个节点
    while(!ListEmpty_E(La) && !ListEmpty_E(Lb))
    {
        c1 = GetCurElem_E(pa);              //c1等于pa所指的元素
        c2 = GetCurElem_E(pb);              //c2等于pb所指的元素
        if(Compare(c1,c2)<=0)               //如下作比较，大的那个在原队列删除，加入新的LC队列直到所有都循环一遍
        {
                DelFirst_E(&La,ha,&q);
                InsFirst_E(Lc,(*Lc).tail,q);
                pa = NextPos_E(ha);
        }
        else
        {
            DelFirst_E(&Lb,hb,&q);
            InsFirst_E(Lc,(*Lc).tail,q);
            pb = NextPos_E(hb);
        }
    }

    if(!ListEmpty_E(La))
                Append_E(Lc,pa);
    else
                Append_E(Lc,pb);

    FreeNode_E(&ha);
    FreeNode_E(&hb);

    return OK;
}

int Cmp(LElemType_E c1,LElemType_E c2)
{
        return c1-c2;
}

Status CreateList_ascend(FILE *fp,ELinkList *L,int count)
{
    int i;
    LElemType_E e;

    InitList_E(L);
    if(!L)
        return ERROR;

    for(i=1;i<=count;i++)
    {
            Scanf(fp,"%d",&e);
            ListInsert_L_E(L,i,e);
    }
    return OK;
}

#endif // MERGEELIST_C




