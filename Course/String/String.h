//
// Created by cxf18 on 2022/5/29.
//

#ifndef DATASTRUCTURE_KMP_H
#define DATASTRUCTURE_KMP_H
#include "Status.c"
#endif //DATASTRUCTURE_KMP_H
// ͳһʹ�þ�̬����ʵ��,��S.ch[0] = '\0';
typedef struct
{
    char ch[Maxsize];
    int length;
}SString; // ��̬����

typedef struct
{
    char *ch;
    int length;
}HString; // ��̬����

typedef struct StringNode
{
    char ch;
    struct StringNode *next;
}StringNode,*String;// ��ʽ�洢 �洢�ܶȽϵ�

typedef struct StringNode1
{
    char ch[4];
    struct StringNode1 *next;
}StringNode1,*String1; // �ṩ�洢�ܶ�

// ��ֵ
bool StrAssign(SString *T,const char *chars);
// ����
bool StrCopy(SString *T,const char *S);
// �п�
bool StrEmpty(SString S);
// ����
int StrLength(SString S);
// ���
int ClearString(SString *S);
// ����
bool Destroy(SString *S);
// ƴ��
bool ConCat(SString *T, char *S1, char *S2);
// ���Ӵ�
bool SubString(SString *Sub,SString S,int pos,int len);
// �Ƚϲ���
int StrCompare(SString S,SString T);
// ������ͬ���ַ�������ģʽƥ�䷨)
int Index(SString S,SString T);
// ����next����
void GetNext(SString T,int next[]);
