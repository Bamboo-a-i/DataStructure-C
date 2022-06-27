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

// ��ʼ��
bool InitQueue(LinkQueue *LQ);
// �п�
bool EmptyQueue(LinkQueue LQ);
// ���
bool EnQueue(LinkQueue *LQ,BitTree *bitTree);
// ����
bool DeQueue(LinkQueue *LQ,BitTree *bitTree);
#endif //DATASTRUCTURE_LQUEUE_H
