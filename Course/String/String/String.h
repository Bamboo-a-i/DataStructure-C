//
// Created by cxf18 on 2022/5/29.
//

#ifndef DATASTRUCTURE_KMP_H
#define DATASTRUCTURE_KMP_H
#include "Status.c"
#endif //DATASTRUCTURE_KMP_H
/*
 * 统一使用静态数组实现,且S.ch[0] = '\0'
 * */

/*
 * 静态数组数据结构
 * */
typedef struct
{
    char ch[Maxsize];
    int length;
}SString;

/*
 * 动态数组数据结构
 * */
typedef struct
{
    char *ch;
    int length;
}HString;

/*
 * 链式存储数据结构1--存储密度较低
 * */
typedef struct StringNode
{
    char ch;
    struct StringNode *next;
}StringNode,*String;
/*
 * 链式存储数据结构2--提高存储密度
 * */
typedef struct StringNode1
{
    char ch[4];
    struct StringNode1 *next;
}StringNode1,*String1;

/*
 * 操作
 * 1.赋值
 * 2.复制
 * 3.判空
 * 4.长度
 * 5.清空
 * 6.销毁
 * 7.拼接
 * 8.求子串
 * 9.比较操作
 * 10.查找相同的字符串朴素模式匹配法
 * */

bool StrAssign(SString *T,const char *chars);
bool StrCopy(SString *T,const char *S);
bool StrEmpty(SString S);
int StrLength(SString S);
int ClearString(SString *S);
bool Destroy(SString *S);
bool ConCat(SString *T, char *S1, char *S2);
bool SubString(SString *Sub,SString S,int pos,int len);
int StrCompare(SString S,SString T);
int Index(SString S,SString T);
