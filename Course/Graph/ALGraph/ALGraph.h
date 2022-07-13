//
// Created by cxf18 on 2022/7/10.
//

#ifndef DATASTRUCTURE_ALGRAPH_H
#define DATASTRUCTURE_ALGRAPH_H
#include "Status.h"
#define MaxVertexNum 100
/*
 * 邻接表示法数据结构
 * */

// 图的类型
typedef enum
{
    UDG,     // 0-无向图
    UDN,     // 1-无向网(带权值)
    DG,    // 2-有向图
    DN     // 3-有向网(带权值)
}GraphKind;

// 权值
typedef int InfoType;
typedef char VertexType;
// 边/弧
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next; //下一条弧的指针
    InfoType info;
}ArcNode;
// 顶点
typedef struct VNode
{
    VertexType data;
    ArcNode *first; //第一条边
    ArcNode *tail; // 尾巴
}VNode,AdjList[MaxVertexNum];
// 图
typedef struct
{
    AdjList vertices; // 顶点
    int vexNum,arcNum;
    GraphKind graphKind;
}ALGraph;

/*
 * 基本操作
 * 1.生成邻接表法的图
 * 1.返回给定的xy对应的下标值,从而来定位
 * 2.初始化一个顶点对应存储边的二维数组值,
 * 3.重置
 * 王道数据结构
 * Adjacent(G,x,y):判断图G是否存在边<x, y>或(x, y)。
 * Neighbors(G,x):列出图G中与结点x邻接的边。
 * InsertVertex(G,x):在图G中插入顶点x。
 * DeleteVertex(G,x):从图G中删除顶点x。
 * AddEdge(G,x,y):若无向边(x, y)或有向边<x, y>不存在，则向图G中添加该边。
 * RemoveEdge(G,x,y):若无向边(x,y)或有向边<x, y>存在，则从图G中删除该边。
 * FirstNeighbor(G,x):求图G中顶点x的第一个邻接点，若有则返回顶点号。若x没有邻接点或图中不存在x，则返回-1。
 * NextNeighbor(G,x,y):假设图G中顶点y是顶点x的一个邻接点，返回除y之外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1。
 * Get_edge_value(G,x,y):获取图G中边(x, y)或<x, y>对应的权值。
 * Set_edge_value(G,x,y,v):设置图G中边(x, y)或<x, y>对应的权值为v。
 * */
int Locate(ALGraph *G,VertexType x);
void CreateAlGraph(ALGraph *G,GraphKind graphKind);
ArcNode FindLast(ArcNode *arcNode);
bool AdjacentByIndex(ALGraph *G,int x,int y);
bool InsertVertex(ALGraph *G,VertexType x);
bool DeleteVertex(ALGraph *G,VertexType x);
bool AddEdge(ALGraph *G,VertexType x,VertexType y,int info);
bool RemoveEdge(ALGraph *G,VertexType x,VertexType y);
#endif //DATASTRUCTURE_ALGRAPH_H
