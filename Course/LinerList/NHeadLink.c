//
// Created by cxf18 on 2022/5/11.
//

#include "NHeadLink.h"
#include "Status.h"
int main()
{
    setbuf(stdout,0);
    LinkList L,L2;
    int result = 0;
    /*��ͷ������*/
    PressEnterToContinue(false);
    printf("������ͷ���\n");
    printf("@@1--���Գ�ʼ������@@\n");
    {
        printf("��ʼ��һ��������ͷ��㵥����L...\n");
        NHeadInitList(&L);
        NHeadInitList(&L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@2--�����пպ���@@\n");
    {
        printf("���Զ���ΪL\n");
        printf("���1Ϊ��...\n");
        bool isEmpty = NHeadEmpty(&L);
        printf("%d\n",isEmpty);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@3--����ͷ�巨����@@\n");
    {
        printf("����һ������!(9999��ʾ�˳�),ͷ�巨�Ƕ�L���н���\n");
        NHeadLinkHeadInsert(&L);
        printf("��ӡ����\n");
        NHeadPrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@4--����β�巨����@@\n");
    {
        printf("����һ������!(9999��ʾ�˳�),β�巨�Ƕ�L2���н���\n");
        NHeadLinkTailInsert (&L2);
        printf("��ӡ����\n");
        NHeadPrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@5--����ָ��������뺯��@@\n");
    {
        printf("(����Ϊ:L,Ĭ�ϵ�1������,���ֽ������뵽3��λ��)\n");
        printf("����L->next�Ľ��:\n");
        NHeadInsertNextNode(L->next,110);
        printf("��ӡ����\n");
        NHeadPrintList(L);
        printf("\n");
        printf("����L�Ľ��:\n");
        NHeadInsertNextNode(L,111);
        printf("��ӡ����\n");
        NHeadPrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@6--����ָ�����ǰ���뺯��@@\n");
    {
        printf("(����Ϊ:L2,Ĭ�ϵ�1�����ǰ)\n");
        printf("����L2->next�Ľ��:\n");
        NHeadInsertNextNode(L2->next,112);
        printf("��ӡ����\n");
        NHeadPrintList(L2);
        printf("\n");
        printf("����L2�Ľ��:\n");
        NHeadInsertNextNode(L2,113);
        printf("��ӡ����\n");
        NHeadPrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@7--���Բ������ݺ���@@\n");
    {
        printf("(����Ϊ:L2,Ĭ���ڵ�1����㴦����)\n");
        NHeadListInsert(&L2,1,114);
        printf("��ӡ����\n");
        NHeadPrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@8--����ɾ������(����Ϊ:L,Ĭ��ɾ����1��)@@\n");
    {
        printf("ɾ�����\n");
        NHeadListDelete(&L,2,&result);
        printf("ɾ����ֵ:%d",result);
        printf("��ӡ����\n");
        NHeadPrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@9--����ָ�����ɾ������@@\n");
    {
        printf("(����Ϊ:L2,Ĭ��ɾ����1�����)\n");
        printf("����L2->next�Ľ��:\n");
        DeleteNode(L2->next);
        printf("��ӡ����\n");
        NHeadPrintList(L2);
        printf("\n");
        printf("����L2�Ľ��:\n");
        DeleteNode(L2);
        printf("��ӡ����\n");
        NHeadPrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@10--�����󳤶Ⱥ���@@\n");
    {
        printf("(����Ϊ:L)\n");
        printf("��ӡ����\n");
        printf("������:%d\n",NHeadLength(L));
        NHeadPrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@11--���԰�λ���Һ�������@@\n");
    {
        printf("(����Ϊ:L��Ĭ�ϵ��ĸ����)\n"); //ʵ��������ǵ�5����������
        printf("��ӡ����\n");
        LNode *temp = NHeadGetElem(L,3);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        NHeadPrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@12--���԰�ֵ���Һ�������@@\n");
    {
        printf("(����Ϊ:L2��Ĭ���ҵ���9)\n");
        printf("��ӡ����\n");
        LNode *temp = NHeadLocateElem(L2,9);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        NHeadPrintList(L2);
        printf("\n");
    }
}

/*������ͷ�������в���*/
bool NHeadInitList(LinkList *L)
{
    (*L) = NULL; // û��ͷ��������
    return true;
}

bool NHeadEmpty(LinkList *L)
{
    return ((*L) == NULL);
}

LNode *NHeadGetElem(LinkList L,int index)
{

    if(index < 0)
    {
        return NULL;
    }
    LNode *temp;
    int j = 1;
    temp = L;

    while(temp != NULL && j<index)
    {
        temp = temp->next;
        j++;
    }
    return temp;
}

bool NHeadListInsert(LinkList *L,int index,int e)
{
    if(index < 1)
    {
        return false;
    }
    if(index == 1)
    {
        // ������ͷ����Ԫ��ʱ����λ��Ϊ1ʱ��Ҫ�ر������
        LNode *node = (LNode *)malloc(sizeof(LNode)); // �µĽ��
        node->data = e; // ��㸳ֵ
        node->next = (*L); // �ı��½ڵ��ָ��
        (*L) = node; // �ı�ͷָ���ָ��
        return true;
    }
    // ������λ�ò��ǵ�һ��ʱ����һ��
    //LNode *p = L;
    //int j = 1;
    //while (p && j<index-1)
    //{
    //    p = p->next;
    //    j++;
    //}
    //if(p == NULL) // index��ֵ���Ϸ�
    //{
    //    return false;
    //}
    LNode *findNode = NHeadGetElem((*L),index-1);
    // ������
//    LNode *s = (LNode *)malloc(sizeof(LNode));
//    s->next = p->next;
//    s->data = e;
//    p->next = s;
//    return true;
    return NHeadInsertNextNode(findNode,e);
}

bool NHeadInsertNextNode(LNode *node,int e)
{
    LNode *nextNode = (LNode *)malloc(sizeof(LNode));
    if(node == NULL && nextNode == NULL)
    {
        return false;
    }
    nextNode->next =node->next;
    nextNode->data = e;
    node->next = nextNode;
    return true;
}

bool NHeadInsertPriorNode(LNode *node,int e)
{
    LNode *priorNode = (LNode *)malloc(sizeof(LNode));

    if(node == NULL && priorNode == NULL)
    {
        return false;
    }
    priorNode->next = node->next;
    node->next = priorNode;
    priorNode->data = node->data;
    node->data = e;
    return true;
}

LinkList NHeadLinkHeadInsert(LinkList *L)
{
    int e;
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999) {
        LNode *node = malloc(sizeof(LNode)); // ����һ����㣬��Ϊ�׽��
        node->next = (*L); // ��Ϊ�ʼ����������nullֵ�����Կ��Ա�֤���һ��Ԫ��ָ���ʼ����null
        node->data = e; // ����һ����㸳ֵ -->ÿ���׽��е����ǽ��ܲ��������
        (*L) = node; // (*L) --> ͷָ��ָ���µĽ��
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

LinkList NHeadLinkTailInsert(LinkList *L)
{
    int e;
    LNode *tail = (*L); //�������β��ָ���׽��
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999) {
        LNode *node = (LNode *)malloc(sizeof(LNode));
        node->data = e;
        if((*L) == NULL) // ����Ϊ�׽ڵ�
        {
            (*L) = node;
            tail = (*L); // ��β���ͬ��
        }
        else
        {
            tail->next = node; // β��㿪ʼ�ƶ�
            tail = node;
        }
        printf("insert e:\n");
        scanf("%d",&e);
    }
    tail->next = NULL;
    return (*L);
}

bool NHeadListDelete(LinkList *L,int index,int *e)
{
    if(index < 0)
        return false;
    LNode *node;
    LNode *delNode;
    int j = 1;
    node = (*L);
    while(node != NULL && j < index -1)
    {
        node = node->next;
        j++;
    }
    if(node == NULL) // index ��ֵ���Ϸ�
        return false;
    if(node->next == NULL) // ֻ����һ����㲻�ܽ���ɾ������
    {
        return false;
    }
    // ����Ҫɾ�����ǵ�һ�����ʱ
    if(index == 1)
    {
        delNode = (*L);
        (*L) = node->next; // ��ͷָ��ֱ��ָ����һ������ַ���ɡ�
        e = (int *) delNode->data;
        free(delNode);
        return true;
    }
    // �ǵ�һ����㡣
    delNode = node->next;
    e = delNode->data;
    node->next = delNode->next;
    free(delNode);
    return true;
}

LNode *NHeadLocateElem(LinkList L,int e)
{
    LNode *temp = L; // ����ͷ���Ĳ�֮ͬ��
    while (temp != NULL && temp->data !=e) {
        temp = temp->next;
    }
    return temp;
}

int NHeadLength(LinkList L)
{
    int len = 0;
    LNode *temp = L;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void NHeadPrintList(LinkList L)
{
    LNode *temp = L; // ��ʼ����ͷ������һ����㣬ͷ����ǲ��洢���ݵ�
    while(temp != NULL)
    {
        printf("nodeAddress:%p;nodee:%d\n",temp,temp->data);
        temp = temp->next;
    }
}

bool DeleteNode(LNode *node)
{
    if(node == NULL)
    {
        return false;
    }
    LNode *temp = node->next;
    node->data = temp->data; // ���̽�㽻������
    node->next = temp->next; // �Ͽ��������.
    free(temp); // �ͷ�
    return true;
}