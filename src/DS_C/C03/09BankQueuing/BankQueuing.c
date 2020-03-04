/*******************************

文件夹：C03栈和队列 /09BankQueuing

BankQueuing.c

算法:3.6、3.7

*******************************/

#ifndef BANKQUEUING_C
#define BANKQUEUING_C

#include "BankQueuing.h"

void Bank_Simulation_1()        //银行业务模拟，统计一天内客户在银行逗留的平均时间
{
    char eventType;         //字符型的变量，功能是从EventDrived函数中取得一个字符A  或者  D

PressEnter;
    OpenForDay();
 PressEnter;
    while(MoreEvent())
    {
        EventDrived(&eventType);            //事件驱动器，进行下一个事件(从事件表表头取出元素，判断下一步的动作，如果是来，就安排来的函数；如果是去，就安排相应的去函数执行相应操作)
 PressEnter;
        switch(eventType)
        {
        case 'A':
PressEnter;
            CustomerArrived();
            break;
        case 'D':
 PressEnter;
            CustomerDeparture();
            break;
        default:
            Invalid();
        }
    }
 PressEnter;

    CloseForDay();
}

void OpenForDay()                   //对变量和数据结构的说明：event是事件，包含发生的时间和类型。Lnode是节点，包含event，加一个指针。LinkList就是LNode组成的链表.QElemType_L是”客户记录队列“的数据类型，包括到达时间，办理业务所需时间，位序三个元素。
{                                               //gTotalTime 和gCustomerNum是两个全局变量，记录总时间和人数。gEv是事件表。gEn是事件表里的事件。
    int i;

    gTotalTime = 0;         //初始化累计时间和客户数，都为0
    gCustomerNum = 0;
    InitList_L(&gEv);         //初始化事件链表为空表
    gEn.OccurTime = 0;                  //temp event里，time和type都初始化为0和arrive
    gEn.NType = Arrive;
    OrderInsert(gEv,gEn,cmp);           //把这个temp（gEn）放进gEv表的合适位置
    for (i=1;i<=4;i++)
        InitQueue_L(&gQ[i]);
    Show();
}

Status MoreEvent()
{
    if(!ListEmpty_L(gEv))
       return TRUE;
       else
        return FALSE;

}

void EventDrived(char *event)
{
    ListDelete_L(gEv,1,&gEn);

    if(gEn.NType==Arrive)
        *event='A';
    else
        *event='D';
}


void CustomerArrived()              //新客户来了，马上算出下一位客户到达时间，并算出两种数据分别对应两种情况用：1.到达时间+需要办理时间+位序；用于需要排队时使用。2.本客户将要离开的时间；用于不用排队，直接安排的情况，这种情况可直接把本客户的离开动作插入进是事件表
{
    int durtime,intertime;
    int cur_LeftTime,suc_ArrivalTime;
    int i;

    ++gCustomerNum;

    Random(&durtime,&intertime);
    cur_LeftTime = gEn.OccurTime+durtime;
    suc_ArrivalTime = gEn.OccurTime +  intertime;           //新的客户来了，这个客户的离开时间和下个客户的到达时间已生成，赋值到temp中

    gCustomerRcd.ArrivedTime = gEn.OccurTime;           //当前客户信息，将到达事件，需要时间，位序记录下来
     gCustomerRcd.Duration = durtime;
      gCustomerRcd.Count = gCustomerNum;

    i= Minimum(gQ);
    EnQueue_L(&gQ[i],gCustomerRcd);         //求出长度最短队列，把客户信息插入到队列中
    Show();

    if(suc_ArrivalTime<gCloseTime)
    {
        gEn.OccurTime = suc_ArrivalTime;
        gEn.NType = Arrive;
        OrderInsert(gEv,gEn,cmp);          //如果下一位客户来的时间还没关门，就把下一位客户的到达这一事件插入到事件表中
    }

if(QueueLength_L(gQ[i])==1)            //本客户的信息已经插入进队列了，判断队列长度是否为1，如果为1，说明不用等待，直接把离开的时间算出来，插入到事件表中。
{
    gEn.OccurTime = cur_LeftTime;
    gEn.NType = i;
    OrderInsert(gEv,gEn,cmp);
}

}

