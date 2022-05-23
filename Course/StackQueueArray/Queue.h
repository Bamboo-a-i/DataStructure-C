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
    ElemType data[MaxSize]; // 静态数组存储队列元素
    int front,rear; // 对头指针和队尾指针
}SqQueue;

typedef struct
{
    ElemType data[MaxSize]; // 静态数组存储队列元素
    int front,rear; // 对头指针和队尾指针
    int size; // 队列的当前长度 size++插入成功，size--删除成功
}SqQueue1;

typedef struct
{
    ElemType data[MaxSize]; // 静态数组存储队列元素
    int front,rear; // 对头指针和队尾指针
    int tag; // 队列最近的一次操作 0：删除 1：插入
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
