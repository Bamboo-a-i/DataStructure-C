//
// Created by cxf18 on 2022/6/11.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H
#include "Status.h"
#include "BitTree.h"

/*
 * 定义二叉树栈的数据结构
 * */
typedef struct BitStack
{
    BitNode *data;
    struct BitStack *next;
}BitStack,*BitTreeStack;

/*
 * 基础操作
 * 1.初始化
 * 2.入栈
 * 3.出栈
 * 4.获取栈顶元素
 * 5.判空
 * */
bool InitStack(BitTreeStack *T);
bool Push(BitTreeStack *T,BitTree *e);
bool Pop(BitTreeStack *T,BitTree *e);
bool GetTop(BitTreeStack *T,BitTree *e);
bool EmptyStack(BitTreeStack T);

#endif //DATASTRUCTURE_STACK_H
