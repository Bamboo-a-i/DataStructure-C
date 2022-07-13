//
// Created by cxf18 on 2022/5/16.
//

#include "ShareStack.h"

void InitStack(ShStack *S)
{
    (*S).top[0] = -1;
    (*S).top[1] = MaxSize;
}

bool StackEmpty(ShStack S,ElemType stackNum)
{
    if(stackNum == 0 && S.top[stackNum] == -1)
    {
        printf("Õ»0Îª¿Õ\n");
        return true;
    }

    if(stackNum == 1 && S.top[stackNum] == MaxSize)
    {
        printf("Õ»1Îª¿Õ\n");
        return true;
    }
}

bool Push(ShStack *S,ElemType x,ElemType stackNum)
{
    if((*S).top[0] - (*S).top[1] == 1) // Õ»Âú
        return false;
    switch (stackNum) {
        case 0:
            (*S).data[++(*S).top[0]] = x;
            return true;
            break;
        case 1:
            (*S).data[--(*S).top[1]] = x;
            return true;
            break;
    }
    return true;
}

bool Pop(ShStack *S,ElemType *x,ElemType stackNum)
{
    switch (stackNum) {
        case 0:
            if((*S).top[stackNum] == -1) // Õ»¿Õ
                return false;
            else
            {
                (*x) = (*S).data[(*S).top[0]--];
                return true;
            }
            break;
        case 1:
            if((*S).top[stackNum] == MaxSize) // Õ»¿Õ
                return false;
            else
            {
                (*x) = (*S).data[(*S).top[1]++];
                return true;
            }
            break;
    }
    return true;
}

bool GetPop(ShStack S,ElemType *x,ElemType stackNum)
{
    if(S.top[0] - S.top[1] == 1) // Õ»Âú
        return false;
    switch (stackNum) {
        case 0:
            (*x) = S.data[S.top[0]];
            break;
        case 1:
            (*x) = S.data[S.top[1]];
            break;
        default:
            return false;
    }
    return true;
}

void PrintStack(ShStack S,ElemType stackNum)
{
    if(S.top[0] - S.top[1] == 1) // Õ»Âú
        return ;
    ElemType count = 0;
    switch (stackNum) {
        case 0:
            count = S.top[0];
            while(count != -1)
            {
                printf("S.data[%d] = %d\n",count,S.data[count]);
                count--;
            }
            break;
        case 1:
            count = S.top[1];
            while(count != MaxSize)
            {
                printf("S.data[%d] = %d\n",count,S.data[count]);
                count++;
            }
            break;
        default:
            return ;
    }
}