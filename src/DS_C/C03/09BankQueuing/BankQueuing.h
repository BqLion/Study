/**************************

文件夹：C03/09BankQueuing

文件名：BankQueuing.h

内容：模拟银行排队相关操作列表

************************/

#ifndef BANKQUEUING_H
#define BANKQUEUING_H

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include"E:/E/DS/C02/01SequenceList/Status.h"

//宏定义

#define SleepTime 1
#define DurationTime 20
#define IntervalTime 10

//类型定义

typedef enum
{
    Arrive,Leave_1,Leave_2,Leave_3,Leave_4
}EventType;             //1234是离开四个队的动作，0是新客户来的动作

typedef struct
{
    int OccurTime;
    EventType NType;
}Event;                                                         //事件的定义：事件发生的时间+它是哪一类事件

typedef Event LElemType_L;          //事件，也称作表的元素类型（马上要定义关于这个事件的事件表）

typedef struct LNode            //event改名叫LElemType_L,把这个Type的data，加上一个next指针，就构成了这个链表的节点，叫做Lnode
{
    LElemType_L data;
    struct LNode *next;
}LNode;

typedef LNode* LinkList;
typedef LinkList EventList;         //定义了一个指向LNode节点的指针，这个指针改名为EventList,就是元素构成的list

#include"E:/E/DS/C02/04SinglyLinkedList/SinglyLinkedList.c"
typedef struct
{
    int ArrivedTime;
    int Duration;
    int Count;
}QElemType_L;
#include"E:/E/DS/C03/07LinkQueue/LinkQueue.c"

//全局变量

int gTotalTime,gCustomerNum;            //累计客户逗留时间，客户数量
int gCloseTime = 480;                            //关门时间，假设营业八个小时，480分钟
EventList gEv;                                         //事件表
Event gEn;                                              //事件
LinkQueue gQ[5];                                    //4个客户队列，0号单元弃用
QElemType_L gCustomerRcd;               //客户记录

//模拟银行排队函数列表

void Bank_Simulation_1();
//(01)算法3.6模拟银行排队事件

void OpenForDay();
//(02)银行开门，初始化各变量

Status MoreEvent();
//(03)判断事件表是否为空

void EventDrived(char *event);
//(04)事件驱动，获得当前事件类型

void CustomerArrived();
//客户到达事件

void CustomerDeparture();

void Invalid();

void CloseForDay();

int cmp(Event a,Event b);
//比较事件a和b发生的先后次序

void Random(int *durtime,int *intertime);
//生成随机数，包括当前客户办理业务时间，和下一客户到达的间隔时间

Status OrderInsert(EventList gEv,Event gEn,int(cmp)(Event,Event));
//将事件插入事件表中正确的位置

int Minimum();
//求当前长度最短的序列

void Show();
//显示当前队列的客户排队情况

void Bank_Simulation_2();
//算法：模拟银行排队事件

#endif // BANKQUEUING_H
























