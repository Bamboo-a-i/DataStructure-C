//
// Created by cxf18 on 2022/7/5.
//

#include "DLinkNode.h"
int main()
{
    setbuf(stdout, 0);
    DLinkList L;
    DLinkList L2;
    printf("@@1--测试初始化双链表函数--;\n");
    {
        printf("result=%d\n",InitDLinkList(&L));
        InitDLinkList(&L2);
    }
    printf("@@2--测试判空函数--;\n");
    {
        printf("result=%d\n",Empty(L));
    }
    printf("@@3--测试头插法函数--;\n");
    {
        DLinkHeadInsert(&L);
        printf("打印数据!\n");
        PrintDLink(L);
    }
    printf("@@4--测试尾插法函数--;\n");
    {
        printf("测试对象L2\n");
        DLinkTailInsert(&L2);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    printf("@@5--测试指定结点后插入函数--;\n");
    {
        DNode node;
        node.data=15;
        printf("测试对象L2->prior,传入一个结点node.data = 15\n");
        InsertNextDnode(L2->next,&node);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    printf("@@6--测试指定结点前插入函数--;\n");
    {
        printf("测试对象L2\n");
        DLinkTailInsert(&L2);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    printf("@@7--测试指定结点插入函数--;\n");
    {
        printf("测试对象L2\n");
        DLinkTailInsert(&L2);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    printf("@@8--测试删除后继结点函数--;\n");
    {
        printf("测试对象L2->next -- 传入L\n");
        DeleteNextNode(L2->next);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    printf("@@9--测试删除前驱结点函数--;\n");
    {
        printf("测试对象L2 -- 传入L2->next->next\n");
        DeletePriorNode(L2->next->next);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    printf("@@10--测试删除指定结点函数--;\n");
    {
        printf("测试对象L2 -- 传入L2->next->next\n");
        DeleteNode(&L2,L2->next->next);
        printf("打印数据!\n");
        PrintDLink(L2);
    }
    printf("@@11--测试销毁双链表函数--;\n");
    {
        printf("测试对象L2 -- 传入L2->next->next\n");
        DestroyList(&L2);
        printf("result=%d\n",Empty(L2));
    }
}