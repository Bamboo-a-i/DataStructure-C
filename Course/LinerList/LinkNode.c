//
// Created by cxf18 on 2022/5/7.
//

#include "LinkNode.h"
#include "Status.h"

int main()
{
    setbuf(stdout,0);
    LinkList L,L2;
    int result = 0;
    //LNode *result;
    // ��ͷ������
    PressEnterToContinue(false);
    printf("����ͷ���Ĳ���\n");
    printf("@@1--���Գ�ʼ������@@\n");
    {
        printf("��ʼ��һ��������L...\n");
        InitList(&L);
        InitList(&L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@2--�����пպ���@@\n");
    {
        printf("���Զ���ΪL\n");
        printf("���1Ϊ��...\n");
        bool isEmpty = Empty(&L);
        printf("%d\n",isEmpty);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@3--����ͷ�巨����@@\n");
    {
        printf("����һ������!(9999��ʾ�˳�),ͷ�巨�Ƕ�L���н���\n");
        LinkHeadInsert(&L);
        printf("��ӡ����\n");
        PrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@4--����β�巨����@@\n");
    {
        printf("����һ������!(9999��ʾ�˳�),β�巨�Ƕ�L2���н���\n");
        LinkTailInsert (&L2);
        printf("��ӡ����\n");
        PrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@5--����ָ��������뺯��@@\n");
    {
        printf("(����Ϊ:L,Ĭ�ϵ�1������),e:00\n");
        InsertNextNode(L->next,00);
        printf("��ӡ����\n");
        PrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@6--����ָ�����ǰ���뺯��@@\n");
    {
        printf("(����Ϊ:L2,Ĭ�ϵ�1�����ǰ),e:11\n");
        InsertPriorNode(L2->next,11);
        printf("��ӡ����\n");
        PrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@7--���Բ������ݺ���@@\n");
    {
        printf("(����Ϊ:L2,Ĭ���ڵ�3����㴦����,e:10)\n");
        ListInsert(L2,3,10);
        printf("��ӡ����\n");
        PrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@8--����ɾ������(����Ϊ:L,Ĭ��ɾ����2��)@@\n");
    {
        printf("ɾ�����\n");

        ListDelete(&L,2,&result);
        printf("��ӡ����\n");
        PrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@9--����ָ�����ɾ������@@\n");
    {
        printf("(����Ϊ:L2,Ĭ��ɾ����1�����)\n");
        DeleteNode(L2->next);
        printf("��ӡ����\n");
        PrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@10--�����󳤶Ⱥ���@@\n");
    {
        printf("(����Ϊ:L)\n");
        printf("��ӡ����\n");
        printf("������:%d\n",Length(L));
        PrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@11--���԰�λ���Һ�������@@\n");
    {
        printf("(����Ϊ:L��Ĭ�ϵ��ĸ����)\n");
        printf("��ӡ����\n");
        LNode *temp = GetElem(L,4);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        PrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@12--���԰�ֵ���Һ�������@@\n");
    {
        printf("(����Ϊ:L2��Ĭ���ҵ���9)\n");
        printf("��ӡ����\n");
        LNode *temp = LocateElem(L,9);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        PrintList(L);
        printf("\n");
    }


}

/*����ͷ�������в���*/
bool InitList(LinkList *L)
{
    (*L) = (LNode *)malloc(sizeof(LNode)); // ����һ����ʼ����ͷ���
    (*L)->next = NULL;
    if((*L) == NULL)
    {
        return false;
    }
    return true;
}

bool Empty(LinkList *L)
{
    if((*L)->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

LinkList LinkHeadInsert(LinkList *L)
{
    LNode *node;
    int e;
    (*L) = (LinkList)malloc(sizeof(LNode));//����ͷ���
    (*L)->next = NULL;
    printf("insert e:\n");
    scanf("%d",&e);
    while(e != 9999)
    {
        node = (LNode *)malloc(sizeof(LNode *));
        node->data = e;
        node->next = (*L)->next; // ������һ�����
        (*L)->next = node; // �����µĽ��
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

LinkList LinkTailInsert(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(LNode));
    LNode *node,*tail = (*L);
    int e;
    printf("insert e:\n");
    scanf("%d",&e);
    while(e != 9999)
    {
        node = (LNode *)malloc(sizeof(LNode *));
        node->data = e;
        //(*L)->next = node;
        tail->next = node;
        //ѭ���ڲ��Լ�����β�ͣ�β�͵�next��ʱ�����Լ�
        //������ʹ��tail�����ǣ�*L���ﵽ�Ľ������һ���ģ�tail�ͣ�*L��ֻ���������Ǹ���ָ���һ�����ֶ��ѣ���һ�����ָ�������һ���˲�����ʧȥ���ֵľͻ���ʧ��Ҳ����������֮�����ϵ����ʧ��
        //(*L) = node; // �Լ��ڳ�Ϊβ��
        tail = node;
        printf("insert e:\n");
        scanf("%d",&e);
    }
    tail->next = NULL; // ���ָ���һ����һ��null
    return (*L);
}

LNode *GetElem(LinkList L,int index)
{
    if(index < 0)
    {
        return NULL;
    }
    LNode *temp;
    int j = 0;
    temp = L;
    //temp
    while(temp != NULL && j < index)
    {
        temp = temp->next;
        j++;
    }
    // index = 0 index<0 false, j(0)<index(0) false -->����ͷ���
    // index = 2 index <0 false,ѭ��j=0,1 ,���س�ͷ�����ĵڶ�����㡣
    return temp; // ���ڷ��ض�Ӧֵ,��������NULL
}

bool ListInsert(LinkList *L,int index,int e)
{
    // ����Ƿ�ֵ
    if(index < 1)
    {
        return false;
    }
    // ���ϵ���GetElem ����ָ����������������
    LNode *findNode = GetElem((*L),index-1); // �ҵ��������ǰ��
    return InsertNextNode(findNode,e);
}

bool InsertPriorNode(LNode *node,int e)
{
    LNode *priorNode = (LNode *)malloc(sizeof(LNode));
    if(node== NULL || priorNode == NULL)
    {
        return false;
    }
    priorNode->next = node->next;
    node->next = priorNode;
    priorNode->data = node->data;
    node->data = e;
    return true;
}

bool InsertNextNode(LNode *node,int e)
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

bool ListDelete(LinkList *L,int index,int *e)
{
//    LNode *node =  GetElem((*L),index-1);
    if(index <1)
        return false;
    LNode *node;
    int j = 0;
    node = (*L);
    while (node!=NULL && j<index - 1)
    {
        node = node->next;
        j++;
    }
    if(node == NULL) // index ֵ���Ϸ�
        return false;
    if(node->next ==NULL) // index - 1�����֮ǰ�����������
        return  false;
    LNode *delNode = node->next; // ָ��ɾ�����
    e = delNode->data; // �����ҵ���ֵ
    node->next = delNode->next; // �Ͽ�����
    free(delNode); // �ͷ�
    return true;
}

LNode *LocateElem(LinkList L,int e)
{
    LNode *temp = L->next;
    while (temp != NULL && temp->data !=e) {
        temp = temp->next;
    }
    return temp;
}

int Length(LinkList L)
{
    int len = 0;
    LNode *temp = L;
    while(temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void PrintList(LinkList L)
{
    LNode *temp = L->next; // ��ʼ����ͷ������һ����㣬ͷ����ǲ��洢���ݵ�
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
