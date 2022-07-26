//
// Created by cxf18 on 2022/7/26.
//

#include "InsertSort.h"
#include "BinaryInsert.h"
#include "ShellSort.h"
#include "stdio.h"
int main()
{
    int A[] = {43,56,78,23,11,31,40,91,76,25};
    int AS[] = {0,49,38,65,97,76,13,27,49,55,04};
    printf("@@1--直接插入排序.\n");
    {
        InsertSort(A,10);
        //InsertSortWS(AS,9);
    }
    printf("@@2--折半插入排序.\n");
    {
        //BinaryInsert(AS,11);
    }
    printf("@@3--希尔排序.\n");
    {
        ShellSort(AS,10);
    }
}