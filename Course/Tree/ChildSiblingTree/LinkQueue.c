//
// Created by cxf18 on 2022/7/5.
//

#include "LinkQueue.h"
/*
 * 初始孩子兄弟表示法树
 * */
bool InitQueue(LinkQueue *LQ)
{
    LinkNode *p = (LinkNode *) malloc(sizeof (LinkNode)); // 分配内存
    if(p == NULL)
        return false;
    (*LQ).front = (*LQ).rear = p; // 初始指向同块地址
    (*LQ).front->data = NULL;
    return true;
}
/*
 * 判空
 * */
bool EmptyQueue(LinkQueue LQ)
{
    if(LQ.front == LQ.rear)
        return true;
    else
        return false;
}
/*
 * 入队 -- 类比尾插法
 * */
bool EnQueue(LinkQueue *LQ,CSTree *csTree)
{
    LinkNode *p = (LinkNode *) malloc(sizeof (LinkNode));
    p->data = *csTree;
    p->next = NULL; // 作为尾部结点
    (*LQ).rear->next = p;
    (*LQ).rear = p;
    return true;
}
/*
 * 出队
 * */
bool DeQueue(LinkQueue *LQ,CSTree *csTree)
{
    if(EmptyQueue(*LQ)) // 判空
        return false;
    LinkNode *p = (*LQ).front->next;
    *csTree = p->data; // 返回数据
    // 此处不能直接让(*LQ).front = p->next 这种做法会使得font直接指向null在下一个入队时将会出错.
    (*LQ).front->next = p->next;
    if((*LQ).rear == p)
        (*LQ).rear = (*LQ).front;
    free(p);
    return true;
}