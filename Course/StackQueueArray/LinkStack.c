//
// Created by cxf18 on 2022/5/18.
//

#include "LinkStack.h"

int main()
{
    setbuf(stdout,0);
    LinkStack Ls;
    PressEnterToContinue(false);
    printf("@@1--��ʼ������ջ����--\n");
    {
        printf("��ʼ\n");
        InitStack(&Ls);
    }

    PressEnterToContinue(false);
    printf("@@2--�����пպ���--\n");
    {
        printf("��ʼ\n");
        printf("isEmpty:%d\n",Empty(&Ls));
    }

    PressEnterToContinue(false);
    printf("@@3--������ջ����--\n");
    {
        printf("��ʼ\n");
        Push(&Ls,11);
        Push(&Ls,12);
        PrintLinkStack(&Ls);
    }

    PressEnterToContinue(false);
    printf("@@4--���Գ�ջ����--\n");
    {
        ElemType e = 0;
        printf("��ʼ\n");
        Pop(&Ls,&e);
        printf("e:%d\n",e);
        PrintLinkStack(&Ls);
    }

    PressEnterToContinue(false);
    printf("@@4--���Ի�ȡջ������--\n");
    {
        ElemType e = 0;
        printf("��ʼ\n");
        GetPop(&Ls,&e);
        printf("e:%d\n",e);
        PrintLinkStack(&Ls);
    }
}

bool InitStack(LinkStack *Ls)
{
    // Ĭ���ǲ�����ͷ����
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
    // ���ͷ�巨
    LsNode *insertNode = (LsNode *) malloc(sizeof (LsNode));
    if(insertNode == NULL) // ����ʧ�� �͸��Ľ����NULL
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
        LsNode *temp = (*Ls); // û��ͷ���
        (*Ls) = temp->next;
        (*e) = temp->data;
        free(temp);
    }
    else
    {
        printf("ջ��.\n");
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