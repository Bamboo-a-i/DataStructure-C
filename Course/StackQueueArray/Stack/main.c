//
// Created by cxf18 on 2022/7/5.
//

#include "main.h"
int main()
{
    SqStack S;
    setbuf(stdout,0);
    PressEnterToContinue(false);
    printf("@@1--初始化堆函数--\n");
    {
        printf("开始\n");
        InitStack(&S);
    }
    PressEnterToContinue(false);
    printf("@@2--判空函数--\n");
    {
        printf("开始\n");
        printf("isEmpty:%d\n",StackEmpty(S));
    }
    PressEnterToContinue(false);
    printf("@@3--入栈函数--\n");
    {
        printf("开始\n");
        Push(&S,1);
        Push(&S,2);
        Push(&S,3);
        Push(&S,4);
        Push(&S,5);
        PrintStack(S);
    }
    PressEnterToContinue(false);
    printf("@@4--出栈函数--\n");
    {
        printf("开始\n");
        ElemType x  = 0;
        Pop(&S,&x);
        printf("Pop x = %d\n",x);
        Pop(&S,&x);
        printf("Pop x = %d\n",x);
        Pop(&S,&x);
        printf("Pop x = %d\n",x);
        PrintStack(S);
    }
    PressEnterToContinue(false);
    printf("@@5--获取栈顶函数--\n");
    {
        printf("开始\n");
        ElemType x  = 0;
        GetPop(S,&x);
        printf("x = %d\n",x);
        PrintStack(S);
    }
}