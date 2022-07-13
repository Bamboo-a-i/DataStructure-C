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
    printf("@@1--测试初始化双链表函数--;\n");
    {
        printf("result=%d\n",InitDLinkList(&L));
        InitDLinkList(&L2);
    }
    PressEnterToContinue(false);
    printf("@@2--测试判空函数--;\n");
    {
        printf("result=%d\n",Empty(L));
    }
    PressEnterToContinue(false);
    printf("@@3--测试头插法函数--;\n");
    {
        DLinkHeadInsert(&L);
        printf("打印数据!\n");
        PrintDLink(L);
    }
    PressEnterToContinue(false);
    printf("@@4--测试尾插法函数--;\n");
    {
        printf("测试对象L2\n");
        DLinkTailInsert(&L2);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@5--测试指定结点后插入函数--;\n");
    {
        DNode node;
        node.data=15;
        printf("测试对象L2->prior,传入一个结点node.data = 15\n");
        InsertNextDnode(L2->next,&node);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@6--测试指定结点前插入函数--;\n");
    {
        printf("测试对象L2\n");
        DLinkTailInsert(&L2);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@7--测试指定结点插入函数--;\n");
    {
        printf("测试对象L2\n");
        DLinkTailInsert(&L2);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@8--测试删除后继结点函数--;\n");
    {
        printf("测试对象L2->next -- 传入L\n");
        DeleteNextNode(L2->next);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@9--测试删除前驱结点函数--;\n");
    {
        printf("测试对象L2 -- 传入L2->next->next\n");
        DeletePriorNode(L2->next->next);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@10--测试删除指定结点函数--;\n");
    {
        printf("测试对象L2 -- 传入L2->next->next\n");
        DeleteNode(&L2,L2->next->next);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    PressEnterToContinue(false);
    printf("@@11--测试销毁双链表函数--;\n");
    {
        printf("测试对象L2 -- 传入L2->next->next\n");
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
        dNode->prior = (*L); // 新插入指针的前结点
        dNode->data = e;
        dNode->next = (*L)->next; // 指向下一个结点
        if((*L)->next != NULL) // 如果不是最后一个结点
            (*L)->next->prior = dNode; // 下一个结点的前结点指向自己，和下一个结点建立联系
        (*L)->next = dNode; // 将结点插入
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

DLinkList DLinkTailInsert(DLinkList *L)
{
    DNode *dNode;
    DNode *tail = (*L); // 尾巴位于头指针位置
    int e;
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999)
    {
        dNode = (DNode *) malloc(sizeof (DNode));
        dNode->data = e; // 赋值e
        dNode->next = tail->next; // 新的结点next 指向尾结点指向的null
        dNode->prior = tail; // 新结点的前结点是上一个尾结点
        tail->next = dNode; // 尾节点的next是新结点
        tail = dNode; // 新结点成为尾结点
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

bool InsertNextDnode(DNode *dNode,DNode *insertNode)
{
    if(dNode == NULL || insertNode == NULL) // 传入结点值不合法
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
    DNode *temp = dNode->next; //找 dNode 的后继结点
    if(temp == NULL) // 后继为空
        return false;
    dNode->next = temp->next; // 断开删除结点与前驱结点的关系
    if(temp->next != NULL) // temp 不是最后一个结点
        temp->next->prior = dNode; // 断开删除结点与后继的关系
    free(temp); // 释放结点
    return true;
}

bool DeletePriorNode(DNode *dNode)
{
    if(dNode == NULL)
        return false;
    DNode *temp = dNode->prior; //找 dNode 的前驱结点
    if(temp == NULL) // 前驱为空
        return false;
    dNode->prior = temp->prior;
    if(temp->prior == NULL) // 为真表示temp 前一个结点是头结点. 直接返回即可,
        return false;
    temp->prior->next = dNode; // 断开前驱结点的关系
    free(temp); // 释放结点
    return true;
}

bool DeleteNode(DLinkList *L, DNode *dNode)
{
    DNode *temp = dNode;
    if(dNode == NULL || (*L) == NULL)
        return false;
    if(dNode->next == NULL && dNode->prior == NULL) // 只有一个结点
        return false;
    if(dNode->next == NULL) // 是尾结点
    {
        dNode->prior->next = temp->next;
        free(temp);
        return true;
    }
    if(dNode->prior == NULL) // 是头结点
    {
        (*L)->next = temp->next; // (*L)->next可以保留头结点
        free(temp);
        return true;
    }
    // 中间结点
    dNode->next->prior = dNode->prior;
    dNode->prior->next = dNode->next;
    free(dNode);
    return true;
}

void DestroyList(DLinkList *L)
{
    while ((*L)->next != NULL)
        DeleteNextNode((*L)); // 头结点可以得以保留到删除后结点处,不会产生不衔接
    //free(L);
    L = NULL;
}

void PrintDLink(DLinkList L)
{
    DNode *temp = L->next;
    // 向后遍历
    while (temp != NULL)
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->next;
    }
    // 向前遍历 传入的结点应该是链表末尾
/*    while (temp != NULL)
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->prior;
    }*/
}
