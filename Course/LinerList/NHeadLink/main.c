//
// Created by cxf18 on 2022/7/5.
//
#include "NHeadLink.h"
int main()
{
    setbuf(stdout,0);
    LinkList L,L2;
    int result = 0;
    /*无头结点操作*/

    printf("不带有头结点\n");
    printf("@@1--测试初始化函数@@\n");
    {
        printf("初始化一个不带有头结点单链表L...\n");
        NHeadInitList(&L);
        NHeadInitList(&L2);
        printf("\n");
    }

    printf("@@2--测试判空函数@@\n");
    {
        printf("测试对象为L\n");
        printf("输出1为空...\n");
        bool isEmpty = NHeadEmpty(&L);
        printf("%d\n",isEmpty);
        printf("\n");
    }

    printf("@@3--测试头插法函数@@\n");
    {
        printf("输入一串数据!(9999表示退出),头插法是对L进行建立\n");
        NHeadLinkHeadInsert(&L);
        printf("打印数据\n");
        NHeadPrintList(L);
        printf("\n");
    }

    printf("@@4--测试尾插法函数@@\n");
    {
        printf("输入一串数据!(9999表示退出),尾插法是对L2进行建立\n");
        NHeadLinkTailInsert (&L2);
        printf("打印数据\n");
        NHeadPrintList(L2);
        printf("\n");
    }

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

    printf("@@7--测试插入数据函数@@\n");
    {
        printf("(对象为:L2,默认在第1个结点处插入)\n");
        NHeadListInsert(&L2,1,114);
        printf("打印数据\n");
        NHeadPrintList(L2);
        printf("\n");
    }

    printf("@@8--测试删除函数(对象为:L,默认删除第1个)@@\n");
    {
        printf("删除结点\n");
        NHeadListDelete(&L,2,&result);
        printf("删除的值:%d",result);
        printf("打印数据\n");
        NHeadPrintList(L);
        printf("\n");
    }

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

    printf("@@10--测试求长度函数@@\n");
    {
        printf("(对象为:L)\n");
        printf("打印数据\n");
        printf("长度是:%d\n",NHeadLength(L));
        NHeadPrintList(L);
        printf("\n");
    }

    printf("@@11--测试按位查找函数函数@@\n");
    {
        printf("(对象为:L，默认第四个结点)\n"); //实际输出会是第5个结点的数据
        printf("打印数据\n");
        LNode *temp = NHeadGetElem(L,3);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        NHeadPrintList(L);
        printf("\n");
    }

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
