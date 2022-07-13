//
// Created by cxf18 on 2022/6/27.
//

#include "ChildSiblingTree.h"
#include "LinkQueue.h"
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
    LinkQueue LQ;
    CSTree p,pc;
    InitQueue(&LQ);
    if(CS == NULL || CS->data == e)
        return CS;
    EnQueue(&LQ,&CS);
    while (!EmptyQueue(LQ))
    {
        // 入队顺序 A B C D E F G H I J K 出队到:E 时就可以找到K了
        DeQueue(&LQ,&p); // 出队作为父节点
        for (pc = p->firstChild;pc != NULL;pc = pc->nextSibling) // 递增的找兄弟结点 并入队兄弟结点
        {
            if(pc->data == e)
                return p; //找到直接返回父节点
            EnQueue(&LQ,&pc); // 孩子结点入队.
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
    LinkQueue LQ;
    CSTree p;
    InitQueue(&LQ);
    EnQueue(&LQ,&CSR);
    while (!EmptyQueue(LQ))
    {
        // 此种写法是以孩子兄弟树的方式进行遍历
        DeQueue(&LQ,&p);
        VisitCST(p);
        if(p->firstChild != NULL)
            EnQueue(&LQ,&p->firstChild);
        if(p->nextSibling !=NULL)
            EnQueue(&LQ,&p->nextSibling);
    }
    /*
     * 此种写法是以树的形式进行遍历
    VisitCST(CSR);
    while (!EmptyQueue(LQ))
    {
        DeQueue(&LQ,&p);
        for(pc = p->firstChild,pc!= NULL,pc = pc->nextSibling)
        {
            VisitCST(pc);
            EnQueue(&LQ,&pc);
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