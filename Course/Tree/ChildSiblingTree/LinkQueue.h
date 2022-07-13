//
// Created by cxf18 on 2022/7/5.
//

#ifndef DATASTRUCTURE_LINKQUEUE_H
#define DATASTRUCTURE_LINKQUEUE_H
#include "ChildSiblingTree.h"
/*
 * 链式队列存储树(孩子兄弟表示法)数据结构 及其操作实现
 * */
typedef struct LinkNode
{
    CSNode *data;
    struct LinkNode *next;
}LinkNode;

typedef struct
{
    LinkNode *front,*rear;
}LinkQueue;

/*
 * 1.初始化
 * 2.判空
 * 3.入队
 * 4.出队
 * */
bool InitQueue(LinkQueue *LQ);
bool EmptyQueue(LinkQueue LQ);
bool EnQueue(LinkQueue *LQ,CSTree *csTree);
bool DeQueue(LinkQueue *LQ,CSTree *csTree);
#endif //DATASTRUCTURE_LINKQUEUE_H
