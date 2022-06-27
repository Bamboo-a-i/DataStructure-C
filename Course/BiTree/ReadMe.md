# 5 ����������

## 5.1 �洢�ṹ
**1.˳��洢**
```c


struct TreeNode
{
    ElemType value;
    bool isEmpty; // ����Ƿ�Ϊ��
};


```

**2.��ʽ�洢**
```c
// ��ʽ�洢
struct  ElemTypeBit
{
    int value;
};
// ˳��洢�Ķ������ṹ��
typedef struct BitNode
{
    //    struct ElemTypeBit data; // ֵ һ��д��
    ElemTypeChar data;
    struct BitNode *lChild,*rChild; // ���Һ���
    //struct BitNode *Parent; // ���ڵ�
}BitNode,*BitTree;


```

## 5.2 ��������

### 5.2.1 ˳��
**1.��������**
```c
printf("@@1--˳��洢������\n");
{
    struct TreeNode T[Maxsize]; // ����һ���������ṹ����
    printf("%d\n", InitTreeNode(T));
    // �洢����
    T[1].value = 10;
    T[5].value = 11;
    T[6].value = 12;
    T[4].value = 13;
    T[3].value = 14;
    printf("%d,%d,%d,%d,%d\n",T[1].value,T[5].value,T[6].value,T[4].value,T[3].value);
}

bool InitTreeNode(struct TreeNode *T)
{
    // ���Դ�0��ʼ����1��ʼ,��1��ʼ����ʹ��
    for (int i = 0; i < Maxsize; i++)
    {
        T[i].isEmpty = true;
    }
    return true;
}
```

### 5.2.2 ��ʽ
#### 1.��������
**1.��ʼ��**
```c
bool InitBitTree(BitTree *root)
{
    (*root) = (BitTree) malloc(sizeof (BitNode));
    if((*root) == NULL)
        return false;
    (*root)->data = 1;
    (*root)->lChild = NULL;
    (*root)->rChild = NULL;
    return true;
}
```

**2.����**
```c
/*
 * �������������ļ�������ڵ���ں���
 *
 * ����:BitTree��ָ��,�ļ�·��
 *
 * ����:bool
 * */
bool CreatBiTree(BitTree *T,ElemTypeChar *path)
{
    FILE *fp;
    fp = fopen(path,"r"); // ���ļ�
    if(fp == NULL)
        return false;
    CreatTree(T,fp);
    fclose(fp); // �ر��ļ�
    return true;
}

/*
 * ���������� һ��static����
 *
 * ����:BitTree��ָ�� FILEָ��
 *
 * ����:void
 * */
static void CreatTree(BitTree *T,FILE *fp)
{
    ElemTypeChar data = ' ';
    if(fp == NULL)
        return;
    else
        fscanf(fp,"%c",&data);
    if(data == '^') // ��ʾ�ú���Ϊnull �����һ��һ��������ݹ�
        *T= NULL;
    else
    {
        (*T) = (BitTree) malloc(sizeof (BitNode));
        (*T)->data = data;
        CreatTree(&((*T)->lChild),fp);
        CreatTree(&((*T)->rChild),fp);
    }
}

```

**3.�п�**
```c
/*
 * �ж϶������Ƿ�Ϊ��
 *
 * ����:BitTree
 *
 * ����:bool
 * */
bool Empty(BitTree T)
{
    return T == NULL ? true:false;
}
```

**4.���**
```c
/*
 * ������������ -- ���õݹ�ʵ��
 *
 * ����:BitTree
 *
 * ����:int(���)
 * */
int BitTreeDepth(BitTree T)
{
    int ld,rd; // �������
    if(T == NULL) // �ݹ����
        return 0;
    else
    {
        ld = BitTreeDepth(T->lChild);
        rd = BitTreeDepth(T->rChild);
        return (ld >= rd ? ld : rd)+1;
    }
}
```

**5.���ݽ��ֵ���ؽ��**
```c
/*
 * ����ֵe��Ӧ�Ľ��,������Ŀ�ģ�����֪��һ������ֵ����ȥ�����Ľ�㣬����֪����ڻ�ȡֵ��û������ġ�
 *
 * ����:BitTree ElemTypeChar
 *
 * ����:BitNode ���
 *
 * �Ľ����:����Ϊstatic
 * */
BitTree BackBitTreeNode(BitTree T,ElemTypeChar e)
{
    BitTree lt,rt;
    if(T == NULL)
        return NULL ;
    
    // ����ҵ�Ŀ���֧
    if(T->data == e)
        return T;
    
    // �����в���
    lt = BackBitTreeNode(T->lChild,e);
    if(lt != NULL)
        return lt;
    
    // �����в���
    rt = BackBitTreeNode(T->rChild,e);
    if(rt != NULL)
        return rt;
    return NULL;
}
```

