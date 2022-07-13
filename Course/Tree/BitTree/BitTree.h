//
// Created by cxf18 on 2022/6/5.
//

#ifndef DATASTRUCTURE_BITTREE_H
#define DATASTRUCTURE_BITTREE_H
#include "Status.h"

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


/*
 * 基础操作
 * 1.初始化二叉树结构数组
 * 2.初始化链式二叉树
 * 3.访问根结点
 * 4.文件创建二叉树入口
 * 5.创建二叉树
 * 6.判空
 * 7.树的深度
 * 8.返回值e的指针
 * 9.返回指定结点值的双亲结点
 * */
bool InitTreeNode(struct TreeNode *T);
bool InitBitTree(BitTree *root);
void Visit(BitTree T);
bool CreatBiTreeEn(BitTree *T,ElemTypeChar *path);
static void CreatTree(BitTree *T,FILE *fp);
bool Empty(BitTree T);
int BitTreeDepth(BitTree T);
BitTree BackBitTreeNode(BitTree T,ElemTypeChar);
BitTree BackBitParentNode(BitTree T,ElemTypeChar e);

/*
 * 递归遍历二叉树
 * */
void PreOrder(BitTree T);
void InOrder(BitTree T);
void PostOrder(BitTree T);
void LevelOrder(BitTree T);

/*
 * 非递归遍历二叉树（栈）
 * */
void StackPreOrder(BitTree T);
void StackInOrder(BitTree T);
void StackPostOrder(BitTree T);
#endif //DATASTRUCTURE_BITTREE_H
