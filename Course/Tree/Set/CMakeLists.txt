# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable( Set
                main.c main.h
                UFSets.c UFSets.h)
# 链接公共库
target_link_libraries(Set Global_lib)