//
// Created by cxf18 on 2022/7/23.
//

#include "BinarySearchTree.h"
#include "stdio.h"
#include "stdlib.h"

// 插入结点函数,根据关键字和T.key的对比确定插入位置.
int BSTInsert(BSTree *T,int key)
{
    if(T == NULL)
    {
        // 此段代码报错
        // Signal: SIGSEGV (Segmentation fault) ;猜测是错误访问指针的问题,
        T = (BSTree *)malloc(sizeof (BSTNode));
        (*T)->key = key;
        (*T)->rChild =  NULL;
        (*T)->lChild = NULL;
    }
    else if(key == (*T)->key)
        return 0;
    else if(key < (*T)->key)
        return BSTInsert(&(*T)->lChild,key);
    else
        return BSTInsert(&(*T)->rChild,key);
    return -1;
}
// 循环查询
BSTree BSTSearch(BSTree T,int key)
{
    while (T != NULL && T->key != key)
    {
        if(key < T->key)
            T = T->lChild;
        else
            T = T->rChild;
    }
    return T;
}
// 递归查询
BSTree BSTSearchD(BSTree T,int key)
{
    if(T == NULL)
        return NULL;
    if(T->key == key)
        return T;
    if(key < T->key)
        return BSTSearchD(T->lChild,key);
    else
        return BSTSearchD(T->rChild,key);
}
// 构建
void BSTBuild(BSTree *T,int value[],int n)
{
    T = NULL;
    int i = 0;
    while (i < n)
    {
        BSTInsert(T,value[i]);
        i++;
    }
}