//
// Created by cxf18 on 2022/6/26.
//

#include "ChildTree.h"

void InitCTree(CTree *CT)
{
    CT->root = -1;
    CT->nodeNum = 0;
}
/*
 * 创建孩子表示法的入口函数 调用CreateCTree 通过读取文件内容来创建树结构.
 * */
bool CreateCTreeEn(CTree *CT,ElemTypeChar path[])
{
    FILE *fp;
    fp = fopen(path,"r");
    if(fp == NULL)
        return false;
//    CreateCTree(CT,fp,0);
    fclose(fp);
    return true;
}

