//
// Created by cxf18 on 2022/6/27.
//
#include "Exercise.h"

int main() {
    LinkList L;
    setbuf(stdout,0);
    LinkHeadInsert(&L);
    PressEnterToContinue(false);
    printf("@@3--课后习题第3题--;\n");
    {
        printf("开始答题!\n");
        R_Print(L);
    }
    PressEnterToContinue(false);
    printf("@@4--课后习题第4题--;\n");
    {
        printf("开始答题!\n");
        Delete_MinNode(&L);
    }

    PressEnterToContinue(false);
    printf("@@5--课后习题第5题--;\n");
    {
        printf("开始答题!\n");
        Reverse_LinkList1(&L); // 方法1
        Reverse_LinkList2(&L); // 方法2
        PrintList(L);
    }

    PressEnterToContinue(false);
    printf("@@6--课后习题第6题--;\n");
    {
        printf("开始答题!\n");
        Sort(&L); // 方法1
        PrintList(L);
    }

}