//
// Created by cxf18 on 2022/5/31.
//

#include "KMP.h"
int main()
{
    setbuf(stdout,0);
    PressEnterToContinue(false);
    printf("@@1--next数组生成--方式1\n");
    {
        printf("开始\n");
        SString T;
        T.ch[1] = 'a';
        T.ch[2] = 'b';
        T.ch[3] = 'a';
        T.ch[4] = 'a';
        T.ch[5] = 'b';
        T.ch[6] = 'c';
        T.ch[7] = 'a';
        T.ch[8] = 'b';
        T.ch[9] = 'a';
        int next[10];
        T.length = 9;
        GetNext(T,next);
    }

    PressEnterToContinue(false);
    printf("@@2--next数组生成--方式2\n");
    {
        printf("开始\n");
        SString T1;
        T1.ch[0] = 'a';
        T1.ch[1] = 'b';
        T1.ch[2] = 'a';
        T1.ch[3] = 'a';
        T1.ch[4] = 'b';
        T1.ch[5] = 'c';
        T1.ch[6] = 'a';
        T1.ch[7] = 'b';
        T1.ch[8] = 'a';
        int next[10];
        T1.length = 9;
        GetNext2(T1,next);
    }
    PressEnterToContinue(false);
    printf("@@3--KMP算法--\n");
    {
        printf("开始\n");
        SString T;
        T.ch[1] = 'a';
        T.ch[2] = 'b';
        T.ch[3] = 'c';
        T.length = 9;
        SString S;
        S.ch[1] = 'a';
        S.ch[2] = 'b';
        S.ch[3] = 'a';
        S.ch[4] = 'a';
        S.ch[5] = 'b';
        S.ch[6] = 'c';
        S.ch[7] = 'a';
        S.ch[8] = 'b';
        S.ch[9] = 'a';
        S.length = 9;
        int next[10];
        GetNext2(T,next);
        printf("%d\n",IndexKMP(S,T,next));
    }
}
/*
 * 分析：本算法是建立在T.ch[0] 不保存数据的基础上，且next[j]对应的就是失配字符跳转的位置.
 * */
int* GetNext(SString T,int next[])
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
int * GetNext2(SString T,int next[])
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

int IndexKMP(SString S,SString T, int next[])
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