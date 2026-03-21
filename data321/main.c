#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "my_fraction.h"

int main() {
    char f1_str[64], f2_str[64], op;


    if (scanf("%s %c %s", f1_str, &op, f2_str) != 3) {
        fprintf(stderr, "Error\n");
        return 1;
    }

    Fraction f1 = str_to_frac(f1_str);
    Fraction f2 = str_to_frac(f2_str);
    Fraction result;

    switch (op) {
    case '+': result = frac_add(f1, f2); break;
    case '-': result = frac_sub(f1, f2); break;
    case '*': result = frac_mul(f1, f2); break;
    case '/': result = frac_div(f1, f2); break;
    default:
        fprintf(stderr, "Error: 알 수 없는 연산자 '%c'\n", op);
        return 1;
    }

    print_frac(result);
    printf("\n");

   
    return 0;
}
