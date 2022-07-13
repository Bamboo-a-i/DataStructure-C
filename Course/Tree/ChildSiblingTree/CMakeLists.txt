# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable( ChildSiblingTree
                main.c main.h
                ChildSiblingTree.c ChildSiblingTree.h
                LinkQueue.c LinkQueue.h)
# 链接公共库
target_link_libraries(ChildSiblingTree Global_lib)