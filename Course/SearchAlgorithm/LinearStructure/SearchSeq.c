//
// Created by cxf18 on 2022/7/23.
//

#include "SearchSeq.h"
/*
 * �㷨˼��:
 * ��ͷ��β�İ�������,������˳��������.
 * �ڱ�:ѭ��ʱ����Ҫ�ж��±��Ƿ�Խ��.
 *
 * �Ż�:
 * 1.��������
 * 2.�����Ҵ������������������.
 *
 * ʱ�临�Ӷ�:O(n).
 * */
int SearchSeq(SSTable ST,ElemType key)
{
    int i;
    ST.elem[0] = key; // �ڱ�
    for(i = ST.tableLen;ST.elem[i] != key;--i);
    return i;
}