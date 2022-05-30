# 2.���Ա�

## 2.1 ���Ա�Ķ���ͻ�������

### 2.1.1���Ա���

���Ա��Ǿ�����ͬ**��������**��**n��n >= 0��**������Ԫ�ص�**��������**��nΪ����n=0��ʾһ���ձ�����L�������Ա�.

$$
(a_1,a_2,a_3....,a_i,...,a_n)
$$

**�߼�����**
- ����
  $$ a_1 $$
  ��Ψһ��"��һ������Ԫ��",�ֳƱ�ͷԪ��.
  $$ a_n $$
  ��Ψһ��"���һ��Ԫ��",.

- **����һ��Ԫ����,����Ԫ������ֻ��һ��ֱ��ǰ��;�����һ��Ԫ����,����Ԫ������ֻ��һ�����.**


**�ص�**
- Ԫ�ظ�������.(����������n�������޵�).
- ����Ԫ�ؾ����߼��ϵ�˳����,���е�Ԫ�������Ⱥ����.
- ����Ԫ�ض�������Ԫ�أ�ÿ��Ԫ�ض��ǵ���Ԫ�ء�
- ����Ԫ�ص��������Ͷ���ͬ������ζ��ÿ��Ԫ��ռ����ͬ��С�Ĵ洢�ռ䡣
- ����Ԫ�ؾ��г����ԣ���������Ԫ�ؼ���߼���ϵ����������Ԫ�ؾ�����ʾʲô���ݡ�

### 2.1.2���Ա��������
- InitList ( &):**��ʼ����**������һ���յ����Ա���ͬʱ�������ڴ�ռ䣩��
- Length (L):**���**���������Ա�L�ĳ��ȣ���L������Ԫ�صĸ�����
- LocateElem (L,e):**��ֵ���Ҳ���**���ڱ�L�в��Ҿ��и����ؼ���ֵ��Ԫ�ء�
- GetElem (L,i):**��λ���Ҳ���**����ȡ��L�е�i��λ�õ�Ԫ�ص�ֵ��
- ListInsert (&L,i,e):**�������**���ڱ��еĵ�i��λ���ϲ���ָ��Ԫ��e��
- ListDelete(&L,i,&e):**ɾ������**��ɾ�����е�i��λ�õ�Ԫ�أ�����e����ɾ��Ԫ�ص�ֵ��
- PrintList(L):**�������**����ǰ��˳��������Ա�������Ԫ��ֵ��
- Empty(L):**�пղ���**����LΪ�ձ��򷵻�true�����򷵻�false��
- DestroyList(&L):**���ٲ���**���������Ա����ͷ����Ա�L��ռ�õ��ڴ�ռ䡣


## 2.2 ���Ա��˳���ʾ

### 2.2.1 ˳���Ķ���
���Ա��˳��洢�ֳ�˳���������**һ���ַ�����Ĵ洢��Ԫ**���δ洢���Ա��е�����Ԫ�أ��Ӷ�ʹ��**�߼������ڵ�����Ԫ��������λ����Ҳ���ڡ�**��1��Ԫ�ش洢�����Ա����ʼλ��,��i��Ԫ�صĴ洢λ�ú�������Ŵ洢���ǵ�i+1��Ԫ�أ���iΪԪ��a�����Ա��е�λ����ˣ�˳�����ص��Ǳ���Ԫ�ص�**�߼�˳����������˳����ͬ**��

#### 1.��̬�Ͷ�̬����˳���

ǰ��:˳���˴�ʹ�ò���C������������������ʵ��.

```C
#include <stdio.h>
#include <stdlib.h>
#define InitSize 10
#define Maxsize 50

typedef struct
{
    int data[Maxsize];
    int length;
}Static_Sqlist;

typedef struct
{
    int *data;
    int length,maxsize;
}Dynaminc_Sqlist;

void IncreaseSize(Dynaminc_Sqlist *list,int len);
void InitList(Dynaminc_Sqlist *list);

int main()
{
    Dynaminc_Sqlist L;
    printf("%d\n",sizeof(L));
    Static_Sqlist Static_l;
    printf("%d\n",sizeof(Static_l));
    // ��ʼ����̬����
    InitList(&L);
    IncreaseSize(&L,10);
    printf("%d\n",sizeof(L.data));
    // ����չ������鸳ֵ
    for(int index = 0;index<L.maxsize;index++)
    {
        L.data[index] = index;
        printf("%d\n",L.data[index]);
    }
    return 0;
}
// Initial
void InitList(Dynaminc_Sqlist *list)
{
    list->data = (int *)malloc(sizeof(int)*InitSize);
    list->length = 0;
    list->maxsize = InitSize;
}
// Incease
void IncreaseSize(Dynaminc_Sqlist *list,int len)
{
    int *p= list->data; // ��ʱָ���������������ڴ�ռ�
    list->data = (int*)malloc((list->maxsize+len)*sizeof(int));
    for(int index = 0;index<list->length;index++)
    {
        list->data[index] = p[index]; // �����ݸ��Ƶ�������
    }
    list->maxsize += len; // ˳���������
    free(p); // �ͷ�ԭ�����ڴ�ռ�.
}

```

