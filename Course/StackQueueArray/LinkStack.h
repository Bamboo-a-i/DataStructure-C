//
// Created by cxf18 on 2022/5/18.
//

#ifndef STACK_LINKSTACK_H
#define STACK_LINKSTACK_H
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "Status.h"
#endif //STACK_LINKSTACK_H
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
}LsNode,*LinkStack;

bool InitStack(LinkStack *Ls);

bool Empty(LinkStack *Ls);

bool Push(LinkStack *Ls,ElemType e);

bool Pop(LinkStack *Ls,ElemType *e);

bool GetPop(LinkStack *Ls,ElemType *e);

bool PrintLinkStack(LinkStack *Ls);