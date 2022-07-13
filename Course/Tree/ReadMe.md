# 5 二叉树和树

## 5.1 二叉树存储结构
**1.顺序存储**
```c
/*
 * 链式存储
 * */
struct  ElemTypeBit
{
    int value;
};

typedef struct BitNode
{
//    struct ElemTypeBit data; // 值 一种写法
    ElemTypeChar data;
    struct BitNode *lChild,*rChild; // 左右孩子
    //struct BitNode *Parent; // 父节点
}BitNode,*BitTree;

/*
 *
 * 顺序存储的二叉树结构体
 * */

struct TreeNode
{
    ElemType value;
    bool isEmpty; // 结点是否为空
};

```

## 5.2 基本操作

### 5.2.1 顺序
**1.基础操作**
```c
printf("@@1--顺序存储二叉树\n");
{
    struct TreeNode T[Maxsize]; // 创建一个二叉树结构数组
    printf("%d\n", InitTreeNode(T));
    // 存储数据
    T[1].value = 10;
    T[5].value = 11;
    T[6].value = 12;
    T[4].value = 13;
    T[3].value = 14;
    printf("%d,%d,%d,%d,%d\n",T[1].value,T[5].value,T[6].value,T[4].value,T[3].value);
}

bool InitTreeNode(struct TreeNode *T)
{
    // 可以从0开始或者1开始,从1开始利于使用
    for (int i = 0; i < Maxsize; i++)
    {
        T[i].isEmpty = true;
    }
    return true;
}
```

### 5.2.2 链式
#### 1.基础操作
```c
/*
 * 初始化二叉树
 * */
bool InitBitTree(BitTree *root)
{
    (*root) = (BitTree) malloc(sizeof (BitNode));
    if((*root) == NULL)
        return false;
    (*root)->data = 1;
    (*root)->lChild = NULL;
    (*root)->rChild = NULL;
    return true;
}

/*
 * 目的:打印根结点的值和地址
 * */
void Visit(BitTree T)
{
    if(T != NULL)
        printf("address:%p,data:%c\n",T,T->data);
}

/*
 * 创建二叉树的文件输入入口的入口函数
 * */
bool CreatBiTreeEn(BitTree *T,ElemTypeChar *path)
{
    FILE *fp;
    fp = fopen(path,"r"); // 打开文件
    if(fp == NULL)
        return false;
    CreatTree(T,fp);
    fclose(fp); // 关闭文件
    return true;
}

/*
 * 创建二叉树 一个static方法
 * */
static void CreatTree(BitTree *T,FILE *fp)
{
    ElemTypeChar data = ' ';
    if(fp == NULL)
        return;
    else
        fscanf(fp,"%c",&data);
    if(data == '^') // 表示置孩子为null 借此来一层一层的跳出递归
        *T= NULL;
    else
    {
        (*T) = (BitTree) malloc(sizeof (BitNode));
        (*T)->data = data;
        CreatTree(&((*T)->lChild),fp);
        CreatTree(&((*T)->rChild),fp);
    }
}
/*
 * 二叉树判空
 * */
bool Empty(BitTree T)
{
    return T == NULL ? true:false;
}
/*
 * 计算二叉树深度 -- 采用递归实现
 * */
int BitTreeDepth(BitTree T)
{
    int ld,rd; // 左右深度
    if(T == NULL) // 递归出口
        return 0;
    else
    {
        ld = BitTreeDepth(T->lChild);
        rd = BitTreeDepth(T->rChild);
        return (ld >= rd ? ld : rd)+1;
    }
}
/*
 * 返回值e对应的结点,方法的目的：我们知道一个结点的值，在去求他的结点，而已知结点在获取值是没有意义的。
 * */
BitTree BackBitTreeNode(BitTree T,ElemTypeChar e)
{
    BitTree lt,rt;
    if(T == NULL)
        return NULL ;

    // 如果找到目标分支
    if(T->data == e)
        return T;

    // 左树中查找
    lt = BackBitTreeNode(T->lChild,e);
    if(lt != NULL)
        return lt;

    // 右树中查找
    rt = BackBitTreeNode(T->rChild,e);
    if(rt != NULL)
        return rt;
    return NULL;
}
/*
 * 返回值e对应的结点,方法的目的：我们知道一个结点的值,去找到他的双亲结点
 * 改进意见:设置为static
 * */
BitTree BackBitParentNode(BitTree T,ElemTypeChar e)
{
    BitTree lt,rt;
    if(T == NULL || T->data == e)
        return NULL;
    // 左孩子
    if(T->rChild != NULL && T->lChild->data == e)
        return T;
    // 右孩子
    if(T->rChild != NULL && T->rChild->data == e)
        return T;
    lt = BackBitParentNode(T->lChild,e);
    if(lt != NULL)
        return lt;
    rt = BackBitParentNode(T->rChild,e);
    if(rt != NULL)
        return rt;
    return NULL;
}
```

