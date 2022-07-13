# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Status)

# 生成可执行文件
add_executable(String main.c main.h ../KMP/KMP.h String.h ../KMP/KMP.c String.c)
# 链接公共库
target_link_libraries(String Global_lib)