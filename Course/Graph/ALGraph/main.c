//
// Created by cxf18 on 2022/7/10.
//
#include "ALGraph.h"
int main()
{
    setbuf(stdout,0);
    ALGraph G;
    printf("@@1--@@邻接表测试 -- 无向无权值\n");
    {
        CreateAlGraph(&G,UDG);
        InsertVertex(&G,'A');
        InsertVertex(&G,'B');
        InsertVertex(&G,'C');
        InsertVertex(&G,'D');
        InsertVertex(&G,'E');
        InsertVertex(&G,'F');
        AddEdge(&G,'A','B',1);
        AddEdge(&G,'A','C',1);
        AddEdge(&G,'A','D',1);
        AddEdge(&G,'B','E',1);
        AddEdge(&G,'B','F',1);
        AddEdge(&G,'B','A',1);
        AddEdge(&G,'C','A',1);
        AddEdge(&G,'C','E',1);
        AddEdge(&G,'D','F',1);
        AddEdge(&G,'D','A',1);
        AddEdge(&G,'E','B',1);
        AddEdge(&G,'E','C',1);
        AddEdge(&G,'F','B',1);
        AddEdge(&G,'F','D',1);
    }
}