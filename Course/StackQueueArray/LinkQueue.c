//
// Created by cxf18 on 2022/5/21.
//

#include "LinkQueue.h"
int main()
{
    setbuf(stdout,0);
    LinkQueue LQ;
    LinkQueue LQ1;
    PressEnterToContinue(false);
    printf("@@1--���ӵĳ�ʼ��--\n");
    {
        printf("��ʼ\n");
        printf("����ͷ���\n");
        InitLQueue(&LQ);
        printf("������ͷ���\n");
        InitNHLQueue(&LQ1);
    }
    PressEnterToContinue(false);
    printf("@@2--�����п�--\n");
    {

        printf("��ʼ\n");
        printf("����ͷ���\n");
        printf("res:%d\n",EmptyLQueue(LQ));
        printf("������ͷ���\n");
        printf("res:%d\n",EmptyNHLQueue(LQ1));
    }
    PressEnterToContinue(false);
    printf("@@3--���--\n");
    {
        printf("��ʼ\n");
        printf("����ͷ���\n");
        EnLQueue(&LQ,1);
        EnLQueue(&LQ,2);
        EnLQueue(&LQ,3);
        EnLQueue(&LQ,4);
        printf("������ͷ���\n");
        EnNHLQueue(&LQ1,5);
        EnNHLQueue(&LQ1,6);
        EnNHLQueue(&LQ1,7);
        EnNHLQueue(&LQ1,8);
    }
    PressEnterToContinue(false);
    printf("@@4--����--\n");
    {
        ElemType x = 0;
        printf("��ʼ\n");
        printf("����ͷ���\n");
        DeLQueue(&LQ,&x);
        printf("deQueue:%d\n",x);
        DeLQueue(&LQ,&x);
        printf("deQueue:%d\n",x);
        DeLQueue(&LQ,&x);
        printf("deQueue:%d\n",x);
        DeLQueue(&LQ,&x);
        printf("deQueue:%d\n",x);

        printf("������ͷ���\n");
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

bool InitLQueue(LinkQueue *LQ)
{
    LinkNode *p = (LinkNode *) malloc(sizeof (LinkNode));
    if(p ==  NULL)
        return false;
    (*LQ).front = (*LQ).rear = p; // ָ��ͬһ���ڴ��ַ
    (*LQ).front->next = NULL; // ��ʼ��ΪNULL
    return true;
}

bool InitNHLQueue(LinkQueue *LQ)
{
    (*LQ).front = (*LQ).rear = NULL;
    return true;
}

bool EmptyLQueue(LinkQueue LQ)
{
    if(LQ.rear == LQ.front)
        return true;
    else
        return false;
}

bool EmptyNHLQueue(LinkQueue LQ)
{
    if(LQ.front == NULL) // ͷ��㶼Ϊ��
        return true;
    else
        return false;
}

bool EnLQueue(LinkQueue *LQ,ElemType x)
{
    // ����û��������һ˵
    LinkNode *insertNode = (LinkNode *) malloc(sizeof (LinkNode));
    insertNode->data = x;
    insertNode->next = NULL;
    (*LQ).rear->next = insertNode; // β��
    (*LQ).rear = insertNode; // β��
    return true;
}

bool EnNHLQueue(LinkQueue *LQ,ElemType x)
{
    LinkNode *insertNode = (LinkNode *) malloc(sizeof (LinkNode));
    insertNode->data = x;
    insertNode->next = NULL;
    if((*LQ).front ==  NULL) // ��һ�����
    {
        (*LQ).front = insertNode;// β�� ����
        (*LQ).rear = insertNode;// β��
        return true;
    }
    else
    {
        (*LQ).rear->next = insertNode; // ֻ��Ҫ�ƶ���β���ɡ�
        (*LQ).rear = insertNode;
        return true;
    }
}

bool DeLQueue(LinkQueue *LQ,ElemType *x)
{
    if((*LQ).front == (*LQ).rear)
        return false; // �ӿ� -- ���׵����˶�β
    LinkNode *deNode = (*LQ).front->next;
    (*x) = deNode->data;
    (*LQ).front->next = deNode->next; // �Ͽ�����
    if((*LQ).rear == deNode) // ɾ���������һ�����ʱ
        (*LQ).rear = (*LQ).front;
    free(deNode);
    return true;
}

bool DeNHLQueue(LinkQueue *LQ,ElemType *x)
{
    if((*LQ).front == NULL)
        return false; // �ӿ� -- ���׵����˶�β
    LinkNode *deNode = (*LQ).front;
    (*x) = deNode->data;
    (*LQ).front = deNode->next; // �Ͽ�����
    if((*LQ).rear == deNode) // ɾ���������һ�����ʱ
    {
        (*LQ).rear = NULL;
        (*LQ).front = NULL;
    }
    free(deNode);
    return true;
}