//
// Created by cxf18 on 2022/5/16.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include "Status.h"
#endif //STACK_STACK_H

#define MaxSize 50 // 定义栈中元素的最大个数
typedef struct
{
    ElemType data[MaxSize]; // 静态数组存放栈中元素
    ElemType top; // 栈顶指针
}SqStack;

void InitStack(SqStack *S);

bool StackEmpty(SqStack S);

bool Push(SqStack *S,ElemType x);

bool Pop(SqStack *S,ElemType *x); // x用来接受删除的值

bool GetPop(SqStack S,ElemType *x); // x返回栈顶元素

void PrintStack(SqStack S);