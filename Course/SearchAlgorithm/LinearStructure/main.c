//
// Created by cxf18 on 2022/7/23.
//
#include "SearchSeq.h"
#include "stdio.h"
#include "stdlib.h"
#include "BinarySearch.h"
#include "BlockSearch.h"
int main()
{

    printf("@@1--À≥–Ú≤È’“\n");
    {
        int i = 0;
        int nums[11] = {0,10,13,16,19,29,32,33,37,41,43};
        SSTable ssTable;
        ssTable.elem = nums;
        ssTable.tableLen = 10;
        i = SearchSeq(ssTable,10);
        printf("res = %d\n",nums[i]);
    }
    printf("@@2--’€∞Î≤È’“\n");
    {
        int i = 0;
        int nums[11] = {7,10,13,16,19,29,32,33,37,41,43};
        SeqList seqList;
        seqList.elem = nums;
        seqList.tableLen = 11;
        BinarySearch(seqList,11);
    }
    printf("@@3--∑÷øÈ≤È’“\n");
    {
        int i = 0;
        ElemType list[14]= {7,10,13,19,16,20,27,22,30,40,36,43,50,48};
        Index index[5] = {{10,0,1},{20,2,5},{30,6,8},{40,9,10},{50,11,13}};
        i = SSBlockSearch(index,list,48);
        i = SBBlockSearch(index,list,19);
        printf("%d\n",i);
    }
}
