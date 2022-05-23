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
    /*无头结点操作*/
    PressEnterToContinue(false);
    printf("不带有头结点\n");
    printf("@@1--测试初始化函数@@\n");
    {
        printf("初始化一个不带有头结点单链表L...\n");
        NHeadInitList(&L);
        NHeadInitList(&L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@2--测试判空函数@@\n");
    {
        printf("测试对象为L\n");
        printf("输出1为空...\n");
        bool isEmpty = NHeadEmpty(&L);
        printf("%d\n",isEmpty);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@3--测试头插法函数@@\n");
    {
        printf("输入一串数据!(9999表示退出),头插法是对L进行建立\n");
        NHeadLinkHeadInsert(&L);
        printf("打印数据\n");
        NHeadPrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@4--测试尾插法函数@@\n");
    {
        printf("输入一串数据!(9999表示退出),尾插法是对L2进行建立\n");
        NHeadLinkTailInsert (&L2);
        printf("打印数据\n");
        NHeadPrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@5--测试指定结点后插入函数@@\n");
    {
        printf("(对象为:L,默认第1个结点后,呈现结果会插入到3的位置)\n");
        printf("传入L->next的结果:\n");
        NHeadInsertNextNode(L->next,110);
        printf("打印数据\n");
        NHeadPrintList(L);
        printf("\n");
        printf("传入L的结果:\n");
        NHeadInsertNextNode(L,111);
        printf("打印数据\n");
        NHeadPrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@6--测试指定结点前插入函数@@\n");
    {
        printf("(对象为:L2,默认第1个结点前)\n");
        printf("传入L2->next的结果:\n");
        NHeadInsertNextNode(L2->next,112);
        printf("打印数据\n");
        NHeadPrintList(L2);
        printf("\n");
        printf("传入L2的结果:\n");
        NHeadInsertNextNode(L2,113);
        printf("打印数据\n");
        NHeadPrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@7--测试插入数据函数@@\n");
    {
        printf("(对象为:L2,默认在第1个结点处插入)\n");
        NHeadListInsert(&L2,1,114);
        printf("打印数据\n");
        NHeadPrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@8--测试删除函数(对象为:L,默认删除第1个)@@\n");
    {
        printf("删除结点\n");
        NHeadListDelete(&L,2,&result);
        printf("删除的值:%d",result);
        printf("打印数据\n");
        NHeadPrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@9--测试指定结点删除函数@@\n");
    {
        printf("(对象为:L2,默认删除第1个结点)\n");
        printf("传入L2->next的结果:\n");
        DeleteNode(L2->next);
        printf("打印数据\n");
        NHeadPrintList(L2);
        printf("\n");
        printf("传入L2的结果:\n");
        DeleteNode(L2);
        printf("打印数据\n");
        NHeadPrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@10--测试求长度函数@@\n");
    {
        printf("(对象为:L)\n");
        printf("打印数据\n");
        printf("长度是:%d\n",NHeadLength(L));
        NHeadPrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@11--测试按位查找函数函数@@\n");
    {
        printf("(对象为:L，默认第四个结点)\n"); //实际输出会是第5个结点的数据
        printf("打印数据\n");
        LNode *temp = NHeadGetElem(L,3);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        NHeadPrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@12--测试按值查找函数函数@@\n");
    {
        printf("(对象为:L2，默认找等于9)\n");
        printf("打印数据\n");
        LNode *temp = NHeadLocateElem(L2,9);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        NHeadPrintList(L2);
        printf("\n");
    }
}

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