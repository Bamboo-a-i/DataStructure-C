//
// Created by cxf18 on 2022/6/27.
//

#ifndef DATASTRUCTURE_CHILDSIBLINGTREE_H
#define DATASTRUCTURE_CHILDSIBLINGTREE_H
#include "Status.h"


/*
 * 孩子兄弟表示法数据结构
 * */
typedef struct CSNode
{
    ElemTypeChar data; // 数据域
    struct CSNode *firstChild,*nextSibling; // 第一个孩子和右兄弟指针
}CSNode,*CSTree;

/*
 * 孩子兄弟表示法操作
 * 1.初始化
 * 2.创建入口
 * 3.创建
 * 4.求深度
 * 5.根据e返回对应结点
 * 6.根据e返回对应父结点
 * 7.前序-后序-层序
 * 8.输出
 * */
bool InitCSTree(CSTree *CS);
bool CreatCSTreeEn(CSTree *CS,ElemTypeChar path[]);
bool static CreatCSTree(CSTree *CS,FILE *fp);
void CSTreeDepth(CSTree CS,int layer,int *max);
CSTree BackCSNode(CSTree CS,ElemTypeChar e);
CSTree BackCSParentNode(CSTree CS,ElemTypeChar e);
void CSTPreOrder(CSNode *CSR);
void CSTPostOrder(CSNode *CSR);
void CSTLevelOrder(CSNode *CSR);
void VisitCST(CSNode *csNode);
#endif //DATASTRUCTURE_CHILDSIBLINGTREE_H
