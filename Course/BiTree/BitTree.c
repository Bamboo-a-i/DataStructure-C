//
// Created by cxf18 on 2022/6/5.
//

#include "BitTree.h"
#include "LQueue.h"
#include "Stack.h"

/*
 * �ṹ�Ͷ�������ʼ��
 *
 * ����:struct TreeNode��ָ��
 * */
bool InitTreeNode(struct TreeNode *T)
{
    // ���Դ�0��ʼ����1��ʼ,��1��ʼ����ʹ��
    for (int i = 0; i < Maxsize; i++)
    {
        T[i].isEmpty = true;
    }
    return true;
}
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
/*
 * Ŀ��:��ӡ������ֵ�͵�ַ
 * */
void Visit(BitTree T)
{
    if(T != NULL)
        printf("address:%p,data:%c\n",T,T->data);
}

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

bool Empty(BitTree T)
{
    return T == NULL ? true:false;
}
/*
 * ������������ -- ���õݹ�ʵ��
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
/*
 * ����ֵe��Ӧ�Ľ��,������Ŀ�ģ�����֪��һ������ֵ����ȥ�����Ľ�㣬����֪����ڻ�ȡֵ��û������ġ�
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
/*
 * ����ֵe��Ӧ�Ľ��,������Ŀ�ģ�����֪��һ������ֵ,ȥ�ҵ�����˫�׽��
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
/*
 * ǰ�к����
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
void InOrder(BitTree T)
{
    if(T != NULL)
    {
        InOrder(T->lChild);
        Visit(T);
        InOrder(T->rChild);
    }
}
void PostOrder(BitTree T)
{
    if(T != NULL)
    {
        PostOrder(T->lChild);
        PostOrder(T->rChild);
        Visit(T);
    }
}

/*
 * ʹ�ö��е���ʽ�����в������
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

/*
 * ʹ��ջ�Ĳ����Ͷ�����ջ���ݽṹʵ��ǰ�к����
 * */
void StackPreOrder(BitTree T)
{
    BitTreeStack ST;
    InitBitStack(&ST);
    BitTree p = T;
    while (p || !EmptyStackTree(ST))
    {
        if(p)
        {
            Visit(p);
            Push(&ST,&p);
            p = p->lChild;
        }
        else
        {
            Pop(&ST,&p);
            p = p->rChild;
        }
    }
}
void StackInOrder(BitTree T)
{
    BitTreeStack ST;
    InitBitStack(&ST);
    BitTree p = T;
    while (p || !EmptyStackTree(ST))
    {
        if(p)
        {
            Push(&ST,&p); // �����ջ
            p = p->lChild; // ָ����һ��
        }
        else
        {
            Pop(&ST,&p);
            Visit(p);
            p = p->rChild; // ��ʼ�Һ���
        }
    }
}
void StackPostOrder(BitTree T)
{
    BitTreeStack ST;
    InitBitStack(&ST);
    BitTree  p = T,r = NULL; // r ��Ϊ��¼���
    while (p || !EmptyStackTree(ST))
    {
        if(p)
        {
            // ���Ԫ��
            Push(&ST,&p);
            p = p->lChild;
        }
        else
        {
            // �ұ�Ԫ��
            GetTop(&ST,&p);//��ȡջ��Ԫ��
            if(p->rChild && p->rChild !=r) //�����������ڣ���δ�����ʹ�
            {
                p = p->rChild;
            }
            else
            {
                Pop(&ST,&p);
                Visit(p);
                r = p; //��¼������ʵĽ��
                p = NULL; //�����ʽ���
            }
        }
    }
}

// ������������ʼ��
bool InitThreadTree(ThreadTree *TT)
{

    return true;
}

/*
 * �������������ļ�������ڵ���ں���
 * �������ڲ�ʵ���Զ���ʽ��һ���ļ�,�����ݸ�CreatThreadTree();
 * */