## 5.3 树的遍历
要求能够手算遍历结构
- 前序:根左右
- 中序:左根右
- 后序:左右根

### 5.3.1 递归方式实现

```C
/*
 * 二叉树的前中后遍历
 * */
void PreOrder(BitTree T)
{
    if(T != NULL)
    {
        Visit(T);
        PreOrder(T->lChild);
        PreOrder(T->rChild);
    }
}
void InOrder(BitTree T)
{
    if(T != NULL)
    {
        InOrder(T->lChild);
        Visit(T);
        InOrder(T->rChild);
    }
}
void PostOrder(BitTree T)
{
    if(T != NULL)
    {
        PostOrder(T->lChild);
        PostOrder(T->rChild);
        Visit(T);
    }
}
```

### 5.3.2 非递归方式前序实现遍历

**算法实现**
1. 沿着根的左孩子，依次入栈，直到左孩子为空，说明已找到可以输出的结点，此时栈内元素依次为ABD。
2. 栈顶元素出栈并访问:若其右孩子为空，继续执行2;
3. 若其右孩子不空，将右子树转执行1。

```C
void StackPreOrder(BitTree T)
{
    BitTreeStack ST;
    InitBitStack(&ST);
    BitTree p = T;
    while (p || !EmptyStackTree(ST))
    {
        if(p)
        {
            Visit(p);
            Push(&ST,&p);
            p = p->lChild; // 若此时拿到的是D,那么他的左孩子为NULL
        }
        else
        {
            Pop(&ST,&p);
            p = p->rChild;
        }
    }
}
```

### 5.3.3 非递归方式中序实现遍历

**算法实现**
1. 中序和前序只是换了Visit()的位置。

```C
void StackInOrder(BitTree T)
{
    BitTreeStack ST;
    InitBitStack(&ST);
    BitTree p = T;
    while (p || !EmptyStackTree(ST))
    {
        if(p)
        {
            Push(&ST,&p); // 结点入栈
            p = p->lChild; // 指向下一个
        }
        else
        {
            Pop(&ST,&p);
            Visit(p);
            p = p->rChild; // 开始右孩子
        }
    }
}
```

### 5.3.4 非递归方式后序实现遍历

**算法实现**
1. 沿着根的左孩子，依次入栈，直到左孩子为空。此时栈内元素依次为ABD。
2. 读栈顶元素:若其右孩子不空且未被访问过，将右子树转执行1;
3. 否则，栈顶元素出栈并访问。

```C
void StackPostOrder(BitTree T)
{
    BitTreeStack ST;
    InitBitStack(&ST);
    BitTree  p = T,r = NULL; // r 作为记录结点
    while (p || !EmptyStackTree(ST))
    {
        if(p)
        {
            // 左边元素
            Push(&ST,&p);
            p = p->lChild;
        }
        else
        {
            // 右边元素
            GetTop(&ST,&p);//获取栈顶元素
            if(p->rChild && p->rChild !=r) //若右子树存在，且未被访问过
            {
                p = p->rChild;
            }
            else
            {
                Pop(&ST,&p);
                Visit(p);
                r = p; //记录最近访问的结点
                p = NULL; //结点访问结束
            }
        }
    }
}
```

### 5.3.5 辅助函数和数据结构

```C

// 定义二叉树栈
typedef struct BitStack
{
    BitNode *data;
    struct BitStack *next;
}BitStack,*BitTreeStack;

/*
 * 初始化二叉树栈
 *
 * 参数：BitTreeStack *T
 *
 * */
bool InitBitStack(BitTreeStack *T)
{
    (*T) == NULL;
    return true;
}

/*
 * 存=入栈
 *
 * 参数：BitTreeStack *T
 *
 * */
bool Push(BitTreeStack *T,BitTree *e)
{
    // 类别尾插法
    BitStack *p = (BitStack *) malloc(sizeof (BitStack));
    if(p == NULL)
        return false;
    p->data = (*e);
    p->next = (*T);
    (*T) = p;
    return true;
}

/*
 * 出栈
 *
 * 参数：BitTreeStack *T BitNode *e
 *
 * */
bool Pop(BitTreeStack *T,BitTree *e)
{
    if((*T) == NULL)
        return false;
    else
    {
        BitStack *temp = (*T);
        (*T) = temp->next;
        (*e) = temp->data;
        free(temp);
    }
    return true;
}

/*
 * 获取栈顶元素
 *
 * 参数：BitTreeStack *T  BitNode *e
 *
 * */
bool GetTop(BitTreeStack *T,BitTree *e)
{
    if((*T) == NULL)
        return false;
    else
        (*e) = (*T)->data;
    return true;
}
/*
 * 判空
 *
 * 参数：BitTreeStack *T
 *
 * */
bool EmptyStackTree(BitTreeStack T)
{
    return (T == NULL)?true:false;
}
```

