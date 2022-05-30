//
// Created by cxf18 on 2022/5/29.
//

#ifndef DATASTRUCTURE_KMP_H
#define DATASTRUCTURE_KMP_H
#include "Status.c"
#endif //DATASTRUCTURE_KMP_H
// 统一使用静态数组实现,且S.ch[0] = '\0';
typedef struct
{
    char ch[Maxsize];
    int length;
}SString; // 静态数组

typedef struct
{
    char *ch;
    int length;
}HString; // 动态数组

typedef struct StringNode
{
    char ch;
    struct StringNode *next;
}StringNode,*String;// 链式存储 存储密度较低

typedef struct StringNode1
{
    char ch[4];
    struct StringNode1 *next;
}StringNode1,*String1; // 提供存储密度

// 赋值
bool StrAssign(SString *T,const char *chars);
// 复制
bool StrCopy(SString *T,const char *S);
// 判空
bool StrEmpty(SString S);
// 长度
int StrLength(SString S);
// 清空
int ClearString(SString *S);
// 销毁
bool Destroy(SString *S);
// 拼接
bool ConCat(SString *T, char *S1, char *S2);
// 求子串
bool SubString(SString *Sub,SString S,int pos,int len);
// 比较操作
int StrCompare(SString S,SString T);
// 查找相同的字符串朴素模式匹配法)
int Index(SString S,SString T);
// 生成next数组
void GetNext(SString T,int next[]);
