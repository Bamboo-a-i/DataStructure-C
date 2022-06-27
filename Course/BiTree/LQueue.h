//
// Created by cxf18 on 2022/6/9.
//

#ifndef DATASTRUCTURE_LQUEUE_H
#define DATASTRUCTURE_LQUEUE_H
#include "Status.h"
#include "BitTree.h"
typedef struct LinkNode
{
    BitNode *data;
    struct LinkNode *next;
}LinkNode;

typedef struct
{
    LinkNode *front,*rear;
}LinkQueue;

// 初始化
bool InitQueue(LinkQueue *LQ);
// 判空
bool EmptyQueue(LinkQueue LQ);
// 入队
bool EnQueue(LinkQueue *LQ,BitTree *bitTree);
// 出队
bool DeQueue(LinkQueue *LQ,BitTree *bitTree);
#endif //DATASTRUCTURE_LQUEUE_H
