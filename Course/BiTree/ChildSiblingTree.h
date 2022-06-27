//
// Created by cxf18 on 2022/6/27.
//

#ifndef DATASTRUCTURE_CHILDSIBLINGTREE_H
#define DATASTRUCTURE_CHILDSIBLINGTREE_H
#include "Status.h"
#define MAX_TREE_SIZE 100
typedef char ElemTypeChar;

/*
 * 孩子兄弟表示法数据结构
 * */
typedef struct CSNode
{
    ElemTypeChar data; // 数据域
    struct CSNode *firstChild,*nextSibling; // 第一个孩子和右兄弟指针
}CSNode,*CSTree;

bool InitCSTree(CSTree *CS);
bool CreatCSTreeEn(CSTree *CS,ElemTypeChar path[]);
bool static CreatCSTree(CSTree *CS,FILE *fp);
void CSTreeDepth(CSTree CS,int layer,int *max);
CSTree BackCSNode(CSTree CS,ElemTypeChar e);
CSTree BackCSParentNode(CSTree CS,ElemTypeChar e);
#endif //DATASTRUCTURE_CHILDSIBLINGTREE_H
