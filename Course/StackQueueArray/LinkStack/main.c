//
// Created by cxf18 on 2022/7/5.
//

#include "main.h"
int main()
{
    setbuf(stdout,0);
    LinkStack Ls;
    PressEnterToContinue(false);
    printf("@@1--初始化共享栈函数--\n");
    {
        printf("开始\n");
        InitStack(&Ls);
    }

    PressEnterToContinue(false);
    printf("@@2--测试判空函数--\n");
    {
        printf("开始\n");
        printf("isEmpty:%d\n",Empty(&Ls));
    }

    PressEnterToContinue(false);
    printf("@@3--测试入栈函数--\n");
    {
        printf("开始\n");
        Push(&Ls,11);
        Push(&Ls,12);
        PrintLinkStack(&Ls);
    }

    PressEnterToContinue(false);
    printf("@@4--测试出栈函数--\n");
    {
        ElemType e = 0;
        printf("开始\n");
        Pop(&Ls,&e);
        printf("e:%d\n",e);
        PrintLinkStack(&Ls);
    }

    PressEnterToContinue(false);
    printf("@@4--测试获取栈顶函数--\n");
    {
        ElemType e = 0;
        printf("开始\n");
        GetPop(&Ls,&e);
        printf("e:%d\n",e);
        PrintLinkStack(&Ls);
    }
}