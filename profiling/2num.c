#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_math.h"

#define N 92

long long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main(void) {

    for (int i = 5; i <= N; i++) {
        long long fn = fibonacci(i);
        long long fn_1 = fibonacci(i - 1);
        long long result = gcd(fn, fn_1);
        printf("%-5d %-25lld %-25lld %-10lld\n", i, fn, fn_1, result);
    }

    return 0;
}