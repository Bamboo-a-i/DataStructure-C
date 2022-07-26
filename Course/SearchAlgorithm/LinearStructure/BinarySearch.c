//
// Created by cxf18 on 2022/7/23.
//
#include "BinarySearch.h"
/*
 * 算法思想:
 * 通过不断的和key比较进而不断缩小查询范围.二分体现在自己找的元素在mid的左或右.
 * 二分(折半)只适用于有序的表.
 *
 * 可以通过二分查找生成查找判定树(唯一的)==>根据树高可以推出二分的查找效率为 O(log2n).
 *
 * */
int BinarySearch(SeqList SL,ElemType key)
{
    int low =0;
    int high = SL.tableLen-1;
    int mid;
    while (low <= high)
    {
        mid = (low +high)/2;
        if(SL.elem[mid] == key)
            return mid;
        else if(SL.elem[mid] >key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}