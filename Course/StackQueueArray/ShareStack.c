//
// Created by cxf18 on 2022/5/16.
//

#include "ShareStack.h"
#include "Status.h"

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

void InitStack(ShStack *S)
{
    (*S).top[0] = -1;
    (*S).top[1] = MaxSize;
}

bool StackEmpty(ShStack S,ElemType stackNum)
{
    if(stackNum == 0 && S.top[stackNum] == -1)
    {
        printf("栈0为空\n");
        return true;
    }

    if(stackNum == 1 && S.top[stackNum] == MaxSize)
    {
        printf("栈1为空\n");
        return true;
    }
}

bool Push(ShStack *S,ElemType x,ElemType stackNum)
{
    if((*S).top[0] - (*S).top[1] == 1) // 栈满
        return false;
    switch (stackNum) {
        case 0:
            (*S).data[++(*S).top[0]] = x;
            return true;
            break;
        case 1:
            (*S).data[--(*S).top[1]] = x;
            return true;
            break;
    }
    return true;
}

bool Pop(ShStack *S,ElemType *x,ElemType stackNum)
{
    switch (stackNum) {
        case 0:
            if((*S).top[stackNum] == -1) // 栈空
                return false;
            else
            {
                (*x) = (*S).data[(*S).top[0]--];
                return true;
            }
            break;
        case 1:
            if((*S).top[stackNum] == MaxSize) // 栈空
                return false;
            else
            {
                (*x) = (*S).data[(*S).top[1]++];
                return true;
            }
            break;
    }
    return true;
}

bool GetPop(ShStack S,ElemType *x,ElemType stackNum)
{
    if(S.top[0] - S.top[1] == 1) // 栈满
        return false;
    switch (stackNum) {
        case 0:
            (*x) = S.data[S.top[0]];
            break;
        case 1:
            (*x) = S.data[S.top[1]];
            break;
        default:
            return false;
    }
    return true;
}

void PrintStack(ShStack S,ElemType stackNum)
{
    if(S.top[0] - S.top[1] == 1) // 栈满
        return ;
    ElemType count = 0;
    switch (stackNum) {
        case 0:
            count = S.top[0];
            while(count != -1)
            {
                printf("S.data[%d] = %d\n",count,S.data[count]);
                count--;
            }
            break;
        case 1:
            count = S.top[1];
            while(count != MaxSize)
            {
                printf("S.data[%d] = %d\n",count,S.data[count]);
                count++;
            }
            break;
        default:
            return ;
    }
}