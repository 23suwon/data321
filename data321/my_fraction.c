#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "my_fraction.h"

static int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}


Fraction reduce(Fraction f) {
    if (f.den == 0) {
        fprintf(stderr, "Error: 분모가 0입니다.\n");
        exit(1);
    }
    
    if (f.den < 0) {
        f.num = -f.num;
        f.den = -f.den;
    }
    int g = gcd(abs(f.num), f.den);
    f.num /= g;
    f.den /= g;
    return f;
}


Fraction frac_add(Fraction f1, Fraction f2) {
    Fraction r;
    r.num = f1.num * f2.den + f2.num * f1.den;
    r.den = f1.den * f2.den;
    return reduce(r);
}

Fraction frac_sub(Fraction f1, Fraction f2) {
    Fraction r;
    r.num = f1.num * f2.den - f2.num * f1.den;
    r.den = f1.den * f2.den;
    return reduce(r);
}

Fraction frac_mul(Fraction f1, Fraction f2) {
    Fraction r;
    r.num = f1.num * f2.num;
    r.den = f1.den * f2.den;
    return reduce(r);
}

Fraction frac_div(Fraction f1, Fraction f2) {
    if (f2.num == 0) {
        fprintf(stderr, "Error: 0으로 나눌 수 없습니다.\n");
        exit(1);
    }
    Fraction r;
    r.num = f1.num * f2.den;
    r.den = f1.den * f2.num;
    return reduce(r);
}

Fraction str_to_frac(const char* s) {
    Fraction f;
    if (sscanf(s, "%d/%d", &f.num, &f.den) == 2) {
        return reduce(f);
    }
    else if (sscanf(s, "%d", &f.num) == 1) {
        f.den = 1;
        return f;
    }
    else {
        fprintf(stderr, "Error: 잘못된 분수 형식 '%s'\n", s);
        exit(1);
    }
}

void print_frac(Fraction f) {
    if (f.den == 1)
        printf("%d", f.num);
    else
        printf("%d/%d", f.num, f.den);
}