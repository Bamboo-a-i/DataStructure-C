# 2.线性表

## 2.1 线性表的定义和基本操作

### 2.1.1线性表定义

线性表是具有相同**数据类型**的**n（n >= 0）**个数据元素的**有限序列**，n为表长，n=0表示一个空表。可用L命名线性表.

$$
(a_1,a_2,a_3....,a_i,...,a_n)
$$

**逻辑特性**
- 其中
  $$ a_1 $$
  是唯一的"第一个数据元素",又称表头元素.
  $$ a_n $$
  是唯一的"最后一个元素",.

- **除第一个元素外,所有元素有且只有一个直接前驱;除最后一个元素外,所有元素有且只有一个后继.**


**特点**
- 元素个数有限.(不断增长的n不是有限的).
- 表中元素具有逻辑上的顺序性,表中的元素有其先后次序.
- 表中元素都是数据元素，每个元素都是单个元素。
- 表中元素的数据类型都相同，这意味着每个元素占有相同大小的存储空间。
- 表中元素具有抽象性，即仅讨论元素间的逻辑关系，而不考虑元素究竟表示什么内容。

### 2.1.2线性表基本操作
- InitList ( &):**初始化表**。构造一个空的线性表。（同时分配了内存空间）。
- Length (L):**求表长**。返回线性表L的长度，即L中数据元素的个数。
- LocateElem (L,e):**按值查找操作**。在表L中查找具有给定关键字值的元素。
- GetElem (L,i):**按位查找操作**。获取表L中第i个位置的元素的值。
- ListInsert (&L,i,e):**插入操作**。在表中的第i个位置上插入指定元素e。
- ListDelete(&L,i,&e):**删除操作**。删除表工中第i个位置的元素，并用e返回删除元素的值。
- PrintList(L):**输出操作**。按前后顺序输出线性表工的所有元素值。
- Empty(L):**判空操作**。若L为空表，则返回true，否则返回false。
- DestroyList(&L):**销毁操作**。销毁线性表，并释放线性表L所占用的内存空间。


## 2.2 线性表的顺序表示

### 2.2.1 顺序表的定义
线性表的顺序存储又称顺序表。它是用**一组地址连续的存储单元**依次存储线性表中的数据元素，从而使得**逻辑上相邻的两个元素在物理位置上也相邻。**第1个元素存储在线性表的起始位置,第i个元素的存储位置后面紧接着存储的是第i+1个元素，称i为元素a在线性表中的位序。因此，顺序表的特点是表中元素的**逻辑顺序与其物理顺序相同**。

#### 1.静态和动态分配顺序表

前提:顺序表此处使用采用C语言中数组数据类型实现.

```C
#include <stdio.h>
#include <stdlib.h>
#define InitSize 10
#define Maxsize 50

typedef struct
{
    int data[Maxsize];
    int length;
}Static_Sqlist;

typedef struct
{
    int *data;
    int length,maxsize;
}Dynaminc_Sqlist;

void IncreaseSize(Dynaminc_Sqlist *list,int len);
void InitList(Dynaminc_Sqlist *list);

int main()
{
    Dynaminc_Sqlist L;
    printf("%d\n",sizeof(L));
    Static_Sqlist Static_l;
    printf("%d\n",sizeof(Static_l));
    // 初始化动态数组
    InitList(&L);
    IncreaseSize(&L,10);
    printf("%d\n",sizeof(L.data));
    // 给扩展后的数组赋值
    for(int index = 0;index<L.maxsize;index++)
    {
        L.data[index] = index;
        printf("%d\n",L.data[index]);
    }
    return 0;
}
// Initial
void InitList(Dynaminc_Sqlist *list)
{
    list->data = (int *)malloc(sizeof(int)*InitSize);
    list->length = 0;
    list->maxsize = InitSize;
}
// Incease
void IncreaseSize(Dynaminc_Sqlist *list,int len)
{
    int *p= list->data; // 临时指针用来辅助分配内存空间
    list->data = (int*)malloc((list->maxsize+len)*sizeof(int));
    for(int index = 0;index<list->length;index++)
    {
        list->data[index] = p[index]; // 将数据复制到新区域
    }
    list->maxsize += len; // 顺序表长度增加
    free(p); // 释放原来的内存空间.
}

```

C 和 C++不同在于传递顺序表时的方式不同，C需要通过指针实现，C++可以通过 `&`实现。

