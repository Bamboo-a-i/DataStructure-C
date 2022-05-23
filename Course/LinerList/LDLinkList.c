//
// Created by cxf18 on 2022/5/12.
//

#include "LDLinkList.h"
#include "Status.h"

int main()
{
    LDLinkList L;
    setbuf(stdout,0);
    PressEnterToContinue(false);
    printf("@@1--���Գ�ʼ��ѭ����������--;\n");
    {
        printf("��ʼ��ʼ��!\n");
        LDLinkListInit(&L);
    }
    PressEnterToContinue(false);
    printf("@@2--�����пպ���--;\n");
    {
        printf("���1Ϊ��\n");
        printf("�����:%d\n", Empty(L));
    }
    PressEnterToContinue(false);
    printf("@@3--�����Ƿ��Ǳ�β��㺯��--;\n");
    {
        printf("���1��ʾ�Ǳ�β\n");
        printf("�����:%d\n", IsTail(L,L->next));
    }
    PressEnterToContinue(false);
    printf("@@4--����ָ��������뺯��--;\n");
    {
        LDLNode temp;
        temp.data = 15;
        InsertNextNode(L,&temp);
        printf("��ӡ����!\n");
        PrintLDLinkList(L);
    }
    PressEnterToContinue(false);
    printf("@@5--����ɾ����㺯��--;\n");
    {
        Delete(L->next->next);
        printf("��ӡ����!\n");
        PrintLDLinkList(L);
    }
}

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
    if(ldlNode->next == L) //ldlNode->prior == tail; ���������ж�һ������ǲ����׽��.
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
    while (temp != L) // .next == Lʱ,��ʾ������β���
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->next;
    }
}