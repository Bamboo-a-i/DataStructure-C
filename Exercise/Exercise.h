//
// Created by cxf18 on 2022/6/27.
// ��Ϊ������ϰ�й��õ�ͷ�ļ�����λ�� ���ⲿ���ļ������ظ����塣
#ifndef DATASTRUCTURE_EXERCISE_H
#define DATASTRUCTURE_EXERCISE_H
#include "Status.h"

/*
 * StackQueueArray ���ݽṹ���亯������
 * */
typedef struct
{
    ElemType data[Maxsize];
    int top;
}SqStack;

typedef struct
{
    char *data;
    int top;
}SqStack1;

bool EnQueue(SqStack *S1,SqStack *S2,ElemType e);

bool DeQueue(SqStack *S1,SqStack *S2,ElemType *e);

bool Empty(SqStack S1,SqStack S2);

bool SEmpty(SqStack S);

bool SOverFlow(SqStack S);

bool Push(SqStack *S,ElemType e);

bool Pop(SqStack *S,ElemType *e);

// ƥ������
bool MatchKuoHao(char *str);
// Push �ַ�
bool PushC(SqStack1 *S1,char e);
// Pop �ַ�
bool PopC(SqStack1 *S1,char *e);
// �ַ�ջ�п�
bool CEmpty(SqStack1 S1);

bool TrainArrange(char *train);

/*��β*/


/*
 * ���������ݽṹ���亯������
 * */
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
// LNode* ǿ����һ�����;
// LinkList ǿ����һ��������;

bool InitList(LinkList *L);

bool LinkListEmpty(LinkList *L);

LinkList LinkHeadInsert(LinkList *L);

LinkList LinkTailInsert(LinkList *L);

bool R_Print(LinkList L);

LinkList Delete_MinNode(LinkList *L);

LinkList Reverse_LinkList1(LinkList *L);

LinkList Reverse_LinkList2(LinkList *L);

void Sort(LinkList *L);

void PrintList(LinkList L);

/*��β*/

#endif //DATASTRUCTURE_EXERCISE_H
