//
// Created by cxf18 on 2022/6/11.
//
#include "main.h"
int main()
{
    PressEnterToContinue(false);
    printf("@@1--双亲表示法\n");
    {
        PTree PT;
        InitParentTree(&PT);
        CreateParentTreeEn(&PT,PATHP); // 创建双亲表示法的树
        InsertPNode(&PT,0,'P'); // 插入子结点
        InsertParentNode(&PT,3,'O'); // 插入父亲结点结点
        printf("@@18--双亲表示法,num:%d\n",DesignateNodeNum(&PT,3));
    }

    PressEnterToContinue(false);
    printf("@@2--孩子表示法\n");
    {
        PTree PT;
        InitParentTree(&PT);
        CreateParentTreeEn(&PT, PATHP); // 创建双亲表示法的树
        InsertPNode(&PT, 0, 'P'); // 插入子结点
        InsertParentNode(&PT, 3, 'O'); // 插入父亲结点结点
        printf("@@18--双亲表示法,num:%d\n", DesignateNodeNum(&PT, 3));
    }


}