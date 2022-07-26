//
// Created by cxf18 on 2022/7/26.
//

#include "ShellSort.h"
void ShellSort(int A[],int n)
{
    int dk,i,j;
    for (dk = n/2; dk >=1 ; dk = dk/2)
    {
        for (i = dk+1; i <= n ; ++i) // i的变化用于切换子表
        {
            if(A[i] <A[i-dk]) // 比较同一增量位置下的元素,选出最小.
            {
                A[0] = A[i];
                // 移动元素的位置也动态的改变j的值,j的值同时影响插入操作时的位置. j-=dk在满足j>0的情况下还会不断的先前检查同增量的元素如果小于则交换.
                for (j = i-dk; j>0 && A[0] <A[j];j-=dk)
                    A[j+dk] = A[j]; // 记录后移
                A[j+dk] = A[0]; //插入
            }
        }
    }
}