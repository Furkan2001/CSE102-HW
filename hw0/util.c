#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d / %d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*n2;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2;
    *d3 = n2*d1;
    fraction_simplify(n3, d3);
    } /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
    int i;
    /* I wrote to show the fraction as a positive fraction when the numerator and denominator of the fraction are negative. */
    if(*n<0 && *d<0){
        *n = *n * (-1);
        *d = *d * (-1);
    }
    /* I wrote to simplify fractional numbers which has negative numerators. */
    if(*n<0 && *d>0){
        for(i=1; -i>=*n && i<=*d;i++){
            if(*n % i==0 && *d % i==0){
            *n = *n / i;
            *d = *d / i;
            }
        }
        /* I also put the second for loop because the simplification could not be done completely.(For example, if the fraction had to be simplified by 4, the fraction could only be simplified by 2.)*/
        for(;i>0;i--){
            if(*n % i==0 && *d % i==0){
            *n = *n / i;
            *d = *d / i;
            }
        }
    }
    /* I wrote to simplify fractional numbers which has negative denominators. */
    if(*n>0 && *d<0){
        for(i=1; i<=*n && -i>=*d ;i++){
            if(*n % i==0 && *d % i==0){
            *n = *n / i;
            *d = *d / i;
            }
        }
        /* I also put the second for loop because the simplification could not be done completely.(For example, if the fraction had to be simplified by 4, the fraction could only be simplified by 2.)*/
        for(;i>0;i--){
            if(*n % i==0 && *d % i==0){
            *n = *n / i;
            *d = *d / i;
            }
        }
    }
    /* I wrote to simplify fractional numbers which has positive numerators and denominators. */
    for(i=1;i<=*n && i<=*d;i++){
        if(*n % i==0 && *d % i==0){
            *n = *n / i;
            *d = *d / i;
        }
    }
    /* I also put the second for loop because the simplification could not be done completely.(For example, if the fraction had to be simplified by 4, the fraction could only be simplified by 2.)*/
    for(;i>0;i--){
        if(*n % i==0 && *d % i==0){
        *n = *n / i;
        *d = *d / i;
        }
    }
  /* I used this if to make the sign of the negative number appear at the beginning of the fraction. */
    if(*n>0 && *d<0)
    {
        *n = *n * (-1);
        *d = *d * (-1);
    }
} /* end fraction_div */
