//
// Created by cxf18 on 2022/5/31.
//

#ifndef DATASTRUCTURE_KMP_H
#define DATASTRUCTURE_KMP_H
#include "Status.h"

typedef struct
{
    char ch[Maxsize];
    int length;
}SString;
// 生成next数组方法1
int* GetNext(SString T,int next[]);
// 方法2
int* GetNext2(SString T,int next[]);
// kmp算法实现
int IndexKMP(SString S,SString T, int next[]);

#endif //DATASTRUCTURE_KMP_H
