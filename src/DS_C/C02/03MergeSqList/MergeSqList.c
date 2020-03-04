/*******************************

�ļ��У�charpter02/03MergeList

�ļ�����MergeSqList.c

�㷨��2.2��2.7

*******************************/

#ifndef MERGESQLIST_C
#define MERGESQLIST_C

#include "E:/E/DS/C02/03MergeSqList/MergeSqList.h"

//�㷨2.2

void MergeSqList_1(SqList La,SqList Lb,SqList *Lc) //����˳��������кϲ�
{
	int La_len,Lb_len;
	int i,j,k;
	LElemType_Sq ai,bj;

	i=j=1;
	k=0;

	InitList_Sq(Lc);
	La_len=ListLength_Sq(La);
	Lb_len=ListLength_Sq(Lb);

	while(i<=La_len && j<=Lb_len)
	{
		GetElem_Sq(La,i,&ai);
	GetElem_Sq(Lb,j,&bj);

	if (ai<=bj)
		{
				ListInsert_Sq(Lc,++k,ai);
				i++;
		}
	else
		{
				ListInsert_Sq(Lc,++k,bj);
				j++;
			}
	}
	while(i<=La_len)
	{
		GetElem_Sq(La,i++,&ai);
		ListInsert_Sq(Lc,++k,ai);
	}

	while(j<=Lb_len)
	{
		GetElem_Sq(Lb,j++,&bj);
		ListInsert_Sq(Lc,++k,bj);
	}
}

//�㷨2.7

void MergeSqList_2(SqList La,SqList Lb,SqList *Lc)
{
	LElemType_Sq *pa,*pb,*pc;
	LElemType_Sq *pa_last,*pb_last;

	pa=La.elem;		//ָ��paָ���б��һ��Ԫ��
	pb=Lb.elem;		//ָ��pbָ���б��һ��Ԫ��

	(*Lc).listsize=(*Lc).length=La.length+Lb.length;	//û����InitLis_Sq����Lc��ֱ�Ӱ�La��Lb�ĳ�����ӵõ�Lc�ĳ���
	pc=(*Lc).elem=(LElemType_Sq*)malloc((*Lc).listsize*sizeof(LElemType_Sq));    //ָ��pcָ��Lc�ĵ�һ��Ԫ�ص�λ�ã���λ����malloc��������
	if(!pc)
		exit(OVERFLOW);				//���pc������0��Ϊ�٣�,�򱨴�

	pa_last=La.elem + La.length - 1;		//pa_last���ָ��ָ��La�����һ��Ԫ��
	pb_last=Lb.elem + Lb.length - 1;		//pb_last���ָ��ֱ��Lb�����һ��Ԫ��


	while(pa<=pa_last && pb<=pb_last)		//��ָ���λ���жϣ�la��lb��δ��ɨ����
	{
		if (*pa <= *pb)
		*pc++ = *pa++;						//��paָ��ʵʱָ�������С�ڵ���pbָ����ָ�����ݣ���paָ���ֵ��ֵ��pc�������pbָ���ֵ��ֵ��pc
		else
		*pc++ = *pb++;
	}

	while(pa<=pa_last)						//����laû�б�ɨ���꣬��ʣ�µĸ�lc
		*pc++ = *pa++;

	while(pb<=pb_last)						//����lbû�б�ɨ���꣬��ʣ�µĸ�lc
		*pc++ = *pb++;

}


#endif
