//
// Created by cxf18 on 2022/7/26.
//

#include "BinaryInsert.h"

/*
 * 算法思想:
 * 通过对一个无序表从头开始采用折半的方式进行查找,定位无序元素插入的坐标位置,在通过外部的for循环实现元素的移动.
 *
 * 其中我们需要关注low 和 high 的变化,
 * low的升高说明表中一直处于一种有序的状态,等待由自己升高达到结束循环条件,也不会实现元素的移动.
 * high的降低说明表中出现了一个无序元素,降低过程就是定位这个元素的过程.,等待由自己降低达到结束循环条件,也不会实现元素的移动.
 *
 * 以上的low和high的变化只是一个总体的趋势.
 * */
void BinaryInsert(int A[],int n)
{
    int i,j,low,high,mid;
    for (i = 2; i <= n ; ++i)
    {
        A[0] = A[i];
        low = 1;high = i-1;
        while (low <= high)
        {
            mid = (low + high)/2;
            if(A[mid] > A[0])
                high = mid - 1; // 查询左子表
            else
                low = mid + 1; // 查询右子表
        }
        for (j = i-1;  j >= high+1 ; --j)
            A[j+1] = A[j];
        A[high+1] = A[0];
    }
    A[0] = 0;
}