### 5.3.6 层序遍历
算法思想:
1. 初始化一个辅助队列
2. 根结点入队
3. 若队列非空，则队头结点出队，访问该结点，并将其左、右孩子插入队尾（如果有的话)
4. 重复3.直至队列为空


**代码实现**
```c
/*
 * 层序 -- 使用队列来输出结点
 *
 * 参数:BitTree
 *
 * 返回:void
 * */
void LevelOrder(BitTree T)
{
    LinkQueue LQ;
    InitQueue(&LQ);
    BitTree bitTree;
    EnQueue(&LQ,&T); // 根结点入队
    while (!EmptyQueue(LQ))
    {
        DeQueue(&LQ,&bitTree); // 出队
        Visit(bitTree); // 访问结点
        if(bitTree->rChild != NULL)
            EnQueue(&LQ,&bitTree->lChild);
        if(bitTree->lChild != NULL)
            EnQueue(&LQ,&bitTree->rChild);
    }
}
```

**LinkQueue**
- 和链式队列有所不同
```c
/*
 * 初始化
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
 * 判空
 * */
bool EmptyQueue(LinkQueue LQ)
{
// 判空条件有所变化 需要判断front 和rear 指向的结点的值是否为NULL
    if(LQ.front ==  LQ.rear && LQ.front->next == NULL && LQ.rear->next == NULL)
        return true;
    else
        return false;
}

/*
 * 入队
 * */
bool EnQueue(LinkQueue *LQ,BitTree *bitTree)
{
    LinkNode *insertNode = (LinkNode *) malloc(sizeof (LinkNode));
    insertNode->data = *bitTree;
    insertNode->next = NULL;
    (*LQ).rear->next = insertNode; // 尾插
    (*LQ).rear = insertNode; // 尾随
    return true;
}

/*
 * 出队
 * */
bool DeQueue(LinkQueue *LQ,BitTree *bitTree)
{
    if((*LQ).rear == (*LQ).front)
        return false;
    LinkNode *deNode = (*LQ).front->next; // 跳过头结点
    *bitTree = deNode->data; // 获取数据
    (*LQ).front->next = deNode->next;
    if(*bitTree == (*LQ).rear->data)
    {
        (*LQ).rear = (*LQ).front; // 避免尾指针指向其他地址.
    }
    free(deNode);
    return true;
}

```

**图解层序遍历数据结构**

![5.树-2022-06-09-20-15-01](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/5.树-2022-06-09-20-15-01.png)


## 5.4 线索二叉树

### 5.4.1 线索二叉树实现
遍历二叉树是以一定的规则将二叉树中的结点排列成一个线性序列，从而得到几种遍历序列，使得该序列中的每个结点（第一个和最后一个结点除外）都有一个直接前驱和直接后继。

**需要掌握的知识点**
- 作用:方便从一个指定结点出发，找到其前驱、后继;方便遍历
- 存储结构
    - 在普通二叉树结点的基础上，增加两个标志位ltag 和rtag
    - ltag==1时，表示lchild指向前驱;ltag==0时，表示lchild指向左孩子
    - rtag==1时，表示rchild指向后继;rtag==O时，表示rchild指向右孩子
- 三种线索二叉树
    - 中序线索二叉树
        - 以中序遍历序列为依据进行"线索化”
    - 先序线索二叉树
        - 以先序遍历序列为依据进行“线索化"
    - 后序线索二叉树
        - 以后序遍历序列为依据进行"线索化”
- 几个概念
    - 线索
        - 指向前驱/后继的指针称为线索
    - 中序前驱/中序后继;先序前驱/先序后继;后序前驱/后序后继
- 手算画出线索二叉树
    - 确定线索二叉树类型——中序、先序、or后序?
    - 按照对应遍历规则，确定各个结点的访问顺序，并写上编号
    - 将n+1个空链域连上前驱、后继

**数据结构图**

![5.树-2022-06-09-21-17-18](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/5.树-2022-06-09-21-17-18.png)

**三种线索树的图**
![5.树-2022-06-09-22-58-58](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/5.树-2022-06-09-22-58-58.png)

