//
// Created by cxf18 on 2022/6/5.
//

#include "BitTree.h"
#include "LinkQueue.h"
#include "Stack.h"
/*
 * 结构型二叉树初始化
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

/*
 * 使用队列的形式来进行二叉树层序遍历
 * */
void LevelOrder(BitTree T)
{
    LinkBTQueue LQ;
    InitLQueue(&LQ);
    BitTree bitTree;
    EnLQueue(&LQ,&T); // 根结点入队
    while (!EmptyLQueue(LQ))
    {
        DeLQueue(&LQ,&bitTree); // 出队
        Visit(bitTree); // 访问结点
        if(bitTree->rChild != NULL)
            EnLQueue(&LQ,&bitTree->lChild);
        if(bitTree->lChild != NULL)
            EnLQueue(&LQ,&bitTree->rChild);
    }
}

/*
 * 使用栈的操作和二叉树栈数据结构实现前中后遍历
 * */
void StackPreOrder(BitTree T)
{
    BitTreeStack ST;
    InitStack(&ST);
    BitTree p = T;
    while (p || !EmptyStack(ST))
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
    InitStack(&ST);
    BitTree p = T;
    while (p || !EmptyStack(ST))
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
    InitStack(&ST);
    BitTree  p = T,r = NULL; // r 作为记录结点
    while (p || !EmptyStack(ST))
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