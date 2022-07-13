//
// Created by cxf18 on 2022/5/31.
//

#include "KMP.h"

/*
 * 分析：本算法是建立在T.ch[0] 不保存数据的基础上，且next[j]对应的就是失配字符跳转的位置.
 * */
int* GetNext(SStringKMP T,int next[])
{
    int i = 1; // 后缀末尾
    int j = 0; // 前缀末尾
    next[1] = 0;
    while (i < T.length)
    {
        if(j == 0 || T.ch[i] == T.ch[j])
        {
            i++,j++;
            next[i] = j;
            printf("next[%d] = %d\n",i,j);
        }
        else
        {
            j = next[j];
        }
    }
    return next;
}

/*
 * 分析：本算法是建立在T.ch[0]保存数据的基础上，且next[j-1]对应的是失配字符跳转的位置.
 * */
int * GetNext2(SStringKMP T,int next[])
{
    // 初始化
    int i;
    int j = 0;
    next[0] = 0;
    for ( i = 1; i < T.length ; i++)
    {
        // 开始处理不相等
        while(j > 0 && T.ch[i] != T.ch[j])
        {
            j = next[j-1];
        }
        // 处理相等
        if(T.ch[i] == T.ch[j])
        {
            j++;
        }
        // 更新next数组表
        next[i] = j;
        printf("next[%d] = %d\n",i,j);
    }
    return next;
}

int IndexKMP(SStringKMP S,SStringKMP T, int next[])
{
    int j = 1; // 主串指针
    int i = 1; // 模式串指针
    while (i<S.length && j<T.length) {
        if (j == 0 || T.ch[j] == S.ch[i])
            ++j, ++i;
        else
            j = next[j];
    }
    if(j > T.length)
        return i - T.length;
    else
        return 0;

}