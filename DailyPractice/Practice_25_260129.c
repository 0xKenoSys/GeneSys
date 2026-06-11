#include <stdlib.h>

int main() {
    FILE *file1 = NULL, *file2 = NULL;
    char *buffer = NULL;

    file1 = fopen("input.txt", "r");
    if (file1 == NULL) {
        printf("Error opening input file.\n");
        goto cleanup;
    }

    file2 = fopen("output.txt", "w");
    if (file2 == NULL) {
        printf("Error opening output file.\n");
        goto cleanup;
    }

    buffer = (char*)malloc(1000);
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        goto cleanup;
    }

    //文件处理码

cleanup:
    if (file1)fclose(file1);
    if (file2)fclose(file2);
    if (buffer)free(buffer);

    return 0;
}



//
// Created by Madeleine on 2026/1/29.
//