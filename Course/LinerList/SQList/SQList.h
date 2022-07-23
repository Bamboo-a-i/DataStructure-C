//
// Created by cxf18 on 2022/7/14.
//

#ifndef DATASTRUCTURE_SQLIST_H
#define DATASTRUCTURE_SQLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define InitSize 5
#define Maxsize 20

typedef struct
{
    int data[Maxsize];
    int length;
}Static_Sqlist;

void ListInit(Static_Sqlist *list);
bool ListInsert(Static_Sqlist *list,int value,int fake_index);
bool ListDelete(Static_Sqlist *list,int fake_index);
void PrintList(Static_Sqlist *list);
bool GetElem(Static_Sqlist *list,int fake_index);
bool LocateElem(Static_Sqlist *list,int value);


typedef struct
{
    int *data;
    int length,maxsize;
}Dynaminc_Sqlist;

void IncreaseSize(Dynaminc_Sqlist *list,int len);
void PrintList(Dynaminc_Sqlist *list);
void InitList(Dynaminc_Sqlist *list);
bool InsertList(Dynaminc_Sqlist *list,int value,int fake_index);
bool DeleteList(Dynaminc_Sqlist *list,int fake_index);
bool GetElem(Dynaminc_Sqlist *list,int fake_index);
bool LocateElem(Dynaminc_Sqlist *list,int value);
#endif //DATASTRUCTURE_SQLIST_H
