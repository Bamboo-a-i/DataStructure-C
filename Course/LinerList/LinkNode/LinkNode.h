//
// Created by cxf18 on 2022/5/7.
//

#ifndef DATASTRUCTURE_LINKNODE_H
#define DATASTRUCTURE_LINKNODE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
// LNode* 强调是一个结点;
// LinkList 强调是一个单链表;

bool InitList(LinkList *L);

bool Empty(LinkList *L);

LinkList LinkHeadInsert(LinkList *L);

LinkList LinkTailInsert(LinkList *L);

void PrintList(LinkList L);

LNode *GetElem(LinkList L,int index);

bool ListInsert(LinkList *L,int index,int e);

bool InsertPriorNode(LNode *node,int e);

bool InsertNextNode(LNode *node,int e);

bool ListDelete(LinkList *L,int index,int *e);

LNode * LocateElem(LinkList L,int e);

int Length(LinkList L);

bool DeleteNode(LNode *node);

#endif //DATASTRUCTURE_LINKNODE_H




