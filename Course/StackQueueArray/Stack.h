//
// Created by cxf18 on 2022/5/16.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include "Status.h"
#endif //STACK_STACK_H

#define MaxSize 50 // ����ջ��Ԫ�ص�������
typedef struct
{
    ElemType data[MaxSize]; // ��̬������ջ��Ԫ��
    ElemType top; // ջ��ָ��
}SqStack;

void InitStack(SqStack *S);

bool StackEmpty(SqStack S);

bool Push(SqStack *S,ElemType x);

bool Pop(SqStack *S,ElemType *x); // x��������ɾ����ֵ

bool GetPop(SqStack S,ElemType *x); // x����ջ��Ԫ��

void PrintStack(SqStack S);