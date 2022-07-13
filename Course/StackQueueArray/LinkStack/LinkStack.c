//
// Created by cxf18 on 2022/5/18.
//

#include "LinkStack.h"

bool InitStack(LinkStack *Ls)
{
    // 默认是不带有头结点的
    (*Ls) = NULL;
    return true;
}

bool Empty(LinkStack *Ls)
{
    if((*Ls) == NULL)
        return true;
    else
        return false;
}

bool Push(LinkStack *Ls,ElemType e)
{
    // 类比头插法
    LsNode *insertNode = (LsNode *) malloc(sizeof (LsNode));
    if(insertNode == NULL) // 分配失败 和给的结点是NULL
        return false;
    insertNode->data = e;
    insertNode->next = (*Ls);
    (*Ls) = insertNode;
    return true;
}

bool Pop(LinkStack *Ls,ElemType *e)
{
    if((*Ls) != NULL)
    {
        LsNode *temp = (*Ls); // 没有头结点
        (*Ls) = temp->next;
        (*e) = temp->data;
        free(temp);
    }
    else
    {
        printf("栈空.\n");
    }
    return true;
}

bool GetPop(LinkStack *Ls,ElemType *e)
{
    if((*Ls) != NULL)
        (*e) = ((*Ls)->data);
    return true;
}

bool PrintLinkStack(LinkStack *Ls)
{
    if((*Ls) == NULL)
        return false;
    LsNode *temp = (*Ls);
    while(temp != NULL)
    {
        printf("address:0X%p,e:%d\n",temp,temp->data);
        temp = temp->next;
    }
    return true;
}