//
// Created by cxf18 on 2022/5/16.
//

#include "Stack.h"



void InitStack(SqStack *S)
{
    (*S).top = -1;
    // (*S).top = 0;
}

bool StackEmpty(SqStack S)
{
    // if(S.top == 0)
    if(S.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack *S,ElemType x)
{
    // if((*S).top == MaxSize)
    if((*S).top - 1 == MaxSize)
        // 栈满
        return false;
    (*S).data[++(*S).top] = x; // === S.top += 1; S.data[S.top] = x;
    // (*S).data[(*S).top++] = x;  初始栈顶为0时
    return true;
}

bool Pop(SqStack *S,ElemType *x)
{
    // if((*S).top == MaxSize)
    if((*S).top == -1) // 没有元素可以供弹出
        return false;
    (*x) = (*S).data[(*S).top--]; // === x = S.data[S.top];S.top--;
    // (*x) = (*S).data[--(*S).top]; 初始栈顶为0时
    return true;
}

bool GetPop(SqStack S,ElemType *x)
{
    if(S.top == -1) // 没有元素可以供弹出
        return false;
    (*x) = S.data[S.top];
    return true;
}

void PrintStack(SqStack S)
{
    if(S.top == -1)
        return;
    ElemType count = S.top;
    while(count != -1)
    {
        printf("S.data[%d] = %d\n",count,S.data[count]);
        count--;
    }
}