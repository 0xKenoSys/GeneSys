#include <stdio.h>

size_t strnchr(const char *str, char ch) {
    int i, n = 0, len = strlen(str);

    for (i=0; i<len; i++) {
        if (str[i] == ch) {
            n++;
        }
    }

    return 0;
}

int main() {
    char *str = "https://KenoSys.net";
    char ch = 't';
    int n = strnchr(str, ch);
    printf("%d\n", n);
    return 0;
}

//
// Created by Madeleine on 2026/2/2.
//

//size_t strlen ( const char * str );
//int strcmp ( const char * str1, const char * str2 );
//char * strcat ( char * destination, const char * source );
//char * strcpy ( char * destination, const char * source );
// int system (const char* command);
// int puts ( const char * str );
// int printf( const char * format, ... );