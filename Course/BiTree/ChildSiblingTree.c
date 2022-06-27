//
// Created by cxf18 on 2022/6/27.
//

#include "ChildSiblingTree.h"
/*
 * ��ʼ�������ֵ���
 * */
bool InitCSTree(CSTree *CS)
{
    if(CS == NULL)
        return false;
    (*CS) = NULL;
    return true;
}
/*
 * �����ֵܱ�ʾ�������
 * */
bool CreatCSTreeEn(CSTree *CS,ElemTypeChar path[])
{
    FILE *fp;
    fp = fopen(path,"r");
    if(fp == NULL)
        return false;
    CreatCSTree(CS,fp);
    fclose(fp);
    return true;
}
/*
 * ���ö�ȡ�ļ�����+�ݹ�ķ�ʽʵ�ִ��������ֵ���.
 * */
bool static CreatCSTree(CSTree *CS,FILE *fp)
{
    ElemTypeChar data = ' ';
    if(fp == NULL)
        return false;
    else
        fscanf(fp,"%c",&data);
    if(data == '^')
        *CS = NULL;
    else
    {
        (*CS) = (CSNode*)malloc(sizeof (CSNode));
        (*CS)->data = data;
        CreatCSTree(&(*CS)->firstChild,fp);
        CreatCSTree(&(*CS)->nextSibling,fp);
    }
    return true;
}
/*
 * ����������� layer����ÿһ�εݹ��ж�����һ�� max�ǵ�ַֻ��һ��
 * */
void CSTreeDepth(CSTree CS,int layer,int *max)
{
    if(CS == NULL)
        return ;
    layer++; // ���Ʋ���
    if(layer > *max)
        *max = layer;
    CSTreeDepth(CS->firstChild,layer,max); // ���ӱ��� ����
    CSTreeDepth(CS->nextSibling,layer,max); // �ֵܱ��� ����
}
/*
 * ����ָ��ֵ�Ľ�� return NULL Ϊ�ݹ����
 * */
CSTree BackCSNode(CSTree CS,ElemTypeChar e)
{
    CSTree pc,ps;
    if(CS == NULL)
        return NULL;
    if(CS->data == e)
        return CS;
    pc = BackCSNode(CS->firstChild,e);
    if(pc != NULL)
        return pc;
    ps = BackCSNode(CS->nextSibling,e);
    if(ps != NULL)
        return pc;
    return NULL;
}

/*
 * ����ָ��ֵ�ĸ��ڵ�.
 * */
CSTree BackCSParentNode(CSTree CS,ElemTypeChar e)
{
    return NULL;
}