**创建线索二叉树**
```C
/*
 * 线索二叉树初始化
 * */
bool InitThreadTree(ThreadTree *TT)
{
    return true;
}

/*
 * 创建二叉树的文件输入入口的入口函数
 * 本函数内部实现以读方式打开一个文件,并传递给CreatThreadTree();
 * */
bool CreatThreadBiTreeEn(ThreadTree *TT,ElemTypeChar *path)
{
    FILE *fp;
    fp = fopen(path,"r"); // 打开文件
    if(fp == NULL)
        return false;
    CreatThreadBiTree(TT,fp);
    fclose(fp); // 关闭文件
    return true;
}

/*
 * 创建二叉树中调用的静态函数 通过读取文件中的内容创建二叉树 使用'^'的个数表示跳出递归的层数.
 * */
static void CreatThreadBiTree(ThreadTree *TT,FILE *fp)
{
    ElemTypeChar data = ' ';
    if(fp == NULL)
        return;
    else
        fscanf(fp,"%c",&data);
    if(data == '^') // 表示置孩子为null 借此来一层一层的跳出递归
        *TT= NULL;
    else
    {
        (*TT) = (ThreadNode *) malloc(sizeof (ThreadNode));
        (*TT)->data = data;
        CreatThreadBiTree(&((*TT)->lChild),fp);
        CreatThreadBiTree(&((*TT)->rChild),fp);
        if((*TT)->lChild != NULL)
        {
            (*TT)->lTag = 0;
        }
        if((*TT)->rChild != NULL)
        {
            (*TT)->rTag = 0;
        }

    }
}

/*
 * 二叉树中序线索树的生成的入口函数
 * */
void CreateInThreadEn(ThreadTree TT)
{
    ThreadTree pre = NULL;
    if(TT != NULL) // 非空才能线索化
    {
        InThread(TT,&pre); // 线索化
        pre->rChild = NULL; // 处理最后一个结点
        pre->rTag = 1;
    }
}
/*
 * 中序线索化调用的函数
 * 程序思想: 线索化需要做的是通过先深度遍历左子树从而建立pre结点,同时根据记录下的pre结点建立后继线索.
 * 过程:1.遍历左子树. 2.建立前驱和后继线索(后继线索是在pre的基础上建立的). 3.更新pre结点. 4.遍历右子树
 * * */
void static InThread(ThreadTree TT,ThreadTree *pre)
{
    if(TT != NULL)
    {
        InThread(TT->lChild,pre); // 线索化左子树
        if(TT->lChild == NULL) // 左子树为空
        {
            TT->lChild = *pre; // 建立前驱线索
            TT->lTag = 1;
        }
        if((*pre) != NULL && (*pre)->rChild == NULL) // 满足前驱不是null且右子树为空
        {
            (*pre)->rChild = TT; // 建立前驱结点的后继线索
            (*pre)->rTag = 1;
        }
        (*pre) = TT;
        InThread((*pre)->rChild,pre); // 线索化右子树
    }
}
/*
 * 先序线索和后序线索处理最后一个结点的方式不同.最后一个结点指向为NULL
 * */
void CreatePreThreadEn(ThreadTree TT)
{
    ThreadTree pre = NULL;
    if(TT != NULL)
    {
        PreThread(TT,&pre); // 开始线索化
        if(pre->rChild == NULL) // 处理最后一个结点
        {
            pre->rTag = 1;
        }
    }
}
/*
 * 思想:先序线索化是一边遍历一边线索化的过程. 和中序所不同的是pre结点这一次记录的是每一次的根节点位置.
 * 过程:1.先序化根结点内容. 2.更新pre指向. 3.左子树. 4.右子树.
 * */
void static PreThread(ThreadTree TT,ThreadTree *pre)
{
    if(TT != NULL)
    {
        // 处理根结点
        if(TT->lChild == NULL)
        {
            TT->lChild = *pre; // 前驱线索
            TT->lTag = 1;
        }
        if((*pre) != NULL && (*pre)->rChild ==  NULL)
        {
            (*pre)->rChild = TT; // 后继线索
            (*pre)->rTag = 1;
        }
        (*pre) = TT; // 更新
        // 左子树
        if(TT->lTag == 0)
            PreThread(TT->lChild,pre);
        // 右子树 多一层判断避免进入死循环
        if(TT->rTag == 0)
            PreThread(TT->rChild,pre);
    }
}
void CreatePostThreadEn(ThreadTree TT)
{
    ThreadTree pre = NULL;
    if(TT != NULL)
        PostThread(TT,&pre);
    if(pre->rChild == NULL) // 处理最后一个结点
        pre->rTag = 1;
}

/*
 * 思想:先左后右最后根节点的思想.
 * 过程:1.左子树 2.右子树 3.根结点 4.更新pre
 * */
void static PostThread(ThreadTree TT,ThreadTree *pre)
{
    if(TT != NULL)
    {
        PostThread(TT->lChild,pre); // 左子树
        PostThread(TT->rChild,pre); // 右子树
        if(TT->lChild == NULL) // 根结点
        {
            TT->lChild = *pre; // 前驱结点线索化
            TT->lTag = 1;
        }
        if(*pre != NULL && (*pre)->rChild != NULL)
        {
            (*pre)->rChild = TT; // 后继结点线索化
            (*pre)->rTag = 1;
        }
        *pre = TT; // 更新
    }
}
```

### 5.4.2 线索二叉树的遍历

**重点知识**

- 中序线索二叉树
    - 后继
        - p的右子树中最左下结点
    - 前驱
        - p的左子树中最右下结点
