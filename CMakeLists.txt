cmake_minimum_required(VERSION 3.10)
project(embed)
aux_source_directory(. SRC)
add_executable(app ${SRC})
# CMake最低版本要求
cmake_minimum_required(VERSION 3.10)
# 项目名称
project(env_sensor_demo C)
# 指定C标准C99
set(CMAKE_C_STANDARD 99)
# 调试编译，保留gdb信息
set(CMAKE_BUILD_TYPE Debug)
# 自动搜集src下所有.c源码
aux_source_directory(src SRC_LIST)
# 生成可执行程序
add_executable(env_app ${SRC_LIST})