bool CreatThreadBiTree(ThreadTree *TT,ElemTypeChar *path)
{
    FILE *fp;
    fp = fopen(path,"r"); // ���ļ�
    if(fp == NULL)
        return false;
    CreatThreadTree(TT,fp);
    fclose(fp); // �ر��ļ�
    return true;
}

/*
 * �����������е��õľ�̬���� ͨ����ȡ�ļ��е����ݴ��������� ʹ��'^'�ĸ�����ʾ�����ݹ�Ĳ���.
 * */
static void CreatThreadTree(ThreadTree *TT,FILE *fp)
{
    ElemTypeChar data = ' ';
    if(fp == NULL)
        return;
    else
        fscanf(fp,"%c",&data);
    if(data == '^') // ��ʾ�ú���Ϊnull �����һ��һ��������ݹ�
        *TT= NULL;
    else
    {
        (*TT) = (ThreadNode *) malloc(sizeof (ThreadNode));
        (*TT)->data = data;
        CreatThreadTree(&((*TT)->lChild),fp);
        CreatThreadTree(&((*TT)->rChild),fp);
        if((*TT)->lChild != NULL)
        {
            (*TT)->lTag = 0;
        }
        if((*TT)->rChild != NULL)
        {
            (*TT)->rTag = 0;
        }

    }
}

/*
 * ���������������������ɵ���ں���
 * */
void CreateInThread(ThreadTree TT)
{
    ThreadTree pre = NULL;
    if(TT != NULL) // �ǿղ���������
    {
        InThread(TT,&pre); // ������
        pre->rChild = NULL; // �������һ�����
        pre->rTag = 1;
    }
}
/*
 * �������������õĺ���
 * ����˼��: ��������Ҫ������ͨ������ȱ����������Ӷ�����pre���,ͬʱ���ݼ�¼�µ�pre��㽨���������.
 * ����:1.����������. 2.����ǰ���ͺ������(�����������pre�Ļ����Ͻ�����). 3.����pre���. 4.����������
 * * */
void static InThread(ThreadTree TT,ThreadTree *pre)
{
    if(TT != NULL)
    {
        InThread(TT->lChild,pre); // ������������
        if(TT->lChild == NULL) // ������Ϊ��
        {
            TT->lChild = *pre; // ����ǰ������
            TT->lTag = 1;
        }
        if((*pre) != NULL && (*pre)->rChild == NULL) // ����ǰ������null��������Ϊ��
        {
            (*pre)->rChild = TT; // ����ǰ�����ĺ������
            (*pre)->rTag = 1;
        }
        (*pre) = TT;
        InThread((*pre)->rChild,pre); // ������������
    }
}
/*
 * ���������ͺ��������������һ�����ķ�ʽ��ͬ.���һ�����ָ��ΪNULL
 * */
void CreatePreThread(ThreadTree TT)
{
    ThreadTree pre = NULL;
    if(TT != NULL)
    {
        PreThread(TT,&pre); // ��ʼ������
        if(pre->rChild == NULL) // �������һ�����
        {
            pre->rTag = 1;
        }
    }
}
/*
 * ˼��:������������һ�߱���һ���������Ĺ���. ����������ͬ����pre�����һ�μ�¼����ÿһ�εĸ��ڵ�λ��.
 * ����:1.���򻯸��������. 2.����preָ��. 3.������. 4.������.
 * */
void static PreThread(ThreadTree TT,ThreadTree *pre)
{
    if(TT != NULL)
    {
        // ��������
        if(TT->lChild == NULL)
        {
            TT->lChild = *pre; // ǰ������
            TT->lTag = 1;
        }
        if((*pre) != NULL && (*pre)->rChild ==  NULL)
        {
            (*pre)->rChild = TT; // �������
            (*pre)->rTag = 1;
        }
        (*pre) = TT; // ����
        // ������
        if(TT->lTag == 0)
            PreThread(TT->lChild,pre);
        // ������ ��һ���жϱ��������ѭ��
        if(TT->rTag == 0)
            PreThread(TT->rChild,pre);
    }
}
void CreatePostThread(ThreadTree TT)
{
    ThreadTree pre = NULL;
    if(TT != NULL)
        PostThread(TT,&pre);
        if(pre->rChild == NULL) // �������һ�����
            pre->rTag = 1;
}

