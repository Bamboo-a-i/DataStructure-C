//
// Created by cxf18 on 2022/7/9.
//

#include "LinkQueue.h"
bool InitLQueue(LinkQueue *LQ)
{
    LinkNode *p = (LinkNode *) malloc(sizeof (LinkNode));
    if(p == NULL)
        return false;
    (*LQ).front = (*LQ).rear = p;
    (*LQ).rear->next = NULL;
    return true;
}
bool EmptyLQueue(LinkQueue *LQ)
{
    if((*LQ).rear == (*LQ).front)
        return true;
    else
        return false;
}
bool EnLQueue(LinkQueue *LQ,ElemType e)
{
    if(LQ == NULL)
        return false;
    LinkNode *p = (LinkNode *) malloc(sizeof (LinkNode));
    p->data = e;
    p->next = NULL;
    (*LQ).rear->next = p;
    (*LQ).rear = p;
    return true;
}
bool DeLQueue(LinkQueue *LQ,ElemType *e)
{
    if(EmptyLQueue(LQ))
        return false;
    LinkNode *delNode = (*LQ).front->next;
    (*e) = delNode->data;
    (*LQ).front->next = delNode->next;
    if((*LQ).rear == delNode)
        (*LQ).rear = (*LQ).front;
    free(delNode);
    return true;
}
