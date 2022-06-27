# 5 二叉树和树

## 5.1 存储结构
**1.顺序存储**
```c


struct TreeNode
{
    ElemType value;
    bool isEmpty; // 结点是否为空
};


```

**2.链式存储**
```c
// 链式存储
struct  ElemTypeBit
{
    int value;
};
// 顺序存储的二叉树结构体
typedef struct BitNode
{
    //    struct ElemTypeBit data; // 值 一种写法
    ElemTypeChar data;
    struct BitNode *lChild,*rChild; // 左右孩子
    //struct BitNode *Parent; // 父节点
}BitNode,*BitTree;


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
**1.初始化**
```c
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
```

**2.创建**
```c
/*
 * 创建二叉树的文件输入入口的入口函数
 *
 * 参数:BitTree的指针,文件路径
 *
 * 返回:bool
 * */
bool CreatBiTree(BitTree *T,ElemTypeChar *path)
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
 *
 * 传参:BitTree的指针 FILE指针
 *
 * 返回:void
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

```

**3.判空**
```c
/*
 * 判断二叉树是否为空
 *
 * 参数:BitTree
 *
 * 返回:bool
 * */
bool Empty(BitTree T)
{
    return T == NULL ? true:false;
}
```

**4.深度**
```c
/*
 * 计算二叉树深度 -- 采用递归实现
 *
 * 参数:BitTree
 *
 * 返回:int(深度)
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
```

**5.根据结点值返回结点**
```c
/*
 * 返回值e对应的结点,方法的目的：我们知道一个结点的值，在去求他的结点，而已知结点在获取值是没有意义的。
 *
 * 参数:BitTree ElemTypeChar
 *
 * 返回:BitNode 结点
 *
 * 改进意见:设置为static
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
```

**6.根据结点值返回双亲结点**
```c

/*
 * 返回值e对应的结点,方法的目的：我们知道一个结点的值,去找到他的双亲结点
 *
 * 参数:BitTree ElemTypeChar
 *
 * 返回:BitNode 结点
 *
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

**1.前序**
```c

/*
 * 目的:前序遍历
 *
 * 参数:BitTree
 *
 * 返回:void
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
```
**2.中序**
```c
/*
 * 目的:中序遍历
 *
 * 参数:BitTree
 *
 * 返回:void
 * */
void InOrder(BitTree T)
{
    if(T != NULL)
    {
        InOrder(T->lChild);
        Visit(T);
        InOrder(T->rChild);
    }
}
```
**3.后序**
```c
/*
 * 目的:后序遍历
 *
 * 参数:BitTree
 *
 * 返回:void
 * */
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

#### 3.层序遍历
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
 *
 * 参数:LinkQueue
 *
 * 返回:bool
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
 *
 * 参数:LinkQueue
 *
 * 返回:bool
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
 *
 * 参数:LinkQueue
 *
 * 返回:bool
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
 *
 * 参数:LinkQueue 存储二叉树结点,bitNode结点值
 *
 * 返回:bool
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

遍历二叉树是以一定的规则将二叉树中的结点排列成一个线性序列，从而得到几种遍历序列，使得该序列中的每个结点（第一个和最后一个结点除外）都有一个直接前驱和直接后继。
