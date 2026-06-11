#include <stdio.h>
int main() {
    char str[100];
    printf("Enter a sentence:\n");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        printf("%s\n", str);
    }
    return 0;
}

//warning: this program uses gets(), which is unsafe.
//gets()不会检查目标缓冲区的大小，应该用fgets()
//不能往地址为0的空指针里写数据，这属于未定义行为
// Created by Madeleine on 2026/2/26.
