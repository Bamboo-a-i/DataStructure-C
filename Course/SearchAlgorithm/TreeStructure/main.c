//
// Created by cxf18 on 2022/7/23.
//

#include "BinarySearchTree.h"
#include "stdio.h"
int main()
{
    printf("@@1--二叉排序树操作");
    {
        BSTree T,resT;
        int keys[] = {50,66,60,26,21,30,70,68};
        BSTBuild(&T,keys,8);
        resT = BSTSearch(T,66);
        printf("addr:%p;key:%d\n",resT,resT->key);
        resT = BSTSearchD(T,11);
        printf("addr:%p;key:%d\n",resT,resT->key);
    }
}