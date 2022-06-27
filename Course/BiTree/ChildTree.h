//
// Created by cxf18 on 2022/6/26.
//

#ifndef DATASTRUCTURE_CHILDTREE_H
#define DATASTRUCTURE_CHILDTREE_H
#include "Status.h"
#define MAX_TREE_SIZE 100
typedef char ElemTypeChar;

/*
 * 孩子结点数据结构
 * */
struct CTNode
{
    int child; // 孩子结点在数组中的位置
    struct CTNode *next; // 下一个孩子
};
/*
 * 链接顺序和链表数据结构
 * */
typedef struct
{
    ElemTypeChar data;
    struct CTNode *firstChild; // 第一个孩子
}CTBox;

typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int nodeNum,root; // 结点数和根所在的位置
}CTree;

void InitCTree(CTree *CT);
bool CreateCTreeEn(CTree *CT,ElemTypeChar path[]);
bool static CreateCTree(CTree *CT,FILE *fp,int index);
#endif //DATASTRUCTURE_CHILDTREE_H