### 2.2.2 顺序表上基本操作的实现

全部是在静态分配顺序表的基础上进行一下操作。

#### 1.插入操作

**分析**
- 在长度为n的数组中，在位置i（1<=i<=L.length）处插入一个新的元素e --> 将包含i在内的所有元素全体向后移动。
- 考虑健壮性：
    - 给的i不能大于当前L.length+1
    - 存储空间是否已满 L.length >= MaxSize

**逻辑结构**

**物理结构**

```C
void ListInit(Static_Sqlist *list)
{
    int index = 0;
    for(index = 0;index<Maxsize;index++)
    {
        list->data[index] = 0;
    }
    list->length = 0;
}

bool ListInsert(Static_Sqlist *list,int value,int fake_index)
{
    // length 长度从1开始自增,那么当输入的index出现异常是就无法正常插入元素.
    // 正常的使用应该是按顺序以此插入数据(1,2,3,4),而不是跳动插入数据(11,3,5)
    if(fake_index<1 || fake_index>list->length+1)
    {
        printf("insert target error\n");
        return false;
    }
    // 超过内存空间
    if(list->length >= Maxsize)
    {
        printf("内存空间已满\n");
        return false;
    }
    // 此处同样考虑内部是否需要等于的判断条件，是必须的。
    // 当没有等于条件时指定插入在某个位置的后一个两个元素将会相等。
    //index   fake_index
    // 0          1      101   101     101     101     101
    // 1          2      102   102     102     102     106
    // 2          3      103   103     103     103     103
    // 3          4      104   104     104     103     103
    // 4          5      105   105     104     104     104
    // 5          6            105     105     105     105
    // 在 位序位2的位置插入106 pos = 5;pos >= 2; data[5] = data[4];data[4] = data[3];data[3] = data[2];
    // 等于条件下不满足data[2] = data[1];---》data[2] = data[3];导致错误
    for(int pos = list->length;pos >= fake_index;pos--)
    {
        list->data[pos] = list->data[pos-1];
    }
    list->length++; // 自增长度
    list->data[fake_index-1] = value; //插入值
    return true;
}   
```

**时间复杂度**

- 最好情况:在表尾插入(即 i= n+1)，元素后移语句将不执行，时间复杂度为O(1).

- 平均情况:假设p<sub>i</sub> (p<sub>i</sub> = 1/(n+1))是在第i个位置上插入一个结点的概率，则在长度为n的线性表中插入一个结点时，所需移动结点的平均次数为
- 最坏情况:在表头插入(即 i= 1)，元素后移语句将执行n次，时间复杂度为O(n).

$$
\sum_{i=1}^{n+1}\ P_i(n-i+1) =\sum_{i=1}^{n+1}  \frac{1}{n+1} = \sum_{i=1}^{n+1}(n-i-1) = \frac{n(n+1)}{2} = \frac{n}{2}
$$


#### 2.删除操作

