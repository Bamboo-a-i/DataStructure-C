//
// Created by cxf18 on 2022/5/31.
//

#include "KMP.h"
int main()
{
    setbuf(stdout,0);
    PressEnterToContinue(false);
    printf("@@1--next��������--��ʽ1\n");
    {
        printf("��ʼ\n");
        SString T;
        T.ch[1] = 'a';
        T.ch[2] = 'b';
        T.ch[3] = 'a';
        T.ch[4] = 'a';
        T.ch[5] = 'b';
        T.ch[6] = 'c';
        T.ch[7] = 'a';
        T.ch[8] = 'b';
        T.ch[9] = 'a';
        int next[10];
        T.length = 9;
        GetNext(T,next);
    }

    PressEnterToContinue(false);
    printf("@@2--next��������--��ʽ2\n");
    {
        printf("��ʼ\n");
        SString T1;
        T1.ch[0] = 'a';
        T1.ch[1] = 'b';
        T1.ch[2] = 'a';
        T1.ch[3] = 'a';
        T1.ch[4] = 'b';
        T1.ch[5] = 'c';
        T1.ch[6] = 'a';
        T1.ch[7] = 'b';
        T1.ch[8] = 'a';
        int next[10];
        T1.length = 9;
        GetNext2(T1,next);
    }
    PressEnterToContinue(false);
    printf("@@3--KMP�㷨--\n");
    {
        printf("��ʼ\n");
        SString T;
        T.ch[1] = 'a';
        T.ch[2] = 'b';
        T.ch[3] = 'c';
        T.length = 9;
        SString S;
        S.ch[1] = 'a';
        S.ch[2] = 'b';
        S.ch[3] = 'a';
        S.ch[4] = 'a';
        S.ch[5] = 'b';
        S.ch[6] = 'c';
        S.ch[7] = 'a';
        S.ch[8] = 'b';
        S.ch[9] = 'a';
        S.length = 9;
        int next[10];
        GetNext2(T,next);
        printf("%d\n",IndexKMP(S,T,next));
    }
}
/*
 * ���������㷨�ǽ�����T.ch[0] ���������ݵĻ����ϣ���next[j]��Ӧ�ľ���ʧ���ַ���ת��λ��.
 * */
int* GetNext(SString T,int next[])
{
    int i = 1; // ��׺ĩβ
    int j = 0; // ǰ׺ĩβ
    next[1] = 0;
    while (i < T.length)
    {
        if(j == 0 || T.ch[i] == T.ch[j])
        {
            i++,j++;
            next[i] = j;
            printf("next[%d] = %d\n",i,j);
        }
        else
        {
            j = next[j];
        }
    }
    return next;
}

/*
 * ���������㷨�ǽ�����T.ch[0]�������ݵĻ����ϣ���next[j-1]��Ӧ����ʧ���ַ���ת��λ��.
 * */
int * GetNext2(SString T,int next[])
{
    // ��ʼ��
    int i;
    int j = 0;
    next[0] = 0;
    for ( i = 1; i < T.length ; i++)
    {
        // ��ʼ�������
        while(j > 0 && T.ch[i] != T.ch[j])
        {
            j = next[j-1];
        }
        // �������
        if(T.ch[i] == T.ch[j])
        {
            j++;
        }
        // ����next�����
        next[i] = j;
        printf("next[%d] = %d\n",i,j);
    }
    return next;
}

int IndexKMP(SString S,SString T, int next[])
{
    int j = 1; // ����ָ��
    int i = 1; // ģʽ��ָ��
    while (i<S.length && j<T.length) {
        if (j == 0 || T.ch[j] == S.ch[i])
            ++j, ++i;
        else
            j = next[j];
    }
    if(j > T.length)
        return i - T.length;
    else
        return 0;

}