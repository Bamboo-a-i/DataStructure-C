//
// Created by cxf18 on 2022/7/10.
//

#include "ALGraph.h"
/*
 * 查询位置
 * */
int Locate(ALGraph *G,VertexType x)
{
    for (int i = 0; i < (*G).vexNum; i++)
    {
        if((*G).vertices[i].data == x )
            return i;
    }
    return -1;
}
/*
 * 找到最后一个结点
 * */
ArcNode FindLast(ArcNode *arcNode)
{
    if(arcNode->next == NULL)
        return *arcNode;
    else
        return FindLast(arcNode->next);
}
/*
 * 四种类型图的创建
 * */
void CreateAlGraph(ALGraph *G,GraphKind graphKind)
{
    (*G).vexNum = 0;
    (*G).arcNum = 0;
    for (int i = 0; i < MaxVertexNum; i++)
    {
        (*G).vertices[i].data = 0;
        (*G).vertices[i].first = NULL;
    }
    switch (graphKind)
    {
        case UDG:
            (*G).graphKind = UDG;
            break;
        case UDN:
            (*G).graphKind = UDN;
            break;
        case DG:
            (*G).graphKind = DG;
            break;
        case DN:
            (*G).graphKind = DN;
            break;
        default:
            break;
    }
}
/*
 * 判断是否存在
 * */
bool AdjacentByIndex(ALGraph *G,int x,int y)
{
    ArcNode *p = (*G).vertices[x].first;
    while (true)
    {
        if(p == NULL)
            return false;
        if(p->adjvex == y)
            return true;
        else
            p = p->next;
    }
}
/*
 * 插入顶点
 * */
bool InsertVertex(ALGraph *G,VertexType x) {

    int X;
    X = Locate(G, x);
    // 不存在
    if (X == -1)
    {
        (*G).vertices[(*G).vexNum].data = x;
        (*G).vertices[(*G).vexNum].first = NULL;
        (*G).vexNum++;
    }
    else
        return false;
    return true;
}
/*
 * 删除顶点
 * */
bool DeleteVertex(ALGraph *G,VertexType x)
{
    int X,i;
    X = Locate(G,x);
    // 不存在
    if(X == -1)
        return false;
    // 遍历删除.
    for ( i = 0; i < (*G).vexNum; i++)
    {
        ArcNode *p = (*G).vertices[i].first;
        ArcNode *q;
        while (true)
        {
            if(p == NULL)
            {
                break;
            }
            // 处理删除最后一个元素
            if(p->next == NULL)
            {
                q = p;
                (*G).vertices[X].tail = q;
            }
            if(p->adjvex == X)
            {
                ArcNode *del = p->next;
                if(del == NULL)
                {
                    q = NULL;
                    free(del);
                    break;
                }
                p->next = del->next;
                p->adjvex = del->adjvex;
                p->info = del->info;
                free(del);
                puts("删除成功");
                (*G).arcNum--;
                return true;
            }
            if(p->adjvex > X)
                p->adjvex--;
            p = p->next;
        }
    }
    // 删除数组中的元素位置
    for ( i = X; i < (*G).vexNum; i++)
    {
        (*G).vertices[X] = (*G).vertices[X+1];
    }
    (*G).vexNum--;
    return true;
}
/*
 * 添加边 通过记录尾部的方式来实现每次的添加边。
 * */
bool AddEdge(ALGraph *G,VertexType x,VertexType y,int info)
{
    int X,Y;
    // 取顶点对应对的XY数组下标
    X = Locate(G,x);
    Y = Locate(G,y);
    // 判断可拆解分别输出不同的错误信息.
    if(X == -1 || Y == -1 || X == Y)
        return false;
    // 边是否已经存在
    if(!AdjacentByIndex(G,X,Y))
    {
        // 第一个元素添加
        if((*G).vertices[X].first == NULL)
        {
            ArcNode *p = (ArcNode *) malloc(sizeof (ArcNode));
            p->adjvex = Y;
            p->next = NULL;
            p->info = info;
            (*G).vertices[X].first = p;
            (*G).arcNum++;
            (*G).vertices[X].tail = p; // 记录尾部
        }
        else
        {
            ArcNode *p = (ArcNode *) malloc(sizeof (ArcNode));
            p->next = NULL;
            p->adjvex = Y;
            p->info =info;
            (*G).vertices[X].tail->next = p;
            (*G).vertices[X].tail = p;
        }
    }
    else
        return false;
    (*G).arcNum++;
    return true;
}
/*
 * 移除一条边
 * */
bool RemoveEdge(ALGraph *G,VertexType x,VertexType y)
{
    int X,Y;
    // 取顶点对应对的XY数组下标
    X = Locate(G,x);
    Y = Locate(G,y);
    // 判断可拆解分别输出不同的错误信息.
    if(X == -1 || Y == -1 || X == Y)
        return false;
    if(AdjacentByIndex(G,X,Y))
    {
        ArcNode *p = (*G).vertices[X].first;
        ArcNode *q;
        while (true)
        {
            if(p == NULL)
            {
                puts("第一个顶点出错");
                return false;
            }
            if(p->adjvex == Y)
            {
                ArcNode *del = p->next;
                if(del == NULL)
                {
                    free(p);
                    (*G).vertices[X].tail = NULL;
                    (*G).vertices[X].first = NULL;
                    break;
                }
                p->next = del->next;
                p->adjvex = del->adjvex;
                p->info = del->info;
                if(p->next == NULL)
                    (*G).vertices[X].tail = p;
                free(del);
                puts("删除成功");
                (*G).arcNum--;
                return true;
            }
            // 处理删除最后一个元素
            if(p->next == (*G).vertices[X].tail)
            {
                q = p;
                (*G).vertices[X].tail = q;
            }
            p = p->next;

        }
    }
    else
    {
        puts("边不存在!");
        return false;
    }

}