**6.���ݽ��ֵ����˫�׽��**
```c

/*
 * ����ֵe��Ӧ�Ľ��,������Ŀ�ģ�����֪��һ������ֵ,ȥ�ҵ�����˫�׽��
 *
 * ����:BitTree ElemTypeChar
 *
 * ����:BitNode ���
 *
 * �Ľ����:����Ϊstatic
 * */
BitTree BackBitParentNode(BitTree T,ElemTypeChar e)
{
    BitTree lt,rt;
    if(T == NULL || T->data == e)
        return NULL;
    // ����
    if(T->rChild != NULL && T->lChild->data == e)
        return T;
    // �Һ���
    if(T->rChild != NULL && T->rChild->data == e)
        return T;
    lt = BackBitParentNode(T->lChild,e);
    if(lt != NULL)
        return lt;
    rt = BackBitParentNode(T->rChild,e);
    if(rt != NULL)
        return rt;
    return NULL;
}
```

## 5.3 ���ı���
Ҫ���ܹ���������ṹ
- ǰ��:������
- ����:�����
- ����:���Ҹ�

**1.ǰ��**
```c

/*
 * Ŀ��:ǰ�����
 *
 * ����:BitTree
 *
 * ����:void
 * */
void PreOrder(BitTree T)
{
    if(T != NULL)
    {
        Visit(T);
        PreOrder(T->lChild);
        PreOrder(T->rChild);
    }
}
```
**2.����**
```c
/*
 * Ŀ��:�������
 *
 * ����:BitTree
 *
 * ����:void
 * */
void InOrder(BitTree T)
{
    if(T != NULL)
    {
        InOrder(T->lChild);
        Visit(T);
        InOrder(T->rChild);
    }
}
```
**3.����**
```c
/*
 * Ŀ��:�������
 *
 * ����:BitTree
 *
 * ����:void
 * */
void PostOrder(BitTree T)
{
    if(T != NULL)
    {
        PostOrder(T->lChild);
        PostOrder(T->rChild);
        Visit(T);
    }
}
```

#### 3.�������
�㷨˼��:
1. ��ʼ��һ����������
2. �������� 
3. �����зǿգ����ͷ�����ӣ����ʸý�㣬���������Һ��Ӳ����β������еĻ�)
4. �ظ�3.ֱ������Ϊ��


**����ʵ��**
```c
/*
 * ���� -- ʹ�ö�����������
 *
 * ����:BitTree
 *
 * ����:void
 * */
void LevelOrder(BitTree T)
{
    LinkQueue LQ;
    InitQueue(&LQ);
    BitTree bitTree;
    EnQueue(&LQ,&T); // ��������
    while (!EmptyQueue(LQ))
    {
        DeQueue(&LQ,&bitTree); // ����
        Visit(bitTree); // ���ʽ��
        if(bitTree->rChild != NULL)
            EnQueue(&LQ,&bitTree->lChild);
        if(bitTree->lChild != NULL)
            EnQueue(&LQ,&bitTree->rChild);
    }
}
```

**LinkQueue**
- ����ʽ����������ͬ
```c
/*
 * ��ʼ��
 *
 * ����:LinkQueue
 *
 * ����:bool
 * */
bool InitQueue(LinkQueue *LQ)
{
    LinkNode *p = (LinkNode *) malloc(sizeof (LinkNode));
    if(p == NULL)
        return false;
    (*LQ).front = (*LQ).rear = p;
    (*LQ).front->next = NULL;
    return true;
}
/*
 * �п�
 *
 * ����:LinkQueue
 *
 * ����:bool
 * */
bool EmptyQueue(LinkQueue LQ)
{
// �п����������仯 ��Ҫ�ж�front ��rear ָ��Ľ���ֵ�Ƿ�ΪNULL
    if(LQ.front ==  LQ.rear && LQ.front->next == NULL && LQ.rear->next == NULL)
        return true;
    else
        return false;
}

/*
 * ���
 *
 * ����:LinkQueue
 *
 * ����:bool
 * */
bool EnQueue(LinkQueue *LQ,BitTree *bitTree)
{
    LinkNode *insertNode = (LinkNode *) malloc(sizeof (LinkNode));
    insertNode->data = *bitTree;
    insertNode->next = NULL;
    (*LQ).rear->next = insertNode; // β��
    (*LQ).rear = insertNode; // β��
    return true;
}

/*
 * ����
 *
 * ����:LinkQueue �洢���������,bitNode���ֵ
 *
 * ����:bool
 * */
bool DeQueue(LinkQueue *LQ,BitTree *bitTree)
{
    if((*LQ).rear == (*LQ).front)
        return false;
    LinkNode *deNode = (*LQ).front->next; // ����ͷ���
    *bitTree = deNode->data; // ��ȡ����
    (*LQ).front->next = deNode->next;
    if(*bitTree == (*LQ).rear->data)
    {
        (*LQ).rear = (*LQ).front; // ����βָ��ָ��������ַ.
    }
    free(deNode);
    return true;
}


```

**ͼ�����������ݽṹ**

![5.��-2022-06-09-20-15-01](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/5.��-2022-06-09-20-15-01.png)

## 5.4 ����������

��������������һ���Ĺ��򽫶������еĽ�����г�һ���������У��Ӷ��õ����ֱ������У�ʹ�ø������е�ÿ����㣨��һ�������һ�������⣩����һ��ֱ��ǰ����ֱ�Ӻ�̡�
