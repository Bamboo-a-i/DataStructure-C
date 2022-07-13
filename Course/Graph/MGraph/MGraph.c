//
// Created by cxf18 on 2022/7/6.
//

#include "MGraph.h"
#include "LinkQueue.h"
/*
 * 返回x对应在顶点数组中的下标索引
 * */
int static Locate(MGraph *G,VertexType x)
{
    for (int i = 0; i < (*G).verNum; i++)
    {
        if((*G).Vex[i] == x)
            return i;
    }
    return -1;
}

/*
 * 按传入的图的类型初始化边 --- 作为一个保留性操作留下来.
 * 有权图 无穷
 * 无权图 0
 * */
int static InitEdge(MGraph *G,GraphKind graphKind)
{
    // 赋值
    int assign;
    int i;
    // 确定一个非连通标记
    if((*G).graphKind == DG || (*G).graphKind == UDG)
        assign = 0;        // 图
    else if((*G).graphKind == DN || (*G).graphKind == UDN)
        assign = INT_MAX;
    else
        return -1;
    for (i = 0; i <= (*G).verNum; i++)
    {
        (*G).Edge[(*G).verNum][i] = assign;
        (*G).Edge[i][(*G).verNum] = assign;
    }
    return (*G).verNum;
}

/*
 * 判断图G是否存在边<x, y>或(x, y)。
 * */
bool Adjacent(MGraph *G,VertexType x,VertexType y)
{
    int X,Y;
    int result = -1;
    X = Locate(G,x);
    Y = Locate(G,y);
    return ( result= (*G).Edge[X][Y] == 0 ? result:-1);
}
/*
 * 列出图G中与结点x邻接的边。
 * */
void Neighbors(MGraph *G,VertexType x)
{
    int X;
    VertexType *vertexType = "";
    X = Locate(G,x);
    for (int i = X; i < (*G).verNum; i++)
    {
        if((*G).Edge[X][i] != 0 && (*G).Edge[X][i] != INT_MAX)
        {
            printf("%c",(G)->Vex[i]);
        }
    }
}
/*
 * 在图G中插入顶点x。
 * */
bool InsertVertex(MGraph *G,VertexType x)
{
    (*G).Vex[(*G).verNum] = x; // 顶点添加
    (*G).verNum++; // 顶点个数增加
    return true;
}
/*
 * 从图G中删除顶点x。 采用删除一个顶点就将所有的元素进行左移和上移动.
 * */
bool DeleteVertex(MGraph *G,VertexType x)
{
    int X = Locate(G,x);
    int assign;
    // 顶点是否存在
    if(X == -1)
        return false;
    // 确定一个非连通标记
    if((*G).graphKind == DG || (*G).graphKind == UDG)
        assign = 0;        // 图
    else if((*G).graphKind == DN || (*G).graphKind == UDN)
        assign = INT_MAX;
    else
        return -1;

    // 更新边/弧的数量
    for(int i = 0; i < (*G).verNum; i++) {
        // 如果存在从顶点v出发的边，则边的数量减一  无向图判断一行/列即可
        if((*G).Edge[X][i] != assign && (*G).Edge[X][i] != 0) {
            (*G).arcNum--;
        }

        // 如果这是有向的图/网，依然需要更新边/弧的数量  有向图行列都需要进行判断.
        if((*G).graphKind == DG || (*G).graphKind == DN) {
            // 如果存在到达顶点v的边，则边的数量减一
            if((*G).Edge[i][X] != assign) {
                (*G).arcNum--;
            }
        }
    }

    // 将邻接矩阵中的顶点关系左移
    for(int j = X + 1; j < (*G).verNum; j++) {
        for(int i = 0; i < (*G).verNum; i++) {
            (*G).Edge[i][j - 1] = (*G).Edge[i][j];    // 右边的列挪到左边的列
        }
    }

    // 将邻接矩阵中的顶点关系上移
    for(int i = X + 1; i < (*G).verNum; i++) {
        // 注:由于上面进行左移的关系，所以这里的j是小于(*G).vexNum - 1
        for(int j = 0; j < (*G).verNum - 1; j++) {
            (*G).Edge[i - 1][j] = (*G).Edge[i][j];    // 下一行挪到上一行
        }
    }

    // 将该顶点从顶点集中移除 并将顶点关系左移
    for(int i = X + 1; i < (*G).verNum; i++) {
        (*G).Vex[i - 1] = (*G).Vex[i];
    }
    (*G).verNum--;
    return true;
}
/*
 * 若无向边(x, y)或有向边<x, y>不存在，则向图G中添加该边。
 * info 值可以采用存放在数据结构中的方式
 * 思想:
 * 1.查找顶点
 * 2.判断顶点意思
 * 3.分无权和有权进行赋值
 * 4.判是否覆盖 -- 涉及边是否加1
 * 5.保证对称性
 * */
