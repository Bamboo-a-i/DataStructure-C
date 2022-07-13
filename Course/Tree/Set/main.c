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
        int UFSETS[SIZE];
        InitSet(UFSETS);
        CreateSetEn(UFSETS,PATHS);
        Union(UFSETS,0,2);
        Union(UFSETS,3,2);
        Find(UFSETS,11);
    }
}