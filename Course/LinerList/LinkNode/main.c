//
// Created by cxf18 on 2022/7/5.
//
#include "LinkNode.h"

int main()
{
    setbuf(stdout,0);
    LinkList L,L2;
    int result = 0;
    //LNode *result;
    // ��ͷ������
    printf("����ͷ���Ĳ���\n");
    printf("@@1--���Գ�ʼ������@@\n");
    {
        printf("��ʼ��һ��������L...\n");
        InitList(&L);
        InitList(&L2);
        printf("\n");
    }

    printf("@@2--�����пպ���@@\n");
    {
        printf("���Զ���ΪL\n");
        printf("���1Ϊ��...\n");
        bool isEmpty = Empty(&L);
        printf("%d\n",isEmpty);
        printf("\n");
    }

    printf("@@3--����ͷ�巨����@@\n");
    {
        printf("����һ������!(9999��ʾ�˳�),ͷ�巨�Ƕ�L���н���\n");
        LinkHeadInsert(&L);
        printf("��ӡ����\n");
        PrintList(L);
        printf("\n");
    }

    printf("@@4--����β�巨����@@\n");
    {
        printf("����һ������!(9999��ʾ�˳�),β�巨�Ƕ�L2���н���\n");
        LinkTailInsert (&L2);
        printf("��ӡ����\n");
        PrintList(L2);
        printf("\n");
    }

    printf("@@5--����ָ��������뺯��@@\n");
    {
        printf("(����Ϊ:L,Ĭ�ϵ�1������),e:00\n");
        InsertNextNode(L->next,00);
        printf("��ӡ����\n");
        PrintList(L);
        printf("\n");
    }

    printf("@@6--����ָ�����ǰ���뺯��@@\n");
    {
        printf("(����Ϊ:L2,Ĭ�ϵ�1�����ǰ),e:11\n");
        InsertPriorNode(L2->next,11);
        printf("��ӡ����\n");
        PrintList(L2);
        printf("\n");
    }

    printf("@@7--���Բ������ݺ���@@\n");
    {
        printf("(����Ϊ:L2,Ĭ���ڵ�3����㴦����,e:10)\n");
        ListInsert(L2,3,10);
        printf("��ӡ����\n");
        PrintList(L2);
        printf("\n");
    }

    printf("@@8--����ɾ������(����Ϊ:L,Ĭ��ɾ����2��)@@\n");
    {
        printf("ɾ�����\n");

        ListDelete(&L,2,&result);
        printf("��ӡ����\n");
        PrintList(L);
        printf("\n");
    }

    printf("@@9--����ָ�����ɾ������@@\n");
    {
        printf("(����Ϊ:L2,Ĭ��ɾ����1�����)\n");
        DeleteNode(L2->next);
        printf("��ӡ����\n");
        PrintList(L2);
        printf("\n");
    }

    printf("@@10--�����󳤶Ⱥ���@@\n");
    {
        printf("(����Ϊ:L)\n");
        printf("��ӡ����\n");
        printf("������:%d\n",Length(L));
        PrintList(L);
        printf("\n");
    }

    printf("@@11--���԰�λ���Һ�������@@\n");
    {
        printf("(����Ϊ:L��Ĭ�ϵ��ĸ����)\n");
        printf("��ӡ����\n");
        LNode *temp = GetElem(L,4);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        PrintList(L);
        printf("\n");
    }

    printf("@@12--���԰�ֵ���Һ�������@@\n");
    {
        printf("(����Ϊ:L2��Ĭ���ҵ���9)\n");
        printf("��ӡ����\n");
        LNode *temp = LocateElem(L,9);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        PrintList(L);
        printf("\n");
    }
}
