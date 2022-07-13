//
// Created by cxf18 on 2022/6/27.
// 作为整体练习中共用的头文件定义位置 避免部分文件内容重复定义。
#ifndef DATASTRUCTURE_EXERCISE_H
#define DATASTRUCTURE_EXERCISE_H
#include "Status.h"

/*
 * StackQueueArray 数据结构及其函数定义
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

// 匹配括号
bool MatchKuoHao(char *str);
// Push 字符
bool PushC(SqStack1 *S1,char e);
// Pop 字符
bool PopC(SqStack1 *S1,char *e);
// 字符栈判空
bool CEmpty(SqStack1 S1);

bool TrainArrange(char *train);

/*结尾*/


/*
 * 链表部分数据结构及其函数定义
 * */
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
// LNode* 强调是一个结点;
// LinkList 强调是一个单链表;

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

/*结尾*/

#endif //DATASTRUCTURE_EXERCISE_H
