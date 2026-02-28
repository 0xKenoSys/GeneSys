#include <stdio.h>

#if _WIN32
#include <windows.h>
#elif __linux__
#include <unistd.h>
#endif

int main() {

    #if _WIN32
    Sleep(5000);
    #elif __linux__
    sleep(5);
    #endif

    //我怀疑上面这一坨根本没执行出来。但是也没bug报错

    puts("KenoSys: https://0xKenoSys.net");

    return 0;
}


//
// Created by Madeleine on 2026/1/31.
//