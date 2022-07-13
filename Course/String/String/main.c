//
// Created by cxf18 on 2022/7/5.
//
#include "main.h"
int main()
{
    setbuf(stdout,0);
    SString S;
    S.ch[0] = '\0';
    // 初始化过程
    // S.ch = (char *) malloc(Maxsize*sizeof (char)); 动态数组初始化
    S.length = 0;
    char *chars = "ababcca";
    PressEnterToContinue(false);
    printf("@@1--赋值\n");
    {
        printf("开始\n");
        StrAssign(&S,chars);
        printf("e:%s",S.ch);
    }
    PressEnterToContinue(false);
    printf("@@2--复制\n");
    {
        chars = "111122";
        printf("开始\n");
        StrCopy(&S,chars);
        printf("e:%s",S.ch);
    }
    PressEnterToContinue(false);
    printf("@@3--判空\n");
    {
        printf("开始\n");
        printf("e:%d\n",StrEmpty(S));
    }
    PressEnterToContinue(false);
    printf("@@4--求长\n");
    {
        printf("开始\n");
        printf("e:%d\n",StrLength(S));
    }
    PressEnterToContinue(false);
    printf("@@5--清空\n");
    {
        printf("开始\n");
        printf("e:%d",ClearString(&S));
    }
    PressEnterToContinue(false);
    printf("@@6--销毁\n");
    {
        printf("开始\n");
        //printf("e:%d",Destroy(&S));
    }
    PressEnterToContinue(false);
    printf("@@7--串接\n");
    {
        printf("开始\n");
        // printf("e:%s\n",ConCat(&S,"111","222"));
    }
    PressEnterToContinue(false);
    printf("@@8--求子串\n");
    {
        printf("开始\n");
        SString sub;
        SString S1;
        sub.length = 0;
        sub.ch[0] = '\0';
        StrAssign(&S1,"aaabbbccc");
        SubString(&sub,S1,1,3);
        printf("e:%s\n",sub.ch);
    }
    PressEnterToContinue(false);
    printf("@@9--求子串\n");
    {
        printf("开始\n");
        SString S1,S2;
        S1.length=S2.length = 0;
        S1.ch[0] = S2.ch[0] = '\0';
        StrAssign(&S1,"aaabbbccc");
        StrAssign(&S2,"aaabbbdcc");
        printf("e:%d\n", StrCompare(S1,S2));
    }
    PressEnterToContinue(false);
    printf("@@10--匹配字符\n");
    {
        printf("开始\n");
        SString S1,S2;
        S1.length=S2.length = 0;
        S1.ch[0] = S2.ch[0] = '\0';
        StrAssign(&S1,"aaababccc");
        StrAssign(&S2,"bab");
        printf("e:%d\n", Index(S1,S2));
    }
}