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
// ����next���鷽��1
int* GetNext(SString T,int next[]);
// ����2
int* GetNext2(SString T,int next[]);
// kmp�㷨ʵ��
int IndexKMP(SString S,SString T, int next[]);

#endif //DATASTRUCTURE_KMP_H
