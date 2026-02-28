cmake_minimum_required(VERSION 3.20)
project(你的项目名)

set(CMAKE_CXX_STANDARD 14)

# ================= 下面是魔法代码 =================

# 1. 扫描当前项目及子目录下所有的 .cpp 文件，把它们存入 files 变量
file(GLOB_RECURSE files "*.cpp")

# 2. 开启一个循环，遍历每一个 .cpp 文件
foreach(file ${files})
    # 提取去掉后缀的文件名 (比如把 Practice_01.cpp 提取为 Practice_01)
    get_filename_component(name ${file} NAME_WE)

    # 3. 为每一个文件单独创建一个执行目标！
    add_executable(${name} ${file}
            KenoSys_Project/1.cpp)
endforeach()


