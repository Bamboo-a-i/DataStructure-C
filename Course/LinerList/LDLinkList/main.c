//
// Created by cxf18 on 2022/7/5.
//

#include "LDLinkList.h"

int main()
{
    LDLinkList L;
    setbuf(stdout,0);
    printf("@@1--测试初始化循环单链表函数--;\n");
    {
        printf("开始初始化!\n");
        LDLinkListInit(&L);
    }

    printf("@@2--测试判空函数--;\n");
    {
        printf("输出1为空\n");
        printf("结果是:%d\n", Empty(L));
    }

    printf("@@3--测试是否是表尾结点函数--;\n");
    {
        printf("输出1表示是表尾\n");
        printf("结果是:%d\n", IsTail(L,L->next));
    }

    printf("@@4--测试指定结点后插入函数--;\n");
    {
        LDLNode temp;
        temp.data = 15;
        InsertNextNode(L,&temp);
        printf("打印数据!\n");
        PrintLDLinkList(L);
    }

    printf("@@5--测试删除结点函数--;\n");
    {
        Delete(L->next->next);
        printf("打印数据!\n");
        PrintLDLinkList(L);
    }
}
