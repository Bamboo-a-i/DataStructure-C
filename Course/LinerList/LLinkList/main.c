//
// Created by cxf18 on 2022/7/5.
//
#include "LLinkList.h"

int main()
{
    setbuf(stdout,0);
    LLinkList L;

    printf("@@1--���Գ�ʼ��ѭ����������--;\n");
    {
        printf("��ʼ��ʼ��!\n");
        LLinkListInit(&L);
    }

    printf("@@2--�����пպ���--;\n");
    {
        printf("���1Ϊ��\n");
        printf("�����:%d\n", Empty(L));
    }

    printf("@@3--����ָ��������뺯��--;\n");
    {
        LLNode temp;
        temp.data = 15;
        InsertNextNode(L,&temp);
        printf("��ӡ����!\n");
        PrintLLinkList(L);
    }
}
