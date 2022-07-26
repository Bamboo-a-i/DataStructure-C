//
// Created by cxf18 on 2022/7/23.
//

#ifndef DATASTRUCTURE_BINARYSEARCHTREE_H
#define DATASTRUCTURE_BINARYSEARCHTREE_H

// 二叉排序树数据结构
typedef struct BSTNode
{
    int key;
    struct BSTNode *lChild,*rChild;
}BSTNode,*BSTree;

/*
 * 操作:
 * 1.插入
 * 2.查找 - 递归和非递归
 * 3.构建
 * */

int BSTInsert(BSTree *T,int key);
BSTree BSTSearch(BSTree T,int key);
BSTree BSTSearchD(BSTree T,int key);
void BSTBuild(BSTree *T,int value[],int n);
#endif //DATASTRUCTURE_BINARYSEARCHTREE_H
