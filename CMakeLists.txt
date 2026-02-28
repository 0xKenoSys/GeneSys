cmake_minimum_required(VERSION 3.20)
project(CppProjects)
set(CMAKE_CXX_STANDARD 14)

# 赋予自动化脚本实时感知的特性
file(GLOB_RECURSE source_files CONFIGURE_DEPENDS "*.cpp")

# 依次为每个独立文件搭建专属的运行环境
foreach(current_file ${source_files})
    # 精准提取出不包含后缀的文件名
    get_filename_component(target_name ${current_file} NAME_WE)
    # 将提取出的名字作为独立可执行程序的标识
    add_executable(${target_name} ${current_file})
endforeach()