bool AddEdge(MGraph *G,VertexType x,VertexType y,int info)
{
    int X,Y;
    X = Locate(G,x);
    Y = Locate(G,y);
    if(X == -1 || Y == -1) // 顶点的位置不存在
        return false;
    if(X == Y) // 环的出现
        return false;
    if((*G).graphKind == DG || (*G).graphKind == UDG) // 无权图
    {
        // 没有产生覆盖
        if((*G).Edge[X][Y] == 0)
        {
            (*G).Edge[X][Y] = info;
            (*G).arcNum++;
        }
        // 有覆盖 - 边数不增加
        (*G).Edge[X][Y] = info;
    }
    else if((*G).graphKind == DN || (*G).graphKind == UDN) // 有权图
    {
        // 没有产生覆盖
        if((*G).Edge[X][Y] == INT_MAX)
        {
            (*G).Edge[X][Y] = info;
            (*G).arcNum++;
        }
        // 有覆盖 - 边数不增加
        (*G).Edge[X][Y] = info;
    }
    else
        return false;
    // 无向图的对称性
    if((*G).graphKind == UDG || (*G).graphKind == UDN)
        (*G).Edge[Y][X] = (*G).Edge[X][Y];
    return true;
}
/*
 * 若无向边(x,y)或有向边<x, y>存在，则从图G中删除该边。
 * 实现思想和删除一致.
 * */
bool RemoveEdge(MGraph *G,VertexType x,VertexType y)
{
    int X,Y;
    X = Locate(G,x);
    Y = Locate(G,y);
    if(X == -1 || Y == -1) // 顶点的位置不存在
        return false;
    if(X == Y) // 环的出现
        return false;
    if((*G).graphKind == DG || (*G).graphKind == UDG) // 无权图
        (*G).Edge[X][Y] = 0;
    else if((*G).graphKind == DN || (*G).graphKind == UDN)
        (*G).Edge[X][Y] = INT_MAX;
    else
        return false;
    // 无向图的对称性
    if((*G).graphKind == UDG || (*G).graphKind == UDN)
        (*G).Edge[Y][X] = (*G).Edge[X][Y];
    return true;

}
/*
 * 求图G中顶点x的第一个邻接点，若有则返回顶点号。若x没有邻接点或图中不存在x，则返回-1
 * */
int FirstNeighbor(MGraph *G,VertexType x)
{
    int X;
    X = Locate(G,x);
    if(X == -1 ) // 顶点的位置不存在
        return -1;
    // 无论是有权图或是无权图,都可以从行上找到一个顶点的第一个邻接点
    for ( int i = 0; i < (*G).verNum; i++)
    {
        if((*G).Edge[X][i] != 0 && (*G).Edge[X][i] != INT_MAX)
        {
            return i;
        }

    }
    return -1;
}
/*
 * 假设图G中顶点y是顶点x的一个邻接点，返回除y之外顶点x的下一个邻接点的顶点号，若y是x的最后一个邻接点，则返回-1。
 * */
int NextNeighbor(MGraph *G,VertexType x,VertexType y)
{
    int X,Y;
    X = Locate(G,x);
    if(X == -1 ) // 顶点的位置不存在
        return false;
    Y = Locate(G,y);
    if(Y == -1 ) // 顶点的位置不存在
        return false;
    // 从顶点Y开始查找
    for (int i = Y+1; i < (*G).verNum ; i++)
    {
        if((*G).Edge[X][i] != 0 && (*G).Edge[X][i] != INT_MAX)
            return i;
    }
    return -1;
}
/*
 * 获取图G中边(x, y)或<x, y>对应的权值。
 * */
