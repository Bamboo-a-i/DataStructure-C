//
// Created by cxf18 on 2022/7/23.
//

#include "BlockSearch.h"
#include "stdio.h"
/*
 *  �㷨˼��:
 *  �����ұ��Ϊ�������,��ѭ��������������(������˲�ͬ�Ĳ��ҷ�ʽ)��ԭ��.��һ���е����ؼ���С�ڵڶ����е����м�¼�ؼ���,һ������
 *  �Ӷ�����һ��������,���м�¼�������Ĺؼ���ֵ�������Ŀ�ʼ�����±�.
 *
 * */


// �������б������˳����ҵķ�ʽ.
int SSBlockSearch(Index *index,const ElemType *list,ElemType key)
{
    int i,j;
    for (i = 0; i < 5 && index[i].maxValue < key; ++i); // ����ѭ��ʱ-->��Ӧ�ֿ�
    for (j = index[i].low; j < index[i].high && list[j] != key ; ++j); // ����-->��Ӧֵ
    return (j<index[5].high)?j:-1;
}
// �����۰��б�˳��
int SBBlockSearch(Index *index,const ElemType *list,ElemType key)
{
    int i,high,low,mid;
    low = 0;
    high = 4;
    while (1)
    {
        mid = (low +high)/2;
        if(index[mid].maxValue == key)
            break;
        else if(index[mid].maxValue > key)
            high = mid -1;
        else
            low = mid +1;
        if(low >high) // ������low ����high�������ʾ,low��ߵ�һ��С��Ŀ��ؼ���,high�ұ�һ������Ŀ��ؼ���.
        {
            mid = low;
            break;
        }
    }
    for (i = index[mid].low; i < index[mid].high && list[i] != key ; ++i); // ����-->��Ӧֵ
    return (i<index[5].high)?i:-1;
}