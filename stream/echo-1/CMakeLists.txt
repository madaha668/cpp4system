# -------------------------------------------------------------------------
# Header
# -------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.6)
project(echo)
set(CMAKE_CXX_STANDARD 17)

# Executable
# -------------------------------------------------------------------------
add_executable(echo echo.cpp)

# 添加头文件目录（注意顺序调整到了 add_executable 之后）
include_directories(${CMAKE_BINARY_DIR}/include)
target_include_directories(echo PRIVATE /home/roobot/2TB-NVMe/home/roobot/madaha/src/include/)
