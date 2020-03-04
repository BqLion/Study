 /********************
 循环队列:  顺序存储结构的队列中，因为是下删上增的存储结构，如果所有的空间都经历了存储-删除的操作

 最终头尾指针都会集中在最后，这时在进行增的操作就会报错溢出。导致前边的内存被浪费。为解决这种浪费，在逻辑上把申请的内存空间优化成一个圈，

 出现上述所说一边报溢出，另一边空置内存浪费的情况，就拐过来从第一个内存开始申请使用，构成了一个圈

 循环队列是队列的一种变体，仍然遵循FIFO,LILO的原则

 *******************/

 #ifndef CYLSEQQUEUE_H
 #define CYLSEQQUEUE_H

 #include <stdio.h>
 #include<stdlib.h>
 #include"E:/E/DS/C02/01SequenceList/Status.h"

 #define MAXQSIZE 1000 //最大队列长度

 //循环队列类型定义

 typedef int QElemType_CSq;
 typedef struct
 {
    QElemType_CSq *base;
    int front;
    int rear;
 }CSqQueue;         //顺序队列还是用数组定义的，所以前后指针都是int

//循环队列函数列表

Status InitQueue_CSq(CSqQueue *Q);
//初始化循环队列Q

void ClearQueue_CSq(CSqQueue *Q);
//置空Q

void DestroyQueue_CSq(CSqQueue *Q);

Status QueueEmpty_CSq(CSqQueue Q);

int QueueLength_CSq(CSqQueue Q);

Status Head_CSq(CSqQueue *Q,QElemType_CSq e);
//元素e入队

Status DeQueue_CSq(CSqQueue *Q,QElemType_CSq *e);

void QueueTraverse_CSq(CSqQueue Q,void(Visit)(QElemType_CSq));
//循环访问队列

#endif // CYLSEQQUEUE_H

