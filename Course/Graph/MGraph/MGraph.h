//
// Created by cxf18 on 2022/7/6.
//

#ifndef DATASTRUCTURE_MGRAPH_H
#define DATASTRUCTURE_MGRAPH_H
#include "Status.h"
#define MaxVertexNum 100 // 图中的顶点数组最大值
#define INFINITY INT_MAX // 最大的int整数

// 图的类型
typedef enum
{
    UDG,     // 0-无向图
    UDN,     // 1-无向网(带权值)
    DG,    // 2-有向图
    DN     // 3-有向网(带权值)
}GraphKind;

// 顶点数据类型
typedef char VertexType;

/*
 * 边的数据类型:
 * 带权图中表示权值.
 * 无权图1表示两点间连接,0表示不连接.
 * */
typedef int EdgeType;

/*
 * 定义邻接矩阵存储图的数据结构
 * */
typedef struct
{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum]; // 二维数组
    int verNum,arcNum; // 图中当前的顶点树和弧数.
    GraphKind graphKind;
}MGraph;

/*
 * 图的基本操作
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

int static Locate(MGraph *G,VertexType x);
int static InitEdge(MGraph *G,GraphKind graphKind);
int static ResetEdge(MGraph *G,GraphKind graphKind,int index);
bool Adjacent(MGraph *G,VertexType x,VertexType y);
void Neighbors(MGraph *G,VertexType x);
bool InsertVertex(MGraph *G,VertexType x);
bool DeleteVertex(MGraph *G,VertexType x);
bool AddEdge(MGraph *G,VertexType x,VertexType y,int info);
bool RemoveEdge(MGraph *G,VertexType x,VertexType y);
int FirstNeighbor(MGraph *G,VertexType x);
int NextNeighbor(MGraph *G,VertexType x,VertexType y);
int Get_edge_value(MGraph *G,VertexType x,VertexType y);
int Set_edge_value(MGraph *G,VertexType x,VertexType y,int info);


/*
 * 图的应用
 * 1.广度优先算法
 * 2.深度优先算法
 * 3.BFS算法求单源最短路径
 * 4.BFS算法求单源最短路径--针对有向图
 * */
void Visit(MGraph G,int v);
void BFSTraverse(MGraph G,int v);
void BFS(MGraph G,int v);
void DFSTraverse(MGraph G);
void DFS(MGraph G,int v);
void BFS_MIN_Distance(MGraph G,int u);
void BFS_MIN_DistanceForDG(MGraph G,int u);

#endif //DATASTRUCTURE_MGRAPH_H
