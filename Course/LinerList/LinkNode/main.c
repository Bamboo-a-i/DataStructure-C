//
// Created by cxf18 on 2022/7/5.
//
#include "LinkNode.h"

int main()
{
    setbuf(stdout,0);
    LinkList L,L2;
    int result = 0;
    //LNode *result;
    // 有头结点操作
    printf("带有头结点的操作\n");
    printf("@@1--测试初始化函数@@\n");
    {
        printf("初始化一个单链表L...\n");
        InitList(&L);
        InitList(&L2);
        printf("\n");
    }

    printf("@@2--测试判空函数@@\n");
    {
        printf("测试对象为L\n");
        printf("输出1为空...\n");
        bool isEmpty = Empty(&L);
        printf("%d\n",isEmpty);
        printf("\n");
    }

    printf("@@3--测试头插法函数@@\n");
    {
        printf("输入一串数据!(9999表示退出),头插法是对L进行建立\n");
        LinkHeadInsert(&L);
        printf("打印数据\n");
        PrintList(L);
        printf("\n");
    }

    printf("@@4--测试尾插法函数@@\n");
    {
        printf("输入一串数据!(9999表示退出),尾插法是对L2进行建立\n");
        LinkTailInsert (&L2);
        printf("打印数据\n");
        PrintList(L2);
        printf("\n");
    }

    printf("@@5--测试指定结点后插入函数@@\n");
    {
        printf("(对象为:L,默认第1个结点后),e:00\n");
        InsertNextNode(L->next,00);
        printf("打印数据\n");
        PrintList(L);
        printf("\n");
    }

    printf("@@6--测试指定结点前插入函数@@\n");
    {
        printf("(对象为:L2,默认第1个结点前),e:11\n");
        InsertPriorNode(L2->next,11);
        printf("打印数据\n");
        PrintList(L2);
        printf("\n");
    }

    printf("@@7--测试插入数据函数@@\n");
    {
        printf("(对象为:L2,默认在第3个结点处插入,e:10)\n");
        ListInsert(L2,3,10);
        printf("打印数据\n");
        PrintList(L2);
        printf("\n");
    }

    printf("@@8--测试删除函数(对象为:L,默认删除第2个)@@\n");
    {
        printf("删除结点\n");

        ListDelete(&L,2,&result);
        printf("打印数据\n");
        PrintList(L);
        printf("\n");
    }

    printf("@@9--测试指定结点删除函数@@\n");
    {
        printf("(对象为:L2,默认删除第1个结点)\n");
        DeleteNode(L2->next);
        printf("打印数据\n");
        PrintList(L2);
        printf("\n");
    }

    printf("@@10--测试求长度函数@@\n");
    {
        printf("(对象为:L)\n");
        printf("打印数据\n");
        printf("长度是:%d\n",Length(L));
        PrintList(L);
        printf("\n");
    }

    printf("@@11--测试按位查找函数函数@@\n");
    {
        printf("(对象为:L，默认第四个结点)\n");
        printf("打印数据\n");
        LNode *temp = GetElem(L,4);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        PrintList(L);
        printf("\n");
    }

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
