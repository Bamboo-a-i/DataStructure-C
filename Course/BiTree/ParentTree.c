//
// Created by cxf18 on 2022/6/23.
//
#include "ParentTree.h"
/*
 * ��ʼ����
 * */
void InitParentTree(PTree *PT)
{
    for (int i = 0; i < MAX_TREE_SIZE; i++)
    {
        PT->nodes[i].data = '#'; // ��ʼÿһ��Ԫ�ص�ֵΪ'#' ָ��Ϊ-1
        PT->nodes[i].parent = -1;
    }
    PT->nodeNum = 0; // ��ʼ������ֵΪ0
}

/*
 * ������������ļ������򿪵��ļ�ָ�봫��������������
 * */
void CreateParentTreeEn(PTree *PT, ElemTypeChar *path)
{
    FILE *fp = fopen(path,"r"); // ��ģʽ��
    if(fp == NULL)
        return;
    CreatParentTree(PT,fp);
    fclose(fp);
}
/*
 * �ֱ��ȡdataֵ�͸��ڵ�ֵ���Ը��ڵ�ֵ����ǿתΪint��ͬʱ��Ҫ�����ַ� - �� # �����������������ڵ�ͽ�β�ġ�
 * �������д����ڵ�ֵ�Ļ�ȡ�Ƚϴֲ�ֻ�ʺ�parent<10�ķ�Χ
 * ֻ��������ʹ�� �����ظ�����(C���Դ����ַ���ĺ��� �ļ�����Ҳ���鷳)
 * */
void static CreatParentTree(PTree *PT,FILE *fp)
{
    ElemTypeChar data = ' ',parent = ' ';
    int index = 0;
    if(fp == NULL)
        return;
    while (PT->nodeNum < MAX_TREE_SIZE - 1)
    {
        fscanf(fp,"%c",&data);
        fscanf(fp,"%c",&parent);
        PT->nodes[index].data = data; // ��ֵ���ֵ
        if(data == '#') // ������β
            break;
        if(parent != '-') // �������ڵ�
            PT->nodes[index].parent = (int)parent-48; // ��ֵ���ڵ�
        PT->nodeNum++; // ���������1
        index++; // ����
    }
}

/*
 * ������
 * ����:˫�׽���� PT ˫�׽��ptNode
 * ����:������CreateParentTree �е��������в������ ����ʱ��Ҫ������и�ֵ,����������˫�׽��ֵ.
 * Ϊ��Ͻ�ʡ�ռ�ɾ��������ɾ������������˶�����Ԫ�ص��ж�����parentֵΪ-1��ֱ�Ӳ��룬���˷ѿռ䡣(��������)
 * */
void InsertPNode(PTree *PT,int parent,ElemTypeChar data)
{
    for (int i = 1; i <= PT->nodeNum; i++)
    {
        if(PT->nodeNum < MAX_TREE_SIZE && parent != -1 && PT->nodes[i].parent == -1)
        {
            PT->nodes[PT->nodeNum].data = data;// ����ֵ �͸��ڵ�
            PT->nodes[PT->nodeNum].parent = parent;
            PT->nodeNum++;
            return ;
        }
    }
}
/*
 * �뷨ʵ��: ��ΪPT->nodes �������һ������,���ǲ���һ���µĸ��ڵ�(���˸�����),
 *          ���ǲ���Ҫ���µĽ���������ϵ�λ��,ֻ��Ҫ��������parent�����ĺ��ӵ�parent��ָ��.
 * ���:����һ�����ڵ���ӽڵ�һ����Ҫ���˷ѿռ�--����˵
 * ����: D:parent = 0;�²���P��ȡ��D��Ϊ����Ϊ0�Ľ��ĺ���,D����ΪP�ĺ���D��parentӦ��ָ��P�����ǵ�indexλ��.
 * */
void InsertParentNode(PTree *PT,int insertIndex,ElemTypeChar data)
{
    for (int i = 1; i <= PT->nodeNum ; i++)
    {
        if(PT->nodeNum < MAX_TREE_SIZE && insertIndex != -1 && PT->nodes[i].parent == -1)
        {
            PT->nodes[PT->nodeNum].data = data; // �²���Ľ��
            PT->nodes[PT->nodeNum].parent = PT->nodes[insertIndex].parent; // ���ڵ㴫��
            PT->nodes[insertIndex].parent = i; // ����λ�����½��(����ֵӦ�����ҵ����Ǹ��յĵ�ַ����)
            PT->nodeNum++;
            return ;
        }
    }
}
/*
 * ɾ��Ԫ��
 * ���ɾ����Ԫ����һ�����ڵ�����������е������ӽ��Ľ�㲢��ֵΪ'#' parent = -1;
 * ����취������ ��֪����ν��ɾ�������ӽڵ�Ľ�� -- ���ܵݹ����
 * */
void DeletePNode(PTree *PT,ElemTypeChar data,int parentIndex)
{
    // �������ҵ����λ��
    for (int i = 0; i < PT->nodeNum; i++)
    {
        if(PT->nodes[i].data == data)
        {
            PT->nodes[i].parent = -1;
            PT->nodes[i].data = '#';
            // �ڲ�����ҵ������ӽ�㲢��Ϊ-1.
            // Ϊʲô����Ҫ��1��ʼ���� ,��Ϊ���ǵĲ������ǿ����������м�հ�λ���в����,����������ҵĽ��ֵ����Ԫ�ص�����λ����������,�Ǿͻ�������ӽڵ�.

/*            // һ�´��� �ݹ���г���  �����㷨�������ӽڵ�Ҳ�Ǹ��ڵ�Ĳ���.
            for (int j = 1; j < PT->nodeNum; j++)
            {
                if (PT->nodes[j].parent == i)
                    PT->nodes[j].parent = -1,PT->nodes[j].data = '#';
            }*/
        }
    }
}
/*
 * ��ѯ���
 * */
void FindNode(PTree *PT,ElemTypeChar data)
{
    if (PT == NULL)
        return ;
    for (int i = 0; i < PT->nodeNum; i++)
    {
        if(PT->nodes[i].data == data)
            printf("index:%d,data:%c,parent:%d\n",i,PT->nodes[i].data,PT->nodes[i].parent);
    }
}
int NodeNum(PTree *PT)
{
    return PT->nodeNum;
}

/*
 * ����ָ�����İ���ָ��������ӽڵ����
 * */
int DesignateNodeNum(PTree *PT,int nodeIndex)
{
    static int num = 1;
    if (PT->nodes[nodeIndex].data == '#')
        return -1;
    for (int i = 0; i < PT->nodeNum; i++)
    {
        if(PT->nodes[i].parent == nodeIndex)
        {
            DesignateNodeNum(PT,i);
            num++;
        }
    }
    return num;
}
