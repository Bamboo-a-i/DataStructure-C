//
// Created by cxf18 on 2022/5/29.
//

#include "String.h"

/*
 * 赋值
 * */
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
/*
 * 字符串复制
 * */
bool StrCopy(SString *T,const char *S)
{
    int i;
    for ( i = 0; i < (*T).length; i++) {
        (*T).ch[i+1] = S[i];
    }
    (*T).length = i-1;
    return true;
}

/*
 * 判空
 * */
bool StrEmpty(SString S)
{
    if(S.length == 0)
        return true;
    else
        return false;
}

/*
 * 字符长度
 * */
int StrLength(SString S)
{
    return S.length;
}

/*
 * 清空字符串
 * */
int ClearString(SString *S)
{
    return (*S).length = 0;;
}

/*
 * 销毁
 * */
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

/*
 * 截取字符串
 * */
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

/*
 * 字符串比较
 * */
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

/*
 * 串的模式匹配(暴力算法)
 * */
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
