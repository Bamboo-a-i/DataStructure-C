//
// Created by cxf18 on 2022/7/5.
//

#include "LDLinkList.h"

int main()
{
    LDLinkList L;
    setbuf(stdout,0);
    printf("@@1--���Գ�ʼ��ѭ����������--;\n");
    {
        printf("��ʼ��ʼ��!\n");
        LDLinkListInit(&L);
    }

    printf("@@2--�����пպ���--;\n");
    {
        printf("���1Ϊ��\n");
        printf("�����:%d\n", Empty(L));
    }

    printf("@@3--�����Ƿ��Ǳ�β��㺯��--;\n");
    {
        printf("���1��ʾ�Ǳ�β\n");
        printf("�����:%d\n", IsTail(L,L->next));
    }

    printf("@@4--����ָ��������뺯��--;\n");
    {
        LDLNode temp;
        temp.data = 15;
        InsertNextNode(L,&temp);
        printf("��ӡ����!\n");
        PrintLDLinkList(L);
    }

    printf("@@5--����ɾ����㺯��--;\n");
    {
        Delete(L->next->next);
        printf("��ӡ����!\n");
        PrintLDLinkList(L);
    }
}
