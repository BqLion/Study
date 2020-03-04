/**************************

�ļ��У�C03/09BankQueuing

�ļ�����BankQueuing.h

���ݣ�ģ�������Ŷ���ز����б�

************************/

#ifndef BANKQUEUING_H
#define BANKQUEUING_H

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//�궨��

#define SleepTime 1
#define DurationTime 20
#define IntervalTime 10

//���Ͷ���

typedef enum
{
    Arrive,Leave_1,Leave_2,Leave_3,Leave_4
}EventType;             //1234���뿪�ĸ��ӵĶ�����0���¿ͻ����Ķ���

typedef struct
{
    int OccurTime;
    EventType NType;
}Event;                                                         //�¼��Ķ��壺�¼�������ʱ��+������һ���¼�

typedef Event LElemType_L;          //�¼���Ҳ�������Ԫ�����ͣ�����Ҫ�����������¼����¼���

typedef struct LNode            //event������LElemType_L,�����Type��data������һ��nextָ�룬�͹������������Ľڵ㣬����Lnode
{
    LElemType_L data;
    struct LNode *next;
}LNode;

typedef LNode* LinkList;
typedef LinkList EventList;         //������һ��ָ��LNode�ڵ��ָ�룬���ָ�����ΪEventList,����Ԫ�ع��ɵ�list

#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"
typedef struct
{
    int ArrivedTime;
    int Duration;
    int Count;
}QElemType_L;
#include"E:/E/DS/C03/07LinkQueue/LinkQueue.c"

//ȫ�ֱ���

int gTotalTime,gCustomerNum;            //�ۼƿͻ�����ʱ�䣬�ͻ�����
int gCloseTime = 480;                            //����ʱ�䣬����Ӫҵ�˸�Сʱ��480����
EventList gEv;                                         //�¼���
Event gEn;                                              //�¼�
LinkQueue gQ[5];                                    //4���ͻ����У�0�ŵ�Ԫ����
QElemType_L gCustomerRcd;               //�ͻ���¼

//ģ�������ŶӺ����б�

void Bank_Simulation_1();
//(01)�㷨3.6ģ�������Ŷ��¼�

void OpenForDay();
//(02)���п��ţ���ʼ��������

Status MoreEvent();
//(03)�ж��¼����Ƿ�Ϊ��

void EventDrived(char *event);
//(04)�¼���������õ�ǰ�¼�����

void CustomerArrived();
//�ͻ������¼�

void CustomerDeparture();

void Invalid();

void CloseForDay();

int cmp(Event a,Event b);
//�Ƚ��¼�a��b�������Ⱥ����

void Random(int *durtime,int *intertime);
//�����������������ǰ�ͻ�����ҵ��ʱ�䣬����һ�ͻ�����ļ��ʱ��

Status OrderInsert(EventList gEv,Event gEn,int(cmp)(Event,Event));
//���¼������¼�������ȷ��λ��

int Minimum();
//��ǰ������̵�����

void Show();
//��ʾ��ǰ���еĿͻ��Ŷ����

void Bank_Simulation_2();
//�㷨��ģ�������Ŷ��¼�

#endif // BANKQUEUING_H
























