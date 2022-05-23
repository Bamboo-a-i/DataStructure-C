//
// Created by cxf18 on 2022/5/22.
//

#include "Exercises.h"

int main()
{
    setbuf(stdout,0);
    SqStack S1,S2;
    PressEnter;
    printf("@@1-课后习题03(P85)--");
    {
        printf("开始\n");
        //
        /*题目:
         * 利用栈S1和S2来模拟队列操作.
         * 已知:栈有判空/满/Pop/Push 操作
         * 实现:队列的EnQueue/Dequeue/Empty操作
         *
         * 分析:
         * 入队操作:可以拆分为先入栈S1-->如果S2为空且栈中已满,则将所有的元素出栈在入栈到S2中.
         * 出队操作:若S1不为空则执行出栈,否则输出空.在否则如果S1中还有元素可以被Pop到S2中,则继续Pop(S1),Push(S2);
         * */
        S1.top = S2.top = -1;
        ElemType e = 0;
        EnQueue(&S1,&S2,1);
        EnQueue(&S1,&S2,2);
        EnQueue(&S1,&S2,3);
        EnQueue(&S1,&S2,4);
        EnQueue(&S1,&S2,5);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        Empty(S1,S2);
    }
}

bool EnQueue(SqStack *S1,SqStack *S2,ElemType e)
{
    if(!SOverFlow(*S1)) // S1未满执行
    {
        Push(S1,e);
        return true;
    }
    if(SOverFlow(*S1) && !SEmpty(*S2)) // S1满且S2非空
    {
        printf("队列满\n");
        return false;
    }
    if(SOverFlow(*S1) && SEmpty(*S2)) // S1满且S2空
    {
        while (SEmpty(*S1) != true)
        {
            Pop(S1,&e);
            Push(S2,e);
        }
    }
    Push(S1,e); // if1/if2判断都未进入,if3执行的是S1满且S2空的情况将元素全部出栈入栈到S2,需要这一句将准备入栈的元素入栈.
    return true;
}

bool DeQueue(SqStack *S1,SqStack *S2,ElemType *e)
{
    if(!SEmpty(*S2)) // 栈S2中元素出队
    {
        Pop(S1,e);
    }
    else if(SEmpty(*S1)) // 栈S1空
    {
        printf("队列空\n");
    }
    else
    {
        while(!SEmpty(*S1)) // 栈S1中还有元素 -- 将他们陆续送入到S2中方便下次直接出队
        {
            Pop(S1,e);
            Push(S2,*e);
        }
    }
    Pop(S2,e);
    // if1未进入,else if进入 ==>代表S2中现在没有元素可以Pop,else 又将S1中的所有元素出栈入栈到S2,
    // 此句此时执行始终不会导致执行后没有Pop元素.
    return true;
}

bool Empty(SqStack S1,SqStack S2)
{
    if(SEmpty(S1) && SEmpty(S2))
        return true;
    else
        return false;
}

bool SEmpty(SqStack S)
{
    if(S.top == -1)
        return true;
    else
        return false;
}
bool SOverFlow(SqStack S)
{
    if(S.top == Maxsize -1)//满
        return true;
    else
        return false;
}
bool Push(SqStack *S,ElemType e)
{
    if((*S).top == Maxsize -1)//满
        return false;
    (*S).data[++(*S).top] = e;
    return true;
}

bool Pop(SqStack *S,ElemType *e)
{
    if((*S).top == -1)//空
        return false;
    (*e) = (*S).data[(*S).top--];
    return true;
}