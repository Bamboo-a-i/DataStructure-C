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
 * �������ӱ�ʾ������ں��� ����CreateCTree ͨ����ȡ�ļ��������������ṹ.
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

