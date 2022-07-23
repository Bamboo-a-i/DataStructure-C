//
// Created by cxf18 on 2022/7/23.
//

#ifndef DATASTRUCTURE_BLOCKSEARCH_H
#define DATASTRUCTURE_BLOCKSEARCH_H
typedef int ElemType;
// �ֿ������ṹ
typedef struct
{
    ElemType maxValue; // �ֿ��е����ֵ
    int low,high; // ����
}Index;



// �������б�ȫ������˳�����
int SSBlockSearch(Index *index,const ElemType *list,ElemType key);
// ���������۰�����б����˳�����
int SBBlockSearch(Index *index,const ElemType *list,ElemType key);
#endif //DATASTRUCTURE_BLOCKSEARCH_H