- 先序线索二叉树
    - 后继
        - 若p有左孩子，则先序后继为左孩子
        - 若p没有左孩子，则先序后继为右孩子
    - 前驱 (需要遍历一整遍)
        - 如果能找到p的父节点，且p是左孩子，则p的父节点为其前驱
        - 如果能找到p的父节点，且p是右孩子，其左兄弟为空，则p的父节点即为其前驱
        - 如果能找到p的父节点，且p是右孩子，其左兄弟非空，则p的前驱为其左兄弟子树最后一个被先序遍历的结点
        - 如果p是根节点，则p没有先序前驱
- 后序线索二叉树
    - 后继(需要遍历一整遍)
        - 如果能找到p的父节点，且p是右孩子，p的父节点即为其后继
        - 如果能找到p 的父节点，且p是左孩子，其右兄弟为空，p的父节点即为其后继
        - 如果能找到p 的父节点，且p是左孩子，其右兄弟非空，则p的后继为其右兄弟子树中第一个被后序遍历的结点
        - 如果p是根节点，则p没有后序后继
    - 前驱
        - 若p有右孩子，则后序前驱为右孩子
        - 若p没有右孩子，则后序前驱为左孩子

#### 5.4.2.1 中序线索树的遍历

**正序**
```C
/*
 * 思想:中序遍历的第一个结点一定是最左最深侧的子节点,那么只需要当ltag = 0 时一直向下遍历即可.
 * */
ThreadNode *FirstNode(ThreadNode *threadNode)
{
    while (threadNode->lTag == 0)threadNode = threadNode->lChild;
    return threadNode;
}
/*
 * 指定结点的后继结点值.
 * 思想:后继结点出现的情况:
 * 1.当rtag = 1 时,那么rchild 指向的就是后继结点.
 * 2.当rtag = 0 时 则需要转到遍历当前结点的左孩子结点直到latg == 1时,lchild指向的结点,此时lchild指向的就是他的前驱,同样也就是当前结点的后继.
 * */
ThreadNode *NextNode(ThreadNode *threadNode)
{
    if(threadNode->rTag == 0) return FirstNode(threadNode->rChild);
    else return threadNode->rChild;
}
/*
 * 采用上述的两种算法来实现中序线索二叉树的遍历
 * 思想:利用for循环,初始值:是一个遍历的结点;判断条件:结点不等于NULL;增加:下一个结点.
 * */
void InorderThread(ThreadNode *TT)
{
    for (ThreadNode * p = FirstNode(TT);p!= NULL; p = NextNode(p))
        VisitThread(p);
}

void VisitThread(ThreadNode *TT)
{
    if(TT != NULL)
        printf("address:%p,data:%c\n",TT,TT->data);
}
```

**逆序**
```C
/*
 * 一下算法和寻找后继结点的思想一致
 * */
ThreadNode *LastNode(ThreadNode *threadNode)
{
    while (threadNode->rTag == 0) threadNode = threadNode->rChild;
    return threadNode;
}
ThreadNode *PreNode(ThreadNode *threadNode)
{
    if(threadNode->lTag == 0)
        return LastNode(threadNode->lChild);
    else
        return threadNode->lChild;
}
void RevInorderThread(ThreadNode *TT)
{
    for (ThreadNode *p = LastNode(TT);p != NULL;p = PreNode(p))
        VisitThread(p);
}
```


#### 5.5.2.2 先序后继和后序前驱的遍历
```C
/*
 * 先序和后序的排列决定了如果先序想找到前驱必须的遍历整个树,后序想找到后继就也必须如果.
 * 更为简单的例子:在先序中根节点第一个遍历,但他没有前驱. 后序中根结点最后一个遍历,但他没有后继.
 *
 * */
ThreadNode * PreThreadNextNode(ThreadNode *threadNode)
{
    // 有左孩子那么左孩子就是后继 否则就是右孩子
    if(threadNode->lTag == 0)
        return threadNode->lChild;
    else
        return threadNode->rChild;
}
ThreadNode * PostThreadPreNode(ThreadNode *threadNode)
{
    // 左右根 如果有右孩子那么就是前驱,否则左孩子是前驱
    if(threadNode->rTag == 0)
        return threadNode->rChild;
    else
        return threadNode->lChild;
}
```

## 5.6 树的存储结构

### 5.6.1 双亲表示法

**数据结构**

![5.树-2022-06-23-20-41-35](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/5.树-2022-06-23-20-41-35.png)

| index | data | parent |
|-------|------|--------|
| 0     | A    | -1     |
| 1     | B    | 0      |
| 2     | C    | 0      |
| 3     | D    | 0      |
| 4     | E    | 1      |
| 5     | F    | 1      |
| 6     | G    | 2      |
| 7     | H    | 3      |
| 8     | I    | 3      |
| 9     | J    | 3      |
| 10    | K    | 4      |

**定义**
```C
/*
 * 树的结点定义
 * data:数据元素
 * parent：双亲的位置域
 * */
typedef struct
{
    ElemTypeChar data;
    int parent;
}PTNode;
/*
 * 树的类型定义
 * nodes:双亲表示
 * nodeNum:结点数
 * */
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int nodeNum;
}PTree;

```

