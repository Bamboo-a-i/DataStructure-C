//
// Created by cxf18 on 2022/6/23.
//

#ifndef DATASTRUCTURE_PARENTTREE_H
#define DATASTRUCTURE_PARENTTREE_H
#include "Status.h"
#define MAX_TREE_SIZE 100
typedef char ElemTypeChar;

/*
 * ���Ľ�㶨��
 * data:����Ԫ��
 * parent��˫�׵�λ����
 * */
typedef struct
{
    ElemTypeChar data;
    int parent;
}PTNode;
/*
 * �������Ͷ���
 * nodes:˫�ױ�ʾ
 * nodeNum:�����
 * */
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int nodeNum;
}PTree;

/*
 * ˫�ױ�ʾ���� 1.��ʼ�� 2.����(��ں�ִ��) 4.������ 5.���븸�ڵ� 6.ɾ��ָ����� 7.������ 8.ָ�����Ľ�����
 * */
void InitParentTree(PTree *PT);
void CreateParentTreeEn(PTree *PT, ElemTypeChar *path);
void static CreatParentTree(PTree *PT,FILE *fp);
void InsertPNode(PTree *PT,int parent,ElemTypeChar data);
void InsertParentNode(PTree *PT,int insertIndex,ElemTypeChar data);
void DeletePNode(PTree *PT,ElemTypeChar data,int parentIndex);
void FindNode(PTree *PT,ElemTypeChar data);
int NodeNum(PTree *PT);
int DesignateNodeNum(PTree *PT,int nodeIndex);

#endif //DATASTRUCTURE_PARENTTREE_H
