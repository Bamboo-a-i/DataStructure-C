//
// Created by cxf18 on 2022/6/27.
//
//
// Created by cxf18 on 2022/5/22.
//

#include "Exercise.h"
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

bool PushC(SqStack1 *S1,char e)
{
    if((*S1).top == Maxsize -1)
        return false;
    (*S1).data[++(*S1).top] = e;
    return true;
}

bool PopC(SqStack1 *S1,char *e)
{
    if((*S1).top == -1)
        return false;
    (*e) = (*S1).data[(*S1).top--];
    return true;
}

bool CEmpty(SqStack1 S1)
{
    if(S1.top == -1)
        return true;
    else
        return false;
}

bool MatchKuoHao(char *str)
{
    SqStack1 S1;
    S1.top = -1;
    int i = 0;
    char e;
    // ѭ��ƥ��
    while (str[i] != '\0')
    {
        switch (str[i])
        {
            case '(':
                PushC(&S1,str[i]);
                break;
            case '[':
                PushC(&S1,str[i]);
                break;
            case '{':
                PushC(&S1,str[i]);
                break;
            case ')':
                PopC(&S1,&e);
                if(e!='(')
                    return false;
                break;
            case ']':
                PopC(&S1,&e);
                if(e!='[')
                    return false;
                break;
            case '}':
                PopC(&S1,&e);
                if(e!='{')
                    return false;
                break;
        }
        i++;
    }
    // �鿴�Ƿ���ȫƥ��
    if(CEmpty(S1))
        return true;
    else
        return false;
}

bool TrainArrange(char *train)
{
    SqStack1 S1;
    char *p = train,*q = train,c;
    // H:Ӳ��;S:����
    S1.top = -1;
    while (*p)
    {
        if(*p == 'H')
        {
            PushC(&S1,*p); //��Ӳ����ջ
            printf("%c\n",*p);
        }
        else
        {
            *(q++) = *p; // ���Ѿ����������������б��� -- �˾�ᱨ�ڴ���ʵĴ������á�
            printf("%c\n",*q);
        }

        p++;
    }
    while (!CEmpty(S1))
    {
        PopC(&S1,&c);
        printf("pop e:%c\n",c);
        *(q++) = c; // ��Ӳ����������
        printf("q:%s",q);
    }
    return true;
}