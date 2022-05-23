//
// Created by cxf18 on 2022/5/16.
//

#ifndef STACK_SHARESTACK_H
#define STACK_SHARESTACK_H
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "Status.h"
#define MaxSize 11 // ����ջ��Ԫ�ص�������

typedef struct
{
    ElemType data[MaxSize]; // ��̬������ջ��Ԫ��
    ElemType top[2]; // ����ջ��ָ��
}ShStack;


#endif //STACK_SHARESTACK_H

void InitStack(ShStack *S);

bool StackEmpty(ShStack S,ElemType stackNum);

bool Push(ShStack *S,ElemType x,ElemType stackNum);

bool Pop(ShStack *S,ElemType *x,ElemType stackNum); // x��������ɾ����ֵ

bool GetPop(ShStack S,ElemType *x,ElemType stackNum); // x����ջ��Ԫ��

void PrintStack(ShStack S,ElemType stackNum);
