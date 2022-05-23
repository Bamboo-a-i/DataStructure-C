//
// Created by cxf18 on 2022/5/23.
//

#include "Exercise.h"
#include "Status.h"

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
bool R_Print(LinkList L)
{
    LNode *temp = (L);
    if(temp->next != NULL)
    {
        temp = temp->next;
        R_Print(temp);
    }
    if(L != NULL)
        printf("address:%p,data:%d\n",temp,temp->data);
    return true;
}

LinkList Delete_MinNode(LinkList *L)
{
    LNode *pre = (*L),*p = pre->next; // ��¼ǰ���͵�ǰ�ȽϽ��
    LNode *minPre = pre,*minP = p; // ��¼��С���ǰ���ͽ��
    while (p != NULL)
    {
        if(p->data < minP->data)
        {
            minP = p; // ����С�ڵ�Ҫ�����
            minPre = pre;
        }
        pre = p; // ������Ҫ����ǰ�ƶ�
        p = p->next;
    }
    minPre->next = minP->next; // �Ͽ�����
    free(minP); // �ͷ�
    return (*L);
}

LinkList Reverse_LinkList1(LinkList *L)
{
    LNode *p,*r;
    p = (*L)->next; // ָ���һ��Ԫ��
    (*L)->next = NULL; // �׽���Ϊβ���
    while (p != NULL)
    {
        r = p->next; // ��ȡ�������
        p->next = (*L)->next; // ���뵽�׽��λ��
        (*L)->next = p; // ǰ������
        p = r; // ��ǰ�ƶ�
    }
    return (*L);
}

LinkList Reverse_LinkList2(LinkList *L)
{
    LNode *p,*r,*pre;
    p = (*L)->next; // ָ���׽��
    r = p->next; // ָ���һ�����
    p->next = NULL; // �𲽱�Ϊβ���.
    while (r !=NULL)
    {
        pre = p; // ǰ�����ڵ�ǰ���
        p = r; // ����̽�㸳ֵ����ǰ���
        r = r->next; // ��̽����ǰ�ƶ�
        p->next = pre; // ��ʼ�������������ϵ
    }
    (*L)->next  = p; // �׽ڵ�
    return (*L);
}

void Sort(LinkList *L)
{
    LNode *p,*r,*pre;
    p = (*L)->next;
    r = p->next;
    p->next = NULL; // ������(*L)��������p��ͷ���.  �γɱȽϵĵ�һ����ʼԪ��.
    p = r; // ָ����һ�����
    while (p != NULL)
    {
        r = p->next; // ����p�ͺ������Ĺ�ϵ
        pre = (*L); // �õ����бȽϵ�����
        while (pre->next != NULL && pre->next->data < p->data) // �ж�ǰ���ֵ�Ƿ�С�ں����ֵ.
            pre = pre->next; // ���С�� 1.���Խ�ֵС�Ľ�㱣������. 2.������滹����С���,���Խ�һ����ǰ�ƶ�
        p->next = pre->next; // �˴�ʱwhile������ĵ�һ�����,˵�� preҪô��������С���,Ҫô�������е��Ѿ����������(*L)����СԪ�ػ�����p;
        pre->next = p;
        p = r;
    }
}

LinkList LinkHeadInsert(LinkList *L)
{
    LNode *node;
    int e;
    (*L) = (LinkList)malloc(sizeof(LNode));//����ͷ���
    (*L)->next = NULL;
    printf("insert e:\n");
    scanf("%d",&e);
    while(e != 9999)
    {
        node = (LNode *)malloc(sizeof(LNode *));
        node->data = e;
        node->next = (*L)->next; // ������һ�����
        (*L)->next = node; // �����µĽ��
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

void PrintList(LinkList L)
{
    LNode *temp = L->next; // ��ʼ����ͷ������һ����㣬ͷ����ǲ��洢���ݵ�
    while(temp != NULL)
    {
        printf("nodeAddress:%p;nodee:%d\n",temp,temp->data);
        temp = temp->next;
    }
}