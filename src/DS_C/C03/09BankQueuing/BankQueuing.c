/*******************************

�ļ��У�C03ջ�Ͷ��� /09BankQueuing

BankQueuing.c

�㷨:3.6��3.7

*******************************/

#ifndef BANKQUEUING_C
#define BANKQUEUING_C

#include "BankQueuing.h"

void Bank_Simulation_1()        //����ҵ��ģ�⣬ͳ��һ���ڿͻ������ж�����ƽ��ʱ��
{
    char eventType;         //�ַ��͵ı����������Ǵ�EventDrived������ȡ��һ���ַ�A  ����  D

PressEnter;
    OpenForDay();
 PressEnter;
    while(MoreEvent())
    {
        EventDrived(&eventType);            //�¼���������������һ���¼�(���¼����ͷȡ��Ԫ�أ��ж���һ���Ķ���������������Ͱ������ĺ����������ȥ���Ͱ�����Ӧ��ȥ����ִ����Ӧ����)
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

void OpenForDay()                   //�Ա��������ݽṹ��˵����event���¼�������������ʱ������͡�Lnode�ǽڵ㣬����event����һ��ָ�롣LinkList����LNode��ɵ�����.QElemType_L�ǡ��ͻ���¼���С����������ͣ���������ʱ�䣬����ҵ������ʱ�䣬λ������Ԫ�ء�
{                                               //gTotalTime ��gCustomerNum������ȫ�ֱ�������¼��ʱ���������gEv���¼���gEn���¼�������¼���
    int i;

    gTotalTime = 0;         //��ʼ���ۼ�ʱ��Ϳͻ�������Ϊ0
    gCustomerNum = 0;
    InitList_L(&gEv);         //��ʼ���¼�����Ϊ�ձ�
    gEn.OccurTime = 0;                  //temp event�time��type����ʼ��Ϊ0��arrive
    gEn.NType = Arrive;
    OrderInsert(gEv,gEn,cmp);           //�����temp��gEn���Ž�gEv��ĺ���λ��
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


void CustomerArrived()              //�¿ͻ����ˣ����������һλ�ͻ�����ʱ�䣬������������ݷֱ��Ӧ��������ã�1.����ʱ��+��Ҫ����ʱ��+λ��������Ҫ�Ŷ�ʱʹ�á�2.���ͻ���Ҫ�뿪��ʱ�䣻���ڲ����Ŷӣ�ֱ�Ӱ��ŵ���������������ֱ�Ӱѱ��ͻ����뿪������������¼���
{
    int durtime,intertime;
    int cur_LeftTime,suc_ArrivalTime;
    int i;

    ++gCustomerNum;

    Random(&durtime,&intertime);
    cur_LeftTime = gEn.OccurTime+durtime;
    suc_ArrivalTime = gEn.OccurTime +  intertime;           //�µĿͻ����ˣ�����ͻ����뿪ʱ����¸��ͻ��ĵ���ʱ�������ɣ���ֵ��temp��

    gCustomerRcd.ArrivedTime = gEn.OccurTime;           //��ǰ�ͻ���Ϣ���������¼�����Ҫʱ�䣬λ���¼����
     gCustomerRcd.Duration = durtime;
      gCustomerRcd.Count = gCustomerNum;

    i= Minimum(gQ);
    EnQueue_L(&gQ[i],gCustomerRcd);         //���������̶��У��ѿͻ���Ϣ���뵽������
    Show();

    if(suc_ArrivalTime<gCloseTime)
    {
        gEn.OccurTime = suc_ArrivalTime;
        gEn.NType = Arrive;
        OrderInsert(gEv,gEn,cmp);          //�����һλ�ͻ�����ʱ�仹û���ţ��Ͱ���һλ�ͻ��ĵ�����һ�¼����뵽�¼�����
    }

if(QueueLength_L(gQ[i])==1)            //���ͻ�����Ϣ�Ѿ�����������ˣ��ж϶��г����Ƿ�Ϊ1�����Ϊ1��˵�����õȴ���ֱ�Ӱ��뿪��ʱ������������뵽�¼����С�
{
    gEn.OccurTime = cur_LeftTime;
    gEn.NType = i;
    OrderInsert(gEv,gEn,cmp);
}

}

void CustomerDeparture()
{
    int i  = gEn.NType;

    DeQueue_L(&gQ[i],&gCustomerRcd);        //�Ѷ���gQ[]����ͷ�ͻ���Ϣɾ����
    Show();

    gTotalTime += gEn.OccurTime-gCustomerRcd.ArrivedTime;

    if(!QueueEmpty_L(gQ[i]))            //���ɾ����Ķ��зǿգ��ǾͰ���һ��Ԫ�ص��뿪�¼������¼�����Ϊ��һ���¼��ڽ����Ŷӵ�ʱ��û�в����¼��� �뿪ʱ��==��ǰʱ��+��Ҫʱ��
    {
        GetHead_L(gQ[i],&gCustomerRcd);             //��ö�����ͷԪ�أ���������ݸ�ֵ��temp
        gEn.OccurTime += gCustomerRcd.Duration; //temp�У�����ʱ��=��ǰʱ��+��¼�е���Ҫʱ��
        gEn.NType = i;                                             //��������=���ڶ������
        OrderInsert(gEv,gEn,cmp);                           //���붯��
    }
}


void Invalid()
{
    printf("���д��󣡣�");
    exit(OVERFLOW);
}

void CloseForDay()
{
    printf("�����ܹ���%d���ͻ���ƽ������ʱ��Ϊ%d���ӡ�\n",gCustomerNum,gTotalTime/gCustomerNum);
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
    *durtime = rand()%DurationTime+1;           //����ҵ��ʱ�����������20����+1�������Ȼ��1-20֮�����
    *intertime = rand()%IntervalTime+1;           //��һ���˿�����ʱ����1-20����֮��
}

Status OrderInsert(EventList gEv,Event gEn,int(cmp)(Event,Event))
{
    int i;
    EventList p,pre,s;
    p = gEv->next;

    while(p && cmp(gEn,p->data)==1)
    {
        pre = p;            //Ѱ��gEn���¼����иò����λ��
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
            printf("��̨1");
        if(i==2)
            printf("��̨1");
        if(i==3)
            printf("��̨1");
        if(i==4)
            printf("��̨1");
        }
        else
            printf("(%03d)",p->data.Count);

        if(p == gQ[i].rear)
            printf("\n");
    }
    }
    Wait(SleepTime);
}

//�㷨3.7
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
    printf("�����ܹ���%d���ͻ���ƽ������ʱ��Ϊ%d���ӣ�gCustomerNum��gTotalTime/gCustomerNum");


}

#endif // BANKQUEUING_C











