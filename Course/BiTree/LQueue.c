//
// Created by cxf18 on 2022/6/9.
//

#include "LQueue.h"

/*
 * ��ʼ��
 *
 * ����:LinkQueue
 *
 * ����:bool
 * */
bool InitQueue(LinkQueue *LQ)
{
    LinkNode *p = (LinkNode *) malloc(sizeof (LinkNode));
    if(p == NULL)
        return false;
    (*LQ).front = (*LQ).rear = p;
    (*LQ).front->next = NULL;
    return true;
}
/*
 * �п�
 *
 * ����:LinkQueue
 *
 * ����:bool
 * */
bool EmptyQueue(LinkQueue LQ)
{
    // �п����������仯 ��Ҫ�ж�front ��rear ָ��Ľ���ֵ�Ƿ�ΪNULL
    if(LQ.front ==  LQ.rear && LQ.front->next == NULL && LQ.rear->next == NULL)
        return true;
    else
        return false;
}

/*
 * ���
 *
 * ����:LinkQueue
 *
 * ����:bool
 * */
bool EnQueue(LinkQueue *LQ,BitTree *bitTree)
{
    LinkNode *insertNode = (LinkNode *) malloc(sizeof (LinkNode));
    insertNode->data = *bitTree;
    insertNode->next = NULL;
    (*LQ).rear->next = insertNode; // β��
    (*LQ).rear = insertNode; // β��
    return true;
}

/*
 * ����
 *
 * ����:LinkQueue �洢���������,bitNode���ֵ
 *
 * ����:bool
 * */
bool DeQueue(LinkQueue *LQ,BitTree *bitTree)
{
    if((*LQ).rear == (*LQ).front)
        return false;
    LinkNode *deNode = (*LQ).front->next; // �˴�ѡ��next����Ϊfront ��û�д洢���ݣ��������Ϊһ�ֲ���ȫ��ͷ��㡣
    *bitTree = deNode->data; // ��ȡ����
    (*LQ).front->next = deNode->next;
    if(*bitTree == (*LQ).rear->data)
    {
        (*LQ).rear = (*LQ).front; // ����βָ��ָ��������ַ.
    }
    free(deNode);
    return true;
}
