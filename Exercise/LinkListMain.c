//
// Created by cxf18 on 2022/6/27.
//
#include "Exercise.h"

int main() {
    LinkList L;
    setbuf(stdout,0);
    LinkHeadInsert(&L);
    PressEnterToContinue(false);
    printf("@@3--�κ�ϰ���3��--;\n");
    {
        printf("��ʼ����!\n");
        R_Print(L);
    }
    PressEnterToContinue(false);
    printf("@@4--�κ�ϰ���4��--;\n");
    {
        printf("��ʼ����!\n");
        Delete_MinNode(&L);
    }

    PressEnterToContinue(false);
    printf("@@5--�κ�ϰ���5��--;\n");
    {
        printf("��ʼ����!\n");
        Reverse_LinkList1(&L); // ����1
        Reverse_LinkList2(&L); // ����2
        PrintList(L);
    }

    PressEnterToContinue(false);
    printf("@@6--�κ�ϰ���6��--;\n");
    {
        printf("��ʼ����!\n");
        Sort(&L); // ����1
        PrintList(L);
    }

}