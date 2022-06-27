//
// Created by cxf18 on 2022/6/23.
//
#include "ParentTree.h"
/*
 * 初始化树
 * */
void InitParentTree(PTree *PT)
{
    for (int i = 0; i < MAX_TREE_SIZE; i++)
    {
        PT->nodes[i].data = '#'; // 初始每一个元素的值为'#' 指向为-1
        PT->nodes[i].parent = -1;
    }
    PT->nodeNum = 0; // 初始结点个数值为0
}

/*
 * 创建树的入口文件，将打开的文件指针传给创建树函数。
 * */
void CreateParentTreeEn(PTree *PT, ElemTypeChar *path)
{
    FILE *fp = fopen(path,"r"); // 读模式打开
    if(fp == NULL)
        return;
    CreatParentTree(PT,fp);
    fclose(fp);
}
/*
 * 分别获取data值和父节点值，对父节点值进行强转为int，同时需要跳过字符 - 和 # 它们是用来跳过根节点和结尾的。
 * 本代码中处理父节点值的获取比较粗糙只适合parent<10的范围
 * 只是做测试使用 避免重复输入(C语言处理字符真的很累 文件操作也好麻烦)
 * */
void static CreatParentTree(PTree *PT,FILE *fp)
{
    ElemTypeChar data = ' ',parent = ' ';
    int index = 0;
    if(fp == NULL)
        return;
    while (PT->nodeNum < MAX_TREE_SIZE - 1)
    {
        fscanf(fp,"%c",&data);
        fscanf(fp,"%c",&parent);
        PT->nodes[index].data = data; // 赋值结点值
        if(data == '#') // 跳过结尾
            break;
        if(parent != '-') // 跳过根节点
            PT->nodes[index].parent = (int)parent-48; // 赋值父节点
        PT->nodeNum++; // 结点总数加1
        index++; // 索引
    }
}

/*
 * 插入结点
 * 参数:双亲结点树 PT 双亲结点ptNode
 * 作用:用于在CreateParentTree 中调用来进行插入操作 插入时需要对其进行赋值,并赋予他们双亲结点值.
 * 为配合节省空间删除所作的删除操作，添加了对所有元素的判断遇到parent值为-1的直接插入，不浪费空间。(垃圾处理)
 * */
void InsertPNode(PTree *PT,int parent,ElemTypeChar data)
{
    for (int i = 1; i <= PT->nodeNum; i++)
    {
        if(PT->nodeNum < MAX_TREE_SIZE && parent != -1 && PT->nodes[i].parent == -1)
        {
            PT->nodes[PT->nodeNum].data = data;// 插入值 和父节点
            PT->nodes[PT->nodeNum].parent = parent;
            PT->nodeNum++;
            return ;
        }
    }
}
/*
 * 想法实现: 因为PT->nodes 本身就是一个数组,我们插入一个新的父节点(除了根以外),
 *          我们不需要管新的结点在物理上的位置,只需要关心他的parent和他的孩子的parent的指向.
 * 添加:插入一个父节点和子节点一样都要不浪费空间--不多说
 * 例如: D:parent = 0;新插入P将取代D作为索引为0的结点的孩子,D将称为P的孩子D的parent应当指向P插入是的index位置.
 * */
void InsertParentNode(PTree *PT,int insertIndex,ElemTypeChar data)
{
    for (int i = 1; i <= PT->nodeNum ; i++)
    {
        if(PT->nodeNum < MAX_TREE_SIZE && insertIndex != -1 && PT->nodes[i].parent == -1)
        {
            PT->nodes[PT->nodeNum].data = data; // 新插入的结点
            PT->nodes[PT->nodeNum].parent = PT->nodes[insertIndex].parent; // 父节点传递
            PT->nodes[insertIndex].parent = i; // 插入位置是新结点(赋的值应该是找到的那个空的地址索引)
            PT->nodeNum++;
            return ;
        }
    }
}
/*
 * 删除元素
 * 如果删除的元素是一个父节点则遍历出所有的是他子结点的结点并置值为'#' parent = -1;
 * 处理办法不完善 不知道如何解决删除带有子节点的结点 -- 可能递归可以
 * */
void DeletePNode(PTree *PT,ElemTypeChar data,int parentIndex)
{
    // 外层控制找到结点位置
    for (int i = 0; i < PT->nodeNum; i++)
    {
        if(PT->nodes[i].data == data)
        {
            PT->nodes[i].parent = -1;
            PT->nodes[i].data = '#';
            // 内层控制找到他的子结点并置为-1.
            // 为什么还是要从1开始遍历 ,因为我们的插入中是可以允许在中间空白位置中插入的,如果我们所找的结点值的子元素的索引位置在他上面,那就会错过这个子节点.

/*            // 一下错误 递归进行尝试  以下算法忽略了子节点也是父节点的操作.
            for (int j = 1; j < PT->nodeNum; j++)
            {
                if (PT->nodes[j].parent == i)
                    PT->nodes[j].parent = -1,PT->nodes[j].data = '#';
            }*/
        }
    }
}
/*
 * 查询结点
 * */
void FindNode(PTree *PT,ElemTypeChar data)
{
    if (PT == NULL)
        return ;
    for (int i = 0; i < PT->nodeNum; i++)
    {
        if(PT->nodes[i].data == data)
            printf("index:%d,data:%c,parent:%d\n",i,PT->nodes[i].data,PT->nodes[i].parent);
    }
}
int NodeNum(PTree *PT)
{
    return PT->nodeNum;
}

/*
 * 返回指定结点的包含指定结点其子节点个数
 * */
int DesignateNodeNum(PTree *PT,int nodeIndex)
{
    static int num = 1;
    if (PT->nodes[nodeIndex].data == '#')
        return -1;
    for (int i = 0; i < PT->nodeNum; i++)
    {
        if(PT->nodes[i].parent == nodeIndex)
        {
            DesignateNodeNum(PT,i);
            num++;
        }
    }
    return num;
}
