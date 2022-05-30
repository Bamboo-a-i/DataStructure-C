# 1-�κ�ϰ��03(P85)

## ��Ŀ:
����ջS1��S2��ģ����в���.
��֪:ջ���п�/��/Pop/Push ����
ʵ��:���е�EnQueue/Dequeue/Empty����

## ����:
- ��Ӳ���:���Բ��Ϊ����ջS1-->���S2Ϊ����ջ������,�����е�Ԫ�س�ջ����ջ��S2��.
- ���Ӳ���:��S1��Ϊ����ִ�г�ջ,���������.�ڷ������S1�л���Ԫ�ؿ��Ա�Pop��S2��,�����Pop(S1),Push(S2);

## ʵ��:
```c
bool EnQueue(SqStack *S1,SqStack *S2,ElemType e)
{
    if(!SOverFlow(*S1)) // S1δ��ִ��
    {
        Push(S1,e);
        return true;
    }
    if(SOverFlow(*S1) && !SEmpty(*S2)) // S1����S2�ǿ�
    {
        printf("������\n");
        return false;
    }
    if(SOverFlow(*S1) && SEmpty(*S2)) // S1����S2��
    {
        while (SEmpty(*S1) != true)
        {
            Pop(S1,&e);
            Push(S2,e);
        }
    }
    Push(S1,e); // if1/if2�ж϶�δ����,if3ִ�е���S1����S2�յ������Ԫ��ȫ����ջ��ջ��S2,��Ҫ��һ�佫׼����ջ��Ԫ����ջ.
    return true;
}

bool DeQueue(SqStack *S1,SqStack *S2,ElemType *e)
{
    if(!SEmpty(*S2)) // ջS2��Ԫ�س���
    {
        Pop(S1,e);
    }
    else if(SEmpty(*S1)) // ջS1��
    {
        printf("���п�\n");
    }
    else
    {
        while(!SEmpty(*S1)) // ջS1�л���Ԫ�� -- ������½�����뵽S2�з����´�ֱ�ӳ���
        {
            Pop(S1,e);
            Push(S2,*e);
        }
    }
    Pop(S2,e);
    // if1δ����,else if���� ==>����S2������û��Ԫ�ؿ���Pop,else �ֽ�S1�е�����Ԫ�س�ջ��ջ��S2,
    // �˾��ʱִ��ʼ�ղ��ᵼ��ִ�к�û��PopԪ��.
    return true;
}

bool Empty(SqStack S1,SqStack S2)
{
    if(SEmpty(S1) && SEmpty(S2))
        return true;
    else
        return false;
}

bool SEmpty(SqStack S)
{
    if(S.top == -1)
        return true;
    else
        return false;
}

bool SOverFlow(SqStack S)
{
    if(S.top == Maxsize -1)//��
        return true;
    else
        return false;
}

bool Push(SqStack *S,ElemType e)
{
    if((*S).top == Maxsize -1)//��
        return false;
    (*S).data[++(*S).top] = e;
    return true;
}

bool Pop(SqStack *S,ElemType *e)
{
    if((*S).top == -1)//��
        return false;
    (*e) = (*S).data[(*S).top--];
    return true;
}
```

# 2-�κ�ϰ��01(P96)

## ��Ŀ:
-����һ���������ʽ�а���Բ���š������źͻ�����3�����͵�����,��дһ���㷨���б���ʽ�е������Ƿ���ԣ����ַ���O����Ϊ�������ʽ�Ľ�������

## ������
- ����˼����ɨ�����������е����Ÿ������������ͽ�����ջ�ͳ�ջ������
  - �����ţ���ջ
  - �����ţ��ж��Ƿ�ƥ���ڳ�ջ
  - �пգ�ȷ��ջ�е��������ž���ƥ��

## ʵ��:
- ������char *
- switch �ж�

```c
typedef struct
{
    char *data;
    int top;
}SqStack1;

bool PushC(SqStack1 *S1,char e)
{
    if((*S1).top == Maxsize -1)
        return false;
    (*S1).data[++(*S1).top] = e;
    return true;
}

bool PopC(SqStack1 *S1,char *e)
{
    if((*S1).top == -1)
        return false;
    (*e) = (*S1).data[(*S1).top--];
    return true;
}

bool CEmpty(SqStack1 S1)
{
    if(S1.top == -1)
        return true;
    else
        return false;
}

bool MatchKuoHao(char *str)
{
    SqStack1 S1;
    S1.top = -1;
    int i = 0;
    char e;
    // ѭ��ƥ��
    while (str[i] != '\0')
    {
        switch (str[i])
        {
            case '(':
                PushC(&S1,str[i]);
                break;
            case '[':
                PushC(&S1,str[i]);
                break;
            case '{':
                PushC(&S1,str[i]);
                break;
            case ')':
                PopC(&S1,&e);
                if(e!='(')
                    return false;
                break;
            case ']':
                PopC(&S1,&e);
                if(e!='[')
                    return false;
                break;
            case '}':
                PopC(&S1,&e);
                if(e!='{')
                    return false;
                break;
        }
        i++;
    }
    // �鿴�Ƿ���ȫƥ��
    if(CEmpty(S1))
        return true;
    else
        return false;
}
```

# 3-�κ�ϰ��02(P96)

## ��Ŀ
����ͼ��ʾ�������г�����ȣ�ע�⣬����������Ϊ������ʻ�����𳵵���վ��һ�����ڵ��ȵġ�ջ����)�� �𳵵���վ����ڴ���n��Ӳ�����������ᣨ�ֱ���H��S��ʾ)�ȴ����ȣ� �Ա�д�㷨���������n�ڳ�����е��ȵĲ���(����ջ���ջ����)���У���ʹ���е��������ᶼ��������Ӳ������֮ǰ��

![3.ջ_����_����-2022-05-27-22-07-47](https://iceimgurl.oss-cn-beijing.aliyuncs.com/markdownimage/3.ջ_����_����-2022-05-27-22-07-47.png)

## ����:
- ���������е�Ԫ��,��Ӳ��������ջ,�ȴ����ĵ���,�����󳵵���ȫ�����������ڽ�Ӳ��pop��
- 