C �� C++��ͬ���ڴ���˳���ʱ�ķ�ʽ��ͬ��C��Ҫͨ��ָ��ʵ�֣�C++����ͨ�� `&`ʵ�֡�

### 2.2.2 ˳����ϻ���������ʵ��

ȫ�����ھ�̬����˳���Ļ����Ͻ���һ�²�����

#### 1.�������

**����**
- �ڳ���Ϊn�������У���λ��i��1<=i<=L.length��������һ���µ�Ԫ��e --> ������i���ڵ�����Ԫ��ȫ������ƶ���
- ���ǽ�׳�ԣ�
    - ����i���ܴ��ڵ�ǰL.length+1
    - �洢�ռ��Ƿ����� L.length >= MaxSize

**�߼��ṹ**

**����ṹ**

```C
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
```

**ʱ�临�Ӷ�**

- ������:�ڱ�β����(�� i= n+1)��Ԫ�غ�����佫��ִ�У�ʱ�临�Ӷ�ΪO(1).

- ƽ�����:����p<sub>i</sub> (p<sub>i</sub> = 1/(n+1))���ڵ�i��λ���ϲ���һ�����ĸ��ʣ����ڳ���Ϊn�����Ա��в���һ�����ʱ�������ƶ�����ƽ������Ϊ
- ����:�ڱ�ͷ����(�� i= 1)��Ԫ�غ�����佫ִ��n�Σ�ʱ�临�Ӷ�ΪO(n).

$$
\sum_{i=1}^{n+1}\ P_i(n-i+1) =\sum_{i=1}^{n+1}  \frac{1}{n+1} = \sum_{i=1}^{n+1}(n-i-1) = \frac{n(n+1)}{2} = \frac{n}{2}
$$


#### 2.ɾ������

