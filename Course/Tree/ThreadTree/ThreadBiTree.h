//
// Created by cxf18 on 2022/7/5.
//

#ifndef DATASTRUCTURE_THREADBITREE_H
#define DATASTRUCTURE_THREADBITREE_H
#include "Status.h"
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
 * 二叉树线索化
 *
 * 定义:1.初始化 2.文件生成线索二叉树入口,生成二叉树  3.前中后序二叉树的线索化入口及实现
 * */
bool InitThreadTree(ThreadTree *TT);

bool CreatThreadBiTreeEn(ThreadTree *TT,ElemTypeChar *path);
static void CreatThreadBiTree(ThreadTree *TT,FILE *fp);

void CreateInThreadEn(ThreadTree TT);
void static InThread(ThreadTree TT,ThreadTree *pre);
void CreatePreThreadEn(ThreadTree TT);
void static PreThread(ThreadTree TT,ThreadTree *pre);
void CreatePostThreadEn(ThreadTree TT);
void static PostThread(ThreadTree TT,ThreadTree *pre);

/*
 * 二叉树线索化的遍历:
 * 1. 中序后继 - a.第一个遍历结点 - b.指定结点的后继结点 - c. 不含头结点中序遍历算法
 * 2. 中序前驱 - a.最后一个遍历结点 - b.指定结点的前驱结点 - c. 不含头结点中序逆向遍历算法
 * 3. 前序 - a.后继结点
 * 4. 后序 - a.前驱结点
 * 5. 打印值
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

#endif //DATASTRUCTURE_THREADBITREE_H
