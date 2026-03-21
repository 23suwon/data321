#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "my_fraction.h"


int main(int c, char** v) {


    Fraction width = str_to_frac(v[1]);
    Fraction height = str_to_frac(v[2]);

   
    Fraction two = { 2, 1 };
    Fraction perimeter = frac_mul(two, frac_add(width, height));

    
    Fraction area = frac_mul(width, height);

    printf("Perimeter: ");
    print_frac(perimeter);
    printf(", Area: ");
    print_frac(area);
    printf("\n");

    return 0;
}