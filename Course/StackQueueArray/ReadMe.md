

# 3.1 ջ

## 3.1.1 ջ�Ļ�������

**1.��������**
ջ( Stack����ֻ������һ�˽��в����ɾ�����������Ա�����ջ��һ�����Ա����޶��������Ա�ֻ����ĳһ�˽��в����ɾ��������

- ջ����Top)�����Ա�������в���ɾ������һ�ˡ�
- ջ��(Bottom)���̶��ģ���������в����ɾ������һ�ˡ�
- ��ջ�������κ�Ԫ�صĿձ�

ջ����ѧ����:n����ͬԪ�ؽ�ջ����ջԪ�ز�ͬ���еĸ���Ϊ
$$
\frac{1}{n+1}\complement^n _2n
$$
������ʽ��Ϊ������(Catalan������

**2.��������**
- Initstack ( &S):��ʼ��һ����ջs��
- stackEmpty(S):�ж�һ��ջ�Ƿ�Ϊ�գ���ջsΪ���򷵻�true�����򷵻�false��
- Push(&s,x):��ջ����ջsδ������x����ʹ֮��Ϊ��ջ����
- Pop(&S,&x):��ջ����ջs�ǿգ��򵯳�ջ��Ԫ�أ�����x���ء�
- GetTop(S,&x):��ջ��Ԫ�أ���ջS�ǿգ�����x����ջ��Ԫ�ء�
- Destroystack (&S):����ջ�����ͷ�ջsռ�õĴ洢�ռ�(��&����ʾ���õ���)��


## 3.1.2 ջ��˳��ṹ

### 1.ջ��ʵ��
```C
#define MaxSize 50 // ����ջ��Ԫ�ص�������
typedef struct
{
    int data[MaxSize]; // ��̬������ջ��Ԫ��
    int top; // ջ��ָ��
}SqStack;
```

### 2.ջ�Ĳ���

#### 1.��ʼ��
```C
void InitStack(SqStack *S)
{
    (*S).top = -1;
    // (*S).top = 0;
}
```
#### 2.�п�
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
#### 3.��ջ
��ջ��++
```C
bool Push(SqStack *S,int x)
{
    // if((*S).top == MaxSize)
    if((*S).top - 1 == MaxSize)
        // ջ��
        return false;
    (*S).data[++(*S).top] = x; // === S.top += 1; S.data[S.top] = x;
    // (*S).data[(*S).top++] = x;  ��ʼջ��Ϊ0ʱ
    return true;
}
```
#### 4.��ջ
��ջ��--
```C
bool Pop(SqStack *S,int *x)
{
    // if((*S).top == MaxSize)
    if((*S).top == -1) // û��Ԫ�ؿ��Թ�����
        return false;
    (*x) = (*S).data[(*S).top--]; // === x = S.data[S.top];S.top--;
    // (*x) = (*S).data[--(*S).top]; ��ʼջ��Ϊ0ʱ
    return true;
}

```
#### 5.��ȡջ��Ԫ��
```C
bool GetPop(SqStack S,int *x)
{
    if(S.top == -1) // û��Ԫ�ؿ��Թ�����
        return false;
    (*x) = S.data[S.top];
    return true;
}
```
#### 6.��ӡ
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

### 3.����ջ

����ջ��λ����Բ�������ԣ���������˳��ջ����һ��һά����ռ䣬������ջ��ջ�׷ֱ������ڹ���ռ�����ˣ�����ջ������ռ���м�����.
![3.ջ_����_����-2022-05-18-20-16-38](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.ջ_����_����-2022-05-18-20-16-38.png)

ʹ�ù���ջʱ���п�,����,��ջ�ͳ�ջ����Ҳ��һ��.
- ����ջ��ջ��ָ�붼ָ��ջ��Ԫ�أ�top0=-1ʱ0��ջΪ�գ�top1=MaxSizeʱ1��ջΪ��;
- ��������ջ��ָ������(topl-top0=1)ʱ���ж�Ϊջ����
- ��0��ջ��ջʱtop0�ȼ� 1�ٸ�ֵ��1��ջ��ջʱtop1�ȼ�1�ٸ�ֵ;��ջʱ��պ��෴��

**���в���**
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
        printf("ջ0Ϊ��\n");
        return true;
    }

    if(stackNum == 1 && S.top[stackNum] == MaxSize)
    {
        printf("ջ1Ϊ��\n");
        return true;
    }
}

