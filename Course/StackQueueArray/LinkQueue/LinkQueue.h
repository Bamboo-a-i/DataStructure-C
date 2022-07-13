//
// Created by cxf18 on 2022/5/21.
//

#ifndef QUEUE_LINKQUEUE_H
#define QUEUE_LINKQUEUE_H
#include "Status.h"
#endif //QUEUE_LINKQUEUE_H

typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct
{
    LinkNode *front,*rear; // 队尾和队首指针
}LinkQueue;

bool InitLQueue(LinkQueue *LQ);

bool InitNHLQueue(LinkQueue *LQ);

bool EmptyLQueue(LinkQueue LQ);

bool EmptyNHLQueue(LinkQueue LQ);

bool EnLQueue(LinkQueue *LQ,ElemType x);

bool EnNHLQueue(LinkQueue *LQ,ElemType x);

bool DeLQueue(LinkQueue *LQ,ElemType *x);

bool DeNHLQueue(LinkQueue *LQ,ElemType *x);