删除顺序表L中第i(1<=i<=L.length）个位置的元素，用引用变量e返回。若i的输入不合法，则返回false;否则，将被删元素赋给引用变量e，并将第i+1个元素及其后的所有元素依次往前移动一个位置,返回true。

```C
bool ListDelete(Static_Sqlist *list,int fake_index)
{
    if(fake_index < 1 || fake_index > list->length+1)
    {
        return false;
    }
    // 关于里面的条件是否需要等号的判断条件，如果没有没有等号的情况最后一个值不会被替换掉，而是一直保留在数组中。
    // 但是length-1,但length只是位序并不是索引。输出时发现不了，但是当你一下次进行操作是便会暴露导致结果错误。
    for(int pos = fake_index;pos<=list->length;pos++)
    {
        list->data[pos-1] = list->data[pos];
    }
    list->length--;
    return true;
}
```

**时间复杂度**
- 最好情况:删除表尾元素.(即i=n)，无须移动元素，时间复杂度为O(1)。
- 最坏情况:删除表头元素（即i= 1)，需移动除表头元素外的所有元素，时间复杂度为O(n)。
- 平均情况:假设p<sub>i</sub>(p<sub>i</sub>= 1/n）是删除第i个位置上结点的概率，则在长度为n的线性表中删除一个结点时，所需移动结点的平均次数为

$$
\sum_{i=1}^{n}\ P_i(n-i) =\sum_{i=1}^{n} \frac{1}{n}(n-i) = \frac{1}{n}\sum_{i=1}^{n+1}(n-i) = \frac{1}{n} \frac{n(n-1)}{2} = \frac{n-1}{2}
$$

#### 3.按值查找

```C
bool GetElem(Static_Sqlist *list,int fake_index)
{
    int temp = list->data[fake_index-1];
    printf("Find by bit:%d\n",temp);
    return true;
}

bool LocateElem(Static_Sqlist *list,int value)
{
    for(int index = 0;index<list->length;index++)
    {
        if(list->data[index] == value)
        {
            printf("Find by value:%d\n",index+1);
            return true;
        }
    }
    return false;
}

```

**按值查找时间复杂度**
- 最好情况:查找的元素就在表头，仅需比较一次，时间复杂度为O(1)。
- 最坏情况:查找的元素在表尾(或不存在）时，需要比较n次，时间复杂度为O(n)。
- 平均情况:假设p<sub>i</sub>(p<sub>i</sub> = 1/n）是查找的元素在第i(1<=i<=L.length)个位置上的概率，则在长度为n的线性表中查找值为e的元素所需比较的平均次数为

$$
\sum_{i=1}^{n}P_i \times i = \sum_{i=1}^{n}\frac{1}{n} \frac{n(n+1)}{2} = \frac{n+1}{2}
$$


## 2.3 线性表的链式表示

顺序表可以随时存取表中的任意一个元素，它的存储位置可以用一个简单直观的公式表但插入和删除操作需要移动大量元素。链式存储线性表时，**不需要使用地址连续的存储单元，即不要求逻辑上相邻的元素在物理位置上也相邻**，它通过“链”建立起数据元素之间的逻辑关系，因此插入和删除操作不需要移动元素，而**只需修改指针**，但也会**失去顺序表可随机存取的优点**。

### 2.3.1 单链表的定义

线性表的链式存储又称单链表，它是指通过一组任意的存储单元来存储线性表中的数据元素。
存放的数据信息

| data | next |
|-|-|
| 数据域| 指针域 |

```C 
// 单链表的定义
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
```


利用单链表可以解决顺序表**需要大量连续存储单元的缺点，**但单链表**附加指针域，也存在浪费存储空间的缺点**。由于单链表的元素离散地分布在存储空间中，所以单链表是非随机存取的存储结构，即不能直接找到表中某个特定的结点。查找某个特定的结点时，需要从表头开始遍历，依次查找。

通常用头指针来标识一个单链表，如单链表L，头指针为NULL时表示一个空表。**此外，为了操作上的方便，在单链表第一个结点之前附加一个结点，称为头结点。头结点的数据域可以不设任何信息，也可以记录表长等信息。**头结点的指针域指向线性表的第一个元素结点。

#### 1.有无头结点的区别

头结点和头指针的区分:不管带不带头结点，头指针都始终指向链表的第一个结点，而头结点是带头结点的链表中的第一个结点，结点内通常不存储信息。

**引入头结点后，可以带来两个优点:**
1. 由于第一个数据结点的位置被存放在头结点的指针域中，因此在链表的第一个位置上的操作和在表的其他位置上的操作一致，无须进行特殊处理。
2. 无论链表是否为空，其头指针都指向头结点的非空指针（空表中头结点的指针域为空)，因此空表和非空表的处理也就得到了统一。

### 2.3.2 单链表的操作

#### 1.初始化

![2.线性表-2022-04-27-08-37-56](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/2.线性表-2022-04-27-08-37-56.png)

```C
// 带有头结点
bool InitList(LinkList *L)
{
    (*L) = (LNode *)malloc(sizeof(LNode)); // 带有一个初始化的头结点
    (*L)->next = NULL;
    if((*L) == NULL)
    {
        return false;
    }
    return true;
}

// 不带有头结点
bool NHeadInitList(LinkList *L)
{
    (*L) = NULL; // 没有头结点的链表
    return true;
}
```

#### 2.判空操作

```C
// 带有头结点
bool Empty(LinkList *L)
{
    if((*L)->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 不带有头结点
bool NHeadEmpty(LinkList *L)
{
    return ((*L) == NULL);
}
```

#### 3.头插法和尾插法建立链表

- 采用头插法建立单链表时，读入数据的顺序与生成的链表中的元素的顺序是相反的。每个结点插入的时间为O(1)，设单链表长为n，则总时间复杂度为O(n)。
- 尾插法形成的数据和我们输入的数据顺序一致,时间复杂相同.

```C
// 带有头结点

LinkList LinkHeadInsert(LinkList *L)
{
    LNode *node;
    int e;
    (*L) = (LinkList)malloc(sizeof(LNode));//创建头结点 没有使用初始化的情况下可以直接使用.
    (*L)->next = NULL;
    printf("insert e:\n");
    scanf("%d",&e);
    while(e != 9999)
    {
        node = (LNode *)malloc(sizeof(LNode *));
        node->data = e;
        node->next = (*L)->next; // 连接上一个结点
        (*L)->next = node; // 连接新的结点
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

LinkList LinkTailInsert(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(LNode)); // 创建头结点
    LNode *node,*tail = (*L); // 尾部结点
    int e;
    printf("insert e:\n");
    scanf("%d",&e);
    while(e != 9999)
    {
        node = (LNode *)malloc(sizeof(LNode *)); //新结点分配空间
        node->data = e;
        //(*L)->next = node;
        tail->next = node;
        //循环内部自己就是尾巴，尾巴的next暂时保存自己
        //不论是使用tail或者是（*L）达到的结果都是一样的，tail和（*L）只不过是我们给到指针的一个名字而已，把一个名字给到另外一个人不代表失去名字的就会消失，也不代表他们之间的联系会消失。
        //(*L) = node; // 自己在成为尾巴
        tail = node;
        printf("insert e:\n");
        scanf("%d",&e);
    }
    tail->next = NULL; // 最后指向一定是尾结点
    return (*L);
}
```

```C
// 不带有头结点
LinkList NHeadLinkHeadInsert(LinkList *L)
{
    int e;
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999) {
        LNode *node = malloc(sizeof(LNode)); // 创建一个结点，作为首结点
        node->next = (*L); // 因为最开始的链表当中是null值，所以可以保证最后一个元素指向的始终是null
        node->data = e; // 给第一个结点赋值 -->每次首结点承担的是接受插入的数据
        (*L) = node; // (*L) --> 头指针指向新的结点
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

LinkList NHeadLinkTailInsert(LinkList *L)
{
    int e;
    LNode *tail = (*L); //外层中让尾巴指向头指针
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999) {
        LNode *node = (LNode *)malloc(sizeof(LNode)); // 声明首结点
        node->data = e;
        if((*L) == NULL) // 输入为首节点
        {
            (*L) = node; // 头指针指向了新创建的结点
            tail = (*L); // 首尾结点同体 (等同于指向了新的结点)
        }
        else
        {
            tail->next = node; // 尾结点开始移动
            tail = node;
        }
        printf("insert e:\n");
        scanf("%d",&e);
    }
    node->next = NULL;
    return (*L);
}
```

#### 4.按序号查找结点值
- 总时间复杂度为O(n)。

```C
// 带有头结点
// GetElem 可以直接被其他函数进行调用
LNode *GetElem(LinkList L,int index)
{
    if(index < 0) // 传入值不合法
    {
        return NULL;
    }
    LNode *temp;
    int j = 0;
    temp = L;
    //temp
    while(temp != NULL && j < index)
    {
        temp = temp->next;
        j++;
    }
    // index = 0 index<0 false, j(0)<index(0) false -->返回头结点
    // index = 2 index <0 false,循环j=0,1 ,返回除头结点外的第二个结点。
    return temp; // 表长内返回对应值,超过返回NULL
}

```

```C
// 不带有头结点 
LNode *NHeadGetElem(LinkList L,int index)
{

    if(index < 0)
    {
        return NULL;
    }
    LNode *temp;
    int j = 1; // 没有头结点就没有了0元素从1开始方便元素.
    temp = L;
    while(temp != NULL && j<index)
    {
        temp = temp->next;
        j++;
    }
    return temp;
}

```

#### 5.4.按值查找结点
- 总时间复杂度为O(n)。

```C
// 带有头结点
LNode *LocateElem(LinkList L,int e)
{
    LNode *temp = L->next;
    while (temp != NULL && temp->data !=e) {
        temp = temp->next;
    }
    return temp;
}
```

```C
// 不带有头结点
LNode *NHeadLocateElem(LinkList L,int e)
{
    LNode *temp = L; // 不带头结点的不同之处
    while (temp != NULL && temp->data !=e) {
        temp = temp->next;
    }
    return temp;
}
```

#### 6.插入结点操作

- 插入结点操作将值为x的新结点插入到单链表的第一个位置先检查插人俭置的合法性，然后找到待插入位置的前驱结点，即第i-1个结点，再在其后插入新结点.
- 前插算法主要的时间开销在于查找第i-1个元素,时间复杂度为O(n)。若在给定的结点后面插入新结点，则时间复杂度仅为O(1)。
- 前插操作是指在某结点的前面插入一个新结点，后插操作的定义刚好与之相反。在单链表插入算法中，通常都采用后插操作。对结点的前插操作均可转化为后插操作，前提是从单链表的头结点开始顺序查找到其前驱结点，时间复杂度为O(n)。

##### 1.带有头结点
- 下方展示的是三种插入操作.
    - 指定结点索引插入
    - 指定结点后插入
    - 指定结点前插入

```C
// 默认使用找到前驱结点后插入到其后
bool ListInsert(LinkList *L,int index,int e)
{
    // 传入非法值
    if(index < 1)
    {
        return false;
    }
    // 联合调用GetElem 和向指定后插入操作函数。
    LNode *findNode = GetElem((*L),index-1); // 找到插入结点的前驱
    return InsertNextNode(findNode,e);
}
```

```C
// 插入到指定结点前
bool InsertPriorNode(LNode *node,int e)
{
    LNode *priorNode = (LNode *)malloc(sizeof(LNode));
    if(node== NULL || priorNode == NULL)
    {
        return false;
    }
    priorNode->next = node->next; // 让新插入的结点和指定结点处于同一垂直地位
    node->next = priorNode;  // 让插入结点位于指定结点后
    priorNode->data = node->data; // 交换数据
    node->data = e;
    return true;
}
```

```C
bool InsertNextNode(LNode *node,int e)
{
    LNode *nextNode = (LNode *)malloc(sizeof(LNode));
    if(node == NULL && nextNode == NULL)
    {
        return false;
    }
    nextNode->next =node->next;
    nextNode->data = e;
    node->next = nextNode;
    return true;
}
```


##### 2.不带有头结点

```C
bool NHeadListInsert(LinkList *L,int index,int e)
{
    if(index < 1)
    {
        return false;
    }
    if(index == 1)
    {
        // 处理不带头结点的元素时插入位置为1时需要特别操作。
        LNode *node = (LNode *)malloc(sizeof(LNode)); // 新的结点
        node->data = e; // 结点赋值
        node->next = (*L); // 给链表赋予了首节点
        (*L) = node; // 改变头指针的指向
        return true;
    }

//  当插入位置不是第一个时操作一致
//  LNode *p = L;
//  int j = 1;
//  while (p && j<index-1)
//  {
//      p = p->next;
//      j++;
//  }
//  if(p == NULL) // index的值不合法
//  {
//      return false;
//  }

    LNode *findNode = NHeadGetElem((*L),index);
//    插入结点
//    LNode *s = (LNode *)malloc(sizeof(LNode));
//    s->next = p->next;
//    s->data = e;
//    p->next = s;
//    return true;
    return NHeadInsertNextNode(findNode,e);
}
```

```C
bool NHeadInsertNextNode(LNode *node,int e)
{
    LNode *nextNode = (LNode *)malloc(sizeof(LNode));
    if(node == NULL && nextNode == NULL)
    {
        return false;
    }
    nextNode->next =node->next;
    nextNode->data = e;
    node->next = nextNode;
    return true;
}
```

```C
bool NHeadInsertPriorNode(LNode *node,int e)
{
    LNode *priorNode = (LNode *)malloc(sizeof(LNode));
    if(node == NULL && priorNode == NULL)
    {
        return false;
    }
    priorNode->next = node->next; // 位于同一垂直水平位置
    node->next = priorNode; // node的next指向priorNode 
    // 上述操作交换了新结点和结点的next指向 -- 可以避免去找node的前驱结点.
    priorNode->data = node->data;
    node->data = e;
    return true;
}
```

##### 3.指定前插入结点而不是值

- 此外，可采用另一种方式将其转化为后插操作来实现，设待插入结点为 *p，将 *p插入到*node的前面。我们仍然将*p插入到*node的后面，然后将p->data与s->data交换，这样既满足了逻辑关系，又能使得时间复杂度为O(1)。

```C
// 原理和前插值道理是一样的，只不过这一次需要使用一个temp来作为中间变量来交换两个结点的数据
bool NHeadInsertPriorNode(LNode *node,LNode *p) // 在node结点前插入p
{
    if(node == NULL && p == NULL)
    {
        return false;
    }
    s->next = node->next; // 位于同一垂直水平位置
    node->next = s; // node的next指向priorNode 
    // 上述操作交换了新结点和结点的next指向 -- 可以避免去找node的前驱结点.
    int temp = node->data; // 中间变量来辅助交换值
    node->data = s->data;
    s->data = temp;
    return true;
}

```

#### 7.删除结点操作

- 算法的主要时间耗费在查找操作上，时间复杂度为O(n)。

```C
// 有头结点
bool ListDelete(LinkList *L,int index,int *e)
{
    if(index <1)
        return false;
    LNode *node;
    int j = 0;
    node = (*L);
    while (node!=NULL && j<index - 1)
    {
        node = node->next;
        j++;
    }
    if(node == NULL) // index 值不合法
        return false;
    if(node->next ==NULL) // index - 1个结点之前已无其他结点
        return  false;
    LNode *delNode = node->next; // 指向删除结点
    e = delNode->data; // 返回找到的值
    node->next = delNode->next; // 断开连接
    free(delNode); // 释放
    return true;
}
```

- 要删除某个给定结点p，通常的做法是先从链表的头结点开始顺序找到其前驱结点，然后执行删除操作，算法的时间复杂度为O(n)。其实，删除结点p的操作可用删除p的后继结点操作来实现，实质就是将其后继结点的值赋予其自身，然后删除后继结点，也能使得时间复杂度为O(1)。

```C
// 删除指定结点
bool DeleteNode(LNode *node)
{
    if(node == NULL)
    {
        return false;
    }
    LNode *temp = node->next;
    node->data = temp->data; // 与后继结点交换数据
    node->next = temp->next; // 断开结点连接.
    free(temp); // 释放
    return true;
}
```

```C
不带有头结点
bool NHeadListDelete(LinkList *L,int index,int *e)
{
    if(index < 0)
        return false;
    LNode *node;
    LNode *delNode;
    int j = 1;
    node = (*L);
    while(node != NULL && j < index -1)
    {
        node = node->next;
        j++;
    }
    if(node == NULL) // index 的值不合法
        return false;
    if(node->next == NULL) // 只有这一个结点不能进行删除操作
    {
        return false;
    }
    // 处理当要删除的是第一个结点时
    if(index == 1)
    {
        delNode = (*L);
        (*L) = node->next; // 让头指针直接指向下一个结点地址即可。
        e = (int *) delNode->data;
        free(delNode);
        return true;
    }
    // 非第一个结点。
    delNode = node->next;
    e = delNode->data;
    node->next = delNode->next;
    free(delNode);
    return true;
}
```

#### 8.求表长操作

```C
// 带有头结点
int Length(LinkList L)
{
    int len = 0;
    LNode *temp = L;
    while(temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
```

```C
// 不带有头结点
int NHeadLength(LinkList L)
{
    int len = 0;
    LNode *temp = L;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
```



### 2.3.3 双链表

- 单链表结点中只有一个指向其后继的指针，使得单链表只能从头结点依次顺序地向后遍历。要访问某个结点的前驱结点（插入、删除操作时)，只能从头开始遍历，访问后继结点的时间复杂度为O(1)，访问前驱结点的时间复杂度为O(n)。为了克服单链表的上述缺点，引入了双链表，双链表结点中有两个指针prior和 next，分别指向其前驱结点和后继结点.

- 定义双链表
```C
typedef struct DNode
{
    int data;
    struct DNode *next,*prior;
}DNode,*DLinkList;
```
#### 2.3.3.1 初始化
```C
bool InitDLinkList(DLinkList *L)
{
    (*L) = (DNode *)malloc(sizeof (DNode));
    if((*L) == NULL)
    {
        return false;
    }
    (*L)->next = NULL;
    (*L)->prior = NULL;
    return true;
}
```

#### 2.3.3.2 判空
```C
bool Empty(DLinkList L)
{
    if(L->next == NULL)
    {
        return false;
    }
    else
        return true;
}
```

#### 2.3.3.3 双链表的头插和尾插法操作

```C
DLinkList DLinkHeadInsert(DLinkList *L)
{
    DNode *dNode;
    int e;
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999)
    {
        dNode = (DNode *) malloc(sizeof (DNode));
        dNode->prior = (*L); // 新插入指针的前结点
        dNode->data = e;
        dNode->next = (*L)->next; // 指向下一个结点
        if((*L)->next != NULL) // 如果不是最后一个结点
            (*L)->next->prior = dNode; // 下一个结点的前结点指向自己
        (*L)->next = dNode; // 将结点插入
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

DLinkList DLinkTailInsert(DLinkList *L)
{
    DNode *dNode;
    DNode *tail = (*L); // 尾巴位于头指针位置
    int e;
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999)
    {
        dNode = (DNode *) malloc(sizeof (DNode));
        dNode->data = e; // 赋值e
        dNode->next = tail->next; // 新的结点next 指向尾结点指向的null
        dNode->prior = tail; // 新结点的前结点是上一个尾结点
        tail->next = dNode; // 尾节点的next是新结点
        tail = dNode; // 新结点成为尾结点
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}
```

#### 2.3.3.4 双链表的插入操作

![2.线性表-2022-05-11-21-00-28](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/2.线性表-2022-05-11-21-00-28.png)

```C
bool InsertNextDnode(DNode *dNode,DNode *insertNode)
{
    if(dNode == NULL || insertNode == NULL) // 传入结点值不合法
        return false;
    insertNode->next = dNode->next;
    if(dNode->next != NULL)
        dNode->next->prior = insertNode;
    insertNode->prior = dNode;
    dNode->next = insertNode;
    return true;
}
```

#### 2.3.3.5 双链表的删除操作

```C
bool DeleteNextNode(DNode *dNode)
{
    if(dNode == NULL)
        return false;
    DNode *temp = dNode->next; //找 dNode 的后继结点
    if(temp == NULL) // 后继为空
        return false;
    dNode->next = temp->next; // 断开删除结点与前驱结点的关系
    if(temp->next != NULL) // temp 不是最后一个结点
        temp->next->prior = dNode; // 断开删除结点与后继的关系
    free(temp); // 释放结点
    return true;
}

bool DeletePriorNode(DNode *dNode)
{
    if(dNode == NULL)
        return false;
    DNode *temp = dNode->prior; //找 dNode 的前驱结点
    if(temp == NULL) // 前驱为空
        return false;
    dNode->prior = temp->prior;
    if(temp->prior == NULL) // temp 前一个结点是头结点. 上一行语句已经做了删除,直接返回即可,此时链表没有头结点
        return false;
    temp->prior->next = dNode; // 断开前驱结点的关系
    free(temp); // 释放结点
    return true;
}

bool DeleteNode(DLinkList *L, DNode *dNode)
{
    DNode *temp = dNode;
    if(dNode == NULL || (*L) == NULL)
        return false;
    if(dNode->next == NULL && dNode->prior == NULL) // 只有一个结点
        return false;
    if(dNode->next == NULL) // 是尾结点
    {
        dNode->prior->next = temp->next;
        free(temp);
        return true;
    }
    if(dNode->prior == NULL) // 是头结点
    {
        (*L)->next = dNode->next; // (*L)->next可以保留头结点
        return true;
    }
    // 中间结点
    dNode->next->prior = dNode->prior;
    dNode->prior->next = dNode->next;
    free(dNode);
    return true;
}
```

#### 2.3.3.6 双链表的销毁操作

```C
void DestroyList(DLinkList *L)
{
    while ((*L)->next != NULL)
        DeleteNextNode((*L)); // 头结点可以得以保留到删除后结点处,不会产生不衔接
    free(L);
    L = NULL;
}
```

#### 2.3.3.7 双链表的遍历操作
- 链表不可随机存取，按位查找、按值查找操作都只能用遍历的方式实现。时间复杂度 O(n)

```C
void PrintDLink(DLinkList L)
{
    DNode *temp = L->next;
    // 向后遍历
    while (temp != NULL)
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->next;
    }
    // 向前遍历 传入的结点应该是链表末尾
/*    while (temp != NULL)
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->prior;
    }*/

        // 向前遍历 跳过头结点
/*    while (temp->prior != NULL)
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->prior;
    }*/
}
```


### 2.3.4 循环链表

#### 2.3.4.1 循环单链表
- 循环单链表和单链表的区别在于，表中最后一个结点的指针不是NULL,而改为指向头结点，从而整个链表形成一个环.
- 在循环单链表中，表尾结点*r的next域指向L，故表中没有指针域为NULL的结点，因此，循环单链表的判空条件不是头结点的指针是否为空，而是它是否等于头指针。

![2.线性表-2022-05-12-19-42-45](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/2.线性表-2022-05-12-19-42-45.png)

- 循环单链表的插入、删除算法与单链表的几乎一样，所不同的是若操作是在表尾进行，则执行的操作不同，以让单链表继续保持循环的性质。当然，正是因为循环单链表是一个“环”，因此在任何一个位置上的插入和删除操作都是等价的，无须判断是否是表尾。
- 在单链表中只能从表头结点开始往后顺序遍历整个链表，而循环单链表可以从表中的任意一个结点开始遍历整个链表。有时对单链表常做的操作是在表头和表尾进行的，此时对循环单链表不设头指针而仅设尾指针，从而使得操作效率更高。其原因是，若设的是头指针，对表尾进行操作需要O(n)的时间复杂度，而若设的是尾指针r，r->next即为头指针，对表头与表尾进行操作都只需要O(1)的时间复杂度。

##### 1.初始-判空-插入-打印
```C
bool LLinkListInit(LLinkList *L)
{
    (*L) = (LLNode*) malloc(sizeof (LLNode));
    if((*L) == NULL)
        return false;
    (*L)->next = (*L);
    return true;
}

bool Empty(LLinkList L)
{
    if(L->next == L) // 下一个结点等于头结点
        return true;
    else
        return false;
}

bool InsertNextNode(LLNode *llNode,LLNode *insertNode)
{
    if(llNode == NULL || insertNode == NULL)
        return false;
    insertNode->next = llNode->next;
    llNode->next = insertNode;
    return true;
}

bool PrintLLinkList(LLinkList L)
{
    LLNode *temp = L->next;
    while (temp != L)
    {
        printf("nodeAddress:%p;nodeE:%d\n",temp,temp->data);
        temp = temp->next;
    }
    return true;
}
```

#### 2.3.4.2 循环双链表
- 头结点prior要指向表尾结点.
- 在循环双链表工中，某结点*p为尾结点时，p->next==L
- 当循环双链表为空表时，其头结点的prior域和next域都等于L

![2.线性表-2022-05-12-19-45-17](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/2.线性表-2022-05-12-19-45-17.png)

#####  1.初始-判空-是否是表尾结点-插入-删除-遍历
```C
bool LDLinkListInit(LDLinkList * L)
{
    (*L) = (LDLNode *) malloc(sizeof(LDLNode));
    if((*L) == NULL)
        return false;
    (*L)->next = (*L);
    (*L)->prior = (*L);
    return true;
}

bool Empty(LDLinkList L)
{
    if(L->next == L)
        return true;
    else
        return false;
}

bool IsTail(LDLinkList L,LDLNode *ldlNode)
{
    if(ldlNode->next == L) //ldlNode->prior == tail; 可以用来判断一个结点是不是首结点.
        return true;
    else
        return false;
}

bool InsertNextNode(LDLNode* ldlNode,LDLNode* insertNode)
{
    if(ldlNode == NULL || insertNode == NULL)
        return false;
    insertNode->next = ldlNode->next;
    ldlNode->next->prior = ldlNode;
    insertNode->prior = ldlNode;
    ldlNode->next = insertNode;
}

bool Delete(LDLNode* ldlNode)
{
    if(ldlNode == NULL)
        return false;
    LDLNode *temp = ldlNode->next;
    ldlNode->next = temp->next;
    temp->next->prior = ldlNode;
    free(temp);
    return true;
}

void PrintLDLinkList(LDLinkList L)
{
    LDLNode *temp = L->next;
    while (temp != L) // .next == L时,表示到达了尾结点
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->next;
    }
}
```

### 2.3.5 静态链表

静态链表借助数组来描述线性表的链式存储结构，结点也有数据域data和指针域next，与前面所讲的链表中的指针不同的是，这里的指针是结点的相对地址（数组下标)，又称游标。和顺序表一样，静态链表也要预先分配一块连续的内存空间。

![2.线性表-2022-05-30-15-33-14](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/2.线性表-2022-05-30-15-33-14.png)

```C
#define MaxSize 50
typedef struct 
{
    ElemType data;
    int next;// 下一个元素的数组下标
}SLinkList[MaxSize];
```