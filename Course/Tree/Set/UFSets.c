//
// Created by cxf18 on 2022/6/30.
//

#include "UFSets.h"

/*
 * 并查集这一种数据结构可以从树的角度来理解,但在实现层面可以不向树的数据结构靠,但可以借鉴其中的思想,例如双亲表示法.
 * 并查集其中主要是两大操作:查和并.
 * */

/*
 * 初始化
 * */
void InitSet(int S[])
{
    for (int i = 0; i < SIZE; i++)
    {
        S[i] = -1;
    }
}

/*
 * 创建并查集的入口
 * */
void CreateSetEn(int S[],char *path)
{
    FILE *fp = fopen(path,"r");
    if(fp == NULL)
        return;
    CreateSet(S,fp);
    fclose(fp);
}
/*
 * 通过文件内容创建并查集
 * */
void static CreateSet(int S[],FILE *fp)
{
    char data[ReadSize];
    if(fp == NULL)
        return;
    for (int i = 0; i < SIZE; i++)
    {
        // 读出数据
        fgets ( data, ReadSize,fp );
        if(data[0] != '#') // 跳过根结点
        {
            S[i] = atoi(data); // 转换为二进制
        }
        printf("data:%d\n",S[i]);
    }
}
/*
 * find 算法实现的是每次对一个结点的查找就会让这个结点最终挂载到根结点上,随着find次数不断增加,最终所有结点都将挂在根结点下.find操作也变得更容易.
 *      返回根的速度也更快.
 * */
int Find(int S[],int x) {
    int root = x;
    while (S[root] >= 0)
        root = S[root]; // 循环找到根
    while (x != root) // 压缩路径
    {
        // 指向x的父节点
        int parent = S[x];
        // 将x直接挂到根结点上
        S[x] = root;
        // 新一轮挂载开始
        x = parent;
    }
    return root;
}
/*
 * union操纵是一个在不断合并中优化的操作,如果需要测试数据建议初始都为-1.
 * */
void Union(int S[],int Root1,int Root2)
{
    // 根相同
    if(Root1 == Root2)
        return;
    // 按照规则发展,未合并的集合会指向一个结点那就是-1,所以在最初的建立过程中会出现增加的负值而这个负值的绝对值恰好是结点总数.
    // 推断此处的大于正好说明了一棵树的结点数小.
    // 进一步还需要考虑高度问题,高度问题在我们每次进行Find操作时其实已经解决了高度的问题,再不断的find和union过程中最后都会指向唯一根结点,
    // 那么自然每次的union会如我们上面推论进行发展.
    if(S[Root2] >S[Root1])
    {
        S[Root1] += S[Root2]; // 累计结点总数
        S[Root2] = Root1; // 小树合并到大树
    }
    // else 触发的条件是 两个根的结点数一致 或者 root1 大于root2
    // 每次触发,都会使得根结点的值变小,结点数增加.
    else
    {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}