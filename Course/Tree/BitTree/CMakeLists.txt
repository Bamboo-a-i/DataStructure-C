# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable( BitTree
                main.c main.h
                BitTree.c BitTree.h
        LinkQueue.h LinkQueue.c
                Stack.c Stack.h)
# 链接公共库
target_link_libraries(BitTree Global_lib)