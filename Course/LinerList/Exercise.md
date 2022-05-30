# 1-课后习题03(P85)

## 题目:
利用栈S1和S2来模拟队列操作.
已知:栈有判空/满/Pop/Push 操作
实现:队列的EnQueue/Dequeue/Empty操作

## 分析:
- 入队操作:可以拆分为先入栈S1-->如果S2为空且栈中已满,则将所有的元素出栈在入栈到S2中.
- 出队操作:若S1不为空则执行出栈,否则输出空.在否则如果S1中还有元素可以被Pop到S2中,则继续Pop(S1),Push(S2);

## 实现:
```c
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
```

# 2-课后习题01(P96)

## 题目:
-假设一个算术表达式中包含圆括号、方括号和花括号3种类型的括号,编写一个算法来判别表达式中的括号是否配对，以字符“O”作为算术表达式的结束符。

## 分析：
- 基本思想是扫描遇到的所有的括号根据遇到的类型进行入栈和出栈操作，
  - 左括号：入栈
  - 右括号：判断是否匹配在出栈
  - 判空：确定栈中的所有括号均被匹配

## 实现:
- 参数：char *
- switch 判断

```c
typedef struct
{
    char *data;
    int top;
}SqStack1;

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
```

# 3-课后习题02(P96)

## 题目
按下图所示铁道进行车厢调度（注意，两侧铁道均为单向行驶道，火车调度站有一个用于调度的“栈道”)， 火车调度站的入口处有n节硬座和软座车厢（分别用H和S表示)等待调度， 试编写算法，输出对这n节车厢进行调度的操作(即入栈或出栈操作)序列，以使所有的软座车厢都被调整到硬座车厢之前。

![3.栈_队列_数组-2022-05-27-22-07-47](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.栈_队列_数组-2022-05-27-22-07-47.png)

## 分析:
- 逐个检查所有的元素,对硬座进行入栈,等待最后的调度,检查完后车道中全部都是软座在将硬座pop出
- 