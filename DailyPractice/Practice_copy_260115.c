#include <stdio.h>
#include <windows.h>
int main_01(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 0x2C );
    puts("Madelina is the best");
    return 0;
}