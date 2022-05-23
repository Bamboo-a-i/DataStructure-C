//
// Created by cxf18 on 2022/5/20.
//

#include "Queue.h"
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

bool InitQueue(SqQueue *Q)
{
    // 队头队尾指向0
    (*Q).rear = (*Q).front = 0;
    return true;
}

bool QueueEmpty(SqQueue Q)
{
    if(Q.rear == Q.front) // 队空
        return true;
    else
        return false;
}

bool EnQueue(SqQueue *Q,ElemType x)
{
    // 此种方式使得又一片内存空间得不到使用
    // 如果rear超过MaxSize，则直接将其从a[0]重新开始存储，如果rear+1和front重合，则表示数组已满
    if(((*Q).rear+1) % MaxSize == (*Q).front)
        return false;
    (*Q).data[(*Q).rear] = x;
    (*Q).rear = ((*Q).rear+1)%MaxSize;
    return true;
}

bool DeQueue(SqQueue *Q,ElemType *x)
{
    if((*Q).rear == (*Q).front) // 队空
        return false;
    (*x) = (*Q).data[(*Q).front];
    (*Q).front = (*Q).front+1 % MaxSize;
    return true;
}

void GetHead(SqQueue Q,ElemType *x)
{
    if(Q.front == Q.rear)
        return;
    (*x) = Q.data[Q.front];
}

bool Destroy(SqQueue *Q)
{
    if((*Q).front == 0 && (*Q).rear == 0)
    {
        // 已知就是一个空队列 直接返回
        return true;
    }
    int index;
    for (index = (*Q).rear-1; index >= 0; index--)
    {
        (*Q).data[index] = 0; // 遍历将值置为0
    }
    (*Q).front = (*Q).rear = 0; // 指针置零
    return true;
}

bool EnQueue1(SqQueue1 *Q1,ElemType x)
{
    if((*Q1).size == MaxSize)
        return false;// 栈满
    (*Q1).size++;
    (*Q1).data[(*Q1).rear] = x;
    (*Q1).rear = (*Q1).rear+1 % MaxSize;
    return true;
}

bool DeQueue1(SqQueue1 *Q1,ElemType *x)
{
    if((*Q1).size == 0)
        return false; // 表示栈空
    (*Q1).size--;
    (*x) = (*Q1).data[(*Q1).front];
    (*Q1).front = (*Q1).front+1 % MaxSize;
    return true;
}

bool EnQueue2(SqQueue2 *Q2,ElemType x)
{
    if((*Q2).front == (*Q2).rear && (*Q2).tag == 1)
        return false;
    (*Q2).tag = 1;
    (*Q2).data[(*Q2).rear] = x;
    (*Q2).rear = ((*Q2).rear+1) % MaxSize;
    return true;
}

bool DeQueue2(SqQueue2 *Q2,ElemType *x)
{
    if((*Q2).front == (*Q2).rear && (*Q2).tag == 0)
        return false;
    (*Q2).tag = 0;
    (*x) = (*Q2).data[(*Q2).front];
    (*Q2).front = ((*Q2).front+1) % MaxSize;
    return true;
}

bool PrintQueue(SqQueue Q)
{
    if(Q.rear == Q.front)
        return false;
    int index;
    for (index = Q.front; index < Q.rear ; index++)
    {
        printf("Q.data[%d] = %d\n",index,Q.data[index]);
    }
    return true;
}

bool PrintQueue1(SqQueue1 Q1)
{
    if(Q1.rear == Q1.front)
        return false;
    int index;
    for (index = Q1.front; index < Q1.rear ; index++)
    {
        printf("Q.data[%d] = %d\n",index,Q1.data[index]);
    }
    return true;
}
