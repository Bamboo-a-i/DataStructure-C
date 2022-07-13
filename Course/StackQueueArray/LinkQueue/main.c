//
// Created by cxf18 on 2022/7/5.
//

#include "main.h"
int main()
{
    setbuf(stdout,0);
    LinkQueue LQ;
    LinkQueue LQ1;
    PressEnterToContinue(false);
    printf("@@1--链队的初始化--\n");
    {
        printf("开始\n");
        printf("带有头结点\n");
        InitLQueue(&LQ);
        printf("不带有头结点\n");
        InitNHLQueue(&LQ1);
    }
    PressEnterToContinue(false);
    printf("@@2--链队判空--\n");
    {

        printf("开始\n");
        printf("带有头结点\n");
        printf("res:%d\n",EmptyLQueue(LQ));
        printf("不带有头结点\n");
        printf("res:%d\n",EmptyNHLQueue(LQ1));
    }
    PressEnterToContinue(false);
    printf("@@3--入队--\n");
    {
        printf("开始\n");
        printf("带有头结点\n");
        EnLQueue(&LQ,1);
        EnLQueue(&LQ,2);
        EnLQueue(&LQ,3);
        EnLQueue(&LQ,4);
        printf("不带有头结点\n");
        EnNHLQueue(&LQ1,5);
        EnNHLQueue(&LQ1,6);
        EnNHLQueue(&LQ1,7);
        EnNHLQueue(&LQ1,8);
    }
    PressEnterToContinue(false);
    printf("@@4--出队--\n");
    {
        ElemType x = 0;
        printf("开始\n");
        printf("带有头结点\n");
        DeLQueue(&LQ,&x);
        printf("deQueue:%d\n",x);
        DeLQueue(&LQ,&x);
        printf("deQueue:%d\n",x);
        DeLQueue(&LQ,&x);
        printf("deQueue:%d\n",x);
        DeLQueue(&LQ,&x);
        printf("deQueue:%d\n",x);

        printf("不带有头结点\n");
        DeNHLQueue(&LQ1,&x);
        printf("deQueue:%d\n",x);
        DeNHLQueue(&LQ1,&x);
        printf("deQueue:%d\n",x);
        DeNHLQueue(&LQ1,&x);
        printf("deQueue:%d\n",x);
        DeNHLQueue(&LQ1,&x);
        printf("deQueue:%d\n",x);
    }
}