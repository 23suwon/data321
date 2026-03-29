#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "my_math.h"

long long gcd(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return llabs(a / gcd(a, b) * b);
}