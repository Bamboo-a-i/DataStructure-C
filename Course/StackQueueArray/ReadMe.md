# 3.1 栈

## 3.1.1 栈的基本概念

**1.基本定义**
栈( Stack）是只允许在一端进行插入或删除操作的线性表。首先栈是一种线性表，但限定这种线性表只能在某一端进行插入和删除操作。

- 栈顶（Top)。线性表允许进行插入删除的那一端。
- 栈底(Bottom)。固定的，不允许进行插入和删除的另一端。
- 空栈。不含任何元素的空表。

栈的数学性质:n个不同元素进栈，出栈元素不同排列的个数为
$$
\frac{1}{n+1}\complement^n _2n
$$
上述公式称为卡特兰(Catalan）数。

**2.基本操作**
- Initstack ( &S):初始化一个空栈s。
- stackEmpty(S):判断一个栈是否为空，若栈s为空则返回true，否则返回false。
- Push(&s,x):进栈，若栈s未满，则将x加入使之成为新栈顶。
- Pop(&S,&x):出栈，若栈s非空，则弹出栈顶元素，并用x返回。
- GetTop(S,&x):读栈顶元素，若栈S非空，则用x返回栈顶元素。
- Destroystack (&S):销毁栈，并释放栈s占用的存储空间(“&”表示引用调用)。


## 3.1.2 栈的顺序结构

### 1.栈的实现
```C
#define MaxSize 50 // 定义栈中元素的最大个数
typedef struct
{
    int data[MaxSize]; // 静态数组存放栈中元素
    int top; // 栈顶指针
}SqStack;
```

### 2.栈的操作

#### 1.初始化
```C
void InitStack(SqStack *S)
{
    (*S).top = -1;
    // (*S).top = 0;
}
```
#### 2.判空
```C
bool StackEmpty(SqStack S)
{
    // if(S.top == 0)
    if(S.top == -1)
        return true;
    else
        return false;
}
```
#### 3.入栈
入栈先++
```C
bool Push(SqStack *S,int x)
{
    // if((*S).top == MaxSize)
    if((*S).top - 1 == MaxSize)
        // 栈满
        return false;
    (*S).data[++(*S).top] = x; // === S.top += 1; S.data[S.top] = x;
    // (*S).data[(*S).top++] = x;  初始栈顶为0时
    return true;
}
```
#### 4.出栈
出栈后--
```C
bool Pop(SqStack *S,int *x)
{
    // if((*S).top == MaxSize)
    if((*S).top == -1) // 没有元素可以供弹出
        return false;
    (*x) = (*S).data[(*S).top--]; // === x = S.data[S.top];S.top--;
    // (*x) = (*S).data[--(*S).top]; 初始栈顶为0时
    return true;
}

```
#### 5.获取栈顶元素
```C
bool GetPop(SqStack S,int *x)
{
    if(S.top == -1) // 没有元素可以供弹出
        return false;
    (*x) = S.data[S.top];
    return true;
}
```
#### 6.打印
```C
void PrintStack(SqStack S)
{
    if(S.top == -1)
        return;
    int count = S.top;
    while(count != -1)
    {
        printf("S.data[%d] = %d\n",count,S.data[count]);
        count--;
    }
}
```

### 3.共享栈

利用栈底位置相对不变的特性，可让两个顺序栈共享一个一维数组空间，将两个栈的栈底分别设置在共享空间的两端，两个栈顶向共享空间的中间延伸.
![3.栈_队列_数组-2022-05-18-20-16-38](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.栈_队列_数组-2022-05-18-20-16-38.png)

使用共享栈时的判空,判满,入栈和出栈操作也不一样.
- 两个栈的栈顶指针都指向栈顶元素，top0=-1时0号栈为空，top1=MaxSize时1号栈为空;
- 仅当两个栈顶指针相邻(topl-top0=1)时，判断为栈满。
- 当0号栈进栈时top0先加 1再赋值，1号栈进栈时top1先减1再赋值;出栈时则刚好相反。

**所有操作**
```C
void InitStack(ShStack *S)
{
    (*S).top[0] = -1;
    (*S).top[1] = MaxSize;
}

bool StackEmpty(ShStack S,int stackNum)
{
    if(stackNum == 0 && S.top[stackNum] == -1)
    {
        printf("栈0为空\n");
        return true;
    }

    if(stackNum == 1 && S.top[stackNum] == MaxSize)
    {
        printf("栈1为空\n");
        return true;
    }
}

bool Push(ShStack *S,ElemType x,ElemType stackNum)
{
    if((*S).top[0] - (*S).top[1] == 1) // 栈满
        return false;
    switch (stackNum) {
        case 0:
            (*S).data[++(*S).top[0]] = x;
            return true;
            break;
        case 1:
            (*S).data[--(*S).top[1]] = x;
            return true;
            break;
    }
    return true;
}

bool Pop(ShStack *S,ElemType *x,ElemType stackNum)
{
    switch (stackNum) {
        case 0:
            if((*S).top[stackNum] == -1) // 栈空
                return false;
            else
            {
                (*x) = (*S).data[(*S).top[0]--];
                return true;
            }
            break;
        case 1:
            if((*S).top[stackNum] == MaxSize) // 栈空
                return false;
            else
            {
                (*x) = (*S).data[(*S).top[1]++];
                return true;
            }
            break;
    }
    return true;
}


bool GetPop(ShStack S,int *x,int stackNum)
{
    if(S.top[0] - S.top[1] == 1) // 栈满
        return false;
    switch (stackNum) {
        case 0:
            (*x) = S.data[S.top[0]];
            break;
        case 1:
            (*x) = S.data[S.top[1]];
            break;
        default:
            return false;
    }
    return true;
}

void PrintStack(ShStack S,int stackNum)
{
    if(S.top[0] - S.top[1] == 1) // 栈满
        return ;
    int count = 0;
    switch (stackNum) {
        case 0:
            count = S.top[0];
            while(count != -1)
            {
                printf("S.data[%d] = %d\n",count,S.data[count]);
                count--;
            }
            break;
        case 1:
            count = S.top[1];
            while(count != MaxSize)
            {
                printf("S.data[%d] = %d\n",count,S.data[count]);
                count++;
            }
            break;
        default:
            return ;
    }
}
```

## 3.1.3 链栈
采用链式存储的栈称为链栈，链栈的优点是便于多个栈共享存储空间和提高其效率，且不存在栈满上溢的情况。通常采用单链表实现，并规定所有操作都是在单链表的表头进行的。这里规定**链栈没有头结点**，Lhead指向栈顶元素.
![3.栈_队列_数组-2022-05-18-20-21-29](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.栈_队列_数组-2022-05-18-20-21-29.png)

**实现**
```C
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *node;
}*LinkStack;
```

### 1.增删改查操作
```C
bool InitStack(LinkStack *Ls)
{
    // 默认是不带有头结点的
    (*Ls) = NULL;
    return true;
}

bool Empty(LinkStack *Ls)
{
    if((*Ls) == NULL)
        return true;
    else
        return false;
}

bool Push(LinkStack *Ls,ElemType e)
{
    LsNode *insertNode = (LsNode *) malloc(sizeof (LsNode));
    if(insertNode == NULL) // 分配失败 和给的结点是NULL
        return false;
    insertNode->data = e;
    insertNode->next = (*Ls);
    (*Ls) = insertNode;
    return true;
}

bool Pop(LinkStack *Ls,ElemType *e)
{
    // 类比头插法
    if((*Ls) != NULL)
    {
        LsNode *temp = (*Ls); // 没有头结点
        (*Ls) = temp->next;
        (*e) = temp->data;
        free(temp);
    }
    else
    {
        printf("栈空.\n");
    }
    return true;
}

bool GetPop(LinkStack *Ls,ElemType *e)
{
    if((*Ls) != NULL)
        (*e) = ((*Ls)->data);
    return true;
}

bool PrintLinkStack(LinkStack *Ls)
{
    if((*Ls) == NULL)
        return false;
    LsNode *temp = (*Ls);
    while(temp != NULL)
    {
        printf("address:0X%p,e:%d\n",temp,temp->data);
        temp = temp->next;
    }
    return true;
}
```

# 3.2 队列

## 3.2.1 队列的基本概念

**1.队列的定义**

队列(Queue）简称队，也是一种操作受限的线性表，只允许在表的一端进行插入，而在表的另一瑞进行删除向队列中插入元素称为进队或入队:删除元素称为出队或离队这和我们日常生活中的排队是一致的,最早排队的也是最早离队的，其操作的特性是先进先出（First In First Out，FIFO)。

![3.栈_队列_数组-2022-05-19-21-05-15](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.栈_队列_数组-2022-05-19-21-05-15.png)

**2.队列的基本操作**
- InitQueue ( &Q):初始化队列，构造一个空队列Q。
- DestroyQueue(&Q):销毁队列。销毁并释放队列Q所占用的内存空间。
- QueueEmpty(Q):判队列空，若队列Q为空返回true，否则返回false。
- EnQueue ( &Q,x):入队，若队列Q未满，将x加入，使之成为新的队尾。
- DeQueue ( &Q,&x):出队，若队列Q非空，删除队头元素，并用x返回。
- GetHead(Q,&x):读队头元素，若队列Q非空，则将队头元素赋值给x。

## 3.2.2 队列的顺序存储结构

### 3.2.2.1 队列的基本操作
![3.栈_队列_数组-2022-05-21-16-11-35](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.栈_队列_数组-2022-05-21-16-11-35.png)
**1.初始**
```C
bool InitQueue(SqQueue *Q)
{
    // 队头队尾指向0
    (*Q).rear = (*Q).front = 0;
    return true;
}
bool PrintQueue(SqQueue Q)
{
    if(Q.rear == Q.front)
        return false;
    int index;
    for (index = Q.front; index < Q.rear ; index++)
    {
        printf("Q.data[%d] = %d\n",index,Q.data[index]);
    }
    return true;
}
```
**2.判空**
```C
bool QueueEmpty(SqQueue Q)
{
    if(Q.rear == Q.front) // 队空
        return true;
    else
        return false;
}
```
**3.入队**
```C
bool EnQueue(SqQueue *Q,ElemType x)
{
    // 此种方式使得又一片内存空间得不到使用
    // 如果rear超过MaxSize，则直接将其从a[0]重新开始存储，如果rear+1和front重合，则表示数组已满
    if(((*Q).rear+1) % MaxSize == (*Q).front)
        return false;
    (*Q).data[(*Q).rear] = x;
    (*Q).rear = ((*Q).rear+1)%MaxSize;
    return true;
}
```
**4.出队**
```C
bool DeQueue(SqQueue *Q,ElemType *x)
{
    if((*Q).rear == (*Q).front) // 队空
        return false;
    (*x) = (*Q).data[(*Q).front];
    (*Q).front = (*Q).front+1 % MaxSize;
    return true;
}

```
**5.获取头部**
```C
void GetHead(SqQueue Q,ElemType *x)
{
    if(Q.front == Q.rear)
        return;
    (*x) = Q.data[Q.front];
}
```
**6.销毁**
```C
bool Destroy(SqQueue *Q)
{
    if((*Q).front == 0 && (*Q).rear == 0)
    {
        // 已知就是一个空队列 直接返回
        return true;
    }
    int index;
    for (index = (*Q).rear-1; index >= 0; index--)
    {
        (*Q).data[index] = 0; // 遍历将值置为0
    }
    (*Q).front = (*Q).rear = 0; // 指针置零
    return true;
}
```

### 3.2.2.2 变换的判空手段
上述的方式中由于判空条件的限制，会导致我们丢失一个存储空间，我们可以使用其他方式来避免损失这一位空间。

#### 1.使用size来进判空
- size++ 表示进队
- size-- 表示出队

```C
bool EnQueue1(SqQueue1 *Q1,ElemType x)
{
    if((*Q1).size == MaxSize)
        return false;// 栈满
    (*Q1).size++;
    (*Q1).data[(*Q1).rear] = x;
    (*Q1).rear = (*Q1).rear+1 % MaxSize;
    return true;
}

bool DeQueue1(SqQueue1 *Q1,ElemType *x)
{
    if((*Q1).size == 0)
        return false; // 表示栈空
    (*Q1).size--;
    (*x) = (*Q1).data[(*Q1).front];
    (*Q1).front = (*Q1).front+1 % MaxSize;
    return true;
}
```

#### 2.使用tag来进判空
- tag用来表示最近进行的是什么操作
    - 1：表示插入操作成功
    - 0：表示删除操作成功
- 判空：front == rear && tag == 0
- 判满：front == rear && tag == 1

**1.实现**
```C
bool EnQueue2(SqQueue2 *Q2,ElemType x)
{
    if((*Q2).front == (*Q2).rear && (*Q2).tag == 1)
        return false;
    (*Q2).tag = 1;
    (*Q2).data[(*Q2).rear] = x;
    (*Q2).rear = ((*Q2).rear+1) % MaxSize;
    return true;
}

bool DeQueue2(SqQueue2 *Q2,ElemType *x)
{
    if((*Q2).front == (*Q2).rear && (*Q2).tag == 0)
        return false;
    (*Q2).tag = 0;
    (*x) = (*Q2).data[(*Q2).front];
    (*Q2).front = ((*Q2).front+1) % MaxSize;
    return true;
}
```

#### 3.其他的考试方式

![3.栈_队列_数组-2022-05-21-16-14-48](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.栈_队列_数组-2022-05-21-16-14-48.png)
![3.栈_队列_数组-2022-05-21-16-15-13](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.栈_队列_数组-2022-05-21-16-15-13.png)
![3.栈_队列_数组-2022-05-21-16-15-29](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.栈_队列_数组-2022-05-21-16-15-29.png)


## 3.2.3 队列的链式存储
队列的链式表示称为链队列，它实际上是一个同时带有队头指针和队尾指针的单链表。头指针指向队头结点，尾指针指向队尾结点，即单链表的最后一个结点（注意与顺序存储的不同)。

