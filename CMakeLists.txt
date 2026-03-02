cmake_minimum_required(VERSION 3.20)
project(CppProjects)

# 保持全局设定的同时，克制搜索范围
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#让指令搜索文件夹KenoSys_Projects之下的文件
file(GLOB source_files CONFIGURE_DEPENDS "KenoSys_Projects/*.cpp")

foreach(current_file ${source_files})
    get_filename_component(target_name ${current_file} NAME_WE)
    add_executable(${target_name} ${current_file}
            KenoSys_Projects/ByronStimulator_v01_Practice_01_260302.cpp)

    # 极其关键的杀招：对每一个独立目标进行绝对的标准绑定
    target_compile_features(${target_name} PRIVATE cxx_std_17)
endforeach()
