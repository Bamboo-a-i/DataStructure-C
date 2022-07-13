//
// Created by cxf18 on 2022/5/12.
//

#include "LDLinkList.h"
#include "Status.h"

int main()
{
    LDLinkList L;
    setbuf(stdout,0);
    PressEnterToContinue(false);
    printf("@@1--测试初始化循环单链表函数--;\n");
    {
        printf("开始初始化!\n");
        LDLinkListInit(&L);
    }
    PressEnterToContinue(false);
    printf("@@2--测试判空函数--;\n");
    {
        printf("输出1为空\n");
        printf("结果是:%d\n", Empty(L));
    }
    PressEnterToContinue(false);
    printf("@@3--测试是否是表尾结点函数--;\n");
    {
        printf("输出1表示是表尾\n");
        printf("结果是:%d\n", IsTail(L,L->next));
    }
    PressEnterToContinue(false);
    printf("@@4--测试指定结点后插入函数--;\n");
    {
        LDLNode temp;
        temp.data = 15;
        InsertNextNode(L,&temp);
        printf("打印数据!\n");
        PrintLDLinkList(L);
    }
    PressEnterToContinue(false);
    printf("@@5--测试删除结点函数--;\n");
    {
        Delete(L->next->next);
        printf("打印数据!\n");
        PrintLDLinkList(L);
    }
}

bool LDLinkListInit(LDLinkList * L)
{
    (*L) = (LDLNode *) malloc(sizeof(LDLNode));
    if((*L) == NULL)
        return false;
    (*L)->next = (*L);
    (*L)->prior = (*L);
    return true;
}

bool Empty(LDLinkList L)
{
    if(L->next == L)
        return true;
    else
        return false;
}

bool IsTail(LDLinkList L,LDLNode *ldlNode)
{
    if(ldlNode->next == L) //ldlNode->prior == tail; 可以用来判断一个结点是不是首结点.
        return true;
    else
        return false;
}

bool InsertNextNode(LDLNode* ldlNode,LDLNode* insertNode)
{
    if(ldlNode == NULL || insertNode == NULL)
        return false;
    insertNode->next = ldlNode->next;
    ldlNode->next->prior = ldlNode;
    insertNode->prior = ldlNode;
    ldlNode->next = insertNode;
    return true;
}

bool Delete(LDLNode* ldlNode)
{
    if(ldlNode == NULL)
        return false;
    LDLNode *temp = ldlNode->next;
    ldlNode->next = temp->next;
    temp->next->prior = ldlNode;
    free(temp);
    return true;
}

void PrintLDLinkList(LDLinkList L)
{
    LDLNode *temp = L->next;
    while (temp != L) // .next == L时,表示到达了尾结点
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->next;
    }
}