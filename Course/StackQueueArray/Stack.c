//
// Created by cxf18 on 2022/5/16.
//

#include "Stack.h"

int main()
{
    SqStack S;
    setbuf(stdout,0);
    PressEnterToContinue(false);
    printf("@@1--��ʼ���Ѻ���--\n");
    {
        printf("��ʼ\n");
        InitStack(&S);
    }
    PressEnterToContinue(false);
    printf("@@2--�пպ���--\n");
    {
        printf("��ʼ\n");
        printf("isEmpty:%d\n",StackEmpty(S));
    }
    PressEnterToContinue(false);
    printf("@@3--��ջ����--\n");
    {
        printf("��ʼ\n");
        Push(&S,1);
        Push(&S,2);
        Push(&S,3);
        Push(&S,4);
        Push(&S,5);
        PrintStack(S);
    }
    PressEnterToContinue(false);
    printf("@@4--��ջ����--\n");
    {
        printf("��ʼ\n");
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
    printf("@@5--��ȡջ������--\n");
    {
        printf("��ʼ\n");
        ElemType x  = 0;
        GetPop(S,&x);
        printf("x = %d\n",x);
        PrintStack(S);
    }
}

void InitStack(SqStack *S)
{
    (*S).top = -1;
    // (*S).top = 0;
}

bool StackEmpty(SqStack S)
{
    // if(S.top == 0)
    if(S.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack *S,ElemType x)
{
    // if((*S).top == MaxSize)
    if((*S).top - 1 == MaxSize)
        // ջ��
        return false;
    (*S).data[++(*S).top] = x; // === S.top += 1; S.data[S.top] = x;
    // (*S).data[(*S).top++] = x;  ��ʼջ��Ϊ0ʱ
    return true;
}

bool Pop(SqStack *S,ElemType *x)
{
    // if((*S).top == MaxSize)
    if((*S).top == -1) // û��Ԫ�ؿ��Թ�����
        return false;
    (*x) = (*S).data[(*S).top--]; // === x = S.data[S.top];S.top--;
    // (*x) = (*S).data[--(*S).top]; ��ʼջ��Ϊ0ʱ
    return true;
}

bool GetPop(SqStack S,ElemType *x)
{
    if(S.top == -1) // û��Ԫ�ؿ��Թ�����
        return false;
    (*x) = S.data[S.top];
    return true;
}

void PrintStack(SqStack S)
{
    if(S.top == -1)
        return;
    ElemType count = S.top;
    while(count != -1)
    {
        printf("S.data[%d] = %d\n",count,S.data[count]);
        count--;
    }
}