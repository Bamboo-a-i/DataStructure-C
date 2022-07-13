# CMake generated Testfile for 
# Source directory: E:/Project/DataStructure/cJSON
# Build directory: E:/Project/DataStructure/cmake-build-debug/cJSON
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cJSON_test "E:/Project/DataStructure/cmake-build-debug/cJSON/cJSON_test")
set_tests_properties(cJSON_test PROPERTIES  _BACKTRACE_TRIPLES "E:/Project/DataStructure/cJSON/CMakeLists.txt;252;add_test;E:/Project/DataStructure/cJSON/CMakeLists.txt;0;")
subdirs("tests")
subdirs("fuzzing")
