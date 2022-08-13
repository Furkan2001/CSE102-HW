#include <stdio.h>
#include "utilx.h"


int main() {

    int num1,den1;
    int num2,den2;
    int num3, den3;
    printf("Enter the numerator and denominator of the first fraction");
    scanf("%d",&num1);
    scanf("%d",&den1);
    /* Fractions with negative denominators are undefined. */
    if(den1==0){
        printf("First fractional number is undefined");
        return 0;
    }
    printf("Enter the numerator and denominator of the second fraction");
    scanf("%d",&num2);
    scanf("%d",&den2);
    /* Fractions with negative denominators are undefined. */
    if(den2==0){
        printf("Second fractional number is undefined");
        return 0;
    }

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");
    
    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");
    
    return(0);
}