![3.栈_队列_数组-2022-05-21-16-18-53](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.栈_队列_数组-2022-05-21-16-18-53.png)


### 3.2.3.1 基本操作

- 分别实现了带有头节点和没有头结点

**1.初始化**
```C
bool InitLQueue(LinkQueue *LQ)
{
    LinkNode *p = (LinkNode *) malloc(sizeof (LinkNode));
    if(p ==  NULL)
        return false;
    (*LQ).front = (*LQ).rear = p; // 指向同一块内存地址
    (*LQ).front->next = NULL; // 初始化为NULL
    return true;
}

bool InitNHLQueue(LinkQueue *LQ)
{
    (*LQ).front = (*LQ).rear = NULL;
    return true;
}
```

**2.判空**
```C
bool EmptyLQueue(LinkQueue LQ)
{
    if(LQ.rear == LQ.front)
        return true;
    else
        return false;
}

bool EmptyNHLQueue(LinkQueue LQ)
{
    if(LQ.front == NULL) // 头结点都为空
        return true;
    else
        return false;
}
```
**3.入队**
```C
bool EnLQueue(LinkQueue *LQ,ElemType x)
{
    // 链表没有满队这一说
    LinkNode *insertNode = (LinkNode *) malloc(sizeof (LinkNode));
    insertNode->data = x;
    insertNode->next = NULL;
    (*LQ).rear->next = insertNode; // 头插
    (*LQ).rear = insertNode; // 尾随
    return true;
}

bool EnNHLQueue(LinkQueue *LQ,ElemType x)
{
    LinkNode *insertNode = (LinkNode *) malloc(sizeof (LinkNode));
    insertNode->data = x;
    insertNode->next = NULL;
    if((*LQ).front ==  NULL) // 第一个结点
    {
        (*LQ).front = insertNode;// 头插 队首
        (*LQ).rear = insertNode;// 尾随
        return true;
    }
    else
    {
        (*LQ).rear->next = insertNode; // 只需要移动队尾即可。
        (*LQ).rear = insertNode;
        return true;
    }
}
```

