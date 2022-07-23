//
// Created by cxf18 on 2022/7/23.
//

#include "SearchSeq.h"
/*
 * 算法思想:
 * 从头到尾的挨个查找,适用于顺序表和链表.
 * 哨兵:循环时不需要判断下标是否越界.
 *
 * 优化:
 * 1.针对有序表
 * 2.按查找次数概率组成有序数组.
 *
 * 时间复杂度:O(n).
 * */
int SearchSeq(SSTable ST,ElemType key)
{
    int i;
    ST.elem[0] = key; // 哨兵
    for(i = ST.tableLen;ST.elem[i] != key;--i);
    return i;
}