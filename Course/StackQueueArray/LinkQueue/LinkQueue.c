//
// Created by cxf18 on 2022/5/21.
//

#include "LinkQueue.h"


bool InitLQueue(LinkQueue *LQ)
{
    LinkNode *p = (LinkNode *) malloc(sizeof (LinkNode));
    if(p ==  NULL)
        return false;
    (*LQ).front = (*LQ).rear = p; // 指向同一块内存地址
    (*LQ).front->next = NULL; // 初始化为NULL
    return true;
}

bool InitNHLQueue(LinkQueue *LQ)
{
    (*LQ).front = (*LQ).rear = NULL;
    return true;
}

bool EmptyLQueue(LinkQueue LQ)
{
    if(LQ.rear == LQ.front)
        return true;
    else
        return false;
}

bool EmptyNHLQueue(LinkQueue LQ)
{
    if(LQ.front == NULL) // 头结点都为空
        return true;
    else
        return false;
}

bool EnLQueue(LinkQueue *LQ,ElemType x)
{
    // 链表没有满队这一说
    LinkNode *insertNode = (LinkNode *) malloc(sizeof (LinkNode));
    insertNode->data = x;
    insertNode->next = NULL;
    (*LQ).rear->next = insertNode; // 尾插
    (*LQ).rear = insertNode; // 尾随
    return true;
}

bool EnNHLQueue(LinkQueue *LQ,ElemType x)
{
    LinkNode *insertNode = (LinkNode *) malloc(sizeof (LinkNode));
    insertNode->data = x;
    insertNode->next = NULL;
    if((*LQ).front ==  NULL) // 第一个结点
    {
        (*LQ).front = insertNode;// 尾插 队首
        (*LQ).rear = insertNode;// 尾随
        return true;
    }
    else
    {
        (*LQ).rear->next = insertNode; // 只需要移动队尾即可。
        (*LQ).rear = insertNode;
        return true;
    }
}

bool DeLQueue(LinkQueue *LQ,ElemType *x)
{
    if((*LQ).front == (*LQ).rear)
        return false; // 队空 -- 队首等于了队尾
    LinkNode *deNode = (*LQ).front->next;
    (*x) = deNode->data;
    (*LQ).front->next = deNode->next; // 断开连接
    if((*LQ).rear == deNode) // 删除的是最后一个结点时
        (*LQ).rear = (*LQ).front;
    free(deNode);
    return true;
}

bool DeNHLQueue(LinkQueue *LQ,ElemType *x)
{
    if((*LQ).front == NULL)
        return false; // 队空 -- 队首等于了队尾
    LinkNode *deNode = (*LQ).front;
    (*x) = deNode->data;
    (*LQ).front = deNode->next; // 断开连接
    if((*LQ).rear == deNode) // 删除的是最后一个结点时
    {
        (*LQ).rear = NULL;
        (*LQ).front = NULL;
    }
    free(deNode);
    return true;
}