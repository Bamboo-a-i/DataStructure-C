//
// Created by cxf18 on 2022/7/5.
//

#include "main.h"
int main()
{
    setbuf(stdout,0);
    SqQueue Q;
    PressEnterToContinue(false);
    printf("@@1--队列初始化--\n");
    {
        printf("开始\n");
        InitQueue(&Q);
    }
    PressEnterToContinue(false);
    printf("@@2--队列判空--\n");
    {
        printf("开始\n");
        printf("res:%d\n",QueueEmpty(Q));
    }
    PressEnterToContinue(false);
    printf("@@3--入队--\n");
    {
        printf("开始\n");
        EnQueue(&Q,1);
        EnQueue(&Q,2);
        EnQueue(&Q,3);
        EnQueue(&Q,4);
        EnQueue(&Q,5);
    }
    PressEnterToContinue(false);
    printf("@@4--出队--\n");
    {
        printf("开始\n");
        ElemType x = 0;
        DeQueue(&Q,&x);
        printf("deQueue:%d\n",x);
        DeQueue(&Q,&x);
        printf("deQueue:%d\n",x);
        PrintQueue(Q);
    }
    PressEnterToContinue(false);
    printf("@@5--销毁--\n");
    {
        printf("开始\n");
        ElemType x = 0;
        GetHead(Q,&x);
        printf("deQueue:%d\n",x);
        PrintQueue(Q);
        Destroy(&Q);

    }
    PressEnterToContinue(false);
    printf("@@6--size来判空--\n");
    {
        printf("开始\n");
        SqQueue1 Q1;
        ElemType x = 0;
        Q1.rear = Q1.front = Q1.size = 0;
        printf("开始入队\n");
        EnQueue1(&Q1,10);
        EnQueue1(&Q1,11);
        EnQueue1(&Q1,12);
        EnQueue1(&Q1,13);
        EnQueue1(&Q1,14);
        EnQueue1(&Q1,15);
        PrintQueue1(Q1);
        printf("开始出队\n");
        DeQueue1(&Q1,&x);
        printf("deQueue:%d\n",x);
        DeQueue1(&Q1,&x);
        printf("deQueue:%d\n",x);
        DeQueue1(&Q1,&x);
        printf("deQueue:%d\n",x);
        PrintQueue1(Q1);

    }
    PressEnterToContinue(false);
    printf("@@7--tag来判空--\n");
    {
        printf("开始\n");
        SqQueue2 Q2;
        ElemType x = 0;
        Q2.rear = Q2.front = Q2.tag = 0;
        printf("开始入队\n");
        EnQueue2(&Q2,10);
        EnQueue2(&Q2,11);
        EnQueue2(&Q2,12);
        EnQueue2(&Q2,13);
        EnQueue2(&Q2,14);
        EnQueue2(&Q2,15);
        printf("开始出队\n");
        DeQueue2(&Q2,&x);
        printf("deQueue:%d\n",x);
        DeQueue2(&Q2,&x);
        printf("deQueue:%d\n",x);
        DeQueue2(&Q2,&x);
        printf("deQueue:%d\n",x);
    }
}