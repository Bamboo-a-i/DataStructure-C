//
// Created by cxf18 on 2022/7/14.
//

#include "SQList.h"

void ListInit(Static_Sqlist *list)
{
    int index = 0;
    for(index = 0;index<Maxsize;index++)
    {
        list->data[index] = 0;
    }
    list->length = 0;
}

bool ListInsert(Static_Sqlist *list,int value,int fake_index)
{
    // length 长度从1开始自增,那么当输入的index出现异常是就无法正常插入元素.
    // 正常的使用应该是按顺序以此插入数据(1,2,3,4),而不是跳动插入数据(11,3,5)
    if(fake_index<1 || fake_index>list->length+1)
    {
        printf("insert target error\n");
        return false;
    }
    // 超过内存空间
    if(list->length >= Maxsize)
    {
        printf("内存空间已满\n");
        return false;
    }
    // 此处同样考虑内部是否需要等于的判断条件，是必须的。
    // 当没有等于条件时指定插入在某个位置的后一个两个元素将会相等。
    //index   fake_index
    // 0          1      101   101     101     101     101
    // 1          2      102   102     102     102     106
    // 2          3      103   103     103     103     103
    // 3          4      104   104     104     103     103
    // 4          5      105   105     104     104     104
    // 5          6            105     105     105     105
    // 在 位序位2的位置插入106 pos = 5;pos >= 2; data[5] = data[4];data[4] = data[3];data[3] = data[2];
    // 等于条件下不满足data[2] = data[1];---》data[2] = data[3];导致错误
    for(int pos = list->length;pos >= fake_index;pos--)
    {
        list->data[pos] = list->data[pos-1];
    }
    list->length++; // 自增长度
    list->data[fake_index-1] = value; //插入值
    return true;
}

bool ListDelete(Static_Sqlist *list,int fake_index)
{
    if(fake_index < 1 || fake_index > list->length+1)
    {
        return false;
    }
    // 关于里面的条件是否需要等号的判断条件，如果没有没有等号的情况最后一个值不会被替换掉，而是一直保留在数组中。
    // 但是length-1,但length只是位序并不是索引。输出时发现不了，但是当你一下次进行操作是便会暴露导致结果错误。
    for(int pos = fake_index;pos<=list->length;pos++)
    {
        list->data[pos-1] = list->data[pos];
    }
    list->length--;
    return true;
}

void PrintList(Static_Sqlist *list)
{
    for(int index = 0;index < list->length;index++)
    {
        printf("value = %d;length = %d\n",list->data[index],index+1);
    }
}

bool GetElem(Static_Sqlist *list,int fake_index)
{
    int temp = list->data[fake_index-1];
    printf("Find by bit:%d\n",temp);
    return true;
}

bool LocateElem(Static_Sqlist *list,int value)
{
    for(int index = 0;index<list->length;index++)
    {
        if(list->data[index] == value)
        {
            printf("Find by value:%d\n",index+1);
            return true;
        }
    }
    return false;
}

// Initial
void InitList(Dynaminc_Sqlist *list)
{
    list->data = (int *)malloc(sizeof(int)*InitSize);
    list->length = 0;
    list->maxsize = InitSize;
}
// show
void PrintList(Dynaminc_Sqlist *list)
{
    for(int index = 0;index < list->length;index++)
    {
        printf("value = %d;length = %d\n",list->data[index],index+1);
    }
}
// Incease
void IncreaseSize(Dynaminc_Sqlist *list,int len)
{
    int *p= list->data; // 指向的是首地址
    list->data = (int*)malloc((list->maxsize+len)*sizeof(int));
    for(int index = 0;index<list->length;index++)
    {
        list->data[index] = p[index]; // 数据复制到新区域
    }
    list->maxsize += len; // 顺序表最大表示增加
    free(p); // 释放原来的内存空间.
}
// Insert
bool InsertList(Dynaminc_Sqlist *list, int value, int fake_index)
{
    if(fake_index<1 || fake_index>list->length+1)
    {
        printf("insert error！\n");
        return false;
    }
    // 当位序等于最大能表示的容量时进行扩展
    if(list->length == list->maxsize)
    {
//        int *p= list->data;
//        list->data = (int*)malloc((list->maxsize+1)*sizeof(int));
//        for(int index = 0;index<list->length;index++)
//        {
//            list->data[index] = p[index]; // 数据复制到新区域
//        }
//        list->maxsize += 1; // 顺序表最大表示增加
//        free(p);
        // 此处list传递过来本身就是一个指针（指向的一个地址），不需要使用&来引用
        IncreaseSize(list,1);
    }
    for(int pos = list->length;pos>=index;pos--)
    {
        list->data[pos] = list->data[pos-1];
    }
    list->data[fake_index-1] = value;
    list->length++;
    return true;
}
// Delete
bool DeleteList(Dynaminc_Sqlist *list,int fake_index)
{
    if(fake_index<1 || fake_index>list->length+1)
    {
        return false;
    }
    for(int pos = fake_index;pos <= list->length ;pos++)
    {
        list->data[pos-1] = list->data[pos];
    }
    list->length--;
    return true;
}
bool GetElem(Dynaminc_Sqlist *list,int fake_index)
{
    int temp = list->data[fake_index-1];
    printf("Find by bit:%d\n",temp);
    return true;
}

bool LocateElem(Dynaminc_Sqlist *list,int value)
{
    for(int index = 0;index<list->length;index++)
    {
        if(list->data[index] == value)
        {
            printf("Find by value:%d\n",index+1);
            return true;
        }
    }
    return false;
}
