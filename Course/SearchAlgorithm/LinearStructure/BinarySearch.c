//
// Created by cxf18 on 2022/7/23.
//
#include "BinarySearch.h"
/*
 * �㷨˼��:
 * ͨ�����ϵĺ�key�ȽϽ���������С��ѯ��Χ.�����������Լ��ҵ�Ԫ����mid�������.
 * ����(�۰�)ֻ����������ı�.
 *
 * ����ͨ�����ֲ������ɲ����ж���(Ψһ��)==>�������߿����Ƴ����ֵĲ���Ч��Ϊ O(log2n).
 *
 * */
int BinarySearch(SeqList SL,ElemType key)
{
    int low =0;
    int high = SL.tableLen-1;
    int mid;
    while (low <= high)
    {
        mid = (low +high)/2;
        if(SL.elem[mid] == key)
            return mid;
        else if(SL.elem[mid] >key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}