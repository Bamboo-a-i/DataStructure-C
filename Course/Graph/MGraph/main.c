//
// Created by cxf18 on 2022/7/5.
//

#include "MGraph.h"
int main()
{
    setbuf(stdout,0);
    /*
     * 手动初始化很残废的操纵
     * */
    MGraph G[4] =
    {
            {
            {'A','B','C','D','E','F'},
            {
                {0,1,1,1,0,0},
                {1,0,0,0,1,1},
                {1,0,0,0,1,0},
                {1,0,0,0,0,1},
                {0,1,1,0,0,0},
                {0,1,0,1,0,0}
                },
            6,7,UDG
            },
            {
            {'A','B','C','D','E','F'},
            {
                {0,5,1,6,INT_MAX,INT_MAX},
                {5,0,INT_MAX,INT_MAX,5,4},
                {1,INT_MAX,0,INT_MAX,3,INT_MAX},
                {6,INT_MAX,INT_MAX,0,INT_MAX,2},
                {INT_MAX,3,3,INT_MAX,0,INT_MAX},
                {INT_MAX,4,INT_MAX,2,INT_MAX,0}
                },
            6,7,UDN
            },
            {
            {'A','B','C','D','E','F'},
            {
                {0,1,0,0,0,0},
                {0,0,0,0,0,0},
                {1,0,0,0,0,0},
                {1,0,0,0,0,0},
                {0,1,1,0,0,0},
                {0,1,0,1,0,0}
                },
            6,7,DG
            },
            {
            {'A','B','C','D','E','F'},
            {
                {0,5,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                {INT_MAX,0,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                {1,INT_MAX,0,INT_MAX,INT_MAX,INT_MAX},
                {6,INT_MAX,INT_MAX,0,INT_MAX,INT_MAX},
                {INT_MAX,3,3,INT_MAX,0,INT_MAX},
                {INT_MAX,4,INT_MAX,2,INT_MAX,0}
                },
            6,7,DN
            }
    };
    printf("@@1--@@找xy边是否存在\n");
    {
        // UDG
        // UDN
        // DG
        // DG
    }
    printf("@@4--@@删除顶点x\n");
    {
        // UDG
/*        DeleteVertex(&G[0],'B');
        // UDN
        DeleteVertex(&G[1],'B');
        // DG
        DeleteVertex(&G[2],'B');
        // DG
        DeleteVertex(&G[3],'B');*/
    }
    printf("@@4--@@添加边\n");
    {
/*        // UDG
        AddEdge(&G[0],'A','E',1);
        // UDN
        AddEdge(&G[1],'A','E',22);
        // DG
        AddEdge(&G[2],'A','E',1);
        // DG
        AddEdge(&G[3],'A','E',22);*/
    }
    printf("@@5--@@获取第一个邻接点\n");
    {
        // UDG
        printf("%d",FirstNeighbor(&G[0],'A'));
        // UDN
        printf("%d",FirstNeighbor(&G[1],'C'));
        // DG
        printf("%d",FirstNeighbor(&G[2],'D'));
        // DG
        printf("%d",FirstNeighbor(&G[3],'E'));
    }
    printf("@@6--@@获取下一个邻接点\n");
    {
        // UDG
        printf("%d",NextNeighbor(&G[0],'A','B'));
        // UDN
        printf("%d",NextNeighbor(&G[1],'F','B'));
        // DG
        printf("%d",NextNeighbor(&G[2],'D','A'));
        // DG
        printf("%d",NextNeighbor(&G[3],'E','B'));
    }
    printf("@@7--@@广度优先算法\n");
    {
        // UDG
        puts("--UDG");
        BFSTraverse(G[0],1);
        // UDN
        puts("--UDN");
        BFSTraverse(G[1],1);
        // DG
        puts("--DG");
        BFSTraverse(G[2],1);
        // DG
        puts("--DG");
        BFSTraverse(G[3],1);
    }
    printf("@@8--@@深度优先算法\n");
    {
        // UDG
        puts("--UDG");
        DFSTraverse(G[0]);
        // UDN
        puts("--UDN");
        DFSTraverse(G[1]);
        // DG
        puts("--DG");
        DFSTraverse(G[2]);
        // DG
        puts("--DG");
        DFSTraverse(G[3]);
    }
    printf("@@9--@@BFS最短距离算法\n");
    {
        // UDG
        puts("--UDG");
        BFS_MIN_Distance(G[0],1);
        // DG
    }
}