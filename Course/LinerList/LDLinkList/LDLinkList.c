//
// Created by cxf18 on 2022/5/12.
//

#include "LDLinkList.h"


bool LDLinkListInit(LDLinkList * L)
{
    (*L) = (LDLNode *) malloc(sizeof(LDLNode));
    if((*L) == NULL)
        return false;
    (*L)->next = (*L);
    (*L)->prior = (*L);
    return true;
}

bool Empty(LDLinkList L)
{
    if(L->next == L)
        return true;
    else
        return false;
}

bool IsTail(LDLinkList L,LDLNode *ldlNode)
{
    if(ldlNode->next == L) //ldlNode->prior == tail; 可以用来判断一个结点是不是首结点.
        return true;
    else
        return false;
}

bool InsertNextNode(LDLNode* ldlNode,LDLNode* insertNode)
{
    if(ldlNode == NULL || insertNode == NULL)
        return false;
    insertNode->next = ldlNode->next;
    ldlNode->next->prior = ldlNode;
    insertNode->prior = ldlNode;
    ldlNode->next = insertNode;
    return true;
}

bool Delete(LDLNode* ldlNode)
{
    if(ldlNode == NULL)
        return false;
    LDLNode *temp = ldlNode->next;
    ldlNode->next = temp->next;
    temp->next->prior = ldlNode;
    free(temp);
    return true;
}

void PrintLDLinkList(LDLinkList L)
{
    LDLNode *temp = L->next;
    while (temp != L) // .next == L时,表示到达了尾结点
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->next;
    }
}