int Get_edge_value(MGraph *G,VertexType x,VertexType y)
{
    int X,Y,res = -1;
    X = Locate(G,x);
    if(X == -1 ) // 顶点的位置不存在
        return false;
    Y = Locate(G,y);
    if(Y == -1 ) // 顶点的位置不存在
        return false;
    if((*G).Edge[X][Y] != 0 || (*G).Edge[X][Y] != INT_MAX)
        res = (*G).Edge[X][Y];
    return res;
}
/*
 * 设置图G中边(x, y)或<x, y>对应的权值为v
 * */
int Set_edge_value(MGraph *G,VertexType x,VertexType y,int info)
{
    int X,Y;
    X = Locate(G,x);
    if(X == -1 ) // 顶点的位置不存在
        return false;
    Y = Locate(G,y);
    if(Y == -1 ) // 顶点的位置不存在
        return false;
    if((*G).Edge[X][Y] == 0 || (*G).Edge[X][Y] == INT_MAX)
        (*G).Edge[X][Y] = info;
    return info;
}



/*
 * 打印边值
 * */
void Visit(MGraph G,int v)
{
    if(v <= G.verNum)
        printf("%c\n",G.Vex[v]);
}

/*
 * 广度优先
 * */
bool visited[MaxVertexNum]; //标记数组
LinkQueue LQ;
void BFSTraverse(MGraph G,int v)
{
    // 初始化访问数组
    for (int i = 0; i < G.verNum; i++)
    {
        visited[i] = false;
    }
    InitLQueue(&LQ);
    BFS(G,v);
    for (int i = 0; i < G.verNum; i++) {
        // 筛查没有访问的顶点
        if (!visited[i])
            BFS(G,i);
    }

}
void BFS(MGraph G,int v)
{

    int w;
    ElemType u;
    Visit(G,v);
    visited[v] = true;
    EnLQueue(&LQ,v); //入队
    while (!EmptyLQueue(&LQ))
    {
        DeLQueue(&LQ,&u);
        for (w = FirstNeighbor(&G,G.Vex[u]);w>=0; w = NextNeighbor(&G,G.Vex[u],G.Vex[w]))
        {
            if(!visited[w])
            {
                Visit(G,w);
                visited[w] = true;
                EnLQueue(&LQ,w);
            }
        }
    }
}

/*
 * 深度优先
 * */
void DFSTraverse(MGraph G)
{
    for (int i = 0; i < G.verNum; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < G.verNum;i++)
    {
        if(!visited[i])
            DFS(G,i);
    }
}
void DFS(MGraph G,int v)
{
    Visit(G,v);
    int w;
    visited[v] = true;
    for (w = FirstNeighbor(&G,G.Vex[v]);w>=0;w = NextNeighbor(&G,G.Vex[v],G.Vex[w]))
    {
        if(!visited[w])
            DFS(G,w);
    }
}

/*
 * 最短路径求解
 * */
int distance[MaxVertexNum];
int path[MaxVertexNum];
void BFS_MIN_Distance(MGraph G,int u)
{
    int w = 0;
    // 初始化
    LinkQueue LQ1;
    InitLQueue(&LQ1);
    for (int i = 0; i < G.verNum; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
        path[i] = -1;
    }
    distance[u] = 0;
    visited[u] = true;
    EnLQueue(&LQ1,u);
    while (!EmptyLQueue(&LQ1))
    {
        DeLQueue(&LQ1,&u);
        for (w = FirstNeighbor(&G,G.Vex[u]);w>=0;w = NextNeighbor(&G,G.Vex[u],G.Vex[w]))
        {
            if(!visited[w])
            {
                distance[w] = distance[w]+1;
                path[w] = distance[u]+1;
                visited[w] = true;
                EnLQueue(&LQ1,w);
            }
        }
    }
}