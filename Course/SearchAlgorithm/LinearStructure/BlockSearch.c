//
// Created by cxf18 on 2022/7/23.
//

#include "BlockSearch.h"
#include "stdio.h"
/*
 *  算法思想:
 *  将查找表分为若干则快,遵循块间有序块内无序(因此有了不同的查找方式)的原则.第一块中的最大关键字小于第二块中的所有记录关键字,一次类推
 *  从而建立一个索引表,表中记录块中最大的关键字值和这个块的开始结束下标.
 *
 * */


// 索引和列表均采用顺序查找的方式.
int SSBlockSearch(Index *index,const ElemType *list,ElemType key)
{
    int i,j;
    for (i = 0; i < 5 && index[i].maxValue < key; ++i); // 跳出循环时-->对应分块
    for (j = index[i].low; j < index[i].high && list[j] != key ; ++j); // 跳出-->对应值
    return (j<index[5].high)?j:-1;
}
// 索引折半列表顺序
int SBBlockSearch(Index *index,const ElemType *list,ElemType key)
{
    int i,high,low,mid;
    low = 0;
    high = 4;
    while (1)
    {
        mid = (low +high)/2;
        if(index[mid].maxValue == key)
            break;
        else if(index[mid].maxValue > key)
            high = mid -1;
        else
            low = mid +1;
        if(low >high) // 出现了low 大于high的情况表示,low左边的一定小于目标关键字,high右边一定大于目标关键字.
        {
            mid = low;
            break;
        }
    }
    for (i = index[mid].low; i < index[mid].high && list[i] != key ; ++i); // 跳出-->对应值
    return (i<index[5].high)?i:-1;
}