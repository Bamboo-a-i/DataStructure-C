//
// Created by cxf18 on 2022/5/31.
//

#ifndef DATASTRUCTURE_KMP_H
#define DATASTRUCTURE_KMP_H
#include "Status.h"
/*
 * KMP算法数据结构
 * */
typedef struct
{
    char ch[Maxsize];
    int length;
}SStringKMP;
/*
 * 操作
 * 1.生成next数组方法1
 * 2.生成next数组方法2
 * 3.Kmp实现
 * */
int* GetNext(SStringKMP T,int next[]);
int* GetNext2(SStringKMP T,int next[]);
int IndexKMP(SStringKMP S,SStringKMP T, int next[]);

#endif //DATASTRUCTURE_KMP_H
