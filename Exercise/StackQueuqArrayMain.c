//
// Created by cxf18 on 2022/6/27.
//
#include "Exercise.h"
int main()
{
    setbuf(stdout,0);
    SqStack S1,S2;
    PressEnterToContinue(false);
    printf("@@1-�κ�ϰ��03(P85)--");
    {
        printf("��ʼ\n");
        S1.top = S2.top = -1;
        ElemType e = 0;
        EnQueue(&S1,&S2,1);
        EnQueue(&S1,&S2,2);
        EnQueue(&S1,&S2,3);
        EnQueue(&S1,&S2,4);
        EnQueue(&S1,&S2,5);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        DeQueue(&S1,&S2,&e);
        printf("e:%d\n",e);
        Empty(S1,S2);
    }

    PressEnterToContinue(false);
    printf("@@2-�κ�ϰ��01(P96)--");
    {
        printf("��ʼ\n");
        char *kuoHao = "[{()}]";
        MatchKuoHao(kuoHao);
    }

    PressEnterToContinue(false);
    printf("@@3-�κ�ϰ��02(P96)");
    {
        printf("��ʼ\n");
        char *str = "HHHSSSHHSHSHSH";
        TrainArrange(str);

    }
}