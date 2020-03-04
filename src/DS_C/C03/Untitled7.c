 /********************
 ѭ������:  ˳��洢�ṹ�Ķ����У���Ϊ����ɾ�����Ĵ洢�ṹ��������еĿռ䶼�����˴洢-ɾ���Ĳ���

 ����ͷβָ�붼�Ἧ���������ʱ�ڽ������Ĳ����ͻᱨ�����������ǰ�ߵ��ڴ汻�˷ѡ�Ϊ��������˷ѣ����߼��ϰ�������ڴ�ռ��Ż���һ��Ȧ��

 ����������˵һ�߱��������һ�߿����ڴ��˷ѵ�������͹չ����ӵ�һ���ڴ濪ʼ����ʹ�ã�������һ��Ȧ

 ѭ�������Ƕ��е�һ�ֱ��壬��Ȼ��ѭFIFO,LILO��ԭ��

 *******************/

 #ifndef CYLSEQQUEUE_H
 #define CYLSEQQUEUE_H

 #include <stdio.h>
 #include<stdlib.h>
 #include"E:/E/DS/C02/01SequenceList/Status.h"

 #define MAXQSIZE 1000 //�����г���

 //ѭ���������Ͷ���

 typedef int QElemType_CSq;
 typedef struct
 {
    QElemType_CSq *base;
    int front;
    int rear;
 }CSqQueue;         //˳����л��������鶨��ģ�����ǰ��ָ�붼��int

//ѭ�����к����б�

Status InitQueue_CSq(CSqQueue *Q);
//��ʼ��ѭ������Q

void ClearQueue_CSq(CSqQueue *Q);
//�ÿ�Q

void DestroyQueue_CSq(CSqQueue *Q);

Status QueueEmpty_CSq(CSqQueue Q);

int QueueLength_CSq(CSqQueue Q);

Status Head_CSq(CSqQueue *Q,QElemType_CSq e);
//Ԫ��e���

Status DeQueue_CSq(CSqQueue *Q,QElemType_CSq *e);

void QueueTraverse_CSq(CSqQueue Q,void(Visit)(QElemType_CSq));
//ѭ�����ʶ���

#endif // CYLSEQQUEUE_H

