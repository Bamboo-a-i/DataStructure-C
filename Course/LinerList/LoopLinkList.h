//
// Created by cxf18 on 2022/5/12.
//

#include <stdbool.h>

#ifndef LINEARLIST_LOOPLINKLIST_H
#define LINEARLIST_LOOPLINKLIST_H

#endif //LINEARLIST_LOOPLINKLIST_H

typedef struct LLNode
{
    int data;
    struct LLNode *next;
}LLNode,*LLinkList;

bool LLinkListInit(LLinkList *);

bool Empty(LLinkList L);

bool InsertNextNode(LLNode *llNode,LLNode *insertNode);

bool PrintLLinkList(LLinkList L);