//
// Created by cxf18 on 2022/7/5.
//

#include "main.h"
int main()
{
    ShStack S;
    setbuf(stdout,0);
    PressEnterToContinue(false);
    printf("@@1--初始化共享栈函数--\n");
    {
        printf("开始\n");
        InitStack(&S);
    }
    PressEnterToContinue(false);
    printf("@@2--判空函数--\n");
    {
        printf("开始\n");
        printf("isEmpty:%d\n",StackEmpty(S,1));
        printf("isEmpty:%d\n",StackEmpty(S,0));
    }
    PressEnterToContinue(false);
    printf("@@3--入栈函数--\n");
    {
        printf("开始\n");
        printf("栈1\n");
        Push(&S,1,1);
        Push(&S,2,1);
        Push(&S,3,1);
        Push(&S,4,1);
        Push(&S,5,1);
        PrintStack(S,1);
        printf("栈0\n");
        Push(&S,1,0);
        Push(&S,2,0);
        Push(&S,3,0);
        Push(&S,4,0);
        Push(&S,5,0);
        PrintStack(S,0);
    }
    PressEnterToContinue(false);
    printf("@@4--出栈函数--\n");
    {
        printf("开始\n");
        ElemType x  = 0;
        printf("栈1\n");
        Pop(&S,&x,1);
        printf("Pop x = %d\n",x);
        Pop(&S,&x,1);
        printf("Pop x = %d\n",x);
        PrintStack(S,1);
        printf("栈0\n");
        Pop(&S,&x,0);
        printf("Pop x = %d\n",x);
        Pop(&S,&x,0);
        printf("Pop x = %d\n",x);
        PrintStack(S,0);
    }
    PressEnterToContinue(false);
    printf("@@5--获取栈顶函数--\n");
    {
        printf("开始\n");
        ElemType x  = 0;
        printf("栈1\n");
        GetPop(S,&x,1);
        printf("x = %d\n",x);
        PrintStack(S,1);
        printf("栈0\n");
        GetPop(S,&x,0);
        printf("x = %d\n",x);
        PrintStack(S,0);

    }
}