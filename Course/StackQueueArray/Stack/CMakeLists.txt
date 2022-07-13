# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(Stack Stack.c main.c main.h Stack.h)
# 链接公共库
target_link_libraries(Stack Global_lib)