/*
 * ˼��:������������ڵ��˼��.
 * ����:1.������ 2.������ 3.����� 4.����pre
 * */
void static PostThread(ThreadTree TT,ThreadTree *pre)
{
    if(TT != NULL)
    {
        PostThread(TT->lChild,pre); // ������
        PostThread(TT->rChild,pre); // ������
        if(TT->lChild == NULL) // �����
        {
            TT->lChild = *pre; // ǰ�����������
            TT->lTag = 1;
        }
        if(*pre != NULL && (*pre)->rChild != NULL)
        {
            (*pre)->rChild = TT; // ��̽��������
            (*pre)->rTag = 1;
        }
        *pre = TT; // ����
    }
}

/*
 * ˼��:��������ĵ�һ�����һ���������������ӽڵ�,��ôֻ��Ҫ��ltag = 0 ʱһֱ���±�������.
 * */
ThreadNode *FirstNode(ThreadNode *threadNode)
{
    while (threadNode->lTag == 0)threadNode = threadNode->lChild;
    return threadNode;
}
/*
 * ָ�����ĺ�̽��ֵ.
 * ˼��:��̽����ֵ����:
 * 1.��rtag = 1 ʱ,��ôrchild ָ��ľ��Ǻ�̽��.
 * 2.��rtag = 0 ʱ ����Ҫת��������ǰ�������ӽ��ֱ��latg == 1ʱ,lchildָ��Ľ��,��ʱlchildָ��ľ�������ǰ��,ͬ��Ҳ���ǵ�ǰ���ĺ��.
 * */
ThreadNode *NextNode(ThreadNode *threadNode)
{
    if(threadNode->rTag == 0) return FirstNode(threadNode->rChild);
    else return threadNode->rChild;
}
/*
 * ���������������㷨��ʵ�����������������ı���
 * ˼��:����forѭ��,��ʼֵ:��һ�������Ľ��;�ж�����:��㲻����NULL;����:��һ�����.
 * */
void InorderThread(ThreadNode *TT)
{
    for (ThreadNode * p = FirstNode(TT);p!= NULL; p = NextNode(p))
        VisitThread(p);
}

void VisitThread(ThreadNode *TT)
{
    if(TT != NULL)
        printf("address:%p,data:%c\n",TT,TT->data);
}

/*
 * һ���㷨��Ѱ�Һ�̽���˼��һ��
 * */
ThreadNode *LastNode(ThreadNode *threadNode)
{
    while (threadNode->rTag == 0) threadNode = threadNode->rChild;
    return threadNode;
}
ThreadNode *PreNode(ThreadNode *threadNode)
{
    if(threadNode->lTag == 0)
        return LastNode(threadNode->lChild);
    else
        return threadNode->lChild;
}
void RevInorderThread(ThreadNode *TT)
{
    for (ThreadNode *p = LastNode(TT);p != NULL;p = PreNode(p))
        VisitThread(p);
}
/*
 * ����ͺ�������о���������������ҵ�ǰ������ı���������,�������ҵ���̾�Ҳ�������.
 * ��Ϊ�򵥵�����:�������и��ڵ��һ������,����û��ǰ��. �����и�������һ������,����û�к��.
 *
 * */
ThreadNode * PreThreadNextNode(ThreadNode *threadNode)
{
    // ��������ô���Ӿ��Ǻ�� ��������Һ���
    if(threadNode->lTag == 0)
        return threadNode->lChild;
    else
        return threadNode->rChild;
}
ThreadNode * PostThreadPreNode(ThreadNode *threadNode)
{
    // ���Ҹ� ������Һ�����ô����ǰ��,����������ǰ��
    if(threadNode->rTag == 0)
        return threadNode->rChild;
    else
        return threadNode->lChild;
}