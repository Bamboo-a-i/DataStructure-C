//
// Created by cxf18 on 2022/6/26.
//

#ifndef DATASTRUCTURE_CHILDTREE_H
#define DATASTRUCTURE_CHILDTREE_H
#include "Status.h"
#define MAX_TREE_SIZE 100
typedef char ElemTypeChar;

/*
 * ���ӽ�����ݽṹ
 * */
struct CTNode
{
    int child; // ���ӽ���������е�λ��
    struct CTNode *next; // ��һ������
};
/*
 * ����˳����������ݽṹ
 * */
typedef struct
{
    ElemTypeChar data;
    struct CTNode *firstChild; // ��һ������
}CTBox;

typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int nodeNum,root; // ������͸����ڵ�λ��
}CTree;

void InitCTree(CTree *CT);
bool CreateCTreeEn(CTree *CT,ElemTypeChar path[]);
bool static CreateCTree(CTree *CT,FILE *fp,int index);
#endif //DATASTRUCTURE_CHILDTREE_H
