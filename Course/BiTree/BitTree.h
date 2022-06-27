//
// Created by cxf18 on 2022/6/5.
//

#ifndef DATASTRUCTURE_BITTREE_H
#define DATASTRUCTURE_BITTREE_H
#include "Status.h"
typedef char ElemTypeChar;

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
 * 线索化二叉树数据结构
 * */
typedef struct ThreadNode
{
    ElemTypeChar data;
    struct ThreadNode *lChild,*rChild;
    int lTag,rTag; // 左右线索标志
}ThreadNode,*ThreadTree;


/*
 * 基础操作  1.初始化二叉树结构数组 2.初始化链式二叉树 3.访问根结点 4.文件创建二叉树入口 5.创建二叉树 6.判空
 *          7.判空 8.树的深度 9.返回值e的指针 10.返回指定结点值的双亲结点
 * */
bool InitTreeNode(struct TreeNode *T);
bool InitBitTree(BitTree *root);
void Visit(BitTree T);
bool CreatBiTree(BitTree *T,ElemTypeChar *path);
static void CreatTree(BitTree *T,FILE *fp);
bool Empty(BitTree T);
int BitTreeDepth(BitTree T);
BitTree BackBitTreeNode(BitTree T,ElemTypeChar);
BitTree BackBitParentNode(BitTree T,ElemTypeChar e);

/*
 * 递归遍历
 * */
void PreOrder(BitTree T);
void InOrder(BitTree T);
void PostOrder(BitTree T);
void LevelOrder(BitTree T);

/*
 * 非递归遍历（栈）
 * */
void StackPreOrder(BitTree T);
void StackInOrder(BitTree T);
void StackPostOrder(BitTree T);

/*
 * 二叉树线索化
 *
 * 定义:1.初始化 2.文件生成二叉树入口,生成二叉树  3.前中后序二叉树的线索化入口及实现  4.线索化的遍历
 * */
bool InitThreadTree(ThreadTree *TT);

bool CreatThreadBiTree(ThreadTree *TT,ElemTypeChar *path);
static void CreatThreadTree(ThreadTree *TT,FILE *fp);

void CreateInThread(ThreadTree TT);
void static InThread(ThreadTree TT,ThreadTree *pre);
void CreatePreThread(ThreadTree TT);
void static PreThread(ThreadTree TT,ThreadTree *pre);
void CreatePostThread(ThreadTree TT);
void static PostThread(ThreadTree TT,ThreadTree *pre);

/*
 * 二叉树线索化的遍历:
 * 1. 中序后继 - a.第一个遍历结点 - b.指定结点的后继结点 - c. 不含头结点中序遍历算法 d. - 打印值
 * 2. 中序前驱 - a.最后一个遍历结点 - b.指定结点的前驱结点 - c. 不含头结点中序逆向遍历算法
 * 3. 前序 - a.后继结点
 * 4. 后序 - a.前驱结点
 * */
ThreadNode *FirstNode(ThreadNode *threadNode);
ThreadNode *NextNode(ThreadNode *threadNode);
void InorderThread(ThreadNode *TT);

ThreadNode *LastNode(ThreadNode *threadNode);
ThreadNode *PreNode(ThreadNode *threadNode);
void RevInorderThread(ThreadNode *TT);

ThreadNode * PreThreadNextNode(ThreadNode *threadNode);
ThreadNode * PostThreadPreNode(ThreadNode *threadNode);

void VisitThread(ThreadNode *TT);

#endif //DATASTRUCTURE_BITTREE_H
