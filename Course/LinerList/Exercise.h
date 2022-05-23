//
// Created by cxf18 on 2022/5/23.
//

#ifndef LINEARLIST_EXERCISE_H
#define LINEARLIST_EXERCISE_H
#include "Status.h"
#endif //LINEARLIST_EXERCISE_H
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
// LNode* ǿ����һ�����;
// LinkList ǿ����һ��������;

bool InitList(LinkList *L);

bool Empty(LinkList *L);

LinkList LinkHeadInsert(LinkList *L);

LinkList LinkTailInsert(LinkList *L);

bool R_Print(LinkList L);

LinkList Delete_MinNode(LinkList *L);

LinkList Reverse_LinkList1(LinkList *L);

LinkList Reverse_LinkList2(LinkList *L);

void Sort(LinkList *L);

void PrintList(LinkList L);