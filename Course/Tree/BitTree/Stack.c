//
// Created by cxf18 on 2022/6/11.
//

#include "Stack.h"

/*
 * 初始化二叉树栈
 * */
bool InitStack(BitTreeStack *T)
{
    (*T) == NULL;
    return true;
}

/*
 * 存=入栈
 * */
bool Push(BitTreeStack *T,BitTree *e)
{
    // 类别尾插法
    BitStack *p = (BitStack *) malloc(sizeof (BitStack));
    if(p == NULL)
        return false;
    p->data = (*e);
    p->next = (*T);
    (*T) = p;
    return true;
}

/*
 * 出栈
 * */
bool Pop(BitTreeStack *T,BitTree *e)
{
    if((*T) == NULL)
        return false;
    else
    {
        BitStack *temp = (*T);
        (*T) = temp->next;
        (*e) = temp->data;
        free(temp);
    }
    return true;
}

/*
 * 获取栈顶元素
 * */
bool GetTop(BitTreeStack *T,BitTree *e)
{
    if((*T) == NULL)
        return false;
    else
        (*e) = (*T)->data;
    return true;
}
/*
 * 判空
 * */
bool EmptyStack(BitTreeStack T)
{
    return (T == NULL)?true:false;
}