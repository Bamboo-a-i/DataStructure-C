//
// Created by cxf18 on 2022/5/11.
//

#include "NHeadLink.h"


/*不带有头结点的所有操作*/
bool NHeadInitList(LinkList *L)
{
    (*L) = NULL; // 没有头结点的链表
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
        // 处理不带头结点的元素时插入位置为1时需要特别操作。
        LNode *node = (LNode *)malloc(sizeof(LNode)); // 新的结点
        node->data = e; // 结点赋值
        node->next = (*L); // 改变新节点的指向。
        (*L) = node; // 改变头指针的指向
        return true;
    }
    // 当插入位置不是第一个时操作一致
    //LNode *p = L;
    //int j = 1;
    //while (p && j<index-1)
    //{
    //    p = p->next;
    //    j++;
    //}
    //if(p == NULL) // index的值不合法
    //{
    //    return false;
    //}
    LNode *findNode = NHeadGetElem((*L),index-1);
    // 插入结点
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
        LNode *node = malloc(sizeof(LNode)); // 创建一个结点，作为首结点
        node->next = (*L); // 因为最开始的链表当中是null值，所以可以保证最后一个元素指向的始终是null
        node->data = e; // 给第一个结点赋值 -->每次首结点承担的是接受插入的数据
        (*L) = node; // (*L) --> 头指针指向新的结点
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

LinkList NHeadLinkTailInsert(LinkList *L)
{
    int e;
    LNode *tail = (*L); //外层中让尾巴指向首结点
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999) {
        LNode *node = (LNode *)malloc(sizeof(LNode));
        node->data = e;
        if((*L) == NULL) // 输入为首节点
        {
            (*L) = node;
            tail = (*L); // 首尾结点同体
        }
        else
        {
            tail->next = node; // 尾结点开始移动
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
    if(node == NULL) // index 的值不合法
        return false;
    if(node->next == NULL) // 只有这一个结点不能进行删除操作
    {
        return false;
    }
    // 处理当要删除的是第一个结点时
    if(index == 1)
    {
        delNode = (*L);
        (*L) = node->next; // 让头指针直接指向下一个结点地址即可。
        e = (int *) delNode->data;
        free(delNode);
        return true;
    }
    // 非第一个结点。
    delNode = node->next;
    e = delNode->data;
    node->next = delNode->next;
    free(delNode);
    return true;
}

LNode *NHeadLocateElem(LinkList L,int e)
{
    LNode *temp = L; // 不带头结点的不同之处
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
    LNode *temp = L; // 初始等于头结点的下一个结点，头结点是不存储数据的
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
    node->data = temp->data; // 与后继结点交换数据
    node->next = temp->next; // 断开结点连接.
    free(temp); // 释放
    return true;
}