**代码实现**
```C
/*
 * 初始化树
 * */
void InitParentTree(PTree *PT)
{
    for (int i = 0; i < MAX_TREE_SIZE; i++)
    {
        PT->nodes[i].data = '#'; // 初始每一个元素的值为'#' 指向为-1
        PT->nodes[i].parent = -1;
    }
    PT->nodeNum = 0; // 初始结点个数值为0
}

/*
 * 创建树的入口文件，将打开的文件指针传给创建树函数。
 * */
void CreateParentTreeEn(PTree *PT, ElemTypeChar *path)
{
    FILE *fp = fopen(path,"r"); // 读模式打开
    if(fp == NULL)
        return;
    CreatParentTree(PT,fp);
    fclose(fp);
}
/*
 * 分别获取data值和父节点值，对父节点值进行强转为int，同时需要跳过字符 - 和 # 它们是用来跳过根节点和结尾的。
 * 本代码中处理父节点值的获取比较粗糙只适合parent<10的范围
 * 只是做测试使用 避免重复输入(C语言处理字符真的很累 文件操作也好麻烦)
 * */
void static CreatParentTree(PTree *PT,FILE *fp)
{
    ElemTypeChar data = ' ',parent = ' ';
    int index = 0;
    if(fp == NULL)
        return;
    while (PT->nodeNum < MAX_TREE_SIZE - 1)
    {
        fscanf(fp,"%c",&data);
        fscanf(fp,"%c",&parent);
        PT->nodes[index].data = data; // 赋值结点值
        if(data == '#') // 跳过结尾
            break;
        if(parent != '-') // 跳过根节点
            PT->nodes[index].parent = (int)parent-48; // 赋值父节点
        PT->nodeNum++; // 结点总数加1
        index++; // 索引
    }
}

/*
 * 插入结点
 * 参数:双亲结点树 PT 双亲结点ptNode
 * 作用:用于在CreateParentTree 中调用来进行插入操作 插入时需要对其进行赋值,并赋予他们双亲结点值.
 * 为配合节省空间删除所作的删除操作，添加了对所有元素的判断遇到parent值为-1的直接插入，不浪费空间。(垃圾处理)
 * */
void InsertPNode(PTree *PT,int parent,ElemTypeChar data)
{
    for (int i = 1; i <= PT->nodeNum; i++)
    {
        if(PT->nodeNum < MAX_TREE_SIZE && parent != -1 && PT->nodes[i].parent == -1)
        {
            PT->nodes[PT->nodeNum].data = data;// 插入值 和父节点
            PT->nodes[PT->nodeNum].parent = parent;
            PT->nodeNum++;
            return ;
        }
    }
}
/*
 * 想法实现: 因为PT->nodes 本身就是一个数组,我们插入一个新的父节点(除了根以外),
 *          我们不需要管新的结点在物理上的位置,只需要关心他的parent和他的孩子的parent的指向.
 * 添加:插入一个父节点和子节点一样都要不浪费空间--不多说
 * 例如: D:parent = 0;新插入P将取代D作为索引为0的结点的孩子,D将称为P的孩子D的parent应当指向P插入是的index位置.
 * */
void InsertParentNode(PTree *PT,int insertIndex,ElemTypeChar data)
{
    for (int i = 1; i <= PT->nodeNum ; i++)
    {
        if(PT->nodeNum < MAX_TREE_SIZE && insertIndex != -1 && PT->nodes[i].parent == -1)
        {
            PT->nodes[PT->nodeNum].data = data; // 新插入的结点
            PT->nodes[PT->nodeNum].parent = PT->nodes[insertIndex].parent; // 父节点传递
            PT->nodes[insertIndex].parent = i; // 插入位置是新结点(赋的值应该是找到的那个空的地址索引)
            PT->nodeNum++;
            return ;
        }
    }
}
/*
 * 删除元素
 * 如果删除的元素是一个父节点则遍历出所有的是他子结点的结点并置值为'#' parent = -1;
 * 处理办法不完善 不知道如何解决删除带有子节点的结点 -- 可能递归可以
 * */
void DeletePNode(PTree *PT,ElemTypeChar data,int parentIndex)
{
    // 外层控制找到结点位置
    for (int i = 0; i < PT->nodeNum; i++)
    {
        if(PT->nodes[i].data == data)
        {
            PT->nodes[i].parent = -1;
            PT->nodes[i].data = '#';
            // 内层控制找到他的子结点并置为-1.
            // 为什么还是要从1开始遍历 ,因为我们的插入中是可以允许在中间空白位置中插入的,如果我们所找的结点值的子元素的索引位置在他上面,那就会错过这个子节点.

/*            // 一下错误 递归进行尝试  以下算法忽略了子节点也是父节点的操作.
            for (int j = 1; j < PT->nodeNum; j++)
            {
                if (PT->nodes[j].parent == i)
                    PT->nodes[j].parent = -1,PT->nodes[j].data = '#';
            }*/
        }
    }
}
/*
 * 查询结点
 * */
void FindNode(PTree *PT,ElemTypeChar data)
{
    if (PT == NULL)
        return ;
    for (int i = 0; i < PT->nodeNum; i++)
    {
        if(PT->nodes[i].data == data)
            printf("index:%d,data:%c,parent:%d\n",i,PT->nodes[i].data,PT->nodes[i].parent);
    }
}
int NodeNum(PTree *PT)
{
    return PT->nodeNum;
}

/*
 * 返回指定结点的包含指定结点其子节点个数
 * */
int DesignateNodeNum(PTree *PT,int nodeIndex)
{
    static int num = 1;
    if (PT->nodes[nodeIndex].data == '#')
        return -1;
    for (int i = 0; i < PT->nodeNum; i++)
    {
        if(PT->nodes[i].parent == nodeIndex)
        {
            DesignateNodeNum(PT,i);
            num++;
        }
    }
    return num;
}

```

