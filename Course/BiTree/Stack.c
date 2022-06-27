//
// Created by cxf18 on 2022/6/11.
//

#include "Stack.h"

/*
 * 初始化二叉树栈
 *
 * 参数：BitTreeStack *T
 *
 * */
bool InitBitStack(BitTreeStack *T)
{
    (*T) == NULL;
    return true;
}

/*
 * 存=入栈
 *
 * 参数：BitTreeStack *T
 *
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
 *
 * 参数：BitTreeStack *T BitNode *e
 *
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
 *
 * 参数：BitTreeStack *T  BitNode *e
 *
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
 *
 * 参数：BitTreeStack *T
 *
 * */
bool EmptyStackTree(BitTreeStack T)
{
    return (T == NULL)?true:false;
}