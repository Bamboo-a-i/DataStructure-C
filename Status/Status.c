//
// Created by cxf18 on 2022/5/23.
//

#include "Status.h"
#include "Status.h"

/* ȫ�ֱ���*/
bool debug = false;  // �Ƿ�ʹ��debugģʽ������ʱ������ΪTRUE������ʱ������ΪFALSE(�޸�debugֵ��һ����Ҫ�������ɾ�̬��)��
#include "Status.h"

/*
 * ���»س����Լ������С�
 *
 * ͨ���ڲ��Խ׶�ʱ����Ҫ��ÿһ�����Զ���ͣ�������Թ۲����������ʱ������debug=TRUE��
 * �ڷ���ʱ��������debug=FALSE����ʱ�������Կ齫������ͣ��
 */
void PressEnterToContinue(bool debug) {
    fflush(stdin);

    // ���ڲ��Խ׶�ʱ��������debug=TRUE���ֶ����뻻�У��Ա��ó�����ͣ�������۲�ÿһ�������
    if(debug) {
        printf("\nPress Enter to Continue...");
        getchar();

        // ����ʱ��������debug=FALSE���Զ���ӻ��У�ֱ�ӳ����
    } else {
        printf("\n");
    }

    fflush(stdin);
}

char GetFirst(void)
{
    int ch;
    ch = getchar();
    while (getchar() != '\n')
        continue;
    return ch;
}