### 5.6.2 孩子表示法

### 5.6.2 孩子兄弟表示法

**定义**
```C
/*
 * 孩子兄弟表示法数据结构
 * */
typedef struct CSNode
{
    ElemTypeChar data; // 数据域
    struct CSNode *firstChild,*nextSibling; // 第一个孩子和右兄弟指针
}CSNode,*CSTree;

```

**实现**
```C
/*
 * 初始化孩子兄弟树
 * */
bool InitCSTree(CSTree *CS)
{
    if(CS == NULL)
        return false;
    (*CS) = NULL;
    return true;
}
/*
 * 孩子兄弟表示法的入口
 * */
bool CreatCSTreeEn(CSTree *CS,ElemTypeChar path[])
{
    FILE *fp;
    fp = fopen(path,"r");
    if(fp == NULL)
        return false;
    CreatCSTree(CS,fp);
    fclose(fp);
    return true;
}
/*
 * 采用读取文件内容+递归的方式实现创建孩子兄弟树.
 * */
bool static CreatCSTree(CSTree *CS,FILE *fp)
{
    ElemTypeChar data = ' ';
    if(fp == NULL)
        return false;
    else
        fscanf(fp,"%c",&data);
    if(data == '^')
        *CS = NULL;
    else
    {
        (*CS) = (CSNode*)malloc(sizeof (CSNode));
        (*CS)->data = data;
        CreatCSTree(&(*CS)->firstChild,fp);
        CreatCSTree(&(*CS)->nextSibling,fp);
    }
    return true;
}
/*
 * 计算树的深度 layer会在每一次递归中都生成一个 max是地址只有一个
 * */
void CSTreeDepth(CSTree CS,int layer,int *max)
{
    if(CS == NULL)
        return ;
    layer++; // 控制层数
    if(layer > *max)
        *max = layer;
    CSTreeDepth(CS->firstChild,layer,max); // 孩子遍历 向下
    CSTreeDepth(CS->nextSibling,layer,max); // 兄弟遍历 向右
}
/*
 * 返回指定值的结点 return NULL 为递归出口
 * */
CSTree BackCSNode(CSTree CS,ElemTypeChar e)
{
    CSTree pc,ps;
    if(CS == NULL)
        return NULL;
    if(CS->data == e)
        return CS;
    pc = BackCSNode(CS->firstChild,e);
    if(pc != NULL)
        return pc;
    ps = BackCSNode(CS->nextSibling,e);
    if(ps != NULL)
        return pc;
    return NULL;
}

/*
 * 返回指定值的父节点.
 * */
CSTree BackCSParentNode(CSTree CS,ElemTypeChar e)
{
    LinkCSTQueue LCSTQ;
    CSTree p,pc;
    InitCSTQueue(&LCSTQ);
    if(CS == NULL || CS->data == e)
        return CS;
    EnCSTQueue(&LCSTQ,&CS);
    while (!EmptyCSTQueue(LCSTQ))
    {
        // 入队顺序 A B C D E F G H I J K 出队到:E 时就可以找到K了
        DeCSTQueue(&LCSTQ,&p); // 出队作为父节点
        for (pc = p->firstChild;pc != NULL;pc = pc->nextSibling) // 递增的找兄弟结点 并入队兄弟结点
        {
            if(pc->data == e)
                return p; //找到直接返回父节点
            EnCSTQueue(&LCSTQ,&pc); // 孩子结点入队.
        }
    }
    return NULL;
}
/*
 * 先根遍历 深度优先,同二叉树,森林的先序遍历
 * */
void CSTPreOrder(CSNode *CSR)
{
    CSTree firstChild,nextSibling;
    if(CSR != NULL)
        VisitCST(CSR);
    firstChild = CSR->firstChild;
    if(firstChild != NULL)
        CSTPreOrder(firstChild);
    nextSibling = CSR->nextSibling;
    if(nextSibling != NULL)
        CSTPreOrder(nextSibling);
}
/*
 * 后根遍历 深度优先,同二叉树,森林的中序遍历
 * */
void CSTPostOrder(CSNode *CSR)
{
    if(CSR == NULL)
        return;
    CSTree firstChild,nextSibling;
    // 左孩子
    firstChild = CSR->firstChild;
    if(firstChild != NULL)
        CSTPostOrder(firstChild);
    VisitCST(CSR); // 遍历根结点
    // 右兄弟
    nextSibling = CSR->nextSibling;
    if(nextSibling != NULL)
        CSTPostOrder(nextSibling);

}

void CSTLevelOrder(CSNode *CSR)
{
    LinkCSTQueue LCSTQ;
    CSTree p;
    InitCSTQueue(&LCSTQ);
    EnCSTQueue(&LCSTQ,&CSR);
    while (!EmptyCSTQueue(LCSTQ))
    {
        // 此种写法是以孩子兄弟树的方式进行遍历
        DeCSTQueue(&LCSTQ,&p);
        VisitCST(p);
        if(p->firstChild != NULL)
            EnCSTQueue(&LCSTQ,&p->firstChild);
        if(p->nextSibling !=NULL)
            EnCSTQueue(&LCSTQ,&p->nextSibling);
    }
    /*
     * 此种写法是以树的形式进行遍历
    VisitCST(CSR);
    while (!EmptyCSTQueue(LCSTQ))
    {
        DeCSTQueue(&LCSTQ,&p);
        for(pc = p->firstChild,pc!= NULL,pc = pc->nextSibling)
        {
            VisitCST(pc);
            EnCSTQueue(&LCSTQ,&pc);
        }
    }
    * */
}
/*
 * 打印值
 * */
void VisitCST(CSNode *csNode)
{
    if(csNode != NULL)
        printf("addr:%p,data:%c\n",csNode,csNode->data);
    else
        return;
}
```

