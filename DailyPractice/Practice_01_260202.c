#include <stdio.h>
#include <stdlib.h>

int main() {
    char plaintext = 'a';
    char secretkey = '!';
    char ciphertext = plaintext ^ secretkey;
    char decodetext = ciphertext ^ secretkey;

    char buffer[9];
    printf("        char    ASCII\n");
    printf(" plaintext  %c      %7s\n", plaintext, itoa(plaintext, buffer, 2));
    printf(" secreykey  %c      %7s\n", secretkey, itoa(secretkey, buffer, 2));
    printf("ciphertext  %c      %7s\n", ciphertext, itoa(ciphertext, buffer, 2));
    printf("decodetext  %c      %7s\n", decodetext, itoa(decodetext, buffer, 2));

    return 0;
}



//
// Created by Madeleine on 2026/2/2.
//