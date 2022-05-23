//
// Created by cxf18 on 2022/5/20.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include "Status.h"
#define MaxSize 5
#endif //QUEUE_QUEUE_H
typedef struct
{
    ElemType data[MaxSize]; // ��̬����洢����Ԫ��
    int front,rear; // ��ͷָ��Ͷ�βָ��
}SqQueue;

typedef struct
{
    ElemType data[MaxSize]; // ��̬����洢����Ԫ��
    int front,rear; // ��ͷָ��Ͷ�βָ��
    int size; // ���еĵ�ǰ���� size++����ɹ���size--ɾ���ɹ�
}SqQueue1;

typedef struct
{
    ElemType data[MaxSize]; // ��̬����洢����Ԫ��
    int front,rear; // ��ͷָ��Ͷ�βָ��
    int tag; // ���������һ�β��� 0��ɾ�� 1������
}SqQueue2;

bool InitQueue(SqQueue *Q);

bool QueueEmpty(SqQueue Q);

bool EnQueue(SqQueue *Q,ElemType x);

bool DeQueue(SqQueue *Q,ElemType *x);

void GetHead(SqQueue Q,ElemType *x);

bool Destroy(SqQueue *Q);

bool PrintQueue(SqQueue Q);

bool EnQueue1(SqQueue1 *Q1,ElemType x);

bool DeQueue1(SqQueue1 *Q1,ElemType *x);

bool EnQueue2(SqQueue2 *Q2,ElemType x);

bool DeQueue2(SqQueue2 *Q2,ElemType *x);

bool PrintQueue1(SqQueue1 Q1);
