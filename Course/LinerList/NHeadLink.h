//
// Created by cxf18 on 2022/5/11.
//

#ifndef LINEARLIST_NHEADLINK_H
#define LINEARLIST_NHEADLINK_H

#endif //LINEARLIST_NHEADLINK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

bool NHeadInitList(LinkList *L);

bool NHeadEmpty(LinkList *L);

bool NHeadListInsert(LinkList *L,int index,int e);

bool NHeadInsertNextNode(LNode *node,int e);

bool NHeadInsertPriorNode(LNode *node,int e);

LinkList NHeadLinkHeadInsert(LinkList *L);

LinkList NHeadLinkTailInsert(LinkList *L);

bool NHeadListDelete(LinkList *L,int index,int *e);

LNode *NHeadGetElem(LinkList L,int index);

LNode * NHeadLocateElem(LinkList L,int e);

int NHeadLength(LinkList L);

void NHeadPrintList(LinkList L);

bool DeleteNode(LNode *node);