//
// Created by cxf18 on 2022/5/12.
//


#ifndef LINEARLIST_LOOPLINKLIST_H
#define LINEARLIST_LOOPLINKLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct LLNode
{
    int data;
    struct LLNode *next;
}LLNode,*LLinkList;

bool LLinkListInit(LLinkList *);

bool Empty(LLinkList L);

bool InsertNextNode(LLNode *llNode,LLNode *insertNode);

bool PrintLLinkList(LLinkList L);

#endif //LINEARLIST_LOOPLINKLIST_H

