//
// Created by cxf18 on 2022/5/22.
//

#include "Exercises.h"

int main()
{
    setbuf(stdout,0);
    SqStack S1,S2;
    PressEnter;
    printf("@@1-�κ�ϰ��03(P85)--");
    {
        printf("��ʼ\n");
        //
        /*��Ŀ:
         * ����ջS1��S2��ģ����в���.
         * ��֪:ջ���п�/��/Pop/Push ����
         * ʵ��:���е�EnQueue/Dequeue/Empty����
         *
         * ����:
         * ��Ӳ���:���Բ��Ϊ����ջS1-->���S2Ϊ����ջ������,�����е�Ԫ�س�ջ����ջ��S2��.
         * ���Ӳ���:��S1��Ϊ����ִ�г�ջ,���������.�ڷ������S1�л���Ԫ�ؿ��Ա�Pop��S2��,�����Pop(S1),Push(S2);
         * */
        S1.top = S2.top = -1;
        ElemType e = 0;
        EnQueue(&S1,&S2,1);
        EnQueue(&S1,&S2,2);
        EnQueue(&S1,&S2,3);
        EnQueue(&S1,&S2,4);
        EnQueue(&S1,&S2,5);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        Empty(S1,S2);
    }
}

bool EnQueue(SqStack *S1,SqStack *S2,ElemType e)
{
    if(!SOverFlow(*S1)) // S1δ��ִ��
    {
        Push(S1,e);
        return true;
    }
    if(SOverFlow(*S1) && !SEmpty(*S2)) // S1����S2�ǿ�
    {
        printf("������\n");
        return false;
    }
    if(SOverFlow(*S1) && SEmpty(*S2)) // S1����S2��
    {
        while (SEmpty(*S1) != true)
        {
            Pop(S1,&e);
            Push(S2,e);
        }
    }
    Push(S1,e); // if1/if2�ж϶�δ����,if3ִ�е���S1����S2�յ������Ԫ��ȫ����ջ��ջ��S2,��Ҫ��һ�佫׼����ջ��Ԫ����ջ.
    return true;
}

bool DeQueue(SqStack *S1,SqStack *S2,ElemType *e)
{
    if(!SEmpty(*S2)) // ջS2��Ԫ�س���
    {
        Pop(S1,e);
    }
    else if(SEmpty(*S1)) // ջS1��
    {
        printf("���п�\n");
    }
    else
    {
        while(!SEmpty(*S1)) // ջS1�л���Ԫ�� -- ������½�����뵽S2�з����´�ֱ�ӳ���
        {
            Pop(S1,e);
            Push(S2,*e);
        }
    }
    Pop(S2,e);
    // if1δ����,else if���� ==>����S2������û��Ԫ�ؿ���Pop,else �ֽ�S1�е�����Ԫ�س�ջ��ջ��S2,
    // �˾��ʱִ��ʼ�ղ��ᵼ��ִ�к�û��PopԪ��.
    return true;
}

bool Empty(SqStack S1,SqStack S2)
{
    if(SEmpty(S1) && SEmpty(S2))
        return true;
    else
        return false;
}

bool SEmpty(SqStack S)
{
    if(S.top == -1)
        return true;
    else
        return false;
}
bool SOverFlow(SqStack S)
{
    if(S.top == Maxsize -1)//��
        return true;
    else
        return false;
}
bool Push(SqStack *S,ElemType e)
{
    if((*S).top == Maxsize -1)//��
        return false;
    (*S).data[++(*S).top] = e;
    return true;
}

bool Pop(SqStack *S,ElemType *e)
{
    if((*S).top == -1)//��
        return false;
    (*e) = (*S).data[(*S).top--];
    return true;
}