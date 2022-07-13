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
    // 有头结点操作
    PressEnterToContinue(false);
    printf("带有头结点的操作\n");
    printf("@@1--测试初始化函数@@\n");
    {
        printf("初始化一个单链表L...\n");
        InitList(&L);
        InitList(&L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@2--测试判空函数@@\n");
    {
        printf("测试对象为L\n");
        printf("输出1为空...\n");
        bool isEmpty = Empty(&L);
        printf("%d\n",isEmpty);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@3--测试头插法函数@@\n");
    {
        printf("输入一串数据!(9999表示退出),头插法是对L进行建立\n");
        LinkHeadInsert(&L);
        printf("打印数据\n");
        PrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@4--测试尾插法函数@@\n");
    {
        printf("输入一串数据!(9999表示退出),尾插法是对L2进行建立\n");
        LinkTailInsert (&L2);
        printf("打印数据\n");
        PrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@5--测试指定结点后插入函数@@\n");
    {
        printf("(对象为:L,默认第1个结点后),e:00\n");
        InsertNextNode(L->next,00);
        printf("打印数据\n");
        PrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@6--测试指定结点前插入函数@@\n");
    {
        printf("(对象为:L2,默认第1个结点前),e:11\n");
        InsertPriorNode(L2->next,11);
        printf("打印数据\n");
        PrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@7--测试插入数据函数@@\n");
    {
        printf("(对象为:L2,默认在第3个结点处插入,e:10)\n");
        ListInsert(L2,3,10);
        printf("打印数据\n");
        PrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@8--测试删除函数(对象为:L,默认删除第2个)@@\n");
    {
        printf("删除结点\n");

        ListDelete(&L,2,&result);
        printf("打印数据\n");
        PrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@9--测试指定结点删除函数@@\n");
    {
        printf("(对象为:L2,默认删除第1个结点)\n");
        DeleteNode(L2->next);
        printf("打印数据\n");
        PrintList(L2);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@10--测试求长度函数@@\n");
    {
        printf("(对象为:L)\n");
        printf("打印数据\n");
        printf("长度是:%d\n",Length(L));
        PrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@11--测试按位查找函数函数@@\n");
    {
        printf("(对象为:L，默认第四个结点)\n");
        printf("打印数据\n");
        LNode *temp = GetElem(L,4);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        PrintList(L);
        printf("\n");
    }
    PressEnterToContinue(false);
    printf("@@12--测试按值查找函数函数@@\n");
    {
        printf("(对象为:L2，默认找等于9)\n");
        printf("打印数据\n");
        LNode *temp = LocateElem(L,9);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        PrintList(L);
        printf("\n");
    }


}

/*带有头结点的所有操作*/
bool InitList(LinkList *L)
{
    (*L) = (LNode *)malloc(sizeof(LNode)); // 带有一个初始化的头结点
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
    (*L) = (LinkList)malloc(sizeof(LNode));//创建头结点
    (*L)->next = NULL;
    printf("insert e:\n");
    scanf("%d",&e);
    while(e != 9999)
    {
        node = (LNode *)malloc(sizeof(LNode *));
        node->data = e;
        node->next = (*L)->next; // 连接上一个结点
        (*L)->next = node; // 连接新的结点
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
        //循环内部自己就是尾巴，尾巴的next暂时保存自己
        //不论是使用tail或者是（*L）达到的结果都是一样的，tail和（*L）只不过是我们给到指针的一个名字而已，把一个名字给到另外一个人不代表失去名字的就会消失，也不代表他们之间的联系会消失。
        //(*L) = node; // 自己在成为尾巴
        tail = node;
        printf("insert e:\n");
        scanf("%d",&e);
    }
    tail->next = NULL; // 最后指向的一定是一个null
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
    // index = 0 index<0 false, j(0)<index(0) false -->返回头结点
    // index = 2 index <0 false,循环j=0,1 ,返回除头结点外的第二个结点。
    return temp; // 表长内返回对应值,超过返回NULL
}

bool ListInsert(LinkList *L,int index,int e)
{
    // 传入非法值
    if(index < 1)
    {
        return false;
    }
    // 联合调用GetElem 和向指定后插入操作函数。
    LNode *findNode = GetElem((*L),index-1); // 找到插入结点的前驱
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
    if(node == NULL) // index 值不合法
        return false;
    if(node->next ==NULL) // index - 1个结点之前已无其他结点
        return  false;
    LNode *delNode = node->next; // 指向删除结点
    e = delNode->data; // 返回找到的值
    node->next = delNode->next; // 断开连接
    free(delNode); // 释放
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
    LNode *temp = L->next; // 初始等于头结点的下一个结点，头结点是不存储数据的
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