**4.出队**

```C
bool DeLQueue(LinkQueue *LQ,ElemType *x)
{
    if((*LQ).front == (*LQ).rear)
        return false; // 队空 -- 队首等于了队尾
    LinkNode *deNode = (*LQ).front->next;
    (*x) = deNode->data;
    (*LQ).front->next = deNode->next; // 断开连接
    if((*LQ).rear == deNode) // 删除的是最后一个结点时
        (*LQ).rear = (*LQ).front;
    free(deNode);
    return true;
}

bool DeNHLQueue(LinkQueue *LQ,ElemType *x)
{
    if((*LQ).front == NULL)
        return false; // 队空 -- 队首等于了队尾
    LinkNode *deNode = (*LQ).front;
    (*x) = deNode->data;
    (*LQ).front = deNode->next; // 断开连接
    if((*LQ).rear == deNode) // 删除的是最后一个结点时
    {
        (*LQ).rear = NULL;
        (*LQ).front = NULL;
    }
    free(deNode);
    return true;
}
```

## 3.2.4 双端队列

双端队列是指允许两端都可以进行入队和出队操作的队列。其元素的**逻辑结构**仍是线性结构。将队列的两端分别称为前端和后端，两端都可以入队和出队。

- 双端队列
    - 允许从两端插入、两端删除的队列
