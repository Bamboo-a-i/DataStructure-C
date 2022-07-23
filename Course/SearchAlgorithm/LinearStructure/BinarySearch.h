//
// Created by cxf18 on 2022/7/23.
//

#ifndef DATASTRUCTURE_BINARYSEARCH_H
#define DATASTRUCTURE_BINARYSEARCH_H
typedef int ElemType;
typedef struct
{
    ElemType *elem; // 动态数组的基地址
    int tableLen;
}SeqList;
// 折半查找
int BinarySearch(SeqList SL,ElemType key);
#endif //DATASTRUCTURE_BINARYSEARCH_H
