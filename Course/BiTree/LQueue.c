//
// Created by cxf18 on 2022/6/9.
//

#include "LQueue.h"

/*
 * 初始化
 *
 * 参数:LinkQueue
 *
 * 返回:bool
 * */
bool InitQueue(LinkQueue *LQ)
{
    LinkNode *p = (LinkNode *) malloc(sizeof (LinkNode));
    if(p == NULL)
        return false;
    (*LQ).front = (*LQ).rear = p;
    (*LQ).front->next = NULL;
    return true;
}
/*
 * 判空
 *
 * 参数:LinkQueue
 *
 * 返回:bool
 * */
bool EmptyQueue(LinkQueue LQ)
{
    // 判空条件有所变化 需要判断front 和rear 指向的结点的值是否为NULL
    if(LQ.front ==  LQ.rear && LQ.front->next == NULL && LQ.rear->next == NULL)
        return true;
    else
        return false;
}

/*
 * 入队
 *
 * 参数:LinkQueue
 *
 * 返回:bool
 * */
bool EnQueue(LinkQueue *LQ,BitTree *bitTree)
{
    LinkNode *insertNode = (LinkNode *) malloc(sizeof (LinkNode));
    insertNode->data = *bitTree;
    insertNode->next = NULL;
    (*LQ).rear->next = insertNode; // 尾插
    (*LQ).rear = insertNode; // 尾随
    return true;
}

/*
 * 出队
 *
 * 参数:LinkQueue 存储二叉树结点,bitNode结点值
 *
 * 返回:bool
 * */
bool DeQueue(LinkQueue *LQ,BitTree *bitTree)
{
    if((*LQ).rear == (*LQ).front)
        return false;
    LinkNode *deNode = (*LQ).front->next; // 此处选择next是因为front 并没有存储数据，可以理解为一种不完全的头结点。
    *bitTree = deNode->data; // 获取数据
    (*LQ).front->next = deNode->next;
    if(*bitTree == (*LQ).rear->data)
    {
        (*LQ).rear = (*LQ).front; // 避免尾指针指向其他地址.
    }
    free(deNode);
    return true;
}
