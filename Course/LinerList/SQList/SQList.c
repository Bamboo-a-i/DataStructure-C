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
    // length ���ȴ�1��ʼ����,��ô�������index�����쳣�Ǿ��޷���������Ԫ��.
    // ������ʹ��Ӧ���ǰ�˳���Դ˲�������(1,2,3,4),������������������(11,3,5)
    if(fake_index<1 || fake_index>list->length+1)
    {
        printf("insert target error\n");
        return false;
    }
    // �����ڴ�ռ�
    if(list->length >= Maxsize)
    {
        printf("�ڴ�ռ�����\n");
        return false;
    }
    // �˴�ͬ�������ڲ��Ƿ���Ҫ���ڵ��ж��������Ǳ���ġ�
    // ��û�е�������ʱָ��������ĳ��λ�õĺ�һ������Ԫ�ؽ�����ȡ�
    //index   fake_index
    // 0          1      101   101     101     101     101
    // 1          2      102   102     102     102     106
    // 2          3      103   103     103     103     103
    // 3          4      104   104     104     103     103
    // 4          5      105   105     104     104     104
    // 5          6            105     105     105     105
    // �� λ��λ2��λ�ò���106 pos = 5;pos >= 2; data[5] = data[4];data[4] = data[3];data[3] = data[2];
    // ���������²�����data[2] = data[1];---��data[2] = data[3];���´���
    for(int pos = list->length;pos >= fake_index;pos--)
    {
        list->data[pos] = list->data[pos-1];
    }
    list->length++; // ��������
    list->data[fake_index-1] = value; //����ֵ
    return true;
}

bool ListDelete(Static_Sqlist *list,int fake_index)
{
    if(fake_index < 1 || fake_index > list->length+1)
    {
        return false;
    }
    // ��������������Ƿ���Ҫ�Ⱥŵ��ж����������û��û�еȺŵ�������һ��ֵ���ᱻ�滻��������һֱ�����������С�
    // ����length-1,��lengthֻ��λ�򲢲������������ʱ���ֲ��ˣ����ǵ���һ�´ν��в����Ǳ�ᱩ¶���½������
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
    int *p= list->data; // ָ������׵�ַ
    list->data = (int*)malloc((list->maxsize+len)*sizeof(int));
    for(int index = 0;index<list->length;index++)
    {
        list->data[index] = p[index]; // ���ݸ��Ƶ�������
    }
    list->maxsize += len; // ˳�������ʾ����
    free(p); // �ͷ�ԭ�����ڴ�ռ�.
}
// Insert
bool InsertList(Dynaminc_Sqlist *list, int value, int fake_index)
{
    if(fake_index<1 || fake_index>list->length+1)
    {
        printf("insert error��\n");
        return false;
    }
    // ��λ���������ܱ�ʾ������ʱ������չ
    if(list->length == list->maxsize)
    {
//        int *p= list->data;
//        list->data = (int*)malloc((list->maxsize+1)*sizeof(int));
//        for(int index = 0;index<list->length;index++)
//        {
//            list->data[index] = p[index]; // ���ݸ��Ƶ�������
//        }
//        list->maxsize += 1; // ˳�������ʾ����
//        free(p);
        // �˴�list���ݹ����������һ��ָ�루ָ���һ����ַ��������Ҫʹ��&������
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