## 5.7 并查集

**实现**
```C
//
// Created by cxf18 on 2022/6/30.
//

#include "UFSets.h"

/*
 * 并查集这一种数据结构可以从树的角度来理解,但在实现层面可以不向树的数据结构靠,但可以借鉴其中的思想,例如双亲表示法.
 * 并查集其中主要是两大操作:查和并.
 * */

/*
 * 初始化
 * */
void InitSet(int S[])
{
    for (int i = 0; i < SIZE; i++)
    {
        S[i] = -1;
    }
}

/*
 * 创建并查集的入口
 * */
void CreateSetEn(int S[],char *path)
{
    FILE *fp = fopen(path,"r");
    if(fp == NULL)
        return;
    CreateSet(S,fp);
    fclose(fp);
}
/*
 * 通过文件内容创建并查集
 * */
void static CreateSet(int S[],FILE *fp)
{
    char data[ReadSize];
    if(fp == NULL)
        return;
    for (int i = 0; i < SIZE; i++)
    {
        // 读出数据
        fgets ( data, ReadSize,fp );
        if(data[0] != '#') // 跳过根结点
        {
            S[i] = atoi(data); // 转换为二进制
        }
        printf("data:%d\n",S[i]);
    }
}
/*
 * find 算法实现的是每次对一个结点的查找就会让这个结点最终挂载到根结点上,随着find次数不断增加,最终所有结点都将挂在根结点下.find操作也变得更容易.
 *      返回根的速度也更快.
 * */
int Find(int S[],int x) {
    int root = x;
    while (S[root] >= 0)
        root = S[root]; // 循环找到根
    while (x != root) // 压缩路径
    {
        // 指向x的父节点
        int parent = S[x];
        // 将x直接挂到根结点上
        S[x] = root;
        // 新一轮挂载开始
        x = parent;
    }
    return root;
}
/*
 * union操纵是一个在不断合并中优化的操作,如果需要测试数据建议初始都为-1.
 * */
void Union(int S[],int Root1,int Root2)
{
    // 根相同
    if(Root1 == Root2)
        return;
    // 按照规则发展,未合并的集合会指向一个结点那就是-1,所以在最初的建立过程中会出现增加的负值而这个负值的绝对值恰好是结点总数.
    // 推断此处的大于正好说明了一棵树的结点数小.
    // 进一步还需要考虑高度问题,高度问题在我们每次进行Find操作时其实已经解决了高度的问题,再不断的find和union过程中最后都会指向唯一根结点,
    // 那么自然每次的union会如我们上面推论进行发展.
    if(S[Root2] >S[Root1])
    {
        S[Root1] += S[Root2]; // 累计结点总数
        S[Root2] = Root1; // 小树合并到大树
    }
    // else 触发的条件是 两个根的结点数一致 或者 root1 大于root2
    // 每次触发,都会使得根结点的值变小,结点数增加.
    else
    {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}
```

