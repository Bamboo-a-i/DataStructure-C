//
// Created by cxf18 on 2022/6/9.
//

#include "LinkQueue.h"

/*
 * 初始化
 * */
bool InitLQueue(LinkBTQueue *LQ)
{
    LinkBTNode *p = (LinkBTNode *) malloc(sizeof (LinkBTNode));
    if(p == NULL)
        return false;
    (*LQ).front = (*LQ).rear = p;
    (*LQ).front->next = NULL;
    return true;
}
/*
 * 判空
 * */
bool EmptyLQueue(LinkBTQueue LQ)
{
    // 判空条件有所变化 需要判断front 和rear 指向的结点的值是否为NULL
    if(LQ.front ==  LQ.rear && LQ.front->next == NULL && LQ.rear->next == NULL)
        return true;
    else
        return false;
}

/*
 * 入队 -- 类比尾插法
 * */
bool EnLQueue(LinkBTQueue *LQ,BitTree *bitTree)
{
    LinkBTNode *insertBTNode = (LinkBTNode *) malloc(sizeof (LinkBTNode));
    insertBTNode->data = *bitTree;
    insertBTNode->next = NULL;
    (*LQ).rear->next = insertBTNode; // 尾插
    (*LQ).rear = insertBTNode; // 尾随
    return true;
}

/*
 * 出队
 * */
bool DeLQueue(LinkBTQueue *LQ,BitTree *bitTree)
{
    if((*LQ).rear == (*LQ).front)
        return false;
    LinkBTNode *deBTNode = (*LQ).front->next; // 此处选择next是因为front 并没有存储数据，可以理解为一种不完全的头结点。
    *bitTree = deBTNode->data; // 获取数据
    (*LQ).front->next = deBTNode->next;
    if(*bitTree == (*LQ).rear->data)
    {
        (*LQ).rear = (*LQ).front; // 避免尾指针指向其他地址.
    }
    free(deBTNode);
    return true;
}

