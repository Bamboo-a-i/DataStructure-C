//
// Created by cxf18 on 2022/5/23.
//

#include "Status.h"
#include "Status.h"

/* 全局变量*/
bool debug = false;  // 是否使用debug模式。测试时可设置为TRUE，发布时可设置为FALSE(修改debug值后，一般需要重新生成静态库)。
#include "Status.h"

/*
 * 摁下回车键以继续运行。
 *
 * 通常在测试阶段时，需要让每一步测试都暂停下来，以观察其输出，此时可以让debug=TRUE。
 * 在发布时，可以让debug=FALSE，此时各个测试块将不会暂停。
 */
void PressEnterToContinue(bool debug) {
    fflush(stdin);

    // 处于测试阶段时，可以让debug=TRUE，手动输入换行，以便让程序暂停下来，观察每一步的输出
    if(debug) {
        printf("\nPress Enter to Continue...");
        getchar();

        // 发布时，可以让debug=FALSE，自动添加换行，直接出结果
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
