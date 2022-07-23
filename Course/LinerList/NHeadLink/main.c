//
// Created by cxf18 on 2022/7/5.
//
#include "NHeadLink.h"
int main()
{
    setbuf(stdout,0);
    LinkList L,L2;
    int result = 0;
    /*��ͷ������*/

    printf("������ͷ���\n");
    printf("@@1--���Գ�ʼ������@@\n");
    {
        printf("��ʼ��һ��������ͷ��㵥����L...\n");
        NHeadInitList(&L);
        NHeadInitList(&L2);
        printf("\n");
    }

    printf("@@2--�����пպ���@@\n");
    {
        printf("���Զ���ΪL\n");
        printf("���1Ϊ��...\n");
        bool isEmpty = NHeadEmpty(&L);
        printf("%d\n",isEmpty);
        printf("\n");
    }

    printf("@@3--����ͷ�巨����@@\n");
    {
        printf("����һ������!(9999��ʾ�˳�),ͷ�巨�Ƕ�L���н���\n");
        NHeadLinkHeadInsert(&L);
        printf("��ӡ����\n");
        NHeadPrintList(L);
        printf("\n");
    }

    printf("@@4--����β�巨����@@\n");
    {
        printf("����һ������!(9999��ʾ�˳�),β�巨�Ƕ�L2���н���\n");
        NHeadLinkTailInsert (&L2);
        printf("��ӡ����\n");
        NHeadPrintList(L2);
        printf("\n");
    }

    printf("@@5--����ָ��������뺯��@@\n");
    {
        printf("(����Ϊ:L,Ĭ�ϵ�1������,���ֽ������뵽3��λ��)\n");
        printf("����L->next�Ľ��:\n");
        NHeadInsertNextNode(L->next,110);
        printf("��ӡ����\n");
        NHeadPrintList(L);
        printf("\n");
        printf("����L�Ľ��:\n");
        NHeadInsertNextNode(L,111);
        printf("��ӡ����\n");
        NHeadPrintList(L);
        printf("\n");
    }

    printf("@@6--����ָ�����ǰ���뺯��@@\n");
    {
        printf("(����Ϊ:L2,Ĭ�ϵ�1�����ǰ)\n");
        printf("����L2->next�Ľ��:\n");
        NHeadInsertNextNode(L2->next,112);
        printf("��ӡ����\n");
        NHeadPrintList(L2);
        printf("\n");
        printf("����L2�Ľ��:\n");
        NHeadInsertNextNode(L2,113);
        printf("��ӡ����\n");
        NHeadPrintList(L2);
        printf("\n");
    }

    printf("@@7--���Բ������ݺ���@@\n");
    {
        printf("(����Ϊ:L2,Ĭ���ڵ�1����㴦����)\n");
        NHeadListInsert(&L2,1,114);
        printf("��ӡ����\n");
        NHeadPrintList(L2);
        printf("\n");
    }

    printf("@@8--����ɾ������(����Ϊ:L,Ĭ��ɾ����1��)@@\n");
    {
        printf("ɾ�����\n");
        NHeadListDelete(&L,2,&result);
        printf("ɾ����ֵ:%d",result);
        printf("��ӡ����\n");
        NHeadPrintList(L);
        printf("\n");
    }

    printf("@@9--����ָ�����ɾ������@@\n");
    {
        printf("(����Ϊ:L2,Ĭ��ɾ����1�����)\n");
        printf("����L2->next�Ľ��:\n");
        DeleteNode(L2->next);
        printf("��ӡ����\n");
        NHeadPrintList(L2);
        printf("\n");
        printf("����L2�Ľ��:\n");
        DeleteNode(L2);
        printf("��ӡ����\n");
        NHeadPrintList(L2);
        printf("\n");
    }

    printf("@@10--�����󳤶Ⱥ���@@\n");
    {
        printf("(����Ϊ:L)\n");
        printf("��ӡ����\n");
        printf("������:%d\n",NHeadLength(L));
        NHeadPrintList(L);
        printf("\n");
    }

    printf("@@11--���԰�λ���Һ�������@@\n");
    {
        printf("(����Ϊ:L��Ĭ�ϵ��ĸ����)\n"); //ʵ��������ǵ�5����������
        printf("��ӡ����\n");
        LNode *temp = NHeadGetElem(L,3);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        NHeadPrintList(L);
        printf("\n");
    }

    printf("@@12--���԰�ֵ���Һ�������@@\n");
    {
        printf("(����Ϊ:L2��Ĭ���ҵ���9)\n");
        printf("��ӡ����\n");
        LNode *temp = NHeadLocateElem(L2,9);
        printf("getaddress:%p,getdata:%d\n",temp->next,temp->data);
        NHeadPrintList(L2);
        printf("\n");
    }
}
