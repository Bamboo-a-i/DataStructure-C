//
// Created by cxf18 on 2022/6/11.
//
#include "main.h"
int main()
{
    setbuf(stdout,0);
    PressEnterToContinue(false);
    printf("@@1--孩子兄弟表示法\n");
    {
        CSTree CS;
        int max = 0;
        InitCSTree(&CS);
        CreatCSTreeEn(&CS,PATHCS);
        CSTreeDepth(CS,0,&max);
        BackCSNode(CS,'G');
        BackCSParentNode(CS,'K');
        puts("前根");
        CSTPreOrder(CS);
        puts("后根");
        CSTPostOrder(CS);
        puts("层序");
        CSTLevelOrder(CS);
    }
}