ɾ��˳���L�е�i(1<=i<=L.length����λ�õ�Ԫ�أ������ñ���e���ء���i�����벻�Ϸ����򷵻�false;���򣬽���ɾԪ�ظ������ñ���e��������i+1��Ԫ�ؼ���������Ԫ��������ǰ�ƶ�һ��λ��,����true��

```C
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
```

**ʱ�临�Ӷ�**
- ������:ɾ����βԪ��.(��i=n)�������ƶ�Ԫ�أ�ʱ�临�Ӷ�ΪO(1)��
- ����:ɾ����ͷԪ�أ���i= 1)�����ƶ�����ͷԪ���������Ԫ�أ�ʱ�临�Ӷ�ΪO(n)��
- ƽ�����:����p<sub>i</sub>(p<sub>i</sub>= 1/n����ɾ����i��λ���Ͻ��ĸ��ʣ����ڳ���Ϊn�����Ա���ɾ��һ�����ʱ�������ƶ�����ƽ������Ϊ

$$
\sum_{i=1}^{n}\ P_i(n-i) =\sum_{i=1}^{n} \frac{1}{n}(n-i) = \frac{1}{n}\sum_{i=1}^{n+1}(n-i) = \frac{1}{n} \frac{n(n-1)}{2} = \frac{n-1}{2}
$$

#### 3.��ֵ����

```C
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

```

**��ֵ����ʱ�临�Ӷ�**
- ������:���ҵ�Ԫ�ؾ��ڱ�ͷ������Ƚ�һ�Σ�ʱ�临�Ӷ�ΪO(1)��
- ����:���ҵ�Ԫ���ڱ�β(�򲻴��ڣ�ʱ����Ҫ�Ƚ�n�Σ�ʱ�临�Ӷ�ΪO(n)��
- ƽ�����:����p<sub>i</sub>(p<sub>i</sub> = 1/n���ǲ��ҵ�Ԫ���ڵ�i(1<=i<=L.length)��λ���ϵĸ��ʣ����ڳ���Ϊn�����Ա��в���ֵΪe��Ԫ������Ƚϵ�ƽ������Ϊ

$$
\sum_{i=1}^{n}P_i \times i = \sum_{i=1}^{n}\frac{1}{n} \frac{n(n+1)}{2} = \frac{n+1}{2}
$$


## 2.3 ���Ա����ʽ��ʾ

˳��������ʱ��ȡ���е�����һ��Ԫ�أ����Ĵ洢λ�ÿ�����һ����ֱ�۵Ĺ�ʽ�������ɾ��������Ҫ�ƶ�����Ԫ�ء���ʽ�洢���Ա�ʱ��**����Ҫʹ�õ�ַ�����Ĵ洢��Ԫ������Ҫ���߼������ڵ�Ԫ��������λ����Ҳ����**����ͨ������������������Ԫ��֮����߼���ϵ����˲����ɾ����������Ҫ�ƶ�Ԫ�أ���**ֻ���޸�ָ��**����Ҳ��**ʧȥ˳���������ȡ���ŵ�**��

### 2.3.1 ������Ķ���

���Ա����ʽ�洢�ֳƵ���������ָͨ��һ������Ĵ洢��Ԫ���洢���Ա��е�����Ԫ�ء�
��ŵ�������Ϣ

| data | next |
|-|-|
| ������| ָ���� |

```C 
// ������Ķ���
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
```


���õ�������Խ��˳���**��Ҫ���������洢��Ԫ��ȱ�㣬**��������**����ָ����Ҳ�����˷Ѵ洢�ռ��ȱ��**�����ڵ������Ԫ����ɢ�طֲ��ڴ洢�ռ��У����Ե������Ƿ������ȡ�Ĵ洢�ṹ��������ֱ���ҵ�����ĳ���ض��Ľ�㡣����ĳ���ض��Ľ��ʱ����Ҫ�ӱ�ͷ��ʼ���������β��ҡ�

ͨ����ͷָ������ʶһ���������絥����L��ͷָ��ΪNULLʱ��ʾһ���ձ�**���⣬Ϊ�˲����ϵķ��㣬�ڵ������һ�����֮ǰ����һ����㣬��Ϊͷ��㡣ͷ������������Բ����κ���Ϣ��Ҳ���Լ�¼������Ϣ��**ͷ����ָ����ָ�����Ա�ĵ�һ��Ԫ�ؽ�㡣

#### 1.����ͷ��������

ͷ����ͷָ�������:���ܴ�����ͷ��㣬ͷָ�붼ʼ��ָ������ĵ�һ����㣬��ͷ����Ǵ�ͷ���������еĵ�һ����㣬�����ͨ�����洢��Ϣ��

**����ͷ���󣬿��Դ��������ŵ�:**
1. ���ڵ�һ�����ݽ���λ�ñ������ͷ����ָ�����У����������ĵ�һ��λ���ϵĲ������ڱ������λ���ϵĲ���һ�£�����������⴦��
2. ���������Ƿ�Ϊ�գ���ͷָ�붼ָ��ͷ���ķǿ�ָ�루�ձ���ͷ����ָ����Ϊ��)����˿ձ�ͷǿձ�Ĵ���Ҳ�͵õ���ͳһ��

### 2.3.2 ������Ĳ���

#### 1.��ʼ��

![2.���Ա�-2022-04-27-08-37-56](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/2.���Ա�-2022-04-27-08-37-56.png)

```C
// ����ͷ���
bool InitList(LinkList *L)
{
    (*L) = (LNode *)malloc(sizeof(LNode)); // ����һ����ʼ����ͷ���
    (*L)->next = NULL;
    if((*L) == NULL)
    {
        return false;
    }
    return true;
}

// ������ͷ���
bool NHeadInitList(LinkList *L)
{
    (*L) = NULL; // û��ͷ��������
    return true;
}
```

#### 2.�пղ���

```C
// ����ͷ���
bool Empty(LinkList *L)
{
    if((*L)->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// ������ͷ���
bool NHeadEmpty(LinkList *L)
{
    return ((*L) == NULL);
}
```

#### 3.ͷ�巨��β�巨��������

- ����ͷ�巨����������ʱ���������ݵ�˳�������ɵ������е�Ԫ�ص�˳�����෴�ġ�ÿ���������ʱ��ΪO(1)���赥����Ϊn������ʱ�临�Ӷ�ΪO(n)��
- β�巨�γɵ����ݺ��������������˳��һ��,ʱ�临����ͬ.

```C
// ����ͷ���

LinkList LinkHeadInsert(LinkList *L)
{
    LNode *node;
    int e;
    (*L) = (LinkList)malloc(sizeof(LNode));//����ͷ��� û��ʹ�ó�ʼ��������¿���ֱ��ʹ��.
    (*L)->next = NULL;
    printf("insert e:\n");
    scanf("%d",&e);
    while(e != 9999)
    {
        node = (LNode *)malloc(sizeof(LNode *));
        node->data = e;
        node->next = (*L)->next; // ������һ�����
        (*L)->next = node; // �����µĽ��
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

LinkList LinkTailInsert(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(LNode)); // ����ͷ���
    LNode *node,*tail = (*L); // β�����
    int e;
    printf("insert e:\n");
    scanf("%d",&e);
    while(e != 9999)
    {
        node = (LNode *)malloc(sizeof(LNode *)); //�½�����ռ�
        node->data = e;
        //(*L)->next = node;
        tail->next = node;
        //ѭ���ڲ��Լ�����β�ͣ�β�͵�next��ʱ�����Լ�
        //������ʹ��tail�����ǣ�*L���ﵽ�Ľ������һ���ģ�tail�ͣ�*L��ֻ���������Ǹ���ָ���һ�����ֶ��ѣ���һ�����ָ�������һ���˲�����ʧȥ���ֵľͻ���ʧ��Ҳ����������֮�����ϵ����ʧ��
        //(*L) = node; // �Լ��ڳ�Ϊβ��
        tail = node;
        printf("insert e:\n");
        scanf("%d",&e);
    }
    tail->next = NULL; // ���ָ��һ����β���
    return (*L);
}
```

```C
// ������ͷ���
LinkList NHeadLinkHeadInsert(LinkList *L)
{
    int e;
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999) {
        LNode *node = malloc(sizeof(LNode)); // ����һ����㣬��Ϊ�׽��
        node->next = (*L); // ��Ϊ�ʼ����������nullֵ�����Կ��Ա�֤���һ��Ԫ��ָ���ʼ����null
        node->data = e; // ����һ����㸳ֵ -->ÿ���׽��е����ǽ��ܲ��������
        (*L) = node; // (*L) --> ͷָ��ָ���µĽ��
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

LinkList NHeadLinkTailInsert(LinkList *L)
{
    int e;
    LNode *tail = (*L); //�������β��ָ��ͷָ��
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999) {
        LNode *node = (LNode *)malloc(sizeof(LNode)); // �����׽��
        node->data = e;
        if((*L) == NULL) // ����Ϊ�׽ڵ�
        {
            (*L) = node; // ͷָ��ָ�����´����Ľ��
            tail = (*L); // ��β���ͬ�� (��ͬ��ָ�����µĽ��)
        }
        else
        {
            tail->next = node; // β��㿪ʼ�ƶ�
            tail = node;
        }
        printf("insert e:\n");
        scanf("%d",&e);
    }
    node->next = NULL;
    return (*L);
}
```

#### 4.����Ų��ҽ��ֵ
- ��ʱ�临�Ӷ�ΪO(n)��

```C
// ����ͷ���
// GetElem ����ֱ�ӱ������������е���
LNode *GetElem(LinkList L,int index)
{
    if(index < 0) // ����ֵ���Ϸ�
    {
        return NULL;
    }
    LNode *temp;
    int j = 0;
    temp = L;
    //temp
    while(temp != NULL && j < index)
    {
        temp = temp->next;
        j++;
    }
    // index = 0 index<0 false, j(0)<index(0) false -->����ͷ���
    // index = 2 index <0 false,ѭ��j=0,1 ,���س�ͷ�����ĵڶ�����㡣
    return temp; // ���ڷ��ض�Ӧֵ,��������NULL
}

```

```C
// ������ͷ��� 
LNode *NHeadGetElem(LinkList L,int index)
{

    if(index < 0)
    {
        return NULL;
    }
    LNode *temp;
    int j = 1; // û��ͷ����û����0Ԫ�ش�1��ʼ����Ԫ��.
    temp = L;
    while(temp != NULL && j<index)
    {
        temp = temp->next;
        j++;
    }
    return temp;
}

```

#### 5.4.��ֵ���ҽ��
- ��ʱ�临�Ӷ�ΪO(n)��

```C
// ����ͷ���
LNode *LocateElem(LinkList L,int e)
{
    LNode *temp = L->next;
    while (temp != NULL && temp->data !=e) {
        temp = temp->next;
    }
    return temp;
}
```

```C
// ������ͷ���
LNode *NHeadLocateElem(LinkList L,int e)
{
    LNode *temp = L; // ����ͷ���Ĳ�֮ͬ��
    while (temp != NULL && temp->data !=e) {
        temp = temp->next;
    }
    return temp;
}
```

#### 6.���������

- �����������ֵΪx���½����뵽������ĵ�һ��λ���ȼ����˼��õĺϷ��ԣ�Ȼ���ҵ�������λ�õ�ǰ����㣬����i-1����㣬�����������½��.
- ǰ���㷨��Ҫ��ʱ�俪�����ڲ��ҵ�i-1��Ԫ��,ʱ�临�Ӷ�ΪO(n)�����ڸ����Ľ���������½�㣬��ʱ�临�ӶȽ�ΪO(1)��
- ǰ�������ָ��ĳ����ǰ�����һ���½�㣬�������Ķ���պ���֮�෴���ڵ���������㷨�У�ͨ�������ú��������Խ���ǰ���������ת��Ϊ��������ǰ���Ǵӵ������ͷ��㿪ʼ˳����ҵ���ǰ����㣬ʱ�临�Ӷ�ΪO(n)��

##### 1.����ͷ���
- �·�չʾ�������ֲ������.
    - ָ�������������
    - ָ���������
    - ָ�����ǰ����

```C
// Ĭ��ʹ���ҵ�ǰ��������뵽���
bool ListInsert(LinkList *L,int index,int e)
{
    // ����Ƿ�ֵ
    if(index < 1)
    {
        return false;
    }
    // ���ϵ���GetElem ����ָ����������������
    LNode *findNode = GetElem((*L),index-1); // �ҵ��������ǰ��
    return InsertNextNode(findNode,e);
}
```

```C
// ���뵽ָ�����ǰ
bool InsertPriorNode(LNode *node,int e)
{
    LNode *priorNode = (LNode *)malloc(sizeof(LNode));
    if(node== NULL || priorNode == NULL)
    {
        return false;
    }
    priorNode->next = node->next; // ���²���Ľ���ָ����㴦��ͬһ��ֱ��λ
    node->next = priorNode;  // �ò�����λ��ָ������
    priorNode->data = node->data; // ��������
    node->data = e;
    return true;
}
```

```C
bool InsertNextNode(LNode *node,int e)
{
    LNode *nextNode = (LNode *)malloc(sizeof(LNode));
    if(node == NULL && nextNode == NULL)
    {
        return false;
    }
    nextNode->next =node->next;
    nextNode->data = e;
    node->next = nextNode;
    return true;
}
```


##### 2.������ͷ���

```C
bool NHeadListInsert(LinkList *L,int index,int e)
{
    if(index < 1)
    {
        return false;
    }
    if(index == 1)
    {
        // ������ͷ����Ԫ��ʱ����λ��Ϊ1ʱ��Ҫ�ر������
        LNode *node = (LNode *)malloc(sizeof(LNode)); // �µĽ��
        node->data = e; // ��㸳ֵ
        node->next = (*L); // �����������׽ڵ�
        (*L) = node; // �ı�ͷָ���ָ��
        return true;
    }

//  ������λ�ò��ǵ�һ��ʱ����һ��
//  LNode *p = L;
//  int j = 1;
//  while (p && j<index-1)
//  {
//      p = p->next;
//      j++;
//  }
//  if(p == NULL) // index��ֵ���Ϸ�
//  {
//      return false;
//  }

    LNode *findNode = NHeadGetElem((*L),index);
//    ������
//    LNode *s = (LNode *)malloc(sizeof(LNode));
//    s->next = p->next;
//    s->data = e;
//    p->next = s;
//    return true;
    return NHeadInsertNextNode(findNode,e);
}
```

```C
bool NHeadInsertNextNode(LNode *node,int e)
{
    LNode *nextNode = (LNode *)malloc(sizeof(LNode));
    if(node == NULL && nextNode == NULL)
    {
        return false;
    }
    nextNode->next =node->next;
    nextNode->data = e;
    node->next = nextNode;
    return true;
}
```

```C
bool NHeadInsertPriorNode(LNode *node,int e)
{
    LNode *priorNode = (LNode *)malloc(sizeof(LNode));
    if(node == NULL && priorNode == NULL)
    {
        return false;
    }
    priorNode->next = node->next; // λ��ͬһ��ֱˮƽλ��
    node->next = priorNode; // node��nextָ��priorNode 
    // ���������������½��ͽ���nextָ�� -- ���Ա���ȥ��node��ǰ�����.
    priorNode->data = node->data;
    node->data = e;
    return true;
}
```

##### 3.ָ��ǰ�����������ֵ

- ���⣬�ɲ�����һ�ַ�ʽ����ת��Ϊ��������ʵ�֣����������Ϊ *p���� *p���뵽*node��ǰ�档������Ȼ��*p���뵽*node�ĺ��棬Ȼ��p->data��s->data�������������������߼���ϵ������ʹ��ʱ�临�Ӷ�ΪO(1)��

```C
// ԭ���ǰ��ֵ������һ���ģ�ֻ������һ����Ҫʹ��һ��temp����Ϊ�м����������������������
bool NHeadInsertPriorNode(LNode *node,LNode *p) // ��node���ǰ����p
{
    if(node == NULL && p == NULL)
    {
        return false;
    }
    s->next = node->next; // λ��ͬһ��ֱˮƽλ��
    node->next = s; // node��nextָ��priorNode 
    // ���������������½��ͽ���nextָ�� -- ���Ա���ȥ��node��ǰ�����.
    int temp = node->data; // �м��������������ֵ
    node->data = s->data;
    s->data = temp;
    return true;
}

```

#### 7.ɾ��������

- �㷨����Ҫʱ��ķ��ڲ��Ҳ����ϣ�ʱ�临�Ӷ�ΪO(n)��

```C
// ��ͷ���
bool ListDelete(LinkList *L,int index,int *e)
{
    if(index <1)
        return false;
    LNode *node;
    int j = 0;
    node = (*L);
    while (node!=NULL && j<index - 1)
    {
        node = node->next;
        j++;
    }
    if(node == NULL) // index ֵ���Ϸ�
        return false;
    if(node->next ==NULL) // index - 1�����֮ǰ�����������
        return  false;
    LNode *delNode = node->next; // ָ��ɾ�����
    e = delNode->data; // �����ҵ���ֵ
    node->next = delNode->next; // �Ͽ�����
    free(delNode); // �ͷ�
    return true;
}
```

- Ҫɾ��ĳ���������p��ͨ�����������ȴ������ͷ��㿪ʼ˳���ҵ���ǰ����㣬Ȼ��ִ��ɾ���������㷨��ʱ�临�Ӷ�ΪO(n)����ʵ��ɾ�����p�Ĳ�������ɾ��p�ĺ�̽�������ʵ�֣�ʵ�ʾ��ǽ����̽���ֵ����������Ȼ��ɾ����̽�㣬Ҳ��ʹ��ʱ�临�Ӷ�ΪO(1)��

```C
// ɾ��ָ�����
bool DeleteNode(LNode *node)
{
    if(node == NULL)
    {
        return false;
    }
    LNode *temp = node->next;
    node->data = temp->data; // ���̽�㽻������
    node->next = temp->next; // �Ͽ��������.
    free(temp); // �ͷ�
    return true;
}
```

```C
������ͷ���
bool NHeadListDelete(LinkList *L,int index,int *e)
{
    if(index < 0)
        return false;
    LNode *node;
    LNode *delNode;
    int j = 1;
    node = (*L);
    while(node != NULL && j < index -1)
    {
        node = node->next;
        j++;
    }
    if(node == NULL) // index ��ֵ���Ϸ�
        return false;
    if(node->next == NULL) // ֻ����һ����㲻�ܽ���ɾ������
    {
        return false;
    }
    // ����Ҫɾ�����ǵ�һ�����ʱ
    if(index == 1)
    {
        delNode = (*L);
        (*L) = node->next; // ��ͷָ��ֱ��ָ����һ������ַ���ɡ�
        e = (int *) delNode->data;
        free(delNode);
        return true;
    }
    // �ǵ�һ����㡣
    delNode = node->next;
    e = delNode->data;
    node->next = delNode->next;
    free(delNode);
    return true;
}
```

#### 8.�������

```C
// ����ͷ���
int Length(LinkList L)
{
    int len = 0;
    LNode *temp = L;
    while(temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
```

```C
// ������ͷ���
int NHeadLength(LinkList L)
{
    int len = 0;
    LNode *temp = L;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
```



### 2.3.3 ˫����

- ����������ֻ��һ��ָ�����̵�ָ�룬ʹ�õ�����ֻ�ܴ�ͷ�������˳�����������Ҫ����ĳ������ǰ����㣨���롢ɾ������ʱ)��ֻ�ܴ�ͷ��ʼ���������ʺ�̽���ʱ�临�Ӷ�ΪO(1)������ǰ������ʱ�临�Ӷ�ΪO(n)��Ϊ�˿˷������������ȱ�㣬������˫����˫��������������ָ��prior�� next���ֱ�ָ����ǰ�����ͺ�̽��.

- ����˫����
```C
typedef struct DNode
{
    int data;
    struct DNode *next,*prior;
}DNode,*DLinkList;
```
#### 2.3.3.1 ��ʼ��
```C
bool InitDLinkList(DLinkList *L)
{
    (*L) = (DNode *)malloc(sizeof (DNode));
    if((*L) == NULL)
    {
        return false;
    }
    (*L)->next = NULL;
    (*L)->prior = NULL;
    return true;
}
```

#### 2.3.3.2 �п�
```C
bool Empty(DLinkList L)
{
    if(L->next == NULL)
    {
        return false;
    }
    else
        return true;
}
```

#### 2.3.3.3 ˫�����ͷ���β�巨����

```C
DLinkList DLinkHeadInsert(DLinkList *L)
{
    DNode *dNode;
    int e;
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999)
    {
        dNode = (DNode *) malloc(sizeof (DNode));
        dNode->prior = (*L); // �²���ָ���ǰ���
        dNode->data = e;
        dNode->next = (*L)->next; // ָ����һ�����
        if((*L)->next != NULL) // ����������һ�����
            (*L)->next->prior = dNode; // ��һ������ǰ���ָ���Լ�
        (*L)->next = dNode; // ��������
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}

DLinkList DLinkTailInsert(DLinkList *L)
{
    DNode *dNode;
    DNode *tail = (*L); // β��λ��ͷָ��λ��
    int e;
    printf("insert e:\n");
    scanf("%d",&e);
    while (e != 9999)
    {
        dNode = (DNode *) malloc(sizeof (DNode));
        dNode->data = e; // ��ֵe
        dNode->next = tail->next; // �µĽ��next ָ��β���ָ���null
        dNode->prior = tail; // �½���ǰ�������һ��β���
        tail->next = dNode; // β�ڵ��next���½��
        tail = dNode; // �½���Ϊβ���
        printf("insert e:\n");
        scanf("%d",&e);
    }
    return (*L);
}
```

#### 2.3.3.4 ˫����Ĳ������

![2.���Ա�-2022-05-11-21-00-28](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/2.���Ա�-2022-05-11-21-00-28.png)

```C
bool InsertNextDnode(DNode *dNode,DNode *insertNode)
{
    if(dNode == NULL || insertNode == NULL) // ������ֵ���Ϸ�
        return false;
    insertNode->next = dNode->next;
    if(dNode->next != NULL)
        dNode->next->prior = insertNode;
    insertNode->prior = dNode;
    dNode->next = insertNode;
    return true;
}
```

#### 2.3.3.5 ˫�����ɾ������

```C
bool DeleteNextNode(DNode *dNode)
{
    if(dNode == NULL)
        return false;
    DNode *temp = dNode->next; //�� dNode �ĺ�̽��
    if(temp == NULL) // ���Ϊ��
        return false;
    dNode->next = temp->next; // �Ͽ�ɾ�������ǰ�����Ĺ�ϵ
    if(temp->next != NULL) // temp �������һ�����
        temp->next->prior = dNode; // �Ͽ�ɾ��������̵Ĺ�ϵ
    free(temp); // �ͷŽ��
    return true;
}

bool DeletePriorNode(DNode *dNode)
{
    if(dNode == NULL)
        return false;
    DNode *temp = dNode->prior; //�� dNode ��ǰ�����
    if(temp == NULL) // ǰ��Ϊ��
        return false;
    dNode->prior = temp->prior;
    if(temp->prior == NULL) // temp ǰһ�������ͷ���. ��һ������Ѿ�����ɾ��,ֱ�ӷ��ؼ���,��ʱ����û��ͷ���
        return false;
    temp->prior->next = dNode; // �Ͽ�ǰ�����Ĺ�ϵ
    free(temp); // �ͷŽ��
    return true;
}

bool DeleteNode(DLinkList *L, DNode *dNode)
{
    DNode *temp = dNode;
    if(dNode == NULL || (*L) == NULL)
        return false;
    if(dNode->next == NULL && dNode->prior == NULL) // ֻ��һ�����
        return false;
    if(dNode->next == NULL) // ��β���
    {
        dNode->prior->next = temp->next;
        free(temp);
        return true;
    }
    if(dNode->prior == NULL) // ��ͷ���
    {
        (*L)->next = dNode->next; // (*L)->next���Ա���ͷ���
        return true;
    }
    // �м���
    dNode->next->prior = dNode->prior;
    dNode->prior->next = dNode->next;
    free(dNode);
    return true;
}
```

#### 2.3.3.6 ˫��������ٲ���

```C
void DestroyList(DLinkList *L)
{
    while ((*L)->next != NULL)
        DeleteNextNode((*L)); // ͷ�����Ե��Ա�����ɾ�����㴦,����������ν�
    free(L);
    L = NULL;
}
```

#### 2.3.3.7 ˫����ı�������
- �����������ȡ����λ���ҡ���ֵ���Ҳ�����ֻ���ñ����ķ�ʽʵ�֡�ʱ�临�Ӷ� O(n)

```C
void PrintDLink(DLinkList L)
{
    DNode *temp = L->next;
    // ������
    while (temp != NULL)
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->next;
    }
    // ��ǰ���� ����Ľ��Ӧ��������ĩβ
/*    while (temp != NULL)
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->prior;
    }*/

        // ��ǰ���� ����ͷ���
/*    while (temp->prior != NULL)
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->prior;
    }*/
}
```


### 2.3.4 ѭ������

#### 2.3.4.1 ѭ��������
- ѭ��������͵�������������ڣ��������һ������ָ�벻��NULL,����Ϊָ��ͷ��㣬�Ӷ����������γ�һ����.
- ��ѭ���������У���β���*r��next��ָ��L���ʱ���û��ָ����ΪNULL�Ľ�㣬��ˣ�ѭ����������п���������ͷ����ָ���Ƿ�Ϊ�գ��������Ƿ����ͷָ�롣

![2.���Ա�-2022-05-12-19-42-45](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/2.���Ա�-2022-05-12-19-42-45.png)

- ѭ��������Ĳ��롢ɾ���㷨�뵥����ļ���һ��������ͬ�������������ڱ�β���У���ִ�еĲ�����ͬ�����õ������������ѭ�������ʡ���Ȼ��������Ϊѭ����������һ����������������κ�һ��λ���ϵĲ����ɾ���������ǵȼ۵ģ������ж��Ƿ��Ǳ�β��
- �ڵ�������ֻ�ܴӱ�ͷ��㿪ʼ����˳���������������ѭ����������Դӱ��е�����һ����㿪ʼ��������������ʱ�Ե��������Ĳ������ڱ�ͷ�ͱ�β���еģ���ʱ��ѭ����������ͷָ�������βָ�룬�Ӷ�ʹ�ò���Ч�ʸ��ߡ���ԭ���ǣ��������ͷָ�룬�Ա�β���в�����ҪO(n)��ʱ�临�Ӷȣ����������βָ��r��r->next��Ϊͷָ�룬�Ա�ͷ���β���в�����ֻ��ҪO(1)��ʱ�临�Ӷȡ�

##### 1.��ʼ-�п�-����-��ӡ
```C
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
    if(L->next == L) // ��һ��������ͷ���
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
```

#### 2.3.4.2 ѭ��˫����
- ͷ���priorҪָ���β���.
- ��ѭ��˫�����У�ĳ���*pΪβ���ʱ��p->next==L
- ��ѭ��˫����Ϊ�ձ�ʱ����ͷ����prior���next�򶼵���L

![2.���Ա�-2022-05-12-19-45-17](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/2.���Ա�-2022-05-12-19-45-17.png)

#####  1.��ʼ-�п�-�Ƿ��Ǳ�β���-����-ɾ��-����
```C
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
    if(ldlNode->next == L) //ldlNode->prior == tail; ���������ж�һ������ǲ����׽��.
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
    while (temp != L) // .next == Lʱ,��ʾ������β���
    {
        printf("address:0X%d;e:%d\n",temp,temp->data);
        temp = temp->next;
    }
}
```

### 2.3.5 ��̬����

��̬��������������������Ա����ʽ�洢�ṹ�����Ҳ��������data��ָ����next����ǰ�������������е�ָ�벻ͬ���ǣ������ָ���ǽ�����Ե�ַ�������±�)���ֳ��αꡣ��˳���һ������̬����ҲҪԤ�ȷ���һ���������ڴ�ռ䡣

![2.���Ա�-2022-05-30-15-33-14](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/2.���Ա�-2022-05-30-15-33-14.png)

```C
#define MaxSize 50
typedef struct 
{
    ElemType data;
    int next;// ��һ��Ԫ�ص������±�
}SLinkList[MaxSize];
```