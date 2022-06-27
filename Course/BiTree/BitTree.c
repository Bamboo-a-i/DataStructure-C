//
// Created by cxf18 on 2022/6/5.
//

#include "BitTree.h"
#include "LQueue.h"
#include "Stack.h"

/*
 * 结构型二叉树初始化
 *
 * 参数:struct TreeNode的指针
 * */
bool InitTreeNode(struct TreeNode *T)
{
    // 可以从0开始或者1开始,从1开始利于使用
    for (int i = 0; i < Maxsize; i++)
    {
        T[i].isEmpty = true;
    }
    return true;
}
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
/*
 * 前中后遍历
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

/*
 * 使用队列的形式来进行层序遍历
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

/*
 * 使用栈的操作和二叉树栈数据结构实现前中后遍历
 * */
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
            p = p->lChild;
        }
        else
        {
            Pop(&ST,&p);
            p = p->rChild;
        }
    }
}
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

// 线索二叉树初始化
bool InitThreadTree(ThreadTree *TT)
{

    return true;
}

/*
 * 创建二叉树的文件输入入口的入口函数
 * 本函数内部实现以读方式打开一个文件,并传递给CreatThreadTree();
 * */
bool CreatThreadBiTree(ThreadTree *TT,ElemTypeChar *path)
{
    FILE *fp;
    fp = fopen(path,"r"); // 打开文件
    if(fp == NULL)
        return false;
    CreatThreadTree(TT,fp);
    fclose(fp); // 关闭文件
    return true;
}

/*
 * 创建二叉树中调用的静态函数 通过读取文件中的内容创建二叉树 使用'^'的个数表示跳出递归的层数.
 * */
static void CreatThreadTree(ThreadTree *TT,FILE *fp)
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
        CreatThreadTree(&((*TT)->lChild),fp);
        CreatThreadTree(&((*TT)->rChild),fp);
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
void CreateInThread(ThreadTree TT)
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
void CreatePreThread(ThreadTree TT)
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
void CreatePostThread(ThreadTree TT)
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