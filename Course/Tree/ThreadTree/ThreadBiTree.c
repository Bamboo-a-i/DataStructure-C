//
// Created by cxf18 on 2022/7/5.
//

#include "ThreadBiTree.h"
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