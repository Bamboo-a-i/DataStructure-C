//
// Created by cxf18 on 2022/6/23.
//

#ifndef DATASTRUCTURE_PARENTTREE_H
#define DATASTRUCTURE_PARENTTREE_H
#include "Status.h"

/*
 * 树的结点定义
 * data:数据元素
 * parent：双亲的位置域
 * */
typedef struct
{
    ElemTypeChar data;
    int parent;
}PTNode;
/*
 * 树的类型定义
 * nodes:双亲表示
 * nodeNum:结点数
 * */
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int nodeNum;
}PTree;

/*
 * 双亲表示法的操作
 * 1.初始化
 * 2.创建(入口和执行)
 * 3.插入结点
 * 4.插入父节点
 * 5.删除指定结点
 * 6.查找结点
 * 7.结点个数
 * 8.指定结点的结点个数
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
