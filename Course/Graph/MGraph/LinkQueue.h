//
// Created by cxf18 on 2022/7/9.
//

#ifndef DATASTRUCTURE_LINKQUEUE_H
#define DATASTRUCTURE_LINKQUEUE_H
#include "Status.h"
/*
 * 数据结构 -- 用于存放图的顶点
 * */
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct
{
    LinkNode *front;
    LinkNode *rear;
}LinkQueue;

/*
 * 基本操作
 * */
bool InitLQueue(LinkQueue *LQ);
bool EmptyLQueue(LinkQueue *LQ);
bool EnLQueue(LinkQueue *LQ,ElemType e);
bool DeLQueue(LinkQueue *LQ,ElemType *e);
#endif //DATASTRUCTURE_LINKQUEUE_H
