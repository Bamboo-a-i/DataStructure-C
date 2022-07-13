//
// Created by cxf18 on 2022/6/11.
//
#include "main.h"
int main()
{
    setbuf(stdout,0);
    ThreadTree  TT;
    PressEnterToContinue(false);
    printf("@@13--生成二叉树(线索中序二叉树结构)\n");
    {
        CreatThreadBiTreeEn(&TT,PATHT);
        CreateInThreadEn(TT);
    }

    PressEnterToContinue(false);
    printf("@@14--生成二叉树(线索先序二叉树结构)\n");
    {
        CreatThreadBiTreeEn(&TT,PATHT);
        CreatePreThreadEn(TT);
    }
    PressEnterToContinue(false);
    printf("@@14--生成二叉树(线索后序二叉树结构)\n");
    {
        CreatThreadBiTreeEn(&TT,PATHT);
        CreatePostThreadEn(TT);
        printf("@@14--生成二叉树(线索二叉树结构)\n");
    }
    PressEnterToContinue(false);
    printf("@@15--遍历中序线索二叉树\n");
    {
        CreatThreadBiTreeEn(&TT,PATHT);
        CreateInThreadEn(TT);
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
        CreatThreadBiTreeEn(&TT,PATHT);
        CreateInThreadEn(TT);
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
        CreatThreadBiTreeEn(&TT,PATHT);
        CreateInThreadEn(TT);
        ThreadNode *p;
        p = PostThreadPreNode(TT);
        printf("address:%p,data:%c\n",p,p->data);
        p = PreThreadNextNode(TT);
        printf("address:%p,data:%c\n",p,p->data);
    }
}