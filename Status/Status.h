//
// Created by cxf18 on 2022/5/23.
//

#ifndef DATASTRUCTURE_STATUS_H
#define DATASTRUCTURE_STATUS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* 全局变量*/
typedef  int ElemType;
typedef char ElemTypeChar;
#define Maxsize 10 // 线性表
#define SIZE 13 // 并查集
#define MAX_TREE_SIZE 100 // 树
#define ReadSize 5 // 读文件
/* 全局变量*/
extern bool debug;   // 是否使用debug模式
/*
 * 摁下回车键以继续运行。
 *
 * 通常在测试阶段时，需要让每一步测试都暂停下来，以观察其输出，此时可以让debug=TRUE。
 * 在发布时，可以让debug=FALSE，此时各个测试块将不会暂停。
 */
void PressEnterToContinue(bool debug);
/*
 * 获取第一个字符的处理函数
 *
 * */
char GetFirst(void);
#endif //DATASTRUCTURE_STATUS_H
