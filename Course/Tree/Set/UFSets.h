//
// Created by cxf18 on 2022/6/30.
//

#ifndef DATASTRUCTURE_UFSETS_H
#define DATASTRUCTURE_UFSETS_H
#include "Status.h"

/*
 * 基础操作
 * 1.创建集合入口
 * 2.创建
 * 3.初始化
 * 4.查
 * 5.并
 * */
void CreateSetEn(int S[],char *path);
void static CreateSet(int S[],FILE *fp);
void InitSet(int S[]);
int Find(int S[],int x);
void Union(int S[],int Root1,int Root2);
#endif //DATASTRUCTURE_UFSETS_H
