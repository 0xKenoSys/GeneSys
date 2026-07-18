# ==============================================================================
# 1. 基础配置区 (The Basics)
# ==============================================================================
# 声明要求的 CMake 最低版本，3.20 是目前比较通用且现代的版本
cmake_minimum_required(VERSION 3.20)

# 声明项目名称为 GeneSys，并指定支持 C 和 C++ 两种语言
project(GeneSys C CXX)

# 设置全局的语言标准，强制要求编译器按照 C11 和 C++17 标准进行编译
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# 开启标准要求，如果编译器不支持上述标准，则直接报错停止，而不是静默降级
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==============================================================================
# 2. 自动化目标生成区 (The Automation Magic)
# 导师注：这段脚本会自动扫描所有的源文件，并为每一个文件单独创建一个可执行程序
# ==============================================================================

# 步骤 A：扫描所有源文件
# 使用 GLOB_RECURSE 递归扫描当前目录及其所有子目录下所有的 .c 和 .cpp 文件
# 将扫描到的 C 语言文件路径列表存入变量 ALL_C_FILES
file(GLOB_RECURSE ALL_C_FILES "*.c")
# 将扫描到的 C++ 语言文件路径列表存入变量 ALL_CXX_FILES
file(GLOB_RECURSE ALL_CXX_FILES "*.cpp")

# 合并两个列表，存入 ALL_SOURCE_FILES
set(ALL_SOURCE_FILES ${ALL_C_FILES} ${ALL_CXX_FILES})

# 步骤 B：遍历文件并生成 Target
# 开启一个 foreach 循环，遍历 ALL_SOURCE_FILES 中的每一个文件路径
foreach(SOURCE_FILE ${ALL_SOURCE_FILES})

    # 过滤掉 CMake 自动生成的构建目录 (非常重要，否则会陷入无限套娃)
    # 只要路径中包含 "cmake-build" 或者 ".idea" 字样的文件，直接跳过
    if(SOURCE_FILE MATCHES "cmake-build" OR SOURCE_FILE MATCHES "\\.idea")
        continue()
    endif()

    # 从完整的文件路径中提取不带后缀的文件名
    # 例如：从 /Users/.../BombLab.c 中提取出 "BombLab"
    # 这个 "BombLab" 将作为我们在 CLion 右上角选择运行时的目标名称 (Target Name)
    get_filename_component(TARGET_NAME ${SOURCE_FILE} NAME_WE)

    # 打印日志（可选，为了让你在控制台看到 CMake 正在做什么）
    message(STATUS "Auto-generating target: ${TARGET_NAME} from ${SOURCE_FILE}")

    # 核心指令：以提取出的文件名作为目标名，以当前遍历到的文件作为源码，生成一个可执行程序
    add_executable(${TARGET_NAME} "${SOURCE_FILE}"
            DailyPractice/CSAPP_Page683.c
            DailyPractice/Practice_01_260708.c
            DailyPractice/Practice_02_260708.c
            DailyPractice/Practice_03_260708.c
            KenoSys_Projects/Kenosh.c
            DailyPractice/Practice_01_260716.c
            DailyPractice/Practice_01_260717.c)

endforeach()