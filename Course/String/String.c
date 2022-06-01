//
// Created by cxf18 on 2022/5/29.
//

#include "String.h"
//#include <string.h>
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

// 赋值
bool StrAssign(SString *T,const char *chars)
{
    if((*T).length == Maxsize-1) //满
        return false;
    int i = 0;
    while (chars[i] != '\0')
    {
        (*T).ch[i+1] = chars[i];
        if((*T).length == Maxsize-1)
        {
            return false;
            // 超过了再次分配 -- 需要考虑判满的条件--动态实现的情况下
            // (*T).ch = (char *)malloc(sizeof ((*T).ch)+Maxsize*sizeof (char));
        }
        (*T).length+=1;
        i++;
    }
    return true;
}

bool StrCopy(SString *T,const char *S)
{
    int i;
    for ( i = 0; i < (*T).length; i++) {
        (*T).ch[i+1] = S[i];
    }
    (*T).length = i-1;
    return true;
}

bool StrEmpty(SString S)
{
    if(S.length == 0)
        return true;
    else
        return false;
}

int StrLength(SString S)
{
    return S.length;
}

int ClearString(SString *S)
{
    return (*S).length = 0;;
}

bool Destroy(SString *S)
{
    (*S).length = 0;
    free(S); // 释放内存
    return true;
}

/*
// 拼接
bool ConCat(SString *T, char *S1, char *S2)
{
    (*T).ch = S1,S2;
    while (*S1 !='\0') //
        S1++;
    while (*S2 !='\0')
    {
        *(S1++) = *S2++;
    }
    return true;
}
*/

bool SubString(SString *Sub,SString S,int pos,int len)
{
    if(pos+len-1 >S.length) //超过长度
        return false;
    for (int i = pos; i <pos+len ; i++)
    {
        (*Sub).ch[i-pos+1] = S.ch[i];
    }
    (*Sub).length = len;
    (*Sub).ch[len+1] ='\0';
    return true;
}

int StrCompare(SString S,SString T)
{
    // 相等返回0;S>T返回值>0,否则小于0;
    for (int i = 1; i < S.length && i< T.length; i++)
    {
        if(S.ch[i] != T.ch[i])
            return S.ch[i]-T.ch[i]; // 返回差值
    }
    // 比较完后,length长的更大
    return S.length-T.length;
}

int Index(SString S,SString T)
{
    int i=1,j=1;
    while (i<=S.length && j<=T.length)
    {
        if(S.ch[i] == T.ch[j])
            i++,j++; // 匹配成功同步前进
        else
        {
            // 匹配失败i回到起点,j回到最初比较的点.
            i = i-j+2;
            j = 1;
        }
    }
    if(j>T.length)
        return i-T.length; //返回匹配成功的位置
    else
        return 0;
}
