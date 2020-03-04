/*********************************

�ļ��У�charpter02/02union

�ļ�����Union.c

�㷨��2.1�鲢�������Ա�ľ���ʵ��

*********************************/

#ifndef UNION_C
#define UNION_C
#include "E:/E/DS/C02/01SequenceList/SequenceList.h"
#include "Union.h"  //��֮ǰ�ĸ��ֶ�����ĺ�����������������֮ǰд��ͬ��ͷ�ļ������

//�㷨2.1 �鲢�������Ա�

void Union(SqList *La,SqList Lb)
{
	int La_len,Lb_len;
	int i;
	LElemType_Sq e;

	La_len=ListLength_Sq(*La);		//��˳����ȵĺ���
	Lb_len=ListLength_Sq(Lb);

	for(i=1;i<=Lb_len;i++)			//��Lb��La��߹鲢
	{
		GetElem_Sq(Lb,i,&e);		//GetElem_Sq���������������ֱ������Ա�Lb����i��Ԫ�أ���ȡeԪ�أ�����eԪ�ص�λ�ã�		������Lb����ÿ��Ԫ�ض�ȡһ�����e��
		if(!LocateElem_Sq(*La,e,equal))	//���LOCATE����������0ִ�����²���������e����equal��ϵ��Ԫ�ز���La������Ա����� ����ÿ�ζ���Lb��ߵ�Ԫ�ض���La���Ԫ��ƥ��һ�£����û���ظ��ģ������²�����
			ListInsert_Sq(La,++La_len,e);//��e��Lb���Ԫ��insert��La�������
	}
}

Status equal(LElemType_Sq e1,LElemType_Sq e2)  //equal���������������ж����Ա��е�Ԫ���Ƿ���ȣ�����ȷ���1������ȷ���0.
{
	return e1 == e2 ? TRUE:FALSE;
}

#endif
