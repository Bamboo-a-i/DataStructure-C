//
// Created by cxf18 on 2022/5/23.
//

#ifndef DATASTRUCTURE_STATUS_H
#define DATASTRUCTURE_STATUS_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* ȫ�ֱ���*/
extern bool debug;   // �Ƿ�ʹ��debugģʽ

typedef  int ElemType;
/*
 * ���»س����Լ������С�
 *
 * ͨ���ڲ��Խ׶�ʱ����Ҫ��ÿһ�����Զ���ͣ�������Թ۲����������ʱ������debug=TRUE��
 * �ڷ���ʱ��������debug=FALSE����ʱ�������Կ齫������ͣ��
 */
void PressEnterToContinue(bool debug);
#endif //DATASTRUCTURE_STATUS_H
