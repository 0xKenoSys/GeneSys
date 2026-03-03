cmake_minimum_required(VERSION 3.20)
project(CppProjects)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY KenoSys_Projects/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#让指令搜索文件夹KenoSys_Projects之下的文件
file(GLOB source_files CONFIGURE_DEPENDS "KenoSys_Projects/*.cpp")

foreach(current_file ${source_files})
    get_filename_component(target_name ${current_file} NAME_WE)
    add_executable(${target_name} ${current_file}
            KenoSys_Projects/ByronSimulator_v01_Practice_01_260302.cpp
            KenoSys_Projects/ByronSimulator_v02_260302.cpp
            KenoSys_Projects/PhoneticParser_260303.cpp)

    target_compile_features(${target_name} PRIVATE cxx_std_17)
endforeach()
