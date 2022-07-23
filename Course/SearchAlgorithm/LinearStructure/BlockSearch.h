//
// Created by cxf18 on 2022/7/23.
//

#ifndef DATASTRUCTURE_BLOCKSEARCH_H
#define DATASTRUCTURE_BLOCKSEARCH_H
typedef int ElemType;
// 分块索引结构
typedef struct
{
    ElemType maxValue; // 分块中的最大值
    int low,high; // 索引
}Index;



// 索引和列表全部采用顺序查找
int SSBlockSearch(Index *index,const ElemType *list,ElemType key);
// 索引采用折半查找列表采用顺序查找
int SBBlockSearch(Index *index,const ElemType *list,ElemType key);
#endif //DATASTRUCTURE_BLOCKSEARCH_H
