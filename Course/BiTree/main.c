//
// Created by cxf18 on 2022/6/11.
//

#include "BitTree.h"
#include "ParentTree.h"
#include "LQueue.h"
#include "ChildTree.h"
#include "ChildSiblingTree.h"
int main()
{
    setbuf(stdout,0);
    char path[] = "E:\\Project\\DataStructure\\Course\\BiTree\\bit.txt";
    char pathl[] = "E:\\Project\\DataStructure\\Course\\BiTree\\lbit.txt";
    char pathr[] = "E:\\Project\\DataStructure\\Course\\BiTree\\rbit.txt";
    char patht[] = "E:\\Project\\DataStructure\\Course\\BiTree\\threadbit.txt";
    char pathParent[] = "E:\\Project\\DataStructure\\Course\\BiTree\\parentTree.txt";
    char pathCS[] = "E:\\Project\\DataStructure\\Course\\BiTree\\childSiblingTree.txt";

    /*BitTree T1 = NULL;
    ThreadTree TT = NULL;

    CreatBiTree(&T1,path);
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
        CreatBiTree(&T,path);
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

    PressEnterToContinue(false);
    printf("@@13--生成二叉树(线索中序二叉树结构)\n");
    {
        CreatThreadBiTree(&TT,patht);
        CreateInThread(TT);
    }

    PressEnterToContinue(false);
    printf("@@14--生成二叉树(线索先序二叉树结构)\n");
    {
        CreatThreadBiTree(&TT,patht);
        CreatePreThread(TT);
    }
    PressEnterToContinue(false);
    printf("@@14--生成二叉树(线索后序二叉树结构)\n");
    {
        CreatThreadBiTree(&TT,patht);
        CreatePostThread(TT);
        printf("@@14--生成二叉树(线索二叉树结构)\n");
    }
    PressEnterToContinue(false);
    printf("@@15--遍历中序线索二叉树\n");
    {
        CreatThreadBiTree(&TT,patht);
        CreateInThread(TT);
        ThreadNode *p;
        p = FirstNode(TT);
        printf("address:%p,data:%c\n",p,p->data);
        p = NextNode(TT);
        printf("address:%p,data:%c\n",p,p->data);
        InorderThread(TT);
    }

    PressEnterToContinue(false);
    printf("@@16--遍历中序线索二叉树逆序\n");
    {
        CreatThreadBiTree(&TT,patht);
        CreateInThread(TT);
        ThreadNode *p;
        p = LastNode(TT);
        printf("address:%p,data:%c\n",p,p->data);
        p = PreNode(TT);
        printf("address:%p,data:%c\n",p,p->data);
        RevInorderThread(TT);
    }


    PressEnterToContinue(false);
    printf("@@17--获取指定结点 先序线索二叉后继 后序线索二叉前驱\n");
    {
        CreatThreadBiTree(&TT,patht);
        CreateInThread(TT);
        ThreadNode *p;
        p = PostThreadPreNode(TT);
        printf("address:%p,data:%c\n",p,p->data);
        p = PreThreadNextNode(TT);
        printf("address:%p,data:%c\n",p,p->data);
    }*/

    // |-* 树的存储结构 双亲表示法-孩子表示法-孩子兄弟表示法 *-|

/*    PressEnterToContinue(false);
    printf("@@18--双亲表示法\n");
    {
        PTree PT;
        InitParentTree(&PT);
        CreateParentTreeEn(&PT,pathParent); // 创建双亲表示法的树
        InsertPNode(&PT,0,'P'); // 插入子结点
        InsertParentNode(&PT,3,'O'); // 插入父亲结点结点
        printf("@@18--双亲表示法,num:%d\n",DesignateNodeNum(&PT,3));
    }*/

/*    PressEnterToContinue(false);
    printf("@@19--孩子表示法\n");
    {
        PTree PT;
        InitParentTree(&PT);
        CreateParentTreeEn(&PT, pathParent); // 创建双亲表示法的树
        InsertPNode(&PT, 0, 'P'); // 插入子结点
        InsertParentNode(&PT, 3, 'O'); // 插入父亲结点结点
        printf("@@18--双亲表示法,num:%d\n", DesignateNodeNum(&PT, 3));
    }*/

    PressEnterToContinue(false);
    printf("@@20--孩子兄弟表示法\n");
    {
        CSTree CS;
        int max = 0;
        InitCSTree(&CS);
        CreatCSTreeEn(&CS,pathCS);
        CSTreeDepth(CS,0,&max);
        BackCSNode(CS,'G');
        printf("CSTree的层数:%d\n",max);
        printf("@@20--孩子兄弟表示法\n");

    }

}