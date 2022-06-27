//
// Created by cxf18 on 2022/6/11.
//

#include "Stack.h"

/*
 * ��ʼ��������ջ
 *
 * ������BitTreeStack *T
 *
 * */
bool InitBitStack(BitTreeStack *T)
{
    (*T) == NULL;
    return true;
}

/*
 * ��=��ջ
 *
 * ������BitTreeStack *T
 *
 * */
bool Push(BitTreeStack *T,BitTree *e)
{
    // ���β�巨
    BitStack *p = (BitStack *) malloc(sizeof (BitStack));
    if(p == NULL)
        return false;
    p->data = (*e);
    p->next = (*T);
    (*T) = p;
    return true;
}

/*
 * ��ջ
 *
 * ������BitTreeStack *T BitNode *e
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
 * ��ȡջ��Ԫ��
 *
 * ������BitTreeStack *T  BitNode *e
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
 * �п�
 *
 * ������BitTreeStack *T
 *
 * */
bool EmptyStackTree(BitTreeStack T)
{
    return (T == NULL)?true:false;
}