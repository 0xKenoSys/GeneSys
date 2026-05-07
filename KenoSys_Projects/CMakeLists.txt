cmake_minimum_required(VERSION 3.20)
project(CppProjects)

find_package(CURL REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

#让指令搜索文件夹KenoSys_Projects之下的文件
file(GLOB source_files CONFIGURE_DEPENDS "KenoSys_Projects/*.cpp")

foreach(current_file ${source_files})
    get_filename_component(target_name ${current_file} NAME_WE)

    # 1. 每次只用当前的 .cpp 文件生成一个对应的独立执行程序
    add_executable(${target_name} ${current_file}
            GhostInTheShell_260304.cpp
            ../DailyPractice/Practice_01_260324.c
            ../DailyPractice/docs_malloc.c
            ../DailyPractice/Practice_01_260331.c
            ../DailyPractice/Practice_01_260409.c
            ../DailyPractice/Practice_02_260409.c
            ../DailyPractice/Practice_01_260324.c
            ../DailyPractice/Two_sum_01_Practice_01_260413.c
            ../DailyPractice/Two_Sum_02_Practice_01_260415.c
            ../DailyPractice/Two_Sum_03_Practice_02_260415.c
            ../DailyPractice/Palindrome_Number_01_Practice_03_260415.c
            ../DailyPractice/Practice_01_260416.c
            ../DailyPractice/Practice_01_260418.c
            ../DailyPractice/Practice_01_260420.c
            ../DailyPractice/Practice_01_260421.c
            ../Log/2026/04_Apr/260422.md
            ../DailyPractice/Practice_01_260507.c)

    # 2. 动态地把 cURL 链接给当前正在生成的这个目标
    target_link_libraries(${target_name} PRIVATE CURL::libcurl)

    target_compile_features(${target_name} PRIVATE cxx_std_17)
endforeach()





