//
// Created by cxf18 on 2022/6/5.
//

#ifndef DATASTRUCTURE_BITTREE_H
#define DATASTRUCTURE_BITTREE_H
#include "Status.h"
typedef char ElemTypeChar;

/*
 * ��ʽ�洢
 * */
struct  ElemTypeBit
{
    int value;
};

typedef struct BitNode
{
//    struct ElemTypeBit data; // ֵ һ��д��
    ElemTypeChar data;
    struct BitNode *lChild,*rChild; // ���Һ���
    //struct BitNode *Parent; // ���ڵ�
}BitNode,*BitTree;

/*
 *
 * ˳��洢�Ķ������ṹ��
 * */

struct TreeNode
{
    ElemType value;
    bool isEmpty; // ����Ƿ�Ϊ��
};

/*
 * ���������������ݽṹ
 * */
typedef struct ThreadNode
{
    ElemTypeChar data;
    struct ThreadNode *lChild,*rChild;
    int lTag,rTag; // ����������־
}ThreadNode,*ThreadTree;


/*
 * ��������  1.��ʼ���������ṹ���� 2.��ʼ����ʽ������ 3.���ʸ���� 4.�ļ�������������� 5.���������� 6.�п�
 *          7.�п� 8.������� 9.����ֵe��ָ�� 10.����ָ�����ֵ��˫�׽��
 * */
bool InitTreeNode(struct TreeNode *T);
bool InitBitTree(BitTree *root);
void Visit(BitTree T);
bool CreatBiTree(BitTree *T,ElemTypeChar *path);
static void CreatTree(BitTree *T,FILE *fp);
bool Empty(BitTree T);
int BitTreeDepth(BitTree T);
BitTree BackBitTreeNode(BitTree T,ElemTypeChar);
BitTree BackBitParentNode(BitTree T,ElemTypeChar e);

/*
 * �ݹ����
 * */
void PreOrder(BitTree T);
void InOrder(BitTree T);
void PostOrder(BitTree T);
void LevelOrder(BitTree T);

/*
 * �ǵݹ������ջ��
 * */
void StackPreOrder(BitTree T);
void StackInOrder(BitTree T);
void StackPostOrder(BitTree T);

/*
 * ������������
 *
 * ����:1.��ʼ�� 2.�ļ����ɶ��������,���ɶ�����  3.ǰ�к������������������ڼ�ʵ��  4.�������ı���
 * */
bool InitThreadTree(ThreadTree *TT);

bool CreatThreadBiTree(ThreadTree *TT,ElemTypeChar *path);
static void CreatThreadTree(ThreadTree *TT,FILE *fp);

void CreateInThread(ThreadTree TT);
void static InThread(ThreadTree TT,ThreadTree *pre);
void CreatePreThread(ThreadTree TT);
void static PreThread(ThreadTree TT,ThreadTree *pre);
void CreatePostThread(ThreadTree TT);
void static PostThread(ThreadTree TT,ThreadTree *pre);

/*
 * �������������ı���:
 * 1. ������ - a.��һ��������� - b.ָ�����ĺ�̽�� - c. ����ͷ�����������㷨 d. - ��ӡֵ
 * 2. ����ǰ�� - a.���һ��������� - b.ָ������ǰ����� - c. ����ͷ���������������㷨
 * 3. ǰ�� - a.��̽��
 * 4. ���� - a.ǰ�����
 * */
ThreadNode *FirstNode(ThreadNode *threadNode);
ThreadNode *NextNode(ThreadNode *threadNode);
void InorderThread(ThreadNode *TT);

ThreadNode *LastNode(ThreadNode *threadNode);
ThreadNode *PreNode(ThreadNode *threadNode);
void RevInorderThread(ThreadNode *TT);

ThreadNode * PreThreadNextNode(ThreadNode *threadNode);
ThreadNode * PostThreadPreNode(ThreadNode *threadNode);

void VisitThread(ThreadNode *TT);

#endif //DATASTRUCTURE_BITTREE_H
