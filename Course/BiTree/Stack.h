//
// Created by cxf18 on 2022/6/11.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H
#include "Status.h"
#include "BitTree.h"

// ���������ջ
typedef struct BitStack
{
    BitNode *data;
    struct BitStack *next;
}BitStack,*BitTreeStack;

// ��������
bool InitBitStack(BitTreeStack *T);

bool Push(BitTreeStack *T,BitTree *e);

bool Pop(BitTreeStack *T,BitTree *e);

bool GetTop(BitTreeStack *T,BitTree *e);

bool EmptyStackTree(BitTreeStack T);

#endif //DATASTRUCTURE_STACK_H
