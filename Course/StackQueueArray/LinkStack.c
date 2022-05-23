//
// Created by cxf18 on 2022/5/18.
//

#include "LinkStack.h"

int main()
{
    setbuf(stdout,0);
    LinkStack Ls;
    PressEnterToContinue(false);
    printf("@@1--初始化共享栈函数--\n");
    {
        printf("开始\n");
        InitStack(&Ls);
    }

    PressEnterToContinue(false);
    printf("@@2--测试判空函数--\n");
    {
        printf("开始\n");
        printf("isEmpty:%d\n",Empty(&Ls));
    }

    PressEnterToContinue(false);
    printf("@@3--测试入栈函数--\n");
    {
        printf("开始\n");
        Push(&Ls,11);
        Push(&Ls,12);
        PrintLinkStack(&Ls);
    }

    PressEnterToContinue(false);
    printf("@@4--测试出栈函数--\n");
    {
        ElemType e = 0;
        printf("开始\n");
        Pop(&Ls,&e);
        printf("e:%d\n",e);
        PrintLinkStack(&Ls);
    }

    PressEnterToContinue(false);
    printf("@@4--测试获取栈顶函数--\n");
    {
        ElemType e = 0;
        printf("开始\n");
        GetPop(&Ls,&e);
        printf("e:%d\n",e);
        PrintLinkStack(&Ls);
    }
}

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