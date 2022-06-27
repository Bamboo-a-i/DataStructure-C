//
// Created by cxf18 on 2022/6/27.
//
//
// Created by cxf18 on 2022/5/22.
//

#include "Exercise.h"
bool EnQueue(SqStack *S1,SqStack *S2,ElemType e)
{
    if(!SOverFlow(*S1)) // S1未满执行
    {
        Push(S1,e);
        return true;
    }
    if(SOverFlow(*S1) && !SEmpty(*S2)) // S1满且S2非空
    {
        printf("队列满\n");
        return false;
    }
    if(SOverFlow(*S1) && SEmpty(*S2)) // S1满且S2空
    {
        while (SEmpty(*S1) != true)
        {
            Pop(S1,&e);
            Push(S2,e);
        }
    }
    Push(S1,e); // if1/if2判断都未进入,if3执行的是S1满且S2空的情况将元素全部出栈入栈到S2,需要这一句将准备入栈的元素入栈.
    return true;
}

bool DeQueue(SqStack *S1,SqStack *S2,ElemType *e)
{
    if(!SEmpty(*S2)) // 栈S2中元素出队
    {
        Pop(S1,e);
    }
    else if(SEmpty(*S1)) // 栈S1空
    {
        printf("队列空\n");
    }
    else
    {
        while(!SEmpty(*S1)) // 栈S1中还有元素 -- 将他们陆续送入到S2中方便下次直接出队
        {
            Pop(S1,e);
            Push(S2,*e);
        }
    }
    Pop(S2,e);
    // if1未进入,else if进入 ==>代表S2中现在没有元素可以Pop,else 又将S1中的所有元素出栈入栈到S2,
    // 此句此时执行始终不会导致执行后没有Pop元素.
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
    if(S.top == Maxsize -1)//满
        return true;
    else
        return false;
}

bool Push(SqStack *S,ElemType e)
{
    if((*S).top == Maxsize -1)//满
        return false;
    (*S).data[++(*S).top] = e;
    return true;
}

bool Pop(SqStack *S,ElemType *e)
{
    if((*S).top == -1)//空
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
    // 循环匹配
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
    // 查看是否完全匹配
    if(CEmpty(S1))
        return true;
    else
        return false;
}

bool TrainArrange(char *train)
{
    SqStack1 S1;
    char *p = train,*q = train,c;
    // H:硬座;S:软座
    S1.top = -1;
    while (*p)
    {
        if(*p == 'H')
        {
            PushC(&S1,*p); //将硬座入栈
            printf("%c\n",*p);
        }
        else
        {
            *(q++) = *p; // 对已经检查出来的软座进行编排 -- 此句会报内存访问的错误慎用。
            printf("%c\n",*q);
        }

        p++;
    }
    while (!CEmpty(S1))
    {
        PopC(&S1,&c);
        printf("pop e:%c\n",c);
        *(q++) = c; // 将硬座街上软座
        printf("q:%s",q);
    }
    return true;
}