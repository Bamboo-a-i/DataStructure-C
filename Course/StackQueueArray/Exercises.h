//
// Created by cxf18 on 2022/5/22.
//

#ifndef QUEUE_EXERCISES_H
#define QUEUE_EXERCISES_H
#include "Status.h"
#endif //QUEUE_EXERCISES_H

typedef struct
{
    ElemType data[Maxsize];
    int top;
}SqStack;

bool EnQueue(SqStack *S1,SqStack *S2,ElemType e);

bool DeQueue(SqStack *S1,SqStack *S2,ElemType *e);

bool Empty(SqStack S1,SqStack S2);

bool SEmpty(SqStack S);

bool SOverFlow(SqStack S);

bool Push(SqStack *S,ElemType e);

bool Pop(SqStack *S,ElemType *e);