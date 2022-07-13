//
// Created by cxf18 on 2022/5/16.
//

#ifndef STACK_SHARESTACK_H
#define STACK_SHARESTACK_H
#include "Status.h"
#define MaxSize 11 // 定义栈中元素的最大个数

typedef struct
{
    ElemType data[MaxSize]; // 静态数组存放栈中元素
    ElemType top[2]; // 两个栈的指针
}ShStack;


#endif //STACK_SHARESTACK_H

void InitStack(ShStack *S);

bool StackEmpty(ShStack S,ElemType stackNum);

bool Push(ShStack *S,ElemType x,ElemType stackNum);

bool Pop(ShStack *S,ElemType *x,ElemType stackNum); // x用来接受删除的值

bool GetPop(ShStack S,ElemType *x,ElemType stackNum); // x返回栈顶元素

void PrintStack(ShStack S,ElemType stackNum);