- 输入受限的双端队列 ：允许从两端删除、从一端插入的队列
- 输出受限的双端队列允许从两端插入、从一端删除的队列
- **考点:对输出序列合法性的判断**



![3.栈_队列_数组-2022-05-21-20-04-43](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.栈_队列_数组-2022-05-21-20-04-43.png)
![3.栈_队列_数组-2022-05-21-20-04-58](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.栈_队列_数组-2022-05-21-20-04-58.png)


# 3.3 栈和队列的应用

## 3.3.1 栈在括号匹配中的应用

有如此一个括号序列
```txt
[   (   [   ]   [   ]   )   ]
1   2   3   4   5   6   7   8
```
分析如下:
1. 计算机接收第1个括号"["后，期待与之匹配的第8个括号 "]"出现。
2. 获得了第2个括号"("，此时第1个括号"["暂时放在一边，而急迫期待与之匹配的第7个括号“)”出现。
3. 获得了第3个括号"["，此时第2个括号"("暂时放在一边，而急迫期待与之匹配的第4个括号 "]"出现。第3个括号的期待得到满足，消解之后，第2个括号的期待匹配又成为当前最急迫的任务。
4. 以此类推,可见该处理过程与栈的思想吻合。

算法的思想如下:
1. 初始设置一个空栈，顺序读入括号。
2. 若是右括号，则或者使置于栈顶的最急迫期待得以消解，或者是不合法的情况（括号序列不匹配，退出程序)。
3. 若是左括号，则作为一个新的更急迫的期待压入栈中，自然使原有的在栈中的所有未消解的期待的急迫性降了一级。算法结束时，栈为空，否则括号序列不匹配。

**算法实现**
```C
typedef struct
{
    char *data;
    int top;
}SqStack1;

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
```

## 3.3.2 栈在表达式求值中的应用

## 3.3.3 栈在递归中的应用

![3.栈_队列_数组-2022-05-30-15-26-35](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.栈_队列_数组-2022-05-30-15-26-35.png)

## 3.3.4 队列的应用
- 树的层次遍历
- 图的广度优先遍历
- 操作系统中的应用
    - 多个进程争抢着使用有限的系统资源时，FCFs (First Come First Service，先来先服务)是一种常用策略。
    - 数据缓冲区，例如打印机。






