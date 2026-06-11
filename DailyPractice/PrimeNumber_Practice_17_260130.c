#include <stdio.h>

int prime(int n) {
    int is_prime = 1, i;

    if (n < 0){ return -1; }

    for (i=2; i<n; i++) {
        if (n % i ==0) {
            is_prime = 0;
            break;
        }
    }

    return is_prime;
}

int main() {
    int num, is_prime;
    scanf("%d", &num);

    is_prime = prime(num);
    if (is_prime < 0) {
        printf("%d is a illegal number.\n", num);
    }else if (is_prime > 0){
        printf("%d is a prime number.\n", num);
    }else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}


//
// Created by Madeleine on 2026/1/30.
//