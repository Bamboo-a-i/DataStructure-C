//
// Created by cxf18 on 2022/7/23.
//

#ifndef DATASTRUCTURE_SEARCHSEQ_H
#define DATASTRUCTURE_SEARCHSEQ_H

// 顺序查找数据结构
typedef int ElemType;
typedef struct
{
    ElemType *elem; // 动态数组的基地址
    int tableLen;
}SSTable;

// 顺序查找算法实现
int SearchSeq(SSTable ST,ElemType key);

#endif //DATASTRUCTURE_SEARCHSEQ_H
