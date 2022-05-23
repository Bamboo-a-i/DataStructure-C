//
// Created by cxf18 on 2022/5/7.
//

#include <stdbool.h>

#ifndef DATASTRUCTURE_DLINKNODE_H
#define DATASTRUCTURE_DLINKNODE_H

#endif //DATASTRUCTURE_DLINKNODE_H
#include "Status.h"
typedef struct DNode
{
    int data;
    struct DNode *next,*prior;
}DNode,*DLinkList;

// 初始化函数
bool InitDLinkList(DLinkList *L);
// 判断空函数
bool Empty(DLinkList L);
// 头插法
DLinkList DLinkHeadInsert(DLinkList *L);
// 尾插法
DLinkList DLinkTailInsert(DLinkList *L);
// 插入元素
bool InsertNextDnode(DNode *dNode,DNode *p);
// 遍历元素
void PrintDLink(DLinkList L);
// 删除后一个结点
bool DeleteNextNode(DNode *dNode);
// 删除前一个结点
bool DeletePriorNode(DNode *dNode);
// 删除指点结点
bool DeleteNode(DLinkList *L, DNode *dNode);
// 销毁
void DestroyList(DLinkList *L);
