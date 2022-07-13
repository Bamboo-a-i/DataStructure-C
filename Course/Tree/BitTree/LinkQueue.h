//
// Created by cxf18 on 2022/6/9.
//

#ifndef DATASTRUCTURE_LINKQUEUE_H
#define DATASTRUCTURE_LINKQUEUE_H
#include "BitTree.h"

/*
 * 链式队列存储二叉树数据结构 及其操作实现
 * */
typedef struct LinkBTNode
{
    BitNode *data;
    struct LinkBTNode *next;
}LinkBTNode;

typedef struct
{
    LinkBTNode *front,*rear;
}LinkBTQueue;

/*
 * 1.初始化
 * 2.判空
 * 3.入队
 * 4.出队
 * */
bool InitLQueue(LinkBTQueue *LQ);
bool EmptyLQueue(LinkBTQueue LQ);
bool EnLQueue(LinkBTQueue *LQ,BitTree *bitTree);
bool DeLQueue(LinkBTQueue *LQ,BitTree *bitTree);

#endif //DATASTRUCTURE_LINKQUEUE_H
