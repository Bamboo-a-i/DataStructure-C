//
// Created by cxf18 on 2022/5/12.
//


#ifndef LINEARLIST_LDLINKLIST_H
#define LINEARLIST_LDLINKLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

#endif //LINEARLIST_LDLINKLIST_H

