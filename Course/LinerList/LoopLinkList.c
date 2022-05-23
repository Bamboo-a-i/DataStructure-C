//
// Created by cxf18 on 2022/5/12.
//

#include "LoopLinkList.h"
#include "Status.h"

int main()
{
    setbuf(stdout,0);
    LLinkList L;
    PressEnterToContinue(false);
    printf("@@1--���Գ�ʼ��ѭ����������--;\n");
    {
        printf("��ʼ��ʼ��!\n");
        LLinkListInit(&L);
    }
    PressEnterToContinue(false);
    printf("@@2--�����пպ���--;\n");
    {
        printf("���1Ϊ��\n");
        printf("�����:%d\n", Empty(L));
    }
    PressEnterToContinue(false);
    printf("@@3--����ָ��������뺯��--;\n");
    {
        LLNode temp;
        temp.data = 15;
        InsertNextNode(L,&temp);
        printf("��ӡ����!\n");
        PrintLLinkList(L);
    }
}
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
    if(L->next == L) // ��һ��������ͷ���
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