bool Push(ShStack *S,ElemType x,ElemType stackNum)
{
    if((*S).top[0] - (*S).top[1] == 1) // ջ��
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
            if((*S).top[stackNum] == -1) // ջ��
                return false;
            else
            {
                (*x) = (*S).data[(*S).top[0]--];
                return true;
            }
            break;
        case 1:
            if((*S).top[stackNum] == MaxSize) // ջ��
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
    if(S.top[0] - S.top[1] == 1) // ջ��
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
    if(S.top[0] - S.top[1] == 1) // ջ��
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

## 3.1.3 ��ջ
������ʽ�洢��ջ��Ϊ��ջ����ջ���ŵ��Ǳ��ڶ��ջ����洢�ռ�������Ч�ʣ��Ҳ�����ջ������������ͨ�����õ�����ʵ�֣����涨���в��������ڵ�����ı�ͷ���еġ�����涨**��ջû��ͷ���**��Lheadָ��ջ��Ԫ��.
![3.ջ_����_����-2022-05-18-20-21-29](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.ջ_����_����-2022-05-18-20-21-29.png)

**ʵ��**
```C
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *node;
}*LinkStack;
```

### 1.��ɾ�Ĳ����
```C
bool InitStack(LinkStack *Ls)
{
    // Ĭ���ǲ�����ͷ����
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
    if(insertNode == NULL) // ����ʧ�� �͸��Ľ����NULL
        return false;
    insertNode->data = e;
    insertNode->next = (*Ls);
    (*Ls) = insertNode;
    return true;
}

bool Pop(LinkStack *Ls,ElemType *e)
{
    // ���ͷ�巨
    if((*Ls) != NULL)
    {
        LsNode *temp = (*Ls); // û��ͷ���
        (*Ls) = temp->next;
        (*e) = temp->data;
        free(temp);
    }
    else
    {
        printf("ջ��.\n");
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

# 3.2 ����

## 3.2.1 ���еĻ�������

**1.���еĶ���**

����(Queue����ƶӣ�Ҳ��һ�ֲ������޵����Ա�ֻ�����ڱ��һ�˽��в��룬���ڱ����һ�����ɾ��������в���Ԫ�س�Ϊ���ӻ����:ɾ��Ԫ�س�Ϊ���ӻ������������ճ������е��Ŷ���һ�µ�,�����Ŷӵ�Ҳ��������ӵģ���������������Ƚ��ȳ���First In First Out��FIFO)��

![3.ջ_����_����-2022-05-19-21-05-15](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.ջ_����_����-2022-05-19-21-05-15.png)

**2.���еĻ�������**
- InitQueue ( &Q):��ʼ�����У�����һ���ն���Q��
- DestroyQueue(&Q):���ٶ��С����ٲ��ͷŶ���Q��ռ�õ��ڴ�ռ䡣
- QueueEmpty(Q):�ж��пգ�������QΪ�շ���true�����򷵻�false��
- EnQueue ( &Q,x):��ӣ�������Qδ������x���룬ʹ֮��Ϊ�µĶ�β��
- DeQueue ( &Q,&x):���ӣ�������Q�ǿգ�ɾ����ͷԪ�أ�����x���ء�
- GetHead(Q,&x):����ͷԪ�أ�������Q�ǿգ��򽫶�ͷԪ�ظ�ֵ��x��

## 3.2.2 ���е�˳��洢�ṹ

### 3.2.2.1 ���еĻ�������
![3.ջ_����_����-2022-05-21-16-11-35](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.ջ_����_����-2022-05-21-16-11-35.png)
**1.��ʼ**
```C
bool InitQueue(SqQueue *Q)
{
    // ��ͷ��βָ��0
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
**2.�п�**
```C
bool QueueEmpty(SqQueue Q)
{
    if(Q.rear == Q.front) // �ӿ�
        return true;
    else
        return false;
}
```
**3.���**
```C
bool EnQueue(SqQueue *Q,ElemType x)
{
    // ���ַ�ʽʹ����һƬ�ڴ�ռ�ò���ʹ��
    // ���rear����MaxSize����ֱ�ӽ����a[0]���¿�ʼ�洢�����rear+1��front�غϣ����ʾ��������
    if(((*Q).rear+1) % MaxSize == (*Q).front)
        return false;
    (*Q).data[(*Q).rear] = x;
    (*Q).rear = ((*Q).rear+1)%MaxSize;
    return true;
}
```
**4.����**
```C
bool DeQueue(SqQueue *Q,ElemType *x)
{
    if((*Q).rear == (*Q).front) // �ӿ�
        return false;
    (*x) = (*Q).data[(*Q).front];
    (*Q).front = (*Q).front+1 % MaxSize;
    return true;
}

```
**5.��ȡͷ��**
```C
void GetHead(SqQueue Q,ElemType *x)
{
    if(Q.front == Q.rear)
        return;
    (*x) = Q.data[Q.front];
}
```
**6.����**
```C
bool Destroy(SqQueue *Q)
{
    if((*Q).front == 0 && (*Q).rear == 0)
    {
        // ��֪����һ���ն��� ֱ�ӷ���
        return true;
    }
    int index;
    for (index = (*Q).rear-1; index >= 0; index--)
    {
        (*Q).data[index] = 0; // ������ֵ��Ϊ0
    }
    (*Q).front = (*Q).rear = 0; // ָ������
    return true;
}
```

### 3.2.2.2 �任���п��ֶ�
�����ķ�ʽ�������п����������ƣ��ᵼ�����Ƕ�ʧһ���洢�ռ䣬���ǿ���ʹ��������ʽ��������ʧ��һλ�ռ䡣

#### 1.ʹ��size�����п�
- size++ ��ʾ����
- size-- ��ʾ����

```C
bool EnQueue1(SqQueue1 *Q1,ElemType x)
{
    if((*Q1).size == MaxSize)
        return false;// ջ��
    (*Q1).size++;
    (*Q1).data[(*Q1).rear] = x;
    (*Q1).rear = (*Q1).rear+1 % MaxSize;
    return true;
}

bool DeQueue1(SqQueue1 *Q1,ElemType *x)
{
    if((*Q1).size == 0)
        return false; // ��ʾջ��
    (*Q1).size--;
    (*x) = (*Q1).data[(*Q1).front];
    (*Q1).front = (*Q1).front+1 % MaxSize;
    return true;
}
```

#### 2.ʹ��tag�����п�
- tag������ʾ������е���ʲô����
    - 1����ʾ��������ɹ�
    - 0����ʾɾ�������ɹ�
- �пգ�front == rear && tag == 0
- ������front == rear && tag == 1

**1.ʵ��**
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

#### 3.�����Ŀ��Է�ʽ

![3.ջ_����_����-2022-05-21-16-14-48](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.ջ_����_����-2022-05-21-16-14-48.png)
![3.ջ_����_����-2022-05-21-16-15-13](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.ջ_����_����-2022-05-21-16-15-13.png)
![3.ջ_����_����-2022-05-21-16-15-29](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.ջ_����_����-2022-05-21-16-15-29.png)


## 3.2.3 ���е���ʽ�洢
���е���ʽ��ʾ��Ϊ�����У���ʵ������һ��ͬʱ���ж�ͷָ��Ͷ�βָ��ĵ�����ͷָ��ָ���ͷ��㣬βָ��ָ���β��㣬������������һ����㣨ע����˳��洢�Ĳ�ͬ)��

![3.ջ_����_����-2022-05-21-16-18-53](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.ջ_����_����-2022-05-21-16-18-53.png)


### 3.2.3.1 ��������

- �ֱ�ʵ���˴���ͷ�ڵ��û��ͷ���

**1.��ʼ��**
```C
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
```

**2.�п�**
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
    if(LQ.front == NULL) // ͷ��㶼Ϊ��
        return true;
    else
        return false;
}
```
**3.���**
```C
bool EnLQueue(LinkQueue *LQ,ElemType x)
{
    // ����û��������һ˵
    LinkNode *insertNode = (LinkNode *) malloc(sizeof (LinkNode));
    insertNode->data = x;
    insertNode->next = NULL;
    (*LQ).rear->next = insertNode; // ͷ��
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
        (*LQ).front = insertNode;// ͷ�� ����
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
```

**4.����**

```C
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
```

## 3.2.4 ˫�˶���

˫�˶�����ָ�������˶����Խ�����Ӻͳ��Ӳ����Ķ��С���Ԫ�ص�**�߼��ṹ**�������Խṹ�������е����˷ֱ��Ϊǰ�˺ͺ�ˣ����˶�������Ӻͳ��ӡ�

- ˫�˶���
    - ��������˲��롢����ɾ���Ķ���
- �������޵�˫�˶��� �����������ɾ������һ�˲���Ķ���
- ������޵�˫�˶�����������˲��롢��һ��ɾ���Ķ���
- **����:��������кϷ��Ե��ж�**



![3.ջ_����_����-2022-05-21-20-04-43](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.ջ_����_����-2022-05-21-20-04-43.png)
![3.ջ_����_����-2022-05-21-20-04-58](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.ջ_����_����-2022-05-21-20-04-58.png)


# 3.3 ջ�Ͷ��е�Ӧ��

## 3.3.1 ջ������ƥ���е�Ӧ��

�����һ����������
```txt
[   (   [   ]   [   ]   )   ]
1   2   3   4   5   6   7   8
```
��������:
1. ��������յ�1������"["���ڴ���֮ƥ��ĵ�8������ "]"���֡�
2. ����˵�2������"("����ʱ��1������"["��ʱ����һ�ߣ��������ڴ���֮ƥ��ĵ�7�����š�)�����֡�
3. ����˵�3������"["����ʱ��2������"("��ʱ����һ�ߣ��������ڴ���֮ƥ��ĵ�4������ "]"���֡���3�����ŵ��ڴ��õ����㣬����֮�󣬵�2�����ŵ��ڴ�ƥ���ֳ�Ϊ��ǰ��ȵ�����
4. �Դ�����,�ɼ��ô��������ջ��˼���Ǻϡ�

�㷨��˼������:
1. ��ʼ����һ����ջ��˳��������š�
2. ���������ţ������ʹ����ջ��������ڴ��������⣬�����ǲ��Ϸ���������������в�ƥ�䣬�˳�����)��
3. ���������ţ�����Ϊһ���µĸ����ȵ��ڴ�ѹ��ջ�У���Ȼʹԭ�е���ջ�е�����δ������ڴ��ļ����Խ���һ�����㷨����ʱ��ջΪ�գ������������в�ƥ�䡣

**�㷨ʵ��**
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

## 3.3.2 ջ�ڱ��ʽ��ֵ�е�Ӧ��

## 3.3.3 ջ�ڵݹ��е�Ӧ��

![3.ջ_����_����-2022-05-30-15-26-35](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.ջ_����_����-2022-05-30-15-26-35.png)

## 3.3.4 ���е�Ӧ��
- ���Ĳ�α���
- ͼ�Ĺ�����ȱ���
- ����ϵͳ�е�Ӧ��
    - �������������ʹ�����޵�ϵͳ��Դʱ��FCFs (First Come First Service�������ȷ���)��һ�ֳ��ò��ԡ�
    - ���ݻ������������ӡ����






