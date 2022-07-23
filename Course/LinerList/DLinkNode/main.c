//
// Created by cxf18 on 2022/7/5.
//

#include "DLinkNode.h"
int main()
{
    setbuf(stdout, 0);
    DLinkList L;
    DLinkList L2;
    printf("@@1--���Գ�ʼ��˫������--;\n");
    {
        printf("result=%d\n",InitDLinkList(&L));
        InitDLinkList(&L2);
    }
    printf("@@2--�����пպ���--;\n");
    {
        printf("result=%d\n",Empty(L));
    }
    printf("@@3--����ͷ�巨����--;\n");
    {
        DLinkHeadInsert(&L);
        printf("��ӡ����!\n");
        PrintDLink(L);
    }
    printf("@@4--����β�巨����--;\n");
    {
        printf("���Զ���L2\n");
        DLinkTailInsert(&L2);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    printf("@@5--����ָ��������뺯��--;\n");
    {
        DNode node;
        node.data=15;
        printf("���Զ���L2->prior,����һ�����node.data = 15\n");
        InsertNextDnode(L2->next,&node);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    printf("@@6--����ָ�����ǰ���뺯��--;\n");
    {
        printf("���Զ���L2\n");
        DLinkTailInsert(&L2);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    printf("@@7--����ָ�������뺯��--;\n");
    {
        printf("���Զ���L2\n");
        DLinkTailInsert(&L2);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    printf("@@8--����ɾ����̽�㺯��--;\n");
    {
        printf("���Զ���L2->next -- ����L\n");
        DeleteNextNode(L2->next);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    printf("@@9--����ɾ��ǰ����㺯��--;\n");
    {
        printf("���Զ���L2 -- ����L2->next->next\n");
        DeletePriorNode(L2->next->next);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    printf("@@10--����ɾ��ָ����㺯��--;\n");
    {
        printf("���Զ���L2 -- ����L2->next->next\n");
        DeleteNode(&L2,L2->next->next);
        printf("��ӡ����!\n");
        PrintDLink(L2);
    }
    printf("@@11--��������˫������--;\n");
    {
        printf("���Զ���L2 -- ����L2->next->next\n");
        DestroyList(&L2);
        printf("result=%d\n",Empty(L2));
    }
}