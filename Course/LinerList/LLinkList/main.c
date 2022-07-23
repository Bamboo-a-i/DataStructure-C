//
// Created by cxf18 on 2022/7/5.
//
#include "LLinkList.h"

int main()
{
    setbuf(stdout,0);
    LLinkList L;

    printf("@@1--测试初始化循环单链表函数--;\n");
    {
        printf("开始初始化!\n");
        LLinkListInit(&L);
    }

    printf("@@2--测试判空函数--;\n");
    {
        printf("输出1为空\n");
        printf("结果是:%d\n", Empty(L));
    }

    printf("@@3--测试指定结点后插入函数--;\n");
    {
        LLNode temp;
        temp.data = 15;
        InsertNextNode(L,&temp);
        printf("打印数据!\n");
        PrintLLinkList(L);
    }
}
