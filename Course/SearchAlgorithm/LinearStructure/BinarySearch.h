//
// Created by cxf18 on 2022/7/23.
//

#ifndef DATASTRUCTURE_BINARYSEARCH_H
#define DATASTRUCTURE_BINARYSEARCH_H
typedef int ElemType;
typedef struct
{
    ElemType *elem; // ��̬����Ļ���ַ
    int tableLen;
}SeqList;
// �۰����
int BinarySearch(SeqList SL,ElemType key);
#endif //DATASTRUCTURE_BINARYSEARCH_H
