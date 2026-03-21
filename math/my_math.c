#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "my_math.h"

int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return abs(a / gcd(a, b) * b);
}