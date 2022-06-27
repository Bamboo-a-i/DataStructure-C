//
// Created by cxf18 on 2022/6/27.
//

#ifndef DATASTRUCTURE_CHILDSIBLINGTREE_H
#define DATASTRUCTURE_CHILDSIBLINGTREE_H
#include "Status.h"
#define MAX_TREE_SIZE 100
typedef char ElemTypeChar;

/*
 * �����ֵܱ�ʾ�����ݽṹ
 * */
typedef struct CSNode
{
    ElemTypeChar data; // ������
    struct CSNode *firstChild,*nextSibling; // ��һ�����Ӻ����ֵ�ָ��
}CSNode,*CSTree;

bool InitCSTree(CSTree *CS);
bool CreatCSTreeEn(CSTree *CS,ElemTypeChar path[]);
bool static CreatCSTree(CSTree *CS,FILE *fp);
void CSTreeDepth(CSTree CS,int layer,int *max);
CSTree BackCSNode(CSTree CS,ElemTypeChar e);
CSTree BackCSParentNode(CSTree CS,ElemTypeChar e);
#endif //DATASTRUCTURE_CHILDSIBLINGTREE_H
