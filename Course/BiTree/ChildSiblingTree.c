//
// Created by cxf18 on 2022/6/27.
//

#include "ChildSiblingTree.h"
/*
 * 初始化孩子兄弟树
 * */
bool InitCSTree(CSTree *CS)
{
    if(CS == NULL)
        return false;
    (*CS) = NULL;
    return true;
}
/*
 * 孩子兄弟表示法的入口
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
 * 采用读取文件内容+递归的方式实现创建孩子兄弟树.
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
 * 计算树的深度 layer会在每一次递归中都生成一个 max是地址只有一个
 * */
void CSTreeDepth(CSTree CS,int layer,int *max)
{
    if(CS == NULL)
        return ;
    layer++; // 控制层数
    if(layer > *max)
        *max = layer;
    CSTreeDepth(CS->firstChild,layer,max); // 孩子遍历 向下
    CSTreeDepth(CS->nextSibling,layer,max); // 兄弟遍历 向右
}
/*
 * 返回指定值的结点 return NULL 为递归出口
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
 * 返回指定值的父节点.
 * */
CSTree BackCSParentNode(CSTree CS,ElemTypeChar e)
{
    return NULL;
}