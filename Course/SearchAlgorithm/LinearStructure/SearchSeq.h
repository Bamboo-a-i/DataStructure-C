//
// Created by cxf18 on 2022/7/23.
//

#ifndef DATASTRUCTURE_SEARCHSEQ_H
#define DATASTRUCTURE_SEARCHSEQ_H

// ˳��������ݽṹ
typedef int ElemType;
typedef struct
{
    ElemType *elem; // ��̬����Ļ���ַ
    int tableLen;
}SSTable;

// ˳������㷨ʵ��
int SearchSeq(SSTable ST,ElemType key);

#endif //DATASTRUCTURE_SEARCHSEQ_H
