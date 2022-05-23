//
// Created by cxf18 on 2022/5/7.
//

#include "DLinkNode.h"
#include "Status.h"

int main()
{
    setbuf(stdout, 0);
    DLinkList L;
    DLinkList L2;
    PressEnterToContinue(true);
    printf("@@1--���Գ�ʼ��˫������--;\n");
    {
        printf("result=%d\n",InitDLinkList(&L));
        InitDLinkList(&L2);
    }
    PressEnterToContinue(false);
    printf("@@2--�����пպ���--;\n");
    {
        printf("result=%d\n",Empty(L));
    }
    PressEnterToContinue(false);
    printf("@@3--����ͷ�巨����--;\n");
    {
        DLinkHeadInsert(&L);
        printf("��ӡ����!\n");
        PrintDLink(L);
    }
    PressEnterToContinue(false);
    printf("@@4--����β�巨����--;\n");
    {
        printf("���Զ���L2\n");
        DLinkTailInsert(&L2);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@5--����ָ��������뺯��--;\n");
    {
        DNode node;
        node.data=15;
        printf("���Զ���L2->prior,����һ�����node.data = 15\n");
        InsertNextDnode(L2->next,&node);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@6--����ָ�����ǰ���뺯��--;\n");
    {
        printf("���Զ���L2\n");
        DLinkTailInsert(&L2);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@7--����ָ�������뺯��--;\n");
    {
        printf("���Զ���L2\n");
        DLinkTailInsert(&L2);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@8--����ɾ����̽�㺯��--;\n");
    {
        printf("���Զ���L2->next -- ����L\n");
        DeleteNextNode(L2->next);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@9--����ɾ��ǰ����㺯��--;\n");
    {
        printf("���Զ���L2 -- ����L2->next->next\n");
        DeletePriorNode(L2->next->next);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@10--����ɾ��ָ����㺯��--;\n");
    {
        printf("���Զ���L2 -- ����L2->next->next\n");
        DeleteNode(&L2,L2->next->next);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@11--��������˫������--;\n");
    {
        printf("���Զ���L2 -- ����L2->next->next\n");
        DestroyList(&L2);
        printf("result=%d\n",Empty(L2));
    }
}

bool InitDLinkList(DLinkList *L)
{
    (*L) = (DNode *)malloc(sizeof (DNode));
    if((*L) == NULL)
    {
        return false;
    }
    (*L)->next = NULL;
    (*L)->prior = NULL;
    return true;
}

bool Empty(DLinkList L)
{
    if(L->next == NULL)
    {
        return true;
    }
    else
        return false;
}

DLinkList DLinkHeadInsert(DLinkList *L)
{
    DNode *dNode;
    int e;
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999)
    {
        dNode = (DNode *) malloc(sizeof (DNode));
        dNode->prior = (*L); // �²���ָ���ǰ���
        dNode->data = e;
        dNode->next = (*L)->next; // ָ����һ�����
        if((*L)->next != NULL) // ����������һ�����
            (*L)->next->prior = dNode; // ��һ������ǰ���ָ���Լ�������һ����㽨����ϵ
        (*L)->next = dNode; // ��������
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

DLinkList DLinkTailInsert(DLinkList *L)
{
    DNode *dNode;
    DNode *tail = (*L); // β��λ��ͷָ��λ��
    int e;
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999)
    {
        dNode = (DNode *) malloc(sizeof (DNode));
        dNode->data = e; // ��ֵe
        dNode->next = tail->next; // �µĽ��next ָ��β���ָ���null
        dNode->prior = tail; // �½���ǰ�������һ��β���
        tail->next = dNode; // β�ڵ��next���½��
        tail = dNode; // �½���Ϊβ���
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

bool InsertNextDnode(DNode *dNode,DNode *insertNode)
{
    if(dNode == NULL || insertNode == NULL) // ������ֵ���Ϸ�
        return false;
    insertNode->next = dNode->next;
    if(dNode->next != NULL)
        dNode->next->prior = insertNode;
    insertNode->prior = dNode;
    dNode->next = insertNode;
    return true;
}

bool DeleteNextNode(DNode *dNode)
{
    if(dNode == NULL)
        return false;
    DNode *temp = dNode->next; //�� dNode �ĺ�̽��
    if(temp == NULL) // ���Ϊ��
        return false;
    dNode->next = temp->next; // �Ͽ�ɾ�������ǰ�����Ĺ�ϵ
    if(temp->next != NULL) // temp �������һ�����
        temp->next->prior = dNode; // �Ͽ�ɾ��������̵Ĺ�ϵ
    free(temp); // �ͷŽ��
    return true;
}

bool DeletePriorNode(DNode *dNode)
{
    if(dNode == NULL)
        return false;
    DNode *temp = dNode->prior; //�� dNode ��ǰ�����
    if(temp == NULL) // ǰ��Ϊ��
        return false;
    dNode->prior = temp->prior;
    if(temp->prior == NULL) // Ϊ���ʾtemp ǰһ�������ͷ���. ֱ�ӷ��ؼ���,
        return false;
    temp->prior->next = dNode; // �Ͽ�ǰ�����Ĺ�ϵ
    free(temp); // �ͷŽ��
    return true;
}

bool DeleteNode(DLinkList *L, DNode *dNode)
{
    DNode *temp = dNode;
    if(dNode == NULL || (*L) == NULL)
        return false;
    if(dNode->next == NULL && dNode->prior == NULL) // ֻ��һ�����
        return false;
    if(dNode->next == NULL) // ��β���
    {
        dNode->prior->next = temp->next;
        free(temp);
        return true;
    }
    if(dNode->prior == NULL) // ��ͷ���
    {
        (*L)->next = temp->next; // (*L)->next���Ա���ͷ���
        free(temp);
        return true;
    }
    // �м���
    dNode->next->prior = dNode->prior;
    dNode->prior->next = dNode->next;
    free(dNode);
    return true;
}

void DestroyList(DLinkList *L)
{
    while ((*L)->next != NULL)
        DeleteNextNode((*L)); // ͷ�����Ե��Ա�����ɾ�����㴦,����������ν�
    //free(L);
    L = NULL;
}

void PrintDLink(DLinkList L)
{
    DNode *temp = L->next;
    // ������
    while (temp != NULL)
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->next;
    }
    // ��ǰ���� ����Ľ��Ӧ��������ĩβ
/*    while (temp != NULL)
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->prior;
    }*/
}
