//
// Created by cxf18 on 2022/7/5.
//
#include "main.h"
int main()
{
    setbuf(stdout,0);
    PressEnterToContinue(false);
    printf("@@1--next数组生成--方式1\n");
    {
        printf("开始\n");
        SStringKMP T;
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
        SStringKMP T1;
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
        SStringKMP T;
        T.ch[1] = 'a';
        T.ch[2] = 'b';
        T.ch[3] = 'c';
        T.length = 9;
        SStringKMP S;
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