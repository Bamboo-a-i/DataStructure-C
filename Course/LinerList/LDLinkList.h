//
// Created by cxf18 on 2022/5/12.
//

#include <stdbool.h>

#ifndef LINEARLIST_LDLINKLIST_H
#define LINEARLIST_LDLINKLIST_H

#endif //LINEARLIST_LDLINKLIST_H

typedef struct LDLNode
{
    int data;
    struct LDLNode *next;
    struct LDLNode *prior;
}LDLNode,*LDLinkList;

bool LDLinkListInit(LDLinkList *);

bool Empty(LDLinkList);

bool IsTail(LDLinkList ,LDLNode *);

bool InsertNextNode(LDLNode*,LDLNode*);

bool Delete(LDLNode*);

void PrintLDLinkList(LDLinkList);