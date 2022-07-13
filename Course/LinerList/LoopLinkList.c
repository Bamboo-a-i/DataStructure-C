//
// Created by cxf18 on 2022/5/12.
//

#include "LoopLinkList.h"
#include "Status.h"

int main()
{
    setbuf(stdout,0);
    LLinkList L;
    PressEnterToContinue(false);
    printf("@@1--测试初始化循环单链表函数--;\n");
    {
        printf("开始初始化!\n");
        LLinkListInit(&L);
    }
    PressEnterToContinue(false);
    printf("@@2--测试判空函数--;\n");
    {
        printf("输出1为空\n");
        printf("结果是:%d\n", Empty(L));
    }
    PressEnterToContinue(false);
    printf("@@3--测试指定结点后插入函数--;\n");
    {
        LLNode temp;
        temp.data = 15;
        InsertNextNode(L,&temp);
        printf("打印数据!\n");
        PrintLLinkList(L);
    }
}
bool LLinkListInit(LLinkList *L)
{
    (*L) = (LLNode*) malloc(sizeof (LLNode));
    if((*L) == NULL)
        return false;
    (*L)->next = (*L);
    return true;
}

bool Empty(LLinkList L)
{
    if(L->next == L) // 下一个结点等于头结点
        return true;
    else
        return false;
}

bool InsertNextNode(LLNode *llNode,LLNode *insertNode)
{
    if(llNode == NULL || insertNode == NULL)
        return false;
    insertNode->next = llNode->next;
    llNode->next = insertNode;
    return true;
}

bool PrintLLinkList(LLinkList L)
{
    LLNode *temp = L->next;
    while (temp != L)
    {
        printf("nodeAddress:%p;nodeE:%d\n",temp,temp->data);
        temp = temp->next;
    }
    return true;
}