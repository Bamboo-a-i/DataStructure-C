//
// Created by cxf18 on 2022/6/27.
//
#include "Exercise.h"

bool R_Print(LinkList L)
{
    LNode *temp = (L);
    if(temp->next != NULL)
    {
        temp = temp->next;
        R_Print(temp);
    }
    if(L != NULL)
        printf("address:%p,data:%d\n",temp,temp->data);
    return true;
}

LinkList Delete_MinNode(LinkList *L)
{
    LNode *pre = (*L),*p = pre->next; // 记录前结点和当前比较结点
    LNode *minPre = pre,*minP = p; // 记录最小结点前驱和结点
    while (p != NULL)
    {
        if(p->data < minP->data)
        {
            minP = p; // 满足小于的要求更新
            minPre = pre;
        }
        pre = p; // 不满足要求，向前移动
        p = p->next;
    }
    minPre->next = minP->next; // 断开连接
    free(minP); // 释放
    return (*L);
}

LinkList Reverse_LinkList1(LinkList *L)
{
    LNode *p,*r;
    p = (*L)->next; // 指向第一个元素
    (*L)->next = NULL; // 首结点变为尾结点
    while (p != NULL)
    {
        r = p->next; // 获取后驱结点
        p->next = (*L)->next; // 插入到首结点位置
        (*L)->next = p; // 前驱连接
        p = r; // 先前移动
    }
    return (*L);
}

LinkList Reverse_LinkList2(LinkList *L)
{
    LNode *p,*r,*pre;
    p = (*L)->next; // 指向首结点
    r = p->next; // 指向第一个结点
    p->next = NULL; // 逐步变为尾结点.
    while (r !=NULL)
    {
        pre = p; // 前结点等于当前结点
        p = r; // 将后继结点赋值给当前结点
        r = r->next; // 后继结点向前移动
        p->next = pre; // 开始建立逆序链表关系
    }
    (*L)->next  = p; // 首节点
    return (*L);
}

void Sort(LinkList *L)
{
    LNode *p,*r,*pre;
    p = (*L)->next;
    r = p->next;
    p->next = NULL; // 给链表(*L)中留下了p和头结点.  形成比较的第一个初始元素.
    p = r; // 指向下一个结点
    while (p != NULL)
    {
        r = p->next; // 连接p和后续结点的关系
        pre = (*L); // 拿到进行比较的链表
        while (pre->next != NULL && pre->next->data < p->data) // 判断前结点值是否小于后结点的值.
            pre = pre->next; // 如果小于 1.可以将值小的结点保存下来. 2.如果后面还有最小结点,可以进一步向前移动
        p->next = pre->next; // 此处时while结束后的第一个结点,说明 pre要么保存了最小结点,要么就是现有的已经排序的链表(*L)的最小元素还大于p;
        pre->next = p;
        p = r;
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

void PrintList(LinkList L)
{
    LNode *temp = L->next; // 初始等于头结点的下一个结点，头结点是不存储数据的
    while(temp != NULL)
    {
        printf("nodeAddress:%p;nodee:%d\n",temp,temp->data);
        temp = temp->next;
    }
}