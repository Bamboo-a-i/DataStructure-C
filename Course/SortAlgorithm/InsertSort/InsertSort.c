//
// Created by cxf18 on 2022/7/26.
//

#include "InsertSort.h"

// 直接插入排序
void InsertSort(int A[],int n)
{
    int i,j,temp;
    for (i = 1; i < n ; ++i)
    {
        if(A[i] < A[i-1])
        {
            temp = A[i]; // 保存较小前驱
            for (j = i-1;  j >=0 && A[j] > temp; --j) // 将大于temp的元素进行后移
                A[j+1] = A[j];
            A[j+1] = temp; // 复制到插入位置
        }
    }
}

// 带有哨兵式插入排序
void InsertSortWS(int A[],int n)
{
    int i,j;
    for (i = 2; i <= n; ++i)
    {
        if(A[i] < A[i-1])
        {
            A[0] = A[i];
            for (j = i-1;A[j] > A[0];--j)
                A[j+1] = A[j];
            A[j+1] = A[0];
        }
    }
    A[0] = 0;
}