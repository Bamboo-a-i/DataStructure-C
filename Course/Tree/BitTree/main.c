//
// Created by cxf18 on 2022/6/11.
//
#include "main.h"

int main()
{
    setbuf(stdout,0);
    BitTree T1 = NULL;

    CreatBiTreeEn(&T1,PATH);
    PressEnterToContinue(false);
    printf("@@1--顺序存储二叉树\n");
    {
        struct TreeNode T[Maxsize]; // 创建一个二叉树结构数组
        printf("%d\n", InitTreeNode(T));
        // 存储数据
        T[1].value = 10;
        T[5].value = 11;
        T[6].value = 12;
        T[4].value = 13;
        T[3].value = 14;
        printf("%d,%d,%d,%d,%d\n",T[1].value,T[5].value,T[6].value,T[4].value,T[3].value);
    }

    PressEnterToContinue(false);
    printf("@@2--链式存储二叉树\n");
    {
        BitTree T = NULL;
        InitBitTree(&T);
    }

    PressEnterToContinue(false);
    printf("@@3--链式存储二叉树的创建\n");
    {
        BitTree T = NULL;
        CreatBiTreeEn(&T,PATH);
    }

    PressEnterToContinue(false);
    printf("@@4--链式存储二叉树的判空\n");
    {
        printf("isEmpty:%d\n", Empty(T1));
    }

    PressEnterToContinue(false);
    printf("@@5--链式存储二叉树的深度\n");
    {
        printf("Depth:%d\n", BitTreeDepth(T1));
    }

    PressEnterToContinue(false);
    printf("@@6--按值查找二叉树结点\n");
    {
        BitTree bitTree;
        bitTree = BackBitTreeNode(T1,'L');
        printf("address:%p;data:%c\n",bitTree, bitTree->data);
    }

    PressEnterToContinue(false);
    printf("@@7--获取指定结点值的双亲结点\n");
    {
        BitTree bitTree;
        bitTree = BackBitParentNode(T1,'L');
        printf("address:%p;data:%c\n",bitTree, bitTree->data);
    }

    PressEnterToContinue(false);
    printf("@@8--前序遍历\n");
    {
        PreOrder(T1);
    }
    PressEnterToContinue(false);
    printf("@@9--中序遍历\n");
    {
        InOrder(T1);
    }
    PressEnterToContinue(false);
    printf("@@10--后序遍历\n");
    {
        PostOrder(T1);
    }

    PressEnterToContinue(false);
    printf("@@11--层序遍历\n");
    {
        LevelOrder(T1);
    }

    PressEnterToContinue(false);
    printf("@@12--非递归方式实现前中后序遍历\n");
    {
        printf("前\n");
        StackPreOrder(T1);
        printf("中\n");
        StackInOrder(T1);
        printf("后\n");
        StackPostOrder(T1);
    }
}