void CustomerDeparture()
{
    int i  = gEn.NType;

    DeQueue_L(&gQ[i],&gCustomerRcd);        //把队列gQ[]的排头客户信息删除掉
    Show();

    gTotalTime += gEn.OccurTime-gCustomerRcd.ArrivedTime;

    if(!QueueEmpty_L(gQ[i]))            //如果删除后的队列非空，那就把下一个元素的离开事件插入事件表，因为下一个事件在进入排队的时候没有插入事件表。 离开时间==当前时间+需要时间
    {
        GetHead_L(gQ[i],&gCustomerRcd);             //获得队列新头元素，把相关数据赋值给temp
        gEn.OccurTime += gCustomerRcd.Duration; //temp中，发生时间=当前时间+记录中的需要时间
        gEn.NType = i;                                             //发生类型=所在队列序号
        OrderInsert(gEv,gEn,cmp);                           //插入动作
    }
}


void Invalid()
{
    printf("运行错误！！");
    exit(OVERFLOW);
}

void CloseForDay()
{
    printf("当天总共有%d个客户，平均逗留时间为%d分钟。\n",gCustomerNum,gTotalTime/gCustomerNum);
}

int cmp(Event a,Event b)
{
    if(a.OccurTime<b.OccurTime)
        return -1;
    if(a.OccurTime==b.OccurTime)
        return 0;
    if(a.OccurTime>b.OccurTime)
        return 1;
}

void Random(int *durtime,int *intertime)
{
    srand((unsigned)time(NULL));
    *durtime = rand()%DurationTime+1;           //办理业务时间是随机数对20求余+1，结果必然是1-20之间的数
    *intertime = rand()%IntervalTime+1;           //下一个顾客来的时间是1-20分钟之间
}

Status OrderInsert(EventList gEv,Event gEn,int(cmp)(Event,Event))
{
    int i;
    EventList p,pre,s;
    p = gEv->next;

    while(p && cmp(gEn,p->data)==1)
    {
        pre = p;            //寻找gEn在事件表中该插入的位置
        p = p->next;
    }

    s = (LinkList)malloc(sizeof(LNode));
    if(!s)
        exit(OVERFLOW);

    s->data =gEn;
    s->next = pre->next;
    pre->next = s;

    return OK;

}

int Minimum()
{
    int i1 = QueueLength_L(gQ[1]);
    int i2 = QueueLength_L(gQ[2]);
    int i3 = QueueLength_L(gQ[3]);
    int i4 = QueueLength_L(gQ[4]);

    if(i1<=i2 && i1<i3 && i1<i4)
        return 1;
    if(i2<=i1 && i2<i3 && i2<i4)
        return 2;
    if(i3<=i1 && i3<i2 && i3<i4)
        return 3;
    if(i4<=i1 && i4<i2 && i4<i3)
        return 4;
}

void Show()
{
    int i;
    QueuePtr p;

    system("cls");

    for(i=1;i<=4;i++)
    {
    for(p=gQ[i].front;p;p=p->next)
    {
        if(p==gQ[i].front)
        {
        if(i==1)
            printf("柜台1");
        if(i==2)
            printf("柜台1");
        if(i==3)
            printf("柜台1");
        if(i==4)
            printf("柜台1");
        }
        else
            printf("(%03d)",p->data.Count);

        if(p == gQ[i].rear)
            printf("\n");
    }
    }
    Wait(SleepTime);
}

//算法3.7
void Bank_Simulation_2()
{
    OpenForDay();

    while(!ListEmpty_L(gEv))
    {
        ListDelete_L(gEv,1,&gEn);

        if(gEn.NType==Arrive)
            CustomerArrived();
        else
            CustomerDeparture();

    }
    printf("当天总共有%d个客户，平均逗留时间为%d分钟，gCustomerNum，gTotalTime/gCustomerNum");


}

#endif // BANKQUEUING_C











