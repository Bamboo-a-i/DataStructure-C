//
// Created by cxf18 on 2022/5/12.
//

#include "LLinkList.h"

bool LLinkListInit(LLinkList *L)
{
    (*L) = (LLNode*) malloc(sizeof (LLNode));
    if((*L) == NULL)
        return false;
    (*L)->next = (*L);
    return true;
}

bool Empty(LLinkList L)
{
    if(L->next == L) // 下一个结点等于头结点
        return true;
    else
        return false;
}

bool InsertNextNode(LLNode *llNode,LLNode *insertNode)
{
    if(llNode == NULL || insertNode == NULL)
        return false;
    insertNode->next = llNode->next;
    llNode->next = insertNode;
    return true;
}

bool PrintLLinkList(LLinkList L)
{
    LLNode *temp = L->next;
    while (temp != L)
    {
        printf("nodeAddress:%p;nodeE:%d\n",temp,temp->data);
        temp = temp->next;
    }
    return true;
}