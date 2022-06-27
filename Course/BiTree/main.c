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
    printf("@@1--˳��洢������\n");
    {
        struct TreeNode T[Maxsize]; // ����һ���������ṹ����
        printf("%d\n", InitTreeNode(T));
        // �洢����
        T[1].value = 10;
        T[5].value = 11;
        T[6].value = 12;
        T[4].value = 13;
        T[3].value = 14;
        printf("%d,%d,%d,%d,%d\n",T[1].value,T[5].value,T[6].value,T[4].value,T[3].value);
    }

    PressEnterToContinue(false);
    printf("@@2--��ʽ�洢������\n");
    {
        BitTree T = NULL;
        InitBitTree(&T);
    }

    PressEnterToContinue(false);
    printf("@@3--��ʽ�洢�������Ĵ���\n");
    {
        BitTree T = NULL;
        CreatBiTree(&T,path);
    }

    PressEnterToContinue(false);
    printf("@@4--��ʽ�洢���������п�\n");
    {
        printf("isEmpty:%d\n", Empty(T1));
    }

    PressEnterToContinue(false);
    printf("@@5--��ʽ�洢�����������\n");
    {
        printf("Depth:%d\n", BitTreeDepth(T1));
    }

    PressEnterToContinue(false);
    printf("@@6--��ֵ���Ҷ��������\n");
    {
        BitTree bitTree;
        bitTree = BackBitTreeNode(T1,'L');
        printf("address:%p;data:%c\n",bitTree, bitTree->data);
    }

    PressEnterToContinue(false);
    printf("@@7--��ȡָ�����ֵ��˫�׽��\n");
    {
        BitTree bitTree;
        bitTree = BackBitParentNode(T1,'L');
        printf("address:%p;data:%c\n",bitTree, bitTree->data);
    }

    PressEnterToContinue(false);
    printf("@@8--ǰ�����\n");
    {
        PreOrder(T1);
    }
    PressEnterToContinue(false);
    printf("@@9--�������\n");
    {
        InOrder(T1);
    }
    PressEnterToContinue(false);
    printf("@@10--�������\n");
    {
        PostOrder(T1);
    }

    PressEnterToContinue(false);
    printf("@@11--�������\n");
    {
        LevelOrder(T1);
    }

    PressEnterToContinue(false);
    printf("@@12--�ǵݹ鷽ʽʵ��ǰ�к������\n");
    {
        printf("ǰ\n");
        StackPreOrder(T1);
        printf("��\n");
        StackInOrder(T1);
        printf("��\n");
        StackPostOrder(T1);
    }

    PressEnterToContinue(false);
    printf("@@13--���ɶ�����(��������������ṹ)\n");
    {
        CreatThreadBiTree(&TT,patht);
        CreateInThread(TT);
    }

    PressEnterToContinue(false);
    printf("@@14--���ɶ�����(��������������ṹ)\n");
    {
        CreatThreadBiTree(&TT,patht);
        CreatePreThread(TT);
    }
    PressEnterToContinue(false);
    printf("@@14--���ɶ�����(��������������ṹ)\n");
    {
        CreatThreadBiTree(&TT,patht);
        CreatePostThread(TT);
        printf("@@14--���ɶ�����(�����������ṹ)\n");
    }
    PressEnterToContinue(false);
    printf("@@15--������������������\n");
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
    printf("@@16--����������������������\n");
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
    printf("@@17--��ȡָ����� �������������� ������������ǰ��\n");
    {
        CreatThreadBiTree(&TT,patht);
        CreateInThread(TT);
        ThreadNode *p;
        p = PostThreadPreNode(TT);
        printf("address:%p,data:%c\n",p,p->data);
        p = PreThreadNextNode(TT);
        printf("address:%p,data:%c\n",p,p->data);
    }*/

    // |-* ���Ĵ洢�ṹ ˫�ױ�ʾ��-���ӱ�ʾ��-�����ֵܱ�ʾ�� *-|

/*    PressEnterToContinue(false);
    printf("@@18--˫�ױ�ʾ��\n");
    {
        PTree PT;
        InitParentTree(&PT);
        CreateParentTreeEn(&PT,pathParent); // ����˫�ױ�ʾ������
        InsertPNode(&PT,0,'P'); // �����ӽ��
        InsertParentNode(&PT,3,'O'); // ���븸�׽����
        printf("@@18--˫�ױ�ʾ��,num:%d\n",DesignateNodeNum(&PT,3));
    }*/

/*    PressEnterToContinue(false);
    printf("@@19--���ӱ�ʾ��\n");
    {
        PTree PT;
        InitParentTree(&PT);
        CreateParentTreeEn(&PT, pathParent); // ����˫�ױ�ʾ������
        InsertPNode(&PT, 0, 'P'); // �����ӽ��
        InsertParentNode(&PT, 3, 'O'); // ���븸�׽����
        printf("@@18--˫�ױ�ʾ��,num:%d\n", DesignateNodeNum(&PT, 3));
    }*/

    PressEnterToContinue(false);
    printf("@@20--�����ֵܱ�ʾ��\n");
    {
        CSTree CS;
        int max = 0;
        InitCSTree(&CS);
        CreatCSTreeEn(&CS,pathCS);
        CSTreeDepth(CS,0,&max);
        BackCSNode(CS,'G');
        printf("CSTree�Ĳ���:%d\n",max);
        printf("@@20--�����ֵܱ�ʾ��\n");

    }

}